/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mar.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 9:00 PM
 */

#ifndef MAR_H
#define MAR_H

#include "Celula.h"
class Navio;

class Mar: public Celula {
    
private:
    int peixe;
    Navio *navio;
    
public:
    Mar();
    Mar(Mar& orig);
    Mar(const Mar& orig);
    void colocarNavio(Navio* navio);
    virtual ~Mar();
    int getQuantidadeDePeixeNaCelulaMar();
    void setQuantidadeDePeixeNaCelulaMar(int peixe);
};

#endif /* MAR_H */

