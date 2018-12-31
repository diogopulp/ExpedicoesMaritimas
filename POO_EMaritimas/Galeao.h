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
    //so pode carregar ate 70 toneladas de carga - peixe e mercadorias
    Galeao(Jogo *jogo, int posX, int posy):Navio(jogo, 'G', posX, posy, true, 40, 400, 0, 0, 0){}
    void navegar(int posx, int posy);
    Navio * duplica()const override;
    void transferePeixe();
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
    bool getAliancaDoNavio() const override;
    void setAliancaDoNavio(bool alianca) override;


};

#endif /* GALEAO_H */

