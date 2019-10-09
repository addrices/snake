#pragma once
#include "snake.hpp"

#define READY_SHOW 1
#define GAMING_SHOW 2
#define GAMING_SHOW_2 3
#define DEATH_SHOW 4

class interface{
private:
    int second;                     //当前游戏执行时间
    int show_state;                 //当前游戏所处的状态  有MENU，GAMING，DEAD3种
    int option;                     //menu中的选项
    int a_row;                      //当前食物所在行
    int a_col;                      //当前食物所在列
    bool special_flag;              //当前食物是否为特殊食物
    int special_count;              //特殊食物的倒计时
    int nom;                        //普通食物的技术，为特殊食物产生做准备
    snake Snake;                    //贪吃蛇
    snake Snake2;                   //贪吃蛇
public:
    interface();
    void show_begin();              //页面展示（更新整个页面）
    void show();                    //根据当前所处的状态修改某几个位置的字符
    void input(const char ch);      //对输入进行对应的判断
    void next_second();             //更新下一秒的状态
    bool new_food();                //生成新的食物
    void game_init();               //启动新游戏的准备，score清理，snake重新生成等。
};