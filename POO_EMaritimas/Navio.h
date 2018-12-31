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
    //Jogo *jogo;
    char tipo;
    int posicaoAtualX, posicaoAtualY, idNavio;
    static int identificador;
    
protected:
    Jogo *jogo;
    int numeroDeSoldados;
    int litosDeAgua;
    int toneladasDePeixe, toneladasDeMercadoria, cargaTotal;
    bool calmaria = false;
    bool aliado = true;
public:
    Navio(char t);
    Navio(Jogo *jogo, char t, int posX, int posY, bool alianca, int numSoldados, int quantAgua, int quantPeixe, int quantMercadorias, int quantTotal);
    
    Navio(const Navio & orig);

    virtual ~Navio(){}
    
    void setPosicaoAtualX(int x);
    void setPosicaoAtualY(int y);
    void setTipoNavio(char tipo);
    virtual int getVelocidade() = 0;
    virtual void setQuantidadeDePeixe(int quantPeixes) = 0;
    virtual void setQuantidadeDeMercadorias(int quantMercadorias) = 0;
    virtual void setQuantidadeTotalDeCarga(int quantCarga) = 0;
    virtual void reabastecerAguaDoNavio() = 0;
    int combate(Navio *nav);
    //void setAliancaDoNavio(bool alianca);
    virtual void setAliancaDoNavio(bool alianca) = 0;
    virtual void setQuantidadeDeAgua(int agua) = 0;
    virtual void setQuantidadeDeSoldados(int soldados) = 0;
    Navio * verificaNavioAdjacente(int x, int y);
    int getPosicaoAtualX();
    int getPosicaoAtualY();
    int getIdNavio()const;
    virtual int getNumeroDeSoldados()const = 0;
    virtual int getQuantidadeDeAgua()const  = 0;
    virtual int getCargaTotal()const = 0;
    virtual int getQuantidadeDePeixe()const = 0;
    virtual int getQuantidadeDeMercadorias()const = 0;
    char getTipoNavio();
    virtual bool getAliancaDoNavio()const = 0;
    //bool getAliancaDoNavio();
    bool getEstadoDeCalmaria();
    void setEstadoDeCalmaria(bool calmaria);
    //funcao que e chamada para criar os diferentes tipos de navios dentro do jogo
    static Navio * fabrica(char t);
    virtual Navio * duplica()const = 0;
    //virtual void abasteceNavioComAgua(int agua) = 0;
    //virtual void soldadosPerdidos(int soldados) = 0;
    virtual void soldadosComsomemAgua() = 0;
    
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

