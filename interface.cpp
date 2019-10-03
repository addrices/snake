#include "interface.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include <stdlib.h>

interface::interface(){
    second = 0;
    show_state = READY_SHOW;
    option = 1;
    score = 0;
}

void interface::show(){
    //show_begin();
    if(show_state == READY_SHOW){
        if(second %2 == 0)
            if(option == 1){
                mvaddch(16,30,'>');
                mvaddch(18,30,' ');
            }
            else{
                mvaddch(18,30,'>');
                mvaddch(16,30,' ');
            }
        else
            if(option == 1)
                mvaddch(16,30,' ');
            else
                mvaddch(18,30,' ');
    }
    else if(show_state == GAMING_SHOW){
        show_begin();
        if(special_flag == false)
            mvprintw(a_row+6,a_col+10,"$");
        else
            mvprintw(a_row+6,a_col+10,"@");
        mvprintw(3,15,"%d",second);
        mvprintw(3,40,"%d",score);
        Snake.show();
    }
    else if(show_state == DEATH_SHOW){
        show_begin();
        mvprintw(15,40,"%d",score);
        refresh();
    }
    mvprintw(29,2,"%d",second);
    refresh();
}

void interface::show_begin(){
    erase();
    if(show_state == READY_SHOW){
        addstr("**********************************************************************************************\n" );
        addstr("*                                                                                            *\n" );
        addstr("*    ||||||||||||    ||\\\\         ||          / \\          ||        ///    ||||||||||||     *\n" );
        addstr("*    ||||||||||||    || \\\\        ||         // \\\\         ||      ///      ||||||||||||     *\n" );
        addstr("*    ||              ||  \\\\       ||        //   \\\\        ||    ///        ||               *\n" );
        addstr("*    ||              ||   \\\\      ||       //     \\\\       ||  ///          ||               *\n" );
        addstr("*    ||||||||||||    ||    \\\\     ||      //       \\\\      ||///            ||||||||||||     *\n" );
        addstr("*    ||||||||||||    ||     \\\\    ||      /////\\\\\\\\\\\\      ||\\\\\\            ||||||||||||     *\n" );
        addstr("*              ||    ||      \\\\   ||     //         \\\\     ||  \\\\\\          ||               *\n" );
        addstr("*              ||    ||       \\\\  ||     //         \\\\     ||    \\\\\\        ||               *\n" );
        addstr("*    ||||||||||||    ||        \\\\ ||    //           \\\\    ||      \\\\\\      ||||||||||||     *\n" );
        addstr("*    ||||||||||||    ||         \\\\||    //           \\\\    ||        \\\\\\    ||||||||||||     *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                       1.START                                              *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                       2.EXIT                                               *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("**********************************************************************************************\n" );        
    }else if(show_state == GAMING_SHOW){
        addstr("**********************************************************************************************\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*       second:                 score:                                                       *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*         ------------------------------------------------------------------------           *\n" );
        addstr("*         |                                                                       |          *\n" );
        addstr("*         |                                                                       |          *\n" );
        addstr("*         |                                                                       |          *\n" );
        addstr("*         |                                                                       |          *\n" );
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         ------------------------------------------------------------------------           *\n" );      
        addstr("*                                                                                            *\n" );      
        addstr("*                                                                                            *\n" );
        addstr("**********************************************************************************************\n" );
    }else if(show_state == DEATH_SHOW){
        addstr("**********************************************************************************************\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                   YOU     DEAD                                             *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*                                                                                            *\n" );
        addstr("*         ------------------------------------------------------------------------           *\n" );
        addstr("*         |                                                                       |          *\n" );
        addstr("*         |                                                                       |          *\n" );
        addstr("*         |                                                                       |          *\n" );
        addstr("*         |                                                                       |          *\n" );
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |               SCORE:                                                  |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         |                                                                       |          *\n" );      
        addstr("*         ------------------------------------------------------------------------           *\n" );      
        addstr("*                                                                                            *\n" );      
        addstr("*                                                                                            *\n" );
        addstr("**********************************************************************************************\n" );        
    }
    refresh();
}

void interface::input(const char ch){
    if(show_state == READY_SHOW){
        if(ch == 's' && option < 2)
            option++;
        if(ch == 'w' && option > 1)
            option--;
        if(ch == 'g'){
            if(option == 2){
                endwin();
                _exit(0);
            }
            else{
                game_init();
                show_state = GAMING_SHOW;
                new_food();
                erase();
                show_begin();
            }
        }
    }
    else if(show_state == GAMING_SHOW){
        Snake.input(ch);
        mvprintw(20,40,"%d",score);
    }
    else if(show_state == DEATH_SHOW){
        show_state = READY_SHOW;
        show_begin();
    }
    refresh();
}

void interface::next_second(){
    second++;
    special_count++;
    if(show_state == GAMING_SHOW){
        if(Snake.eat(a_row,a_col) == true){
            if(special_flag == false){
                Snake.next_second(true);
                score++;
                new_food();
                nom++;
                if(nom == 5){
                    nom = 0;
                    special_flag = true;
                    special_count = 0;
                }
            }
            else{
                score += 40 - special_count;
                Snake.next_second(true);
                special_flag = false;
                new_food();
            }
        }else{
            if(special_flag == true && special_count == 30){
                Snake.next_second(false);
                special_flag = false;
                new_food();
            }
            else
                Snake.next_second(false);
        }
        if(Snake.if_death() == true){
            show_state = DEATH_SHOW;
        }
    }
}

void interface::new_food(){
    srand(time(0));
    a_col = rand() % (WIDTH-1)+1;
    a_row = rand() % (HIGH-1)+1;
    refresh();
}

void interface::game_init(){
    special_flag = false;
    special_count = 0;
    score = 0;
    nom = 0;
    Snake.snake_init();
}