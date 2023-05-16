#!/bin/bash

project_root=$(pwd)

# AVR home for toolchains and header files to link to sources
AVR_TOOLCHAIN_HOME="$project_root/avr8-gnu-toolchain-linux_x86_64" 
AVR_C_COMPILER="${AVR_TOOLCHAIN_HOME}/bin/avr-gcc"
AVR_CXX_COMPILER="${AVR_TOOLCHAIN_HOME}/bin/avr-g++"
AVR_OBJ_COPY="${AVR_TOOLCHAIN_HOME}/bin/avr-objcopy"
AVR_TOOLCHAIN_HEADERS="${AVR_TOOLCHAIN_HOME}/avr/include"

# supported targets
mcu_atmega32A="atmega32"
mcu_atmega328p="atmega328p"

# cmake build caches
source_dir="$project_root/arithmos-core"
examples_dir="$project_root/arithmos-examples"

# AVR-DUDE properties
BAUD_RATE='57600'
PORT='/dev/ttyUSB0'
CHIP='atmega328p'
CHIP_ALIAS='m328p'
PROGRAMMER='arduino'