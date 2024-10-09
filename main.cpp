// Bibliotecas necessárias
#include <cstdio>
#include <cstdlib>
#include "Lista.h"
#include <iostream>

using namespace std;

// Função principal para demonstrar o uso da Lista
int main() {
    int x; // Variável utilizada para receber o valor digitado do usuário e colocar na Lista
    int opcao; // variável utilizada no Menu para testar a Lista
    int posicao; // variável utilizada para retornar a posição onde o elemento foi encontrado

    Lista_Construtor(); // para iniciar a Lista

    do { // menu com opções para testar a implementação da Lista
        system("cls");

        printf("Programa para uso da Lista Singularmente Encadeada\n\n");
        printf("Escolha uma das opcoes abaixo.");
        printf("\n\n\nMenu: \n");
        printf("\n1 - Inserir ordenado");
        printf("\n2 - Remover no inicio");
        printf("\n3 - Remover no fim");
        printf("\n4 - Remover dado em uma posicao");
        printf("\n5 - Elemento no inicio");
        printf("\n6 - Elemento no fim");
        printf("\n7 - Procurar elemento");
        printf("\n8 - Numero de elementos na lista");
        printf("\n9 - Exibir elemento em uma posicao");
        printf("\n10 - Exibir elementos da Lista");
        printf("\n11 - Remover e exibir todos os elementos");
        printf("\n12 - Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                printf("Escreva a palavra: ");
                scanf("%d", &x); // Ajuste aqui para aceitar int
                if (Lista_Inserir_Ordenado(x))
                    printf("Palavra inserido com sucesso.\n");
                else
                    printf("Erro ao inserir o palavra.\n");
                system("pause");
                break;

            case 2:
                if (Lista_Remover_Inicio(x))
                    printf("\n\nDado %d removido\n\n", x);
                else
                    printf("Erro. Lista vazia.\n\n");
                system("pause");
                break;

            case 3:
                if (Lista_Remover_Fim(x))
                    printf("\n\nDado %d removido\n\n", x);
                else
                    printf("Erro. Lista vazia.\n\n");
                system("pause");
                break;

            case 4:
                printf("Digite a posicao para remover o dado: ");
                scanf("%d", &posicao);
                if (Lista_Remover(x, posicao))
                    printf("\n\nElemento %d removido\n\n", x);
                else
                    printf("Erro. Posicao não encontrada.\n\n");
                system("pause");
                break;

            case 5:
                printf("\nElemento no inicio da lista: ");
                if (Lista_Inicio(x))
                    printf("%d\n\n", x);
                else
                    printf("\n\nLista vazia\n\n");
                system("pause");
                break;

            case 6:
                printf("\nElemento no fim da lista: ");
                if (Lista_Fim(x))
                    printf("%d\n\n", x);
                else
                    printf("\n\nLista vazia\n\n");
                system("pause");
                break;

            case 7:
                printf("\nDigite o elemento para pesquisa: ");
                scanf("%d", &x);
                if (Lista_BuscarPeloElemento(x, posicao))
                    printf("Elemento encontrado na posicao %d.\n\n", posicao);
                else
                    printf("Erro. Elemento não encontrado.\n\n");
                system("pause");
                break;

            case 8:
                printf("\n\nNumero de elementos na lista: %d\n\n", Lista_Tamanho()); // exibe o número de elementos da lista
                system("pause");
                break;

            case 9:
                printf("\n\nEntre com a posicao desejada:\n\n");
                scanf("%d", &posicao);
                if (Lista_BuscarPelaPosicao(x, posicao)) {
                    printf("\nValor na posicao %d: %d", posicao, x);
                } else {
                    printf("Lista vazia ou posicao invalida");
                }
                printf("\n\n");
                system("pause");
                break;

            case 10:
                printf("\n\nElementos na Lista:\n\n");
                posicao = 0;
                while (Lista_BuscarPelaPosicao(x, posicao)) {
                    printf("\nValor na posicao %d: %d", posicao, x);
                    posicao++;
                }
                printf("\n\n");
                system("pause");
                break;

            case 11:
                printf("\nTodos os elementos: \n\n");
                while (Lista_Remover_Inicio(x)) {
                    printf("\nElemento: %d", x);
                }
                printf("\n\n");
                system("pause");
                break;

            case 12:
                Lista_Destrutor();
                break;

            default:
                printf("\n\nOpcao invalida\n\n");
                system("pause");
        }
    } while (opcao != 12);

    return 0;
}
