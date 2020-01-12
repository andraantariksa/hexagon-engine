include(FetchContent)

# Google Test
set(GTEST_VERSION 1.10.0 CACHE STRING "Google test version")
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        release-${GTEST_VERSION}
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

file(GLOB TEST_SOURCE *.cpp)

add_executable(HexagonEngineTest ${TEST_SOURCE})

include_directories(
	HexagonEngineTest
	PRIVATE
	"${googletest_SOURCE_DIR}/googletest/include/"
)

target_include_directories(HexagonEngineTest PRIVATE "../")

target_link_libraries(HexagonEngineTest HexagonEngineCore gtest_main gtest ${SDL2_LIBRARIES})

add_test(
	NAME    HexagonEngineTest
    COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/HexagonEngineTest
)