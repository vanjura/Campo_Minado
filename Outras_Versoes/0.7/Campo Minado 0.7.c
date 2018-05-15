//Trabalho interdiciplinar de Linguagem De Programação e Algoritmos
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

struct sRank
{
    char nick[3];
    int pontos;
}rank[100];
struct tRank
{
    char R[6];
}T[100];



int Matriz1[20][21], Linha=4, pLinha, Coluna=4, pColuna, Bombas=-1,Controle=1,Score=0,cheat=0;
char Matriz2[20][20],Matriz3[20][20],usuario[5];
void colocarCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, TRUE};//Struct do windows para modificar configurações do cursor.TRUE ativa o cursor e FALSE desativa;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void removerCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void inicio(){
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
    for(x=0;x<15;x++){
        printf("\t\t\t\t\t\t");
        for(y=0;y<62;y++){
            printf("%c",game[x][y]);
        }
        printf("\n");
    }//comando de for para motrar a matriz.
    printf("\n\n\n\t\t\t\t\t\t\t    Pressione qualquer tecla para iniciar.");
    i=getch();//reconhece qualquer tecla e pula para a proxima tela
}
void regras(){
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
void pulaLinhaBonitinho( linhasAntes )//pequeno procedimento para pular linhas antes de criar um menu (somente questão gráfica, não muda o funcionamento do jogo);
{
    int i = 0;
    do{
        printf( " \n");
        i++;
    }while( i <= linhasAntes );
}
void tabulacaoBonitinha( tabulacao, ajuste )//Mesmo intuito do procedimento anterior só que com tabulação;
{
    int i = 0;
    do{
        i++;
        printf( "\t" );
    }while( i < tabulacao );
    i = 0;
    while( i < ajuste ){
        i++;
        printf( " " );
    }
}
void menuBonitinho( xColunas, yLinhas, cabecalho, linhasAntes, tabulacao, ajuste )//procedmento para criar uma área para menus, as opções dos menus são incluidas através de gotoxy()
{//tamanho(Colunas, Linhas, Cabeçalho, Linhas_Antes_De_Imprimir, Tabulação, Ajuste);
    int m, n, i = 0;
    pulaLinhaBonitinho( linhasAntes );//chama um procedimento que pular uma quantidade prédeterminada de linhas;
    tabulacaoBonitinha( tabulacao, ajuste );//chama um procedimento capaz de organizar a tabulação com controle de linhas;
    printf( "%c", 201 );//inprime o canto;
    for( m = 0; m < xColunas; m++ )//faz a linha superior;
    {
        printf( "%c", 205 );
    }
    printf( "%c", 187 );//imprime o canto superior direito;
    if(cabecalho != 0 ){//caso precise esse codigo pode fazer um cabeçalho para um nome de menu por exemplo;
        do{
            printf( "\n" );
            tabulacaoBonitinha( tabulacao, ajuste );// usa a mesma tabulação para que o menu fique correto;
            printf( "%c", 186 );//linha vertical
            for( m = 0; m < xColunas; m++ ){//parte nula para escrita do cabeçalho;
                printf( " " );
            }
            printf( "%c", 186 );
            i++;
        }while( cabecalho > i );//pode-se escolher o numero de linhas que o cabeçalho deverá ter;
        printf( "\n" );
        tabulacaoBonitinha( tabulacao, ajuste );
        printf( "%c", 204 );
        for( m = 0; m < xColunas; m++ ){
            printf( "%c", 205 );
        }
        printf( "%c", 185 );
    }
    i=0;
    do{
        printf( "\n" );
        tabulacaoBonitinha( tabulacao, ajuste );
        printf( "%c", 186 );
        for( m = 0; m < xColunas; m++ ){
            printf( " " );
        }
        printf( "%c", 186 );
        i++;
    }while( yLinhas > i );
    printf( "\n" );
    tabulacaoBonitinha( tabulacao, ajuste );
    printf( "%c", 200 );
    for( m = 0; m < xColunas; m++ ){
        printf( "%c", 205 );
    }
    printf( "%c", 188 );
}

void salvarScore()
{
    arq = fopen("Rank.txt", "a");
    fputs(usuario,arq);
    fprintf(arq,"\n");
    fclose(arq);
}

void Rank()
{
    system("cls");
    int letra=65,tecla,i,s1,s2,s3;
    for(i=0;i<=2;i++){
        gotoxy(i+10,10);
        do{
            printf("%c\b",letra);
            tecla = getch();
            switch(tecla)
            {
                case 80: letra--;
                if(letra<65){
                    letra=90;
                }break;
                case 72: letra++;
                if(letra>90){
                    letra=65;
                }break;
            }
        }while(tecla!=13);
        usuario[i]=letra;
    }
    s1=Score/100;
    s2=(Score%100)/10;
    s3=(Score%100)%10;
    usuario[3]=s1+48;
    usuario[4]=s2+48;
    usuario[5]=s3+48;
    salvarScore();
}
void calcularRank()
{
    system("cls");
    int x,y,vPontos[10],g[10];
    char vNick[3];
    for(x=0;x<10;x++)
    {
        vPontos[x]=0;
    }
    menuBonitinho(62,15,1,9,6,0);
    gotoxy(1,17);
    for(x=0;x<10;x++)
    {

        for(y=0;y<100;y++)
        {
            if(g[0]!=y && g[1]!=y && g[2]!=y && g[3]!=y && g[4]!=y && g[5]!=y && g[6]!=y && g[7]!=y && g[8]!=y && g[9]!=y){
                if(rank[y].pontos>vPontos[x] && rank[y].pontos<=vPontos[x-1])
                {
                    vPontos[x]=rank[y].pontos;
                    strncpy(vNick,rank[y].nick,3);
                    g[x]=y;
                }
            }
        }
        tabulacaoBonitinha(8,0);
        printf("%d%c",x+1,167);
        if(x==9)
        {
            printf("\b");
        }
        printf("   %c   %c",186,vNick[0]);
        printf("%c",vNick[1]);
        printf("%c",vNick[2]);
        printf("   %c   %d\n",186,vPontos[x]);
    }
    getch();
}
void lerScore()
{
    int i,j,p1,p2,p3,total;
    char x[3];
    arq = fopen("Rank.txt", "r");
    for(j=0;j<100;j++){
        for(i=0;i<6;i++)
        {
            T[j].R[i]=fgetc(arq);
        }
        x[0]=fgetc(arq);
    }
    for(i=0;i<100;i++){
        rank[i].nick[0]=T[i].R[0];
        rank[i].nick[1]=T[i].R[1];
        rank[i].nick[2]=T[i].R[2];
        p1=T[i].R[3]-48;
        p2=T[i].R[4]-48;
        p3=T[i].R[5]-48;
        total=(p1*100)+(p2*10)+p3;
        rank[i].pontos=total;
    }
    calcularRank();
}
int menuPrincipal()
{
    removerCursor();//remove o cursor por questão gráfica;
    int Op,x,y,z=16,c;//variáveis de controle indispensáveis para o funcionamento do menu
    do{
        system("cls");
        menuBonitinho(62,15,1,9,6,0);
        gotoxy(31,12);//gotoxy será usado varias vezes por questão grafica e funcional;
        tabulacaoBonitinha(6,1);
        printf("MENU PRINCIPAL");
        gotoxy(60,16);
        printf("Jogar");
        gotoxy(60,17);
        printf("Tutorial");
        gotoxy(60,18);
        printf("Ranking");
        gotoxy(60,19);
        printf("Sair");
        do{ //codigo para o funcionamento das teclas up e down para controle do menu;
            gotoxy(60,z);
            textbackground(WHITE);
            textcolor(0);
            switch(z)
            {
                case 16 : printf("JOGAR\b\b\b\b\b");break; //O \b faz com que o cursor volte algumas linhas para ficar logo acima da primeira linha da escrita, desse modo pode-se apagar facimente o que está escrito dando o efeito de seleção quando usado com um textbackground();
                case 17 : printf("TUTORIAL\b\b\b\b\b\b\b\b");break;
                case 18 : printf("RANKING\b\b\b\b\b\b\b");break;
                case 19 : printf("SAIR\b\b\b\b");break;
            }
            textbackground(0);
            textcolor(WHITE);
            c=getch();
            switch(z)
                {
                    case 16 : printf("Jogar");break;//imprime novamente a escrita antiga dando o efeito de DesSeleção;
                    case 17 : printf("Tutorial");break;
                    case 18 : printf("Ranking");break;
                    case 19 : printf("Sair");break;
                }
            switch(c)
            {
                case 80 ://caso aperte a seta para baixo;
                z++;
                if(z==20)
                {
                    z=16;
                };break;
                case 72 ://caso aperte a seta para cima
                z--;
                if(z==15)
                {
                    z=19;
                };break;
            }
        }while(c!=13);//quando a tecla enter for precionada, a opção é selecionada;
        switch(z)
        {
            case 16 : Op=0;break;
            case 17 : Op=1;
                regras();break;
            case 18 : Op=1;
                lerScore();break;
            case 19 : Op=2;break;
        }
    }while(Op==1);
    return Op;//retorna a opção escolhida para um switch case;
}
void configuracoesDoJogo()
{
    textcolor(15);
    int dificuldade,R=1,z=17,c,tecla;//variaveis para a configuração do jogo;
    char dif[10];
    do{
        system("cls");
        menuBonitinho(62,15,1,9,6,0);//tamanho(Colunas, Linhas, Cabeçalho, Linhas_Antes_De_Imprimir, Tabulação, Ajuste);
        gotoxy(1,12);
        tabulacaoBonitinha(8,3);
        printf("CONFIGURACOES DO JOGO");
        pulaLinhaBonitinho(15);
        tabulacaoBonitinha(6,0);
        printf("%c Use as setas do teclado para selecionar a opcao desejada.",186);
        gotoxy(51,14);
        printf("Quantidade de linhas: ");
        do{
            printf("%d ",Linha);
            gotoxy(73,14);
            tecla=getch();
            switch(tecla){
                case 80 : Linha--;
                if(Linha<=3){
                    Linha++;
                };break;
                case 72: Linha++;
                if(Linha>=21){
                    Linha--;
                };break;
            }
        }while(tecla!=13);
        gotoxy(51,14);
        printf("Linhas: %d              ",Linha);
        gotoxy(51,15);
        printf("Quantidade de colunas: ");
        do{
            printf("%d ",Coluna);
            gotoxy(74,15);
            tecla=getch();
            switch(tecla){
                case 80 : Coluna--;
                if(Coluna<=3){
                    Coluna++;
                };break;
                case 72: Coluna++;
                if(Coluna>=21){
                    Coluna--;
                };break;
            }
        }while(tecla!=13);
        do{
            gotoxy(51,15);
            printf("Colunas: %d              ",Coluna);
            gotoxy(51,16);
            printf("Escolha a dificuldade:");
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
            Matriz3[x][y]=254;
        }
    }
}
void mostrarMatriz3()
{
    int x,y,i=0;
    printf("\n");
    tabulacaoBonitinha(1,0);
    printf("%c",201);
    for(x=0;x<Coluna*2+1;x++){
        printf("%c",205);
    }
    printf("%c\n",187);
    for(x=0;x<Linha;x++)
    {
        tabulacaoBonitinha(1,0);
        printf("%c ",186);
        for(y=0;y<Coluna;y++)
        {
            textcolor(8);
            switch(Matriz3[x][y]){
                case vazio : textcolor(corVazio);break;
                case '1' : textcolor(cor1);break;
                case '2' : textcolor(cor2);break;
                case '3' : textcolor(cor3);break;
                case '4' : textcolor(cor4);break;
                case '5' : textcolor(cor5);break;
                case '6' : textcolor(cor6);break;
                case '7' : textcolor(cor7);break;
                case '8' : textcolor(cor8);break;
                case bomba : textcolor(corBomba);break;
            }
            printf("%c ",Matriz3[x][y]);
            textcolor(15);
//            textcolor(8);
//            printf("%c ",Matriz3[x][y]);
//            textcolor(15);
        }
        printf("%c",186);
        printf("\n");
    }
    tabulacaoBonitinha(1,0);
    printf("%c",200);
    for(x=0;x<Coluna*2+1;x++){
        printf("%c",205);
    }
    printf("%c\n",188);
    gotoxy(9,1);
    printf("Score: %d",Score);
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
                case '0': Matriz3[x][y]=vazio;break;
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
                case 0 : Matriz3[x][y]=vazio;break;
                case 1 : Matriz3[x][y]='1';break;
                case 2 : Matriz3[x][y]='2';break;
                case 3 : Matriz3[x][y]='3';break;
                case 4 : Matriz3[x][y]='4';break;
                case 5 : Matriz3[x][y]='5';break;
                case 6 : Matriz3[x][y]='6';break;
                case 7 : Matriz3[x][y]='7';break;
                case 8 : Matriz3[x][y]='8';break;
                case 9 : Matriz3[x][y]=bomba;break;
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
    int z=219,x,y,i=18,tecla;
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
    for(x=0;x<6;x++)
    {
        tabulacaoBonitinha(5,0);
        for(y=0;y<89;y++)
        {
            printf("%c",game[x][y]);
        }
        printf("\n");
    }
    pulaLinhaBonitinho(2);
    tabulacaoBonitinha(6,0);
    printf("Salvar pontuacao?\n");
    tabulacaoBonitinha(6,0);
    printf("Sim\n");
    tabulacaoBonitinha(6,0);
    printf("Nao");
    do{
        do{
            gotoxy(49,i);
            textbackground(RED);
            textcolor(0);
            switch(i)
            {
                case 18 : printf("SIM");break;
                case 19 : printf("NAO");break;
            }
            textbackground(0);
            textcolor(RED);
            tecla=getch();
            switch(i)
            {
                case 18 : printf("\b\b\bSim");break;
                case 19 : printf("\b\b\bNao");break;
            }
            switch(tecla)
            {
                case 80 : i++;
                if(i>19)
                {
                    i=18;
                };break;
                case 72 : i--;
                if(i<18)
                {
                    i=19;
                };break;
            }
        }while(tecla!=13);
        if(i==18){
            system("color 0F");
            Rank();
            Controle=1;
        }else{
            system("color 0F");
            Controle=1;
        }
    }while(Controle!=1);
}
void fimDeJogo()
{
    explodir();
    mostrarMatriz3();
    gotoxy(21,1);
    textcolor(RED);
    printf("Perdeu!");
    getch();
    GAMEOVER();
}
void GANHOU()
{
    system("color 02");
    Controle=0;
    int z=219,x,y,i=18,tecla;
    char game[6][61]={
        z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,z,z,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,0,z,z,0,0,0,0,0,0,z,z,
        z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,z,z,0,0,0,0,z,z,
        0,0,z,z,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,0,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,
        0,0,0,0,z,z,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,0,0,z,z,
        0,0,0,0,z,z,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,0,0,0,0,0,0,z,z,0,0,0,z,z,z,z,0,0,z,z,z,z,0,0,z,z,0,0,z,z,0,0,0,0,z,z,z,z,
        0,0,0,0,z,z,0,0,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,0,z,z,z,z,z,z,0,0,0,0,0,z,z,0,0,0,0,0,0,z,z,0,z,z,z,z,0,z,z,0,0,0,0,0,0,z,z,
    };
    system("cls");
    pulaLinhaBonitinho(6);
    for(x=0;x<6;x++)
    {
        tabulacaoBonitinha(5,6);
        for(y=0;y<61;y++)
        {
            printf("%c",game[x][y]);
        }
        printf("\n");
    }
    pulaLinhaBonitinho(2);
    tabulacaoBonitinha(6,0);
    printf("Voltar ao Menu? (Caso selecionar nao o jogo sera fechado)\n");
    tabulacaoBonitinha(6,0);
    printf("Sim\n");
    tabulacaoBonitinha(6,0);
    printf("Nao");
    do{
        do{
            gotoxy(49,i);
            textbackground(GREEN);
            textcolor(0);
            switch(i)
            {
                case 18 : printf("SIM");break;
                case 19 : printf("NAO");break;
            }
            textbackground(0);
            textcolor(GREEN);
            tecla=getch();
            switch(i)
            {
                case 18 : printf("\b\b\bSim");break;
                case 19 : printf("\b\b\bNao");break;
            }
            switch(tecla)
            {
                case 80 : i++;
                if(i>19)
                {
                    i=18;
                };break;
                case 72 : i--;
                if(i<18)
                {
                    i=19;
                };break;
            }
        }while(tecla!=13);
        if(i==18){
            system("color 0F");
            Rank();
            Controle=1;
        }else{
            system("color 0F");
            Controle=1;
        }
    }while(Controle!=1);
    system("color 0F");
}
void jogoGanho()
{
    system("cls");
    explodir();
    mostrarMatriz3();
    gotoxy(21,1);
    textcolor(GREEN);
    printf("Jogo Ganho!");
    textcolor(15);
    getch();
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
    int l,L=0,C=0,i=0,posLinha=3,posColuna=11,v;
    char c;
    zerarMatrizes();
    randomMatriz();
    verificarMatriz1();
    reiniciarCantos();
    do{
       system("cls");
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
           switch(Matriz1[L][C])
           {
               case 0 : zero(L,C);break;
               case 1 : Matriz2[L][C]='1';
                   Score++;break;
               case 2 : Matriz2[L][C]='2';
                   Score++;break;
               case 3 : Matriz2[L][C]='3';
                   Score++;if(cheat==1)
                   {
                       Score=666;
                   };break;
               case 4 : Matriz2[L][C]='4';
                   Score++;break;
               case 5 : Matriz2[L][C]='5';
                   Score++;
                   if(cheat==1)
                   {
                       Score=666;
                   };break;
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
       }
    } while(i==0);
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
void fullScreen()
{
    keybd_event(VK_MENU  , 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1C, 0, 0);
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU  , 0x38, KEYEVENTF_KEYUP, 0);
}
void main()
{
    fullScreen();
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
        cheat=0;
    }while(Controle==1);
}
