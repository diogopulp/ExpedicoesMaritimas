/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jogo.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 7:19 PM
 */

#ifndef JOGO_H
#define JOGO_H

#include <vector>
#include "Celula.h"
#include "Mar.h"
#include "Terra.h"
#include <math.h>
//#include <time.h>
#include <iostream>
#include <sstream>
#include <string>

class Navio;

using namespace std;


enum valoresFicheiro {
    LINHAS = 1,
    COLUNAS,
    MOEDAS,
    PROB_PIRATA,
    PRECO_NAVIO,
    PRECO_SOLDADO,
    PRECO_VENDA_PEIXE,
    PRECO_COMPRA_MERCADO,
    PRECO_VENDA_MERCADO,
    SOLDADOS_PORTO,
    PROB_VENTO,
    PROB_TEMPESTADE,
    PROB_SEREIAS,
    PROB_CALMARIA,
    PROB_MOTIM
};

enum cmdsEnum {
            moedas = 1,       //<N>
            exec,         //<nomeFicheiro>
            prox,
            compranav,    //<T>
            vendeN,       //<N>
            lista,
            compra,       //<N><M>
            vende,        //<N>
            move,         //<N><X>
            autoMov,     //<N>
            stop,        //<N>
            pirata,      //<x><y><t>
            evpos,       //<E> <x><y>
            evnav,       //<E><N>
            vaipara,     //<N> <x><y>
            comprasold,  //<N><S>
            saveg,       //<nome>
            loadg,       //<nome>
            delg,        //<nome>
            sair
};

class Jogo {

private:
    vector<vector<Celula*> > mapa;
    int numeroMoedas;
    int numeroPortos;
    
    int linhas;
    int colunas;
    
    int probabilidadePirata;
    int probabilidadeSereias;
    int probabilidadeCalmaria;
    int probabilidadeMotim;
    int probabilidadeVento;
    int probabilidadeTempestade;
    int precoNavio;
    int precoSoldado;
    int precoVendePeixe;
    int precoCompraMercadoria;
    int precoVendeMercadoria;
    int soldadosPorto;
    
public:
    Jogo();
    void constroiMapa(int lin, int col);
    vector<vector<Celula*> > getMapa();
    vector<Navio *> navios;
    Jogo(const Jogo& orig);
    virtual ~Jogo();
    void setLinhas(int linhas);
    void setColunas(int colunas);
    void setProbabilidadePirata(int prob);
    void setProbabilidadeSereias(int prob);
    void setProbabilidadeCalmaria(int prob);
    void setProbabilidadeMotim(int prob);
    void setProbabilidadeVento(int prob);
    void setProbabilidadeTempestade(int prob);
    void setPrecoNavio(int preco);
    void setPrecoSoldado(int preco);
    void setPrecoVendePeixe(int preco);
    void setPrecoCompraMercadoria(int preco);
    void setPrecoVendeMercadoria(int preco);
    void setSoldadosPorto(int num);
    void imprimeMapa();
    void menuGame();
    void getOptions()const;
    void startNewGame();
    void startGameFromFile();
    void infoComandos();
    void setNumMoedasIniciais(int nummoedas);
    void setNumPortosIniciais(int numPortos);
    void setPortoPrincipal();
    int getLinhas();
    int getColunas();
    int getNumMoedas();
    int getNumNavios();
    int getNumPortos();
    void readFile();
    int valorNaLinhaDoFicheiro(string linha);
    int converteValoresFicheiro(string chave);
    int getProbabilidadePirata();
    int getProbabilidadeSereias();
    int getProbabilidadeCalmaria();
    int getProbabilidadeMotim();
    int getProbabilidadeVento();
    int getProbabilidadeTempestade();
    int getPrecoSoldado();
    int getPrecoVendePeixe();
    int getPrecoCompraMercadoria();
    int getPrecoVendeMercadoria();
    int getSoldadosPorto();
    int getPrecoNavio();
    
    void compraNavio(char tipoNavio);
    void listaInfo();
    void colocarNavioEmPosicao(Navio *navio, char caractereNavio);
    void moverNavioAutomaticamente(int numeroNavio);
};

#endif /* JOGO_H */

