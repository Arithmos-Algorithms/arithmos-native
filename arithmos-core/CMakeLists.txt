cmake_minimum_required(VERSION 3.18.1)

# define a project with a version
project(arithmos VERSION 1.0)

message(STATUS "Project: arithmos")
message(STATUS "Toolchain: ${TOOLCHAIN_HOME}")
message(STATUS "Target Hardware: ${TARGET}")

# Cmake variables
set(library "arithmos")
set(CMAKE_C_COMPILER "${TOOLCHAIN_HOME}/bin/avr-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_HOME}/bin/avr-g++")
set(COMPILER_OPTIONS "-mmcu=${TARGET} -O3")

set(toolchain_headers "${TOOLCHAIN_HOME}/toolchain/include/")
set(libvector2d "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_add.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_angle.c"  
                "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_dot_product.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_length.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_lerp.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_normalize.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_polar.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_scalar_add.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_scalar_divide.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_scalar_multiply.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_scalar_subtract.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_subtract.c")

set(headers "${toolchain_headers}"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/include/")
set(sources ${libvector2d}) 

# add a library target
add_library(${library} STATIC ${sources})

# set both COMPILE_FLAGS and LINK_FLAGS to the specified binary architecture
set_target_properties(${library} PROPERTIES COMPILE_FLAGS "${COMPILER_OPTIONS}" LINK_FLAGS "${COMPILER_OPTIONS}")

# include headers for the target
target_include_directories(${library} PUBLIC ${headers})

# Start building the target
target_sources(${library} PUBLIC ${sources})
