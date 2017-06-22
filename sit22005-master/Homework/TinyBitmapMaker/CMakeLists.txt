PROJECT(TinyBitmapMaker)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
file(COPY ./image DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

#add_subdirectory(lucidUtil)
add_subdirectory(tinybmp_maker)
add_subdirectory(test_suite)
