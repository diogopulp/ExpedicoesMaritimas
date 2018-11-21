/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Celula.h
 * Author: daniel
 *
 * Created on 20 de Novembro de 2018, 21:50
 */

#ifndef CELULA_H
#define CELULA_H

#include <string>

using namespace std;

class Celula {
    
    string car;
    
public:
    Celula();
    Celula(const Celula& orig);
    virtual ~Celula();
    string getCarater();
    friend ostream& operator<<(ostream& os, const Celula& cel);  
private:

};

#endif /* CELULA_H */

