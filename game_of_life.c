//LINUX

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int i, j;

void limpar(int linha, int coluna, unsigned char matriz[linha][coluna]);
void escrever(int linha, int coluna, unsigned char matriz[linha][coluna]);
void proxima_geracao(int linha, int coluna, unsigned char matriz[linha][coluna]);
void cantos(int linha, int coluna, unsigned char matriz[linha][coluna]);
void redefinir(int linha, int coluna, unsigned char matriz[linha][coluna]);

void main(){
	FILE *jogo, *gravado;
	int x, y, a, aux;
	char b, arquivo[30];
	unsigned char matriz[20][30], cell;
	limpar(20,30,matriz);
	system("clear");
	printf("Para ler direto de um arquivo, entre com 1 para detalhar as instruções de leitura;\n");
	usleep(200000);
	printf("Para preencher manualmente, entre com 2;\n");
	usleep(200000);
	printf("Ou digite 3 para preencher aleatoriamente.\n");
	scanf("%d",&a);
	system("clear");
	if(a==1){
		printf("Preencha o arquivo de texto com os seguintes caracteres:\n\n");
		printf("Células vivas: 1\n");
		printf("Células mortas: -\n\n");
		usleep(600000);
		printf("Coloque o arquivo na mesma pasta do programa.\n\n");
		sleep(1);
		printf("Quando estiver pronto, digite o nome do arquivo: ");
		scanf("%s",arquivo);
			jogo=fopen(arquivo,"r");
			for(i=0;i<20;i++) for(j=0;j<30;j++){
					fscanf(jogo," %c",&cell);
					if(cell=='\n') break;
					matriz[i][j]=cell;
				}
			redefinir(20,30,matriz);
			fclose(jogo);
	}
	else if(a==2){
		while(1){
			printf("Digite a linha e a coluna para colocar uma célula. Entre com 0 e 0 para finalizar as entradas.\n");
			printf("Linha: ");
			scanf("%d", &x);
			printf("Coluna: ");
			scanf("%d", &y);
			printf("\n");
			if(x==0 && y==0) break;
			else matriz[x][y]=178;
			system("clear");
			escrever(20,30,matriz);
		}
	}
	else{
		for(i=0;i<20;i++){
			for(j=0;j<30;j++){
				srand(time(0)+b);
				aux=rand()%2;
				b--;
				if(aux==1) matriz[i][j]=178;
			}
		}
	}
	system("clear");
	printf("Certo. O seu jogo está assim:\n");
	usleep(500000);
	escrever(20,30,matriz);
	sleep(1);
	printf("\n\nAgora coloque o número de gerações que você deseja que aconteça:\n");
	scanf("%d",&b);
	system("clear");
	printf("Tudo pronto! Acontecerá %d gerações com as células que você colocou.\n\n", b);
	printf("Aperte ENTER para começar!");
	__fpurge(stdin);
	getchar();
	sleep(1);
	aux=0;
	while(1){
		usleep(400000);
		system("clear");
		cantos(20,30,matriz);
		proxima_geracao(20,30,matriz);
		escrever(20,30,matriz);
		aux++;
		printf("\nGeração %d\n", aux);
		if(aux==b) break;
	}
	printf("Feito!\n");
	printf("Deseja salvar o jogo em um arquivo de texto?\n");
	printf("('1' para salvar; '0' para sair)\n");
	scanf("%d",&b);
	if(b==1){
		printf("Salvar o arquivo com o nome: ");
		scanf("%s", arquivo);
		gravado=fopen(arquivo,"w");
		for(i=0;i<20;i++){
			for(j=0;j<30;j++){
				if(matriz[i][j]==' ') fprintf(gravado, "-");
				else fprintf(gravado, "1");
			}
			fprintf(gravado, "\n");
		}
		printf("Arquivo salvo!\n");
		fclose(gravado);
		sleep(1);
	}
}

void limpar(int linha, int coluna, unsigned char matriz[linha][coluna]){
	for(i=0;i<linha;i++) for(j=0;j<coluna;j++) matriz[i][j]=' ';
}

void cantos(int linha, int coluna, unsigned char matriz[linha][coluna]){
	for(i=0;i<linha;i++) for(j=0;j<coluna;j++){
			if((i-1)<0 || (i+1)>linha || (j-1)<0 || (j+1)>coluna) matriz[i][j]=' ';
		}
}

void escrever(int linha, int coluna, unsigned char matriz[linha][coluna]){
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			if(matriz[i][j]==178) printf("▓");
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

void redefinir(int linha, int coluna, unsigned char matriz[linha][coluna]){
	for(i=0;i<linha;i++) for(j=0;j<coluna;j++){
			if(matriz[i][j]=='1') matriz[i][j]=178;
			else matriz[i][j]=' ';
		}
}