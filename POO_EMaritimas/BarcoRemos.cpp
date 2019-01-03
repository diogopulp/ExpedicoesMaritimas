/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BarcoRemos.cpp
 * Author: danielmoita
 * 
 * Created on 03 January 2019, 16:17
 */

#include "BarcoRemos.h"

BarcoRemos::BarcoRemos() : Navio("RRRR", 1, 100, 500){
    setNumMaxSoldados(1);
}

Navio * BarcoRemos::duplica() const{
    return new BarcoRemos(*this);
}


// verificar  se o navio esta na agua ou no porto
void BarcoRemos::soldadosComsomemAgua(){
    if(this->getQuantidadeDeAgua()>= this->getNumeroDeSoldados()){
        this->setQuantidadeDeAgua(this->getQuantidadeDeAgua() - getNumeroDeSoldados());
    }
    else{
         int soldadosVivos = this->getNumeroDeSoldados() - this->getQuantidadeDeAgua();
        this->setQuantidadeDeSoldados(soldadosVivos);
        this->setQuantidadeDeAgua(0);
    }
}

void BarcoRemos::reabastecerAguaDoNavio(){
    this->litosDeAgua = 100;
}

void BarcoRemos::setQuantidadeDeAgua(int agua){
    this->litosDeAgua = agua;
}

void BarcoRemos::setQuantidadeDeSoldados(int soldados){
    this->numeroDeSoldados = soldados;
}

int BarcoRemos::getQuantidadeDeAgua() const {
    return litosDeAgua;
}

int BarcoRemos::getNumeroDeSoldados() const {
    return numeroDeSoldados;
}

int BarcoRemos::getCargaTotal()const{
    return cargaTotal;
}

int BarcoRemos::getQuantidadeDePeixe()const{
    return toneladasDePeixe;
}

int BarcoRemos::getQuantidadeDeMercadorias()const{
    return toneladasDeMercadoria;
}

void BarcoRemos::setQuantidadeDePeixe(int peixes){
    this->toneladasDePeixe = peixes;
}

void BarcoRemos::setQuantidadeDeMercadorias(int mercadoria){
    this->toneladasDeMercadoria = mercadoria;
}

void BarcoRemos::setQuantidadeTotalDeCarga(int total){
    this->cargaTotal = total;
}

int BarcoRemos::getVelocidade(){
    return 1;
}

int BarcoRemos::pescar(int peixe){
    if(this->getQuantidadeDePeixe() + peixe <= this->getCargaTotal()){
        this->setQuantidadeDePeixe(this->getQuantidadeDePeixe() + peixe);
        return 0;
    }
    else{
        int peixeTotal = this->getQuantidadeDePeixe() + peixe;
        int peixeEscunaFinal = peixeTotal - this->getCargaTotal();
        this->setQuantidadeDePeixe(peixe - peixeEscunaFinal);
        return peixeTotal - peixeEscunaFinal;
    }
}

bool BarcoRemos::getAliancaDoNavio()const{
    return aliado;
}

//barco pertence ao jogador
void BarcoRemos::setAliancaDoNavio(bool a){
    aliado = a;
}

