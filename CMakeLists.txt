cmake_minimum_required(VERSION 3.17)

project(cuda_video_stub
  VERSION 0.1.0
  LANGUAGES
  C CUDA)

if(NOT DEFINED ${CMAKE_CUDA_ARCHITECTURES})
  set(CMAKE_CUDA_ARCHITECTURES 75)
endif()

enable_language(CUDA)
find_package(CUDAToolkit REQUIRED COMPONENT cuda_driver)

set(version 12.1.14)
add_library(nvcuvid-stub SHARED stub.c)
set_target_properties(nvcuvid-stub PROPERTIES OUTPUT_NAME "nvcuvid")
target_include_directories(nvcuvid-stub PUBLIC "${version}")
target_link_libraries(nvcuvid-stub CUDA::cudart)
