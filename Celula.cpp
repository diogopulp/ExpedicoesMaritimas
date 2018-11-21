/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Celula.cpp
 * Author: daniel
 * 
 * Created on 20 de Novembro de 2018, 21:50
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

ostream& operator<<(ostream& os, const Celula& cel)  
{  
    os << cel.car;  
    return os; 
}  

