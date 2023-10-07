# CMakeList.txt : CMake project for Wisdom-VkUtils, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.25)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("VkUtils")

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


option(WISVK_INSTALL "Enable installation of VkUtils." ON)
option(WISVK_RUN_GENERATOR "Run VkUtils generator to generate newest headers." ${WTOP})
option(WISVK_LOAD_SPEC "Download fresh spec from Khronos" ${WTOP})
option(WISVK_USE_FMT "Use fmtlib for formatting" ${WUSE_FMT})

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

message("Loading tinyxml2...")
FetchContent_Declare(
  tinyxml2
  GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
  GIT_TAG origin/master)

set(tinyxml2_BUILD_TESTING
    OFF
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(tinyxml2)

if(WISVK_USE_FMT)
	message("Loading fmtlib...")
	FetchContent_Declare(
		fmt
		GIT_REPOSITORY https://github.com/fmtlib/fmt.git
		GIT_TAG origin/master)
	FetchContent_MakeAvailable(fmt)
endif()



add_executable (${PROJECT_NAME})
target_sources(${PROJECT_NAME}
	PRIVATE 
		 "entry_main.cpp"
 "format.h" "context.h"  "generator.h" "generator.cpp" "context.cpp" "wisvk/vk_managed_handles.hpp")
if(WISVK_USE_FMT)
	target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE tinyxml2::tinyxml2)
target_compile_definitions(${PROJECT_NAME} 
	PRIVATE 
		VK_SPEC="${VK_SPEC}"
		CLANG_FORMAT_EXECUTABLE="${CLANG_FORMAT_EXECUTABLE}"
		WISVK_USE_FMT=$<BOOL:${WISVK_USE_FMT}>
		OUTPUT_FOLDER="${CMAKE_CURRENT_SOURCE_DIR}/wisvk"
)


set_target_properties( ${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

if(WISVK_INSTALL)
	include( GNUInstallDirs )

	set( WIS_HEADERS
		
	)
	install( 
		FILES 
			${WIS_HEADERS} 
		DESTINATION 
			${CMAKE_INSTALL_INCLUDEDIR}/wisvk 
	)
endif()