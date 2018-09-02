#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define listavacia (cabecera== NULL)

typedef struct datos elemento;
struct datos{
	int dato;
	elemento *siguiente;
};


// funciones
void error(void){
	perror("error: insuficiente espacio de memoria");
	exit(1);
}

elemento *nuevoelemento()
{
	elemento *q = (elemento*)malloc(sizeof(elemento));
	if(!q){ error();}
		return (q);
}
//prototipo de funciones
void menu(void);
void anadir(elemento **,int);
void borrar(elemento **,int);
elemento *buscar(elemento *,int);
void ver(elemento*);
int main(){
	elemento *cabecera = NULL;
	elemento *q;
	int opcion, dato, k=10;
	 while(1){
		 do{
			 //system("cls");
			 menu();
			 opcion= getche();
		 }while(opcion<'1'||opcion>'5');
		 //system("cls");
	 switch(opcion){
	 case '1':
		 printf("ingrese un dato");
		 scanf("%d",&dato);
		 anadir(&cabecera,dato);
		 break;
	 case '2':
		 printf("borrar dato");
		 scanf("%d",&dato);
		 anadir(&cabecera,dato);
		 break;
	 case '3':
		 printf("buscar dato");
		 scanf("%d",&dato);
		 q=buscar(cabecera,dato);
		 if(q)
			 q -> dato +=k;
		 else printf("lista vacía\n");
		 break;
	 case '4':
		 printf("Ver lista");
		 break;
	 case '5': 
		 exit(0);
	 }
	 printf("\n presione una tecla para continuar");getch();
	 }	 
}
void menu(){
	printf("\n  Elija una opcion");
	printf("\n  añadir un elemento\n");
	printf("\n  eliminar un elemento de la lista\n");
	printf("\n  buscar un elemento en la lista\n");
	printf("\n  ver lista\n");
	printf("\n  salir\n");
}

void anadir(elemento **cab, int dato){
	elemento *cabecera= *cab;
	elemento *actual= cabecera, *anterior =cabecera, *q;
	if(listavacia){
		cabecera= nuevoelemento();
		cabecera -> dato = dato;
		cabecera -> siguiente= NULL;
		*cab = cabecera;
		return;
	}
	
	while(actual != NULL && dato> actual->dato){
		anterior= actual;
		actual= actual -> siguiente;
	}
	q= nuevoelemento();
	if(anterior== actual){
		q->dato= dato;
		q->siguiente=cabecera;
		cabecera=q;
	}else{
		q->dato= dato;
		q->siguiente= actual;
		anterior->siguiente=q;
	}
	*cab= cabecera;
}
//encontrar un dato y borrar
void borrar(elemento **cab, int dato){
	elemento *cabecera=*cab;
	elemento *actual= cabecera, *anterior=cabecera;
	if(listavacia){
		printf("la lista no contiene ningun elemento");
		return;
	}
	//wntrar a la lista y borrar
	while(actual != NULL && dato != actual -> dato){
		anterior=actual;
		actual=actual->siguiente;
	}
	//si el dato no existe
	if(actual== NULL) return;
	//si el dato se encuentra va a borrar el dato
	
	if(anterior==actual){
		cabecera= cabecera->siguiente;
	}else {
		anterior->siguiente=actual-> siguiente;
	free(actual);
	*cab=cabecera;}
}
 //aqui vamos a borrar un elemento de la lista
elemento *buscar(elemento *cabecera, int dato){
	elemento *actual= cabecera;
	while (actual !=NULL && dato != actual->dato){
		actual= actual -> siguiente;}
		return(actual);
}
// ver lista
void ver(elemento *cabecera)
{
	elemento *actual= cabecera;
	if(listavacia){
		printf("La lista esta vacia\n");
	}else{
		while (actual != NULL){
			printf("%d", actual->dato);
			actual= actual->siguiente;
		}
		printf("\n");
	}
}
