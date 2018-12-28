/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Galeao.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 8:56 PM
 */

#ifndef GALEAO_H
#define GALEAO_H
#include "Navio.h"

class Galeao: public Navio{
public:
    Galeao();
    void navegar(int posx, int posy);
    Navio * duplica()const override;
    void recolhePeixeDeEscuna();
    virtual ~Galeao();
};

#endif /* GALEAO_H */

