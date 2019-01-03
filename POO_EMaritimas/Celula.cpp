/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Celula.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 7:18 PM
 */

#include "Celula.h"

Celula::Celula() {
    
}

Celula::Celula(const Celula& orig) {
}

Celula::~Celula() {
}

void Celula::setCaratere(string caracter) {
    car = caracter;
}

string Celula::getCaratere() const{
    return car;
}


