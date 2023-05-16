#!/bin/bash

source "./helper-scripts/abstract/abstract-compile.sh"
source "./helper-scripts/project-impl/variables.sh"

compile "${AVR_C_COMPILER}" \
        "${AVR_CXX_COMPILER}" \
        "${AVR_TOOLCHAIN_HEADERS}" \
        "-mmcu=${mcu_atmega328p} -O3" \
        "ALL" \
        "${mcu_atmega328p}" \
        ${source_dir}
