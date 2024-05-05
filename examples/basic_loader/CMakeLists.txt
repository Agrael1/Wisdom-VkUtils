project(basic_loader)

find_package(Vulkan REQUIRED)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} 
	PRIVATE 
		entry_main.cpp
)
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 23
	CXX_STANDARD_REQUIRED ON
)
target_include_directories(${PROJECT_NAME} PRIVATE
	${Vulkan_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
	Wisdom::WisVk
)
