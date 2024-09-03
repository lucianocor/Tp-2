#include <stdio.h>
int producto();
int main() {
	int a,b;
	printf("Ingresar A: ");
	scanf("%d",&a);
	printf("\nIngresar B: ");
	scanf("%d",&b);
	printf("\nEl producto  de A Y B es %d ",producto(a,b));
	return 0;
}
int producto(int a,int b){
	int sum=0;
	do{
		sum=sum+a;
		b--;
	}while(b!=0);
	return sum;
}
