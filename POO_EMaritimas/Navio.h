/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Navio.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 8:53 PM
 */

#ifndef NAVIO_H
#define NAVIO_H

#include <stdio.h>

using namespace std;

class Jogo;

class Navio {
    
private:
    char tipo;
    int posicaoAtualX, posicaoAtualY, idNavio;
    static int identificador;
    bool aliado = true;
    int numeroDeSoldados;
    int litosDeAgua;
    int toneladasDePeixe, toneladasDeMercadoria, cargaTotal;
    
public:
    
    Navio(char t, int posX, int posY, bool alianca, int numSoldados, int quantAgua, int quantPeixe, int quantMercadorias, int quantTotal);
    
    Navio(const Navio& orig);
     
    Navio();
    virtual ~Navio(){}
    
    void setPosicaoAtualX(int x);
    void setPosicaoAtualY(int y);
    void setTipoNavio(char tipo);
    void setBarcoAmigo(bool a);
    void setQuantidadeDePeixe(int quantPeixes);
    void setQuantidadeDeMercadorias(int quantMercadorias);
    void setQuantidadeTotalDeCarga(int quantCarga);
    void setAliancaDoNavio(bool alianca);
    
    int getPosicaoAtualX();
    int getPosicaoAtualY();
    int getIdNavio()const;
    int getNumeroDeSoldados();
    int getQuantidadeDeAgua();
    int getCargaTotal();
    int getQuantidadeDePeixe();
    int getQuantidadeDeMercadorias();
    char getTipoNavio();
    bool getAliancaDoNavio();
    //funcao que e chamada para criar os diferentes tipos de navios dentro do jogo
    static Navio * fabrica(char t);
    virtual Navio * duplica()const = 0;
    /*
    int moverNavio(int direcao);
    void navegar(int posx, int posy);
    void abastecerNavioComAgua();
    void alimentaSoldados();
    void venderMercadorias();
    void vendePeixe();
    */
};

#endif /* NAVIO_H */

