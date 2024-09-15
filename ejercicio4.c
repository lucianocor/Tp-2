#include <stdio.h>
void ingresar (int*,int*);
void reducir(int,int,int*,int*);
int main() {
	int nu,de,ar,br;
	ingresar(&nu,&de);
	reducir(nu,de,&ar,&br);
	if(nu==0)
		printf("El resultado es 0");
	else
	printf("La fraccion irreducible es %d/%d ",ar,br);
	return 0;
}
void ingresar(int *x,int *y){
	printf("Ingresar una fraccion\nIngresar un A ");
	scanf("%d",x);
	printf("\ningresar un B ");
	scanf("%d",y);
	if(y==0){
		printf("\nValor invalido.Ingresar otro B");
		scanf("%d",y);}
}
void reducir(int x,int y,int *ar,int *br){
	int i=1;
		while(i<=x){
		if(x%i==0 && y%i==0){
			*ar=x/i;
			*br=y/i;
		}
	i++;	
	}		
 }
