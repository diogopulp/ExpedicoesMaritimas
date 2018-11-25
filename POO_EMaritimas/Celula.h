/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Celula.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 7:18 PM
 */

#ifndef CELULA_H
#define CELULA_H

#include <string>

using namespace std;

class Celula {
protected:
    char car;
    
public:
    explicit Celula();
    explicit Celula(const Celula& orig);
    virtual ~Celula();
    void setCaractere(char caractere);
    virtual char getCarater() const;
    //friend 
private:

};

#endif /* CELULA_H */

