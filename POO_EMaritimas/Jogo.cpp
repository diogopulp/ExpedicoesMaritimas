/* 
 * File:   Jogo.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 7:19 PM
 */

#include <fstream>
#include <math.h>
#include <regex>
#include "Jogo.h"
#include "Terra.h"
#include "Navio.h"
#include "Galeao.h"
#include "Veleiro.h"
#include "Fragata.h"
#include "Escuna.h"
#include "Jogador.h"


Jogo & Jogo::operator=(const Jogo& orig){
    if(this == &orig){
        return *this;
    }
    for(int i = 0; i<navios.size(); i++){
        delete navios[i];
    }
    navios.clear();
    for(int i = 0; i <orig.navios.size(); i++){
        Navio * n = orig.navios[i]->duplica();
        navios.push_back(n);
    }
    return *this;
}

/*eliminar os ponteiros do tipo navio do vector navios*/
Jogo::~Jogo(){
    for(Navio * n: navios){
        delete n;
    }
}


Jogo::Jogo() {
    //constroiMapa(10,20);

}

Jogo::Jogo(const Jogo& orig) {
    *this = orig;
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


void Jogo::compraNavio(char tipoNavio) {

    // Se o jogador não tiver moedas em quantia suficiente, sai da função
    if(numeroMoedas < CUSTONAVIO)
        return;
    
    Navio *novoNavio;\
    
    // TODO mudar isto!!!
    
    switch(tipoNavio){
        case 'g':
            novoNavio = new Galeao();
            break;
        case 'G':
            novoNavio = new Galeao();
            break;
        case 'v':
            novoNavio = new Veleiro();
            break;
        case 'V':
            novoNavio = new Veleiro();
            break;
        case 'e':
            novoNavio = new Escuna();
            break;
        case 'E':
            novoNavio = new Escuna();
            break;
        case 'f':
            novoNavio = new Fragata();
             break;
        case 'F':
            novoNavio = new Fragata();
             break;
        default:
            break;
    }
    
    
    novoNavio->setTipoNavio(tipoNavio);
    
    // 1ª fase (apagar depois) -> colocar navio numa posição no mar
    colocarNavioEmPosicao(novoNavio, tipoNavio);
    navios.push_back(novoNavio);
    
    numeroMoedas -= CUSTONAVIO;
    
    textUI.novoNavioConstruido(
            novoNavio->getIdNavio(),
            novoNavio->getTipoNavio(),
            novoNavio->getPosicaoAtualX(),
            novoNavio->getPosicaoAtualY()
    );
    
}

void Jogo::moverNavioAutomaticamente(int id){
    
    if (getNumNavios() <= 0) {
        textUI.mensagemAvisoNavio();
        return;
    }
    
    bool navioEncontrado = false;
    Navio *navio;
    
    for (int i = 0; i < getNumNavios(); i++) {
        
        if (navios[i]->getIdNavio() == id) {
            navio = navios[i];
            navioEncontrado = true;
            break;
        }
    }
    
    if (!navioEncontrado) {
        textUI.mensagemAvisoNavio(id);
        return;
    }
    
    int novaLinha = 0, novaColuna = 0;
    
    do{
        
        int posicao = rand() % 8;
        
        switch (posicao) {
            case 1:
            {
                novaLinha = navio->getPosicaoAtualX() - 1;
                novaColuna = navio->getPosicaoAtualY() - 1;
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
    
    //mapa[navio->getPosicaoAtualX()][navio->getPosicaoAtualY()]->setCarater('~');
    //mapa[novaLinha][novaColuna]->setCarater(navio->getTipoNavio());
    navio->setPosicaoAtualX(novaLinha);
    navio->setPosicaoAtualY(novaColuna);
    
}

void Jogo::colocarNavioEmPosicao(Navio *navio, char caraterNavio) {
    int novaLinha = 0, novaColuna = 0;
    
    do{
        
        novaLinha = rand() % getLinhas();
        novaColuna = rand() % getColunas();

    }while((novaLinha > getLinhas() || novaColuna > getColunas()) && mapa[novaLinha][novaColuna]->getCarater()[0] != '~');
    
    //mapa[novaLinha][novaColuna]->setCarater(caraterNavio);
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

void Jogo::lerFicheiro(){

    fstream ficheiro("startGame.txt");
    string linha;
    int valor;
    
    if (!ficheiro.is_open()) {
        textUI.mensagemErroFicheiro();
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

cmdsEnum Jogo::convertCommandToEnum(string const &command) {
    
    cmdsEnum enumCommand;
    
    if(command == "info"){
        enumCommand = info;
    }
    else if (command == "lista") {
        enumCommand = lista;
    }
    else if (command == "compranav") {
        enumCommand = compranav;
    }
    else if(command == "sair"){
        enumCommand = sair;
    }
    else if (command == "automov") {
        enumCommand = automov;
    }
    else if(command == "vendenav"){
        enumCommand = vendenav;
    }
    else if(command == "exec"){
        enumCommand = exec;
    }
    else if(command == "prox"){
        enumCommand = prox;
    }
    else if(command == "compra"){
        enumCommand = compra;
    }
    else if(command == "vende"){
        enumCommand = vende;
    }
    else if(command == "movenavio"){
        enumCommand = movenavio;
    }
    else if(command == "stop"){
        enumCommand = stop;
    }
    else if(command == "pirata"){
        enumCommand = pirata;
    }
    else if(command == "evpos"){
        enumCommand = evpos;
    }
    else if(command == "evnav"){
        enumCommand = evnav;
    }
    else if(command == "vaipara"){
        enumCommand = vaipara;
    }
    else if(command == "comprasold"){
        enumCommand = comprasold;
    }
    else if(command == "saveg"){
        enumCommand = saveg;
    }
    else if(command == "loadg"){
        enumCommand = loadg;
    }
    else if(command == "delg"){
        enumCommand = delg;
    }
    
    
    return enumCommand;
}

void Jogo::startNewGame(){
    
    string cmd;
    jogador = new Jogador();
    jogador->setNumeroDeMoedas(textUI.moedasIniciais());
    // A interface é responsável por receber os comandos inseridos pelo utilizador
    //setNumMoedasIniciais(textUI.moedasIniciais());
    setDimensoesMapa(10,20);
    constroiMapa(getLinhas(),getColunas());
    textUI.listaInfo(getNumMoedas(), getNumNavios());
    textUI.imprimeSegundaFase();  
    
    while(1){
            
        cmd = textUI.escutaComandos();
        cout << cmd;
        
        istringstream iss(cmd);
  
        // Vetor necessário para separar os comandos vindos da UI
        vector<string> tokens{
                        istream_iterator<string>{iss},
                        istream_iterator<string>{}
        };
        
        // Interpretação de comandos
        if(tokens.size() > 0){
            
            cmdsEnum command = convertCommandToEnum(tokens[0]);
            
            if(tokens.size() == 1)
            {
                switch(command){
                    case info:
                        textUI.infoComandos();
                        break;
                    case prox:
                        // Implementar comportamento
                        break;
                    case lista:
                        textUI.listaInfo(getNumMoedas(), getNumNavios());
                        break;
                    default:
                        break;
                }       
            }else if(tokens.size() == 2)
            {
                switch(command){
                    case exec:
                        // Implementar comportamento
                        break;
                    case compranav:
                        // Envia o primeiro caractere do token
                        compraNavio(tokens[1].at(0));
                        break;
                    case vendenav:
                        // Implementar comportamento
                        break;
                    case vende:
                        // Implementar comportamento
                        break;
                    case automov:
                        moverNavioAutomaticamente(tokens[1].at(0));
                        break;
                    case stop:
                        // Implementar comportamento
                        break;
                    case moedas:
                        // Implementar comportamento
                        break;
                    case saveg:
                        // Implementar comportamento
                        break;
                    case loadg:
                        // Implementar comportamento
                        break;
                    case delg:
                        // Implementar comportamento
                        break;
                    default:
                        break;
                }       
            }else if(tokens.size() == 3)
            {
                switch(command){
                    case compra:
                        // Implementar comportamento
                        break;
                    case movenavio:
                        // Implementar comportamento
                        break;
                    case evnav:
                        // Implementar comportamento
                        break;
                    case vaipara:
                        // Implementar comportamento
                        break;
                    case comprasold:
                        // Implementar comportamento
                        break;
                    default:
                        break;
                }     
            }else if(tokens.size() == 4)
            {
                switch(command){
                    case pirata:
                        // Implementar comportamento
                        break;
                    case evpos:
                        // Implementar comportamento
                        break;
                    case vaipara:
                        // Implementar comportamento
                        break;
                    default:
                        break;
                }     
            }
                
            
        }
        
        if(cmd == "sair" || cmd == "SAIR")
            return;
        
        textUI.imprimeMapa(mapa);
        
}
}


void Jogo::startGameFromFile() {
    
    lerFicheiro();
    textUI.imprimeLinhasColunas(getLinhas(),getColunas());
    constroiMapa(getLinhas(), getColunas());
    textUI.imprimeMapa(mapa);
    textUI.resumoFicheiroCarregado(
            getNumMoedas(),
            getNumNavios(),
            getProbabilidadePirata(),
            getPrecoNavio(),
            getPrecoSoldado(),
            getPrecoVendePeixe(),
            getPrecoVendeMercadoria(),
            getPrecoCompraMercadoria(),
            getProbabilidadeVento(),
            getProbabilidadeTempestade(),
            getProbabilidadeSereias(),
            getProbabilidadeCalmaria(),
            getProbabilidadeMotim()
    );

}

void Jogo::getOptions(){
   
    textUI.imprimeOpcoes();
    
}

void Jogo::menuJogo(){
    
    textUI.imprimirMenu();
    
    switch (textUI.escutaMenu()){

        case 1: 
            startNewGame();
            break;
        case 2: 
            startGameFromFile();
            break;
        case 3: 
            getOptions();
            break;
        case 4: 
            exit(0);
            break;
        default:
            textUI.imprimirMenu();
    }
 
}

// Gets e Setters
// Os Gets e Setters devem ser colocados no fim do código pois são funções de auxílio e
// são têm menos probabilidade de serem alteradas futuramente(ganha-se muito tempo no scroll).

bool Jogo::setLinhas(int linhas) {
    
    // O número de linhas deve ser superior a 10
    if(linhas >= 10){
        this->linhas = linhas;
        return true;
    }
    return false;
}

int Jogo::getLinhas() {
    return linhas;
}

bool Jogo::setColunas(int colunas) {
    
    // O número de colunas deve ser superior a 10
    if(colunas >= 10){
        this->colunas = colunas;
        return true;
    }
    return false;
}

int Jogo::getColunas() {
    return colunas;
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

//criacao dos diferentes navios metodo a chamar quando se compra um navio
bool Jogo::adicionaNavio(char tipo){
    Navio * n = Navio::fabrica(tipo);
    if(n == nullptr){
        return false;
    }
    navios.push_back(n);
    return true;
}

int Jogo::procuraNavio(int id)const{
    for(int i = 0; i<navios.size(); i++){
        if(navios[i]->getIdNavio() == id){
            return i; // posicao do vector
        }
    }
    return -1; 
    /*posicao impossivel*/
}

/*remove navio do jogo
//destroi o navio alvo
//liberta memoria dinamica
//retirar do vector o ponteiro que aponta para a memoria que ja foi livertada anteriormente
 */
bool Jogo::destroiNavio(int id){
    int alvo = procuraNavio(id);
    if(alvo == -1){
        return false;
    }
    delete navios[alvo];
    
    navios.erase(navios.begin() + alvo);
    return true;
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

vector<vector<Celula*> > Jogo::getMapa(){
    return mapa;
}

void Jogo::setDimensoesMapa(int lin, int col){
    
    setLinhas(lin);
    setColunas(col);
    
}

void Jogo::moveNavio(Navio * navio, DIRECAO moverN){
    
    if(navio->getEstadoDeCalmaria() == true || navio->getAliancaDoNavio() == false){
        return;
    }
    int novaLinha = 0, novaColuna = 0;
    int distancia = navio->getVelocidade();
    
        switch(moverN){
            case frente:
            {
                novaLinha = navio->getPosicaoAtualX();
                novaColuna = navio->getPosicaoAtualY() + distancia;
            }
                break;
            case diagonalfrenteDireita:
            {
                novaLinha = navio->getPosicaoAtualX() + distancia;
                novaColuna = navio->getPosicaoAtualY() + distancia;
            }
                break;
            case diagonalfrenteEsquerda:
            {
                novaLinha = navio->getPosicaoAtualX() - distancia;
                novaColuna = navio->getPosicaoAtualY() + distancia;
            }
                break;
            case direita:
            {
                novaLinha = navio->getPosicaoAtualX() + distancia;
                novaColuna = navio->getPosicaoAtualY();
            }
                break;
            case esquerda:
            {
                novaLinha = navio->getPosicaoAtualX() - distancia;
                novaColuna = navio->getPosicaoAtualY();
            }
                break;
            case tras:
            {
                novaLinha = navio->getPosicaoAtualX();
                novaColuna = navio->getPosicaoAtualY() - distancia;
            }
                break;
            case diagonaltrasDireita:
            {
                novaLinha = navio->getPosicaoAtualX() + distancia;
                novaColuna = navio->getPosicaoAtualY() - distancia;
            }
                break;
            case diagonaltrasEsquerda:
            {
                novaLinha = navio->getPosicaoAtualX() - distancia;
                novaColuna = navio->getPosicaoAtualY() - distancia;
            }
                break;
            default:
                break;
    
        }

            
    if((novaLinha <= getLinhas() || novaColuna <= getColunas()) && mapa[novaLinha][novaColuna]->getCarater()[0] == '~'){
    navio->setPosicaoAtualX(novaLinha);
    navio->setPosicaoAtualY(novaColuna);
    }
}

Celula * Jogo::getCelula(int x, int y) const{
    return mapa[x][y];
}

void Jogo::escunasPescam(){
    for(int i = 0; i < navios.size(); i++){
        if(navios[i]->getTipoNavio() == 'E'){
            Escuna *e = dynamic_cast<Escuna *>(navios[i]);
            Celula *mar = getCelula(e->getPosicaoAtualX(), e->getPosicaoAtualY());
            int peixeSobra = e->pescar(((Mar *)mar)->getQuantidadeDePeixeNaCelulaMar());
            ((Mar *)mar)->setQuantidadeDePeixeNaCelulaMar(peixeSobra);
        }
    }
}

void Jogo::ocorreTempestade(){
    for(int i = 0; i<navios.size(); i++){
        danificaNavio(navios[i], i);
    }
}

void Jogo::ocorreSereias(){
    int linha=0, coluna=0;
    
    do{
        linha = rand() % getLinhas();
        coluna = rand() % getColunas();
    }while((linha > getLinhas() || coluna > getColunas()) && (mapa[linha][coluna]->getCarater()[0] == 'E' || mapa[linha][coluna]->getCarater()[0] == 'V' || mapa[linha][coluna]->getCarater()[0] == 'G' || mapa[linha][coluna]->getCarater()[0] == 'F'));
}

void Jogo::sereiasMatamSoldados(){
    int navioRand = rand() % navios.size();
    navios[navioRand]->setQuantidadeDeSoldados(navios[navioRand]->getNumeroDeSoldados() * 0.9);
}

void Jogo::ocorreCalmaria(){
    int navioRand = rand() % navios.size();
    navios[navioRand]->soldadosComsomemAgua();
    navios[navioRand]->setEstadoDeCalmaria(true);
    jogador->setNumeroDeMoedas(jogador->getNumeroDeMoedas() + 100);
}

void Jogo::ocorreMotim() {
    int navioRand = rand() % navios.size();
    if(navios[navioRand]->getTipoNavio() == 'E' || navios[navioRand]->getTipoNavio() == 'F'){
        navios[navioRand]->setAliancaDoNavio(false);
    }else{
        delete navios[navioRand];
        navios.erase(navios.begin() + navioRand);
    }
}

void Jogo::apareceNavioPirata(){
    int linha=0, coluna=0;
    
    do{
        linha = rand() % getLinhas();
        coluna = rand() % getColunas();
    }while((linha > getLinhas() || coluna > getColunas()) && (mapa[linha][coluna]->getCarater()[0] == '~'));
    
    int tipoDeNavioPirata = rand() % 2;
    if(tipoDeNavioPirata <= 50){
        Fragata *f = new Fragata();
        f->setAliancaDoNavio(false);
        f->setPosicaoAtualX(linha);
        f->setPosicaoAtualY(coluna);
    }else{
        Veleiro *v = new Veleiro();
        v->setAliancaDoNavio(false);
        v->setPosicaoAtualX(linha);
        v->setPosicaoAtualY(coluna);
    }
    
}


void Jogo::danificaNavio(Navio *navio, int posicaoArray){
    int probabilidade = rand() % 101;
    
    if(navio->getTipoNavio() == 'E'){
        if(probabilidade <= 20){
            Escuna escuna;
            navio = &escuna;
            escuna.setQuantidadeDePeixe(0);
            
//            Escuna *escuna = dynamic_cast<Escuna *>(navio);
//            escuna->setQuantidadeDePeixe(0);
        }else if(probabilidade > 20 && probabilidade <= 55){
            delete navio;
            navios.erase(navios.begin() + posicaoArray);
        }else{
            Escuna escuna;
            navio = &escuna;
            escuna.setQuantidadeDeAgua(100);
        }
    }else if(navio->getTipoNavio() == 'V'){
        Veleiro veleiro;
        navio = &veleiro;
        int cargaDoVeleiro = veleiro.getQuantidadeDePeixe() + veleiro.getQuantidadeDeMercadorias();
//        Veleiro *veleiro = dynamic_cast<Veleiro *>(navio);
//        int cargaDoVeleiro = veleiro->getQuantidadeDePeixe() + veleiro->getQuantidadeDeMercadorias();
        if(cargaDoVeleiro > veleiro.getCargaTotal()/2){
            if(probabilidade <= 35){
                delete navio;
                navios.erase(navios.begin() + posicaoArray);
            }
        }else if(probabilidade <= 20){
                delete navio;
                navios.erase(navios.begin() + posicaoArray);
        }else {
            Veleiro veleiro;
            navio = &veleiro;
            veleiro.setQuantidadeDeAgua(200);
        }
    }else if(navio->getTipoNavio() == 'G'){
        Galeao galeao;
        navio = &galeao;
        galeao.setQuantidadeDeSoldados(galeao.getNumeroDeSoldados() * 0.9);
//        Galeao *galeao = dynamic_cast<Galeao *>(navio);
//        galeao->setQuantidadeDeSoldados(galeao->getNumeroDeSoldados() * 0.9);
        if(probabilidade <= 40){
            delete navio;
            navios.erase(navios.begin() + posicaoArray);
        }else{
            Galeao galeao;
            navio = &galeao;
            galeao.setQuantidadeDeAgua(400);
        }
    }else if(navio->getTipoNavio() == 'F'){
        Fragata fragata;
        navio = &fragata;
        int perdeSoldados = fragata.getNumeroDeSoldados() * 0.85;
        fragata.setQuantidadeDeSoldados(perdeSoldados);
//        Fragata *fragata = dynamic_cast<Fragata *>(navio);
//        int perdeSoldados = fragata->getNumeroDeSoldados() * 0.85;
//        fragata->setQuantidadeDeSoldados(perdeSoldados);
        if(probabilidade <= 20){
            delete navio;
            navios.erase(navios.begin() + posicaoArray);
        }else{
            Fragata fragata;
            navio = &fragata;
            fragata.setQuantidadeDeAgua(500);
        }
    }
}

int Jogo::contaPontuacao(){
    int totalDeBarcosAliados = 0;
    for(int i = 0; i < navios.size(); i++){
        if(navios[i]->getAliancaDoNavio() == true){
            totalDeBarcosAliados++;
        }
    }
    int pontuacao = (totalDeBarcosAliados * 100) + jogador->getNumeroDeMoedas();
    return pontuacao;
}

void Jogo::venderNavio(int idNav){
    
    if(navios.size() > 0){
        for(int i = 0; i < navios.size(); i++){
            if(navios[i]->getIdNavio() == idNav){
                delete navios[i];
                navios.erase(navios.begin() + i);
                jogador->setNumeroDeMoedas(jogador->getNumeroDeMoedas() + 100);
                break;
            }
        }
    }
}

void Jogo::verificaCombate(){
    for(int i = 0; i< navios.size(); i++){
        if(navios[i]->getAliancaDoNavio() == true){
            Navio * nav = navios[i]->verificaNavioAdjacente(navios[i]->getPosicaoAtualX(), navios[i]->getPosicaoAtualY());
            if(nav!=nullptr){
               int navQuePerdeu = navios[i]->combate(nav);
               destroiNavio(navQuePerdeu);
            }
        }
    }

}

void Jogo::ocorreEvento(){
    int probabilidade = rand() % 101;
    
    if(probabilidade <= 30){
        ocorreCalmaria();
    }
    else if(probabilidade > 30 && probabilidade <= 60){
        ocorreTempestade();
    }else if(probabilidade > 60 && probabilidade <= 80){
        ocorreSereias();
    }else{
        ocorreMotim();
    }
}