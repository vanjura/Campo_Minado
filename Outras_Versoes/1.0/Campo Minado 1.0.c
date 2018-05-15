//Trabalho interdiciplinar de Linguagem De Programação e Algoritmos
//Nomes dos envolvidos:
//    Lucas Vanjura
//    Rafael Penczkoski
//    Elieser
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.c>
#include <time.h>
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
#define Som 600
#define Dur 80

FILE *arq;

typedef struct Rank{
    char nick[3];
    int pontos, dif, Linha, Coluna;
}TRank;

TRank rRank[11], sRank[11];

int Matriz1 [20][21], Linha=4, Coluna = 4, Bombas = -1, Controle = 1, Score = 0, cheat = 0, dificuldade = 0;
char Matriz2 [20][20], Matriz3 [20][20];

void removerCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void limpaTela() { //metodo generico para limpar a tela
    system("cls");
}

void quebraLinha() {
    printf("\n");
}

void inicio(){
    limpaTela(); //Limpa a tela para não haver erros na localização da matriz.
    int z = pixel, x, y; //Declaração de variaveis para criar e mostrar a matriz.
    char game[15][62]={ {0,0,0,0,z,z,z,z,z,z,0,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,z,z,z,z,0,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0},
                        {0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,0,0,z,z,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0},
                        {0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0},
                        {0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,z,z,z,z,z,z,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,z,z,z,z,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0},
                        {0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0},
                        {0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0},
                        {0,0,0,0,z,z,z,z,z,z,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,0,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,0,z,z,z,z,z,z,0,0,0,0,z,z,z,z,z,z,z,z,0,0,0,0,0,0,z,z,z,z,z,z,0,0},
                        {z,z,z,z,0,0,z,z,z,z,0,0,z,z,0,0,z,z,z,z,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z},
                        {z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z},
                        {z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,z,z,z,z,0,0,z,z,z,z,z,z,z,z,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z},
                        {z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z},
                        {z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z},
                        {z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,z,z,z,z,0,0,0,0,0,0,z,z,z,z,z,z,0,0}}; // Matriz com "CAMPO MINADO" escrito.
    gotoxy(1, 10);//gotoxy para não encher de \n no código.
    for(x = 0; x < 15; x++){
        printf("\t\t\t\t\t\t");
        for(y = 0; y < 62; y++){
            printf("%c", game[x][y]);
        }
        quebraLinha();
    }//comando de for para motrar a matriz.
    printf("\n\n\n\t\t\t\t\t\t\t    Pressione qualquer tecla para iniciar.");
    getch();//reconhece qualquer tecla e pula para a proxima tela
    Beep(Som,Dur);
}

void pulaLinhaBonitinho(linhas)//pequeno procedimento para pular linhas antes de criar um menu (somente questão gráfica, não muda o funcionamento do jogo);
{
    int i = 0;
    do {
        printf("\n");
        i++;
    } while(i <= linhas);
}

void tabulacaoBonitinha(tabulacao, ajuste)//Mesmo intuito do procedimento anterior só que com tabulação;
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

void menuBonitinho(xColunas, yLinhas, cabecalho, linhasAntes, tabulacao, ajuste)//procedmento para criar uma área para menus, as opções dos menus são incluidas através de gotoxy()
{//tamanho(Colunas, Linhas, Cabeçalho, Linhas_Antes_De_Imprimir, Tabulação, Ajuste);
    int m, i = 0;
    pulaLinhaBonitinho(linhasAntes);//chama um procedimento que pular uma quantidade prédeterminada de linhas;
    tabulacaoBonitinha(tabulacao, ajuste);//chama um procedimento capaz de organizar a tabulação com controle de linhas;
    printf("%c", 201);//inprime o canto;
    for(m = 0; m < xColunas; m++)//faz a linha superior;
    {
        printf("%c", 205);
    }
    printf("%c", 187);//imprime o canto superior direito;
    if(cabecalho != 0){//caso precise esse codigo pode fazer um cabeçalho para um nome de menu por exemplo;
        do{
            quebraLinha();
            tabulacaoBonitinha(tabulacao, ajuste);// usa a mesma tabulação para que o menu fique correto;
            printf("%c", 186);//linha vertical
            for(m = 0; m < xColunas; m++){//parte nula para escrita do cabeçalho;
                printf(" ");
            }
            printf("%c", 186);
            i++;
        }while(cabecalho > i);//pode-se escolher o numero de linhas que o cabeçalho deverá ter;
        quebraLinha();
        tabulacaoBonitinha(tabulacao, ajuste);
        printf("%c", 204);
        for(m = 0; m < xColunas; m++){
            printf("%c", 205);
        }
        printf("%c", 185);
    }
    i = 0;
    do{
        quebraLinha();
        tabulacaoBonitinha(tabulacao, ajuste);
        printf("%c", 186);
        for(m = 0; m < xColunas; m++){
            printf(" ");
        }
        printf("%c", 186);
        i++;
    }while(yLinhas > i);
    quebraLinha();
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
    printf("%c Caso abra um quadrado sem n%cmeros e sem bomba os quadrados\n",186,163);
    tabulacaoBonitinha(6,0);
    printf("%c iguais ao redor tamb%cm ser%co abertos automaticamente.\n",186,130,198);
    tabulacaoBonitinha(6,0);
    printf("%c O jogo %c considerado ganho quando n%co houver mais quadrados\n",186,130,198);
    tabulacaoBonitinha(6,0);
    printf("%c seguros para abrir.\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c Caso abra um quadrado com bomba, GAME OVER.\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c Cada dificuldade atribui um n%cmero diferente por quadrados\n",186,163);
    tabulacaoBonitinha(6,0);
    printf("%c seguros abertos, quanto mais dificil e maior o tabuleiro mais\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c pontuac%co.\n",186,198);
    tabulacaoBonitinha(6,0);
    printf("%c Mesmo que perca o jogo ainda poder%c salvar sua pontuac%co.\n\n",186,160,198);
    tabulacaoBonitinha(6,0);
    printf("%c                     Tenha um bom jogo!\n\n\n\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c Pressione ENTER para voltar ao menu principal.\n",186);
    do{
        i = getch();
    }while(i!=13);
    Beep(Som,Dur);
}

void tutorialPagina1()
{ //75
    int i;
    gotoxy(50,14);
    printf(" Utilize as SETAS para mover o %c pelo tabuleiro.\n",158);
    tabulacaoBonitinha(6,0);
    printf("%c Quando o %c estiver em cima do quadrado que deseja selecionar,\n",186,158);
    tabulacaoBonitinha(6,0);
    printf("%c pressione a tecla ENTER.\n",186);
    tabulacaoBonitinha(6,0);
    printf("%c Os n%cmeros que aparecerem representam quantas bombas existem\n",186,163);
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
    printf("%c Pressione ENTER para ir a pr%cxima p%cgina ou ESC para voltar\n",186,162,160);
    tabulacaoBonitinha(6,0);
    printf("%c ao menu.\n",186);
    do{
        i = getch();
        if(i==13)
        {
            Beep(Som,Dur);
            tutorialPagina2();
        }
    }while(i != 13 && i != 27);
}

void tutorial()
{
    limpaTela();
    menuBonitinho(62, 15, 1, 9, 6, 0);
    gotoxy(76,12);
    printf("TUTORIAL");
    tutorialPagina1();
}

void MostrarRank()
{
    limpaTela();
    int x;
    menuBonitinho(62, 15, 1, 9, 6, 0);
    gotoxy(1,1);
    pulaLinhaBonitinho(26);
    tabulacaoBonitinha(6,0);
    printf("%c Pressione qualquer tecla para voltar ao menu principal.",186);
    gotoxy(51, 12);
    tabulacaoBonitinha(3, 4);
    printf("RANKING\n");
    gotoxy(51, 14);
    printf(" \tPosic%co\t  Nome\tPontos\tDificuldade\tTamanho\n\n",198);
    for(x=0;x<10;x++)
    {
        tabulacaoBonitinha(6,0);
        printf("%c\t  %d%c\t  %s\t%d\t",186,x+1,167,sRank[x].nick,sRank[x].pontos);
        switch(sRank[x].dif)
        {
            case 1 : printf("F%ccil          \t",160);break;
            case 2 : printf("M%cdio          \t",130);break;
            case 3 : printf("Dificil        \t");break;
            case 5 : printf("Infernal       \t");break;
            case 666 : printf("666 FROM HELL\t");break;
            default : printf("             \t");
        }
        printf(" %dx%d\n", sRank[x].Linha, sRank[x].Coluna);
    }
    getch();
    Beep(Som,Dur);
}

void RegravarRank()
{
    int x;
    arq=fopen("Ranking.txt","w");
    for(x=0;x<10;x++){
        fprintf(arq,"%s %d %d %d %d\n", sRank[x].nick, sRank[x].pontos, sRank[x].dif, sRank[x].Linha, sRank[x].Coluna);
    }
    fclose(arq);
}

void OrganizaRank()
{
    int x, y, g[10];
    for(x = 0;x < 10; x++){
        g[x] = -10;
        sRank[x].pontos = 0;
    }
    for(x = 0;x < 11; x++)
    {
        for(y = 0; y < 11; y++)
        {
            if(g[0] != y && g[1] != y && g[2] != y && g[3] != y && g[4] != y && g[5] != y && g[6] != y && g[7] != y && g[8] != y && g[9] != y)
            {
                if(rRank[y].pontos > sRank[x].pontos)
                {
                    sRank[x].pontos = rRank[y].pontos;
                    sRank[x].dif = rRank[y].dif;
                    sRank[x].Linha = rRank[y].Linha;
                    sRank[x].Coluna = rRank[y].Coluna;
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
        fscanf(arq, "%s", rRank[x].nick);
        fscanf(arq, "%d", &rRank[x].pontos);
        fscanf(arq, "%d", &rRank[x].dif);
        fscanf(arq, "%d", &rRank[x].Linha);
        fscanf(arq, "%d", &rRank[x].Coluna);
    }
    fclose(arq);
}

int menuPrincipal()
{
    removerCursor();//remove o cursor por questão gráfica;
    int Op, z = 16, c;//variáveis de controle indispensáveis para o funcionamento do menu
    do{
        limpaTela();
        menuBonitinho(62, 15, 1, 9, 6, 0);
        gotoxy(1,1);
        pulaLinhaBonitinho(25);
        tabulacaoBonitinha(6,0);
        printf("%c Utilize as SETAS para mover-se pelo menu.\n",186);
        tabulacaoBonitinha(6,0);
        printf("%c Pressione ENTER para selecionar a op%c%co desejada.",186,135,198);
        gotoxy(31, 12);//gotoxy será usado varias vezes por questão grafica e funcional;
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
                case 16 : printf ("Jogar"); break;//imprime novamente a escrita antiga dando o efeito de DesSeleção;
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
        }while(c != 13);//quando a tecla enter for precionada, a opção é selecionada;
        Beep(Som,Dur);
        switch(z)
        {
            case 16 : Op = 0; break;
            case 17 :
                Op = 1;
                tutorial(); break;
            case 18 :
                Op = 1;
                MostrarRank(); break;
            case 19 :
                Op = 2; break;
        }
    }while(Op == 1);
    return Op;//retorna a opção escolhida para um switch case;
}

void configuracoesDoJogo() {
    textcolor(15);
    int naoAceita = 1, opcao = 17, tecla; //variaveis para a configuração do jogo;
    char dif[10];
    do {
        limpaTela();
        menuBonitinho(62, 15, 1, 9, 6, 0);//tamanho(Colunas, Linhas, Cabeçalho, Linhas_Antes_De_Imprimir, Tabulação, Ajuste);
        gotoxy(1, 12);
        tabulacaoBonitinha(8, 3);
        printf("CONFIGURA%c%cES DO JOGO",128,229);
        pulaLinhaBonitinho(14);
        tabulacaoBonitinha(6, 0);
        printf("%c Use as SETAS do teclado para navegar pelas op%c%ces.\n",186,135,228);
        tabulacaoBonitinha(6, 0);
        printf("%c Pressione ENTER para selecionar.",186);
        gotoxy(51, 14);
        printf("Quantidade de linhas: ");

        do { // usa uma configuração parecida com a de seleção de menus, porém o cursor fica parado em só um lugar;
            printf("%d ", Linha);
            gotoxy(73, 14);
            tecla = getch();
            switch(tecla){
                case 80 :
                    Linha--;
                    if (Linha <= 3){
                        Linha++;
                    } break;
                case 72:
                    Linha++;
                    if (Linha >= 21){
                        Linha--;
                    } break;
            }
        } while(tecla != 13);
        Beep(Som,Dur);
        gotoxy(51,14);
        printf("Linhas: %d              ", Linha); //varios espaços para cobrir o antigo texto imprimido nesa linha;
        gotoxy(51,15);
        printf("Quantidade de colunas: ");
        do { //configuração igual a de escolher linhas;
            printf("%d ", Coluna);
            gotoxy(74, 15);
            tecla = getch();
            switch(tecla){
                case 80 :
                    Coluna--;
                    if (Coluna <= 3){
                        Coluna++;
                    }
                    break;
                case 72:
                    Coluna++;
                    if (Coluna >= 21){
                        Coluna--;
                    }
                    break;
            }
        } while(tecla != 13);
        Beep(Som,Dur);
        do {
            gotoxy(51, 15);
            printf("Colunas: %d              ", Coluna); //imprime a coluna para que o usuário possa conferir o se escolheu corretamente;
            gotoxy(51, 16);
            printf("Escolha a dificuldade:");
            gotoxy(51, 17);
            printf("F%ccil",160);
            gotoxy(51, 18);
            printf("M%cdio",130);
            gotoxy(51, 19);
            printf("Dificil");
            gotoxy(51, 20);
            printf("Infernal");
            do {
                gotoxy(51, opcao);
                textbackground(15);
                textcolor(0);

                switch(opcao) { //configuração igual a de todos os menus com escolha;
                    case 17:
                        printf("F%cCIL",181);
                        break;
                    case 18:
                        printf("M%cDIO",144);
                        break;
                    case 19:
                        printf("DIFICIL");
                        break;
                    case 20:
                        printf("INFERNAL");
                        break;
                }

                textbackground(0);
                textcolor(15);
                tecla = getch();
                gotoxy(51, opcao);

                switch(opcao){
                    case 17:
                        printf("F%ccil",160);
                        break;
                    case 18:
                        printf("M%cdio",130);
                        break;
                    case 19:
                        printf("Dificil");
                        break;
                    case 20:
                        printf("Infernal");
                        break;
                    case 21:
                        printf("                ");
                        break;
                    case 16:
                        gotoxy(51,21);
                        printf("                ");
                        break;
                }

                switch(tecla){
                    case 80:
                        opcao++;
                        if (opcao == 21) {
                            opcao = 17;
                        }
                        if (opcao == 22) {
                            opcao = 20;
                        }
                        break;
                    case 72:
                        opcao--;
                        if (opcao == 16) {
                            opcao = 20;
                        }
                        if (opcao == 15) {
                            opcao = 17;
                        }
                        break;
                    case 59:
                        if(opcao == 20){
                            opcao = 21;
                            gotoxy(51, 21);
                            textbackground(RED);
                            printf("     666     ");
                            textcolor(15);
                        } else if (opcao == 17){
                            opcao = 16;
                            gotoxy(51, 21);
                            textbackground(GREEN);
                            printf(" BEBE CHOR%cO ",199);
                            textcolor(15);
                        }
                        break;
                }
            } while(tecla != 13);
            Beep(Som,Dur);

            switch(opcao){
                case 17:
                    dificuldade = 1;
                    Bombas = (((float)Linha * (float)Coluna) / 100.0) * 10;
                    strcpy(dif, "Facil      ");//comando para atribuir uma palavra completa a uma string;
                    break;
                case 18:
                    dificuldade = 2;
                    Bombas = (((float)Linha * (float)Coluna) / 100.0) * 15;
                    strcpy(dif, "Medio      ");
                    break;
                case 19:
                    dificuldade = 3;
                    Bombas = (((float)Linha * (float)Coluna) / 100.0) * 20;
                strcpy(dif, "Dificil    ");break;
                case 20:
                    dificuldade = 5;
                    Bombas = (((float)Linha * (float)Coluna) / 100.0) * 40;
                    strcpy(dif, "Infernal   ");
                    break;
                case 21: //opção escondida para testes que resolvemos deixar;
                    dificuldade = 666;
                    Linha = 20;
                    Coluna = 20;
                    Bombas = 399;
                    cheat = 1;
                    strcpy(dif, "666 FROM HELL");
                    break;
                case 16: //opção escondida para testes que resolvemos deixar;
                    Linha = 20;
                    Coluna = 20;
                    Bombas = 1;
                    cheat = 2;
                    strcpy(dif, "Bebe Chorao");
                    break;
            }
        } while(Bombas < 0);

        gotoxy(51, 16);
        printf("Dificuldade: %s", dif);
        gotoxy(51, 17);
        printf("Voce aceita jogar com esse valores?");
        gotoxy(51, 18);
        printf("Sim      ");
        gotoxy(51, 19);
        printf("N%co      ",198);
        gotoxy(51, 20);
        printf("         ");
        gotoxy(51, 21);
        printf("                 ");
        opcao = 18;

        do {
            gotoxy(51, opcao);
            textbackground(15);
            textcolor(0);

            switch(opcao){
                case 18:
                    printf("SIM");
                    break;
                case 19:
                    printf("N%cO",199);
                    break;
            }
            textbackground(0);
            textcolor(15);
            tecla = getch();
            gotoxy(51, opcao);

            switch(opcao){
                case 18:
                    printf("Sim");
                    break;
                case 19:
                    printf("N%co",198);
                    break;
            }

            switch(tecla) {
                case 80:
                    opcao++;
                    if(opcao == 20){
                        opcao = 18;
                    }
                    break;
                case 72:
                    opcao--;
                    if(opcao == 17){
                        opcao = 19;
                    }
                    break;
            }
        } while(tecla != 13);
        Beep(Som,Dur);

        switch(opcao) {
            case 18:
                naoAceita = 0;
                break;
            case 19:
                naoAceita = 1;
                break;
        }
    } while(naoAceita == 1);//controle para voltar ao inicio da escolha caso o usuario não aceite jogar com os valores escolhidos;
}

void zerarMatrizes() { //inicializa todas as matrizes de acordo com o tipo de cada uma;
    int x, y;
    for(x = 0; x < Linha; x++){
        for(y = 0; y < Coluna; y++){
            Matriz1[x][y] = 0;
            Matriz2[x][y] = 'x';
            Matriz3[x][y] = 254;
        }
    }
}

void mostrarMatriz3() {//função para mostrar a matriz em tela com borda e tabulação corretas
    int x, y;
    quebraLinha();
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
            switch(Matriz3[x][y]){ //controla as cores de cada numero mostrado em tela (cores prédefinidas)
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
            printf("%c ", Matriz3[x][y]); //após mudar a cor, imprime em tela;
            textcolor(15);
        }
        printf("%c", 186);
        quebraLinha();
    }
    tabulacaoBonitinha(1, 0);
    printf("%c", 200);
    for(x = 0; x < Coluna * 2 + 1; x++){
        printf("%c", 205);
    }
    printf("%c\n", 188);
    printf("\t Utilize as SETAS para se mover pelo tabuleiro.\n");
    printf("\t Pressione ENTER para selecionar o quadrado desejado.\n");
    printf("\t Pressione ESC para desistir.");
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

void randomMatriz() {//randomiza posicoes da matris e atribui bombas;
    int x, y, i = 0, c = 0;
    srand(time(NULL)); //randomisa com base no horario do computador, desse modo a randomizacao nunca sera igual;
    do{
        do{
            x = rand() % Linha;
            y = rand() % Coluna;
            Matriz1[x][y] = 9; //randomiza 2 coordenada para atribuir o 9 (numero escolhido para ser considerado uma bomba)
            i++; // incrementa i para nao colocar mais bombas que o suficiente;
        }while(i < Bombas);
    c = testeBombas(); //recebe retorno de quantas bombas existem no tabuleiro;
    }while(c < Bombas || c > Bombas); //continua randomizando ate que o numero de bombas seja o correto;
}

void verificarMatriz1() {//detecta bombas e incrementa as casas ao redor;
    int x, y;
    for (x = 0; x < Linha; x++) {
        for (y = 0; y < Coluna; y++){
            if (Matriz1[x][y] != 9){         // controle para que não incremente uma bomba e acabe com a lógica do jogo
                if (Matriz1[x][y + 1] == 9) {   // esse e todos os testes abaixo servem para detectar bombas incrementando as casas
                    Matriz1[x][y]++;        // ao redor, exatamente como deve funcionar em um campo minado;
                }
                if (Matriz1[x + 1][y] == 9) {
                    Matriz1[x][y]++;
                }
                if (Matriz1[x + 1][y + 1] == 9) {
                    Matriz1[x][y]++;
                }
                if (Matriz1[x][y - 1] == 9) {
                    Matriz1[x][y]++;
                }
                if (Matriz1[x - 1][y] == 9) {
                    Matriz1[x][y]++;
                }
                if (Matriz1[x - 1][y - 1] == 9) {
                    Matriz1[x][y]++;
                }
                if (Matriz1[x - 1][y + 1] == 9) {
                    Matriz1[x][y]++;
                }
                if (Matriz1[x + 1][y - 1] == 9) {
                    Matriz1[x][y]++;
                }
            }
        }
    }
}

int deveExpandir(x, y) { //faz um teste retornando 0 ou 1 para controle e execução do procedimento expandir();
    if(Matriz1[x][y] == 0 && Matriz2[x][y] == 'x'){ //deve ser 0 e x ao mesmo tempo para não ocorrer bugs ou loopping infinito;
        Score = Score + dificuldade; // pontuação aumenta;
        return 1; // retorna 1 para continuar o teste;
    }
    if((Matriz1[x][y] == 1 || Matriz1[x][y] == 2 || Matriz1[x][y] == 3) && Matriz2[x][y] == 'x'){
        Matriz2[x][y] = Matriz1[x][y] + 48; //transforma o valor da Matriz1 em caractere para ser imprimido;
        Score = Score + dificuldade;
        return 0; //retorna zero parando a execução do codigo para essa direção;
    }
    return 0;
}

void expandir(linha, coluna) {
    if (deveExpandir(linha, coluna) == 1) {
        Matriz2[linha][coluna] = Matriz1[linha][coluna] + 48;
        expandir(linha + 1, coluna); //executa o mesmo código para todas as direções
        expandir(linha, coluna + 1);
        expandir(linha - 1, coluna);
        expandir(linha, coluna - 1);
    }
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

int explodir() {//Literalmente explode a Matriz revelando todos as posições e retornando o valor referente ao GameOver
    int x, y;
    limpaTela();
    for(x = 0; x < Linha; x++)  {
        for(y = 0; y < Coluna; y++) {
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

void reiniciarCantos() {//atribui um valor não utilizado no jogo para a ultima coluna da Matriz1 para remover um erro de verificação;
    int x = 0;
    do {
        Matriz1[x][Coluna] = 111;
        x++;
    } while(x < Linha);
}

void SalvarUltimoRank() {
    limpaTela();
    int letra = 65, tecla, i, opcao;
    menuBonitinho(62, 15, 1, 9, 6, 0);
    gotoxy(51,12);
    tabulacaoBonitinha(3,2);
    printf("SALVAR SCORE");
    gotoxy(51,14);
    printf("Use as SETAS para selecionar 3 letras para salvar o score.");
    gotoxy(51,15);
    printf("Pressione ENTER para selecionar a letra desejada.");
    gotoxy(1,1);
    menuBonitinho(5,1,0,14,9,0);
    do {
        gotoxy(75, 17);
        printf("   ");
        for(i = 0; i <= 2; i++){ //for para salvar somente 3 letras na variavel;
            gotoxy(75 + i, 17); // imprime em uma coordenada na tela;
            do {
                printf("%c\b", letra);
                tecla = getch();
                switch(tecla) {
                    case 80:
                        letra--;
                        if (letra < 65){ // se a variável letra for menor que o código da letra A, a letra se transforma em Z;
                            letra = 90;
                        }
                        break;
                    case 72:
                        letra++;
                        if(letra > 90){ // se a variavel letra for maior que o codigo da letra Z, a letra se transforma em A;
                            letra = 65;
                        }
                        break;
                }
            } while(tecla != 13); //continua executando até que a tecla entre seja pressionada;
            Beep(Som,Dur);
            rRank[10].nick[i] = letra;
        }
        printf("%c", letra);
        pulaLinhaBonitinho(10);
        tabulacaoBonitinha(6,0);
        printf("%c Pressione ESC para reescrever ou ENTER para confirmar.\r",186);
        do {
            opcao = getch();
        } while(opcao != 27 && opcao != 13);
        tabulacaoBonitinha(6,0);
        printf("%c                                                       ", 186);
    } while(opcao != 13);
    rRank[10].pontos = Score;
    rRank[10].dif = dificuldade;
    rRank[10].Linha = Linha;
    rRank[10].Coluna = Coluna;
    AtribuirRank();
    OrganizaRank();
    MostrarRank();
}

void GAMEOVER() {
    system("color 40"); //muda a cor da tela completa e do texto;
    int z = 219, x, y, opcao = 18, tecla;
    char game[6][89]=
   {{0,0,z,z,z,z,z,z,z,z,0,0,0,z,z,z,z,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,z,z,z,z,z,z,0,0,0,0,0,z,z,z,z,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,z,z,z,z,z,z,0,z,z,z,z,z,z,z,z,0,0},
    {z,z,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,0,0,z,z,z,z,0,z,z,0,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z},
    {z,z,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,z,z,0,0,z,z,0,z,z,z,z,z,z,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,z,z,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z},
    {z,z,0,0,0,0,z,z,z,z,0,z,z,z,z,z,z,z,z,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,0,0,0,z,z,z,z,z,z,z,z,0,0},
    {z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,z,z,0,0},
    {0,0,z,z,z,z,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,z,z,z,z,z,z,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,0,0,0,z,z,0,0,0,0,0,z,z,z,z,z,z,z,z,z,z,0,z,z,0,0,0,0,0,0,z,z}};
    limpaTela();
    pulaLinhaBonitinho(6);
    for(x = 0; x < 6; x++) {
        tabulacaoBonitinha(5, 0);
        for(y = 0; y < 89; y++) {
            printf("%c", game[x][y]);
        }
        quebraLinha();
    }
    pulaLinhaBonitinho(2);
    tabulacaoBonitinha(6, 0);
    printf("Salvar pontuac%co?\n",198);
    tabulacaoBonitinha(6, 0);
    printf("Sim\n");
    tabulacaoBonitinha(6,0);
    printf("N%co",198);
    do{
        do {
            gotoxy(49, opcao);
            textbackground(0);
            textcolor(4);
            switch(opcao){
                case 18:
                    printf("SIM");
                    break;
                case 19:
                    printf("N%cO",199);
                    break;
            }
            textbackground(4);
            textcolor(0);
            tecla = getch();
            gotoxy(49, opcao);
            switch(opcao){
                case 18:
                    printf("Sim");
                    break;
                case 19:
                    printf("N%co",198);
                    break;
            }
            switch(tecla){
                case 80:
                    opcao++;
                    if (opcao > 19){
                        opcao = 18;
                    }
                    break;
                case 72 :
                    opcao--;
                    if (opcao < 18){
                        opcao = 19;
                    }
                    break;
            }
        } while(tecla != 13);
        Beep(Som,Dur);

        if (opcao == 18){ //caso sim irá executar o procedimento que salva o ranking;
            system("color 0F");
            SalvarUltimoRank();
            Controle = 1;
        } else {
            system("color 0F");
            Controle = 1;
        }
    } while(Controle != 1);
}

void fimDeJogo() {
    int tecla;
    explodir(); //revela todas as posições da matriz ao usuário;
    mostrarMatriz3(); //mostra a matriz totalmente aberta;
    gotoxy(21,1);
    textcolor(12);
    printf("Perdeu! Pressione ENTER."); //escreve perdeu em coordenadas prédeterminadas;
    do {
       tecla = getch();
    } while(tecla != 13);
    Beep(Som,Dur);
    GAMEOVER();
}

void GANHOU() {
    system("color 20");
    Controle = 0;
    int z = 219, x, y, opcao = 18, tecla;
    char game[6][61] =
       {{z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,z,z,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,0,z,z,0,0,0,0,0,0,z,z},
        {z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,z,z,0,0,0,0,z,z},
        {0,0,z,z,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z},
        {0,0,0,0,z,z,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z},
        {0,0,0,0,z,z,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,z,z,0,0,z,z,z,z,0,0,z,z,0,0,z,z,0,0,0,0,z,z,z,z},
        {0,0,0,0,z,z,0,0,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,0,z,z,0,0,0,0,0,0,z,z}};
    limpaTela();
    pulaLinhaBonitinho(6);
    for(x = 0; x < 6; x++) {
        tabulacaoBonitinha(5, 6);
        for(y = 0; y < 61; y++) {
            printf("%c", game[x][y]);
        }
        quebraLinha();
    }
    pulaLinhaBonitinho(2);
    tabulacaoBonitinha(6, 0);
    printf("Salvar pontuac%co?\n",198);
    tabulacaoBonitinha(6, 0);
    printf("Sim\n");
    tabulacaoBonitinha(6, 0);
    printf("N%co",198);
    do {
        do {
            gotoxy(49, opcao);
            textbackground(0);
            textcolor(GREEN);
            switch(opcao){
                case 18:
                    printf("SIM");
                    break;
                case 19:
                    printf("N%cO",199);
                    break;
            }
            textbackground(GREEN);
            textcolor(0);
            tecla = getch();
            gotoxy(49,opcao);
            switch(opcao) {
                case 18:
                    printf("Sim");
                    break;
                case 19:
                    printf("N%co",198);
                    break;
            }

            switch(tecla) {
                case 80 :
                    opcao++;
                    if (opcao > 19){
                        opcao = 18;
                    }
                    break;
                case 72 :
                    opcao--;
                    if (opcao < 18){
                        opcao = 19;
                    }
                    break;
            }
        } while(tecla != 13);
        Beep(Som,Dur);

        system("color 0F");
        if (opcao == 18){
            SalvarUltimoRank();
            Controle = 1;
        } else {
            Controle = 1;
        }
    } while(Controle != 1);
}

void jogoGanho() {
    int tecla = 0;
    if (cheat == 2) {
        Score = 0;
    }
    limpaTela();
    explodir();
    mostrarMatriz3();
    gotoxy(21, 1);
    textcolor(LIGHTGREEN);
    printf("Jogo Ganho! Pressione ENTER.");
    textcolor(15);
    do {
        tecla = getch();
    } while(tecla != 13);
    Beep(Som,Dur);
    GANHOU();
}

int verificarBombas() {
    int x, y, i = 0;
    for (x = 0; x < Linha; x++) {
        for(y = 0; y < Coluna; y++) {
            if (Matriz2[x][y] == 'x' && (Matriz1[x][y] >= 0 && Matriz1[x][y] < 9)) {
                i++;
            }
        }
    }

    if (i == 0) {
        return 2; //jogo ganho
    } else {
        return 0; //jogo continua
    }
}

void Sair() { //procedimento de saída do jogo e créditos
    limpaTela();
    menuBonitinho(62, 15, 1, 9, 6, 0);
    gotoxy(1,1);
    pulaLinhaBonitinho(10);
    tabulacaoBonitinha(9,2);
    printf("SAINDO...");
    pulaLinhaBonitinho(4);
    tabulacaoBonitinha(7);
    printf("Desenvolvido por:  Lucas Vanjura,\n\n");
    tabulacaoBonitinha(7);
    printf("                   Rafael Penczkoski e\n\n");
    tabulacaoBonitinha(7);
    printf("                   Elieser Pantale%co.",198);
    pulaLinhaBonitinho(10);
    Sleep(5000);
    exit(0);
}

void jogo() {
    int linha = 0, coluna = 0, statusJogo = 0, posLinha = 3, posColuna = 11, teclaPressionada;
    zerarMatrizes();
    randomMatriz();
    reiniciarCantos();
    verificarMatriz1();
    limpaTela();
    do {
       gotoxy(1,1);
       mostrarMatriz3();
       do {
           gotoxy(posColuna, posLinha);
           textcolor(15);
           printf("%c\b", 158);
           teclaPressionada = getch();
           switch(Matriz3[linha][coluna]) {
                case vazio:
                    textcolor(corVazio);
                    break;
                case '1':
                    textcolor(cor1);
                    break;
                case '2':
                    textcolor(cor2);
                    break;
                case '3':
                    textcolor(cor3);
                    break;
                case '4':
                    textcolor(cor4);
                    break;
                case '5':
                    textcolor(cor5);
                    break;
                case '6':
                    textcolor(cor6);
                    break;
                case '7':
                    textcolor(cor7);
                    break;
                case '8':
                    textcolor(cor8);
                    break;
                default:
                    textcolor(corDefault);
           }

           switch(teclaPressionada) {
               case 80:
                    printf("%c",Matriz3[linha][coluna]);
                    posLinha++;
                    linha++;
                    if(posLinha > Linha + 2){
                        posLinha--;
                        linha--;
                    }
                    break;
               case 72:
                    printf("%c",Matriz3[linha][coluna]);
                    posLinha--;
                    linha--;
                    if(posLinha < 3){
                        posLinha++;
                        linha++;
                    }
                    break;
               case 77:
                    printf("%c",Matriz3[linha][coluna]);
                    posColuna = posColuna + 2;
                    coluna++;
                    if(posColuna> Coluna * 2 + 10){
                        posColuna = posColuna - 2;
                        coluna--;
                    }
                    break;
               case 75:
                    printf("%c",Matriz3[linha][coluna]);
                    posColuna = posColuna - 2;
                    coluna--;
                    if(posColuna < 11){
                        posColuna = posColuna + 2;
                        coluna++;
                    }
                    break;
               case 27:
                    Score = 0;
                    statusJogo = 1;
                    break;
           }
           textcolor(15);
       } while(teclaPressionada != 13 && teclaPressionada != 27);

       if (statusJogo != 1) {
           if(Matriz2[linha][coluna]=='x' && Matriz1[linha][coluna]!=9)//controle para não atribuir Score caso a posição já tenha sido escolhida;
           {
               Score = Score + dificuldade;
           }
           switch(Matriz1[linha][coluna])
           {
               case 0: Beep(Som,Dur);
                    expandir(linha, coluna);
                    break;
               case 1: Beep(Som,Dur);
                    Matriz2[linha][coluna]='1';
                    break;
               case 2: Beep(Som,Dur);
                    Matriz2[linha][coluna]='2';
                    break;
               case 3: Beep(Som,Dur);
                    Matriz2[linha][coluna]='3';
                    if (cheat == 1) {
                       Score=6660;
                    }
                    break;
               case 4: Beep(Som,Dur);
                    Matriz2[linha][coluna]='4';
                    break;
               case 5: Beep(Som,Dur);
                    Matriz2[linha][coluna]='5';
                    if (cheat == 1) {
                        Score=6660;
                    }
                    break;
               case 6: Beep(Som,Dur);
                    Matriz2[linha][coluna]='6';
                    break;
               case 7: Beep(Som,Dur);
                    Matriz2[linha][coluna]='7';
                    break;
               case 8: Beep(Som,Dur);
                    Matriz2[linha][coluna]='8';
                    if (cheat==1) {
                       Score=6660;
                    }
                    break;
           }

           verificarMatriz3();
           statusJogo = verificarBombas();

           if(Matriz1[linha][coluna] == 9) {
                Beep(1000,Dur);
               statusJogo = explodir();
           }
       }
    } while(statusJogo == 0);

    switch(statusJogo)
    {
        case 1:
            fimDeJogo();
            break;
        case 2:
            jogoGanho();
            break;
    }
}

void fullScreen() //função que da um Alt+Enter e muda a tela para FullScreen
{
    keybd_event(VK_MENU  , 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1C, 0, 0);
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU  , 0x38, KEYEVENTF_KEYUP, 0);
}

int main() {
    fullScreen();
    AtribuirRank();
    OrganizaRank();
    system("color 0F");
    inicio();
    do {
        Score = 0;
        switch(menuPrincipal()){
            case 0: configuracoesDoJogo(); break;
            case 2: Sair(); break;
        }
        jogo();
        cheat = 0;
    } while(Controle == 1);
    return 0;
}
