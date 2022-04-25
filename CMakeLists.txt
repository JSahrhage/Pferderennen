cmake_minimum_required (VERSION 3.14 FATAL_ERROR)

project(Pferderennen LANGUAGES CXX)

option(BUILD_SHARED_LIBS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(App)
add_subdirectory(Libs/0-Plugins)
add_subdirectory(Libs/1-Adapters)
add_subdirectory(Libs/2-Application)
add_subdirectory(Libs/3-Domain)
add_subdirectory(Libs/4-Abstraction)

option(BUILD_DOC ON)
find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
set_property(TARGET doc_doxygen PROPERTY FOLDER "Doc")

include(FetchContent)
FetchContent_Declare(
  googletest
	URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set_property(TARGET gmock gmock_main gtest gtest_main PROPERTY FOLDER "External Projects")

enable_testing()

set(UNIT_TESTS CardDeckTest DrawCardTest MockedControllerMockTest)

foreach(UNIT_TEST IN LISTS UNIT_TESTS)
	add_executable(${UNIT_TEST} ./test/source/${UNIT_TEST}.cpp ./test/include/${UNIT_TEST}.h)

	add_dependencies(${UNIT_TEST} gtest)
	add_dependencies(${UNIT_TEST} gmock)
	target_include_directories(${UNIT_TEST}
		PUBLIC
			${PROJECT_SOURCE_DIR}/test/include
			${source_dir}/test/include
			$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/0-Plugins/0-Plugins_autogen/include_Debug>
			$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/0-Plugins/0-Plugins_autogen/include_Release>
			$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/1-Adapters/1-Adapters_autogen/include_Debug>
			$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/1-Adapters/1-Adapters_autogen/include_Release>
			$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/2-Application/2-Application_autogen/include_Debug>
			$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/2-Application/2-Application_autogen/include_Release>
			$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/3-Domain/3-Domain_autogen/include_Debug>
			$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/3-Domains/3-Domain_autogen/include_Release>
			$<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Libs/4-Abstraction/4-Abstraction_autogen/include_Debug>
			$<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Libs/4-Abstraction/4-Abstraction_autogen/include_Release>
	)

	target_link_libraries(${UNIT_TEST}
		PUBLIC
			Lib::0-Plugins
			Lib::1-Adapters
			Lib::2-Application
			Lib::3-Domain
			Lib::4-Abstraction
			Qt5::Widgets
			Qt5::Core
			Qt5::Gui
			gtest
			gtest_main
			gmock
			gmock_main
	)

	set_property(TARGET ${UNIT_TEST} PROPERTY FOLDER "Tests")

	include(GoogleTest)
	gtest_discover_tests(${UNIT_TEST})

endforeach()
