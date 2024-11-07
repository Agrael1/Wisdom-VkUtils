# CMakeList.txt : CMake project for Wisdom-VkUtils, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.25)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (WisVk)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(WTOP ON)
else()
  set(WTOP OFF)
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU"
   AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "13"
   OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang"
   AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "16")
  set(WUSE_FMT ON)
else()
  set(WUSE_FMT OFF)
endif()

include( GNUInstallDirs )

option(WISVK_ONLY_HEADERS "Only use generated headers" OFF)
option(WISVK_RUN_GENERATOR "Run VkUtils generator to generate newest headers." ${WTOP})
option(WISVK_LOAD_SPEC "Download fresh spec from Khronos" ${WTOP})
option(WISVK_BUILD_EXAMPLES "Build examples" ${WTOP})
option(WISVK_USE_FMT "Use fmtlib for formatting" ${WUSE_FMT})

set(OUTPUT_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/wisvk/wisvk")

if(NOT WISVK_ONLY_HEADERS)
	set_property( GLOBAL PROPERTY USE_FOLDERS ON )
	include(format.cmake)
	
	
	
	# Download the vk spec
	if(WISVK_LOAD_SPEC)
		message(STATUS "Downloading Vulkan spec...")
		file(DOWNLOAD "https://raw.githubusercontent.com/KhronosGroup/Vulkan-Docs/main/xml/vk.xml" "${CMAKE_CURRENT_SOURCE_DIR}/spec/vk.xml" SHOW_PROGRESS)
		message(STATUS "Downloading Vulkan spec... Done")
		set(WISVK_LOAD_SPEC OFF CACHE BOOL "Download fresh spec from Khronos" FORCE)
	endif()
	file( TO_NATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/spec/vk.xml VK_SPEC )
	string( REPLACE "\\" "\\\\" VK_SPEC ${VK_SPEC} )
	
	
	include(FetchContent)
	
	set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

	find_package(tinyxml2 CONFIG QUIET)
 	if (tinyxml2_FOUND OR TARGET tinyxml2::tinyxml2)
  		message("tinyxml2 found, skipping download.")
  	else()
		message("Loading tinyxml2...")
		FetchContent_Declare(
	 	 tinyxml2
	 	 GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
	 	 GIT_TAG origin/master)
	
		set(tinyxml2_BUILD_TESTING
	 	   OFF
	 	   CACHE BOOL "" FORCE)
		FetchContent_MakeAvailable(tinyxml2)
 	endif()
	
	if(WISVK_USE_FMT)
 		find_package(fmt 10.0 CONFIG QUIET)
		if(fmt_FOUND OR TARGET fmt::fmt)
 		 message("fmtlib found, skipping download.")
		else()
		  message("Loading fmtlib...")
		  FetchContent_Declare(
			fmt
			GIT_REPOSITORY https://github.com/fmtlib/fmt.git
			GIT_TAG origin/master)
		  FetchContent_MakeAvailable(fmt)
    		endif()
	endif()
	
	
	
	add_executable (${PROJECT_NAME}_generator)
	target_sources(${PROJECT_NAME}_generator
		PRIVATE 
			 "entry_main.cpp"
	 "format.h" "context.h"  "generator.h" "generator.cpp" "context.cpp"   "local_gen.cpp" "local_gen.h" "util.h")
	if(WISVK_USE_FMT)
		target_link_libraries(${PROJECT_NAME}_generator PRIVATE fmt::fmt)
	endif()
	
	target_link_libraries(${PROJECT_NAME}_generator PRIVATE tinyxml2::tinyxml2)
	target_compile_definitions(${PROJECT_NAME}_generator
		PRIVATE 
			VK_SPEC="${VK_SPEC}"
			CLANG_FORMAT_EXECUTABLE="${CLANG_FORMAT_EXECUTABLE}"
			WISVK_USE_FMT=$<BOOL:${WISVK_USE_FMT}>
			OUTPUT_FOLDER="${OUTPUT_FOLDER}"
	)
	
	
	set_target_properties( ${PROJECT_NAME}_generator PROPERTIES
		CXX_STANDARD 20
		CXX_STANDARD_REQUIRED ON
	)
endif(NOT WISVK_ONLY_HEADERS)

find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} INTERFACE)
add_library(Wisdom::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} INTERFACE 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/wisvk>
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(${PROJECT_NAME} INTERFACE Vulkan::Headers)

if(WISVK_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

# install

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/wisvk/wisvk" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/")
install(EXPORT ${PROJECT_NAME}Targets
        NAMESPACE Wisdom::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
        FILE ${PROJECT_NAME}Targets.cmake
)


include(CMakePackageConfigHelpers)
configure_package_config_file( 
  "cmake/${PROJECT_NAME}Config.cmake.in" 
  "${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION 1.0
    COMPATIBILITY SameMajorVersion
)

install(FILES 
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
	IMMEDIATE @ONLY
)

add_custom_target(
	uninstall
	"${CMAKE_COMMAND}" -P
	"${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
)

set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE.md")
include(CPack)
