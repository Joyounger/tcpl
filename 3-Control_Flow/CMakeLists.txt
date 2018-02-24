PROJECT(tcpl_chap3)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)


ADD_EXECUTABLE(atoi_v2 atoi_v2.c)
ADD_EXECUTABLE(shellsort shellsort.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./exercise/) #设置属性CMAKE_RUNTIME_OUTPUT_DIRECTORY，控制编译出的可执行文件的输出路径
ADD_EXECUTABLE(3-1 ./exercise/3-1.c)
ADD_EXECUTABLE(3-2 ./exercise/3-2.c)
ADD_EXECUTABLE(3-3 ./exercise/3-3.c)
ADD_EXECUTABLE(3-5 ./exercise/3-5.c)
ADD_EXECUTABLE(3-6 ./exercise/3-6.c)
