/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Navio.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 8:53 PM
 */

#include "Navio.h"

Navio::Navio() {
    this->idNavio = this->identificador++;
}

Navio::Navio(const Navio& orig) {
}

Navio::~Navio() {
}

void Navio::setPosicaoAtualX(int x){
    posicaoAtualX = x;
}

void Navio::setPosicaoAtualY(int y){
    posicaoAtualY = y;
}

void Navio::setTipoNavio(char tipo) {
    this->tipo = tipo;
}

int Navio::getPosicaoAtualX(){
    return posicaoAtualX;
}

int Navio::getPosicaoAtualY(){
    return posicaoAtualY;
}

int Navio::getIdentificadorNavio() {
    return idNavio;
}

char Navio::getTipoNavio() {
    return tipo;
}

