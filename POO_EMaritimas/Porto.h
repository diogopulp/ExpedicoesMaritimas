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
public:
    Porto();
    Porto(const Porto& orig);
    virtual ~Porto();
    
    vector<Navio> navios;
private:

};

#endif /* PORTO_H */

