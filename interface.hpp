#pragma once
#include "snake.hpp"

#define READY_SHOW 1
#define GAMING_SHOW 2
#define DEATH_SHOW 3

class interface{
private:
    int second;
    int show_state;
    int option;
    int score;
    int history_score;
    int a_row;
    int a_col;
    bool special_flag;
    int special_count;
    int nom;
    snake Snake;
public:
    interface();
    void show_begin();
    void show();
    void input(const char ch);
    void next_second();
    void new_food();
    void game_init();
};