add_library(HumanPlayer HumanPlayer.cpp)

target_link_libraries(HumanPlayer PUBLIC Player)
target_include_directories(HumanPlayer PUBLIC .)