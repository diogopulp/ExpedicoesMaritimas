/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Veleiro.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 8:56 PM
 */

#include "Veleiro.h"

Veleiro::Veleiro(): Navio('v') {
}

void Veleiro::navegar(int posx, int posy){
    
}

Navio * Veleiro::duplica() const{
    return new Veleiro(*this);
}