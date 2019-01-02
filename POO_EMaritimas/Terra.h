/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Terra.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 8:59 PM
 */

#ifndef TERRA_H
#define TERRA_H

#include "Celula.h"

class Porto;

class Terra: public Celula {
    
private:
    Porto* porto;
 
    
public:
    Terra();
    Terra(const Terra& orig);
    virtual ~Terra();
    
    // Colocação dos objetos
    void colocarPorto(Porto* porto);

};

#endif /* TERRA_H */

