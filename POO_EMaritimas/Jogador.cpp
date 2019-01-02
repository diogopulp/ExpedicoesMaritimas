/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jogador.cpp
 * Author: danielmoita
 * 
 * Created on 25 December 2018, 17:07
 */

#include "Jogador.h"

Jogador::Jogador() {
    
    numeroTotalDeMoedas = 0;
}

Jogador::Jogador(const Jogador& orig) {
}

Jogador::~Jogador() {
}

void Jogador::setNumeroDeMoedas(int moedas){
    
    if (moedas > 0){
        numeroTotalDeMoedas = moedas;
    }
}

void Jogador::addMaisMoedas(int moedas){
    
    if(numeroTotalDeMoedas >= 0){
        numeroTotalDeMoedas += moedas;
    }
    
}

int Jogador::getNumeroDeMoedas(){
    return numeroTotalDeMoedas;
}

 void Jogador::dimNumMoedas(int custo){
     
     int diferenca = numeroTotalDeMoedas - custo;
     
     if(diferenca > 0){
         numeroTotalDeMoedas -=custo;
     }else{
         return;
     }
 }
 
 void Jogador::adicionaPorto(Porto* porto){   
     portos.push_back(porto);
 }
 
 void Jogador::adicionaNavio(Navio* navio){
     navios.push_back(navio);
 }
 
 vector<Porto*> Jogador::getPortos(){
     return this->portos;
 }
 
 vector<Navio*> Jogador::getNavios(){
     return this->navios;
 }
 
 