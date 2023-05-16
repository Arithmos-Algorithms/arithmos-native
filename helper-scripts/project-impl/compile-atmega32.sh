#!/bin/bash

source "./helper-scripts/abstract/abstract-compile.sh"
source "./helper-scripts/project-impl/variables.sh"

compile "${AVR_C_COMPILER}" \
        "${AVR_CXX_COMPILER}" \
        "${AVR_TOOLCHAIN_HEADERS}" \
        "-mmcu=${mcu_atmega32A} -O3" \
        "ALL" \
        "${mcu_atmega32A}" \
        ${source_dir}
