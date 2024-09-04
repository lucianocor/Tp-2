#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int contarmul(int x);
int main() {
	int a,b,cont,x;
	cont=0;
	srand(time(NULL));
	printf("Ingresar un nunmero A: ");
	scanf("%d",&a);
	printf("\nIngresar un nunmero B: ");
	scanf("%d",&b);
	do{
	x=rand()%(b-a+1)+a;
	if(contarmul(x) >= x)
		printf("\nEl numero no es deficiente");
	printf("%d",x);
	cont++;
	}while(cont<10);	
	return 0;
}
int contarmul(int x){
	int i,contm=0;
	i=1;
	for(i=1;i<=x;i++){
		if(x%i == 0)
			contm=contm+i;}
	return contm;
}
