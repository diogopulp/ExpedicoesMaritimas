/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jogo.h
 * Author: daniel
 *
 * Created on 20 de Novembro de 2018, 21:48
 */

#ifndef JOGO_H
#define JOGO_H

#include <vector>
#include "Celula.h"

using namespace std;

class Jogo {

private:
    vector<vector<Celula>> mapa;
    
public:
    Jogo();
    void constroiMapa(int lin, int col);
    vector<vector<Celula>> getMapa();
    Jogo(const Jogo& orig);
    virtual ~Jogo();


};

#endif /* JOGO_H */

