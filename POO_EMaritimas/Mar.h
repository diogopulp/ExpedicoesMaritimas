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
class Porto;

class Mar: public Celula {
    
private:
    int peixe;
    Navio *navio;
    Porto *porto;
    
public:
    Mar();
    Mar(Mar& orig);
    Mar(const Mar& orig);
    
    // Colocar objetos
    void colocarNavio(Navio* navio);
    void colocarPorto(Porto* porto);
    
    virtual ~Mar();
    int getQuantidadeDePeixeNaCelulaMar();
    void setQuantidadeDePeixeNaCelulaMar(int peixe);
};

#endif /* MAR_H */

