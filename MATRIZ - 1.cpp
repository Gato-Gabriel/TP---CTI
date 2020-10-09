//Exercicio MAT 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 10
#define C 10
main(){
	int mat[L][C];
	int i,j;
	printf("\n Matriz: \n");
	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			mat[i][j]=rand()%50+1;
			printf(" %d  ",mat[i][j]);
		}
		printf("\n");
	}	

	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			printf(" %d  ",mat[i][j]);
			total+=mat[i][j];
		}
		printf("\n");
	}			
	printf("A soma de todos os itens eh : %d",total);
	printf("\nDigite qual linha voce deseja somar: ");	scanf("%d",&li);
	total=0;
	for(j=0;j<C;j++)
		total+=mat[li][j];
	printf("A soma da linha %d eh de %d .",li,total);
}
