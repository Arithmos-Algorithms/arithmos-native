#!/bin/bash

function compile() {
    local C_COMPILER=${1}
    local CXX_COMPILER=${2}
    local TOOLCHAIN_HEADERS=${3}
    local COMPILER_OPTIONS=${4}
    local TARGET=${5}
    local STATIC_LIB_DIR=${6}
    local EXAMPLE=${7}
    local source_dir=${8}
    
    local temp=$(pwd)
    cd ${source_dir}
    cmake "-DC_COMPILER=${C_COMPILER}" \
          "-DCXX_COMPILER=${CXX_COMPILER}" \
          "-DTOOLCHAIN_HEADERS=${TOOLCHAIN_HEADERS}" \
          "-DCOMPILER_OPTIONS=${COMPILER_OPTIONS}" \
          "-DSTATIC_LIB_DIR=${STATIC_LIB_DIR}" \
          "-DEXAMPLE=${EXAMPLE}" \
          -S . -B "./build/${TARGET}"
          
    cmake --build "./build/${TARGET}"
    cd ${temp}
}

