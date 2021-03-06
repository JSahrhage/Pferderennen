project(Main LANGUAGES CXX)

include(files.cmake)

add_executable(${PROJECT_NAME} ${HEADERS} ${CPPS})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		Lib::0-Plugins
		Lib::1-Adapters
		Lib::2-Application
		Lib::3-Domain
		Lib::4-Plate
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/0-Plugins/0-Plugins_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/0-Plugins/0-Plugins_autogen/include_Release>
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/1-Adapters/1-Adapters_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/1-Adapters/1-Adapters_autogen/include_Release>
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/2-Application/2-Application_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/2-Application/2-Application_autogen/include_Release>
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/3-Domain/3-Domain_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/3-Domains/3-Domain_autogen/include_Release>
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/4-Plate/4-Plate_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/4-Plate/4-Plate_autogen/include_Release>
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Application")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
