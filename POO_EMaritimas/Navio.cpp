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
int Navio::identificador = 0;

Navio::Navio(Jogo *jogo, string car, int posX, int posY, bool alianca, int numSoldados, int quantAgua, int quantPeixe, int quantMercadorias, int quantTotal){
    this->jogo = jogo;
    this->caractere = car;
    this->posicaoAtualX = posX;
    this->posicaoAtualY = posY;
    this->aliado = alianca;
    this->numeroDeSoldados = numSoldados;
    this->litosDeAgua = quantAgua;
    this->toneladasDePeixe = quantPeixe;
    this->toneladasDeMercadoria = quantMercadorias;
    this->cargaTotal = quantTotal;
    identificador++;
}
//construtor por copia

Navio::Navio(const Navio& orig):
    caractere(orig.caractere), numeroDeSoldados(orig.numeroDeSoldados), 
            posicaoAtualX(orig.posicaoAtualX), 
            posicaoAtualY(orig.posicaoAtualY){
    identificador++;
}

Navio::Navio(string car, int numSoldados, int quantAgua, int cargaMax):caractere(car),numeroDeSoldados(numSoldados),litosDeAgua(quantAgua){
    this->aliado = true;
    this->toneladasDePeixe = 0;
    this->toneladasDeMercadoria=0;
    this->cargaTotal = cargaMax;
    identificador++;
}

int Navio::getIdentificador(){
    return identificador;
}
void Navio::setPosicaoAtualX(int x){
    posicaoAtualX = x;
}

void Navio::setPosicaoAtualY(int y){
    posicaoAtualY = y;
}

void Navio::setTipoNavio(string caractere) {
    this->caractere = caractere;
}

int Navio::getPosicaoAtualX(){
    return posicaoAtualX;
}

int Navio::getPosicaoAtualY(){
    return posicaoAtualY;
}

string Navio::getCaractereNavio(){
    return caractere;
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
        return this->getIdentificador();
    }else if(nav->getNumeroDeSoldados() <= 0){
        return nav->getIdentificador();
    }
    return 0;
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
