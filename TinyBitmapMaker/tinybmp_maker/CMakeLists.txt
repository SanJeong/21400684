PROJECT(tinybmp_maker)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(tbm tinybmp.cpp tinybmp_maker.cpp tbm.cpp)