/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Galeao.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 8:56 PM
 */

#include "Galeao.h"

Galeao::Galeao(): Navio("GGGG",40, 400, 70) {
    
}

Navio * Galeao::duplica() const{
    return new Galeao(*this);
}
//cada turno que passa chamar esta funcao para todos os navios os navios no porto nao chamam a funcao porque os soldados no porto nao bebem agua
void Galeao::soldadosComsomemAgua(){
    if(this->getQuantidadeDeAgua()>= this->getNumeroDeSoldados()){
        this->setQuantidadeDeAgua(this->getQuantidadeDeAgua() - getNumeroDeSoldados());
    }
    else{
         int soldadosVivos = this->getNumeroDeSoldados() - this->getQuantidadeDeAgua();
        this->setQuantidadeDeSoldados(soldadosVivos);
        this->setQuantidadeDeAgua(0);
    }
}

//lembrar de fazer verificacao de adjacencia
void Galeao::transferePeixe(Escuna *e){
    
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

void Galeao::reabastecerAguaDoNavio(){
    this->litosDeAgua = 400;
}

void Galeao::setQuantidadeDeAgua(int agua){
    this->litosDeAgua = agua;
}

void Galeao::setQuantidadeDeSoldados(int soldados){
    this->numeroDeSoldados = soldados;
}

int Galeao::getQuantidadeDeAgua() const {
    return litosDeAgua;
}

int Galeao::getNumeroDeSoldados() const {
    return numeroDeSoldados;
}

int Galeao::getCargaTotal()const{
    return cargaTotal;
}

int Galeao::getQuantidadeDePeixe()const{
    return toneladasDePeixe;
}

int Galeao::getQuantidadeDeMercadorias()const{
    return toneladasDeMercadoria;
}

void Galeao::setQuantidadeDePeixe(int peixes){
    this->toneladasDePeixe = peixes;
}

void Galeao::setQuantidadeDeMercadorias(int mercadoria){
    this->toneladasDeMercadoria = mercadoria;
}

void Galeao::setQuantidadeTotalDeCarga(int total){
    this->cargaTotal = total;
}

int Galeao::getVelocidade(){
    return 1;
}

bool Galeao::getAliancaDoNavio()const{
    return aliado;
}

//barco pertence ao jogador
void Galeao::setAliancaDoNavio(bool a){
    aliado = a;
}