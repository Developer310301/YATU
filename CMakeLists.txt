cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME TestYATU)
set(LIBRARY_NAME YATU)

project(${PROJECT_NAME})

# Set Sources file
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(INCLUDE_DIR ${BASE_DIR}/include)
set(SOURCES_DIR ${BASE_DIR}/src)
file(GLOB INCLUDE ${INCLUDE_DIR}/*.h)
file(GLOB SOURCES ${SOURCES_DIR}/*.cpp)

# Set the output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BASE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BASE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BASE_DIR}/bin)

add_library(${LIBRARY_NAME} STATIC ${SOURCES} ${INCLUDE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${INCLUDE_DIR})

install(TARGETS ${LIBRARY_NAME})

#add_executable(${PROJECT_NAME} ${BASE_DIR}/test/main.cpp)
#target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
#target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/lib${LIBRARY_NAME}.a)