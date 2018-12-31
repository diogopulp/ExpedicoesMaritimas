/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escuna.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 8:56 PM
 */

#ifndef ESCUNA_H
#define ESCUNA_H

#include <stdio.h>

#include "Navio.h"

using namespace std;


class Escuna : public Navio{

public:
    Escuna();
    //so pode cargar ate 20 toneladas de carga - so pode carregar peixe
    Escuna(Jogo *jogo, int posX, int posy):Navio(jogo, 'E', posX, posy, true, 10, 100, 0, 0, 0){}
    Navio * duplica()const override;
    int pescar(int peixe);
    /*void abasteceNavioComAgua(int agua) override;
    void soldadosPerdidos(int soldados) override;
*/
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




    


    //void abastecerNavioComAgua();
    //int moverNavio(int direcao);
    //void navegar(int px, int py);
    //void alimentaSoldados();
   
};

#endif /* ESCUNA_H */

