#include <stdio.h>

// PRINCIPAL
void ler(int matriz[9][9]);
int verificacao(int matriz[9][9]);

void main(){
	int matriz[9][9];
	ler(matriz);
	if(verificacao(matriz)==0) printf("invalida\n");
	else printf("valida\n");
}
// ***********************
// LÊ A MATRIZ
void ler(int matriz[9][9]){
	int i, j;
	for(i=0;i<9;i++) for(j=0;j<9;j++) scanf("%d",&matriz[i][j]);
}
// VERIFICA SE O SUDOKU É VÁLIDO
int linhacoluna(int matriz[9][9], int i, int j);
int submatriz(int matriz[9][9], int i, int j);

int verificacao(int matriz[9][9]){
	int i, j, k, validade=1;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			validade=linhacoluna(matriz,i,j)*submatriz(matriz,i,j);
			if(validade==0) break;
		}
		if(validade==0) break;
	}
	return(validade);
}
// VERIFICA SE A LINHA E A COLUNA DA QUAL O ELEMENTO PERTENCE É VÁLIDA
int linhacoluna(int matriz[9][9], int i, int j){
	int k, validade=1;
	for(k=(j+1);k<9;k++) if(matriz[i][j]==matriz[i][k] || matriz[j][i]==matriz[k][i]){
			validade=0;
			break;
		}
	return(validade);
}
// VERIFICA SE A SUBMATRIZ É VÁLIDA
void smatvet(int matriz[9][9], int vetor[9], int i, int j);

int submatriz(int matriz[9][9], int i, int j){
	int vetor[9], validade=1, k, g;
	if(i%3==0 && j%3==0){
		smatvet(matriz,vetor,i,j);
		for(k=0;k<9;k++){
			for(g=(k+1);g<9;g++) if(vetor[k]==vetor[g]){
						validade=0;
						break;
					}
			if(validade==0) break;
		}
	}
	return(validade);
}
// TRANSFORMA A SUBMATRIZ EM VETOR
void smatvet(int matriz[9][9], int vetor[9], int i, int j){
	int l=0, k, g;
	for(k=i;k<(i+3);k++) for(g=j;g<(j+3);g++){
			vetor[l]=matriz[k][g];
			l++;
		}
}