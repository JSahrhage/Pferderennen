project(2-Application LANGUAGES CXX)

include(files.cmake)

add_library(${PROJECT_NAME} ${HEADERS} ${CPPS})
add_library(Lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
		Lib::3-Domain
		Lib::4-Abstraction
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/3-Domain/3-Domain_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/3-Domain/3-Domain_autogen/include_Release>
		$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/4-Abstraction/4-Abstraction_autogen/include_Debug>
		$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/4-Abstraction/4-Abstraction_autogen/include_Release>	
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Libs")
