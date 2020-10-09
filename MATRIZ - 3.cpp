#include <stdio.h>
#include <conio.c>
#define L 5
#define C 5
/*Dada uma matriz mat(5x5) de elementos inteiros, calcule a soma dos elementos da
diagonal principal. Declare uma variável local no programa principal, chame uma função para ler os
valores e passe como parâmetro a matriz. Retorne para o programa principal, chame outra função
para cálculo da soma. Esta, recebe a matriz como parâmetro e retorna o valor da soma. Apresente o
resultado no programa principal.*/
void leitura(int mat[L][C]){
	for(int i=0;i<L;i++){
		for(int j=0;j<C;j++){
			printf("Digite o valor  mat[%d][%d]:  ",i,j);		scanf("%d",&mat[i][j]);
		}
	}
}
int diagonal(int mat[L][C]){
	int soma=0;
	for(int i=0;i<L;i++)
		for(int j=0;j<C;j++){
			if(i==j)
				soma+=mat[i][j];
		}	
	return soma;	
}
main(){
	int mat[L][C];
	int i,j;
	printf("\n -Lendo os valores da matriz- \n");
	leitura(mat);		//Lê os valores da matriz
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
	printf("  - A soma dos elementos das diagonais eh de: %d",diagonal(mat));		//Realiza o cálculo da diagonal
}

