project(0-Plugins LANGUAGES CXX)

include(files.cmake)

add_library(${PROJECT_NAME} ${HEADERS} ${CPPS})
add_library(Lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
		Lib::1-Adapters
		Lib::2-Application
		Lib::3-Domain
		Lib::4-Plate
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/1-Adapters/1-Adapters_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/1-Adapters/1-Adapters_autogen/include_Release>
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/2-Application/2-Application_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/2-Application/2-Application_autogen/include_Release>
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/3-Domain/3-Domain_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/3-Domain/3-Domain_autogen/include_Release>
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/4-Plate/4-Plate_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/4-Plate/4-Plate_autogen/include_Release>
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
		Qt5::Widgets
		Qt5::Core
		Qt5::Gui
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Libs")
