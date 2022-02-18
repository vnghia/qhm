file(GLOB HEADER_FILES include/*.h)
file(GLOB SRC_FILES src/*.cpp)

add_library(qhm ${HEADER_FILES} ${SRC_FILES})

target_include_directories(qhm PRIVATE ${PROJECT_ROOT_DIR}/source/include)
target_link_libraries(qhm PRIVATE Qt::Core Qt::Gui Qt::Widgets
                                  Qt::DataVisualization)
