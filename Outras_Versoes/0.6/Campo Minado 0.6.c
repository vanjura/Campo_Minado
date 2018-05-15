//Trabalho interdiciplinar de Linguagem De Programação e Algoritmos
//Nomes dos envolvidos:
//    Lucas Vanjura
//    Rafael Penczkoski
//    Elieser

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.c>
#define vazio 254
#define pixel 219

int Matriz1[20][21], Linha, Coluna, Bombas=-1,Controle=1,Score=0,cheat=0;
char Matriz2[20][20],Matriz3[20][20];
void colocarCursor()
{
  CONSOLE_CURSOR_INFO cursor = {1, TRUE};//Struct do windows para modificar configurações do cursor.TRUE ativa o cursor e FALSE desativa;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void removerCursor()
{
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void inicio()
{
    int i; //Variavel para o comando getch() funcionar.
    system("cls"); //Limpa a tela para não haver erros na localização da matriz.
    int z=pixel,x,y; //Declaração de variaveis para criar e mostrar a matriz.
    char game[15][62]={
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
    gotoxy(1,10);//gotoxy para não encher de \n no código.
    for(x=0;x<15;x++)
    {
        printf("\t\t\t\t\t\t");
        for(y=0;y<62;y++)
        {
            printf("%c",game[x][y]);
        }
        printf("\n");
    }//comando de for para motrar a matriz.
    printf("\n\n\n\t\t\t\t\t\t\t    Pressione qualquer tecla para iniciar.");
    i=getch();//reconhece qualquer tecla e pula para a proxima tela
}
void regras()
{
    int i;
    do{
        system("cls");
        printf("\n\n\tREGRAS:\n");
        textcolor(2);
        textbackground(3);
        printf("\tO Campo Minado e um jogo aparentemente simples de\n");
        textcolor(3);
        textbackground(5);
        printf("\tmemoria e raciocinio. O objetivo do Campo Minado \n");
        textcolor(4);
        textbackground(0);
        printf("\te revelar os quadrados vazios e com numeros, evi-\n");
        textcolor(5);
        printf("\tando aqueles que escondem bombas.               \n");
        textcolor(7);
        printf("\n\tEnter para voltar.");
        i=getch();
    }while(i!=13);
}
void pulaLinhaBonitinho(l)//pequeno procedimento para pular linhas antes de criar um menu (somente questão gráfica, não muda o funcionamento do jogo);
{
    int i=0;
    do{
        printf(" \n");
        i++;
    }while(i<=l);
}
void tabulacaoBonitinha(t,k)//Mesmo intuito do procedimento anterior só que com tabulação;
{
    int i=0;
    do{
        i++;
        printf("\t");
    }while(i<t);
    i=0;
    while(i<k){
        i++;
        printf(" ");
    }
}
void menuBonitinho(x,y,c,l,t,k)//procedmento para criar uma área para menus, as opções dos menus são incluidas através de gotoxy()
{
    int m,n,i=0;
    pulaLinhaBonitinho(l);//chama um procedimento que pular uma quantidade prédeterminada de linhas;
    tabulacaoBonitinha(t,k);//chama um procedimento capaz de organizar a tabulação com controle de linhas;
    printf("%c",201);//inprime o canto;
    for(m=0;m<x;m++)//faz a linha superior;
    {
        printf("%c",205);
    }
    printf("%c",187);//imprime o canto superior direito;
    if(c!=0)//caso precise esse codigo pode fazer um cabeçalho para um nome de menu por exemplo;
    {
        do{
        printf("\n");
        tabulacaoBonitinha(t,k);// usa a mesma tabulação para que o menu fique correto;
        printf("%c",186);//linha vertical
        for(m=0;m<x;m++)//parte nula para escrita do cabeçalho;
        {
            printf(" ");
        }
        printf("%c",186);
        i++;
        }while(c>i);//pode-se escolher o numero de linhas que o cabeçalho deverá ter;
        printf("\n");
        tabulacaoBonitinha(t,k);
        printf("%c",204);
        for(m=0;m<x;m++)
        {
            printf("%c",205);
        }
        printf("%c",185);
    }
    i=0;
    do{
        printf("\n");
        tabulacaoBonitinha(t,k);
        printf("%c",186);
        for(m=0;m<x;m++)
        {
            printf(" ");
        }
        printf("%c",186);
        i++;
    }while(y>i);
    printf("\n");
    tabulacaoBonitinha(t,k);
    printf("%c",200);
    for(m=0;m<x;m++)
    {
        printf("%c",205);
    }
    printf("%c",188);
}
int menuPrincipal()
{
    removerCursor();//remove o cursor por questão gráfica;
    int Op,x,y,z=16,c;//variáveis de controle indispensáveis para o funcionamento do menu
    do{
        system("cls");
        menuBonitinho(62,15,1,9,6,0);//tamanho(Colunas, Linhas, Cabeçalho, Linhas_Antes_De_Imprimir, Tabulação, Ajuste);
        gotoxy(31,12);//gotoxy será usado varias vezes por questão grafica e funcional;
        tabulacaoBonitinha(6,1);
        printf("MENU PRINCIPAL");
        gotoxy(60,16);
        printf("Jogar");
        gotoxy(60,17);
        printf("Regras");
        gotoxy(60,18);
        printf("Sair");
        do{ //codigo para o funcionamento das teclas up e down para controle do menu;
            gotoxy(60,z);
            textbackground(WHITE);
            textcolor(0);
            switch(z)
            {
                case 16 : printf("JOGAR\b\b\b\b\b");break; //O \b faz com que o cursor volte algumas linhas para ficar logo acima da primeira linha da escrita, desse modo pode-se apagar facimente o que está escrito dando o efeito de seleção quando usado com um textbackground();
                case 17 : printf("REGRAS\b\b\b\b\b\b");break;
                case 18 : printf("SAIR\b\b\b\b");break;
            }
            textbackground(0);
            textcolor(WHITE);
            c=getch();
            switch(c)
            {
                case 80 ://caso aperte a seta para baixo;
                switch(z)
                {
                    case 16 : printf("Jogar");break;//imprime novamente a escrita antiga dando o efeito de DesSeleção;
                    case 17 : printf("Regras");break;
                    case 18 : printf("Sair");break;
                }
                z++;
                if(z==19)
                {
                    z=16;
                };break;
                case 72 ://caso aperte a seta para cima
                switch(z)
                {
                    case 16 : printf("Jogar");break;
                    case 17 : printf("Regras");break;
                    case 18 : printf("Sair");break;
                }
                z--;
                if(z==15)
                {
                    z=18;
                };break;
            }
        }while(c!=13);//quando a tecla enter for precionada, a opção é selecionada;
        switch(z)
        {
            case 16 : Op=0;break;
            case 17 : Op=1;
                regras();break;
            case 18 : Op=2;break;
        }
    }while(Op==1);
    return Op;//retorna a opção escolhida para um switch case;
}
void configuracoesDoJogo()
{
    textcolor(15);
    int dificuldade,R=1,z=17,c;//variaveis para a configuração do jogo;
    char dif[10];
    do{
        system("cls");
        menuBonitinho(62,15,1,9,6,0);//tamanho(Colunas, Linhas, Cabeçalho, Linhas_Antes_De_Imprimir, Tabulação, Ajuste);
        gotoxy(1,12);
        tabulacaoBonitinha(8,3);
        printf("CONFIGURACOES DO JOGO");
        do{
            gotoxy(51,14);
            printf("Informe a quantidade de linhas (4 ate 20):                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            scanf("%d",&Linha);//atibui para uma variavel global;
            if(Linha<4)
            {
                gotoxy(51,15);
                printf("O minimo para as linhas eh 4.                            ");
            }
            else if(Linha>20)
            {
                gotoxy(51,15);
                printf("O maximo para as linhas eh 20.                           ");
            }
        }while(Linha<4 || Linha>20);
        do{
            gotoxy(51,14);
            printf("Linhas: %d                                                   ",Linha);
            gotoxy(51,15);
            printf("Informe a quantidade de colunas (4 ate 20):                  \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            scanf("%d",&Coluna);//atribui para uma variavel global;
            if(Coluna<4)
            {
                gotoxy(51,16);
                printf("O minimo para as colunas eh 4.                           ");
            }
            else if(Coluna>20)
            {
                gotoxy(51,16);
                printf("O maximo para as colunas eh 20.                          ");
            }
        }while(Coluna<4 || Coluna>20);
        do{
            gotoxy(51,15);
            printf("Colunas: %d                                                  ",Coluna);
            gotoxy(51,16);
            printf("Escolha a dificuldade:                                       ");
            gotoxy(51,17);
            printf("Facil");
            gotoxy(51,18);
            printf("Medio");
            gotoxy(51,19);
            printf("Dificil");
            gotoxy(51,20);
            printf("Infernal");
            do{
                gotoxy(51,z);
                textbackground(15);
                textcolor(0);
                switch(z)
                {
                    case 17 : printf("FACIL\b\b\b\b\b");break;
                    case 18 : printf("MEDIO\b\b\b\b\b");break;
                    case 19 : printf("DIFICIL\b\b\b\b\b\b\b");break;
                    case 20 : printf("INFERNAL\b\b\b\b\b\b\b\b");break;
                }
                textbackground(0);
                textcolor(15);
                c=getch();
                switch(c)
                {
                    case 80 :
                    switch(z)
                    {
                        case 17 : printf("Facil");break;
                        case 18 : printf("Medio");break;
                        case 19 : printf("Dificil");break;
                        case 20 : printf("Infernal");break;
                        case 21 : printf("                ");break;
                        case 16 : gotoxy(51,21); printf("                ");break;
                    }
                    z++;
                    if(z==21)
                    {
                        z=17;
                    }
                    if(z==22)
                    {
                        z=20;
                    }break;
                    case 72 :
                    switch(z)
                    {
                        case 17 : printf("Facil");break;
                        case 18 : printf("Medio");break;
                        case 19 : printf("Dificil");break;
                        case 20 : printf("Infernal");break;
                        case 21 : printf("                ");break;
                        case 16 : gotoxy(51,21); printf("                ");break;
                    }
                    z--;
                    if(z==16)
                    {
                        z=20;
                    }
                    if(z==15)
                    {
                        z=17;
                    }break;
                    case 59 :
                    if(z==20)
                    {
                        z=21;
                        gotoxy(51,21);
                        textbackground(RED);
                        printf("     666     ");
                        textcolor(15);
                    }else if(z==17)
                    {
                        z=16;
                        gotoxy(51,21);
                        textbackground(GREEN);
                        printf(" BEBE CHORAO ");
                        textcolor(15);
                    }break;
                }
            }while(c!=13);
            switch(z)
            {
                case 17 : Bombas=(((float)Linha*(float)Coluna)/100.0)*10+1;
                    strcpy(dif, "Facil      ");break;//comando para atribuir uma palavra completa a uma string;
                case 18 : Bombas=(((float)Linha*(float)Coluna)/100.0)*15+1;
                    strcpy(dif, "Medio      ");break;
                case 19 : Bombas=(((float)Linha*(float)Coluna)/100.0)*20+1;
                    strcpy(dif, "Dificil    ");break;
                case 20 : Bombas=(((float)Linha*(float)Coluna)/100.0)*40+1;
                    strcpy(dif, "Infernal   ");break;
                case 21 : Linha= 20;
                    Coluna= 20;
                    Bombas=399;
                    cheat=1;
                    strcpy(dif, "666 FROM HELL");break;
                case 16 : Linha= 20;
                    Coluna= 20;
                    Bombas=1;
                    cheat=1;
                    strcpy(dif, "Bebe Chorao");break;
            }
        }while(Bombas<0);
        gotoxy(51,16);
        printf("Dificuldade: %s",dif);
        gotoxy(51,17);
        printf("Voce aceita jogar com esse valores?");
        gotoxy(51,18);
        printf("Sim      ");
        gotoxy(51,19);
        printf("Nao      ");
        gotoxy(51,20);
        printf("         ");
        gotoxy(51,21);
        printf("                 ");
        z=18;
        do{
            gotoxy(51,z);
            textbackground(15);
            textcolor(0);
            switch(z)
            {
                case 18 : printf("SIM\b\b\b");break;
                case 19 : printf("NAO\b\b\b");break;
            }
            textbackground(0);
            textcolor(15);
            c=getch();
            switch(c)
            {
                case 80 :
                switch(z)
                {
                    case 18 : printf("Sim");break;
                    case 19 : printf("Nao");break;
                }
                z++;
                if(z==20)
                {
                    z=18;
                };break;
                case 72 :
                switch(z)
                {
                    case 18 : printf("Sim");break;
                    case 19 : printf("Nao");break;
                }
                z--;
                if(z==17)
                {
                    z=19;
                };break;
            }
        }while(c!=13);
        switch(z)
        {
            case 18: R=0;break;
            case 19: R=1;break;
        }
    }while(R==1);
}
void zerarMatrizes() //zera todas as matrizes te acordo com o tipo de cada uma;
{
    int x,y;
    for(x=0;x<Linha;x++)
    {
        for(y=0;y<Coluna;y++)
        {
            Matriz1[x][y]=0;
            Matriz2[x][y]='x';
            Matriz3[x][y]='-';
        }
    }
}

void mostrarMatriz3()
{
    int x,y;
    for(x=0;x<Linha;x++)
    {
        printf("\t");
        for(y=0;y<Coluna;y++)
        {
            printf("%c ",Matriz3[x][y]);
        }
        printf("\n");
    }
}
int testeBombas()
{
    int x,y,c=0;
    for(x=0;x<Linha;x++)
    {
        for(y=0;y<Coluna;y++)
        {
            if(Matriz1[x][y]==9)
            {
                c++;
            }
        }
    }
    return c;
}
void randomMatriz()
{
    int x,y,i=0,c=0;
    srand(time(NULL));
    do{
        do{
        x=rand()%Linha;
        y=rand()%Coluna;
        Matriz1[x][y]=9;
        i++;
        }while(i<Bombas);
    c=testeBombas();
    }while(c<Bombas || c>Bombas);
}
void verificarMatriz1()
{
    int x,y;
    for(x=0;x<Linha;x++)
    {
        for(y=0;y<Coluna;y++)
        {
            if(Matriz1[x][y]!=9)
            {
                if(Matriz1[x][y+1]==9)
                {
                    Matriz1[x][y]++;
                }
                if(Matriz1[x+1][y]==9)
                {
                    Matriz1[x][y]++;
                }
                if(Matriz1[x+1][y+1]==9)
                {
                    Matriz1[x][y]++;
                }
                if(Matriz1[x][y-1]==9)
                {
                    Matriz1[x][y]++;
                }
                if(Matriz1[x-1][y]==9)
                {
                    Matriz1[x][y]++;
                }
                if(Matriz1[x-1][y-1]==9)
                {
                    Matriz1[x][y]++;
                }
                if(Matriz1[x-1][y+1]==9)
                {
                    Matriz1[x][y]++;
                }
                if(Matriz1[x+1][y-1]==9)
                {
                    Matriz1[x][y]++;
                }
            }
        }
    }
}
int testeZero(x,y)
{
    if(Matriz1[x][y]==0 && Matriz2[x][y]=='x')
    {
        Score++;
        return 1;
    }
    if(Matriz1[x][y]==1 || Matriz1[x][y]==2 || Matriz1[x][y]==3 && Matriz2[x][y]=='x')
    {
        Matriz2[x][y]=Matriz1[x][y]+48;
        Score++;
        return 0;
    }
    return 0;
}
void zero(L,C)
{
    int c;
    do{
        c=testeZero(L,C);
        if(c==1)
        {
            Matriz2[L][C]=Matriz1[L][C]+48;
            zero(L+1,C);
            zero(L,C+1);
            zero(L-1,C);
            zero(L,C-1);
        }
    }while(c==1);
}
void verificarMatriz3()
{
    int x,y;
    for(x=0;x<Linha;x++)
    {
        for(y=0;y<Coluna;y++)
        {
            switch(Matriz2[x][y])
            {
                case '0': Matriz3[x][y]=254;break;
                case '1': Matriz3[x][y]='1';break;
                case '2': Matriz3[x][y]='2';break;
                case '3': Matriz3[x][y]='3';break;
                case '4': Matriz3[x][y]='4';break;
                case '5': Matriz3[x][y]='5';break;
                case '6': Matriz3[x][y]='6';break;
                case '7': Matriz3[x][y]='7';break;
                case '8': Matriz3[x][y]='8';break;
            }
        }
    }
}
int explodir()
{
    int x,y;
    system("cls");
    for(x=0;x<Linha;x++)
    {
        for(y=0;y<Coluna;y++)
        {
            switch(Matriz1[x][y])
            {
                case 0 : Matriz3[x][y]=254;break;
                case 1 : Matriz3[x][y]='1';break;
                case 2 : Matriz3[x][y]='2';break;
                case 3 : Matriz3[x][y]='3';break;
                case 4 : Matriz3[x][y]='4';break;
                case 5 : Matriz3[x][y]='5';break;
                case 6 : Matriz3[x][y]='6';break;
                case 7 : Matriz3[x][y]='7';break;
                case 8 : Matriz3[x][y]='8';break;
                case 9 : Matriz3[x][y]=207;break;
            }
        }
    }
    return 1;
}
void reiniciarCantos()
{
    int x=0;
    do{
    Matriz1[x][Coluna]=111;
    x++;
    }while(x<Linha);
}
void GAMEOVER()
{
    system("color 04");
    int z=219,x,y,i;
    char game[13][46]={
    0,0,z,z,z,z,z,z,z,z,0,0,0,0,z,z,z,z,z,z,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,z,z,z,z,z,z,
    z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,0,0,z,z,z,z,0,0,z,z,0,0,0,0,0,0,0,0,
    z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,z,z,z,z,0,0,0,0,
    z,z,0,0,0,0,z,z,z,z,0,0,z,z,z,z,z,z,z,z,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,0,0,
    z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,0,0,
    0,0,z,z,z,z,z,z,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,z,z,z,z,z,z,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,z,z,z,z,z,z,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,z,z,z,z,z,z,0,0,z,z,z,z,z,z,z,z,0,0,
    z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,
    z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,z,z,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,
    z,z,0,0,0,0,0,0,z,z,0,0,0,0,z,z,0,0,z,z,0,0,0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,z,z,z,z,z,z,0,0,
    z,z,0,0,0,0,0,0,z,z,0,0,0,0,z,z,0,0,z,z,0,0,0,0,z,z,0,0,0,0,0,0,0,0,0,0,z,z,0,0,0,0,z,z,0,0,
    0,0,z,z,z,z,z,z,0,0,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,z,z,z,z,z,z,z,z,0,0,z,z,0,0,0,0,0,0,z,z,
    };
    system("cls");
    printf("\n\n");
    for(x=0;x<13;x++)
    {
        printf("\t");
        for(y=0;y<46;y++)
        {
            printf("%c",game[x][y]);
        }
        printf("\n");
    }
    printf("\n\tVoltar ao Menu?\n");
    printf("\t1. Sim\n");
    printf("\t2. Nao (o programa sera fechado)\n\t");
    scanf("%d",&i);
    if(i==1)
    {
        Controle=1;
    }
    else
    {
        exit(0);
    }
    system("color 07");
}
void fimDeJogo()
{
    explodir();
    mostrarMatriz3();
    printf("\n\tFIM DE JOGO.");
    printf("\n\t");
    system("pause");
    GAMEOVER();
}
void GANHOU()
{
    system("color 02");
    int z=219,x,y,i;
    char game[13][34]={
        z,z,0,0,0,0,0,0,z,z,0,0,0,0,z,z,z,z,z,z,0,0,0,0,z,z,0,0,0,0,0,0,z,z,
        z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,
        0,0,z,z,0,0,z,z,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,
        0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,
        0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,0,0,0,0,z,z,
        0,0,0,0,z,z,0,0,0,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,0,0,z,z,z,z,z,z,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,
        0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,0,z,z,z,z,0,0,0,0,z,z,0,0,0,
        0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,
        0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,z,z,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,0,
        0,0,0,z,z,z,z,0,0,z,z,z,z,0,0,0,z,z,0,0,0,z,z,0,0,0,0,z,z,z,z,0,0,0,
        0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,z,z,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,
    };
    system("cls");
    printf("\n\n");
    for(x=0;x<13;x++)
    {
        printf("\t");
        for(y=0;y<34;y++)
        {
            printf("%c",game[x][y]);
        }
        printf("\n");
    }
    printf("\n\tVoltar ao Menu?\n");
    printf("\t1. Sim\n");
    printf("\t2. Nao (o programa sera fechado)\n\t");
    scanf("%d",&i);
    if(i==1)
    {
        Controle=1;
    }
    else
    {
        exit(0);
    }
    system("color 07");
}
void jogoGanho()
{
    system("cls");
    explodir();
    mostrarMatriz3();
    printf("\n\t");
    system("pause");
    GANHOU();
}
int verificarBombas()
{
    int x,y,i=0,c=0;
    for(x=0;x<Linha;x++)
    {
        for(y=0;y<Coluna;y++)
        {
            if(Matriz2[x][y]=='x' && (Matriz1[x][y]>=0 && Matriz1[x][y]<9))
            {
                i++;
            }
            else if(i==0 && Matriz2[x][y]=='x' && Matriz1[x][y]==9)
            {
                c++;
            }
        }
    }
    if(i==0)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
void Sair()
{
    system("cls");
    printf("\n\n\tSaindo...\n\n\n\n\n\n\n\n\n\n\n\n\t");
    Sleep(3000);
    exit(0);
}
void jogo()
{
    colocarCursor();
    int l,L=0,C=0,i=0,z=6,w=9,v;
    char c;
    zerarMatrizes();
    randomMatriz();
    verificarMatriz1();
    reiniciarCantos();
    do{
        system("cls");
        mostrarMatriz3();
        do{
            gotoxy(w,z);
            v=getch();
            switch(v)
            {
                case 80 : z++;
                L++;
                if(z==Linha+6)
                {
                    z--;
                    L--;
                };break;
                case 72 : z--;
                L--;
                if(z==5)
                {
                    L++;
                    z++;
                };break;
                case 77 : w=w+2;
                C++;
                if (w>Coluna*2+7)
                {
                    C--;
                    w=w-2;
                }break;
                case 75 : w=w-2;
                C--;
                if (w<8)
                {
                    C++;
                    w=w+2;
                }break;
            }
        }while(v!=13);
        switch(Matriz1[L][C])
        {
            case 0 : zero(L,C);break;
            case 1 : Matriz2[L][C]='1';
                Score++;break;
            case 2 : Matriz2[L][C]='2';
                Score++;break;
            case 3 : Matriz2[L][C]='3';
                Score++;break;
            case 4 : Matriz2[L][C]='4';
                Score++;break;
            case 5 : Matriz2[L][C]='5';
                Score++;break;
            case 6 : Matriz2[L][C]='6';
                Score++;break;
            case 7 : Matriz2[L][C]='7';
                Score++;break;
            case 8 : Matriz2[L][C]='8';
                if(cheat==1)
                {
                    Score=666;
                };break;
        }
        verificarMatriz3();
        i=verificarBombas();
        if(Matriz1[L][C]==9)
        {
            i=explodir();
        }
    }while(i==0);
    switch(i)
    {
        case 1 : fimDeJogo();break;
        case 2 : jogoGanho();break;
    }
}
void mostrarMatriz1()
{
    int x, y;
    for(x = 0; x < Linha; x++){
        for(y = 0; y < Coluna; y++) {
            printf("%d ",Matriz1[x][y]);
        }
        printf("\n");
    }
}
void mostrarMatriz2()
{
    int x,y;
    for(x=0;x<Linha;x++)
    {
        for(y=0;y<Coluna;y++)
        {
            printf("%c ",Matriz2[x][y]);
        }
        printf("\n");
    }
}
void main()
{
    int i=0;
    system("color 0F");
    inicio();
    do{
        Score=0;
        switch(menuPrincipal())
        {
            case 0:configuracoesDoJogo();break;
            case 2:Sair();break;
        }
        jogo();
    }while(Controle==1);
}
