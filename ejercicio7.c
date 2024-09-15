#include <stdio.h>
void ingresar(int*,int*);
void salida(int x,int y,int z,int t);
void reducar(int,int,float*,float*);
int main(){
	float nur,der;
	int n,nu,i=1,de,b=0,may=0,men=1000,maynu,mayde,mennu,mende;
	printf("Ingrese un N :");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		ingresar(&nu,&de);
		reducar(nu,de,&nur,&der);
		if(nur/der>may ){
			may=nur/der;
			maynu=nur;
			mayde=der;}
			if(b==0){
		    men=nur/der;
			mennu=nur;
			mende=der;
			b=1;}
		else if(nur/der<men){
			men=nur/der;
			mennu=nur;
			mende=der;}
	}
	salida(maynu,mayde,mennu,mende);
	
	return 0;
}
void ingresar(int*x,int*y){
	printf("\nIngresar el numerador: ");
	scanf("%d",x);
	printf("Ingresar el denominador: ");
	scanf("%d",y);
	printf("El numero es %d/%d ",*x,*y);
}
	
void reducar(int x,int y,float *ar,float *br){
	int i=1;
	while(i<=x){
		if(x%i==0 && y%i==0){
			*ar=x/i;
			*br=y/i;
			}
		i++;	
		}		
	}
void salida(int x,int y,int z,int t){
	printf("\nLa mayor fraccion  es %d/%d y la menor fraccion es %d/%d",x,y,z,t);
}
