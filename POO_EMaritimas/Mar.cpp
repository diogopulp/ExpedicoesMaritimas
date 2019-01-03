/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mar.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 9:00 PM
 */

#include "Mar.h"
#include "Navio.h"
#include "Porto.h"

Mar::Mar() {
    this->car = "~~~~";
}

Mar::Mar(const Mar& orig) {
}

Mar::Mar(Mar& orig){
    
}

Mar::~Mar() {
}

void Mar::setQuantidadeDePeixeNaCelulaMar(int p){
    peixe = p;
}

int Mar::getQuantidadeDePeixeNaCelulaMar(){
    return peixe;
}

void Mar::colocarNavio(Navio* navio){
    this->navio = navio;
    car = navio->getCaractereNavio();
}

void Mar::colocarPorto(Porto* porto){
    this->porto = porto;
    car = porto->getCaracterePorto();
}

void Mar::removerNavio(){
    
    navio = nullptr;
    delete navio;
    
    car = "~~~~";
}