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

Jogo::Jogo() {
   
}

void Jogo::constroiMapa(int lin, int col){
    for(int i = 0; i <lin ; i++){
            
        vector<Celula> temp;
        {
            for( int j = 0; j<col; j++){
                temp.push_back(Celula());
            }
            mapa.push_back(temp);
        }
    }
}

Jogo::Jogo(const Jogo& orig) {
}

vector<vector<Celula> > Jogo::getMapa(){
    return mapa;
}

Jogo::~Jogo() {
}

