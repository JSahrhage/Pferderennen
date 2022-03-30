project(4-Abstraction LANGUAGES CXX)

include(files.cmake)

add_library(${PROJECT_NAME} ${HEADERS} ${CPPS})
add_library(Lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Libs")
