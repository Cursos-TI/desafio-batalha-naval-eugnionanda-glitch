#include <stdio.h>

int main() {

        int tabuleiro[10][10];
        int navio1[3] = {1, 2, 3}; //horizontal
        int navio2[3] = {1, 2, 3}; //vertical
        int navio3[3] = {1, 2, 3}; //diagonal principal
        int navio4[3] = {1, 2, 3}; //diagonal secundária

        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                tabuleiro[i][j] = 0;
            }
            
        }   
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
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
            if (linhaH == linhaV + i && colunaH + i== colunaV){
                printf("Os navios se sobrepõe!\n");
            return 1;
            }
        }
        
        for (int i = 0; i < 3; i++){
            tabuleiro[linhaH][colunaH + i] = 3;
        }

        for (int i = 0; i < 3; i++){
            tabuleiro[linhaV + i][colunaV] = 3;
        }
        
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
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




        printf("=== TABULEIRO BATALHA NAVAL ===\n\n\n");

        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                printf("%d ", tabuleiro[i][j]);
            }
            
            printf("\n");
        }




    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0


        return 0;

        }