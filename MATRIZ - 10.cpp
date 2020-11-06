#include <stdio.h>
#include <iostream>
#include <conio.c>
#define amarelo textcolor(14); 
#define azul textcolor(1);
#define vermelho textcolor(4);
#define normal textcolor(7);
using namespace std;
void func(int ord){
	int mat[ord][ord];
	int m=ord-1;
	for (int i=0;i<ord;i++)
		for(int j=0;j<ord;j++){
			if(i==0 || j==0 || i==m || j==m){
				mat[i][j]=1;
			}
			else if(i==1 || j==1 || i==m-1 || j==m-1)
				mat[i][j]=2;
			else
				mat[i][j]=3;
			else
				mat[i][j]=4;
		}
	for(int a=0;a<ord;a++){
		for(int b=0;b<ord;b++){
			if(mat[a][b]==1)
				vermelho
			else if(mat[a][b]==2)
				amarelo
			else 
				azul
			cout<<" "<< mat[a][b];
		}
		cout<<"\n";
	}
}
main(){
	int ordem;
	cout<<" Digite a ordem da matriz (4,5 ou 6): ";		cin>>ordem;
	func(ordem);
	normal
}
/*
for (int i=0;i<ord;i++)
		for(int j=0;j<ord;j++){
			if(i==0 || j==0 || i==m || j==m){
				mat[i][j]=1;
			}
			else if(i==1 || j==1 || i==m-1 || j==m-1)
				mat[i][j]=2;
			else
				mat[i][j]=3;
		}
*/
