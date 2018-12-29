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

Escuna::Escuna() : Navio('E'){
    
}

Navio * Escuna::duplica() const{
    return new Escuna(*this);
}


// verificar  se o navio esta na agua ou no porto
void Escuna::soldadosComsomemAgua(){
    if(this->getQuantidadeDeAgua()>= this->getNumeroDeSoldados()){
        this->setQuantidadeDeAgua(this->getQuantidadeDeAgua() - getNumeroDeSoldados());
    }
    else{
         int soldadosVivos = this->getNumeroDeSoldados() - this->getQuantidadeDeAgua();
        this->setQuantidadeDeSoldados(soldadosVivos);
        this->setQuantidadeDeAgua(0);
    }
}

void Escuna::reabastecerAguaDoNavio(){
    this->litosDeAgua = 100;
}

void Escuna::setQuantidadeDeAgua(int agua){
    this->litosDeAgua = agua;
}

void Escuna::setQuantidadeDeSoldados(int soldados){
    this->numeroDeSoldados = soldados;
}

int Escuna::getQuantidadeDeAgua() const {
    return litosDeAgua;
}

int Escuna::getNumeroDeSoldados() const {
    return numeroDeSoldados;
}

int Escuna::getCargaTotal()const{
    return cargaTotal;
}

int Escuna::getQuantidadeDePeixe()const{
    return toneladasDePeixe;
}

int Escuna::getQuantidadeDeMercadorias()const{
    return toneladasDeMercadoria;
}

void Escuna::setQuantidadeDePeixe(int peixes){
    this->toneladasDePeixe = peixes;
}

void Escuna::setQuantidadeDeMercadorias(int mercadoria){
    this->toneladasDeMercadoria = mercadoria;
}

void Escuna::setQuantidadeTotalDeCarga(int total){
    this->cargaTotal = total;
}