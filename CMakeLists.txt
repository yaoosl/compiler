cmake_minimum_required(VERSION 2.8.12)
project(ys_compiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MACOSX_RPATH 1)

# Enable multithreaded compilation in MSVC
if (MSVC)
  add_definitions(/MP)
endif()

# Configure output paths
set(ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/output)
set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/output)
set(RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/output)

# Include Paths
# include_directories("${PROJECT_SOURCE_DIR}/include/tclap-1.2.2/include")

# Source Files
file(GLOB ys_compiler_src 
    "${PROJECT_SOURCE_DIR}/src/*.h" "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_BINARY_DIR}/src/git_sha1.cpp"
)

# Get the local git revision hash and put it into a header we can use
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_SHA1)
configure_file("${PROJECT_SOURCE_DIR}/cmake/git_sha1.cpp.in" "${CMAKE_CURRENT_BINARY_DIR}/src/git_sha1.cpp" @ONLY)
list(APPEND ys_compiler_src "${CMAKE_CURRENT_BINARY_DIR}/src/git_sha1.cpp")


# Add packages to project
# find_package(Threads)


option(YS_BUILD_COMPILER "BUILD COMPILER" ON)


if (YS_BUILD_COMPILER)
    add_compile_definitions(YAOOSL_COMPILER)
    add_library(ys_compiler STATIC ${ys_compiler_src})
    target_include_directories(ys_compiler PUBLIC ${PROJECT_SOURCE_DIR}/src)
    target_compile_options(ys_compiler PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Wall>
     $<$<CXX_COMPILER_ID:MSVC>:
          /W4>)
    SET_TARGET_PROPERTIES(ys_compiler PROPERTIES PREFIX "")
    target_include_directories(ys_compiler PUBLIC ${PROJECT_SOURCE_DIR}/src)
endif ()