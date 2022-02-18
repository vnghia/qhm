add_executable(demo demo.cpp)
target_include_directories(demo PRIVATE ${PROJECT_ROOT_DIR}/source/include)
target_link_libraries(demo PRIVATE qhm)
target_link_libraries(demo PRIVATE Qt::Core Qt::Gui Qt::Widgets
                                   Qt::DataVisualization)
