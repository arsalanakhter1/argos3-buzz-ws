cmake_minimum_required(VERSION 2.8.12)

include_directories(/usr/include/lua5.2)
find_package(Qt5 COMPONENTS Widgets Gui)

find_package(OpenGL)

link_directories(${CMAKE_BINARY_DIR}../buzz/src/buzz/argos/buzz_controller_footbot)
set(energy_loop_functions_SOURCES energy_loop_functions.cpp)

if(ARGOS_COMPILE_QTOPENGL)
  set(energy_loop_functions_SOURCES
    ${energy_loop_functions_SOURCES}
    energy_qt_user_functions.cpp)
endif(ARGOS_COMPILE_QTOPENGL)

add_library(energy_loop_functions MODULE 
  energy_loop_functions.h
  energy_qt_user_functions.h
  energy_loop_functions.cpp
  energy_qt_user_functions.cpp)

target_link_libraries(energy_loop_functions
  argos3core_simulator
  argos3plugin_simulator_entities
  argos3plugin_simulator_footbot
  argos3plugin_simulator_qtopengl
  ${ARGOS_QTOPENGL_LIBRARIES})

if(ARGOS_COMPILE_QTOPENGL)
  target_link_libraries(energy_loop_functions argos3plugin_simulator_qtopengl)
endif(ARGOS_COMPILE_QTOPENGL)
