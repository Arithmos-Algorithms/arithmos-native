#!/bin/bash

source "./helper-scripts/abstract/abstract-upload.sh"
source "./helper-scripts/project-impl/variables.sh"

elf=${1}
directory=${2}

convertToHex ${AVR_OBJ_COPY} ${elf} ${directory}
upload ${PROGRAMMER} ${BAUD_RATE} ${PORT} ${CHIP_ALIAS} ${elf} ${directory}