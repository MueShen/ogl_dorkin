cmake_minimum_required(VERSION 3.2)
project(Dorkdote)

find_package(OpenGL)
set(GLFWDIR "~/Code/vnd/")



file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.c")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/include/*.h")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")



add_executable(core ${SOURCES} ${HEADERS})


target_compile_options(core PRIVATE -Wall  )

target_include_directories(core PUBLIC ${GLFWDIR} ${OPENGL_INCLUDE_DIR}) 
target_link_directories(core PUBLIC ${GLFWDIR} ${OPENGL_INCLUDE_DIR})
target_link_libraries(core ${OPENGL_gl_LIBRARY} glfw X11)
