cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Maze)

file(GLOB_RECURSE SDK_SRC
     "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
     "${CMAKE_CURRENT_LIST_DIR}/include/*.h"
)

set(SOURCES ${SDK_SRC} main.cpp)

include_directories("${CMAKE_CURRENT_LIST_DIR}/include")

# Hide the console window in visual studio projects
if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif()

add_executable(${PROJECT_NAME} ${SOURCES})


## link libraries
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

if(WIN32)
    set(SFML_ROOT "${CMAKE_CURRENT_LIST_DIR}/external/SFML")
    # copy dlls to build directory
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${SFML_DLL_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()

find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()


set(ASSETS_DIR "${CMAKE_CURRENT_LIST_DIR}/assets")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${ASSETS_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)
