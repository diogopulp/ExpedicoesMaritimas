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
    //void navegar(int posx, int posy);
    Navio * duplica()const override;
    void protegeGaleao();
    void soldadosComsomemAgua()override;
    void setQuantidadeDeAgua(int agua)override;
    void setQuantidadeDeSoldados(int soldados)override;
    int getQuantidadeDeAgua() const override;
    int getNumeroDeSoldados() const override;
    int getCargaTotal()const override;
    int getQuantidadeDePeixe()const override;
    int getQuantidadeDeMercadorias()const override;
    void setQuantidadeDePeixe(int quantPeixes)override;
    void setQuantidadeDeMercadorias(int quantMercadorias)override;
    void setQuantidadeTotalDeCarga(int quantCarga)override;
    void reabastecerAguaDoNavio()override;

};

#endif /* FRAGATA_H */

