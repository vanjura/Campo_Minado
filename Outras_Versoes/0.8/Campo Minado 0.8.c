//Trabalho interdiciplinar de Linguagem De Programa��o e Algoritmos
//Nomes dos envolvidos:
//    Lucas Vanjura
//    Rafael Penczkoski
//    Elieser
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.c>
#define vazio ' '
#define bomba '*'
#define pixel 219
#define corDefault 8
#define corVazio 10
#define cor1 9
#define cor2 10
#define cor3 11
#define cor4 5
#define cor5 13
#define cor6 14
#define cor7 15
#define cor8 8
#define corBomba 12
FILE *arq;

struct SalvarRank{
    char nick[3];
    int pontos,dif;
}sRank[11];

struct RecuperarRank{
    char nick[3];
    int pontos,dif;
}rRank[11];

int Matriz1 [20][21], Linha=4, pLinha, Coluna = 4, pColuna, Bombas = -1, Controle = 1, Score = 0, cheat = 0, dificuldade = 0;
char Matriz2 [20][20], Matriz3 [20][20], usuario[5];

void colocarCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, TRUE};//Struct do windows para modificar configura��es do cursor.TRUE ativa o cursor e FALSE desativa;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void removerCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void inicio(){
    int i; //Variavel para o comando getch() funcionar.
    system("cls"); //Limpa a tela para n�o haver erros na localiza��o da matriz.
    int z = pixel, x, y; //Declara��o de variaveis para criar e mostrar a matriz.
    char game[15][62]=
    {
        0,0,0,0,z,z,z,z,z,z,0,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,z,z,z,z,0,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,
        0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,0,0,z,z,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,
        0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,
        0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,z,z,z,z,z,z,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,z,z,z,z,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,
        0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,
        0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,
        0,0,0,0,z,z,z,z,z,z,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,0,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,0,z,z,z,z,z,z,0,0,0,0,z,z,z,z,z,z,z,z,0,0,0,0,0,0,z,z,z,z,z,z,0,0,
        z,z,z,z,0,0,z,z,z,z,0,0,z,z,0,0,z,z,z,z,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,
        z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,
        z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,z,z,z,z,0,0,z,z,z,z,z,z,z,z,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,
        z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,
        z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,
        z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,z,z,z,z,0,0,0,0,0,0,z,z,z,z,z,z,0,0,
    }; // Matriz com "CAMPO MINADO" escrito.
    gotoxy(1, 10);//gotoxy para n�o encher de \n no c�digo.
    for(x = 0; x < 15; x++){
        printf("\t\t\t\t\t\t");
        for(y = 0; y < 62; y++){
            printf("%c", game[x][y]);
        }
        printf("\n");
    }//comando de for para motrar a matriz.
    printf("\n\n\n\t\t\t\t\t\t\t    Pressione qualquer tecla para iniciar.");
    i = getch();//reconhece qualquer tecla e pula para a proxima tela
}

void pulaLinhaBonitinho(linhasAntes)//pequeno procedimento para pular linhas antes de criar um menu (somente quest�o gr�fica, n�o muda o funcionamento do jogo);
{
    int i = 0;
    do{
        printf(" \n");
        i++;
    }while(i <= linhasAntes);
}

void tabulacaoBonitinha(tabulacao, ajuste)//Mesmo intuito do procedimento anterior s� que com tabula��o;
{
    int i = 0;
    do{
        i++;
        printf("\t");
    }while(i < tabulacao);
    i = 0;
    while(i < ajuste){
        i++;
        printf(" ");
    }
}

void menuBonitinho(xColunas, yLinhas, cabecalho, linhasAntes, tabulacao, ajuste)//procedmento para criar uma �rea para menus, as op��es dos menus s�o incluidas atrav�s de gotoxy()
{//tamanho(Colunas, Linhas, Cabe�alho, Linhas_Antes_De_Imprimir, Tabula��o, Ajuste);
    int m, n, i = 0;
    pulaLinhaBonitinho(linhasAntes);//chama um procedimento que pular uma quantidade pr�determinada de linhas;
    tabulacaoBonitinha(tabulacao, ajuste);//chama um procedimento capaz de organizar a tabula��o com controle de linhas;
    printf("%c", 201);//inprime o canto;
    for(m = 0; m < xColunas; m++)//faz a linha superior;
    {
        printf("%c", 205);
    }
    printf("%c", 187);//imprime o canto superior direito;
    if(cabecalho != 0){//caso precise esse codigo pode fazer um cabe�alho para um nome de menu por exemplo;
        do{
            printf("\n");
            tabulacaoBonitinha(tabulacao, ajuste);// usa a mesma tabula��o para que o menu fique correto;
            printf("%c", 186);//linha vertical
            for(m = 0; m < xColunas; m++){//parte nula para escrita do cabe�alho;
                printf(" ");
            }
            printf("%c", 186);
            i++;
        }while(cabecalho > i);//pode-se escolher o numero de linhas que o cabe�alho dever� ter;
        printf("\n");
        tabulacaoBonitinha(tabulacao, ajuste);
        printf("%c", 204);
        for(m = 0; m < xColunas; m++){
            printf("%c", 205);
        }
        printf("%c", 185);
    }
    i = 0;
    do{
        printf("\n");
        tabulacaoBonitinha(tabulacao, ajuste);
        printf("%c", 186);
        for(m = 0; m < xColunas; m++){
            printf(" ");
        }
        printf("%c", 186);
        i++;
    }while(yLinhas > i);
    printf("\n");
    tabulacaoBonitinha(tabulacao, ajuste);
    printf("%c", 200);
    for(m = 0; m < xColunas; m++){
        printf("%c", 205);
    }
    printf("%c", 188);
}

void tutorialPagina2()
{
    int x,i;
    gotoxy(1,14);
    for(x=0;x<15;x++)
    {
        tabulacaoBonitinha(6,0);
        printf("%c                                                              \n",186);
    }
    gotoxy(49,14);
    printf("%c Caso abra um quadrado sem numeros e sem bomba os quadrados\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c iguais ao redor tambem serao abertos automaticamente.\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c O jogo eh considerado ganho quando nao houver mais quadrados\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c seguros para abrir.\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c Caso abra um quadrado com bomba GAME OVER.\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c Cada dificuldade atribui um numero diferente por quadrados\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c seguros abertos, quanto mais dificil e maior o tabuleiro mais\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c pontuacao.\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c Mesmo que perca o jogo ainda podera salvar sua pontuacao.\n\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c                     Tenha um bom jogo!\n\n\n\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c Pressione ENTER para voltar ao menu principal.\n",186);
    do{
        i = getch();
    }while(i!=13);
}

void tutorialPagina1()
{ //75
    int i;
    gotoxy(50,14);
    printf(" Utilize as SETAS para mover o %c pelo tabuleiro.\n",158);
    tabulacaoBonitinha(6,0);
    printf("%c Quando o %c estiver em cima do quadrado que deseja selecionar,\n",186,158);
    tabulacaoBonitinha(6,0);
    printf("%c precione a tecla ENTER.\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c Os numeros que aparecerem representam quantas bombas existem\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c nos quadrados ao redor.\n\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c                         %c%c%c%c%c%c%c%c%c%c%c\n",186,201,205,205,205,205,205,205,205,205,205,187);
    tabulacaoBonitinha(6,0);
    printf("%c                         %c 1 1 1   %c\n",186,186,186);
    tabulacaoBonitinha(6,0);
    printf("%c                         %c 1 * 1   %c\n",186,186,186);
    tabulacaoBonitinha(6,0);
    printf("%c                         %c 1 2 2 1 %c\n",186,186,186);
    tabulacaoBonitinha(6,0);
    printf("%c                         %c   1 * 1 %c\n",186,186,186);
    tabulacaoBonitinha(6,0);
    printf("%c                         %c%c%c%c%c%c%c%c%c%c%c\n\n",186,200,205,205,205,205,205,205,205,205,205,188);
    tabulacaoBonitinha(6,0);
    printf("%c Pressione ENTER para ir a proxima pagina ou ESC para voltar\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c ao menu.\n",186);
    do{
        i = getch();
        if(i==13)
        {
            tutorialPagina2();
        }
    }while(i != 13 && i != 27);
}

void tutorial()
{
    system("cls");
    menuBonitinho(62, 15, 1, 9, 6, 0);
    gotoxy(76,12);
    printf("TUTORIAL");
    tutorialPagina1();
}

void MostrarRank()
{
    system("cls");
    int x;
    menuBonitinho(62, 15, 1, 9, 6, 0);
    gotoxy(51, 12);
    tabulacaoBonitinha(3, 4);
    printf("RANKING\n");
    gotoxy(51, 14);
    printf(" \tPosicao\t  Nome\tPontos\tDificuldade\n\n");
    for(x=0;x<10;x++)
    {
        tabulacaoBonitinha(6,0);
        printf("%c\t  %d%c\t  %s\t%d\t",186,x+1,167,sRank[x].nick,sRank[x].pontos);
        switch(sRank[x].dif)
        {
            case 1 : printf("Facil\n");break;
            case 2 : printf("Medio\n");break;
            case 3 : printf("Dificil\n");break;
            case 5 : printf("Infernal\n");break;
            case 666 : printf("666 FROM HELL\n");break;
            default : printf("\n");
        }
    }
    getch();
}

void RegravarRank()
{
    int x;
    arq=fopen("Ranking.txt","w");
    for(x=0;x<10;x++){
        fprintf(arq,"%s %d %d\n",sRank[x].nick,sRank[x].pontos,sRank[x].dif);
    }
    fclose(arq);
}

void OrganizaRank()
{
    int x, y, g[10],t,vPontos[10];
    for(x = 0;x < 10; x++){
        g[x] = -10;
        sRank[x].pontos = 0;
    }
    for(x = 0;x < 11; x++)
    {
        t = x - 1;
        for(y = 0; y < 11; y++)
        {
            if(g[0] != y && g[1] != y && g[2] != y && g[3] != y && g[4] != y && g[5] != y && g[6] != y && g[7] != y && g[8] != y && g[9] != y)
            {
                if(rRank[y].pontos > sRank[x].pontos)
                {
                    sRank[x].pontos = rRank[y].pontos;
                    sRank[x].dif = rRank[y].dif;
                    strcpy(sRank[x].nick, rRank[y].nick);
                    g[x]=y;
                }
            }
        }
    }
    RegravarRank();
}

void AtribuirRank()
{
    int x;
    arq = fopen("Ranking.txt","r");
    printf("rRank");
    for(x=0;x<10;x++){
        fscanf(arq, "%s", &rRank[x].nick);
        fscanf(arq, "%d", &rRank[x].pontos);
        fscanf(arq, "%d", &rRank[x].dif);
    }
    fclose(arq);
}

int menuPrincipal()
{
    removerCursor();//remove o cursor por quest�o gr�fica;
    int Op, x, y, z = 16, c;//vari�veis de controle indispens�veis para o funcionamento do menu
    do{
        system("cls");
        menuBonitinho(62, 15, 1, 9, 6, 0);
        gotoxy(31, 12);//gotoxy ser� usado varias vezes por quest�o grafica e funcional;
        tabulacaoBonitinha(6, 1);
        printf("MENU PRINCIPAL");
        gotoxy(60, 16);
        printf("Jogar");
        gotoxy(60, 17);
        printf("Tutorial");
        gotoxy(60, 18);
        printf("Ranking");
        gotoxy(60, 19);
        printf("Sair");
        do{ //codigo para o funcionamento das teclas up e down para controle do menu;
            gotoxy(60, z);
            textbackground(15);
            textcolor(0);
            switch(z){
                case 16 : printf("JOGAR"); break;
                case 17 : printf("TUTORIAL"); break;
                case 18 : printf("RANKING"); break;
                case 19 : printf("SAIR"); break;
            }
            textbackground(0);
            textcolor(15);
            c = getch();
            gotoxy(60,z);
            switch(z){
            case 16 : printf ("Jogar"); break;//imprime novamente a escrita antiga dando o efeito de DesSele��o;
                case 17 : printf ("Tutorial"); break;
                case 18 : printf ("Ranking"); break;
                case 19 : printf ("Sair"); break;
            }
            switch(c){
                case 80 ://caso aperte a seta para baixo;
                    z++;
                    if(z == 20){
                        z = 16;
                    } break;
                case 72 ://caso aperte a seta para cima
                    z--;
                    if(z == 15){
                        z = 19;
                    } break;
            }
        }while(c != 13);//quando a tecla enter for precionada, a op��o � selecionada;
        switch(z)
        {
            case 16 : Op = 0; break;
            case 17 :
                Op = 1;
                tutorial(); break;
            case 18 :
                Op = 1;
                AtribuirRank();
                OrganizaRank();
                MostrarRank(); break;
            case 19 :
                Op = 2; break;
        }
    }while(Op == 1);
    return Op;//retorna a op��o escolhida para um switch case;
}
void configuracoesDoJogo()
{
    textcolor(15);
    int R = 1, z = 17, c, tecla; //variaveis para a configura��o do jogo;
    char dif[10];
    do{
        system("cls");
        menuBonitinho(62, 15, 1, 9, 6, 0);//tamanho(Colunas, Linhas, Cabe�alho, Linhas_Antes_De_Imprimir, Tabula��o, Ajuste);
        gotoxy(1, 12);
        tabulacaoBonitinha(8, 3);
        printf("CONFIGURACOES DO JOGO");
        pulaLinhaBonitinho(15);
        tabulacaoBonitinha(6, 0);
        printf("%c Use as setas do teclado para selecionar a opcao desejada.",186);
        gotoxy(51, 14);
        printf("Quantidade de linhas: ");
        do{ // usa uma configura��o parecida com a de sele��o de menus, por�m o cursor fica parado em s� um lugar;
            printf("%d ", Linha);
            gotoxy(73, 14);
            tecla = getch();
            switch(tecla){
                case 80 :
                    Linha--;
                    if(Linha <= 3){
                        Linha++;
                    } break;
                case 72:
                    Linha++;
                    if(Linha >= 21){
                        Linha--;
                    } break;
            }
        }while(tecla != 13);
        gotoxy(51,14);
        printf("Linhas: %d              ",Linha); //varios espa�os para cobrir o antigo texto imprimido nesa linha;
        gotoxy(51,15);
        printf("Quantidade de colunas: ");
        do{ //configura��o igual a de escolher linhas;
            printf("%d ", Coluna);
            gotoxy(74, 15);
            tecla = getch();
            switch(tecla){
                case 80 :
                    Coluna--;
                    if(Coluna <= 3){
                        Coluna++;
                    } break;
                case 72:
                    Coluna++;
                    if(Coluna >= 21){
                        Coluna--;
                    } break;
            }
        }while(tecla != 13);
        do{
            gotoxy(51, 15);
            printf("Colunas: %d              ", Coluna); //imprime a coluna para que o usu�rio possa conferir o se escolheu corretamente;
            gotoxy(51, 16);
            printf("Escolha a dificuldade:");
            gotoxy(51, 17);
            printf("Facil");
            gotoxy(51, 18);
            printf("Medio");
            gotoxy(51, 19);
            printf("Dificil");
            gotoxy(51, 20);
            printf("Infernal");
            do{
                gotoxy(51, z);
                textbackground(15);
                textcolor(0);
                switch(z){ //cofigura��o igual a de todos os menus com escolha;
                    case 17 : printf("FACIL"); break;
                    case 18 : printf("MEDIO"); break;
                    case 19 : printf("DIFICIL"); break;
                    case 20 : printf("INFERNAL"); break;
                }
                textbackground(0);
                textcolor(15);
                c = getch();
                gotoxy(51, z);
                switch(z){
                    case 17 : printf("Facil"); break;
                    case 18 : printf("Medio"); break;
                    case 19 : printf("Dificil"); break;
                    case 20 : printf("Infernal"); break;
                    case 21 : printf("                "); break;
                    case 16 :
                        gotoxy(51,21);
                        printf("                "); break;
                }
                switch(c){
                    case 80 :
                        z++;
                        if(z == 21){
                            z = 17;
                        }
                        if(z == 22){
                            z = 20;
                        } break;
                    case 72 :
                        z--;
                        if(z == 16){
                            z = 20;
                        }
                        if(z == 15){
                            z = 17;
                        } break;
                    case 59 :
                        if(z == 20){
                            z = 21;
                            gotoxy(51, 21);
                            textbackground(RED);
                            printf("     666     ");
                            textcolor(15);
                        }else if(z == 17){
                            z = 16;
                            gotoxy(51, 21);
                            textbackground(GREEN);
                            printf(" BEBE CHORAO ");
                            textcolor(15);
                        } break;
                }
            }while(c != 13);
            switch(z){
                case 17 :
                    dificuldade = 1;
                    Bombas = (((float)Linha * (float)Coluna) / 100.0) * 10;
                    strcpy(dif, "Facil      ");//comando para atribuir uma palavra completa a uma string;
                    break;
                case 18 :
                    dificuldade = 2;
                    Bombas = (((float)Linha * (float)Coluna) / 100.0) * 15;
                    strcpy(dif, "Medio      ");
                    break;
                case 19 :
                    dificuldade = 3;
                    Bombas = (((float)Linha * (float)Coluna) / 100.0) * 20;
                strcpy(dif, "Dificil    ");break;
                case 20 :
                    dificuldade = 5;
                    Bombas = (((float)Linha * (float)Coluna) / 100.0) * 40;
                    strcpy(dif, "Infernal   ");
                    break;
                case 21 : //op��o escondida para testes que resolvemos deixar;
                    dificuldade = 666;
                    Linha = 20;
                    Coluna = 20;
                    Bombas = 399;
                    cheat = 1;
                    strcpy(dif, "666 FROM HELL");
                    break;
                case 16 : //op��o escondida para testes que resolvemos deixar;
                    Linha = 20;
                    Coluna = 20;
                    Bombas = 1;
                    cheat = 2;
                    strcpy(dif, "Bebe Chorao");
                    break;
            }
        }while(Bombas < 0);
        gotoxy(51, 16);
        printf("Dificuldade: %s", dif);
        gotoxy(51, 17);
        printf("Voce aceita jogar com esse valores?");
        gotoxy(51, 18);
        printf("Sim      ");
        gotoxy(51, 19);
        printf("Nao      ");
        gotoxy(51, 20);
        printf("         ");
        gotoxy(51, 21);
        printf("                 ");
        z = 18;
        do{
            gotoxy(51, z);
            textbackground(15);
            textcolor(0);
            switch(z){
                case 18 :
                    printf("SIM");
                    break;
                case 19 :
                    printf("NAO");
                    break;
            }
            textbackground(0);
            textcolor(15);
            c = getch();
            gotoxy(51, z);
            switch(z){
                case 18 :
                    printf("Sim");
                    break;
                case 19 :
                    printf("Nao");
                    break;
            }
            switch(c){
                case 80 :
                    z++;
                    if(z == 20){
                        z = 18;
                    }
                    break;
                case 72 :
                    z--;
                    if(z == 17){
                        z = 19;
                    }
                    break;
            }
        }while(c != 13);
        switch(z)
        {
            case 18:
                R = 0;
                break;
            case 19:
                R = 1;
                break;
        }
    }while(R == 1);//controle para voltar ao inicio da escolha caso o usuario n�o aceite jogar com os valores escolhidos;
}
void zerarMatrizes() //zera todas as matrizes de acordo com o tipo de cada uma;
{
    int x, y;
    for(x = 0; x < Linha; x++){
        for(y = 0; y < Coluna; y++){
            Matriz1[x][y] = 0;
            Matriz2[x][y] = 'x';
            Matriz3[x][y] = 254;
        }
    }
}
void mostrarMatriz3() //fun��o para mostrar a matriz em tela com borda e tabula��o corretas
{
    int x, y, i = 0;
    printf("\n");
    tabulacaoBonitinha(1, 0);
    printf("%c", 201);
    for(x = 0; x < Coluna * 2 + 1; x++){
        printf("%c", 205);
    }
    printf("%c\n", 187);
    for(x = 0; x < Linha; x++){
        tabulacaoBonitinha(1, 0);
        printf("%c ", 186);
        for(y = 0; y < Coluna; y++){
            textcolor(8);
            switch(Matriz3[x][y]){ //controla as cores de cada numero mostrado em tela (cores pr�definidas)
                case vazio :
                    textcolor(corVazio);
                    break;
                case '1' :
                    textcolor(cor1);
                    break;
                case '2' :
                    textcolor(cor2);
                    break;
                case '3' :
                    textcolor(cor3);
                    break;
                case '4' :
                    textcolor(cor4);
                    break;
                case '5' :
                    textcolor(cor5);
                    break;
                case '6' :
                    textcolor(cor6);
                    break;
                case '7' :
                    textcolor(cor7);
                    break;
                case '8' :
                    textcolor(cor8);
                    break;
                case bomba :
                    textcolor(corBomba);
                    break;
            }
            printf("%c ", Matriz3[x][y]); //ap�s mudar a cor, imprime em tela;
            textcolor(15);
        }
        printf("%c", 186);
        printf("\n");
    }
    tabulacaoBonitinha(1, 0);
    printf("%c", 200);
    for(x = 0; x < Coluna * 2 + 1; x++){
        printf("%c", 205);
    }
    printf("%c\n", 188);
    printf("\t Utilize as SETAS para se mover pelo tabuleiro.\n");
    printf("\t Pressione ENTER para selecionar o quadrado desejado.");
    gotoxy(9, 1);
    printf("Score: %d", Score);
}
int testeBombas() //testa quantas bombas existem no tabuleiro, retormando esse valor para um teste;
{
    int x, y, c = 0;
    for(x = 0; x < Linha; x++){ //for para verificar toda a matriz;
        for(y = 0; y < Coluna; y++){
            if(Matriz1[x][y] == 9){ //se encontrar um 9 incrementa a variavel c para um teste posterior;
                c++;
            }
        }
    }
    return c; //retorna o valor de c para verificar se a quantidade de bombas � a correta;
}
void randomMatriz() //randomiza posi��es da matris e atribui bombas;
{
    int x, y, i = 0, c = 0;
    srand(time(NULL)); //randomisa com base no hor�rio do computador, desse modo a randomiza��o nunca ser� igual;
    do{
        do{
            x = rand() % Linha;
            y = rand() % Coluna;
            Matriz1[x][y] = 9; //randomiza 2 coordenada para atribuir o 9 (numero escolhido para ser considerado uma bomba)
            i++; // incrementa i para n�o colocar mais bombas que o suficiente;
        }while(i < Bombas);
    c = testeBombas(); //recebe retorno de quantas bombas existem no tabuleiro;
    }while(c < Bombas || c > Bombas); //continua randomizando at� que o numero de bombas seja o correto;
}
void verificarMatriz1() //detecta bombas e incrementa as casas ao redor;
{
    int x, y;
    for(x = 0; x < Linha; x++){
        for(y = 0; y < Coluna; y++){
            if(Matriz1[x][y] != 9){ //controle para que n�o incremente uma bomba e acabe com a l�gica do jogo
                if(Matriz1[x][y+1] == 9){   // esse e todos os testes abaixo servem para detectar bombas incrementando as casas
                    Matriz1[x][y]++;        // ao redor, exatamente como deve funcionar em um campo minado;
                }
                if(Matriz1[x+1][y] == 9){
                    Matriz1[x][y]++;
                }
                if(Matriz1[x+1][y+1] == 9){
                    Matriz1[x][y]++;
                }
                if(Matriz1[x][y-1] == 9){
                    Matriz1[x][y]++;
                }
                if(Matriz1[x-1][y] == 9){
                    Matriz1[x][y]++;
                }
                if(Matriz1[x-1][y-1] == 9){
                    Matriz1[x][y]++;
                }
                if(Matriz1[x-1][y+1] == 9){
                    Matriz1[x][y]++;
                }
                if(Matriz1[x+1][y-1] == 9){
                    Matriz1[x][y]++;
                }
            }
        }
    }
}
int testeZero(x, y) //faz um teste retornando 0 ou 1 para controle e execu��o do procedimento zero();
{
    if(Matriz1[x][y] == 0 && Matriz2[x][y] == 'x'){ //deve ser 0 e x ao mesmo tempo para n�o ocorrer bugs ou loopping infinito;
        Score=Score+dificuldade; // pontua��o aumenta;
        return 1; // retorna 1 para continuar o teste;
    }
    if(Matriz1[x][y] == 1 || Matriz1[x][y] == 2 || Matriz1[x][y] == 3 && Matriz2[x][y] == 'x'){
        Matriz2[x][y] = Matriz1[x][y] + 48; //transforma o valor da Matriz1 em caractere para ser imprimido;
        Score=Score+dificuldade;
        return 0; //retorna zero parando a execu��o do codigo para essa dire��o;
    }
    return 0;
}
void zero(L, C)
{
    int c;
    do{
        c = testeZero(L,C);
        if(c == 1)
        {
            Matriz2[L][C] = Matriz1[L][C] + 48;
            zero(L + 1, C); //executa o mesmo c�digo para todas as dire��es (completamente � prova de erros)
            zero(L, C + 1);
            zero(L - 1, C);
            zero(L, C - 1);
        }
    }while(c == 1);
}
void verificarMatriz3() //verifica a Matriz3 de acordo com os valores atribuidos na Matriz2
{
    int x, y;
    for(x = 0; x < Linha; x++){
        for(y = 0; y < Coluna; y++){
            switch(Matriz2[x][y]){
                case '0':
                    Matriz3[x][y] = vazio;
                    break;
                case '1':
                    Matriz3[x][y] = '1';
                    break;
                case '2':
                    Matriz3[x][y] = '2';
                    break;
                case '3':
                    Matriz3[x][y] = '3';
                    break;
                case '4':
                    Matriz3[x][y] = '4';
                    break;
                case '5':
                    Matriz3[x][y] = '5';
                    break;
                case '6':
                    Matriz3[x][y] = '6';
                    break;
                case '7':
                    Matriz3[x][y] = '7';
                    break;
                case '8':
                    Matriz3[x][y] = '8';
                    break;
            }
        }
    }
}
int explodir() //Literalmente explode a Matriz revelando todos as posi��es e retornando o valor referente ao GameOver
{
    int x, y;
    system("cls");
    for(x = 0; x < Linha; x++){
        for(y = 0; y < Coluna; y++){
            switch(Matriz1[x][y]){
                case 0 :
                    Matriz3[x][y] = vazio;
                    break;
                case 1 :
                    Matriz3[x][y] = '1';
                    break;
                case 2 :
                    Matriz3[x][y] = '2';
                    break;
                case 3 :
                    Matriz3[x][y] = '3';
                    break;
                case 4 :
                    Matriz3[x][y] = '4';
                    break;
                case 5 :
                    Matriz3[x][y] = '5';
                    break;
                case 6 :
                    Matriz3[x][y] = '6';
                    break;
                case 7 :
                    Matriz3[x][y] = '7';
                    break;
                case 8 :
                    Matriz3[x][y] = '8';
                    break;
                case 9 :
                    Matriz3[x][y] = bomba;
                    break;
            }
        }
    }
    return 1;
}
void reiniciarCantos() //atribui um valor n�o utilisado no jogo para a ultima coluna da Matriz1 para remover um erro de verifica��o;
{
    int x = 0;
    do{
        Matriz1[x][Coluna] = 111;
        x++;
    }while(x < Linha);
}

void SalvarUltimoRank()
{
    system("cls");
    int letra = 65, tecla, i, s1, s2, s3;
    menuBonitinho(62, 15, 1, 9, 6, 0);
    gotoxy(51,12);
    tabulacaoBonitinha(3,2);
    printf("SALVAR SCORE");
    gotoxy(51,14);
    printf("Use as setas para selecionar 3 letras para salvar o score.");
    gotoxy(51,15);
    printf("Pressione enter para selecionar a letra desejada.");
    gotoxy(1,1);
    menuBonitinho(5,1,0,14,9,0);
    for(i = 0; i <= 2; i++){ //for para salvar somente 3 letras na variavel;
        gotoxy(i + 75, 17); // imprime em uma coordenada na tela;
        do{
            printf("%c\b", letra);
            tecla = getch();
            switch(tecla)
            {
                case 80: letra--;
                if(letra < 65){ // se a vari�vel letra for menor que o c�digo da letra A, a letra se transforma em Z;
                    letra = 90;
                }break;
                case 72: letra++;
                if(letra > 90){ // se a variavel letra for maior que o codigo da letra Z, a letra se transforma em A;
                    letra = 65;
                }break;
            }
        }while(tecla != 13); //continua executando at� que a tecla entre seja pressionada;
        rRank[10].nick[i] = letra; // atribui as letras corretas para a variavel usu�rio, uma por uma;
        rRank[10].pontos = Score;
        rRank[10].dif = dificuldade;
    }
    gotoxy(51,19);
    printf("Pressione qualquer tecla para vizualizar o ranking.");
    getch();
    AtribuirRank();
    OrganizaRank();
    MostrarRank();
}

void GAMEOVER()
{
    system("color 40"); //muda a cor da tela completa e do texto;
    int z = 219, x, y, i = 18, tecla;
    char game[6][89]={
    0,0,z,z,z,z,z,z,z,z,0,0,0,z,z,z,z,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,z,z,z,z,z,z,0,0,0,0,0,z,z,z,z,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,z,z,z,z,z,z,0,z,z,z,z,z,z,z,z,0,0,
    z,z,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,0,0,z,z,z,z,0,z,z,0,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,
    z,z,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,z,z,0,0,z,z,0,z,z,z,z,z,z,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,z,z,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,
    z,z,0,0,0,0,z,z,z,z,0,z,z,z,z,z,z,z,z,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,0,0,0,z,z,z,z,z,z,z,z,0,0,
    z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,z,z,0,0,
    0,0,z,z,z,z,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,z,z,z,z,z,z,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,0,0,0,z,z,0,0,0,0,0,z,z,z,z,z,z,z,z,z,z,0,z,z,0,0,0,0,0,0,z,z,
    };
    system("cls");
    pulaLinhaBonitinho(6);
    for(x = 0; x < 6; x++){
        tabulacaoBonitinha(5, 0);
        for(y = 0; y < 89; y++){
            printf("%c", game[x][y]);
        }
        printf("\n");
    }
    pulaLinhaBonitinho(2);
    tabulacaoBonitinha(6, 0);
    printf("Salvar pontuacao?\n");
    tabulacaoBonitinha(6, 0);
    printf("Sim\n");
    tabulacaoBonitinha(6,0);
    printf("Nao");
    do{
        do{
            gotoxy(49, i);
            textbackground(0);
            textcolor(4);
            switch(i){
                case 18 : printf("SIM"); break;
                case 19 : printf("NAO"); break;
            }
            textbackground(4);
            textcolor(0);
            tecla = getch();
            gotoxy(49, i);
            switch(i){
                case 18 : printf("Sim"); break;
                case 19 : printf("Nao"); break;
            }
            switch(tecla){
                case 80 :
                    i++;
                    if(i > 19){
                        i = 18;
                    } break;
                case 72 :
                    i--;
                    if(i < 18){
                        i = 19;
                    } break;
            }
        }while(tecla != 13);
        if(i == 18){ //caso sim ir� executar o procedimento que salva o ranking;
            system("color 0F");
            SalvarUltimoRank();
            Controle = 1;
        }else{
            system("color 0F");
            Controle = 1;
        }
    }while(Controle != 1);
}
void fimDeJogo()
{
    int tecla;
    explodir(); //revela todas as posi��es da matriz ao usu�rio;
    mostrarMatriz3(); //mostra a matriz totalmente aberta;
    gotoxy(21,1);
    textcolor(RED);
    printf("Perdeu! Pressione enter."); //escreve perdeu em coordenadas pr�determinadas;
    do{
        tecla = getch();
    }while(tecla != 13);
    GAMEOVER();
}
void GANHOU()
{
    system("color 20");
    Controle = 0;
    int z = 219, x, y, i = 18, tecla;
    char game[6][61] = {
        z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,z,z,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,0,z,z,0,0,0,0,0,0,z,z,
        z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,z,z,0,0,0,0,z,z,
        0,0,z,z,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,
        0,0,0,0,z,z,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,
        0,0,0,0,z,z,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,z,z,0,0,z,z,z,z,0,0,z,z,0,0,z,z,0,0,0,0,z,z,z,z,
        0,0,0,0,z,z,0,0,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,0,z,z,0,0,0,0,0,0,z,z,
    };
    system("cls");
    pulaLinhaBonitinho(6);
    for(x = 0; x < 6; x++){
        tabulacaoBonitinha(5, 6);
        for(y = 0; y < 61; y++){
            printf("%c", game[x][y]);
        }
        printf("\n");
    }
    pulaLinhaBonitinho(2);
    tabulacaoBonitinha(6, 0);
    printf("Salvar pontuacao?\n");
    tabulacaoBonitinha(6, 0);
    printf("Sim\n");
    tabulacaoBonitinha(6, 0);
    printf("Nao");
    do{
        do{
            gotoxy(49,i);
            textbackground(0);
            textcolor(GREEN);
            switch(i){
                case 18 : printf("SIM");break;
                case 19 : printf("NAO");break;
            }
            textbackground(GREEN);
            textcolor(0);
            tecla=getch();
            gotoxy(49,i);
            switch(i){
                case 18 : printf("Sim");break;
                case 19 : printf("Nao");break;
            }
            switch(tecla)
            {
                case 80 :
                    i++;
                    if(i > 19){
                        i = 18;
                    } break;
                case 72 :
                    i--;
                    if(i < 18){
                        i = 19;
                    } break;
            }
        }while(tecla != 13);
        system("color 0F");
        if(i == 18){
            SalvarUltimoRank();
            Controle = 1;
        }
        else{
            Controle = 1;
        }
    }while(Controle!=1);
}
void jogoGanho()
{
    int tecla = 0;
    if(cheat == 2)
    {
        Score = 0;
    }
    system("cls");
    explodir();
    mostrarMatriz3();
    gotoxy(21, 1);
    textcolor(GREEN);
    printf("Jogo Ganho!");
    textcolor(15);
    do{
        tecla = getch();
    }while(tecla != 13);
    GANHOU();
}
int verificarBombas()
{
    int x, y, i = 0, c = 0;
    for(x = 0; x < Linha; x++){
        for(y = 0; y < Coluna; y++){
            if(Matriz2[x][y] == 'x' && (Matriz1[x][y] >= 0 && Matriz1[x][y] < 9)){
                i++;
            }
            else if(i == 0 && Matriz2[x][y] == 'x' && Matriz1[x][y] == 9){
                c++;
            }
        }
    }
    if(i == 0){
        return 2;
    }
    else{
        return 0;
    }
}
void Sair() //procedimento de sa�da do jogo
{
    system("cls");
    printf("\n\n\tSaindo...\n\n\n\n\n\n\n\n\n\n\n\n\t");
    Sleep(3000);
    exit(0);
}
void jogo()
{
    int l,L=0,C=0,i=0,posLinha=3,posColuna=11,v;
    char c;
    zerarMatrizes();
    randomMatriz();
    verificarMatriz1();
    reiniciarCantos();
    system("cls");
    do{
       gotoxy(1,1);
       mostrarMatriz3();
       do{
           gotoxy(posColuna,posLinha);
           textcolor(15);
           printf("%c\b",158);
           v=getch();
           switch(Matriz3[L][C])
           {
                case vazio : textcolor(corVazio);break;
                case '1' : textcolor(cor1);break;
                case '2' : textcolor(cor2);break;
                case '3' : textcolor(cor3);break;
                case '4' : textcolor(cor4);break;
                case '5' : textcolor(cor5);break;
                case '6' : textcolor(cor6);break;
                case '7' : textcolor(cor7);break;
                case '8' : textcolor(cor8);break;
                default : textcolor(corDefault);
           }
           switch(v)
           {
               case 80 : printf("%c",Matriz3[L][C]);
               posLinha++;
               L++;
               if(posLinha>Linha+2){
                   posLinha--;
                   L--;
               }break;
               case 72 : printf("%c",Matriz3[L][C]);
               posLinha--;
               L--;
               if(posLinha<3){
                   posLinha++;
                   L++;
               }break;
               case 77 : printf("%c",Matriz3[L][C]);
               posColuna=posColuna+2;
               C++;
               if(posColuna>Coluna*2+10){
                   posColuna=posColuna-2;
                   C--;
               }break;
               case 75 :
                   printf("%c",Matriz3[L][C]);
                   posColuna=posColuna-2;
               C--;
               if(posColuna<11){
                   posColuna=posColuna+2;
                   C++;
               }break;
               case 27:
                  Score = 0;
                  i = 1;
                  break;
           }
           textcolor(15);
       }while(v!=13 && v!=27);
       if (i != 1) {
           if(Matriz2[L][C]=='x' && Matriz1[L][C]!=9)//controle para n�o atribuir Score caso a posi��o j� tenha sido escolhida;
           {
               Score=Score+dificuldade;
           }
           switch(Matriz1[L][C])
           {
               case 0 : zero(L,C);break;
               case 1 : Matriz2[L][C]='1'; break;
               case 2 : Matriz2[L][C]='2'; break;
               case 3 : Matriz2[L][C]='3';
                   if(cheat==1)
                   {
                       Score=6660;
                   };break;
               case 4 : Matriz2[L][C]='4'; break;
               case 5 : Matriz2[L][C]='5';
                   if(cheat==1)
                   {
                       Score=6660;
                   };break;
               case 6 : Matriz2[L][C]='6'; break;
               case 7 : Matriz2[L][C]='7'; break;
               case 8 : Matriz2[L][C]='8';
                   if(cheat==1)
                   {
                       Score=6660;
                   };break;
           }
           verificarMatriz3();
           i=verificarBombas();
           if(Matriz1[L][C]==9)
           {
               i = explodir();
           }
       }
    } while(i == 0);
    switch(i)
    {
        case 1 : fimDeJogo(); break;
        case 2 : jogoGanho(); break;
    }
}
void fullScreen() //fun��o que da um Alt+Enter e muda a tela para FullScreen
{
    keybd_event(VK_MENU  , 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1C, 0, 0);
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU  , 0x38, KEYEVENTF_KEYUP, 0);
}
void main()
{
    fullScreen();
    int i = 0;
    system("color 0F");
    inicio();
    do{
        Score = 0;
        switch(menuPrincipal()){
            case 0: configuracoesDoJogo(); break;
            case 2: Sair(); break;
        }
        jogo();
        cheat = 0;
    }while(Controle == 1);
}
