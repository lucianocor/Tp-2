#include <stdio.h>
int ingresar(int*);
void primo(int*);
int main() {
	int x;
	while(ingresar(&x)>0){
		primo(&x);
	}
	return 0;
}
int ingresar(int*x){
	printf("\nIngresar un X: ");
	scanf("%d",x);
	return *x;
}
void primo(int *k){
	int pd=2,dig,sum=0,aux=0;
	while(pd<=*k/2 && *k%pd != 0){
		pd=pd+1;}
	if(pd>(*k/2) && (*k != 1)){
		while(*k!=0){
		dig=*k%10;
		sum=sum*10+dig;
		*k=*k/10;}
		printf("\nEl invertido es %d",sum);			
	}
	else{
		while(*k!=0){
			dig=*k%10;
			if(dig==9 ||dig==8||dig==6||dig==4){
				aux=dig+aux*10;}
		*k=*k/10;
		}
	printf("\nEl numero modificado queda igual a=%d ",aux
		   );
	}}


