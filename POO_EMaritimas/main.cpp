/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: diogosantos
 *
 * Created on November 22, 2018, 7:16 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <ncurses.h>

#include "Jogo.h"

using namespace std;

int main(int argc, char** argv) {
    
    WINDOW *game_win;
    int HEIGHT = 10;
    int WIDTH = 20;
    int starty = 0;
    int startx = 0;
    
    /*initscr(); // initializes the terminal in curses mode
    raw(); // funcao imediatamente depois da initscr
    cbreak(); // funcao imediatamente depois da initscr
    noecho(); //These functions control the echoing of
              //characters typed by the user to the terminal.
              //noecho() switches off echoing
    clear();
    
    
    game_win = newwin(HEIGHT, WIDTH, starty, startx); // CRIA JANELA DE JOGO
    wrefresh(game_win);*/
    
    
    Jogo jogo;
    jogo = Jogo();
    jogo.constroiMapa(10,20);
    jogo.imprimeMapa();
    //jogo.print_game(game_win,starty,startx);
    
    return 0;
}


