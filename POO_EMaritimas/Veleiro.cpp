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

#include <regex>

#include "Veleiro.h"

Veleiro::Veleiro() : Navio("VVVV",20, 200, 40){
    setNumMaxSoldados(20);
}

Navio * Veleiro::duplica()const{
    return new Veleiro(*this);
}

void Veleiro::soldadosComsomemAgua(){
    if(this->getQuantidadeDeAgua()>= this->getNumeroDeSoldados()){
        this->setQuantidadeDeAgua(this->getQuantidadeDeAgua() - getNumeroDeSoldados());
    }
    else{
         int soldadosVivos = this->getNumeroDeSoldados() - this->getQuantidadeDeAgua();
        this->setQuantidadeDeSoldados(soldadosVivos);
        this->setQuantidadeDeAgua(0);
    }
}

void Veleiro::setQuantidadeDeAgua(int agua){
    this->litosDeAgua = agua;
}

void Veleiro::setQuantidadeDeSoldados(int soldados){
    this->numeroDeSoldados = soldados;
}

int Veleiro::getQuantidadeDeAgua() const {
    return litosDeAgua;
}

int Veleiro::getNumeroDeSoldados() const {
    return numeroDeSoldados;
}

int Veleiro::getCargaTotal()const{
    return cargaTotal;
}

int Veleiro::getQuantidadeDePeixe()const{
    return toneladasDePeixe;
}

int Veleiro::getQuantidadeDeMercadorias()const{
    return toneladasDeMercadoria;
}

void Veleiro::setQuantidadeDePeixe(int peixes){
    this->toneladasDePeixe = peixes;
}

void Veleiro::setQuantidadeDeMercadorias(int mercadoria){
    this->toneladasDeMercadoria = mercadoria;
}

void Veleiro::setQuantidadeTotalDeCarga(int total){
    this->cargaTotal = total;
}

void Veleiro::reabastecerAguaDoNavio() {
    this->litosDeAgua = 200;
}

int Veleiro::getVelocidade(){
    return rand() % 2;
}

//lembrar de fazer verificacao de adjacencia
void Veleiro::transferePeixe(Escuna *e){
   
    if(this->getCargaTotal() >= this->getQuantidadeDePeixe() + this->getQuantidadeDeMercadorias() + e->getQuantidadeDePeixe()){
        this->setQuantidadeDePeixe(this->getQuantidadeDePeixe() + e->getQuantidadeDePeixe());
        e->setQuantidadeDePeixe(0);
    }
    else{
        int peixeTotal = this->getQuantidadeDePeixe() + e->getQuantidadeDePeixe();
        int peixeEscunaFinal = peixeTotal - this->getCargaTotal();
        this->setQuantidadeDePeixe(e->getQuantidadeDePeixe() - peixeEscunaFinal);
        e->setQuantidadeDePeixe(peixeEscunaFinal);
    }
}

void Veleiro::venderPeixeAoPorto(){
    
}

bool Veleiro::getAliancaDoNavio()const{
    return aliado;
}

//barco pertence ao jogador
void Veleiro::setAliancaDoNavio(bool a){
    aliado = a;
}

