/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jogo.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 7:19 PM
 */

#include <fstream>
#include "Jogo.h"
#include "Terra.h"
#include "Navio.h"
#include "Galeao.h"
#include "Veleiro.h"
#include "Fragata.h"
#include "Escuna.h"


int Navio::identificador = 1;

Jogo::Jogo() {
   
}

bool Jogo::setLinhas(int linhas) {
    
    // O número de linhas deve ser superior a 10
    if(linhas > 10){
        this->linhas = linhas;
        return true;
    }
    return false;
}

bool Jogo::setColunas(int colunas) {
    
    // O número de colunas deve ser superior a 10
    if(colunas > 10){
        this->colunas = colunas;
        return true;
    }
    return false;
}

int Jogo::getLinhas() {
    return linhas;
}

int Jogo::getColunas() {
    return colunas;
}

void Jogo::constroiMapa(int lin, int col){
    
    if(lin > 0 && col > 0){
        for(int i = 0; i <lin ; i++){

            vector<Celula*> temp;

                for( int j = 0; j<col; j++){

                    int num = rand() % 101;

                    if(num<90){
                        temp.push_back(new Mar());
                    }
                    else{
                        temp.push_back(new Terra());
                    }
                }

            mapa.push_back(temp);
        } 
    }           
}

void Jogo::imprimeMapa(){
    
    for(int i =0; i<mapa.size(); i++){
        cout << endl;
        for(int j=0; j<mapa[i].size(); j++){

            cout << mapa[i][j]->getCarater()[0];
            cout << mapa[i][j]->getCarater()[1] << " ";
           
            
        }
        cout << endl;
        for(int j=0; j<mapa[i].size(); j++){
            cout << mapa[i][j]->getCarater()[2];
            cout << mapa[i][j]->getCarater()[3] << " ";

        }
    }   
}

Jogo::Jogo(const Jogo& orig) {
    
}

vector<vector<Celula*> > Jogo::getMapa(){
    return mapa;
}

Jogo::~Jogo() {
}


void Jogo::getOptions()const{
   
    cout << "Opcoes do jogo:\n"
            "O jogo tem duas fases. Na primeira fase precisa de inicializar o jogo e defenir os elementos iniciais do jogo abrindo "
            "o ficheiro.\nPara esta funcionalidade tem que usar o comando config <nomeFicheiro>\n"
            "Na segunda fase vai ser o desenrolar do jogo e vai ter que escolher os seus commandos para interagir com o jogo";
}



void Jogo::infoComandos(){
    cout << "Inicio de Jogo!\n\n"
            "Primeira fase do jogo\n"
            "Comandos possiveis:\n"
            "config <nomeFicheiro>\n\n"
            "Segunda fase do jogo\n"
            "Comandos possiveis:\n"
            "moedas <N>\n"
            "exec <nomeFicheiro>\n"
            "prox\n"
            "compranav <T>\n"
            "vendeN <N>"
            "lista\n"
            "compra <N><M>\n"
            "vende <N>\n"
            "move <N><X>\n"
            "auto <N>\n"
            "stop <N>\n"
            "pirata <x><y><t>\n"
            "evpos <E> <x><y>\n"
            "evnav <E><N>\n"
            "vaipara <N> <x><y>\n"
            "vaipara <N><P>\n"
            "comprasold <N><S>\n"
            "saveg <nome>\n"
            "loadg <nome>\n"
            "delg <nome>\n"
            "sair \n";
}

bool Jogo::setNumMoedasIniciais(int numMoedas){
    
    // O número de moedas inserido deve ser positivo
    if(numMoedas > 0){
        numeroMoedas = numMoedas;
        return true;
    }
    return false;
}

int Jogo::getNumMoedas() { 
    return  numeroMoedas; 
}

int Jogo::getNumNavios() {
    return navios.size();
}

bool Jogo::setProbabilidadePirata(int prob) {
    
    // A probabilidade deve ser um número positivo
    if(prob > 0){
        probabilidadePirata = prob;
        return true;
    }
    return false;
}

int Jogo::getProbabilidadePirata() {
    return probabilidadePirata;
}

bool Jogo::setProbabilidadeCalmaria(int prob){
    
     // A probabilidade deve ser um número positivo
    if(prob > 0){
        probabilidadeCalmaria = prob;
        return true;
    }
    return false;
}

int Jogo::getProbabilidadeCalmaria() {
    return probabilidadeCalmaria;
}

bool Jogo::setProbabilidadeSereias(int prob){
    
     // A probabilidade deve ser um número positivo
    if(prob > 0){
        probabilidadeSereias = prob;
        return true;
    }
    return false;
          
}

int Jogo::getProbabilidadeSereias(){
    return probabilidadeSereias;
}

bool Jogo::setProbabilidadeMotim(int prob){
    
     // A probabilidade deve ser um número positivo
    if(prob > 0){
        probabilidadeMotim = prob;
        return true;
    }
    return false;
}

int Jogo::getProbabilidadeMotim(){
    return probabilidadeMotim;
}

bool Jogo::setProbabilidadeVento(int prob){
    
     // A probabilidade deve ser um número positivo
    if(prob > 0){
        probabilidadeVento = prob;
        return true;
    }
    return false;
}

int Jogo::getProbabilidadeVento(){
    return probabilidadeVento;
}

bool Jogo::setProbabilidadeTempestade(int prob){
    
     // A probabilidade deve ser um número positivo
    if(prob > 0){
        probabilidadeTempestade = prob;
        return true;
    }
    return false;
}

int Jogo::getProbabilidadeTempestade(){
    return probabilidadeTempestade;
}

bool Jogo::setPrecoSoldado(int preco) {
    
    // O preco deve ser um número positivo
    if(preco > 0){
        precoSoldado = preco;
        return true;
    }
    return false;
}

int Jogo::getPrecoSoldado(){
    return precoSoldado;
}

bool Jogo::setPrecoVendePeixe(int preco){
    
    // O preco deve ser um número positivo
    if(preco > 0){
        precoVendePeixe = preco;
        return true;
    }
    return false;
}

int Jogo::getPrecoVendePeixe(){
    return precoVendePeixe;
}

bool Jogo::setPrecoCompraMercadoria(int preco){
    
    // O preco deve ser um número positivo
    if(preco > 0){
        precoCompraMercadoria = preco;
        return true;
    }
    return false;
}

int Jogo::getPrecoCompraMercadoria(){
    return precoCompraMercadoria;
}

bool Jogo::setPrecoVendeMercadoria(int preco){
    
    // O preco deve ser um número positivo
    if(preco > 0){
        precoVendeMercadoria = preco;
        return true;
    }
    return false;
}

int Jogo::getPrecoVendeMercadoria(){
    return precoVendeMercadoria;
}

bool Jogo::setSoldadosPorto(int num){
    
    // O número de soldados deve ser positivo
    if(num > 0){
        soldadosPorto = num;
        return true;
    }
    return false;
}

int Jogo::getSoldadosPorto(){
    return soldadosPorto;
}

bool Jogo::setPrecoNavio(int preco){
    
    // O preco deve ser um número positivo
    if(preco > 0){
        precoNavio = preco;
        return true;
    }
    return false;
}

int Jogo::getPrecoNavio(){
    return precoNavio;
}





void Jogo::listaInfo() {
    cout << "Num moedas: "<< getNumMoedas() << endl;
    cout << "Num navios: "<< getNumNavios() << endl;
}


void Jogo::compraNavio(char tipoNavio) {

    if(numeroMoedas<100){ 
        return;
    }
    
    Navio *novoNavio;
    
    if(tipoNavio == 'G' || tipoNavio == 'g'){
        novoNavio = new Galeao();
    }
    else if(tipoNavio == 'V' || tipoNavio == 'v'){
        novoNavio = new Veleiro();
    }
    else if(tipoNavio == 'E' || tipoNavio == 'e'){
        novoNavio = new Escuna();
    }
    else if(tipoNavio == 'F' || tipoNavio == 'f'){
        novoNavio = new Fragata();
    }
    
    novoNavio->setTipoNavio(tipoNavio);
    
    // 1ª fase (apagar depois) -> colocar navio numa posição no mar
    colocarNavioEmPosicao(novoNavio, tipoNavio);
    navios.push_back(novoNavio);
    
    numeroMoedas-=100;
    
    cout << "Novo navio construido com ID:" << novoNavio->getIdentificadorNavio() << ", Tipo:" << novoNavio->getTipoNavio() << ", Posicao: (" << novoNavio->getPosicaoAtualX() << "," << novoNavio->getPosicaoAtualY() << ")" << endl;
    
    imprimeMapa();
}

void Jogo::moverNavioAutomaticamente(int identificador){
    
    if (getNumNavios() <= 0) {
        cout << "Não tem nenhum navio" << endl;
        return;
    }
    
    bool navioEncontrado = false;
    Navio *navio;
    
    for (int i = 0; i < getNumNavios(); i++) {
        
        if (navios[i]->getIdentificadorNavio() == identificador) {
            navio = navios[i];
            navioEncontrado = true;
            break;
        }
    }
    
    if (!navioEncontrado) {
        cout << "Não foi encontrado um navio com o identificador: " << identificador << endl;
        return;
    }
    
    int novaLinha = 0, novaColuna = 0;
    
    do{
        
        int posicao = rand() % 8;
        
        switch (posicao) {
            case 1:
            {
                novaLinha = navio->getPosicaoAtualX() - 1;
                novaColuna = navio->getPosicaoAtualY() - 1;;
            }
            break;
            case 2:
            {
                novaLinha = navio->getPosicaoAtualX() - 1;
                novaColuna = navio->getPosicaoAtualY();
            }
            break;
            case 3:
            {
                novaLinha = navio->getPosicaoAtualX() - 1;
                novaColuna = navio->getPosicaoAtualY() + 1;
            }
            break;
            case 4:
            {
                novaLinha = navio->getPosicaoAtualX();
                novaColuna = navio->getPosicaoAtualY() - 1;
            }
            break;
            case 5:
            {
                novaLinha = navio->getPosicaoAtualX();
                novaColuna = navio->getPosicaoAtualY() + 1;
            }
            break;
            case 6:
            {
                novaLinha = navio->getPosicaoAtualX() + 1;
                novaColuna = navio->getPosicaoAtualY() - 1;
            }
            break;
            case 7:
            {
                novaLinha = navio->getPosicaoAtualX() + 1;
                novaColuna = navio->getPosicaoAtualY();
            }
            break;
            case 8:
            {
                novaLinha = navio->getPosicaoAtualX() + 1;
                novaColuna = navio->getPosicaoAtualY() + 1;
            }
            break;
            default:
                break;
        }
        
    }while((novaLinha > getLinhas() || novaColuna > getColunas()) && mapa[novaLinha][novaColuna]->getCarater()[0] != '~');
    
    mapa[navio->getPosicaoAtualX()][navio->getPosicaoAtualY()]->setCarater('~');
    mapa[novaLinha][novaColuna]->setCarater(navio->getTipoNavio());
    navio->setPosicaoAtualX(novaLinha);
    navio->setPosicaoAtualY(novaColuna);
    
    imprimeMapa();
}

void Jogo::colocarNavioEmPosicao(Navio *navio, char caraterNavio) {
    int novaLinha = 0, novaColuna = 0;
    
    do{
        
        novaLinha = rand() % getLinhas();
        novaColuna = rand() % getColunas();

    }while((novaLinha > getLinhas() || novaColuna > getColunas()) && mapa[novaLinha][novaColuna]->getCarater()[0] != '~');
    
    mapa[novaLinha][novaColuna]->setCarater(caraterNavio);
    navio->setPosicaoAtualX(novaLinha);
    navio->setPosicaoAtualY(novaColuna);
}

int Jogo::converteValoresFicheiro(string chave) {
    
    if (chave == "linhas") {
        return LINHAS;
    }
    else if (chave == "colunas") {
        return COLUNAS;
    }
    else if (chave == "moedas") {
        return MOEDAS;
    }
    else if(chave == "probpirata"){
        return PROB_PIRATA;
    }
    else if(chave == "preconavio"){
        return PRECO_NAVIO;
    }
    else if(chave == "precosoldado"){
        return PRECO_SOLDADO;
    }
    else if(chave == "precovendapeixe"){
        return PRECO_VENDA_PEIXE;
    }
    else if(chave == "precocompramercado"){
        return PRECO_COMPRA_MERCADO;
    }
    else if(chave == "precovendamercado"){
        return PRECO_VENDA_MERCADO;
    }
    else if(chave == "soldadosporto"){
        return SOLDADOS_PORTO;
    }
    else if(chave == "probvento"){
        return PROB_VENTO;
    }
    else if(chave == "probtempestade"){
        return PROB_TEMPESTADE;
    }
    else if(chave == "probsereias"){
        return PROB_SEREIAS;
    }
    else if(chave == "probcalmaria"){
        return PROB_CALMARIA;
    }
    else if(chave == "probmotim"){
        return PROB_MOTIM;
    }
    
    return 0;
}

int Jogo::valorNaLinhaDoFicheiro(string linha) {
    
    vector<string> dadosDoFicheiro;
    
    dadosDoFicheiro.push_back("linhas");
    dadosDoFicheiro.push_back("colunas");
    dadosDoFicheiro.push_back("moedas");
    dadosDoFicheiro.push_back("probpirata");
    dadosDoFicheiro.push_back("preconavio");
    dadosDoFicheiro.push_back("precosoldado");
    dadosDoFicheiro.push_back("precovendapeixe");
    dadosDoFicheiro.push_back("precocompramercado");
    dadosDoFicheiro.push_back("precovendamercado");
    dadosDoFicheiro.push_back("soldadosporto");
    dadosDoFicheiro.push_back("probvento");
    dadosDoFicheiro.push_back("probtempestade");
    dadosDoFicheiro.push_back("probsereias");
    dadosDoFicheiro.push_back("probcalmaria");
    dadosDoFicheiro.push_back("probmotim");
    
    for (int i = 0; i < dadosDoFicheiro.size(); i++) {
        if (linha.compare(dadosDoFicheiro[i]) == 0) {
            return converteValoresFicheiro(dadosDoFicheiro[i]);
        }
    }
    
    return 0;
}

void Jogo::readFile(){

    fstream ficheiro("startGame.txt");
    string linha;
    int valor;
    
    if (!ficheiro.is_open()) {
        cout << "Erro ao carregar ficheiro. Fechar programa.";
    }
    else {
        
        while (getline(ficheiro, linha)) {
            
            istringstream buffer(linha);
            
            if (buffer >> linha && buffer >> valor) {
                
                switch(valorNaLinhaDoFicheiro(linha)) {
                    case LINHAS:
                        setLinhas(valor);
                        break;
                    case COLUNAS:
                        setColunas(valor);
                        break;
                    case PROB_PIRATA:
                        setProbabilidadePirata(valor);
                        break;
                    case MOEDAS:
                        setNumMoedasIniciais(valor);
                        break;
                    case PROB_SEREIAS:
                        setProbabilidadeSereias(valor);
                        break;
                    case PROB_CALMARIA:
                        setProbabilidadeCalmaria(valor);
                        break;
                    case PROB_MOTIM:
                        setProbabilidadeMotim(valor);
                        break;
                    case PROB_VENTO:
                        setProbabilidadeVento(valor);
                        break;
                    case PROB_TEMPESTADE:
                        setProbabilidadeTempestade(valor);
                        break;
                    case PRECO_SOLDADO:
                        setPrecoSoldado(valor);
                        break;
                    case PRECO_VENDA_PEIXE:
                        setPrecoVendePeixe(valor);
                        break;
                    case PRECO_COMPRA_MERCADO:
                        setPrecoCompraMercadoria(valor);
                        break;
                    case PRECO_VENDA_MERCADO:
                        setPrecoVendeMercadoria(valor);
                        break;
                    case SOLDADOS_PORTO:
                        setSoldadosPorto(valor);
                        break;
                    case PRECO_NAVIO:
                        setPrecoNavio(valor);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    ficheiro.close();
}


cmdsEnum convertCommandToEnum(string const &command) {
    
    cmdsEnum enumCommand;
    
    if (command == "lista") {
        enumCommand = lista;
    }
    else if (command == "compranav") {
        enumCommand = compranav;
    }
    else if(command == "sair"){
        enumCommand = sair;
    }
    else if (command == "autoMov") {
        enumCommand = autoMov;
    }
    
    return enumCommand;
}

void Jogo::startNewGame(){
    int moedas;
    string cmd;
    
    cout << "\nIntroduza Moedas Iniciais: ";
    cin >> moedas;
    
    setNumMoedasIniciais(moedas);
    
    setLinhas(10);
    setColunas(20);
    
    constroiMapa(getLinhas(),getColunas());
    imprimeMapa();
    
    cout << "\n\nmoedas do jogador: " << getNumMoedas() << endl;
    cout << "navios do jogador: " << getNumNavios() << endl << endl;
    
    cout << "Segunda fase: \n";
    
    string accao;
    char tipo;
    int identificador;
    
    while(cmd!="sair"){
        
        cout << "\n>>";
        getline(cin, cmd);
        
        istringstream buffer(cmd);
        
        if (buffer >> accao) {
            
            cmdsEnum command = convertCommandToEnum(accao);

            switch(command) {
                case compranav:
                {
                    buffer >> tipo;
                    compraNavio(tipo);
                }
                    break;
                case sair:
                    exit(0);
                    break;
                case lista:
                    listaInfo();
                    break;
                case autoMov:
                {
                    buffer >> identificador;
                    moverNavioAutomaticamente(identificador);
                }
                default:
                    break;
            }
        }
    }
}

void Jogo::startGameFromFile() {
    
    readFile();
    
    cout << "Linhas: " << getLinhas() << ", Colunas: " << getColunas() << endl;
    
    constroiMapa(getLinhas(), getColunas());
    imprimeMapa();
    
    cout << "\n\nmodeas do jogador: " << getNumMoedas() << endl;
    cout << "navios do jogador: " << getNumNavios() << endl;
    cout << "probabilidade Pirata: " << getProbabilidadePirata() << endl;
    cout << "preco Navio: " << getPrecoNavio() << endl;
    cout << "preco Soldado: " << getPrecoSoldado() << endl;
    cout << "preco Venda Peixe: " << getPrecoVendePeixe() << endl;
    cout << "preco Venda Mercado: " << getPrecoVendeMercadoria() << endl;
    cout << "preco Compra Mercado: " << getPrecoCompraMercadoria() << endl;
    cout << "probabilidade Vento: " << getProbabilidadeVento() << endl;
    cout << "probabilidade Tempestade: " << getProbabilidadeTempestade() << endl;
    cout << "probabilidade Sereias: " << getProbabilidadeSereias() << endl;
    cout << "probabiliddade Calmaria: " << getProbabilidadeCalmaria() << endl;
    cout << "probabilidade Motim: " << getProbabilidadeMotim() << endl;

}

void Jogo::menuGame(){
    int escolha;
    while(escolha>3 || escolha <1){
    cout << "\nWelcome to Espedicoes Maritimas"<<endl;
    cout << "1 - Start Game\n"
            "2 - Load from file\n"
            "3 - Options\n"
            "4 - Quit Game\n\n"
            ">> ";
    
    cin >> escolha;
    
    switch (escolha){
        
        case 1: startNewGame();
            break;
            case 2: startGameFromFile();
            break;
        case 3: 
            cout << "Abriu opcoes de Jogo:\n\n";
            getOptions();
            break;
        case 4: 
            cout << "sair do jogo";
            exit(0);
            break;  
        }
    }
}
