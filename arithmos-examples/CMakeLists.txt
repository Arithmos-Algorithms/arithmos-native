cmake_minimum_required(VERSION 3.18.1)

# define a project with a version
project(arithmos-examples VERSION 1.0)

# display external options
message(STATUS "Project: arithmos-examples")
message(STATUS "C compiler: ${C_COMPILER}")
message(STATUS "CXX compiler: ${CXX_COMPILER}")
message(STATUS "Toolchain headers: ${TOOLCHAIN_HEADERS}")
message(STATUS "Compiler Options: ${COMPILER_OPTIONS}")
message(STATUS "Included-library: ${STATIC_LIB_SOURCE}")
message(STATUS "Runnable-example: ${EXAMPLE}")

# Cmake variables
set(elf "${EXAMPLE}.elf")

set(CMAKE_C_COMPILER "${C_COMPILER}")
set(CMAKE_CXX_COMPILER "${CXX_COMPILER}")
set(COMPILER_OPTIONS "${COMPILER_OPTIONS}")

set(headers "${STATIC_LIB_SOURCE}/src/include")
set(avr_headers "${TOOLCHAIN_HEADERS}")

# C sources
set(sources "${CMAKE_CURRENT_SOURCE_DIR}/src/${EXAMPLE}")

# add a library target
add_executable(${elf})

# set both COMPILE_FLAGS and LINK_FLAGS to the specified binary architecture
set_target_properties(${elf} PROPERTIES COMPILE_FLAGS "${COMPILER_OPTIONS}" LINK_FLAGS "${COMPILER_OPTIONS}")

# include headers for the target
target_include_directories(${elf} PUBLIC ${avr_headers} ${headers})

# add all arithmos libraries here
target_link_libraries(${elf} "${ARITHMOS_LIB}/build/${TARGET}/libvector2d.a")
# target_link_libraries(${elf} "${ARITHMOS_LIB}/build/${TARGET}/libvector3d.a")
# target_link_libraries(${elf} "${ARITHMOS_LIB}/build/${TARGET}/libmatrix4x4.a")

# Start building the target
target_sources(${elf} PUBLIC ${sources})