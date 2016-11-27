#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void limpar(char string[22]);
void limparmat(char matriz[5][200]);
void letreiro(char s[22], char matriz[5][200]);
void moverdir(char matriz[5][200]);
void showmatriz(char matriz[5][200]);

void main() {
	char nome[22], matriz[5][200];
	limpar(nome);
	gets(nome);
	limparmat(matriz);
	letreiro(nome,matriz);
	while(1){
		system("clear");
		showmatriz(matriz);
		printf("\n");
		moverdir(matriz);
		sleep(1);
	}
}

int i, j;

void limpar(char string[22]){
	for(i=0;i<22;i++) string[i]=' ';
}

void limparmat(char matriz[5][200]){
	for(i=0;i<5;i++) for(j=0;j<200;j++) matriz[i][j]=' ';
}

void moverdir(char matriz[5][200]){
	char a;
	a=matriz[0][199];
	for(i=199;i>0;i--) matriz[0][i]=matriz[0][i-1];
	matriz[0][0]=a;
	a=matriz[1][199];
	for(i=199;i>0;i--) matriz[1][i]=matriz[1][i-1];
	matriz[1][0]=a;
	a=matriz[2][199];
	for(i=199;i>0;i--) matriz[2][i]=matriz[2][i-1];
	matriz[2][0]=a;
	a=matriz[3][199];
	for(i=199;i>0;i--) matriz[3][i]=matriz[3][i-1];
	matriz[3][0]=a;
	a=matriz[4][199];
	for(i=199;i>0;i--) matriz[4][i]=matriz[4][i-1];
	matriz[4][0]=a;
}

void showmatriz(char matriz[5][200]){
	for(i=0;i<5;i++){
		for(j=0;j<130;j++) printf("%c", matriz[i][j]);
		printf("\n");
	}
}

void etapa1(char matriz[5][200], char s[22], int k);
void etapa2(char matriz[5][200], char s[22], int k);
void etapa3(char matriz[5][200], char s[22], int k);
void etapa4(char matriz[5][200], char s[22], int k);
void etapa5(char matriz[5][200], char s[22], int k);
void etapa6(char matriz[5][200], char s[22], int k);
void etapa7(char matriz[5][200], char s[22], int k);

void letreiro(char s[22], char matriz[5][200]){
	int k;
	i=0;
	for(k=0;k<22;k++){
		if(s[k]=='\0') break;
		if(s[k]!=' '){
			etapa1(matriz,s,k);
			etapa2(matriz,s,k);
			etapa3(matriz,s,k);
			etapa4(matriz,s,k);
			etapa5(matriz,s,k);
			etapa6(matriz,s,k);
			etapa7(matriz,s,k);
		}
		else i+=7;
		i+=2;
	}
}

int j;

void etapa1(char matriz[5][200], char s[22], int k){
	if(s[k]!='a' && s[k]!='c' && s[k]!='g' && s[k]!='i' && s[k]!='j' && s[k]!='o' && s[k]!='q' && s[k]!='s') matriz[0][i]='#';
	if(s[k]!='i' && s[k]!='j' && s[k]!='t' && s[k]!='x' && s[k]!='z') matriz[1][i]='#';
	if(s[k]!='i' && s[k]!='j' && s[k]!='s' && s[k]!='t' && s[k]<'x') matriz[2][i]='#';
	if(s[k]!='i' && s[k]!='s' && s[k]!='t' && s[k]!='v' && s[k]<'x') matriz[3][i]='#';
	if(s[k]!='c' && s[k]!='g' && s[k]!='i' && s[k]!='j' && s[k]!='o' && s[k]!='q' && (s[k]<'t' || s[k]>'v') && s[k]!='y') matriz[4][i]='#';
	i++;
}

void etapa2(char matriz[5][200], char s[22], int k){
	if(s[k]!='i' && s[k]!='j' && s[k]!='m') matriz[0][i]='#';
	if(s[k]!='i' && s[k]!='j' && s[k]!='t' && s[k]!='z') matriz[1][i]='#';
	if(s[k]!='i' && s[k]!='j' && s[k]!='t' && s[k]!='x' && s[k]!='z') matriz[2][i]='#';
	if(s[k]!='i' && s[k]!='s' && s[k]!='t' && s[k]!='y') matriz[3][i]='#';
	if(s[k]!='i' && s[k]!='t' && s[k]!='v' && s[k]!='w' && s[k]!='y') matriz[4][i]='#';
	i++;
}

void etapa3(char matriz[5][200], char s[22], int k){
	if(s[k]!='h' && (s[k]<'j' || s[k]>'n') && (s[k]<'u' || s[k]>'y')) matriz[0][i]='#';
	if(s[k]=='i' || s[k]=='n' || s[k]=='t' || s[k]=='x') matriz[1][i]='#';
	if(s[k]!='c' && s[k]!='d' && s[k]!='g' && s[k]!='j' && s[k]!='l' && s[k]!='o' && s[k]!='q' && s[k]!='u' && s[k]!='v') matriz[2][i]='#';
	if(s[k]=='i' || s[k]=='t' || s[k]=='v' || s[k]>'w') matriz[3][i]='#';
	if(s[k]!='a' && s[k]!='f' && s[k]!='h' && s[k]!='k' && s[k]!='m' && s[k]!='n' && s[k]!='p' && s[k]!='r' && s[k]!='w' && s[k]!='x') matriz[4][i]='#';
	i++;
}

void etapa4(char matriz[5][200], char s[22], int k){
	if(s[k]!='h' && (s[k]<'j' || s[k]>'n') && (s[k]<'u' || s[k]>'y')) matriz[0][i]='#';
	if(s[k]=='i' || s[k]=='t' || s[k]=='w' || s[k]=='z') matriz[1][i]='#';
	if(s[k]!='c' && s[k]!='d' && s[k]!='j' && s[k]!='l' && s[k]!='o' && s[k]!='u' && s[k]!='v') matriz[2][i]='#';
	if(s[k]=='i' || s[k]=='m' || s[k]=='t' || s[k]>'x') matriz[3][i]='#';
	if(s[k]!='a' && s[k]!='f' && s[k]!='h' && s[k]!='k' && s[k]!='m' && s[k]!='n' && s[k]!='p' && s[k]!='r' && s[k]!='w' && s[k]!='x') matriz[4][i]='#';
	i++;
}

void etapa5(char matriz[5][200], char s[22], int k){
	if(s[k]!='h' && (s[k]<'j' || s[k]>'n') && (s[k]<'u' || s[k]>'y')) matriz[0][i]='#';
	if(s[k]=='i' || s[k]=='k' || s[k]=='t' || s[k]=='x' || s[k]=='z') matriz[1][i]='#';
	if(s[k]!='c' && s[k]!='d' && s[k]!='j' && s[k]!='l' && s[k]!='o' && s[k]!='q' && s[k]!='u' && s[k]!='v') matriz[2][i]='#';
	if(s[k]=='i' || s[k]=='k' || s[k]=='n' || s[k]=='q' || s[k]=='t' || s[k]=='v' || s[k]=='x' || s[k]=='y') matriz[3][i]='#';
	if(s[k]!='a' && s[k]!='f' && s[k]!='h' && s[k]!='k' && s[k]!='m' && s[k]!='n' && s[k]!='p' && s[k]!='r' && s[k]!='w' && s[k]!='x') matriz[4][i]='#';
	i++;
}

void etapa6(char matriz[5][200], char s[22], int k){
	if(s[k]!='i' && s[k]!='l' && s[k]!='m') matriz[0][i]='#';
	if(s[k]!='c' && (s[k]<'e' || s[k]>'g') && s[k]!='i' && s[k]!='l' && s[k]!='s' && s[k]!='t') matriz[1][i]='#';
	if(s[k]!='c' && s[k]!='i' && s[k]!='k' && s[k]!='l' && s[k]!='t' && s[k]!='x' && s[k]!='z') matriz[2][i]='#';
	if(s[k]!='c' && s[k]!='e' && s[k]!='f' && s[k]!='i' && s[k]!='l' && s[k]!='p' && s[k]!='t' && s[k]<'y') matriz[3][i]='#';
	if(s[k]!='f' && s[k]!='i' && s[k]!='p' && s[k]!='t' && s[k]!='v' && s[k]!='w' && s[k]!='y') matriz[4][i]='#';
	i++;
}

void etapa7(char matriz[5][200], char s[22], int k){
	if(s[k]=='c' || (s[k]>'d' && s[k]<'i') || s[k]=='j' || s[k]=='k' || s[k]=='m' || s[k]=='n' || s[k]>'r') matriz[0][i]='#';
	if(s[k]!='c' && (s[k]<'e' || s[k]>'g') && s[k]!='i' && s[k]!='k' && s[k]!='l' && s[k]!='s' && s[k]!='t' && s[k]!='x' && s[k]!='z') matriz[1][i]='#';
	if(s[k]!='b' && s[k]!='c' && s[k]!='e' && s[k]!='f' && s[k]!='i' && s[k]!='k' && s[k]!='l' && s[k]!='p' && (s[k]<'r' || s[k]>'t') && s[k]<'x') matriz[2][i]='#';
	if(s[k]!='c' && s[k]!='e' && s[k]!='f' && s[k]!='i' && s[k]!='k' && s[k]!='l' && s[k]!='p' && s[k]!='t' && s[k]!='v' && s[k]<'x') matriz[3][i]='#';
	if(s[k]!='b' && s[k]!='d' && s[k]!='f' && s[k]!='i' && s[k]!='j' && s[k]!='o' && s[k]!='p' && (s[k]<'s' || s[k]>'v') && s[k]!='y') matriz[4][i]='#';
	i++;
}

/*
 #####   ######    ######  ######   #######  #######   ######  ##   ##    ###         ##  ##   ##
##   ##  ##   ##  ##       ##   ##  ##       ##       ##       ##   ##    ###         ##  ##  ## 
#######  ######   ##       ##   ##  ######   ######   ## ####  #######    ###         ##  #####  
##   ##  ##   ##  ##       ##   ##  ##       ##       ##   ##  ##   ##    ###    ##   ##  ##  ## 
##   ##  ######    ######  ######   #######  ##        ######  ##   ##    ###     #####   ##   ##

##       #     #  ##   ##   #####   ######    #####   ######    ######  #######  ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  #######
##       ##   ##  ###  ##  ##   ##  ##   ##  ##   ##  ##   ##  ##         ###    ##   ##  ##   ##  ## # ##   ## ##   ##   ##     ### 
##       #######  #######  ##   ##  ######   ## # ##  ######    #####     ###    ##   ##  ##   ##  #######    ###     #####     ###  
##       ## # ##  ##  ###  ##   ##  ##       ##  ###  ##   ##       ##    ###    ##   ##   ## ##   ##   ##   ## ##     ###     ###   
#######  ##   ##  ##   ##   #####   ##        ######  ##   ##  ######     ###     #####     ###    #     #  ##   ##    ###    #######
*/