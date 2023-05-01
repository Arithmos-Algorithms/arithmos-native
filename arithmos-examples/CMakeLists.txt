cmake_minimum_required(VERSION 3.18.1)

# define a project with a version
project(arithmos-examples VERSION 1.0)

# display external options
message(STATUS "Project: arithmos-examples")
message(STATUS "Toolchain: ${TOOLCHAIN_HOME}")
message(STATUS "Target Hardware: ${TARGET}")
message(STATUS "Included-library: ${ARITHMOS_LIB}")
message(STATUS "Runnable-example: ${EXAMPLE}")

# Cmake variables
set(elf "${EXAMPLE}.elf")

set(CMAKE_C_COMPILER "${TOOLCHAIN_HOME}/bin/avr-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_HOME}/bin/avr-g++")
set(COMPILER_OPTIONS "-mmcu=${TARGET}")

set(headers "${ARITHMOS_LIB}/src/include")
set(avr_headers "${TOOLCHAIN_HOME}/include")

# C sources
set(sources "${CMAKE_CURRENT_SOURCE_DIR}/src/${EXAMPLE}")

# add a library target
add_executable(${elf})

# set both COMPILE_FLAGS and LINK_FLAGS to the specified binary architecture
set_target_properties(${elf} PROPERTIES COMPILE_FLAGS "${COMPILER_OPTIONS}" LINK_FLAGS "${COMPILER_OPTIONS}")

# include headers for the target
target_include_directories(${elf} PUBLIC ${avr_headers} ${headers})

target_link_libraries(${elf} "${ARITHMOS_LIB}/build/${TARGET}/libarithmos.a")

# Start building the target
target_sources(${elf} PUBLIC ${sources})
