#!/bin/bash

function compile() {
    local C_COMPILER=${1}
    local CXX_COMPILER=${2}
    local TOOLCHAIN_HEADERS=${3}
    local COMPILER_OPTIONS=${4}
    local BUILD_COMMAND=${5}
    local TARGET=${6}
    local source_dir=${7}
    
    local temp=$(pwd)
    cd ${source_dir}
    cmake "-DC_COMPILER=${C_COMPILER}" \
          "-DCXX_COMPILER=${CXX_COMPILER}" \
          "-DTOOLCHAIN_HEADERS=${TOOLCHAIN_HEADERS}" \
          "-DCOMPILER_OPTIONS=${COMPILER_OPTIONS}" \
          "-DBUILD_COMMAND=${BUILD_COMMAND}" \
          -S . -B "./build/${TARGET}"
    cmake --build "./build/${TARGET}"
    cd ${temp}
    
    return $?
}

