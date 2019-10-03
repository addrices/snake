#include <ncurses.h>
#include "interface.hpp"
#include "snake.hpp"
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int kbhit(void){
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]){
    initscr();                  //初始化
    cbreak();                   // 接受单个字符处理  禁止行缓冲
    nonl();
    noecho();
    keypad(stdscr,TRUE);        //指定窗口 激活功能键  上下左右 F1 F2等
    interface interface;
    interface.show_begin();
    interface.show();
    char ch = ' ';
    int a = 23;
    while(1){
        refresh();
        if(kbhit()){
            ch = getchar();
            mvprintw(28,2,"%c",ch);
            refresh();
            interface.input(ch);
        }
        interface.show();
        usleep(100000);
        interface.next_second();
    }
    endwin();
    return 0;
}