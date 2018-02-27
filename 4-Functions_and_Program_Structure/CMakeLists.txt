PROJECT(tcpl_chap4)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)



#ADD_EXECUTABLE(4-1 4-1.c)
#设置属性CMAKE_RUNTIME_OUTPUT_DIRECTORY，控制编译出的可执行文件的输出路径，这里将1.5和1.6这两个elf的输出目录设为了./exercise/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./exercise/)
ADD_EXECUTABLE(4-1 ./exercise/4-1.c)

LINK_LIBRARIES(m)
ADD_EXECUTABLE(4-2 ./exercise/4-2.c) #exercise 4-2 编译时需要链接数学库m gcc 4-2.c -o 4-2 -lm