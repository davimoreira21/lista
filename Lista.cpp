// Bibliotecas necessárias
#include <cstdio>
#include <cstdlib>
#include "Lista.h"
#include <iostream>

TipoCelula *Frente, *Tras;
int Contador;

void Lista_Construtor() {
    Frente = Tras = NULL;
    Contador = 0;
}

void Lista_Destrutor() {
    TipoCelula *Temp;
    while (Frente != NULL) {
        Temp = Frente;
        Frente = Frente->Prox;
        Temp->Prox = NULL;
        free(Temp);
    }
    Tras = NULL;
    Contador = 0;
}

bool Lista_Vazia() {
    return Frente == NULL;
}

int Lista_Tamanho() {
    return Contador;
}

bool Lista_Inserir_Ordenado(int Elemento) {
    // Verificar se o elemento já existe na lista
    TipoCelula *Atual = Frente;
    while (Atual != NULL) {
        if (Atual->Item == Elemento) {
            printf("Elemento '%d' ja esta na lista!\n", Elemento);
            return false; // Elemento já existe
        }
        Atual = Atual->Prox;
    }

    // Criar novo nó
    TipoCelula *Novo = (TipoCelula *)malloc(sizeof(TipoCelula));
    if (Novo == NULL) {
        return false;  // Falta de memória
    }
    Novo->Item = Elemento;
    Novo->Prox = NULL;

    // Caso lista esteja vazia
    if (Lista_Vazia()) {
        Frente = Tras = Novo;
    } else {
        // Inserção ordenada
        TipoCelula *Anterior = NULL;
        Atual = Frente;
        while (Atual != NULL && Atual->Item < Elemento) {
            Anterior = Atual;
            Atual = Atual->Prox;
        }

        if (Anterior == NULL) {
            // Inserir no início
            Novo->Prox = Frente;
            Frente = Novo;
        } else if (Atual == NULL) {
            // Inserir no fim
            Tras->Prox = Novo;
            Tras = Novo;
        } else {
            // Inserção no meio
            Anterior->Prox = Novo;
            Novo->Prox = Atual;
        }
    }
    Contador++; // Incrementar o contador
    return true; // Retornar sucesso
}

bool Lista_Inserir_Inicio(int Elemento) {
    TipoCelula *Novo = (TipoCelula *)malloc(sizeof(TipoCelula));
    if (Novo == NULL) {
        return false;
    } else {
        Novo->Item = Elemento;
        Novo->Prox = Frente;

        if (Lista_Vazia()) {
            Tras = Novo;
        }

        Frente = Novo;
        Contador++;
        return true;
    }
}

bool Lista_Inserir_Fim(int Elemento) {
    TipoCelula *Novo = (TipoCelula *)malloc(sizeof(TipoCelula));
    if (Novo == NULL) {
        return false;
    } else {
        Novo->Item = Elemento;
        Novo->Prox = NULL;

        if (Lista_Vazia()) {
            Frente = Novo;
        } else {
            Tras->Prox = Novo;
        }

        Tras = Novo;
        Contador++;
        return true;
    }
}

bool Lista_Inserir(int Elemento, int Posicao) {
    if (Posicao < 0 || Posicao > Contador) return false; // Permitir inserção no final
    TipoCelula *Novo = (TipoCelula *)malloc(sizeof(TipoCelula));
    if (Novo == NULL) {
        return false;
    } else {
        TipoCelula *Temp = Frente;

        for (int i = 0; i < Posicao; i++) {
            Temp = Temp->Prox;
        }

        Novo->Item = Temp->Item;
        Temp->Item = Elemento;
        Novo->Prox = Temp->Prox;
        Temp->Prox = Novo;

        if (Tras == Temp) Tras = Novo;

        Contador++;
        return true;
    }
}

bool Lista_Remover_Inicio(int &Elemento) {
    if (!Lista_Vazia()) {
        TipoCelula *Temp = Frente;
        Elemento = Frente->Item;
        Frente = Frente->Prox;
        Temp->Prox = NULL;
        free(Temp);

        if (Frente == NULL) {
            Tras = NULL;
        }

        Contador--;
        return true;
    }
    return false;
}

bool Lista_Remover_Fim(int &Elemento) {
    if (!Lista_Vazia()) {
        TipoCelula *Temp = Frente;

        if (Frente == Tras) {
            Elemento = Tras->Item;
            Contador--;
            free(Tras);
            Frente = Tras = NULL;
            return true;
        }

        while (Temp->Prox != Tras) {
            Temp = Temp->Prox;
        }

        Elemento = Tras->Item;
        Tras = Temp;
        Temp->Prox = NULL;
        free(Tras->Prox); // Liberar o último nó
        Contador--;
        return true;
    }
    return false;
}

bool Lista_Remover(int &Elemento, int Posicao) {
    if (!Lista_Vazia()) {
        if (Posicao < 0 || Posicao >= Contador) return false;

        TipoCelula *Temp, *Temp2;

        if (Frente == Tras) {
            Elemento = Tras->Item;
            Contador--;
            free(Tras);
            Frente = Tras = NULL;
            return true;
        }

        Temp = Frente;
        for (int i = 0; i < Posicao; i++) {
            Temp2 = Temp;
            Temp = Temp->Prox;
        }

        if (Frente == Temp) {
            Frente = Frente->Prox;
        } else {
            Temp2->Prox = Temp->Prox;
        }

        if (Tras == Temp) {
            Tras = Temp2;
        }

        Elemento = Temp->Item;
        free(Temp);
        Contador--;
        return true;
    }
    return false;
}

bool Lista_Inicio(int &Elemento) {
    if (!Lista_Vazia()) {
        Elemento = Frente->Item;
        return true;
    }
    return false;
}

bool Lista_Fim(int &Elemento) {
    if (!Lista_Vazia()) {
        Elemento = Tras->Item;
        return true;
    }
    return false;
}

bool Lista_BuscarPeloElemento(int Elemento, int &Posicao) {
    TipoCelula *Temp = Frente;
    int i = 0;

    if (!Lista_Vazia()) {
        while (Temp != NULL && Temp->Item != Elemento) {
            i++;
            Temp = Temp->Prox;
        }

        if (Temp != NULL) {
            Posicao = i;
            return true;
        }
    }
    return false;
}

bool Lista_BuscarPelaPosicao(int &Elemento, int Posicao) {
    TipoCelula *Temp = Frente;
    int i = 0;

    if (!Lista_Vazia()) {
        if (Posicao < 0 || Posicao >= Contador) return false;

        while (i < Posicao) {
            i++;
            Temp = Temp->Prox;
        }

        Elemento = Temp->Item;
        return true;
    }
    return false;
}

