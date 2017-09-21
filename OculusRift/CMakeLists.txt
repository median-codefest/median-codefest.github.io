cmake_minimum_required(VERSION 3.0)

project(anatomyVR)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(Oculus REQUIRED)

file(GLOB_RECURSE SRC "src/*")
file(GLOB_RECURSE CMN "Common/*")

list(APPEND SRC ${CMN})

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${OCULUS_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC "Common")

target_link_libraries(${PROJECT_NAME} PUBLIC ${OCULUS_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PUBLIC  "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.15063.0/um/x64/dxgi.lib")
target_link_libraries(${PROJECT_NAME} PUBLIC  "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.15063.0/um/x64/d3d11.lib")
