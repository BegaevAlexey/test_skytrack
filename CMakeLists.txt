cmake_minimum_required(VERSION 3.12)
project(test_skytrack)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE(OpenCV REQUIRED)

set(HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/paramcallback.h
        )

set(SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/paramcallback.cpp
        )

set(INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/src/
        )

set(LIBS
        ${OpenCV_LIBS}
        config++
        )

add_executable(${PROJECT_NAME} main.cpp  ${SOURCE} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${LIBS} ${OpenMP_CXX_FLAGS})