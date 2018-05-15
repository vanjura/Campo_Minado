#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.c>

int Matriz1[20][21], Linha, Coluna, Bombas=-1,Controle=1,Score=0,cheat=0;
char Matriz2[20][20],Matriz3[20][20];
void inicio()
{
    int i;
    system("cls");
    int z=219,x,y;
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
    };
    printf("\n\n");
    for(x=0;x<15;x++)
    {
        printf("\t");
        for(y=0;y<62;y++)
        {
            printf("%c",game[x][y]);
        }
        printf("\n");
    }
    printf("\n\n\t\t   Pressione qualquer tecla para iniciar.");
    i=getch();
}
void regras()
{
    int i;
    do{
        system("cls");
        printf("\n\n\tREGRAS:\n");
        printf("\tO Campo Minado e um jogo aparentemente simples de\n");
        printf("\tmemoria e raciocinio. O objetivo do Campo Minado \n");
        printf("\te revelar os quadrados vazios e com numeros, evi-\n");
        printf("\tando aqueles que escondem bombas.               \n");
        printf("\n\tEnter para voltar.");
        i=getch();
    }while(i!=13);
}
void menuPrincipal()
{
    int Op,x,y,z=7,c;
    do{
        system("cls");
        printf("\n\n\t%c",201);
        for(x=0;x<60;x++)
        {
            printf("%c",205);
        }
        printf("%c",187);
        printf("\n\t%c                       MENU PRINCIPAL                       %c\n",186,186);
        printf("\t%c",204);
        for(x=0;x<60;x++)
        {
            printf("%c",205);
        }
        printf("%c\n",185);
        printf("\t%c",186);
        for(x=0;x<60;x++)
        {
            printf(" ");
        }
        printf("%c\n",186);
        printf("\t%c         Jogar                                              %c\n",186,186);
        printf("\t%c         Regras                                             %c\n",186,186);
        printf("\t%c         Sair                                               %c\n",186,186);
        printf("\t%c",186);
        for(x=0;x<60;x++)
        {
            printf(" ");
        }
        printf("%c\n",186);
        printf("\t%c",186);
        for(x=0;x<60;x++)
        {
            printf(" ");
        }
        printf("%c\n",186);
        printf("\t%c",186);
        for(x=0;x<60;x++)
        {
            printf(" ");
        }
        printf("%c\n",186);
        printf("\t%c",200);
        for(x=0;x<60;x++)
        {
            printf("%c",205);
        }
        printf("%c\n",188);
        do{
            gotoxy(18,z);
            c=getch();
            switch(c)
            {
                case 80 : z++;
                if(z==10)
                {
                    z--;
                };break;
                case 72 : z--;
                if(z==6)
                {
                    z++;
                };break;
            }
        }while(c!=13);
        switch(z)
        {
            case 7 : Op=1;break;
            case 8 : regras();break;
            case 9 : Sair();break;
        }
    }while(Op!=1);
}
void configuracoesDoJogo()
{
    int dificuldade,R=1;
    char dif[10];
    do{
        do{
            system("cls");
            printf("\n\n\tInforme a quantidade de linhas (4 ate 20):");
            scanf("%d",&Linha);
            if(Linha<4)
            {
                printf("\n\n\tO minimo para as linhas eh 4.\n\n\n\t");
                system("pause");
            }
            else if(Linha>20)
            {
                printf("\n\n\tO maximo para as linhas eh 20.\n\n\n\t");
                system("pause");
            }
        }while(Linha<4 || Linha>20);
        do{
            system("cls");
            printf("\n\n\tLinhas: %d\n",Linha);
            printf("\tInforme a quantidade de colunas (4 ate 20):");
            scanf("%d",&Coluna);
            if(Coluna<4)
            {
                printf("\n\n\tO minimo para as colunas eh 4.\n\n\n\t");
                system("pause");
            }
            else if(Coluna>20)
            {
                printf("\n\n\tO maximo para as colunas eh 20.\n\n\n\t");
                system("pause");
            }
        }while(Coluna<4 || Coluna>20);
        do{
            system("cls");
            printf("\n\n\tLinhas: %d\n",Linha);
            printf("\tColunas: %d\n\n",Coluna);
            printf("\tEscolha a dificuldade:\n");
            printf("\t1. Facil\n");
            printf("\t2. Medio\n");
            printf("\t3. Dificil\n");
            printf("\t4. Infernal\n");
            printf("\tInsira o numero respectivo:");
            scanf("%d",&dificuldade);
            switch(dificuldade)
            {
                case 1 : Bombas=(((float)Linha*(float)Coluna)/100.0)*10+1;
                    strcpy(dif, "Facil");break;
                case 2 : Bombas=(((float)Linha*(float)Coluna)/100.0)*15+1;
                    strcpy(dif, "Medio");break;
                case 3 : Bombas=(((float)Linha*(float)Coluna)/100.0)*20+1;
                    strcpy(dif, "Dificil");break;
                case 4 : Bombas=(((float)Linha*(float)Coluna)/100.0)*40+1;
                    strcpy(dif, "Infernal");break;
                case 666 : Linha= 20;
                    Coluna= 20;
                    Bombas=399;
                    cheat=1;
                    strcpy(dif, "666 FROM HELL");break;
                case 999 : Linha= 20;
                    Coluna= 20;
                    Bombas=1;
                    cheat=1;
                    strcpy(dif, "Bebe Chorao");break;
                default : system("cls");
                    printf("\n\n\tDificuldade invalida.\n\n\t");
                    system("pause");
            }
        }while(Bombas<0);
        system("cls");
        printf("\n\n\tLinhas: %d\n",Linha);
        printf("\tColunas: %d\n",Coluna);
        printf("\tDificuldade: %s\n\n",dif);
        printf("\tVoce aceita jogar com esse valores?\n");
        printf("\t0. Sim\n");
        printf("\t1. Nao\n");
        printf("\tInsira o valor respectivo:");
        scanf("%d",&R);
    }while(R==1);
}
void zerarMatrizes()
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
    char Letras=65;
    int x,y;
    printf("\n\n\tScore: %d\n\n\t",Score);
    for(x=0;x<Coluna;x++)
    {
        printf("%c ",Letras);
        Letras++;
    }
    printf("\n");
    for(x=0;x<Linha;x++)
    {
        printf("    %d \t",x+1);
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
    int l,L,C,i=0;
    char c;
    zerarMatrizes();
    randomMatriz();
    verificarMatriz1();
    reiniciarCantos();
    do{
        do{
            system("cls");
            mostrarMatriz3();
            printf("\n\t>Informe um valor negativo na LINHA para fechar o jogo<",Linha);
            printf("\n\tInforme a LINHA (1 a %d)",Linha);
            scanf("%d",&l);
            L=l-1;
            printf("\tInforme a COLUNA (A a %c)",Coluna+64);
            scanf("%s",&c);
            c=toupper(c);
            C=c-65;
            if(L<0)
            {
                Sair();
            }
        }while(L<0 || L>Linha || C<0 || C>Coluna);
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
    int x,y;
    for(x=0;x<Linha;x++)
    {
        for(y=0;y<Coluna;y++)
        {
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
    inicio();
    do{
        Score=0;
        menuPrincipal();
        configuracoesDoJogo();
        jogo();
    }while(Controle==1);
}
