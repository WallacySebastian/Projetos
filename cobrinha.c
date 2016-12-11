#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i, j, a=30, b=30, y=35, z=30, k, l, direcao=0;

void limpar(unsigned char matriz[60][60], int matrizL[2][6]);
void escrevermatriz(unsigned char matriz[60][60]);
void possibilidades(unsigned char matriz[60][60]);
void clean(unsigned char matriz[60][60]);
void posicoes(int matrizL[2][6]);

void main(){
	unsigned char matriz[60][60];
	int matrizL[2][6];
	limpar(matriz,matrizL);
	while(1){
		sleep(1);
		system("clear");
		possibilidades(matriz);
		clean(matriz);
		matriz[y][z]=' ';
		posicoes(matrizL);
		for(i=1;i<6;i++) matriz[matrizL[0][i]][matrizL[1][i]]=177;
		escrevermatriz(matriz);
	}
}

void limpar(unsigned char matriz[60][60], int matrizL[2][6]){
	for(i=0;i<60;i++) for(j=0;j<60;j++) matriz[i][j]=' ';
	for(i=30;i<36;i++) matriz[i][30]=178;
	for(i=5;i>=0;i--){
		matrizL[0][i]=i+30;
		matrizL[1][i]=30;
	}
}

void escrevermatriz(unsigned char matriz[60][60]){
	for(i=0;i<60;i++){
		for(j=0;j<60;j++){
			if(matriz[i][j]==' ') printf("%c", matriz[i][j]);
			else if(matriz[i][j]==177) printf("▒");
			else printf("▓");
		}
		printf("\n");
	}
}

void clean(unsigned char matriz[60][60]){
	if(matriz[a+1][b]!=178 && matriz[a+1][b]!=177) matriz[a+1][b]=' ';
	if(matriz[a+1][b+1]!=178 && matriz[a+1][b+1]!=177) matriz[a+1][b+1]=' ';
	if(matriz[a][b+1]!=178 && matriz[a][b+1]!=177) matriz[a][b+1]=' ';
	if(matriz[a-1][b+1]!=178 && matriz[a-1][b+1]!=177) matriz[a-1][b+1]=' ';
	if(matriz[a-1][b]!=178 && matriz[a-1][b]!=177) matriz[a-1][b]=' ';
	if(matriz[a-1][b-1]!=178 && matriz[a-1][b-1]!=177) matriz[a-1][b-1]=' ';
	if(matriz[a][b-1]!=178 && matriz[a][b-1]!=177) matriz[a][b-1]=' ';
	if(matriz[a+1][b-1]!=178 && matriz[a+1][b-1]!=177) matriz[a+1][b-1]=' ';
	a=k;
	b=l;
}

void posicoes(int matrizL[2][6]){
	for(i=5;i>0;i--){
		matrizL[0][i]=matrizL[0][i-1];
		matrizL[1][i]=matrizL[1][i-1];
	}
	matrizL[0][0]=k;
	matrizL[1][0]=l;
	y=matrizL[0][5];
	z=matrizL[1][5];
}

void marcar(unsigned char matriz[60][60], int n);

void possibilidades(unsigned char matriz[60][60]){
	int n=48;
	if(matriz[a+1][b]==' ' && (direcao>=0 && direcao<3 || direcao==6 || direcao==7) && (a+1)<60){
		matriz[a+1][b]=n;
		n++;
	}
	if(matriz[a+1][b+1]==' ' && (direcao==7 || direcao>=0 && direcao<4) && (a+1)<60 && (b+1)<60){
		matriz[a+1][b+1]=n;
		n++;
	}
	if(matriz[a][b+1]==' ' && (direcao>=0 && direcao<5) && (b+1)<60){
		matriz[a][b+1]=n;
		n++;
	}
	if(matriz[a-1][b+1]==' ' && (direcao>0 && direcao<6) && (a-1)>0 && (b+1)<60){
		matriz[a-1][b+1]=n;
		n++;
	}
	if(matriz[a-1][b]==' ' && (direcao>1 && direcao<7) && (a-1)>0){
		matriz[a-1][b]=n;
		n++;
	}
	if(matriz[a-1][b-1]==' ' && (direcao>2 && direcao<8) && (a-1)>0 && (b-1)>0){
		matriz[a-1][b-1]=n;
		n++;
	}
	if(matriz[a][b-1]==' ' && (direcao>3 && direcao<8 || direcao==0) && (b-1)>0){
		matriz[a][b-1]=n;
		n++;
	}
	if(matriz[a+1][b-1]==' ' && (direcao>4 && direcao<8 || direcao==1 || direcao==2) && (a+1)<60 && (b-1)>0){
		matriz[a+1][b-1]=n;
		n++;
	}
	marcar(matriz, n);
}

void marcar(unsigned char matriz[60][60], int n){
	int g=n-48;
	g=rand()%g;
	g+=48;
	if(matriz[a+1][b]==g){
		matriz[a+1][b]=178;
		k=a+1;
		l=b;
		direcao=0;
	}
	if(matriz[a+1][b+1]==g){
		matriz[a+1][b+1]=178;
		k=a+1;
		l=b+1;
		direcao=1;
	}
	if(matriz[a][b+1]==g){
		matriz[a][b+1]=178;
		k=a;
		l=b+1;
		direcao=2;
	}
	if(matriz[a-1][b+1]==g){
		matriz[a-1][b+1]=178;
		k=a-1;
		l=b+1;
		direcao=3;
	}
	if(matriz[a-1][b]==g){
		matriz[a-1][b]=178;
		k=a-1;
		l=b;
		direcao=4;
	}
	if(matriz[a-1][b-1]==g){
		matriz[a-1][b-1]=178;
		k=a-1;
		l=b-1;
		direcao=5;
	}
	if(matriz[a][b-1]==g){
		matriz[a][b-1]=178;
		k=a;
		l=b-1;
		direcao=6;
	}
	if(matriz[a+1][b-1]==g){
		matriz[a+1][b-1]=178;
		k=a+1;
		l=b-1;
		direcao=7;
	}
}

/* DIREÇÃO:

   7 0 1
   6   2
   5 4 3

*/