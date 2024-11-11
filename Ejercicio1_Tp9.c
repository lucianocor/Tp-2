#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int X,Y;
}Tpar_ordenado;

typedef Tpar_ordenado* Tptr;

int calculo(Tpar_ordenado* );
Tptr Cargar_par();
void Mostrar_Nodo(Tptr );
void mostrar_menor(Tptr aux1,Tptr aux2,Tptr aux3);
int main() {
	Tptr Par1,Par2,Par3;
	Par1=Par2=Par3=NULL;
	Par1=Cargar_par();
	Par2=Cargar_par();
	Par3=Cargar_par();
	mostrar_menor(Par1,Par2,Par3);
	free(Par1);
	free(Par2);
	free(Par3);
	return 0;
}
Tptr Cargar_par(){
	Tptr aux;
	aux=(Tptr) malloc(sizeof(Tpar_ordenado));
	printf("\nIngrese el numero X: ");
	scanf("%d",&aux->X);
	printf("\nIngrese el valor de Y: ");
	scanf("%d",&aux->Y);
	printf("\nCarga hecha ");
	return aux;
}
void mostrar_menor(Tptr aux1,Tptr aux2,Tptr aux3){
	if(calculo(aux1)<calculo(aux2) && calculo(aux1)<calculo(aux3))
		Mostrar_Nodo(aux1);
}
int calculo(Tpar_ordenado* aux){
 	int suma;
	suma=aux->X+aux->X-(aux->Y) * 10;
	return suma;
}
	void Mostrar_Nodo(Tptr Aux){
	printf("\nEl menor par es %d/%d", Aux->X,Aux->Y);
	
		}
