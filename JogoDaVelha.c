#include <stdio.h>
#include <stdlib.h>

int main (void) {
int opcao;
int jogador = 0;
int vencedor = 0;
int escolha = 0;
int linha = 0;
int coluna = 0;
int j = 0;
int i=0;


start://Mensagem inicial
    printf("\n\n\n\n");
    printf("\t\tXXXXXXXX   XXXXX    XXXXXX    XXXXXX   \n");
    printf("\t\tXXXXXXXX  XX   XX  XX    XX  XX    XX  \n");
    printf("\t\t     XXX  XX   XX  XX        XX    XX  \n");
    printf("\t\t     XXX  XX   XX  XX  XXXX  XX    XX  \n");
    printf("\t\tXX   XXX  XX   XX  XX  XXXX  XX    XX  \n");
    printf("\t\tXXXXXXXX  XX   XX  XX    XX  XX    XX  \n");
    printf("\t\t XXXXXX    XXXXX    XXXXXX    XXXXXX   \n");
    printf("\n");
    printf("\t\t		XXXXX    XXXXX		\n");
    printf("\t\t		XXXXXX  XX   XX		\n");
    printf("\t\t		XX   XX XX   XX		\n");
    printf("\t\t		XX   XX XXXXXXX		\n");
    printf("\t\t		XX   XX XXXXXXX		\n");
    printf("\t\t		XXXXXX  XX   XX		\n");
    printf("\t\t		XXXXX   XX   XX		\n");
    printf("\n");
    printf("\t\tX      X  XXXXXXX  XXX      XX   XX   XXXXX   \n");
    printf("\t\tXX    XX  XXXXXXX  XXX      XX   XX  XX   XX  \n");
    printf("\t\tXX    XX  XX       XXX      XX   XX  XX   XX  \n");
    printf("\t\tXX    XX  XXXXXXX  XXX      XXXXXXX  XXXXXXX  \n");
    printf("\t\tXXX  XXX  XX       XXX      XXXXXXX  XXXXXXX  \n");
    printf("\t\t XXX XX   XXXXXXX  XXXXXXX  XX   XX  XX   XX  \n");
    printf("\t\t  XXXX    XXXXXXX  XXXXXXX  XX   XX  XX   XX  \n\n");                  


    printf ("\t*------------------------------------------------------*\n");
	printf ("\t|                    MENU DE OPCOES                    |\n");
	printf ("\t*------------------------------------------------------*\n");
	printf ("\t|  0 - SAIR DO JOGO                                    |\n");
	printf ("\t|  1 - JOGAR EM DOIS JOGADORES                         |\n");
	printf ("\t|  2 - JOGAR CONTRA O COMPUTADOR                       |\n");       //seleciona o que deseja fazer
	printf ("\t|  3 - VER INSTRUCOES DO JOGO E INFORMACOES            |\n");
	printf ("\t|  4 - VER OS PROGRAMADORES                            |\n");
	printf ("\t*------------------------------------------------------*\n");
	printf ("\tO QUE DESEJA FAZER ? ");
	scanf ("%d",&opcao);                                                           //armazena opção em opção

	if(opcao != 1 && opcao != 2 && opcao != 3
    && opcao != 4 && opcao != 0){                      //verifica se a opção existe


                goto invalido;                           //se opção não existir, encaminha para a mensagem de invalido
                                                                 
             }
             if(opcao ==1){
int escolha;
printf("\t\n\nDigite 1 se deseja ser o jogador 'X' ou 2 se deseja ser o jogador 'O':  ");
scanf("%d", &escolha);
if(escolha==1)//Verifica qual opcao de jogo, 'x' ou 'o'
printf("\n\n\tOk, voce e o jogador 'X'! o jogo ira comecar!\n\n\n");
if(escolha==2)
printf("\n\n\tOk, voce e o jogador 'O'! o jogo ira comecar!\n\n\n");

char matriz[3][3];
int i=0,j=0,k=0,m=0;
for(i=0;i<3;i++){//preenchimento das linhas com ' '
for(j=0;j<3;j++){//preenchimento das colunas com ' '
matriz[i][j]=' ';}}
do{
if(k%2==0){// A variavel vê de quem é a vez
/*Imprime o tabuleiro*/
printf("\n%c|%c|%c\n",matriz[0][0],matriz[0][1],matriz[0][2]);
printf("------\n");
printf("%c|%c|%c\n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("------\n");
printf("%c|%c|%c\n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("Em qual linha e a coluna vc deseja marcar, jogador 'X'?\n");
scanf("%d%d",&i,&j);//Lê a linha e coluna marcada
while((matriz[i-1][j-1]=='X') || (matriz[i-1][j-1]=='O')|| (i<1 || i>3) || (j<1 || j>3)){//Verifica se a posição existe ou se está marcada
printf("Por favor digite novamente a linha e a coluna qe vc deseja marcar.\n");
scanf("%d%d",&i,&j);//Lê a linha e coluna marcada
}
matriz[i-1][j-1]='X';//preenche com o 'X' a posição desejada
m++;//Contador para que, quando igual ou maior a 5, entra na verificação de ganho, abaixo
if (m>=5){//Realiza os testes de ganho
if((matriz[0][0]=='X' && matriz[0][1]=='X' && matriz[0][2]=='X')|| // Verifica se 'X' ganhou
(matriz[1][0]=='X' && matriz[1][1]=='X' && matriz[1][2]=='X')||
(matriz[2][0]=='X' && matriz[2][1]=='X' && matriz[2][2]=='X')||
(matriz[0][0]=='X' && matriz[1][0]=='X' && matriz[2][0]=='X')||
(matriz[0][1]=='X' && matriz[1][1]=='X' && matriz[2][1]=='X')||
(matriz[0][2]=='X' && matriz[1][2]=='X' && matriz[2][2]=='X')||
(matriz[0][0]=='X' && matriz[1][1]=='X' && matriz[2][2]=='X')||
(matriz[0][2]=='X' && matriz[1][1]=='X' && matriz[2][0]=='X')){
printf("\n%c|%c|%c\n",matriz[0][0],matriz[0][1],matriz[0][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("Parabens, o jogador 'X' vc venceu!!!\n\n\n");
break;
}
if(m==9){//Se houve 9 jogadas, sem um vencedor, houve, logicamente, um empate
printf("\n\nEMPATE\n\n");
goto start;}
}
}
else{/*Imprime a matriz*/
printf("\n%c|%c|%c\n",matriz[0][0],matriz[0][1],matriz[0][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("Em qual linha e a coluna vc deseja marcar, jogador 'O'?\n");
scanf("%d%d",&i,&j);
while((matriz[i-1][j-1]=='X') || (matriz[i-1][j-1]=='X')|| (i<1 || i>3) || (j<1 || j>3)){//Verifica se a posição existe ou se está marcada
printf("Por favor, digite novamente a LINHA e a COLUNA que voce deseja marcar.\n");
scanf("%d%d",&i,&j);//Lê a linha e coluna marcada
}
matriz[i-1][j-1]='O';//preenche com o 'O' a posição desejada
m++;//Contador para que, quando igual ou maior a 5, entra na verificação de ganho, abaixo
if (m>=5){//Realiza os testes de ganho
if((matriz[0][0]=='O' && matriz[0][1]=='O' && matriz[0][2]=='O')|| //  Verifica se 'O' ganhou
(matriz[1][0]=='O' && matriz[1][1]=='O' && matriz[1][2]=='O')||
(matriz[2][0]=='O' && matriz[2][1]=='O' && matriz[2][2]=='O')||
(matriz[0][0]=='O' && matriz[1][0]=='O' && matriz[2][0]=='O')||
(matriz[0][1]=='O' && matriz[1][1]=='O' && matriz[2][1]=='O')||
(matriz[0][2]=='O' && matriz[1][2]=='O' && matriz[2][2]=='O')||
(matriz[0][0]=='O' && matriz[1][1]=='O' && matriz[2][2]=='O')||
(matriz[0][2]=='O' && matriz[1][1]=='O' && matriz[2][0]=='O')){
printf("\n					%c|%c|%c\n",matriz[0][0],matriz[0][1],matriz[0][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("Parabens, o jogador 'O' vc venceu!!!\n\n\n");
break;
}
if(m==9){//Se o jogo chegou ao fim sem nenhum ganhador, haverá um empate
printf("\n\nEMPATE\n\n");
goto start;}
}
}
k++;//Contador para ver quem joga
}while(1);//mantem o jogo rodando
 getchar();
 printf ("\tPressione Enter para retornar ao menu.");//Ao final do jogo, a função verifica o desejo do usuário
    getchar();
	system("cls");                                                        //limpa a tela
    goto start;
         }
             if (opcao == 2){

getchar();
	system("cls");
char matriz[3][3];
int i=0,j=0,k=0,m=0;
for(i=0;i<3;i++){// preenche as linhas com ' '
for(j=0;j<3;j++){//preenche as colunas com ' '
matriz[i][j]=' ';}}
int escolha;
printf("\n\n\n\tJogador, digite 1 se deseja 'X' ou 2 se deseja 'O': \n\n\n");
scanf("%d", &escolha);//variavel escolha verifica o desejo do jogador, por 'x' ou 'o'

if(escolha==1){//escolha do 'x' ou 'o'

do{
if(k%2==0){//  variavel serve para ver de quem é a vez, com um contador abaixo.
printf("\t                                              \n");
printf("\t                                              \n");
printf("\t                    %c|%c|%c                  \n",matriz[0][0],matriz[0][1],matriz[0][2]);
printf("\t                    -----                     \n");
printf("\t                    %c|%c|%c                  \n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("\t                    -----                     \n");
printf("\t                    %c|%c|%c                  \n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("\t                                              \n");
printf("\t                                              \n");
printf("\t  Em qual linha e coluna vc deseja marcar.  \n");
scanf("%d%d",&i,&j);
while((matriz[i-1][j-1]=='X') || (matriz[i-1][j-1]=='O')|| (i<1 || i>3) || (j<1 || j>3)){/*Verifica se a posição ja foi marcada, ou se existe*/
printf("\t  Por favor digite novamente a linha e a coluna qe vc deseja marcar.\n");
scanf("%d%d",&i,&j);
}
matriz[i-1][j-1]='X';
m++;
if (m>=5){//A partir da quinta jogada, verifica se houve ganhador
if((matriz[0][0]=='X' && matriz[0][1]=='X' && matriz[0][2]=='X')|| //Vê se 'x' ganhou
(matriz[1][0]=='X' && matriz[1][1]=='X' && matriz[1][2]=='X')||
(matriz[2][0]=='X' && matriz[2][1]=='X' && matriz[2][2]=='X')||
(matriz[0][0]=='X' && matriz[1][0]=='X' && matriz[2][0]=='X')||
(matriz[0][1]=='X' && matriz[1][1]=='X' && matriz[2][1]=='X')||
(matriz[0][2]=='X' && matriz[1][2]=='X' && matriz[2][2]=='X')||
(matriz[0][0]=='X' && matriz[1][1]=='X' && matriz[2][2]=='X')||
(matriz[0][2]=='X' && matriz[1][1]=='X' && matriz[2][0]=='X')){
printf("\t                                              \n");
printf("\t					%c|%c|%c					\n",matriz[0][0],matriz[0][1],matriz[0][2]);
printf("\t					-----   					\n");
printf("\t					%c|%c|%c					\n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("\t					-----   					\n");
printf("\t					%c|%c|%c					\n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("Voce venceu!!!\n");
break;
}
if(m==9){//Se o jogo tiver 9 jogadas, logicamente, houve empate
printf("\n\nEMPATE\n\n");
goto start;}
}
}
else{//vez do computador
printf("\n%c|%c|%c\n",matriz[0][0],matriz[0][1],matriz[0][2]);//imprime matriz
printf("--------\n");
printf("%c|%c|%c\n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("Computador mexeu.\n");
//função que sorteia a jogada do computador
i = rand()%3;//sorteia uma posição i
j = rand()%3;//sorteia uma posição j
while((matriz[i][j]=='X') || (matriz[i][j]=='O')){//testa para ver se a posição ja está sendo usada
i = rand()%3;//sorteia posição para i
j = rand()%3;//sorteia posição para j
}
matriz[i][j]='O';//preenche a posição desejada com 'o'
m++;
if (m>=5){//Testa, a partir da quinta jogada, se o computador vencer
if((matriz[0][0]=='O' && matriz[0][1]=='O' && matriz[0][2]=='O')|| // Verifica se o 'o' ganhou
(matriz[1][0]=='O' && matriz[1][1]=='O' && matriz[1][2]=='O')||
(matriz[2][0]=='O' && matriz[2][1]=='O' && matriz[2][2]=='O')||
(matriz[0][0]=='O' && matriz[1][0]=='O' && matriz[2][0]=='O')||
(matriz[0][1]=='O' && matriz[1][1]=='O' && matriz[2][1]=='O')||
(matriz[0][2]=='O' && matriz[1][2]=='O' && matriz[2][2]=='O')||
(matriz[0][0]=='O' && matriz[1][1]=='O' && matriz[2][2]=='O')||
(matriz[0][2]=='O' && matriz[1][1]=='O' && matriz[2][0]=='O')){
printf("\n%c|%c|%c\n",matriz[0][0],matriz[0][1],matriz[0][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("O computador venceu!!!\n");
break;
}
if(m==9){//Se chegou até a jogada 9, logicamente, houve empate
printf("\n\nEMPATE\n\n");
goto start;}
}
}
k++;
}while(1);//mantem o jogo rodando
}


if(escolha==2){//variável escolha verifica se o usuário quis jogar com 'o' ou 'x'

do{
if(k%2==0){//  Variável que verifica de quem é a vez. Contador abaixo
printf("\t                                              \n");
printf("\t                                              \n");
printf("\t                    %c|%c|%c                  \n",matriz[0][0],matriz[0][1],matriz[0][2]);
printf("\t                    -----                     \n");
printf("\t                    %c|%c|%c                  \n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("\t                    -----                     \n");
printf("\t                    %c|%c|%c                  \n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("\t                                              \n");
printf("\t                                              \n");
printf("\t  Em qual linha e coluna vc deseja marcar.  \n");
scanf("%d%d",&i,&j);
while((matriz[i-1][j-1]=='O') || (matriz[i-1][j-1]=='X')|| (i<1 || i>3) || (j<1 || j>3)){/*Verifica se a posição ja está sendo usada ou é invalida*/
printf("\t  Por favor digite novamente a linha e a coluna qe vc deseja marcar.\n");
scanf("%d%d",&i,&j);
}
matriz[i-1][j-1]='O';
m++;//Contador de jogadas
if (m>=5){//Verifica, a partir da quinta jogada, se o jogador ganhou
if((matriz[0][0]=='O' && matriz[0][1]=='O' && matriz[0][2]=='O')|| //Verifica se o jogador 'x' ganhou
(matriz[1][0]=='O' && matriz[1][1]=='O' && matriz[1][2]=='O')||
(matriz[2][0]=='O' && matriz[2][1]=='O' && matriz[2][2]=='O')||
(matriz[0][0]=='O' && matriz[1][0]=='O' && matriz[2][0]=='O')||
(matriz[0][1]=='O' && matriz[1][1]=='O' && matriz[2][1]=='O')||
(matriz[0][2]=='O' && matriz[1][2]=='O' && matriz[2][2]=='O')||
(matriz[0][0]=='O' && matriz[1][1]=='O' && matriz[2][2]=='O')||
(matriz[0][2]=='O' && matriz[1][1]=='O' && matriz[2][0]=='O')){
printf("\t                                              \n");
printf("\t					%c|%c|%c					\n",matriz[0][0],matriz[0][1],matriz[0][2]);
printf("\t					-----    					\n");
printf("\t					%c|%c|%c					\n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("\t					-----    					\n");
printf("\t					%c|%c|%c					\n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("Voce venceu!!!\n");
break;
}
if(m==9){//Se chegou a nove jogadas, logicamente, houve empate
printf("\n\nEMPATE\n\n");
goto start;}
}
}
else{//vez do computador
printf("\n%c|%c|%c\n",matriz[0][0],matriz[0][1],matriz[0][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("Computador mexeu.\n");
//função que sorteia a posição
i = rand()%3;//sorteia uma posição i
j = rand()%3;//sorteia uma posição j
while((matriz[i][j]=='O') || (matriz[i][j]=='X')){//Verifica se a posição sorteada já está em uso
i = rand()%3;
j = rand()%3;
}
matriz[i][j]='X';//preenche a posição com 'x'
m++;
if (m>=5){//Verifica se o computador ganhou
if((matriz[0][0]=='X' && matriz[0][1]=='X' && matriz[0][2]=='X')|| // Verifica se o computador 'x' ganhou
(matriz[1][0]=='X' && matriz[1][1]=='X' && matriz[1][2]=='X')||
(matriz[2][0]=='X' && matriz[2][1]=='X' && matriz[2][2]=='X')||
(matriz[0][0]=='X' && matriz[1][0]=='X' && matriz[2][0]=='X')||
(matriz[0][1]=='X' && matriz[1][1]=='X' && matriz[2][1]=='X')||
(matriz[0][2]=='X' && matriz[1][2]=='X' && matriz[2][2]=='X')||
(matriz[0][0]=='X' && matriz[1][1]=='X' && matriz[2][2]=='X')||
(matriz[0][2]=='X' && matriz[1][1]=='X' && matriz[2][0]=='X')){
printf("\n%c|%c|%c\n",matriz[0][0],matriz[0][1],matriz[0][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[1][0],matriz[1][1],matriz[1][2]);
printf("--------\n");
printf("%c|%c|%c\n",matriz[2][0],matriz[2][1],matriz[2][2]);
printf("O computador venceu!!!\n");
break;
}
if(m==9){//Se o jogo chegou até a nona rodada, logicamente, houve empate
printf("\n\nEMPATE\n\n");
goto start;}
}
}
k++;
}while(1);//mantem o jogo rodando
}
getchar();
 printf ("\tEnter para retornar ao menu.");//Função que oferece a opção de retorno ao menu
    getchar();
	system("cls");                                                        //limpa a tela
    goto start;//Volta ao menu principal
         }


             if (opcao == 3){
             goto intrucoes;
             }
             if (opcao == 4){
             goto programadores;
             }

             if ( opcao == 0 ){
             return 0;
             }

	getchar();
	system("cls");

	switch (opcao)//Verifica qual a opção escolhida

	intrucoes:

    case 3 :
	{

    system("cls");                                                                 //limpa a tela
    printf ("\n\n\t5 - INSTRUCOES\n\n");//Imprime as instruções do jogo
    printf ("\tO tabuleiro possui uma matriz de tres linhas por tres colunas.\n");
	printf ("\tPara jogar, e necessario digitar uma linha e coluna. \n");
	printf("\tAlgum jogador ganha quando se completa uma linha, coluna\n");
	printf("\tou diagonal com os mesmos simbolos.\n\n\n");
	
	
	getchar();printf ("\tPressione Enter para retornar ao menu.");
    getchar();system("cls");                                                        //limpa a tela
    goto start;
    }

	switch (opcao)//Verifica qual a opção escolhida

	programadores:

	case 4 :

	{

    system("cls");                                                                  //limpa a tela
    printf ("\n\n\n\n\n\tPROGRAMADORES:\n\n");//Imprime os programadores
	printf ("\tAndre Munhos de Souza\n\n");
	printf ("\tGuilherme Luckfett de Oliveira Hasselmann \n\n");
	printf ("\tFabio Aurelio Dias\n\n");



	getchar();printf ("\tPressione Enter para retornar ao menu.");
    getchar();system("cls");                                                        //limpa a tela
    goto start;//Vai ao menu principal

	invalido:
		default : system("cls");//Se a opcao for invalida, entra nessa opcao
	
	printf ("\n\n\t\t\tOpcao invalida!\n\n");
		{
            getchar();printf ("\n\n\t\tPressione Enter para voltar ao inicio\n\n");

			getchar(); system ("cls");
			goto start;//Vai ao menu principal
	         }
	     }

printf ("\n\n");

	system ("PAUSE");//Interrompe a execução do programa
    return (0);

}