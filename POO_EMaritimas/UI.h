/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UI.h
 * Author: diogosantos
 *
 * Created on December 28, 2018, 11:54 AM
 */

#ifndef UI_H
#define UI_H

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include "Celula.h"

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
            moedas = 1,  //<N>
            exec,        //<nomeFicheiro>
            prox,
            compranav,   //<T>
            vendeN,      //<N>
            lista,
            compra,      //<N><M>
            vende,       //<N>
            move,        //<N><X>
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

using namespace std;

class UI {
private:
    
public:
    UI();
    UI(const UI& orig);
    virtual ~UI();
    
    // Método responsável por imprimir o mapa
    // Recebe um vetor de "Celula*"
    void imprimeMapa(vector<vector<Celula*> > mapa);
    void infoComandos();
    void listaInfo(int nMoedas, int nNavios);
    int moedasIniciais();
    void imprimeNumMoedasJogador(int nMoedas);
    void imprimeNumNaviosJogador(int nNavios);
    void imprimeSegundaFase();
    void imprimirMenu();
    
    int escutaComandos();
    int escutaMenu();
    
    int compraEscolherTipodeNavio(char tipo);
    char leCaraterInserido();
    int leInteiroInserido();
    cmdsEnum convertCommandToEnum(string const &command);
    void imprimeOpcoes();
    void mensagemErroFicheiro();
    void mensagemAvisoNavio();
    void novoNavioConstruido(int navioID, int tipo, int posX, int posY);
    void mensagemAvisoNavio(int id);
    void imprimeLinhasColunas(int lin, int col);  
    void resumoFicheiroCarregado(
        int nMoedas,
        int nNavios,
        int probPirata,
        int precoNavio,
        int precoSoldado,
        int precoVPeixe,
        int precoVMercadoria,
        int precoCMercadoria,
        int probVento,
        int probTempestade,
        int probSereias,
        int probCalmaria,
        int probMotim
    );
    
   
};

#endif /* UI_H */

