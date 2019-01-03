/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fragata.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 8:56 PM
 */

#include "Fragata.h"
#include <math.h>
#include <cstdlib>
Fragata::Fragata():Navio("FFFF", 50, 500, 0) {
    setNumMaxSoldados(50);
}

Navio * Fragata::duplica() const{
    return new Fragata(*this);
}

void Fragata::soldadosComsomemAgua(){
    if(this->getQuantidadeDeAgua()>= this->getNumeroDeSoldados()){
        this->setQuantidadeDeAgua(this->getQuantidadeDeAgua() - getNumeroDeSoldados());
    }
    else{
         int soldadosVivos = this->getNumeroDeSoldados() - this->getQuantidadeDeAgua();
        this->setQuantidadeDeSoldados(soldadosVivos);
        this->setQuantidadeDeAgua(0);
    }
}

void Fragata::reabastecerAguaDoNavio(){
    this->litosDeAgua = 500;
}

void Fragata::setQuantidadeDeAgua(int agua){
    this->litosDeAgua = agua;
}

void Fragata::setQuantidadeDeSoldados(int soldados){
    this->numeroDeSoldados = soldados;
}

int Fragata::getQuantidadeDeAgua() const {
    return litosDeAgua;
}

int Fragata::getNumeroDeSoldados() const {
    return numeroDeSoldados;
}

int Fragata::getCargaTotal()const{
    return cargaTotal;
}

int Fragata::getQuantidadeDePeixe()const{
    return toneladasDePeixe;
}

int Fragata::getQuantidadeDeMercadorias()const{
    return toneladasDeMercadoria;
}

void Fragata::setQuantidadeDePeixe(int peixes){
    this->toneladasDePeixe = peixes;
}

void Fragata::setQuantidadeDeMercadorias(int mercadoria){
    this->toneladasDeMercadoria = mercadoria;
}

void Fragata::setQuantidadeTotalDeCarga(int total){
    this->cargaTotal = total;
}

int Fragata::getVelocidade(){
    return rand() % 2;
}

bool Fragata::getAliancaDoNavio()const{
    return aliado;
}

//barco pertence ao jogador
void Fragata::setAliancaDoNavio(bool a){
    aliado = a;
}