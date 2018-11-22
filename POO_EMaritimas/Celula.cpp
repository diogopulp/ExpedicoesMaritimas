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
    
    car = "x";
    
}

Celula::Celula(const Celula& orig) {
}

Celula::~Celula() {
}

string Celula::getCarater(){
    return car;
}


