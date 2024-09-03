#include <stdio.h>
int menu();
int divisores(int x);
int invertir(int x);
void primo(int k);
void devolver();
int main() {
	int opc,x;
	printf("Ingresar un numero natural X: ");
	scanf("%d",&x);
	do{
	opc=menu();
	switch(opc){
		case 1:printf("La cantidad de divisores naturales de X es:%d ",divisores(x));
			break;
		case 2:primo(x);
			break;
		case 3:devolver();
			break;
		case 4:printf("El numero invertido es :%d",(int)invertir( x));
			break;
		case 0:
			break;
		default:
			printf("Opcion invalida");
	}}while(opc!=0);
	
	return 0;
}
int menu(){
	int c;
	printf("\nIngresar 1 si quiere calcular la cantidad de divisores naturales de X ");
	printf("\nIngresar 2 si quiere determinar el número natural X es primo");
	printf("\nIngresar 3 si quiere Comparar dos números reales A y B,devolviendo 1 si A>B,0 si A=B o -1 si A<B ");
	printf("\nIngresar 4 si quiere invertir X");
	printf("\nIngresar un 0 si quiere salir del programa:\n");
	scanf("%d",&c);
	return c;
}
	
int divisores(int x){
	int cont=0,i;
	for(i=1;i>=x;i++){
		if(x%i==0)
			cont++;
	}
	return cont;
}
void primo(int k){
	int pd=2;
	while(pd<=k/2 && k%pd != 0){
		pd=pd+1;}
	if(pd>(k/2) && (k != 1))
		printf("Es primo");
	else
		printf("No es primo");
	}
void devolver(){
	int a,b;
	printf("\nIngresar A: ");
	scanf("%d",&a);
	printf("\nIngresar B: ");
	scanf("%d",&b);
	if(a>b){
		printf("1");
	}else if(a==b){
		printf("0");
		}else 
			printf("-1");
}
int invertir(int x){
	int sum=0,dig;
	while(x!=0){
		dig=x%10;
		sum=sum*10+dig;
		x=x/10;
	}
	return sum;
}
