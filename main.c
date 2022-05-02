#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <time.h>
#include "lib/menu.h"

#define clrscr() printf("\e[1;1H\e[2J")

#define menu_size 100

void draw_main_menu(){
    draw_top_menu(menu_size);
    draw_blank_line(menu_size);
    center_text(menu_size, "The Hangman Game");
    draw_blank_line(menu_size);
    draw_vertical_line(1);
    draw_horizontal_line(menu_size);
    draw_vertical_line(1);
    new_line();
    draw_blank_line(menu_size);
    center_text(menu_size, "Choose an option:");
    draw_blank_line(menu_size);
    draw_hangman(menu_size, 6);
    center_text(menu_size, "1. Play the game");
    center_text(menu_size, "2. Dictionary   ");
    center_text(menu_size, "3. Credits      ");
    center_text(menu_size, "4. Exit         ");
    draw_blank_line(menu_size);
    draw_bottom_menu(menu_size);
}


int main(){
    clrscr();
    int option = 0;
    while(1){
        draw_main_menu();
        scanf("%d", &option);
        switch(option){
            case 1:
                clrscr();
                
                break;
        }
        sleep(1000);
    }
    
}