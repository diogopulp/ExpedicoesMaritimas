/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escuna.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 8:56 PM
 */

#ifndef ESCUNA_H
#define ESCUNA_H

#include <stdio.h>

#include "Navio.h"

using namespace std;

class Jogo;

class Escuna : public Navio{

public:
    Escuna();
    Escuna(const Escuna& orig);
    virtual ~Escuna();
    //Navio * duplica()const override;
    void pescar();
    
    //void abastecerNavioComAgua();
    //int moverNavio(int direcao);
    //void navegar(int px, int py);
    //void alimentaSoldados();
    



    
};

#endif /* ESCUNA_H */

