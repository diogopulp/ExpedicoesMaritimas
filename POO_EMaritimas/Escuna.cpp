/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escuna.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 8:56 PM
 */

#include "Escuna.h"
#include "Jogo.h"

Escuna::Escuna(): Navio('e') {
}

Navio * Escuna::duplica() const{
    return new Escuna(*this);
}

