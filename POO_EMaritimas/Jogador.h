/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jogador.h
 * Author: danielmoita
 *
 * Created on 25 December 2018, 17:07
 */

#ifndef JOGADOR_H
#define JOGADOR_H
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

#include "Navio.h"
#include "Porto.h"

using namespace std;

class Jogo;

class Jogador {
private:
    int numeroTotalDeMoedas;
    char portoPrincipal;
    
    vector<Navio*> navios;
    vector<Porto*> portos;
    
public:
    void setNumeroDeMoedas(int moedas);
    int getNumeroDeMoedas();
    void addMaisMoedas(int moedas);
    void dimNumMoedas(int custo);
    Jogador();
    Jogador(const Jogador& orig);
    virtual ~Jogador();

};

#endif /* JOGADOR_H */

