/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Navio.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 8:53 PM
 */

#ifndef NAVIO_H
#define NAVIO_H

class Navio {
public:
    Navio();
    Navio(const Navio& orig);
    virtual ~Navio();
    void setPosicaoAtualX(int x);
    void setPosicaoAtualY(int y);
    void setTipoNavio(char tipo);
    int getPosicaoAtualX();
    int getPosicaoAtualY();
    int getIdentificadorNavio();
    char getTipoNavio();
private:
    char tipo;
    int posicaoAtualX, posicaoAtualY, idNavio;
    static int identificador;

};

#endif /* NAVIO_H */

