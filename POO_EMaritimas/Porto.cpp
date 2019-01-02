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

int Porto::identificador = 0;

Porto::Porto() {
    car = "PPPP";
    numsoldados = 0;
    identificador++;
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

string Porto::getCaracterePorto(){
    return car;
}

void Porto::setPosXMar(int posX){
    posXMar = posX;
}
void Porto::setPosYMar(int posY){
    posYMar = posY;
}
void Porto::setPosXTerra(int posX){
    posXTerra = posX;
}
void Porto::setPosYTerra(int posY){
    posYTerra = posY;
}

void Porto::adicionarNavio(Navio* navio){
    
    navios.push_back(navio);
    
}


int Porto::getPortoID(){
    return identificador;
}

int Porto::getPosXMar(){
    return posXMar;
}
int Porto::getPosYMar(){
    return posYMar;
}
int Porto::getPosXTerra(){
    return posXTerra;
}
int Porto::getPosYTerra(){
    return posYTerra;
}