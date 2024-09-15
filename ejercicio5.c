#include <stdio.h>
void ingresar(float*);
void entero(float,float*);
int main(){
	float x,pentX;
	ingresar(&x);
	entero( x,&pentX);
	printf("La parte decimal es %d",(int)pentX);
	return 0;
}
	void ingresar (float*x){
		printf("Ingresar un x: ");
		scanf("%f",x);
		printf("X es:%.4f ",*x);
	}
		void entero(float x,float *y){
			int z;
			printf("La parte entera de X es: %d",(int)x);
			z=x;
			*y=x-z;
			do{
				*y=*y*10;
			}while((int)*y != *y);
			
			
		}
			
