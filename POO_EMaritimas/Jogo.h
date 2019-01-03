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
#include "UI.h"
#include "Jogador.h"
#include <math.h>
//#include <time.h>
#include <iostream>
#include <sstream>
#include <string>


//#include <ncurses.h>

using namespace std;
class Navio;
class Escuna;


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

enum cmdsEnum {
            info,  
            moedas = 1,  //<N>
            exec,        //<nomeFicheiro>
            prox,
            compranav,   //<T>
            vendenav,      //<N>
            lista,
            compra,      //<N><M>
            vende,       //<N>
            movenav,        //<idNavio> <direcao>
            automov,     //<N>
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
    
    static const int CUSTONAVIO = 100;
    
    vector<vector<Celula*> > mapa;
    vector<Navio *> navios;
    vector<Porto *> portos;
    int procuraNavio(int id)const;
    Jogador *jogador;
    
    UI textUI;
    
    DIRECAO moverN;
    int distancia;
    
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
    //Jogo()=default;
    virtual ~Jogo();
    
    void constroiMapa(int lin, int col);
    vector<vector<Celula*> > getMapa();
    
    Jogo(const Jogo& orig);
    
    Jogo();
   
    
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
    bool setNumPortosIniciais(int numPortos);
    bool setPortoPrincipal();

    bool adicionaNavio(char tipo);
    bool destroiNavio(int id);

    void setDimensoesMapa(int lin, int col);
    
    void colocarPortoEmPosicao(Porto *porto);
    void menuJogo();
    void getOptions()const;
    void startNewGame();
    void startGameFromFile();
    void infoComandos();
    int getLinhas();
    int getColunas();
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
    cmdsEnum convertCommandToEnum(string const &command);
    void apareceNavioPirata();
    void compraNavio(char tipoNavio);
    void ocorreTempestade();
    void ocorreSereias();
    void ocorreCalmaria();
    void ocorreMotim();
    void ocorreEvento();
    void sereiasMatamSoldados();
    int contaPontuacao();
    void verificaCombate();
    void danificaNavio(Navio *navio, int i);
    void listaInfo();
    void colocarNavioEmPosicao(Navio *navio);
    void moverNavioAutomaticamente(int id);
    void moveNavio(string id, string dir);
    void escunasPescam();
    Navio * verificaNavioAdjacente(int x, int y);
    Escuna * procuraEscuna(int x, int y);
    void verificaTransfernciaDePeixe();
    Celula * getCelula(int x, int y)const;
    Jogo & operator=(const Jogo& orig);
    void adicionaNavioAoPorto(Navio* navio);

    //void moverNavioAutomaticamente(int numeroNavio);
    void getOptions();
    void adicionaNavioAoPorto(Navio* navio,int idPorto);
    void vaiPara(string idNavio, string idPorto);
    void colocarNavioEmPosicaoAtualizada(Navio *navio);
    void desocuparMarDeNavio(int lin, int col);
    DIRECAO converteStringParaDirecao(string dir);
    void vendeNavio(string id);
    void acrescentaMoedas(string moedas);
    void criaNavioPirata(string x, string y, string tipo);
    void adicionaNovoPorto(Porto* porto);
    vector <Porto*> getPortos();
   
};

#endif /* JOGO_H */

