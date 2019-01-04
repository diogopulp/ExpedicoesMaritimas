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


#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

// Em Navio.h apenas está declarado um ponteiro para Porto, 
// não sendo preciso conhecer a estrutura de Porto, apenas o seu nome. Em Navio.h, 
// em vez de se incluir toda a declaração de Porto, declara-se o seu nome:

class Porto;
class Jogo;

enum DIRECAO {
    C = 1,
    B,
    D,
    E,
    CD,
    CE,
    BD,
    BE
};

class Navio{
    
private:
    string caractere;
    int posicaoAtualX, posicaoAtualY;
    static int identificador;
    bool autoGestao;
    
protected:
    Jogo* jogo;
    Porto* porto;
    int numMaxSoldados;
    int numeroDeSoldados;
    int litosDeAgua;
    int toneladasDePeixe, toneladasDeMercadoria, cargaTotal;
    bool calmaria = false;
    bool aliado = true;
public:
    Navio(string car);
    Navio(Jogo *jogo, string car, int posX, int posY, bool alianca, int numSoldados, int quantAgua, int quantPeixe, int quantMercadorias, int quantTotal);
    Navio(string car, int numSoldados, int quantAgua, int cargaMax);
    Navio(const Navio & orig);

    virtual ~Navio(){}
    
    void setPosicaoAtualX(int x);
    void setPosicaoAtualY(int y);
 
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
    int getPosicaoAtualX();
    int getPosicaoAtualY();
    int getIdentificador();
    virtual int getNumeroDeSoldados()const = 0;
    virtual int getQuantidadeDeAgua()const  = 0;
    virtual int getCargaTotal()const = 0;
    virtual int getQuantidadeDePeixe()const = 0;
    virtual int getQuantidadeDeMercadorias()const = 0;
    string getCaractereNavio();
    void setTipoNavio(string caractere);
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
    void setJogo(Jogo* jogo);
    
    void navega(Porto* porto);
    void moveNavio(string dir);
    void moveNavioAutoGestao();
    
    void vaiPara(int x, int y);
    
    void setPorto(Porto* porto);
    Porto* getPorto();
    
    void setNumMaxSoldados(int soldados);
    int getNumMaxSoldados();
    void adicionaSoldados(int soldados);
    
    void compraSoldados(int nSoldados);
    
    void compraMercadorias(int toneladas);
    
    DIRECAO converteStringParaDirecao(string dir);
    
    void vendeCargaEMercadoria();
    
    void switchAutoGestao();
    bool getAutoGestao();
    
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

