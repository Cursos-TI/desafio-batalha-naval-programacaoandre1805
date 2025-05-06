#include <stdio.h>

#define TAM_TABULEIRO 10  // Tamanho fixo do tabuleiro
#define TAM_NAVIO 3       // Tamanho fixo dos navios

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n🗺️  Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime cada célula
        }
        printf("\n"); // Nova linha para cada linha do tabuleiro
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Define os navios com tamanho 3 usando vetores
    int navio_horizontal[TAM_NAVIO] = {3, 3, 3}; // navio horizontal
    int navio_vertical[TAM_NAVIO] = {3, 3, 3};   // navio vertical

    // Coordenadas iniciais dos navios (pré-definidas)
    int linhaH = 2, colunaH = 1; // navio horizontal começa na linha 2, coluna 1
    int linhaV = 5, colunaV = 4; // navio vertical começa na linha 5, coluna 4

    // Validação de limites do navio horizontal
    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Garante que não sobrepõe outro navio
            if (tabuleiro[linhaH][colunaH + i] == 0) {
                tabuleiro[linhaH][colunaH + i] = navio_horizontal[i];
            }
        }
    }

    // Validação de limites do navio vertical
    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Garante que não sobrepõe outro navio
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = navio_vertical[i];
            }
        }
    }

    // Exibe o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
