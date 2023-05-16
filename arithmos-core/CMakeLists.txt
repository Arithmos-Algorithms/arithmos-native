cmake_minimum_required(VERSION 3.18.1)

# define a project with a version
project(arithmos VERSION 1.0)

message(STATUS "Project: arithmos")
message(STATUS "C compiler: ${C_COMPILER}")
message(STATUS "CXX compiler: ${CXX_COMPILER}")
message(STATUS "Toolchain headers: ${TOOLCHAIN_HEADERS}")
message(STATUS "Compiler Options: ${COMPILER_OPTIONS}")
message(STATUS "Build command: ${BUILD_COMMAND}")

# Cmake variables
set(CMAKE_C_COMPILER "${C_COMPILER}")
set(CMAKE_CXX_COMPILER "${CXX_COMPILER}")
set(COMPILER_OPTIONS "${COMPILER_OPTIONS}")

set(headers "${TOOLCHAIN_HEADERS}"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/include/")

########################### libvector2d START ###########################
function(build_vector2d)
    set(vector2d "vector2d")
    set(libvector2d "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_add.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_angle.c"  
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_dot_product.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_product.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_subtract.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_distance.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_length.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_interpolate.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_extrapolate.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_are_parallel.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_are_perpendicular.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_normalize.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_polar.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_scalar_add.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_scalar_divide.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_scalar_multiply.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_scalar_subtract.c"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/libvector2d/vector2d_scalar_moduluo.c")

    # add a library target
    add_library(${vector2d} STATIC ${libvector2d})

    # set both COMPILE_FLAGS and LINK_FLAGS to the specified binary architecture
    set_target_properties(${vector2d} PROPERTIES COMPILE_FLAGS "${COMPILER_OPTIONS}" LINK_FLAGS "${COMPILER_OPTIONS}")

    # include headers for the target
    target_include_directories(${vector2d} PUBLIC ${headers})

    # Start building the target
    target_sources(${vector2d} PUBLIC ${libvector2d})
endfunction()
########################### libvector2d END ###########################

function(build_all)
    build_vector2d()
endfunction()

########################### build process START ###########################
if(BUILD_COMMAND STREQUAL "vector2d")
    build_vector2d()
else()
    build_all()
endif()
########################### build process END ###########################