#include <stdio.h>
#include <conio.c>
#define L 5
#define C 6
/*Fa�a um programa que preencha a matriz com os valores dados abaixo e com a
utiliza��o de comandos de repeti��o. A matriz deve ser declarada como vari�vel local deve ser
chamada uma fun��o para a atribui��o e apresentar o resultado no programa principal.
	0 1 2 3 4 5
	1 2 3 4 5 6
A = 2 3 4 5 6 7
	3 4 5 6 7 8
	4 5 6 7 8 9
*/
void preenche(int mat[L][C]){
	for(int i=0;i<L;i++){
		for(int j=0;j<C;j++){
			mat[i][j]=i+j;
		}
	}
}
main(){
	int mat[L][C];
	int i,j;
	printf("\n -Preenchendo os valores da matriz- \n");
	preenche(mat);		//L� os valores da matriz
	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			if(i==j){
				textcolor(4);
				printf(" %d ",mat[i][j]);	textcolor(7);
			}
			else
				printf(" %d ",mat[i][j]);
		}
		printf("\n");
	}
}
