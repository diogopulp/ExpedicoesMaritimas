/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Navio.h
 * Author: diogosantos
 *
 * Created on November 22, 2018, 8:53 PM
 */

#ifndef NAVIO_H
#define NAVIO_H

class Jogo;

class Navio {
    
private:
    char tipo;
    int posicaoAtualX, posicaoAtualY, idNavio;
    static int identificador;
    bool aliado = true;
    int numeroDeSoldados;
    int litosDeAgua;
    double toneladasDePeixe, toneladasDeMercadoria, cargaTotal;
    
public:
    Navio(char t);
    Navio(const Navio& orig);
    virtual ~Navio();
    void setPosicaoAtualX(int x);
    void setPosicaoAtualY(int y);
    void setTipoNavio(char tipo);
    void setBarcoAmigo(bool a);
    int getPosicaoAtualX();
    int getPosicaoAtualY();
    int getIdentificadorNavio()const;
    char getTipoNavio()const;
    bool barcoAmigo()const;
    virtual void navegar(int posx, int posy);
    static Navio * fabrica(char tipo);
    virtual Navio * duplica()const = 0;
};

#endif /* NAVIO_H */

