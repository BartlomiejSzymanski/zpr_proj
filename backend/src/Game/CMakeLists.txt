add_library(Game Game.cpp)

target_link_libraries(Game PUBLIC Controler)

target_include_directories(Game PUBLIC .)