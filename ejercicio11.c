#include <stdio.h>
int contarmul(int x );
int main() {
	int x,b,cont;
	b=0;
	printf("Ingresar un numero X: ");
	scanf("%d",&x);
	while(x>0){
		cont=contarmul(x);
		if(cont >= x){
			if(cont == x){
				printf("El numero es perfecto ");
			}else
			   printf("El numero es abundante ");
		}else printf("El numero es deficiente");	
		printf("\nIngresar un numero X: ");
		scanf("%d",&x);
		b=1;
	}
	if(b==0)
		  printf("No ingreso un numero natural");
	return 0;
}
int contarmul(int a){
	int i,contm=0;
	i=1;
	for(i=1;i<=a;i++){
		if(a%i == 0)
			contm=contm+i;}
	return contm;
}
