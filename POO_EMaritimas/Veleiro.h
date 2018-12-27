/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Veleiro.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 8:56 PM
 */

#ifndef VELEIRO_H
#define VELEIRO_H
#include "Navio.h"

class Veleiro : public Navio {
        
    public:
        Veleiro();
        void navegar(int posx, int posy);
        //Navio * duplica()const override;
        void transferePeixe();
        Veleiro(const Veleiro& orig);
        virtual ~Veleiro();
        

};

#endif /* VELEIRO_H */

