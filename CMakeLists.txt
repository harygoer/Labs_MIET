cmake_minimum_required(VERSION 3.16)
project(hello C)

if(WIN32)
    if(MSVC)
        add_compile_options("/source-charset:utf-8" "/execution-charset:866")
    else()
        add_compile_options(-finput-charset=UTF-8 -fexec-charset=CP866)
    endif()
endif()

add_executable(hello main.c)