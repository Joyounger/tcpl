PROJECT(tcpl_chap2)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)


ADD_EXECUTABLE(2.7-rand 2.7-rand.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./exercise/) #设置属性CMAKE_RUNTIME_OUTPUT_DIRECTORY，控制编译出的可执行文件的输出路径
ADD_EXECUTABLE(2-1 ./exercise/2-1.c)
ADD_EXECUTABLE(2-1v2 ./exercise/2-1v2.c)
ADD_EXECUTABLE(2-2 ./exercise/2-2.c)
ADD_EXECUTABLE(2-3 ./exercise/2-3.c)
ADD_EXECUTABLE(2-4 ./exercise/2-4.c)
ADD_EXECUTABLE(2-5 ./exercise/2-5.c)
ADD_EXECUTABLE(2-6 ./exercise/2-6.c)
ADD_EXECUTABLE(2-9 ./exercise/2-9.c)
ADD_EXECUTABLE(2-10 ./exercise/2-10.c)
