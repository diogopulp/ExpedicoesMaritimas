/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: daniel
 *
 * Created on 19 de Novembro de 2018, 23:44
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "Jogo.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Jogo jogo;
    
    jogo.constroiMapa(10,10);
    
    for(int i =0; i<10; i++){
        cout << endl;
        for(int j=0; j<10; j++){
            cout << jogo.getMapa()[i][j];
        }
    }   
    return 0;
}

