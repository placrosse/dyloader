cmake_minimum_required(VERSION 2.6)

project("dyloader" C)

include_directories("include")

if (CMAKE_COMPILER_IS_GNUCC)
	set (CMAKE_C_FLAGS "-Wall -Wextra -Werror -Wfatal-errors")
endif (CMAKE_COMPILER_IS_GNUCC)

add_subdirectory("lib")

enable_testing()
