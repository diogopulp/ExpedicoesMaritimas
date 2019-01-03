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

void UI::mostraPontuacao(int pontuacao){
    cout << endl << "Pontuacao Final: " << pontuacao;
}

void UI::imprimeMapa(vector<vector<Celula*> > mapa){
    
    
    // Gera representação do mapa com células 2x2
    for(int i = 0; i<mapa.size(); i++){
        cout << endl << endl;
        for(int j=0; j<mapa[i].size(); j++){

            
            // Imprime os dois primeiros carateres
            cout << mapa[i][j]->getCaratere()[0] << " ";
            cout << mapa[i][j]->getCaratere()[1] << "   ";
           
        }
        cout << endl;
        for(int j=0; j<mapa[i].size(); j++){
            
            // Imprime os restantes carateres
            cout << mapa[i][j]->getCaratere()[2] << " ";
            cout << mapa[i][j]->getCaratere()[3] << "   ";

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
            "movenav <N><X>\n"
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
    cout << endl << "Numero de moedas: "<< nMoedas << endl;
    cout << "Numero de navios: "<< nNavios << endl;
}

void UI::imprimirMenu(){
    
    cout << endl <<
            "Bem-Vindo ao Espedicoes Maritimas" << endl << endl <<
            "1 - Começar Jogo" << endl <<
            "2 - Carregar Jogo" << endl <<
            "3 - Opcoes" << endl << 
            "4 - Sair do Jogo" << endl << endl;
}

int UI::escutaMenu(){
    
    int escolha;
    
    cout << ">> ";
    cin >> escolha;
    
    //Inputs protegidos
    if(cin.good())
        return escolha;
    
    while(!cin.good()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
                
        cout << ">> ";
        cin >> escolha;
        if(cin.good())
            return escolha;
    }
    
    return 0;
}

int UI::moedasIniciais(){
    
    int moedas;
    cout << endl << "Introduza Moedas Iniciais: ";
    cin >> moedas;
    
    //Inputs protegidos
    if(cin.good())
            return moedas;
    
    while(!cin.good()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
                
        cout << endl <<"Introduza Moedas Iniciais: ";
        cin >> moedas;
        if(cin.good())
            return moedas;
    }
    
    return 0;
    
    
}

void UI::imprimeNumMoedasJogador(int nMoedas){
    
    cout << endl << "N Moedas do jogador: " << nMoedas << endl;
}

void UI::imprimeNumNaviosJogador(int nNavios){
    
    cout << endl << "Navios do jogador: " << nNavios << endl << endl;
    
}

void UI::mostraNaviosPorto(int nNavios, int idPorto){
    
    cout << endl << "Navios no porto " << idPorto << ": " <<  nNavios << endl << endl;
}

void UI::imprimeListaNavios(vector <Navio*> navios){
    
    cout << endl;
    for (int i=0; i<navios.size(); i++){
        
        cout << "[" << navios[i]->getCaractereNavio()[0] << "] ";
    }
    cout << endl;
            
    
}

void UI::imprimeSegundaFase(){
    cout << "Segunda fase:" << endl;
}

string UI::escutaComandos(){
    
    string cmd;
      
    cout << endl << ">> ";
    getline(cin, cmd);

    return cmd;

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

void UI::imprimeOpcoes(){
    
    cout << "Opcoes do jogo:\n"
            "O jogo tem duas fases. Na primeira fase precisa de inicializar o jogo e defenir os elementos iniciais do jogo abrindo "
            "o ficheiro.\nPara esta funcionalidade tem que usar o comando config <nomeFicheiro>\n"
            "Na segunda fase vai ser o desenrolar do jogo e vai ter que escolher os seus commandos para interagir com o jogo";
    
}

void UI::mensagemErroComando(){
    cout << endl << "Insira um valor valido." << endl;
}

void UI::mensagemSemMoedas(){
    cout << endl << "Nao tem moedas suficientes para efetuar a compra." << endl;
}

void UI::mensagemErroFicheiro(){
    cout << endl <<"Erro ao carregar ficheiro. Fechar programa." << endl;
}

void UI::mensagemAvisoNavio(){
    cout << endl <<"Não tem nenhum navio" << endl;
}

void UI::novoNavioConstruido(int navioID, char tipo, int posX, int posY, int quantSoldados, int quantAgua, int quantPeixe, int quantMercadorias){
    
    cout << endl << "Novo navio construido com ID:" << navioID 
    << ", Tipo:" << tipo
    << ", Posicao: (" << posX << "," << posY << ")" <<" Soldados: "<<quantSoldados<<" Agua: "<<quantAgua
    << " Peixes: "<<quantPeixe << " Mercadorias: "<< quantMercadorias <<endl;
    
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