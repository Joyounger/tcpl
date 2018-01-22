PROJECT(tcpl_chap1)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)


ADD_EXECUTABLE(1_5_4 1_5_4.c)
ADD_EXECUTABLE(1.9-CharacterArrays 1.9-CharacterArrays.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./exercise/) #设置属性CMAKE_RUNTIME_OUTPUT_DIRECTORY，控制编译出的可执行文件的输出路径
ADD_EXECUTABLE(1-2 ./exercise/1-2.c)
ADD_EXECUTABLE(1-3 ./exercise/1-3.c)
ADD_EXECUTABLE(1-4 ./exercise/1-4.c)
ADD_EXECUTABLE(1-5 ./exercise/1-5.c)
ADD_EXECUTABLE(1-6 ./exercise/1-6.c)
ADD_EXECUTABLE(1-7 ./exercise/1-7.c)
ADD_EXECUTABLE(1-8 ./exercise/1-8.c)
ADD_EXECUTABLE(1-9 ./exercise/1-9.c)
ADD_EXECUTABLE(1-10 ./exercise/1-10.c)
ADD_EXECUTABLE(1-12 ./exercise/1-12.c)
ADD_EXECUTABLE(1-14 ./exercise/1-14.c)
ADD_EXECUTABLE(1-15 ./exercise/1-15.c)
ADD_EXECUTABLE(1-17 ./exercise/1-17.c)