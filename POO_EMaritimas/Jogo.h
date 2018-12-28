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
#include "Navio.h"
#include "UI.h"

#include <math.h>
//#include <time.h>
#include <iostream>
#include <sstream>
#include <string>


//#include <ncurses.h>

using namespace std;

class Jogo {

private:
    
    static const int CUSTONAVIO = 100;
    
    vector<vector<Celula*> > mapa;
    
    UI textUI;
    
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
    vector<Navio *> navios;
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
    void setDimensoesMapa(int lin, int col);
    
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
    void lerFicheiro();
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
    void getOptions();
   
};

#endif /* JOGO_H */

