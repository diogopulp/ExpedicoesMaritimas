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
        //so pode carregar ate 40 toneladas de carga-peixe e mercadorias
        Veleiro(Jogo *jogo, int posX, int posy):Navio(jogo, 'V', posX, posy, true, 20, 200, 0, 0, 0){}
        void navegar(int posx, int posy);
        Navio * duplica()const override;
        void transferePeixe();
        void venderPeixeAoPorto();
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

#endif /* VELEIRO_H */

