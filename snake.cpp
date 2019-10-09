#include <ncurses.h>
#include "snake.hpp"

snake::snake(int i){
    snake_init(i);
}

void snake::snake_init(int i){
    node* a = new node;
    node* b = new node;
    node* c = new node;
    a->next = b;
    b->next = c;
    c->next = NULL;

    if(i == 1){
        a->col = WIDTH/2;
        b->col = a->col + 1;
        c->col = b->col + 1;
        a->row = HIGH/2;
        state = LEFT;
        p1_p2 = true;
    }
    else{
        a->col = WIDTH/2;
        b->col = a->col - 1;
        c->col = b->col - 1;
        a->row = HIGH/2 + 1;
        state = RIGHT;
        p1_p2 = false;
    }
    b->row = a->row;
    c->row = b->row;
    head = a;
    score = 0;
}

node* snake::get_head(){
    return head;
}

int snake::get_score(){
    return score;
}

void snake::add_score(int s){
    score += s;
    return;
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
    if(p1_p2 == true){
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
    }else{
        if(ch == 'i' && state != DOWN){
            state = UP;
        }
        else if(ch == 'k' && state != UP){
            state = DOWN;
        }
        else if(ch == 'j' && state != RIGHT){
            state = LEFT;
        }
        else if(ch == 'l' && state != LEFT){
            state = RIGHT;
        }        
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

bool snake::another_death(const node* const n){
    node* current = head;
    while(current != NULL){
        if(current->col == n->col && current->row == n->row){
            snake_destory();
            return true;
        }
        current = current->next;
    }
    return false;
}

snake::~snake(){
    snake_destory();
}