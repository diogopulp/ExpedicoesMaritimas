/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Porto.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 9:00 PM
 */

#ifndef PORTO_H
#define PORTO_H

#include <vector>
#include <iostream>
#include <string>

#include "Navio.h"

using namespace std;

class Porto {
    
private:
    string car;
    int numsoldados;
    int posXMar, posYMar;
    int posXTerra, posYTerra;

    // Amizade
    // 0 - Não conquistado;
    // 1 - Jogador;
    // 2 - Piratas;
    int amigo;
     
    void portoAmigoJogador();
    void portoAmigoPirata();
    
public:
      
    Porto();
    Porto(const Porto& orig);
    virtual ~Porto();
    
    void lutar();
    vector<Navio> navios;
    void conquistarPorto(Navio navio);
    void setNumSoldados(int num);
    int getNumSoldados();
    bool getRelacaoAmizade(Navio navio);
    string getCaracterePorto();
    void setPosXMar(int posX);
    void setPosYMar(int posY);
    void setPosXTerra(int posX);
    void setPosYTerra(int posY);


};

#endif /* PORTO_H */

