cmake_minimum_required(VERSION 3.10)
project(audio-gn)

set(CMAKE_CXX_STANDARD 11)

add_executable(audio-gn main.cpp wav.h)


if (WIN32)
    set(CMAKE_INSTALL_PREFIX "C:\\Program Files\\")
elseif (UNIX)
    set(CMAKE_INSTALL_PREFIX /usr/local/bin/)
endif ()

install(TARGETS audio-gn DESTINATION ${CMAKE_INSTALL_PREFIX})