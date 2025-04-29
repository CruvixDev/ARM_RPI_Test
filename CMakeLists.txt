cmake_minimum_required(VERSION 3.10.0)

# Include the toolchain file for Raspberry PI (AARCH64 GNU)
include("cmake/aarch64-none-linux-gnu.cmake")

project(ARM_RPI_Test VERSION 0.1.0 LANGUAGES C CXX)

add_executable(${CMAKE_PROJECT_NAME})

target_sources(${CMAKE_PROJECT_NAME} PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR}/src/app_main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/app_s2lp.c  
    ${CMAKE_CURRENT_SOURCE_DIR}/src/app_spi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/S2LP_Library/src/S2LP_Types.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/S2LP_Library/src/S2LP_General.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/S2LP_Library/src/S2LP_Gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/S2LP_Library/src/S2LP_Radio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/S2LP_Library/src/S2LP_PktBasic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/S2LP_Library/src/S2LP_PktWMbus.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/S2LP_Library/src/S2LP_PacketHandler.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/S2LP_Library/src/S2LP_Commands.c
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE

    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/S2LP_Library/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/S2LP_Middleware/STM32/inc
    "C:/Program Files (x86)/Arm GNU Toolchain aarch64-none-linux-gnu/12.2 rel1/aarch64-none-linux-gnu/libc/usr/include/linux/spi"
    "C:/Program Files (x86)/Arm GNU Toolchain aarch64-none-linux-gnu/12.2 rel1/aarch64-none-linux-gnu/libc/usr/include"
)
