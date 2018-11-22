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

#include "Jogo.h"

using namespace std;

int main(int argc, char** argv) {

    Jogo jogo;
    jogo = Jogo();
    jogo.constroiMapa(10,10);
    
    
    for(int i =0; i<jogo.getMapa().size(); i++){
        cout << endl;
        for(int j=0; j<jogo.getMapa()[i].size(); j++){
            cout << jogo.getMapa()[i][j]->getCarater();
        }
    }   
    return 0;
}

