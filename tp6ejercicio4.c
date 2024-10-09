/*Una academia de danzas tiene una lista de alumnos, registrando de cada alumno los
	siguientes datos: “DNI del alumno, Apellido y Nombre del alumno, Código de curso de verano ([1] folclore,
	[2] español, [3] contemporáneo)”.
	Crear un programa que permita cargar la lista de alumnos, inicializando el campo Código de curso en 0.
	Luego ordene la lista por DNI del alumno utilizando el método de la Burbuja. Posteriormente, a través de
	un menú realizar las siguientes tareas:
	a) Agregar un alumno a la lista.
	b) Dado el DNI de un alumno inscribirlo a uno de los 3 cursos que se dictan, teniendo en cuenta que el
	cupo es de 10 personas para cada curso. Un alumno sólo puede estar inscripto en un curso a la vez.
	c) Permitir dar de baja a un alumno de un curso ingresando su DNI. (Cambiar Código a 0)
	d) Eliminar de la lista todos los alumnos que no se encuentren inscriptos en algún curso.
	e) Dado un Código de curso, mostrar la lista de inscriptos. */
#include <stdio.h>
#define max 20
typedef char Tcad[max];
typedef struct{
	long int DNI;
	Tcad nombre,apellido;
	int codigo_curso;
}alumnos;
typedef alumnos Tlista[max];
void inicializar(Tlista,int *n);
alumnos cargar_registro();
void leecad(Tcad cad, int tmax);
void ordenar_lista(Tlista L,int tam);
void ingresar(Tlista L,int *n);
int menu();
void asignar_curso(Tlista L,int *cont1,int *cont2,int *cont3,int n);
int verificar_tamanio(int codigo,int *cont1,int *cont2,int *cont3);
void asignar(alumnos*r,int *cont1,int *cont2,int *cont3	);
void bajar(alumnos*r, int *cont1,int *cont2,int *cont3);
void dar_de_baja(Tlista L,int *cont1,int *cont2,int *cont3,int n);
void mostrar_alumnos(Tlista L,int n);
void mostrar(alumnos*r);
void eliminar_alumno(Tlista L,int *n,int i);
void eliminar(Tlista L, int *n);
	
int main() {
	Tlista a;
	int cont1=0,cont2=0,cont3=0,n,opc;
	inicializar(a,&n);
	ordenar_lista(a,n);
	do{
		opc=menu();
	switch(opc){
	case 1:ingresar(a,&n);
		break;
	case 2: asignar_curso(a,&cont1,&cont2,&cont3,n);
		break;
	case 3:dar_de_baja(a,&cont1,&cont2,&cont3,n);
		break;
	case 4:eliminar(a,&n);
		break;
	case 5:mostrar_alumnos(a,n);
		break;
	default:printf("Salio del programa");
	break;
	}} while(opc!=0);
	return 0;
}
void inicializar(Tlista L, int *n){
	int i=0,band=1;
	while(band!=0){
		printf("\nIngrese un alumno ");
		L[i]=cargar_registro();
		i++;
		printf("\nIngrese 1 si quiere seguir cargando o 0 para salir:  ");
		scanf("%d",&band);
	}
	*n=i-1;}
alumnos cargar_registro(){
	alumnos r;
	printf("\ningresar el nombre del alumno: ");
	fflush(stdin);
	leecad(r.nombre,max);
	printf("\ningresar el apellido del alumno: ");
	fflush(stdin);
	leecad(r.apellido,max);
	printf("\ningresar el DNI del alumno: ");
	scanf("%ld",&r.DNI);
	r.codigo_curso=0;
	return r;
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
void ordenar_lista(Tlista L,int tam){
	int i,j;
		alumnos aux;
		for(i=0;i<tam;i++){
			for (j=i+1;j<=tam;j++){
				if (L[j].DNI<L[i].DNI){
					aux=L[j];
					L[j]=L[i];
					L[i]=aux;
			}
		}
	}
}
int menu(){
	int opc;
	printf("\nIngresar 1 para agregar un alumno a la lista. ");
	printf("\ningresar 2 para Dado el DNI de un alumno inscribirlo a uno de los 3 cursos que se dictan.");
	printf("\nIngresar 3 para Permitir dar de baja a un alumno de un curso ingresando su DNI. ");
	printf("\ningresar 4 para Eliminar de la lista todos los alumnos que no se encuentren inscriptos en algún curso.");
	printf("\nIngresar 5 Dado un Código de curso, mostrar la lista de inscriptos. ");
	printf("\nIngresar 0 para salir del programa ");
	scanf("%d",&opc);
	return opc;
}
void ingresar(Tlista L,int *n){
	L[*n]=cargar_registro();
	*n=*n+1;
	}
void asignar_curso(Tlista L,int *cont1,int *cont2,int *cont3,int n){
	int aux,i=0,band=0;
	printf("\nIngresar el Dni del alumno para asignarle un curso: ");
	scanf("%d",&aux);
	while(i<n){
		if(L[i].DNI==aux){
			if(L[i].codigo_curso==0){
				band=1;
				asignar(&L[i],cont1,cont2,cont3);
			}else
				printf("\nYa se ingreso un curso en este alumno");
		}
	i++;
	}
	if(band==0)
		  printf("\nNo se encontro el alumno en la lista");

}
void asignar(alumnos*r,int *cont1,int *cont2,int *cont3	){
	int codigo;
	printf("\nIngresar curso para el alumno %s ",r->nombre);
	printf("\ningresar 1 si quiere inscribirlo en folclore. ");
	printf("\ningresar 2 si quiere inscribirlo en espaniol. ");
	printf("\ningresar 3 si quiere inscribirlo en contemporaneo: ");
	scanf("%d",&codigo);
	if(codigo==1 || codigo==2 || codigo==3){
		r->codigo_curso=codigo;
	}else 
	   printf("CODIGO INVALIDO");
	if(verificar_tamanio(codigo,cont1,cont2,cont3)==1)
		printf("\nsupero el limite de alumnos en  este curso,ingresar a otro curso ");
}
int verificar_tamanio(int codigo,int *cont1,int *cont2,int *cont3){
	int band=0;
	if(codigo==1){
		*cont1=*cont1+1;
		if(*cont1>10)
			band=1;
	}else if(codigo==2){
	   *cont2=*cont2+1;
		if(*cont2>10)
			band=1;
	}else if(codigo==3){
	*cont3=*cont3+1;
		if(*cont3>10)
			band=1;
	}return band;
}
void dar_de_baja(Tlista L,int *cont1,int *cont2,int *cont3,int n){
	int aux,i=0;
	printf("\nIngresar el dni del alumno: ");
	scanf("%d",&aux);
	while(i<n){
		if(L[i].DNI==aux){
			bajar(&L[i],cont1,cont2,cont3);
			
		}
		i++;
	}
}
void bajar(alumnos*r, int *cont1,int *cont2,int *cont3){
	int codigo;
	codigo=r->codigo_curso;
	if(codigo==1){
		*cont1=*cont1-1;
	}else if(codigo==2){
		*cont2=*cont2-1;
	}else if(codigo==3)
		*cont3=*cont3-1;
	r->codigo_curso=0;
}
void mostrar_alumnos(Tlista L,int n){
	int i=0,aux;
	printf("\nIngresar el codigo del curso del que quiera ver sus inscriptos: ");
	scanf("%d",&aux);
	for(i=0;i<n;i++){
		if(aux==L[i].codigo_curso){
			printf("\nEl alumno %d: ",(i+1));
			mostrar(&L[i]);}
	}}
	void mostrar(alumnos*r){
		printf("\nEl nombre es %s ",r->nombre);
		printf("\nEl apellido es %s ",r->apellido);
		printf("\nEl nombre es %ld ",r->DNI);
	}
void eliminar(Tlista L, int *n){
	int i=0;
	while(i<*n){
		if(L[i].codigo_curso==0)
			eliminar_alumno(L,n,i);
		i++;
	}printf("\n\tAlumnos borrados");
}
void eliminar_alumno(Tlista L,int *n,int i){
	for(i;i<*n-1;i++){
		L[i]=L[i+1];
	}
	*n=*n-1;
}
