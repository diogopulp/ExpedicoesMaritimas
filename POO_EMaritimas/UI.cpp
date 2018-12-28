/* 
 * File:   UI.cpp
 * Author: diogosantos
 * 
 * Created on December 28, 2018, 11:54 AM
 */

#include "UI.h"

UI::UI() {
}

UI::UI(const UI& orig) {
}

UI::~UI() {
}

void UI::imprimeMapa(vector<vector<Celula*> > mapa){
    
    // Gera representação do mapa com células 2x2
    for(int i = 0; i<mapa.size(); i++){
        cout << endl;
        for(int j=0; j<mapa[i].size(); j++){

            // Imprime os dois primeiros carateres
            cout << mapa[i][j]->getCarater()[0];
            cout << mapa[i][j]->getCarater()[1] << " ";
           
        }
        cout << endl;
        for(int j=0; j<mapa[i].size(); j++){
            
            // Imprime os restantes carateres
            cout << mapa[i][j]->getCarater()[2];
            cout << mapa[i][j]->getCarater()[3] << " ";

        }
    }   
}

void UI::infoComandos(){
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

void UI::listaInfo(int nMoedas, int nNavios) {
    cout << "Num moedas: "<< nMoedas << endl;
    cout << "Num navios: "<< nNavios << endl;
}

int UI::menuGame(int escolha){
  
    while(escolha>3 || escolha <1){
    cout << "\nBem-Vindo ao Espedicoes Maritimas"<<endl;
    cout << "1 - Começar Jogo\n"
            "2 - Carregar Jogo\n"
            "3 - Opcoes\n"
            "4 - Sair do Jogo\n\n"
            ">> ";
    
    cin >> escolha;
    
    switch (escolha){
        
        case 1: 
            //startNewGame();
            return 1;
        case 2: 
            //startGameFromFile();
            return 2;
        case 3: 
            cout << "Abriu opcoes de Jogo:\n\n";
            //getOptions();
            return 3;
        case 4: 
            cout << "Sair do jogo";
            //exit(0);
            return 4; 
        default:
            return 0;
        }
    }
    
    return 0;
   
}

int UI::moedasIniciais(){
    
    int moedas;
    cout << "\nIntroduza Moedas Iniciais: ";
    cin >> moedas;
    
    return moedas;
}

void UI::imprimeNumMoedasJogador(int nMoedas){
    
    cout << endl << "N Moedas do jogador: " << nMoedas << endl;
}

void UI::imprimeNumNaviosJogador(int nNavios){
    
    cout << "Navios do jogador: " << nNavios << endl << endl;
    
}

void UI::imprimeSegundaFase(){
    cout << "Segunda fase:" << endl;
}

int UI::escutaComandos(){
    
    string cmd, accao;
       
    cout << endl << ">> ";
    getline(cin, cmd);
        
    istringstream buffer(cmd);

    if (buffer >> accao) {

        cmdsEnum command = convertCommandToEnum(accao);

        switch(command) {
            case compranav:
               
                //compraNavio(tipo);
                return 1;
            case sair:
                //exit(0);
                return 2;
            case lista:
                //listaInfo();
                return 3;
            case autoMov:
               
                //moverNavioAutomaticamente(identificador);
                return 4;
            default:
                return 0;
        }
    }
    return 0;
}

int UI::compraEscolherTipodeNavio(char tipo){
    
    switch(tipo){
        case 'g':
            return 1;
        case 'G':
            return 1;
        case 'v':
            return 2;
        case 'V':
            return 2;
        case 'e':
            return 3;
        case 'E':
            return 3;
        case 'f':
            return 4;
        case 'F':
            return 4;
        default:
            return 0;
    }
}

char UI::leCaraterInserido(){
    
    string cmd;
    char carater;
    
    getline(cin, cmd);
        
    istringstream buffer(cmd);
    
    buffer >> carater;
    return carater;
}

int UI::leInteiroInserido(){
    
    string cmd;
    int identificador;
    
    getline(cin, cmd);
        
    istringstream buffer(cmd);
    
    buffer >> identificador;
    return identificador;
    
}

cmdsEnum UI::convertCommandToEnum(string const &command) {
    
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

void UI::imprimeOpcoes(){
    
    cout << "Opcoes do jogo:\n"
            "O jogo tem duas fases. Na primeira fase precisa de inicializar o jogo e defenir os elementos iniciais do jogo abrindo "
            "o ficheiro.\nPara esta funcionalidade tem que usar o comando config <nomeFicheiro>\n"
            "Na segunda fase vai ser o desenrolar do jogo e vai ter que escolher os seus commandos para interagir com o jogo";
    
}

void UI::mensagemErroFicheiro(){
    cout << "Erro ao carregar ficheiro. Fechar programa.";
}

void UI::mensagemAvisoNavio(){
    cout << "Não tem nenhum navio" << endl;
}

void UI::novoNavioConstruido(int navioID, int tipo, int posX, int posY){
    
    cout << "Novo navio construido com ID:" << navioID 
    << ", Tipo:" << tipo
    << ", Posicao: (" << posX << "," << posY << ")" << endl;
    
}

void UI::mensagemAvisoNavio(int id){
    cout << "Não foi encontrado um navio com o identificador: " << id << endl;
}

void UI::imprimeLinhasColunas(int lin, int col){
    
    cout << "Linhas: " << lin << ", Colunas: " << col << endl;
}

void UI::resumoFicheiroCarregado(
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
){
    
    cout << "\n\nmodeas do jogador: " << nMoedas << endl;
    cout << "navios do jogador: " << nNavios << endl;
    cout << "probabilidade Pirata: " << probPirata << endl;
    cout << "preco Navio: " << precoNavio << endl;
    cout << "preco Soldado: " << precoSoldado << endl;
    cout << "preco Venda Peixe: " << precoVPeixe << endl;
    cout << "preco Venda Mercado: " << precoVMercadoria << endl;
    cout << "preco Compra Mercado: " << precoCMercadoria << endl;
    cout << "probabilidade Vento: " << probVento << endl;
    cout << "probabilidade Tempestade: " << probTempestade << endl;
    cout << "probabilidade Sereias: " << probSereias << endl;
    cout << "probabiliddade Calmaria: " << probCalmaria << endl;
    cout << "probabilidade Motim: " << probMotim << endl;
}