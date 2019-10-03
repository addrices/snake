#pragma once

#define WIDTH 72
#define HIGH 22

enum SNAKE_STATE{
    UP, DOWN, LEFT, RIGHT
};

struct node{
    node* next;
    int row;
    int col;
};

class snake{
private:
    node* head;
    SNAKE_STATE state;
public:
    snake();
    void snake_init();
    void show_snake();
    void next_second(bool flag);
    bool eat(int row,int col);
    void show();
    void input(char ch);
    bool if_death();
    void snake_destory();
    ~snake();

};