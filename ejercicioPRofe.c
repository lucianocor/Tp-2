/*Un consultorio de mascotas presetna las siguientes actividades, clinica, peluqueria, ecogrefia y rayos X
	Este tiene una lista de atencion de mascotas por dia con la siguiente informacion:
	Nombre de la mascota, nombre del dueño, codigo de identificacion de la mascota(numerico),
	horas de atencion(horas y minutos que pueden ser represetnados por un real), y especialidad
	Crear un programa que permita: Iniciar el proceso con una lista vacia de atenciones. Y luego presente un menu con las siguientes opcioens:
	1- Agregar una atencion de mascota a la lista, manteniendo la lista ordenada por codigo de identificacion.
	2- Dado un codigo de identificacion eliminar todos los registros vinculados a ese codigo.
	3- Dada una hora atencion mostra todas las mascotas que estan anoptadas en ese horario y la especialidad de atencion reservada, considerar
	que los turnos se dan cada media hora y que en un mismo horario pueden haber reservados diferentes turnos para diferentes especialidades.*/
#include <stdio.h>
#define max 30
#include <string.h>
typedef char Tcad[max];

typedef struct{
	Tcad nombre_mascota,nombre_duenio;
	int codigo,horas,especialidad;
}Tclinica;

typedef Tclinica Tlis[max];
void ingresar(Tlis L,int *n);
int menu();
Tclinica ingresarcliente();
void ordenar(Tlis L,int *n);
void leecad(Tcad cad, int tmax);
void eliminar_registro(Tlis A,int i,int *n);
void eliminar(Tlis A,int *n);
void turnos(Tlis A,int I,int *cont1,int *cont2,int *cont3,int *cont4);
void mostrar(Tlis A,int n);
void mostrar_registro(Tclinica a);



int main(){
	Tlis ingreso;
	int cont1=0,cont2=0,cont3=0,cont4=0,op,n=0;
	do{
	op=menu();
	switch(op){
	case 1:ingresar(ingreso,&n);
		turnos(ingreso,n,&cont1,&cont2,&cont3,&cont4);
		break;
	case 2:eliminar(ingreso,&n);
		break;
	case 3:mostrar(ingreso,n);
		break;
	default:
		printf("Slio del programa ");
		break;
	}} while(op!=0);
	return 0;
}
int menu(){
	int op; 	
	printf("\nIngrese 1 si quiere agregar una atencion de mascota a lista ordenada por el codigo de identificacion");
	printf("\nIngrese 2 si dado un codgio de identificacion eliminar todos los registros vinculados a ese codigo.");
	printf("\nIngrese 3 Dada una hora atencion mostra todas las mascotas que estan anoptadas en ese horarios");
	printf("\nIngrese 0 si quiere salir del programa: ");
	scanf("%d",&op);
	return op;
}
	void ingresar(Tlis A,int *n){
		*n=*n+1;
		A[*n]=ingresarcliente();
		ordenar(A,n);
	}
	Tclinica ingresarcliente(){
		Tclinica a;
		printf("\nIngrese el nombre del animal: ");
		fflush(stdin);
		leecad(a.nombre_mascota,max);
		printf("\nIngrese el nombre del cliente: ");
		fflush(stdin);
		leecad(a.nombre_duenio,max);
		printf("\nIngrese la atencion que quiera: 1 para clinica, 2 para peluqueria, 3 para ecogrefia y 4 para rayos X ");
		scanf("%d",&a.especialidad);
		printf("Ingrese el codigo de verificacion: ");
		scanf("%d",&a.codigo);
		return a;
	}
	void ordenar(Tlis L,int *n){
	int i=1,j;
	Tclinica aux;
	for(i=2;i<=*n;i++){
		aux=L[i];
		L[0]=aux;
		j=i-1;
		while(aux.codigo<L[j].codigo){
			L[j+1]=L[j];
			j=j-1;
		}
		L[j+1]=aux;
		}
	}
	void leecad(Tcad cad, int tmax){
		
		int i;
		char c;
		i=0;
		c=getchar();
		while(c!='\n' && c!=EOF && i< tmax-1) {
			cad[i]=c;
			i++;
			c=getchar();
		} 
		cad[i]='\0';
		while(c!='\n' && c!=EOF)
			c=getchar();
	}

void turnos(Tlis A,int n,int *cont1,int *cont2,int *cont3,int *cont4){
	int I;
	I=n;
	if(A[I].especialidad==1){
		*cont1+=30;
		A[I].horas=*cont1;
	}else if(A[I].especialidad==2){
		*cont2+=30;
		A[I].horas=*cont2;
	}else if (A[I].especialidad==3){
		*cont3+=30;
		A[I].horas=*cont3;
	}else if(A[I].especialidad==4){
		*cont4+=30;
	A[I].horas=*cont4;}
}
void eliminar(Tlis A,int *n){
	int aux,i=1;
	printf("Ingrese el codigo del animal: ");
	scanf("%d",&aux);
	while(i<*n && aux==A[i].codigo)
		i++;
	if(i<*n){
		eliminar_registro(A,i,n);
	}else printf("\n No se encontro el codigo del animal");
}
void eliminar_registro(Tlis A,int aux,int *n){
	int i;
	for(i=aux;i<*n-1;i++){
		A[i]=A[i+1];
	}
	*n=*n-1;
}
	void mostrar(Tlis A,int n){
		int aux,i;
		printf("\nIngresar la hora que quiera ver los turnos ");
		scanf("%d",&aux);
		aux=aux*120;
		for(i=1;i<=n;i++){
			if(A[i].horas>=aux-120 && A[i].horas<=aux)
			mostrar_registro(A[i]);
		}}
void mostrar_registro(Tclinica a){
		printf("\nLA mascota es %s y esta anotado para la atencion de: %d",a.nombre_mascota,a.especialidad);
		}
	
