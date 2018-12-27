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
#include "Navio.h"
#include "Fragata.h"
#include "Galeao.h"
#include "Veleiro.h"
#include "Escuna.h"

using namespace std;
/*
Navio::Navio(char t, int posX, int posY, int id, bool alianca,
        int numSoldados, int quantAgua, int quantPeixe, int quantMercadorias,
        int quantTotal):tipo(t), posicaoAtualX(posX), posicaoAtualY(posY),
        idNavio(id = identificador++), aliado(alianca), 
        numeroDeSoldados(numSoldados), litosDeAgua(quantAgua),
        toneladasDePeixe(quantPeixe), toneladasDeMercadoria(quantMercadorias),
        cargaTotal(quantTotal){
}
*/
//construtor por copia
/*
Navio::Navio(const Navio& orig):
    tipo(orig.tipo), numeroDeSoldados(orig.numeroDeSoldados),
            idNavio(identificador++), 
            posicaoAtualX(orig.posicaoAtualX), 
            posicaoAtualY(orig.posicaoAtualY){
}
*/

Navio::Navio() {
    this->idNavio = this->identificador++;
}
Navio::~Navio() {
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

int Navio::getIdentificadorNavio(){
    return idNavio;
}

char Navio::getTipoNavio(){
    return tipo;
}

//barco do jogador
bool Navio::getAliancaDoNavio(){
    return aliado;
}

//barco pertence ao jogador
void Navio::setBarcoAmigo(bool a){
    aliado = a;
}


//fabrica de objectos
Navio * Navio::fabrica(char tipo){
    if(tipo == 'v'){
        return new Veleiro();
    }
    else if(tipo == 'g'){
        return new Galeao();
    }
    else if(tipo == 'f'){
        return new Fragata();
    }
    else if(tipo == 'e'){
        return new Escuna();
    }
    return nullptr;
}
