#include <stdio.h>
int menu();
int main(){
	int opc;
	float a,b;
	printf("ingresar un numero A: ");
	scanf("%f",&a);
	printf("\nIngresar un numero B: ");
	scanf("%f",&b);
	do{
		opc=menu();
			switch(opc){
			case 1:printf("La suma de A y B es:%f",a+b);
			break;
			case 2:printf("\nLa resta de A y B es:%f",a-b);
			break;
			case 3:printf("La multiplicacion de A y B es: %.2f",a*b);
			break;
			case 4:printf("La division entre A y B es:%.2f",a/b);
			break;
			default:printf("Salio del programa");
			break;
			}}while(opc !=0);
			return 0;
	}
int menu(void){
		int op;
		printf("\nIngresar 1 si quiere calcular la suma entre A y B");
		printf("\nIngresar 2 si quiere calcular la resta entre A y B");
		printf("\nIngresar 3 si quiere calcular la division entre A y B");
		printf("\nIngresar 4 si quiere calcular la multiplicacion entre A y B");
		printf("\ningrese 0 si quiere salir del programa ");
		scanf("%d",&op);
		return op;}
