/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Porto.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 9:00 PM
 */

#include "Porto.h"

Porto::Porto() {
    car = "PPPP";
    numsoldados = 0;
}

Porto::Porto(const Porto& orig) {
}

Porto::~Porto() {
}

void Porto::lutar(){
    
    //Fim da Luta
    //SE o porto for inimigo do jogador e ganhar
    portoAmigoPirata();
    //SE o porto for inimigo do pirata e ganhar
    portoAmigoJogador();
    
}

void Porto::portoAmigoJogador(){
    amigo = 1;
    
}
void Porto::portoAmigoPirata(){
    amigo = 2;
}

void Porto::conquistarPorto(Navio navio){
    //SE navio jogador
    portoAmigoJogador();
    //SE navio pirata();
    portoAmigoPirata();
}

void Porto::setNumSoldados(int num){
    // O número de soldados pode ser maior ou igual que ZERO
    if(num >= 0){
        numsoldados = num;
    }
    
}

int Porto::getNumSoldados(){
    return numsoldados;
}

bool Porto::getRelacaoAmizade(Navio navio){
    
    //SE forem amigos
    return true;
    //SE não
    return false;
}


