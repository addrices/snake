#include <ncurses.h>
#include "snake.hpp"

snake::snake(){
    snake_init();
}

void snake::snake_init(){
    node* a = new node;
    node* b = new node;
    node* c = new node;
    a->next = b;
    b->next = c;
    c->next = NULL;
    a->col = WIDTH/2;
    b->col = a->col + 1;
    c->col = b->col + 1;
    a->row = HIGH/2;
    b->row = a->row;
    c->row = b->row;
    head = a;
    state = LEFT;
}

void snake::next_second(bool flag){
    node* new_head = new node;
    switch (state)
    {
        case UP:new_head->col = head->col; new_head->row = head->row - 1; break;
        case DOWN:new_head->col = head->col; new_head->row = head->row + 1; break;
        case LEFT:new_head->col = head->col - 1; new_head->row = head->row; break;
        case RIGHT:new_head->col = head->col + 1; new_head->row = head->row; break;
        default: break;
    }
    new_head->next = head;
    head = new_head;
    node* current = head;
    while(current->next->next != NULL){
        current = current->next;
    }
    if(flag == false){
        delete(current->next);
        current->next = NULL;
    }
}

void snake::show(){
    node* current = head;
    while(current != NULL){
        mvprintw(current->row+6,current->col+10,"0");
        current = current->next;
        refresh();
    }
}

void snake::input(char ch){
    if(ch == 'w' && state != DOWN){
        state = UP;
    }
    else if(ch == 's' && state != UP){
        state = DOWN;
    }
    else if(ch == 'a' && state != RIGHT){
        state = LEFT;
    }
    else if(ch == 'd' && state != LEFT){
        state = RIGHT;
    }
}

bool snake::if_death(){
    if(head->col <= 0 || head->col >= WIDTH || head->row <= 0 || head->row >= HIGH){
        snake_destory();
        return true;
    }
    node* current = head->next;
    while(current != NULL){
        if(current->col == head->col && current->row == head->row){
            snake_destory();
            return true;
        }
        current = current->next;
    }
    return false;
}

bool snake::eat(int row,int col){
    if(head->col == col && head->row == row)
        return true;
    return false;
}

void snake::snake_destory(){
    node* current = head;
    while(current != NULL){
        node* n = current->next;
        delete(current);
        current = n;
    }
    return;
}

snake::~snake(){
    snake_destory();
}