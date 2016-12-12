#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int i, j;

void limpar(int linha, int coluna, unsigned char matriz[linha][coluna]);
void escrever(int linha, int coluna, unsigned char matriz[linha][coluna]);
void proxima_geracao(int linha, int coluna, unsigned char matriz[linha][coluna]);
void cantos(int linha, int coluna, unsigned char matriz[linha][coluna]);

void main(){
	FILE *jogo;
	int x, y, a, aux;
	unsigned char matriz[42][42], cell;
	limpar(42,42,matriz);
	printf("Para ler direto de um arquivo, entre com 1.\n");
	printf("Para preencher manualmente, entre com 2.\n");
	scanf("%d",&a);
	if(a==2){
		printf("Escolha 2 para entrar com cada coordenada, ou 3 para preencher aleatóriamente.\n");
		scanf("%d", &a);
		if(a==2){
			while(1){
				printf("Digite a posição X e Y para colocar uma célula. Entre com 0 e 0 para começar.\n");
				printf("X: ");
				scanf("%d", &x);
				printf("Y: ");
				scanf("%d", &y);
				printf("\n");
				if(x==0 && y==0) break;
				else matriz[x][y]=178;
				escrever(42,42,matriz);
			}
		}
		if(a==3){
			for(i=0;i<42;i++){
				for(j=0;j<42;j++){
					srand(time(0));
					aux=rand()%2;
					if(aux==1) matriz[i][j]=178;
				}
			}
		}
	}
	else{
		printf("Coloque o arquivo de texto com o nome 'jogo' na mesma pasta do programa.\n");
		printf("Quando estiver pronto, digite 1 para continuar.\n");
		scanf("%d", &a);
		if(a==1){
			jogo=fopen("jogo","r");
			for(i=0;i<42;i++) for(j=0;j<42;j++){
					cell=fgetc(jogo);
					if(cell=='\n') break;
					matriz[i][j]=cell;
				}
		}
	}
	while(1){
		usleep(200000);
		system("clear");
		proxima_geracao(42,42,matriz);
		escrever(42,42,matriz);
		cantos(42,42,matriz);
	}
}

void limpar(int linha, int coluna, unsigned char matriz[linha][coluna]){
	for(i=0;i<linha;i++) for(j=0;j<coluna;j++) matriz[i][j]=' ';
}

void cantos(int linha, int coluna, unsigned char matriz[linha][coluna]){
	for(i=0;i<linha;i++){
		matriz[i][0]=' ';
		matriz[i][41]=' ';
	}
	for(j=1;j<(coluna-1);j++){
		matriz[0][j]=' ';
		matriz[41][j]=' ';
	}
}

void escrever(int linha, int coluna, unsigned char matriz[linha][coluna]){
	for(i=1;i<(linha-1);i++){
		for(j=1;j<(coluna-1);j++){
			if(matriz[i][j]==178 || matriz[i][j]=='*') printf("▓");
			else printf("%c",matriz[i][j]);
		}
		printf("\n");
	}
}

void proxima_geracao(int linha, int coluna, unsigned char matriz[linha][coluna]){
	int vizinhos;
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			vizinhos=0;
			if(matriz[i+1][j]==178 || matriz[i+1][j]==176) vizinhos++;
			if(matriz[i+1][j+1]==178 || matriz[i+1][j+1]==176) vizinhos++;
			if(matriz[i][j+1]==178 || matriz[i][j+1]==176) vizinhos++;
			if(matriz[i-1][j+1]==178 || matriz[i-1][j+1]==176) vizinhos++;
			if(matriz[i-1][j]==178 || matriz[i-1][j]==176) vizinhos++;
			if(matriz[i-1][j-1]==178 || matriz[i-1][j-1]==176) vizinhos++;
			if(matriz[i][j-1]==178 || matriz[i][j-1]==176) vizinhos++;
			if(matriz[i+1][j-1]==178 || matriz[i+1][j-1]==176) vizinhos++;
			if(matriz[i][j]==' ') if(vizinhos==3) matriz[i][j]=177;
			if(matriz[i][j]==178) if(vizinhos!=2 && vizinhos!=3) matriz[i][j]=176;
		}
	}
	for(i=0;i<linha;i++) for(j=0;j<coluna;j++){
			if(matriz[i][j]==177) matriz[i][j]=178;
			if(matriz[i][j]==176) matriz[i][j]=' ';
		}
}