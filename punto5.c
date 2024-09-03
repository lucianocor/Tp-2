#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int aleatorio(int a,int b);
void mostrarmult();
int main() {
	int a,k,c,b,n,i=1;
	printf("Ingresar A: ");
	srand(time(NULL));
	scanf("%d",&a);
	printf("\nIngresar B: ");
	scanf("%d",&b);
	printf("\nIngresa un numero natural N:");
	scanf("%d",&n);
	printf("Ingresar un K: ");
	scanf("%d",&k);
	while(i<=n){
		c=aleatorio(a,b);
		printf("\nEl random es %d",c);
		mostrarmult(c,k);
		i++;
	}return 0;}
int aleatorio(int a,int b){
	return rand()%(b-a+1)+a;
}
void mostrarmult(int c,int k){
	
	if((c%k) ==0)
		printf("\nEs multiplo de k");
	else 
		printf("\nNo es multiplo ");
}

