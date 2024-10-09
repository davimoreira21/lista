#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


typedef int TipoDado; //Define o tipo de dado que ser� armazenado na Lista


struct TipoCelula {
    int Item;
    TipoCelula *Prox;
};

void Lista_Construtor();
void Lista_Destrutor();
bool Lista_Inserir_Ordenado(int Elemento);
bool Lista_Remover_Inicio(int &Elemento);
bool Lista_Remover_Fim(int &Elemento);
bool Lista_Remover(int &Elemento, int Posicao);
bool Lista_Inicio(int &Elemento);
bool Lista_Fim(int &Elemento);
bool Lista_BuscarPeloElemento(int Elemento, int &Posicao);
int Lista_Tamanho();
bool Lista_BuscarPelaPosicao(int &Elemento, int Posicao);

#endif
