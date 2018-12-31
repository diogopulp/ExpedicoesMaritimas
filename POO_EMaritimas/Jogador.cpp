/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jogador.cpp
 * Author: danielmoita
 * 
 * Created on 25 December 2018, 17:07
 */

#include "Jogador.h"

Jogador::Jogador() {
}

Jogador::Jogador(const Jogador& orig) {
}

Jogador::~Jogador() {
}

void Jogador::setNumeroDeMoedas(int moedas){
    numeroTotalDeMoedas += moedas;
}

int Jogador::getNumeroDeMoedas(){
    return numeroTotalDeMoedas;
}