project(3-Domain LANGUAGES CXX)

include(files.cmake)

add_library(${PROJECT_NAME} ${HEADERS} ${CPPS})
add_library(Lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
		Lib::4-Plate
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/4-Plate/4-Plate_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/4-Plate/4-Plate_autogen/include_Release>
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Libs")
