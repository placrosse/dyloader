cmake_minimum_required(VERSION 2.6)

add_executable("dyloader-cli" "dyloader.c")

set_target_properties("dyloader-cli" PROPERTIES OUTPUT_NAME "dyloader")

target_link_libraries("dyloader-cli" "dyloader" "dyloader-builtin" "dyloader-elf")
