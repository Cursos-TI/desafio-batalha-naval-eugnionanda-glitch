#include <stdio.h>
#include <stdlib.h> // para abs

#define TAM 10
#define HAB 5   // tamanho das matrizes de habilidade (5x5)

void criarCone(int m[HAB][HAB]) {
    int centro = HAB / 2;
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i <= centro && j >= centro - i && j <= centro + i)
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

void criarCruz(int m[HAB][HAB]) {
    int centro = HAB / 2;
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == centro || j == centro)
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

void criarOctaedro(int m[HAB][HAB]) {
    int centro = HAB / 2;
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

// sobrepõe a habilidade no tabuleiro, marcando com 5 as áreas afetadas
void aplicarHabilidade(int tabuleiro[TAM][TAM], int hab[HAB][HAB], int origemLinha, int origemColuna) {
    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (hab[i][j] == 1) {
                int linhaTab = origemLinha + (i - centro);
                int colunaTab = origemColuna + (j - centro);

                // garante que está dentro do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                    // não sobrescreve navio (3), só marca água
                    if (tabuleiro[linhaTab][colunaTab] == 0) {
                        tabuleiro[linhaTab][colunaTab] = 5;
                    }
                }
            }
        }
    }
}

int main() {

    int tabuleiro[TAM][TAM];
    int navio1[3] = {1, 2, 3}; //horizontal
    int navio2[3] = {1, 2, 3}; //vertical
    int navio3[3] = {1, 2, 3}; //diagonal principal
    int navio4[3] = {1, 2, 3}; //diagonal secundária

    // inicializa tabuleiro com água (0)
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona dois navios: um horizontal e um vertical
    int linhaH = 3; 
    int colunaH = 0;        

    int linhaV = 5; 
    int colunaV = 7;

    if  (linhaH + 3 > 10){
        printf("Navio horizontal ultrapassa limites do tabuleiro!\n");
        return 1;
    }

    if (linhaV + navio2[0] > 10){
        printf("Navio vertical ultrapassa limites do tabuleiro!\n");
    }

    for (int i = 0; i < 3; i++){
        if (linhaH == linhaV + i && colunaH + i == colunaV){
            printf("Os navios se sobrepõem!\n");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++){
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    for (int i = 0; i < 3; i++){
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Posiciona dois navios nas diagonais
    int linhaDP = 0; 
    int colunaDP = 0;        

    int linhaDS = 9; 
    int colunaDS = 5;
        
    for (int i = 0; i < 3; i++){
        tabuleiro[linhaDP + i][colunaDP + i] = 3;
    }

    for (int i = 0; i < 3; i++){
        tabuleiro[linhaDS - i][colunaDS - i] = 3;
    }

    // ====== MATRIZES DE HABILIDADE ======
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Define pontos de origem das habilidades no tabuleiro
    int origemConeLinha = 2, origemConeColuna = 2;
    int origemCruzLinha = 6, origemCruzColuna = 3;
    int origemOctLinha  = 4, origemOctColuna  = 8;

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, octaedro, origemOctLinha, origemOctColuna);

    // Exibe tabuleiro final
    printf("=== TABULEIRO BATALHA NAVAL COM HABILIDADES ===\n\n");
    printf("Legenda: 0 = água | 3 = navio | 5 = área de habilidade\n\n");

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
