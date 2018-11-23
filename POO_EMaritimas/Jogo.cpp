/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jogo.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 7:19 PM
 */

#include "Jogo.h"
#include "Terra.h"

Jogo::Jogo() {
   
}

void Jogo::constroiMapa(int lin, int col){
    
    for(int i = 0; i <lin ; i++){
            
        vector<Celula*> temp;
        
            for( int j = 0; j<col; j++){
              
                int num = rand() % 101;
                
                    if(num<90){
                        temp.push_back(new Mar());
                    }else{
                        temp.push_back(new Terra());
                    }
                }
  
                mapa.push_back(temp);
            }
    
            
    }

void Jogo::imprimeMapa(){
    for(int i =0; i<mapa.size(); i++){
        cout << endl;
        for(int j=0; j<mapa[i].size(); j++){
            cout << mapa[i][j]->getCarater()[0];
            cout << mapa[i][j]->getCarater()[1] << " ";
           
            
        }
        cout << endl;
        for(int j=0; j<mapa[i].size(); j++){
            cout << mapa[i][j]->getCarater()[2];
            cout << mapa[i][j]->getCarater()[3] << " ";
        }
    }   
}

void Jogo::print_game(WINDOW* game_win, int highlightx, int highlighty){
    
    /*box(game_win, 0, 0);
    
    for(int i =0; i<mapa.size(); i++){       
        
        for(int j=0; j<mapa[i].size(); j++){          
            wattron(game_win,COLOR_PAIR(2));
            mvwprintw(game_win, i, j, "%c", mapa[i][j]->getCarater()[0]);
            mvwprintw(game_win, i, j, "%c", mapa[i][j]->getCarater()[1]);     
            wattroff(game_win,COLOR_PAIR(2));   
        }
    
        for(int j=0; j<mapa[i].size(); j++){
            wattron(game_win,COLOR_PAIR(2));
            mvwprintw(game_win, i, j, "%c", mapa[i][j]->getCarater()[2]);
            mvwprintw(game_win, i, j, "%c", mapa[i][j]->getCarater()[3]);
            wattroff(game_win,COLOR_PAIR(2));      
        }
    }  */ 
}

Jogo::Jogo(const Jogo& orig) {
}

vector<vector<Celula*> > Jogo::getMapa(){
    return mapa;
}

Jogo::~Jogo() {
}

