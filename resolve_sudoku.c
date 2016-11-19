#include <stdio.h>

void ler(int matriz[9][9][10]);
void zerar(int matriz[9][9][10]);
void resolvendo(int matriz[9][9][10]);
void possibilidades(int matriz[9][9][10], int i, int j);
int verificacao(int matriz[9][9][10]);
void smatvet(int matriz[9][9][10], int vetor[9], int i, int j);
void escrever(int matriz[9][9][10]);

void main(){
	int matriz[9][9][10];
	ler(matriz);
	resolvendo(matriz);
	if(verificacao(matriz)==1) printf("CERTO\n\n");
	else printf("ERRADO\n\n");
	escrever(matriz);
}

void zerar(int matriz[9][9][10]){
	int i, j, k;
	for(i=0;i<9;i++) for(j=0;j<9;j++) for(k=1;k<10;k++) matriz[i][j][k]=0;
}

void resolvendo(int matriz[9][9][10]){
	int i, j, k, g, validade;
	while(1){
		validade=1;
		zerar(matriz);
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				if(matriz[i][j][0]==0){
					validade=0;
					possibilidades(matriz,i,j);
					for(g=0;g<10;g++) printf("%d ", matriz[i][j][g]);
					printf("\n");
				}
			}
		}
		if(validade==1) break;
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				if(matriz[i][j][0]==0 && matriz[i][j][2]==0){
					matriz[i][j][0]=matriz[i][j][1];
					matriz[i][j][1]=0;
				}
			}
		}

	}
}

// LÊ A MATRIZ
void ler(int matriz[9][9][10]){
	int i, j;
	for(i=0;i<9;i++) for(j=0;j<9;j++) scanf("%d",&matriz[i][j][0]);
}

void possibilidades(int matriz[9][9][10], int i, int j){
	int k, l=1, n, validade, vetor[9];
	for(n=1;n<10;n++){
		validade=1;
		matriz[i][j][l]=n;
		for(k=0;k<9;k++){
			if(k!=j && matriz[i][j][l]==matriz[i][k][0]){
				validade=0;
				break;
			}
			if(k!=i && matriz[i][j][l]==matriz[k][j][0]){
				validade=0;
				break;
			}
		}
		if(i%3==0 && j%3==0) smatvet(matriz,vetor,i,j);
		for(k=0;k<9;k++){
			if(matriz[i][j][l]==vetor[k]){
				validade=0;
				break;
			}
			if(validade==0) break;
		}
		if(validade==1) l++;
	}
	if(validade==0) matriz[i][j][l]=0;
}

// VERIFICA SE O SUDOKU É VÁLIDO
int linhacoluna(int matriz[9][9][10], int i, int j);
int submatriz(int matriz[9][9][10], int i, int j);

int verificacao(int matriz[9][9][10]){
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
int linhacoluna(int matriz[9][9][10], int i, int j){
	int k, validade=1;
	for(k=(j+1);k<9;k++) if(matriz[i][j][0]==matriz[i][k][0] || matriz[j][i][0]==matriz[k][i][0]){
			validade=0;
			break;
		}
	return(validade);
}
// VERIFICA SE A SUBMATRIZ É VÁLIDA
void smatvet(int matriz[9][9][10], int vetor[9], int i, int j);

int submatriz(int matriz[9][9][10], int i, int j){
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
void smatvet(int matriz[9][9][10], int vetor[9], int i, int j){
	int l=0, k, g;
	for(k=i;k<(i+3);k++) for(g=j;g<(j+3);g++){
			vetor[l]=matriz[k][g][0];
			l++;
		}
}

void escrever(int matriz[9][9][10]){
	int i, j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++) printf("%d ", matriz[i][j][0]);
		printf("\n");
	}
}