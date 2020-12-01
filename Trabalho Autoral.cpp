/*
	Gabriel Gato Piragini Sant'Ana - número 07
				Turma 71A
	Trabalho Final - Técnicas de Programação
	
						CONSIDERAÇÕES
	Professora, gostaria, primeiramente de agradecer por tudo neste ano.
	Apesar de não ter sido presencial, este primeiro ano do Ensino Médio
	foi extremamente importante e definitivo, principalmente por, creio
	eu, ter me introduzido à minha atual paixão, a Programação.
	E, sem professores como você, do curso, nada disso seria possível.
	Foram vocês que me ensinaram o necessário, e propiciaram esta
	experiência a mim, dando-me estrutura para que eu possa evoluí-la.
	Sentirei muito a falta de vocês ano que vêm, e espero que dê tudo
	certo dentro do possível, ou até além dele.
	Sem mais, subscrevo-me. Obrigado por tudo.
	
*/
/*	
	TEMA : CORONAVIRUS
	ESCALA : PAISES
	NUMERO DE CASOS - NUMERO DE MORTOS - INVESTIMENTO NA SAUDE
	
*/
#include <stdio.h>		// Bibliotecas
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>		// Bibliotecas

#define preto textcolor(0);			//Definem a Paleta de cores
#define azulesc textcolor(1);		
#define verde textcolor(2);	
#define ciano textcolor(3);
#define vermelho textcolor(4);
#define roxo textcolor(5);
#define amarelo textcolor(6);
#define txtnormal textcolor(7);
#define cinza textcolor(8);
#define azulcla textcolor(9);	
#define verdeclaro textcolor(10);
#define cianoclaro textcolor(11);
#define vermelhoclaro textcolor(12);	
#define branco textcolor(15);		//Definem a Paleta de cores
using namespace std;

text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 35, 120, 1, 1};
void textcolor(int newcolor){
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0xf0) | newcolor);
   vActual.attribute = (csbi.wAttributes & 0xf0) | newcolor;
}
void textbackground(int newcolor){
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0x0f) | (newcolor << 4));
   vActual.attribute = (csbi.wAttributes & 0x0f) | (newcolor << 4);
}
void cursor (int x){ // mostra ou não o cursor do promp
	switch (x) {
		case 0: {//ocultar cursor
			CONSOLE_CURSOR_INFO cursor = {1, FALSE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
			break;
		}
		case 1: {//apresentar cursor
			CONSOLE_CURSOR_INFO cursor = {1, TRUE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
			break;
		}
	}
}
void gotoxy(int x, int y){
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void carrega(char letra,int c){ //função que simula uma tela de carregamento
	int x,y;
	int tempo;
	char slv=letra;
	if(c==0){
		system("cls");
		gotoxy(48,9);	cout<<"Carregando . . .";
	}
	else{
		gotoxy(48,9);	cout<<"Encerrando . . .";
	}
		
	for(int i=0;i<12;i++){
		if(i%2==0){
			letra=slv;	tempo=10;
		}
		else{
			letra=' ';	tempo=15;
		}
		x=51;	y=12;
		gotoxy(x,y);	cout<<letra;
		x+=2;	y--;	Sleep(tempo);
		gotoxy(x,y);	cout<<letra;
		Sleep(tempo);	x+=2;
		gotoxy(x,y);	cout<<letra;
		Sleep(tempo);	x+=2;
		gotoxy(x,y);	cout<<letra;
		y++;	x+=2;	Sleep(tempo);
		gotoxy(x,y); 	cout<<letra;
		x++;	y++;	Sleep(tempo);
		gotoxy(x,y); 	cout<<letra;
		y++;	Sleep(tempo);
		gotoxy(x,y);	cout<<letra;
		x--;	y++;	Sleep(tempo);
		gotoxy(x,y);	cout<<letra;
		x-=2;	y++;	Sleep(tempo);
		gotoxy(x,y);	cout<<letra;
		x-=2;	Sleep(tempo);
		gotoxy(x,y);	cout<<letra;
		x-=2;	Sleep(tempo);
		gotoxy(x,y);	cout<<letra;
		x-=2;	y--;	Sleep(tempo);
		gotoxy(x,y);	cout<<letra;
		x--;	y--;	Sleep(tempo);
		gotoxy(x,y);	cout<<letra;
		y--;	Sleep(tempo);
		gotoxy(x,y);	cout<<letra;
		x++;	y--;	Sleep(tempo);
		gotoxy(x,y);	cout<<letra;
	}
	system("cls");
}

void imprime_char(char c,int vzs){
	for(int i=0;i<vzs;i++)
		cout<<c;
}

void borda(){		// Função que imprime a borda do terminal
	textbackground(YELLOW);
	for(int i=0;i<36;i++){	// Borda do terminal
		gotoxy(0,i);	cout<<"  ";
		gotoxy(119,i);	cout<<"  ";
	}
	for(int j=0;j<121;j++ ){
		gotoxy(j,1);	cout<<" ";
	}
	
	textbackground(LIGHTBLUE);
	gotoxy(34,4);	imprime_char(' ',45);	//Imprime a moldura do menu
	gotoxy(34,26);	imprime_char(' ',45);
	for(int i=4;i<26;i++){
		gotoxy(34,i);	cout<<"  ";
		gotoxy(77,i);	cout<<"  ";
	}
	
	textbackground(BLUE);
}

void mostramatriz(){		// Mostra a tabela da matriz
	textcolor(LIGHTRED);	textbackground(WHITE);
	gotoxy(50,2); cout<<"TEMA - CORONAVIRUS";
	textbackground(BLUE);	textcolor(BLACK);
	for(int i=5;i<18;i++){	// Imprime as bordas da matriz
		gotoxy(27,i);	cout<<"|";
		gotoxy(98,i);	cout<<"|";
	}
	for(int co=7;co<16;co+=2){
		gotoxy(28,co);	imprime_char('-',70);
	}
	gotoxy(27,4);	imprime_char('_',72);
	gotoxy(28,17);	imprime_char('_',70);
	for(int i=5;i<18;i++){	// Imprime as linhas dentro da matriz
		gotoxy(49,i);	cout<<"|";
		gotoxy(71,i);	cout<<"|";
	}
	textcolor(LIGHTGRAY);
	gotoxy(31,5);	cout<<"Número de casos";
	gotoxy(32,6);	cout<<"(em milhões)";
	gotoxy(53,6);	cout<<"Número de mortos";
	gotoxy(75,5);	cout<<"Taxa de Investimento";
	gotoxy(74,6);	cout<<"em saúde (em % do PIB)";
}
void opc1(float matriz[5][3]);	// Mostra a matriz
void opc2(float matriz[5][3]);	// Média de investimento financeiro na saúde
void opc3(float matriz[5][3]);	// Média de casos, e qual país mais tem
void opc4(float matriz[5][3]);	// Média de mortos, e qual país mais tem
void opc5(float matriz[5][3]);	// Taxa de "letalidade"(n de casos/numero de mortos) e em qual país surtiu mais efeito.
void encerramento();	// Opção de encerrar o programa

main(){
	setlocale(LC_ALL,"Portuguese");
	char c;
	int lin=9;
	int sair;
		
	float matriz[5][3];
	// Define o numero de casos (em milhões)
	matriz[0][0]=5.748;
	matriz[1][0]=10.266;
	matriz[2][0]=1.881;
	matriz[3][0]=8.728;
	matriz[4][0]=1.862;
	// Define os números de mortos
	matriz[0][1]=163.373;
	matriz[1][1]=240.044;
	matriz[2][1]=32.443;
	matriz[3][1]=128.668;
	matriz[4][1]=42.628;
	// Define a taxa de investimento dos países
	matriz[0][2]=12.0;
	matriz[1][2]=17.0;
	matriz[2][2]=6.0;
	matriz[3][2]=4.0;
	matriz[4][2]=12.0;
	
	SetConsoleTitle("Trabalho Autoral - TP");
	system("mode con:cols=120 lines=35");
	
	branco
	textbackground(BLUE); // cor de fundo
	system("cls"); // limpar/pintar a tela	
	cursor(0);//ocultar cursor
	// Função que mostra a tela inicial, de carregamento
	carrega('·',0);
	system("cls");	borda();
	
	do{
		sair=1;
		branco	textbackground(BLUE);
		gotoxy(49,6);	cout<<"Menu de Opções";
		gotoxy(43,9);printf("Dados de cada país");
		gotoxy(43,12);printf("Média de investimento financeiro");
		gotoxy(43,13);printf("na saúde");
		gotoxy(43,15);printf("Média de casos de ");  verdeclaro;  cout<<"COVID-19";
		branco;
		gotoxy(43,18);printf("Média de mortos por ");  verdeclaro;  cout<<"COVID-19";
		branco;
		gotoxy(43,21);printf("Taxa de letalidade por país");
		gotoxy(43,24);printf("Sair");
		gotoxy(39,lin); printf("-%c", 62);//62 é o caractere '>'
		c=getch();
		gotoxy(39,lin); printf("  ");
	
		switch(c){	//movimento das setas
			case 72 : //seta para cima
				lin-=3;
				if(lin<9)
					lin=24;	
				gotoxy(39,lin); printf("-%c", 62);
				break;
			case 80 : //seta para baixo
				lin+=3;
				if(lin>24)
					lin=9;
				gotoxy(39,lin); printf("-%c", 62);
				break;
		}
		
		switch(c){	//Quando teclar enter para escolher opção
			case 13: //teclou enter
				if(lin==9)
					opc1(matriz);
				else if(lin==12)
					opc2(matriz);
				else if(lin==15)
					opc3(matriz);
				else if(lin==18)
					opc4(matriz);
				else if(lin==21)
					opc5(matriz);
				else if(lin==24){
					textbackground(BLUE);	system("cls");
					borda();	carrega('·',1);
					sair=0;
				}
		}

	}while(sair);
	gotoxy(49,12);	cout<<"Execução encerrada!";
	cursor(1);	Sleep(1700);
	gotoxy(1,32);
}

void opc1(float matriz[5][3]){		// Dados de cada país
	carrega('·',0);
	textcolor(LIGHTRED);	textbackground(WHITE);
	gotoxy(50,2); cout<<"TEMA - CORONAVIRUS";
	textbackground(BLUE);	textcolor(BLACK);
	int escolha;
	int a;
	do{
		system("cls");
		textcolor(LIGHTGRAY);
		gotoxy(8,6);	cout<<"1 - Tabela Geral";
		gotoxy(8,8);	cout<<"2 - Brasil";
		gotoxy(8,10);	cout<<"3 - Estados Unidos";
		gotoxy(8,12);	cout<<"4 - Rússia";
		gotoxy(8,14);	cout<<"5 - Índia";
		gotoxy(8,16);	cout<<"6 - França";
		gotoxy(8,18);	cout<<"7 - Sair";
		gotoxy(23,20);	cout<<"Qual a sua opção? ";
		cursor(1);	cin>>escolha;
		cursor(0);
		switch(escolha){
			case 1:
				mostramatriz();
				a=8;
				for(int x=0;x<5;x++){
					gotoxy(35,x+a);
					printf("%.3f",matriz[x][0]);
					a++;
				}
				a=8;
				for(int x=0;x<5;x++){
					gotoxy(57,x+a);
					printf("%.3f",matriz[x][1]);
					a++;
				}
				a=8;
				for(int x=0;x<5;x++){
					gotoxy(84,x+a);
					printf("%.0f",matriz[x][2]);
					a++;
				}
				gotoxy(36,23);	cout<<"Pressione qualquer tecla para prosseguir . . .";
				getch();	system("cls");
				break;
			case 2:
				textcolor(BLACK);
				for(int i=5;i<9;i++){	// Imprime as bordas da matriz
					gotoxy(27,i);	cout<<"|";
					gotoxy(98,i);	cout<<"|";
				}
				gotoxy(28,7);	imprime_char('-',70);
				
				for(int i=5;i<9;i++){	// Imprime as colunas dentro da matriz
					gotoxy(49,i);	cout<<"|";
					gotoxy(71,i);	cout<<"|";
				}
				gotoxy(27,4);	imprime_char('_',72);
				gotoxy(27,9);	imprime_char('¯',72);
				textcolor(LIGHTGRAY);
				gotoxy(31,5);	cout<<"Número de casos";
				gotoxy(32,6);	cout<<"(em milhões)";
				gotoxy(53,5);	cout<<"Número de mortos";
				gotoxy(75,5);	cout<<"Taxa de Investimento";
				gotoxy(74,6);	cout<<"em saúde (em % do PIB)";
				gotoxy(35,8);	cout<<matriz[0][0];
				gotoxy(57,8);	cout<<matriz[0][1];
				gotoxy(84,8);	cout<<matriz[0][2];
				gotoxy(36,23);	cout<<"Pressione qualquer tecla para prosseguir . . .";
				getch();	system("cls");
				break;
			case 3:
				textcolor(BLACK);
				for(int i=5;i<8;i++){	// Imprime as bordas da matriz
					gotoxy(27,i);	cout<<"|";
					gotoxy(98,i);	cout<<"|";
				}
				gotoxy(28,7);	imprime_char('_',70);
				gotoxy(27,4);	imprime_char('_',72);
				for(int i=5;i<8;i++){	// Imprime as colunas dentro da matriz
					gotoxy(49,i);	cout<<"|";
					gotoxy(71,i);	cout<<"|";
				}
				
				for(int i=7;i<12;i++){	// Imprime o entorno dos dados
					gotoxy(27,i);	cout<<"|";
					gotoxy(98,i);	cout<<"|";
				}
				gotoxy(27,8);	imprime_char('_',72);
				gotoxy(28,11);	imprime_char('_',70);
				for(int i=9;i<12;i++){
					gotoxy(49,i);	cout<<"|";
					gotoxy(71,i);	cout<<"|";
				}
				
				textcolor(LIGHTGRAY);
				gotoxy(31,5);	cout<<"Número de casos";
				gotoxy(32,6);	cout<<"(em milhões)";
				gotoxy(53,6);	cout<<"Número de mortos";
				gotoxy(75,5);	cout<<"Taxa de Investimento";
				gotoxy(74,6);	cout<<"em saúde (em % do PIB)";
				gotoxy(35,10);	cout<<matriz[1][0];
				gotoxy(57,10);	cout<<matriz[1][1];
				gotoxy(84,10);	cout<<matriz[1][2];
				
				gotoxy(36,23);	cout<<"Pressione qualquer tecla para prosseguir . . .";
				getch();	system("cls");
				break;
			case 4:
				textcolor(BLACK);
				for(int i=5;i<8;i++){	// Imprime as bordas da matriz
					gotoxy(27,i);	cout<<"|";
					gotoxy(98,i);	cout<<"|";
				}
				gotoxy(28,7);	imprime_char('_',70);
				gotoxy(27,4);	imprime_char('_',72);
				for(int i=5;i<8;i++){	// Imprime as colunas dentro da matriz
					gotoxy(49,i);	cout<<"|";
					gotoxy(71,i);	cout<<"|";
				}
				
				for(int i=11;i<14;i++){	// Imprime o entorno dos dados
					gotoxy(27,i);	cout<<"|";
					gotoxy(98,i);	cout<<"|";
				}
				gotoxy(27,10);	imprime_char('_',72);
				gotoxy(28,13);	imprime_char('_',70);
				for(int i=11;i<14;i++){
					gotoxy(49,i);	cout<<"|";
					gotoxy(71,i);	cout<<"|";
				}
				
				textcolor(LIGHTGRAY);
				gotoxy(31,5);	cout<<"Número de casos";
				gotoxy(32,6);	cout<<"(em milhões)";
				gotoxy(53,6);	cout<<"Número de mortos";
				gotoxy(75,5);	cout<<"Taxa de Investimento";
				gotoxy(74,6);	cout<<"em saúde (em % do PIB)";
				gotoxy(35,12);	cout<<matriz[2][0];
				gotoxy(57,12);	cout<<matriz[2][1];
				gotoxy(84,12);	cout<<matriz[2][2];
				
				gotoxy(36,23);	cout<<"Pressione qualquer tecla para prosseguir . . .";
				getch();	system("cls");
				break;
			case 5:
				textcolor(BLACK);
				for(int i=5;i<8;i++){	// Imprime as bordas da matriz
					gotoxy(27,i);	cout<<"|";
					gotoxy(98,i);	cout<<"|";
				}
				gotoxy(28,7);	imprime_char('_',70);
				gotoxy(27,4);	imprime_char('_',72);
				for(int i=5;i<8;i++){	// Imprime as colunas dentro da matriz
					gotoxy(49,i);	cout<<"|";
					gotoxy(71,i);	cout<<"|";
				}
				
				for(int i=12;i<16;i++){	// Imprime o entorno dos dados
					gotoxy(27,i);	cout<<"|";
					gotoxy(98,i);	cout<<"|";
				}
				gotoxy(27,12);	imprime_char('_',72);
				gotoxy(28,15);	imprime_char('_',70);
				for(int i=13;i<16;i++){
					gotoxy(49,i);	cout<<"|";
					gotoxy(71,i);	cout<<"|";
				}
				
				textcolor(LIGHTGRAY);
				gotoxy(31,5);	cout<<"Número de casos";
				gotoxy(32,6);	cout<<"(em milhões)";
				gotoxy(53,6);	cout<<"Número de mortos";
				gotoxy(75,5);	cout<<"Taxa de Investimento";
				gotoxy(74,6);	cout<<"em saúde (em % do PIB)";
				gotoxy(35,14);	cout<<matriz[3][0];
				gotoxy(57,14);	cout<<matriz[3][1];
				gotoxy(84,14);	cout<<matriz[3][2];
				
				gotoxy(36,23);	cout<<"Pressione qualquer tecla para prosseguir . . .";
				getch();	system("cls");
				break;
			case 6:
				textcolor(BLACK);
				for(int i=5;i<8;i++){	// Imprime as bordas da matriz
					gotoxy(27,i);	cout<<"|";
					gotoxy(98,i);	cout<<"|";
				}
				gotoxy(28,7);	imprime_char('_',70);
				gotoxy(27,4);	imprime_char('_',72);
				for(int i=5;i<8;i++){	// Imprime as colunas dentro da matriz
					gotoxy(49,i);	cout<<"|";
					gotoxy(71,i);	cout<<"|";
				}
				
				for(int i=15;i<18;i++){	// Imprime o entorno dos dados
					gotoxy(27,i);	cout<<"|";
					gotoxy(98,i);	cout<<"|";
				}
				gotoxy(27,14);	imprime_char('_',72);
				gotoxy(28,17);	imprime_char('_',70);
				for(int i=15;i<18;i++){
					gotoxy(49,i);	cout<<"|";
					gotoxy(71,i);	cout<<"|";
				}
				
				textcolor(LIGHTGRAY);
				gotoxy(31,5);	cout<<"Número de casos";
				gotoxy(32,6);	cout<<"(em milhões)";
				gotoxy(53,6);	cout<<"Número de mortos";
				gotoxy(75,5);	cout<<"Taxa de Investimento";
				gotoxy(74,6);	cout<<"em saúde (em % do PIB)";
				gotoxy(35,16);	cout<<matriz[4][0];
				gotoxy(57,16);	cout<<matriz[4][1];
				gotoxy(84,16);	cout<<matriz[4][2];
				
				gotoxy(36,23);	cout<<"Pressione qualquer tecla para prosseguir . . .";
				getch();	system("cls");
				break;
			case 7:
				break;
			default:
				gotoxy(50,11);	cout<<"Opção inválida!";
				Sleep(1450);
				gotoxy(50,11);	imprime_char(' ',20);
				break;
		}

	}while(escolha!=7);
	carrega('·',0);	 borda();
}

void opc2(float matriz[5][3]){		// Média de desenvolvimento de cada país
	int soma_investimento=0;
	carrega('·',0);
	textcolor(LIGHTRED);	textbackground(WHITE);
	gotoxy(53,2); cout<<"TEMA - CORONAVIRUS";
	textbackground(BLUE);	textcolor(BLACK);
	for(int i=5;i<19;i++){	// Imprime as bordas da matriz
		gotoxy(28,i);	cout<<"|";
		gotoxy(54,i);	cout<<"|";
	}
	for(int co=7;co<16;co+=2){
		gotoxy(29,co);	imprime_char('-',25);
	}
	gotoxy(28,4);	imprime_char('_',27);
	gotoxy(28,18);	imprime_char('¯',27);
	textcolor(LIGHTGRAY);
	gotoxy(32,5);cout<<"Taxa de Investimento";
	gotoxy(31,6);cout<<"em saúde (em % do PIB)";
	
	gotoxy(11,8);	cout<<"Brasil";
	gotoxy(11,10);	cout<<"Estados Unidos";
	gotoxy(11,12);	cout<<"Rússia";
	gotoxy(11,14);	cout<<"Índia";
	gotoxy(11,16);	cout<<"França";
	int a=8;
	for(int x=0;x<5;x++){
		gotoxy(40,x+a);
		printf("%.0f",matriz[x][2]);
		soma_investimento+=matriz[x][2];
		a++;
	}
	gotoxy(64,8);printf("A média de investimentos na saude é de %.1f %% .",soma_investimento/5.0);
	gotoxy(65,10);cout<<"Isso faz com que os países acima da média";
	gotoxy(68,11);cout<<"sejam os Estados Unidos e o Brasil.";
	
	gotoxy(36,21);	cout<<"Pressione qualquer tecla para prosseguir . . .";
	getch();
	system("cls");
	borda();
}

void opc3(float matriz[5][3]){
	float soma_casos=0;
	carrega('·',0);
	textcolor(LIGHTRED);	textbackground(WHITE);
	gotoxy(53,2); cout<<"TEMA - CORONAVIRUS";
	textbackground(BLUE);	textcolor(BLACK);
	for(int i=5;i<19;i++){	// Imprime as bordas da matriz
		gotoxy(28,i);	cout<<"|";
		gotoxy(54,i);	cout<<"|";
	}
	for(int co=7;co<16;co+=2){
		gotoxy(29,co);	imprime_char('-',25);
	}
	gotoxy(28,4);	imprime_char('_',27);
	gotoxy(28,18);	imprime_char('¯',27);
	textcolor(LIGHTGRAY);
	gotoxy(31,5);cout<<"Número de casos de";
	gotoxy(33,6);verdeclaro	cout<<"COVID-19";	
	textcolor(7);cout<<" (em milhões)";
	
	gotoxy(11,8);	cout<<"Brasil";
	gotoxy(11,10);	cout<<"Estados Unidos";
	gotoxy(11,12);	cout<<"Rússia";
	gotoxy(11,14);	cout<<"Índia";
	gotoxy(11,16);	cout<<"França";
	int a=8;
	for(int x=0;x<5;x++){
		gotoxy(38,x+a);
		printf("%.3f",matriz[x][0]);
		soma_casos+=matriz[x][0];
		a++;
	}
	gotoxy(65,8);printf("A média de casos de COVID-19 para os");
	gotoxy(68,9);printf("países listados é de %.3f",soma_casos/5.0);
	gotoxy(67,12);cout<<"Isso faz com que Rússia e França";
	gotoxy(71,13);cout<<"estejam abaixo da média.";
	
	
	gotoxy(36,21);	cout<<"Pressione qualquer tecla para prosseguir . . .";
	getch();
	system("cls");
	borda();
}

void opc4(float matriz[5][3]){
	float soma_casos=0;
	carrega('·',0);
	textcolor(LIGHTRED);	textbackground(WHITE);
	gotoxy(53,2); cout<<"TEMA - CORONAVIRUS";
	textbackground(BLUE);	textcolor(BLACK);
	for(int i=5;i<19;i++){	// Imprime as bordas da matriz
		gotoxy(28,i);	cout<<"|";
		gotoxy(53,i);	cout<<"|";
	}
	for(int co=7;co<16;co+=2){
		gotoxy(29,co);	imprime_char('-',24);
	}
	gotoxy(28,4);	imprime_char('_',26);
	gotoxy(28,18);	imprime_char('¯',26);
	textcolor(LIGHTGRAY);
	gotoxy(33,5);cout<<"Número de mortes";
	gotoxy(36,6);cout<<"de ";	verdeclaro
	cout<<"COVID-19";	textcolor(7);
	
	gotoxy(11,8);	cout<<"Brasil";
	gotoxy(11,10);	cout<<"Estados Unidos";
	gotoxy(11,12);	cout<<"Rússia";
	gotoxy(11,14);	cout<<"Índia";
	gotoxy(11,16);	cout<<"França";
	int a=8;
	for(int x=0;x<5;x++){
		gotoxy(38,x+a);
		printf("%.3f",matriz[x][1]);
		soma_casos+=matriz[x][1];
		a++;
	}
	gotoxy(63,9);printf("A média de mortes de COVID-19 é de %.3f",soma_casos/5.0);
	gotoxy(71,10);cout<<"para os países listados.";
	gotoxy(63,12);cout<<"Isso faz com que apenas França e Rússia";
	gotoxy(70,13);cout<<"estejam abaixo da média.";
	
	
	gotoxy(36,21);	cout<<"Pressione qualquer tecla para prosseguir . . .";
	getch();
	system("cls");
	borda();
}

void opc5(float matriz[5][3]){
	float taxa=0;
	float maior_taxa,menor_taxa;
	carrega('·',0);
	textcolor(LIGHTRED);	textbackground(WHITE);
	gotoxy(53,2); cout<<"TEMA - CORONAVIRUS";
	textbackground(BLUE);	textcolor(BLACK);
	for(int i=5;i<18;i++){	// Imprime as bordas da matriz
		gotoxy(27,i);	cout<<"|";
		gotoxy(66,i);	cout<<"|";
	}
	for(int co=7;co<16;co+=2){
		gotoxy(28,co);	imprime_char('-',38);
	}
	gotoxy(27,4);	imprime_char('_',40);
	gotoxy(27,18);	imprime_char('¯',40);
	textcolor(LIGHTGRAY);
	gotoxy(30,5);cout<<"Taxa de letalidade (%) de ";   verdeclaro  cout<<"COVID-19";  textcolor(7);
	gotoxy(31,6);cout<<"(num. de casos / num. de mortos)";
	
	gotoxy(10,8);	cout<<"Brasil";
	gotoxy(10,10);	cout<<"Estados Unidos";
	gotoxy(10,12);	cout<<"Rússia";
	gotoxy(10,14);	cout<<"Índia";
	gotoxy(10,16);	cout<<"França";
	int a=8;
	for(int x=0;x<5;x++){
		gotoxy(44,x+a);
		taxa = matriz[x][0]/matriz[x][1];
		if(x==0){
			maior_taxa=taxa;
			menor_taxa=taxa;
		}
		else{
			if(taxa>maior_taxa)
				maior_taxa=taxa;
			if(taxa<menor_taxa)
				menor_taxa=taxa;
		}
		printf("%.3f",taxa);
		//soma_casos+=matriz[x][1];
		a++;
	}
	gotoxy(69,9);printf("O país com a maior taxa de letalidade por COVID-19");
	gotoxy(74,10);printf("é a Índia, onde cerca de %.3f%% dos casos",maior_taxa);
	gotoxy(84,11);printf("resultam em morte.");
	gotoxy(71,13);cout<<"Por outro lado, a França é aquele com a menor,";
	gotoxy(79,14);printf("onde apenas cerca de %.3f%% dos",menor_taxa);
	gotoxy(80,15);printf("enfermos chegam a falecer.");
	
	gotoxy(36,21);	cout<<"Pressione qualquer tecla para prosseguir . . .";
	getch();
	system("cls");
	borda();
}
