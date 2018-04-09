cmake_minimum_required(VERSION 2.6)

add_library("dyloader"
	"buffer.c"
	"dyloader.c"
	"host.c")

if (UNIX)
	add_library("dyloader-builtin" "builtin.c" "host-linux.c")
endif (UNIX)

add_executable("sample" "sample.c")

function(ADD_DYLOADER_TEST TEST)
	add_executable(${TEST} ${ARGN})
	target_link_libraries(${TEST} "dyloader" "dyloader-builtin")
	add_test(${TEST} ${TEST})
endfunction(ADD_DYLOADER_TEST TEST)

add_dyloader_test("dyloader-test" "dyloader-test.c")

enable_testing()
