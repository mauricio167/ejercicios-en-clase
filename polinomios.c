#include <stdio.h>
#include <stdlib.h>
typedef struct datos elemento;
typedef elemento *pelemento;
struct datos{
	float coeficiente;
	int abc;
	pelemento siguiente;
};
typedef struct lista listcir;
struct lista{
	pelemento cabecera;
	pelemento anterior;
	pelemento actual;
	
};
void error(){
	perror("insuiciente memoria\n");
	exit(1);
}
pelemento nuevoelemento(){
	pelemento q = (pelemento)malloc(sizeof(elemento));
	if (!q) error();
	return (q);
}
void leer_polinomio (listcir*);
void inicializar(listcir*);
void comparar(listcir*,listcir*);
void sumar_coeficiente(listcir*,listcir*);
void restar_coeficiente (listcir*,listcir*);
void insertar_nuevo_termino(listcir*,listcir*);
void eliminar_termino(listcir*);
void escribir_polinomio(listcir);

int main(){
	listcir polp,polq;
	leer_polinomio(&polp);
	leer_polinomio(&polq);
	
	inicializar(&polp);
	inicializar(&polq);
	comparar(&polp,&polq);
	
	escribir_polinomio(polq);
}

void leer_polinomio(listcir *polx){
	int abc;
	float coef;
	pelemento q;
	polx -> cabecera= nuevoelemento();
	polx ->cabecera->coeficiente=0;
	polx ->cabecera->abc=-001;
	polx->cabecera->siguiente=polx->cabecera;
	polx->anterior=polx->actual=NULL;
	
	printf("introducir los terminos del polinomioen orden creciente (abc: x^a,y^b,z^c)\n");
	printf("para finalizar teclear coeficiente=0\n");
	printf("coeficiente:         ");
	scanf("%f",&coef);
	while(coef){
		printf("exponentes abc sin espacios:     \n");
		scanf("%d",&abc);
		q=nuevoelemento();
		q->coeficiente= coef;
		q->abc=abc;
		q->siguiente=polx->cabecera->siguiente;
		polx->cabecera->siguiente=q;
		
		printf("coeficiente:           \n");
		scanf("%f",&coef);
	}
} 

void inicializar(listcir *polx){
	polx->anterior= polx->cabecera;
	polx->actual=polx->cabecera->siguiente;
}

void comparar(listcir *polp,listcir *polq){
	while(!(polp->actual->abc < 0)){
		while(polp->actual->abc < polq->actual->abc){
			polq->anterior=polq->actual;
			polq->actual= polq->actual->siguiente;
		}
		if(polq->actual->abc == polq->actual->abc){
			sumar_coeficiente(polp,polq);
		}else{
			insertar_nuevo_termino(polp,polq);
			polq->actual= polp->actual->siguiente;
		}
	}
	
}

void sumar_coeficiente(listcir *polp, listcir *polq){
	if(polp->actual->abc < 0){
		return;
	}else{
		polq->actual->coeficiente += polp->actual->coeficiente;
		if(polq->actual->coeficiente==0){
			eliminar_termino(polq);
			polp->actual=polp->actual->siguiente;
		}else{
			polp->actual = polp->actual->siguiente;
			polq->anterior=polq->actual;
			polq->actual= polq->actual->siguiente;
		}
	}
}
void insertar_nuevo_termino(listcir *polp,listcir *polq){
pelemento q;
q= nuevoelemento();
q->coeficiente = polp->actual->coeficiente;
q->abc = polp->actual->abc;
q->siguiente=polq->actual;
polq->anterior=polq->anterior->siguiente =q;
return;
}

void eliminar_termino(listcir *polq){
pelemento q;
q=polq->actual;
polq->actual= polq->actual->siguiente;
polq->anterior->siguiente= polq->actual;
free(q);
return;
}

void escribir_polinomio(listcir polq){
printf("suma de polinomios\n");
polq.cabecera= polq.cabecera->siguiente;
while(polq.cabecera ->abc != -1){
	printf("coef: %+g exps. de x y z %03d\n",polq.cabecera->coeficiente, polq.cabecera->abc);
	polq.cabecera=polq.cabecera->siguiente;
	}
}
