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
//#include "Navio.h"
#include <math.h>
//#include <time.h>
#include <iostream>
#include <sstream>
#include <string>


//#include <ncurses.h>

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
class Navio;
class Jogo {

private:
    vector<vector<Celula*> > mapa;
    vector<Navio *> navios;
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
    virtual ~Jogo();
    
    void constroiMapa(int lin, int col);
    vector<vector<Celula*> > getMapa();
    
    Jogo(const Jogo& orig);
    
    
    bool setLinhas(int linhas);
    bool setColunas(int colunas);
    bool setProbabilidadePirata(int prob);
    bool setProbabilidadeSereias(int prob);
    bool setProbabilidadeCalmaria(int prob);
    bool setProbabilidadeMotim(int prob);
    bool setProbabilidadeVento(int prob);
    bool setProbabilidadeTempestade(int prob);
    bool setPrecoNavio(int preco);
    bool setPrecoSoldado(int preco);
    bool setPrecoVendePeixe(int preco);
    bool setPrecoCompraMercadoria(int preco);
    bool setPrecoVendeMercadoria(int preco);
    bool setSoldadosPorto(int num);
    bool setNumMoedasIniciais(int nummoedas);
    bool setNumPortosIniciais(int numPortos);
    bool setPortoPrincipal();
    bool adicionaNavio(char tipo);
    bool destroiNavio(int id);
    int procuraNavio(int id)const;
    void imprimeMapa();
    void menuGame();
    void getOptions()const;
    void startNewGame();
    void startGameFromFile();
    void infoComandos();
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
    void colocarNavioEmPosicao(Navio *navio, char caraterNavio);
    void moverNavioAutomaticamente(int numeroNavio);
   



};

#endif /* JOGO_H */

