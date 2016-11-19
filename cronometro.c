#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// PRINCIPAL
void cronometro(int a, int b);

void main(){
	int m, s, i, j;
	printf("Digite abaixo os minutos e os segundos, nesse formato: 'mm:ss'\n");
	scanf("%d:%d",&m,&s);
	for(i=m;i>=0;i--){
		for(j=(s-1);j>=0;j--){
			system("clear");
			cronometro(i,j);
			sleep(1);
		}
		if(i==0) break;
		s=60;
	}
	printf("\n");
}
// ***********************
// DESENHA O CRONÔMETRO
void etapa1(int a);
void etapa2(int a);
void etapa3(int a);
void etapa4(int a);
void etapa5(int a);

void cronometro(int a, int b){
	etapa1(a);
	printf("  ##  \t");
	etapa1(b);
	printf("\n");
	etapa2(a);
	printf("  ##  \t");
	etapa2(b);
	printf("\n");
	etapa3(a);
	printf("      \t");
	etapa3(b);
	printf("\n");
	etapa4(a);
	printf("  ##  \t");
	etapa4(b);
	printf("\n");
	etapa5(a);
	printf("  ##  \t");
	etapa5(b);
	printf("\n");
}
// // // DESENHO EM 5 ETAPAS OU LINHAS
// PRIMEIRA LINHA
void etapa1(int a){
	if(a/10==1) printf("    ##\t");
	else if(a/10==4) printf("##  ##\t");
	else printf("######\t");
	if(a%10==1) printf("    ##\t");
	else if(a%10==4) printf("##  ##\t");
	else printf("######\t");
}
// SEGUNDA LINHA
void etapa2(int a){
	if((a/10>=1 && a/10<=3) || a/10==7) printf("    ##\t");
	else if(a/10==5 || a/10==6) printf("##    \t");
	else printf("##  ##\t");
	if((a%10>=1 && a%10<=3) || a%10==7) printf("    ##\t");
	else if(a%10==5 || a%10==6) printf("##    \t");
	else printf("##  ##\t");
}
// TERCEIRA LINHA
void etapa3(int a){
	if(a/10==0) printf("##  ##\t");
	else if(a/10==1 || a/10==7) printf("    ##\t");
	else printf("######\t");
	if(a%10==0) printf("##  ##\t");
	else if(a%10==1 || a%10==7) printf("    ##\t");
	else printf("######\t");
}
// QUARTA LINHA
void etapa4(int a){
	if(a/10==0 || a/10==6 || a/10==8) printf("##  ##\t");
	else if(a/10==2) printf("##    \t");
	else printf("    ##\t");
	if(a%10==0 || a%10==6 || a%10==8) printf("##  ##\t");
	else if(a%10==2) printf("##    \t");
	else printf("    ##\t");
}
// QUINTA LINHA
void etapa5(int a){
	if(a/10==1 || a/10==4 || a/10==7) printf("    ##\t");
	else printf("######\t");
	if(a%10==1 || a%10==4 || a%10==7) printf("    ##\t");
	else printf("######\t");
}