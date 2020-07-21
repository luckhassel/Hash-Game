#include <stdio.h>

char tabuleiro[3][3];
char first_player;
char second_player;
int choice, num_jogadas = 0;

void menu_inicial(){
    printf("Bem vindo ao jogo da velha!\n");
    printf("As colunas e as linhas vão de 0 a 2!\n\n");
    printf("Escolha se deseja 'O' ou 'X' digitando 1 ou 2, respectivamente:\n\n");
    scanf("%d", &choice);
    if (choice == 1){
        first_player = 'O';
        second_player = 'X';
        printf("OK! O jogador 1 jogará com 'O' e o jogador 2 jogará com 'X'\n\n");
    }
    else if (choice == 2){
        first_player = 'X';
        second_player = 'O';
        printf("OK! O jogador 1 jogará com 'X' e o jogador 2 jogará com 'O'\n\n");
    }
    else{
        printf("Operação Inválida! Voltando ao início do jogo.\n\n");
        menu_inicial();
    }
}

void inicializa_tabuleiro(){
    int i, j;
    for (i=0;i<3;i++){
        for (j=0; j<3; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprime_tabuleiro(){
    printf("%c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("----------\n");
    printf("%c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("----------\n");
    printf("%c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

int verifica_ganhador(){
    int i, j, first_player_points=0, second_player_points=0;
    for (i=0; i<=2; i++){
        for(j=0; j<=2; j++){
            if (tabuleiro[i][j] == first_player){
                first_player_points++;
            }
            else if(tabuleiro[i][j] == second_player){
                second_player_points++;
            }
            if (first_player_points == 3){
                printf("Jogador 1 ganhou!!\n\n");
                return 1;
            }
            else if (second_player_points == 3){
                printf("Jogador 2 ganhou!!\n\n");
                return 1;
            }
        }
        first_player_points=0;
        second_player_points=0;
    }


    for (j=0; j<=2; j++){
        for(i=0; i<=2; i++){
            if (tabuleiro[i][j] == first_player){
                first_player_points++;
            }
            else if(tabuleiro[i][j] == second_player){
                second_player_points++;
            }
            if (first_player_points == 3){
                printf("Jogador 1 ganhou!!\n\n");
                return 1;
             }
            else if (second_player_points == 3){
                printf("Jogador 2 ganhou!!\n\n");
                return 1;
             }
        }
        first_player_points=0;
        second_player_points=0;
    }


    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[2][2] == tabuleiro[0][0]){
        if (tabuleiro[0][0] == first_player){
            printf("Jogador 1 ganhou!!\n\n");
            return 1;
        }
        else{
            printf("Jogador 2 ganhou!!\n\n");
            return 1;
        }
    }

    if (tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0]){
        if (tabuleiro[2][0] == first_player){
            printf("Jogador 1 ganhou!!\n\n");
            return 1;
        }
        else{
            printf("Jogador 2 ganhou!!\n\n");
            return 1;
        }
    }
    return 0;
}

void jogar(){
    int linha, coluna, vencedor=0;
    while (vencedor == 0){
        if (num_jogadas == 0 || num_jogadas%2 == 0){
            printf("Digite a linha e coluna da sua jogada jogador 1: ");
            scanf("%d %d", &linha, &coluna);
            if ((tabuleiro[linha][coluna]) != ' '){
                printf("Posição inválida!\n\n");
                jogar();
            }
            tabuleiro[linha][coluna] = first_player;
            num_jogadas++;
        }
        else{
            printf("Digite a linha e coluna da sua jogada jogador 2: ");
            scanf("%d %d", &linha, &coluna);
            if ((tabuleiro[linha][coluna]) != ' '){
                printf("Posição inválida!\n\n");
                jogar();
            }
            tabuleiro[linha][coluna] = second_player;
            num_jogadas++;
        }
        imprime_tabuleiro();
        if (num_jogadas >= 5){
            vencedor = verifica_ganhador();
        }
        if (num_jogadas == 9 && vencedor == 0){
            printf("O jogo empatou!!\n\n");
            vencedor = 1;
        }
    }
}

int main(){
    menu_inicial();
    inicializa_tabuleiro();
    jogar();
    return 0;
}