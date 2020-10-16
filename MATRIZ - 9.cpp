//Dale Mari
#include <stdio.h>
#include <conio.c>
#include <stdlib.h>
#include <time.h>
#define L 5
#define C 3
void sorteia(int mat[L][C]){
	//int sorteio;
	for(int i=0;i<L;i++)
		for(int j=0;j<C;j++){
			/*sorteio=rand()%2;
			if(sorteio%2==0)
				mat[i][j]=rand()%-10;
			else*/
				mat[i][j]=rand()%10;
		}
}
void mostra(int mat[L][C]){
	for(int i=0;i<L;i++){
		for(int j=0;j<C;j++){
			/*if(mat[i][j]<0)
				printf("-%d ",mat[i][j]);
			else*/
				printf(" %d ",mat[i][j]);
		}
		printf("\n");
	}
}
main(){
	srand(time(NULL));
	int mat[L][C];
	int vet[L];
	for(int i=0;i<L;i++)		//Zera todas as posições do Vetor. Se isso não for feito,
		vet[i]=0;				//os resultados erão somados a lixo eletrônico.
	printf(" -Sorteando os valores da matriz- \n");
	sorteia(mat);		//Sorteia os valores da matriz
	printf("\n -Apresentando os valores das matrizes- \n");
	printf(" Matriz: \n");	mostra(mat);
	for(int i=0;i<L;i++){	//Calcula as posicoes do vetor
		for(int j=0;j<C;j++){
			vet[i]+=mat[i][j];
		}
	}
	printf("\n Vetor final: \n [");
	for(int i=0;i<L;i++)
		printf(" %d ",vet[i]);
	printf(" ]");
}
