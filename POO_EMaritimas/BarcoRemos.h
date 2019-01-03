/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BarcoRemos.h
 * Author: danielmoita
 *
 * Created on 03 January 2019, 16:17
 */

#ifndef BARCOREMOS_H
#define BARCOREMOS_H
#include "Navio.h"

class BarcoRemos : public Navio{
public:
    BarcoRemos();
    BarcoRemos(Jogo *jogo, int posX, int posy):Navio(jogo, "RRRR", posX, posy, true, 1, 100, 0, 0, 0){}
    Navio * duplica()const override;
    int pescar(int peixe);
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
    int getVelocidade()override;
    void setAliancaDoNavio(bool alianca) override;
    bool getAliancaDoNavio() const override;
};


#endif /* BARCOREMOS_H */

