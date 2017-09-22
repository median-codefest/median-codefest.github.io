cmake_minimum_required(VERSION 3.0)

project(anatomyVR)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS_RELEASE "/MT")

include(BasicConfig)


	
find_package(Oculus REQUIRED)
find_package(GLFW REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
find_package(Freenect2 REQUIRED)



file(GLOB_RECURSE SRC "src/*")
file(GLOB_RECURSE GFX "graphics/*")
file(GLOB_RECURSE SHD "shaders/*")
file(GLOB_RECURSE HDR "Common/Win32_GLAppUtil.h")


list(APPEND SRC ${GFX})
list(APPEND SRC ${RES})
list(APPEND SRC ${SHD})
list(APPEND SRC ${HDR})

add_executable(${PROJECT_NAME} ${SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")

target_include_directories(${PROJECT_NAME} PUBLIC ${OCULUS_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC "Common")
target_include_directories(${PROJECT_NAME} PUBLIC "graphics")
target_include_directories(${PROJECT_NAME} PUBLIC ${GLEW_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${GLM_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${FREENECT2_INCLUDE_PATH})
target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW_INCLUDE_DIR})


target_link_libraries(${PROJECT_NAME} PUBLIC ${OCULUS_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${FREENECT2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${GLEW_LIBRARY})
target_link_libraries(${PROJECT_NAME} PUBLIC ${GLFW_LIBRARIES})




add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/shaders/
                ${PROJECT_BINARY_DIR}/bin/$(Configuration)/shaders/)
				
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/shaders/
                ${PROJECT_BINARY_DIR}/shaders/)
				
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/resources/
                ${PROJECT_BINARY_DIR}/bin/$(Configuration)/resources/)
				
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/resources/
                ${PROJECT_BINARY_DIR}/resources/)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/meshes/
                ${PROJECT_BINARY_DIR}/bin/$(Configuration)/meshes/)
				
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/meshes/
                ${PROJECT_BINARY_DIR}/meshes/)