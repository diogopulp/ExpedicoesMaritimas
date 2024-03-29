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

#include "global_vars.cpp"

#include "Celula.h"
#include "Navio.h"

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
    
    string escutaComandos();
    int escutaMenu();
    
    int compraEscolherTipodeNavio(char tipo);
    char leCaraterInserido();
    int leInteiroInserido();
    void imprimeOpcoes();
    void mensagemErroFicheiro();
    void mensagemErroComando();
    void mensagemAvisoNavio();
    void novoNavioConstruido(int navioID, char tipo, int posX, int posY, int quantSoldados, int quantAgua, int quantPeixe, int quantMercadorias);
    void mensagemAvisoNavio(int id);
    void imprimeLinhasColunas(int lin, int col); 
    void mensagemSemMoedas();
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
    
    void mostraPontuacao(int pontuacao);
    void imprimeListaNavios(vector <Navio*> navios);
    void mostraNaviosPorto(int nNavios, int idPorto);
    void mostraNumSoldadosNavio(Navio* navio);
    void mensagemNavioNaoEstaNumPorto();
    void mensagemComamdoInexistente(string comando);
    void imprimeListaDePrecosNosPortos(vector <Porto*> portos);
    
   
};

#endif /* UI_H */

