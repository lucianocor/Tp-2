#include <stdio.h>
void ingresar(int*);
int comprobar(int);
int clave(int);
int main() {
	int c;
	ingresar(&c);	
	if(clave(c)!=6){
		printf("\nLa clave no es de 6 digitos.Ingresar otra clave:\n ");
		ingresar(&c);}
	if(comprobar(c) )
		printf("\nLa Clave ingresada cumple con los requisitos");
	else
		printf("\nLa Clave ingresada no cumple con los requisitos");
	return 0;
}
void ingresar (int*x){
	printf("Ingresar la clave con 6 digitos: ");
	scanf("%d",x);
}
int comprobar (int x){
	int b=0,digd,aux,dig;
	while(x!=0 && b==0){
	dig=x%10;
	aux=x;
		while(x!=0 && b==0){
			digd=x%10;
			if(dig==digd)
				b=1;
			aux=aux/10;	
		}
	x=x/10;
	}return b;
		}
int clave(int x){
	int c=0;
	while(x!=0){
	x=x/10;
	c++;}
	return c;
	}
