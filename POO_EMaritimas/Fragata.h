/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fragata.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 8:56 PM
 */

#ifndef FRAGATA_H
#define FRAGATA_H
#include "Navio.h"

class Fragata : public Navio {
public:
    Fragata();
    Fragata(const Fragata& orig);
    virtual ~Fragata();
    //void navegar(int posx, int posy);
    //Navio * duplica()const override;
    void protegeGaleao();

};

#endif /* FRAGATA_H */

