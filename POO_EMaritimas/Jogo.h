/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jogo.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 7:19 PM
 */

#ifndef JOGO_H
#define JOGO_H

#include <vector>
#include "Celula.h"
#include "Mar.h"
#include "Terra.h"
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

class Jogo {

private:
    vector<vector<Celula*> > mapa;
    
public:
    Jogo();
    void constroiMapa(int lin, int col);
    vector<vector<Celula*> > getMapa();
    Jogo(const Jogo& orig);
    virtual ~Jogo();
    void imprimeMapa();


};

#endif /* JOGO_H */

