#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fecha();
void fecha_random();
int main() {
	int deuda;
	float tasa;
	srand(time(NULL));
	printf("Ingrese la deuda en pesos: ");
	scanf("%d",&deuda);
	fecha();
	printf("\nIngrese la tasa de interes diario ");
	scanf("%f",&tasa);
	fecha_random();
	return 0;
}
void fecha(){
	int mes,dia,ao;
	printf("\nIngrese la fecha de vencimiento: ");
	printf("DIA ");
	scanf("%d",&dia);
	if(dia>0 && dia<32){
	   printf("MES ");
		scanf("%d",&mes);
		if (mes<13 && mes>0){
			printf("AÑO ");
			scanf("%d",&ao);
			if(ao>2023){
				printf("\nFecha valida");
			}else printf("Fecha invalida ");
		}else printf("Fecha invalida ");
	}else printf("\nFecha invalida ");
	printf("\nLa fecha ingresada es %d/%d/%d",dia,mes,ao);
}
void fecha_random(){
	int diasF,mesF,aoF;
	diasF=rand() % (30-1+1)+1;
	mesF=rand() % (12-1+1)+1;
	aoF=rand() % (2030-2023+1)+2024;
	printf("Fecha generada posterior al pago es %d/%d/%d ",diasF,mesF,aoF);	

}

