#include <stdio.h>
#include <conio.c>
#include <stdlib.h>
#include <time.h>
#define L 2
#define C 2
/*Fazer um programa que leia duas matrizes de dimensão 2x2. Calcule e apresente
as duas matrizes e a matriz diferença. Faça utilizando função para ler e apresentar. */
void leitura(int mat[L][C]){
	for(int i=0;i<L;i++)
		for(int j=0;j<C;j++){
			printf("Digite o valor da casa [%d][%d]: ",i,j);
			scanf("%d",&mat[i][j]);
		}
}
void mostra(int mat[L][C]){
	for(int i=0;i<L;i++){
		for(int j=0;j<C;j++)
			printf(" %d ",mat[i][j]);
		printf("\n");
	}
}
main(){
	srand(time(NULL));
	int mat1[L][C];
	int mat2[L][C];
	int matdiferenca[L][C];
	printf(" -Lendo os valores das matrizes- \n");
	printf(" Matriz 1: \n");	leitura(mat1);		//Lê os valores da matriz 1
	printf(" Matriz 2: \n");	leitura(mat2);		//Lê os valores da matriz 2
	printf("\n -Apresentando os valores das matrizes- \n");
	printf(" Matriz 1: \n");	mostra(mat1);
	printf("\n Matriz 2:\n");		mostra(mat2);
	for(int i=0;i<L;i++)
		for(int j=0;j<C;j++)
			matdiferenca[i][j] = mat1[i][j] - mat2[i][j];
	printf("\n Matriz Soma:\n");	mostra(matdiferenca);
}
