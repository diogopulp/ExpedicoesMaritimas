/* 
 * File:   Jogo.cpp
 * Author: diogosantos
 * 
 * Created on November 22, 2018, 7:19 PM
 */

#include <fstream>
#include <math.h>
#include <regex>
#include <string.h>
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
    if(jogador->getNumeroDeMoedas() < CUSTONAVIO){
        textUI.mensagemSemMoedas();
        return;
    }
    
    Navio *novoNavio;\
    
    // TODO mudar isto para a nova forma implementada pelo Daniel!
    
    switch(tipoNavio){
        case 'g':
            novoNavio = Navio::fabrica(tipoNavio);
            //novoNavio = new Galeao();
            break;
        case 'G':
            novoNavio = Navio::fabrica(tipoNavio);
            break;
        case 'v':
            novoNavio = Navio::fabrica(tipoNavio);
            break;
        case 'V':
            novoNavio = Navio::fabrica(tipoNavio);
            break;
        case 'e':
            novoNavio = Navio::fabrica(tipoNavio);
            break;
        case 'E':
            novoNavio = Navio::fabrica(tipoNavio);
            break;
        case 'f':
            novoNavio = Navio::fabrica(tipoNavio);
             break;
        case 'F':
            novoNavio = Navio::fabrica(tipoNavio);
             break;
        default:
            textUI.mensagemErroComando();
            return;
    }
    
 
    //novoNavio->setTipoNavio(tipoNavio);
    
    // 1ª fase (apagar depois) -> colocar navio numa posição no mar
    colocarNavioEmPosicao(novoNavio);
    navios.push_back(novoNavio);
    
    jogador->adicionaNavio(novoNavio);
    jogador->dimNumMoedas(CUSTONAVIO);
    
    textUI.novoNavioConstruido(
            novoNavio->getIdentificador(),
            novoNavio->getCaractereNavio()[0],
            novoNavio->getPosicaoAtualX(),
            novoNavio->getPosicaoAtualY(),
            novoNavio->getNumeroDeSoldados(),
            novoNavio->getQuantidadeDeAgua(),
            novoNavio->getQuantidadeDePeixe(),
            novoNavio->getQuantidadeDeMercadorias()
                    
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
        
        if (navios[i]->getIdentificador() == id) {
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
    
    //mapa[novaLinha][novaColuna]->setCarater(navio->getTipoNavio());
    navio->setPosicaoAtualX(novaLinha);
    navio->setPosicaoAtualY(novaColuna);
    static_cast<Mar*>(mapa[navio->getPosicaoAtualX()][navio->getPosicaoAtualY()])->colocarNavio(navio);
    cout << navio->getPosicaoAtualX();
    cout << navio->getPosicaoAtualY();
}

void Jogo::colocarNavioEmPosicao(Navio *navio) {
    int novaLinha = 0, novaColuna = 0;
    
    do{
        
        novaLinha = rand() % getLinhas();
        novaColuna = rand() % getColunas();

    }while((novaLinha > getLinhas() || novaColuna > getColunas()) && mapa[novaLinha][novaColuna]->getCarater()[0] != '~');
    
    
    //DownCasting
        static_cast<Mar*>(mapa[novaLinha][novaColuna])->colocarNavio(navio);
        
    navio->setPosicaoAtualX(novaLinha);
    navio->setPosicaoAtualY(novaColuna);
}

void Jogo::colocarNavioEmPosicaoAtualizada(Navio *navio) {
    
   
    //DownCasting
    // Depois de colocado o navio no mapa, o navio deve ir buscar as coordenadas ao mapa
    static_cast<Mar*>(mapa[navio->getPosicaoAtualX()][navio->getPosicaoAtualY()])->colocarNavio(navio);
        
    
}

void Jogo::desocuparMarDeNavio(int lin, int col){
    
    cout << endl << "LIN: " << lin << " COL: " << col << endl;
    static_cast<Mar*>(mapa[lin][col])->removerNavio();
    
}

void Jogo::colocarPortoEmPosicao(Porto *porto){
    int linhaTerra = 0, colunaTerra = 0;
    int linhaMar = 0, colunaMar = 0;
    
    // Encontra posição com terra
    do{ 
        linhaTerra = rand() % getLinhas();
        colunaTerra = rand() % getColunas();

    }while((linhaTerra > getLinhas() || colunaTerra > getColunas()) && mapa[linhaTerra][colunaTerra]->getCarater()[0] != '.');
    
    // NOTA: Neste momento os portos estão a ser construidos horizontalmente
    // e não está a ser feita uma verificação dos limites do mapa!
    
    //do{
        linhaMar = linhaTerra;
        colunaMar = colunaTerra+1;
    //}while();
    
    //DownCasting
    // Adicionar o porto ao bloco de terra e ao bloco de mar
    static_cast<Terra*>(mapa[linhaTerra][colunaTerra])->colocarPorto(porto);
    static_cast<Mar*>(mapa[linhaMar][colunaMar])->colocarPorto(porto);
    
    // Adicionar o porto ao jogador
    jogador->adicionaPorto(porto);
        
    porto->setPosXTerra(linhaTerra);
    porto->setPosYTerra(colunaTerra);
    porto->setPosXMar(linhaMar);
    porto->setPosYMar(colunaMar);
    
   
}

DIRECAO Jogo::converteStringParaDirecao(string dir){
    
    if (dir == "C"){
        return C;
    }else if(dir == "B"){
        return B;
    }else if(dir == "E"){
        return E;
    }else if(dir == "D"){
        return D;
    }else if(dir == "CD"){
        return CD;
    }else if(dir == "CE"){
        return CE;
    }else if(dir == "BD"){
        return BD;
    }else if(dir == "BE"){
        return BE;
    }else{
        return C; 
    }
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

void Jogo::adicionaNavioAoPorto(Navio* navio,int idPorto){
    
    int tamanho;
    
    tamanho = jogador->getPortos().size();
    
    for(int i=0; i<tamanho; i++){
        
        if(idPorto == jogador->getPortos()[i]->getPortoID()){
            cout << jogador->getPortos()[i]->getPortoID();
        }
        
    }
    
}

void Jogo::lerFicheiro(){

    // TODO o programa crasha quando chega aqui
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
                        jogador->setNumeroDeMoedas(valor);
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
    else if(command == "movenav"){
        enumCommand = movenav;
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
    }else if(command == "moedas"){
        enumCommand = moedas;
    }
    
    
    return enumCommand;
}

void Jogo::startNewGame(){
    
    string cmd;
    jogador = new Jogador();
    
    // A interface é responsável por receber os comandos inseridos pelo utilizador
    jogador->setNumeroDeMoedas(textUI.moedasIniciais());
    setDimensoesMapa(10,20);
    constroiMapa(getLinhas(),getColunas());
    colocarPortoEmPosicao(new Porto());
    textUI.imprimeSegundaFase();
    
    while(1){
        
        textUI.listaInfo(jogador->getNumeroDeMoedas(), getNumNavios());
        textUI.imprimeListaNavios(navios);
            
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
                        textUI.listaInfo(jogador->getNumeroDeMoedas(), getNumNavios());
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
                        vendeNavio(tokens[1]);
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
                        acrescentaMoedas(tokens[1]);
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
                    case movenav:
                        // Implementar comportamento
                        moveNavio(tokens[1],tokens[2]);
                        break;
                    case evnav:
                        // Implementar comportamento
                        break;
                    case vaipara:
                        // Implementar comportamento
                        //colocaNavioNoPorto()
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
                        criaNavioPirata(tokens[1],tokens[2],tokens[3]);
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
        
        if(cmd == "sair" || cmd == "SAIR"){
            textUI.mostraPontuacao(contaPontuacao());
            return;
        }
        
        textUI.imprimeMapa(mapa);
        
}
}


void Jogo::startGameFromFile() {
    
    lerFicheiro();
    textUI.imprimeLinhasColunas(getLinhas(),getColunas());
    constroiMapa(getLinhas(), getColunas());
    textUI.imprimeMapa(mapa);
    textUI.resumoFicheiroCarregado(
    // TODO Possível ERRO!!!
            jogador->getNumeroDeMoedas(),
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
        if(navios[i]->getIdentificador() == id){
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

void Jogo::moveNavio(string id, string dir){
    
    
    int idNavio; 
    DIRECAO moverN;
    
    // Converte para inteiro
    std::istringstream iss (id);
    iss >> idNavio;
    
    moverN = converteStringParaDirecao(dir);
      
    for(int i=0; i<jogador->getNavios().size(); i++){
        if(jogador->getNavios()[i]->getIdentificador() == idNavio){
            
            Navio* navio = jogador->getNavios()[i];         
    
    if(navio->getEstadoDeCalmaria() == true || navio->getAliancaDoNavio() == false){
        return;
    }
    int novaLinha = 0, novaColuna = 0;
    int antigaLinha = 0, antigaColuna = 0;
    
    antigaLinha = navio->getPosicaoAtualX();
    antigaColuna = navio->getPosicaoAtualY();
    
    int distancia = navio->getVelocidade();
    
        switch(moverN){
            case D:
            {
     
                novaLinha = navio->getPosicaoAtualX();
                novaColuna = navio->getPosicaoAtualY() + distancia;
            }
                break;
            case BD:
            {
                novaLinha = navio->getPosicaoAtualX() + distancia;
                novaColuna = navio->getPosicaoAtualY() + distancia;
            }
                break;
            case CD:
            {
                novaLinha = navio->getPosicaoAtualX() - distancia;
                novaColuna = navio->getPosicaoAtualY() + distancia;
            }
                break;
            case B:
            {
                novaLinha = navio->getPosicaoAtualX() + distancia;
                novaColuna = navio->getPosicaoAtualY();
            }
                break;
            case C:
            {
                novaLinha = navio->getPosicaoAtualX() - distancia;
                novaColuna = navio->getPosicaoAtualY();
            }
                break;
            case E:
            {
                novaLinha = navio->getPosicaoAtualX();
                novaColuna = navio->getPosicaoAtualY() - distancia;
            }
                break;
            case BE:
            {
                novaLinha = navio->getPosicaoAtualX() + distancia;
                novaColuna = navio->getPosicaoAtualY() - distancia;
            }
                break;
            case CE:
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

                colocarNavioEmPosicaoAtualizada(navio);
                desocuparMarDeNavio(antigaLinha, antigaColuna);

                cout << endl << "NLIN: " << novaLinha << " NCOL: " << novaColuna << endl;

                cout << endl << "ALIN: " << antigaLinha << " ACOL: " << antigaColuna << endl;


            }
        
           }
    }
}



Celula * Jogo::getCelula(int x, int y) const{
    return mapa[x][y];
}

void Jogo::escunasPescam(){
    for(int i = 0; i < navios.size(); i++){
        
        if(navios[i]->getCaractereNavio()[0] == 'E'){
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
    if(navios[navioRand]->getCaractereNavio()[0] == 'E' || navios[navioRand]->getCaractereNavio()[0] == 'F'){
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
    
    if(navio->getCaractereNavio()[0] == 'E'){
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
    }else if(navio->getCaractereNavio()[0] == 'V'){
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
    }else if(navio->getCaractereNavio()[0] == 'G'){
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
    }else if(navio->getCaractereNavio()[0] == 'F'){
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

void Jogo::verificaCombate(){
    for(int i = 0; i< navios.size(); i++){
        if(navios[i]->getAliancaDoNavio() == true){
            Navio * nav = this->verificaNavioAdjacente(navios[i]->getPosicaoAtualX(), navios[i]->getPosicaoAtualY());
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

Navio * Jogo::verificaNavioAdjacente(int x, int y){
    
    // verificar se existe navio adjacente a x e y, se houver retorna navio senão retorna null
    
    if(x + 1 > this->getLinhas() || y + 1 > this->getColunas() || x - 1 < 0 || y - 1 < 0){
        return nullptr;
    }
    
    for(int i = 0; i < navios.size(); i++){
        int posx = navios[i]->getPosicaoAtualX();
        int posy = navios[i]->getPosicaoAtualY();
        if((posx == x - 1 && posy == y + 1) || (posx == x && posy == y + 1) || (posx == x + 1 && posy == y + 1) || (posx == x - 1 && posy == y) || (posx == x + 1 && posy == y) || (posx == x - 1 && posy == y - 1) || (posx == x && posy == y - 1) || (posx == x + 1 && posy == y - 1)){
            return navios[i];
        }
    }
    return nullptr;
}



Escuna * Jogo::procuraEscuna(int x, int y){
     if(x + 1 > this->getLinhas() || y + 1 > this->getColunas() || x - 1 < 0 || y - 1 < 0){
        return nullptr;;
    }
    
     for(int i = 0; i < navios.size(); i++){
        int posx = navios[i]->getPosicaoAtualX();
        int posy = navios[i]->getPosicaoAtualY();
        if(((posx == x - 1 && posy == y + 1) || (posx == x && posy == y + 1) || (posx == x + 1 && posy == y + 1) || (posx == x - 1 && posy == y) || (posx == x + 1 && posy == y) || (posx == x - 1 && posy == y - 1) || (posx == x && posy == y - 1) || (posx == x + 1 && posy == y - 1)) && navios[i]->getCaractereNavio() == "EEEE"){
            Escuna escuna;
            navios[i] = &escuna;
            return (Escuna *)navios[i];
        }
    }
     return nullptr;
}

void Jogo::verificaTransfernciaDePeixe(){
    for(int i = 0; i < navios.size(); i++){
        if(navios[i]->getCaractereNavio()[0] == 'G'){
            Escuna *e = this->procuraEscuna(navios[i]->getPosicaoAtualX(),navios[i]->getPosicaoAtualY());
            if(e != nullptr){
                Galeao galeao;
                navios[i] = &galeao;
                galeao.transferePeixe(e);
            }
        }else if(navios[i]->getCaractereNavio()[0] == 'V' && navios[i]->getAliancaDoNavio() == true){
            Escuna *e = this->procuraEscuna(navios[i]->getPosicaoAtualX(), navios[i]->getPosicaoAtualY());
            if(e != nullptr){
                Veleiro veleiro;
                navios[i] = &veleiro;
                veleiro.transferePeixe(e);
            }
            
        }
    }
}

void Jogo::vaiPara(Navio* navio, Porto* porto){
    
    int difLin, difCol;
    int comp1, comp2;
   
    //Saber qual das duas células que o Porto tem fica mais perto
    comp1 = navio->getPosicaoAtualX() - porto->getPosXMar();
    comp2 = navio->getPosicaoAtualX() - porto->getPosXTerra();
    
    if(abs(comp1) < abs(comp2)){
        difLin = abs(comp1);
    }else if(abs(comp1) > abs(comp2)){
        difLin = abs(comp2);
    }else{
        difLin = abs(comp1);
    }
    
    cout << endl << abs(comp1) << endl;
    cout << endl << abs(comp2) << endl;
    
    //Saber qual das duas células que o Porto tem fica mais perto
    comp1 = navio->getPosicaoAtualY() - porto->getPosYMar();
    comp2 = navio->getPosicaoAtualY() - porto->getPosYTerra();
    
    if(abs(comp1) < abs(comp2)){
        difCol = abs(comp1);
    }else if(abs(comp1) > abs(comp2)){
        difCol = abs(comp2);
    }else{
        difCol = abs(comp1);
    }
    
    cout << endl << abs(comp1) << endl;
    cout << endl << abs(comp2) << endl;
    
    /*for(int i=navio->getPosicaoAtualX(); i<difLin; i++){
        
        moveNavio(navio,)
    }*/
    
    
    
}

void Jogo::vendeNavio(string id){
     
    int idNav; 
    
    // Converte para inteiro
    std::istringstream iss (id);
    iss >> idNav;
    
    jogador->venderNavio(idNav);
    
    for(int i=0; i<navios.size(); i++){
        if(idNav == navios[i]->getIdentificador()){
            
            desocuparMarDeNavio(navios[i]->getPosicaoAtualX(), navios[i]->getPosicaoAtualY());
            navios.erase(navios.begin() + i);
            
        }
    }
    
}

void Jogo::acrescentaMoedas(string moedas){
    
    int novasMoedas; 
    
    // Converte para inteiro
    std::istringstream iss (moedas);
    iss >> novasMoedas;
    
    jogador->addMaisMoedas(novasMoedas);
}

void Jogo::criaNavioPirata(string x, string y, string tipo){
    
    int lin, col; 
    
    // Converte para inteiro
    std::istringstream iss (x);
    iss >> lin;
    
    std::istringstream oss(y);
    oss >> col;
    
    if(tipo == "F" || tipo == "f"){
        Fragata* fragata = new Fragata();
        
        static_cast<Mar*>(mapa[lin][col])->colocarNavio(fragata);
        navios.push_back(fragata);
    }else if(tipo == "V" || tipo == "v"){
        Veleiro* veleiro = new Veleiro();
        
        static_cast<Mar*>(mapa[lin][col])->colocarNavio(veleiro);
        navios.push_back(veleiro);
    }
}
