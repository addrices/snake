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
    node* head;                     //贪吃蛇的头结点
    SNAKE_STATE state;              //贪吃蛇的运动状态
public:
    snake();    
    void snake_init();              //游戏开始时初始化蛇
    void next_second(bool flag);    //处理下一秒蛇的状态（包括运动和显示）true表示吃到了食物，false表示没吃到
    bool eat(int row,int col);      //处理蛇是否吃到row行，col列的食物
    void show();                    //在页面中打印当前蛇
    void input(char ch);            //处理输入，更改蛇的运动状态
    bool if_death();                //判断当前状态蛇是否死亡
    void snake_destory();           //游戏结束时释放蛇身节点所占用的空间
    ~snake();

};