//Exercicio MAT 2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 3
#define C 4
float soma(float mat[L][C]){
	int i,j;
	float total;
	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			total+=mat[i][j];
		}
	}
	return total;
}
main(){
	float mat[L][C];
	int i,j;
	printf(" Matriz: \n");
	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			printf("Digite o valor  mat[%d][%d]:  ",i,j);		scanf("%f",&mat[i][j]);
		}
	}	
	printf("\n Matriz\n");
	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			printf("%.1f  ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\nA soma de todos os itens eh de  %.1f",soma(mat));
}
