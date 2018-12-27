/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fragata.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 8:56 PM
 */

#include "Fragata.h"

Fragata::Fragata() : Navio('f') {
}
/*
Fragata::Fragata(const Fragata& orig) {
}
*/

Navio * Fragata::duplica()const{
    return new Fragata(*this);
}
