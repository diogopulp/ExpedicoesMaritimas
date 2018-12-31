/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Navio.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 8:53 PM
 */
#include <sstream>
#include "Navio.h"
#include "Fragata.h"
#include "Galeao.h"
#include "Veleiro.h"
#include "Escuna.h"
#include <math.h>

using namespace std;
/*
Navio::Navio(char t, int posX, int posY, bool alianca, int numSoldados, int quantAgua, int quantPeixe, int quantMercadorias, int quantTotal):
tipo(t),posicaoAtualX(posX),posicaoAtualY(posY), idNavio(identificador++), aliado(alianca),
        numeroDeSoldados(numSoldados), litosDeAgua(quantAgua), toneladasDePeixe(quantPeixe), 
        toneladasDeMercadoria(quantMercadorias), cargaTotal(quantTotal)
{}
*/

Navio::Navio(Jogo *jogo, char t, int posX, int posY, bool alianca, int numSoldados, int quantAgua, int quantPeixe, int quantMercadorias, int quantTotal){
    this->jogo = jogo;
    this->tipo = t;
    this->posicaoAtualX = posX;
    this->posicaoAtualY = posY;
    this->aliado = alianca;
    this->numeroDeSoldados = numSoldados;
    this->litosDeAgua = quantAgua;
    this->toneladasDePeixe = quantPeixe;
    this->toneladasDeMercadoria = quantMercadorias;
    this->cargaTotal = quantTotal;
}
//construtor por copia

Navio::Navio(const Navio& orig):
    tipo(orig.tipo), numeroDeSoldados(orig.numeroDeSoldados),
            idNavio(identificador++), 
            posicaoAtualX(orig.posicaoAtualX), 
            posicaoAtualY(orig.posicaoAtualY){
}

int Navio::identificador = 0;

Navio::Navio(char t):tipo(t){
    
}



void Navio::setPosicaoAtualX(int x){
    posicaoAtualX = x;
}

void Navio::setPosicaoAtualY(int y){
    posicaoAtualY = y;
}

void Navio::setTipoNavio(char tipo) {
    this->tipo = tipo;
}

int Navio::getPosicaoAtualX(){
    return posicaoAtualX;
}

int Navio::getPosicaoAtualY(){
    return posicaoAtualY;
}

int Navio::getIdNavio()const{
    return idNavio;
}

char Navio::getTipoNavio(){
    return tipo;
}

//barco do jogador
/*
bool Navio::getAliancaDoNavio(){
    return aliado;
}

//barco pertence ao jogador
void Navio::setAliancaDoNavio(bool a){
    aliado = a;
}
*/
Navio * Navio::verificaNavioAdjacente(int x, int y){
    
    // verificar se existe navio adjacente a x e y, se houver retorna navio senão retorna null
    
    return nullptr;
}

bool Navio::getEstadoDeCalmaria(){
    return calmaria;
}

void Navio::setEstadoDeCalmaria(bool calmaria) {
    calmaria = true;
}

int Navio::combate(Navio* nav){
    int probNavioAliado = rand() % this->getNumeroDeSoldados();
    int probNavioPirata = rand() % this->getNumeroDeSoldados();
   
    if(probNavioAliado > probNavioPirata){
        this->setQuantidadeDeSoldados(this->getNumeroDeSoldados() * 0.8);
        nav->setQuantidadeDeSoldados(nav->getNumeroDeSoldados() * 0.6);
    }else{
         nav->setQuantidadeDeSoldados(nav->getNumeroDeSoldados() * 0.8);
         this->setQuantidadeDeSoldados(this->getNumeroDeSoldados() * 0.6);   
    }
    
    if(this->getNumeroDeSoldados() <= 0){
        return this->getIdNavio();
    }else if(nav->getNumeroDeSoldados() <= 0){
        return nav->getIdNavio();
    }
}

//fabrica de objectos
Navio * Navio::fabrica(char t){
    if(t == 'v'){
        return new Veleiro();
    }
    else if(t == 'g'){
        return new Galeao();
    }
    else if(t == 'f'){
        return new Fragata();
    }
    else if(t == 'e'){
        return new Escuna();
    }
    return nullptr;
}
