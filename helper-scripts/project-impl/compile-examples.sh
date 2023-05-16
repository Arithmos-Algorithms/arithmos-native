#!/bin/bash

source "./helper-scripts/abstract/abstract-compile-examples.sh"
source "./helper-scripts/project-impl/variables.sh"

target_mcu=${1}
example=${2}

temp=$(pwd)
cd "${examples_dir}"

compile "${AVR_C_COMPILER}" \
        "${AVR_CXX_COMPILER}" \
        "${AVR_TOOLCHAIN_HEADERS}" \
        "-mmcu=${target_mcu} -O3" \
        "${target_mcu}" \
        "${example}" 
        ""

cd ${temp}
        