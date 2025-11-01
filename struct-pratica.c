// ================================================================================
// PRÁTICA: SISTEMA DE BIBLIOTECA - PARTE 1
//
// OBJETIVO DESTA PARTE:
// Implementar o cadastro e a listagem de livros usando uma array estatático.
// Foco em structs, entradsa/saída de daos e organização básica.
//
//
// ================================================================================

#include <stdio.h>
#include <stdlib.h> //
#include <string.h> // Para strcspn()

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define TAM_STRING 100

// --- Definição da Estrutura (Struct) ---
struct Livro {
    char nome [TAM_STRING];
    char autor [TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função Principal (main) ---
int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // --- Laço Principal do Menu ---
    do {

        // Exibe o menu de opções.
        printf("==================================\n");
        printf("    BIBLIOTECA - PARTE 1\n");
        printf("==================================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        // Lê a opção do usuário.
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o buffer '\n' após scanf.

        // --- Processa a opção escolhida ---
        switch (opcao) {
            case 1: // Cadastrar novo livro
                printf("----- Cadastro de Novo Livro -----\n\n");

                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = 0; // Remove '\n'

                    printf("Digite o autor do livro: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = 0; // Remove '\n'

                    printf("Digite a editora do livro: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = 0; // Remove '\n'

                    printf("Digite a edicao do livro: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada(); // Limpa o buffer '\n' após scanf.

                    totalLivros++;

                    printf("Livro cadastrado com sucesso!\n\n");
                } else {
                    printf("Biblioteca cheia! Não é possível cadastrar mais livros.\n\n");
                }
                break;

            case 2:
                // Listagem de livros
                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado ainda.\n\n");
                } else {
                    printf("Lista de Livros Cadastrados:\n");
                    for (int i = 0; i < totalLivros; i++) {
                        printf("Livro %d:\n", i + 1);
                        printf(" Nome: %s\n", biblioteca[i].nome);
                        printf(" Autor: %s\n", biblioteca[i].autor);
                        printf(" Editora: %s\n", biblioteca[i].editora);
                        printf(" Edicao: %d\n\n", biblioteca[i].edicao);
                    }
                     printf("==================================\n\n");
                }

                // A pausa é crucial para que o usuário possa ler a lista antes de voltar ao menu.
                printf("\nPressione Enter para continuar...");
                getchar(); // Aguarda o usuário pressionar Enter.
                break;

            case 0: // Sair
                printf("\nSaindo do sistema...\n");
                break;

            default: // Opção inválida
                printf("\nOpcao invalida! Tente novamente.\n");
                printf("\nPressione Enter para continuar...");
                getchar(); // Aguarda o usuário pressionar Enter.
                break;
        }

    } while (opcao != 0);
   
    return 0;
}
