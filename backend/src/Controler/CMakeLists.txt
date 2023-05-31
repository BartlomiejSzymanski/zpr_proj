add_library(Controler Controler.cpp)

target_link_libraries(Controler PUBLIC Board)

target_include_directories(Controler PUBLIC .)