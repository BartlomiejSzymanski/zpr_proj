add_library(controler Controler.cpp)

target_link_libraries(controler PUBLIC board)
target_include_directories(controler PUBLIC .)
