# include <stdio.h>
# include <stdlib.h >
# include <string.h>
# include <conio.h >
#include <stdio.h>
# define ListaVacia (listaD->princ== NULL)

typedef struct datos elemento; 
	typedef elemento * pelemento; 
		struct datos{
		 pelemento siguiente;
		 char clave[12];
		 pelemento anterior;
		 };
		 typedef struct lista ListDob;
		 struct lista{
			  pelemento princ;
			 pelemento final;
		 };
		void error(void)
		 {
			  perror("error: insuficiente espacio de memoria ");
			  exit(1);
		 }
		 
		 pelemento NuevoElemento()
		 {
			  pelemento q = (pelemento )malloc(sizeof(elemento));
			  if (!q) error();
			  return (q);
		 }
		 
		 void insertar(ListDob *, char []);
		 void borrar(ListDob *, char []);
		 void visualizar_lista(ListDob);
		 void menu(void);
	
		 main( ){
			  ListDob listaD;
			  char opcion, clave[12];
			  listaD.princ=listaD.final=NULL;
				  while (1)
			  {
					  do
					  {
						  system("cls");
								  menu();
								  opcion = toupper((getche( ));
					  }
									  while (opcion!= '1' && opcion != 'B'&& opcion!= 'V' && opcion !='S');
											 system("cls");
									  switch (opcion){
									  case 'I': 
										  printf(" \n lntroduzca la clave a añadir: ");
									  gets(clave);
									  insertar(&listaD, clave);
									  break;
									  case 'B':
										  printf(" \n lntroduzca la clave a borrar: ");
										  gets(clave);
										  borrar(&listaD, clave);
										  break;
									  case 'V':
										  visualizar_lista(listaD);
										  printf(" \n Pulse una tecla para continuar "); getch( );
										  break;
									  case 'S':
										  exit(0);
									  }
			  }
		 }
		 void insertar(ListDob*listaD, char clave[]){
			 pelemento q, pactual,panterior;
			 q=NuevoElemento();
			 strcpy(q->clave,clave);
			 q->anterior = q->siguiente=NULL;
			 
			 if (ListaVacia)
			 {
				  listaD->princ;
				  return;
			 }
					pactual = panterior = listaD->princ;
				  while (pactual != NULL && strcmp( clave, pactual->clave) > 0)
				  {
				panterior = pactual;
				pactual = pactual->siguiente;
				  }
				  if (panterior == pactual)
				  {
					q->siguiente = listaD->princ;
					listaD->princ = pactual->anterior = q;
				  }
				  else{
					  q->anterior = panterior;
					  q->siguiente = pactual;
						  panterior->siguiente = q;
					  if (pactual) pactual->anterior = q;
				  }
		 }
		 void borrar(ListDob *listaD,char clave[]){
			 pelemento panterior, pactual;
			 if (ListaVacia)
				 return;
			 while (pactual != NULL && strcmp(clave, pactual->clave) != 0)
			 {
				 panterior = pactual;
				 pactual = pactual->siguiente;
			 }
			 if (pactual == NULL)
			 {
				 printf("%s no esta en la lista \n", clave);
				 printf("\n Pulse una tecla para continuar"); getch( );
						return;
			 }
							if (panterior == pactual)
								{
									listaD -> princ = listaD -> princ -> siguiente;
								if (listaD->princ) listaD->princ->anterior = NULL;
							}
							else{
								panterior->siguiente = pactual->siguiente;	
								if (pactual->siguiente)
									panterior-> siguiente-> anterior = pactual-> anterior;
							}
							free(pactual);
				}
		 void visualizar_lista(ListDob listaD){
			 pelemento pactual = listaD.princ;
			 while (pactual != NULL)
			 {
				 printf("%s \n", pactual->clave);
						pactual = pactual->siguiente;
			 }
		 }
		 
		 void menu(){
			 printf("\n elija la opcion que desee\n");
			 printf("\n I. introducir un elemento\n");
			 printf("\n B. Borrar un elemento\n");
			 printf("\n V. visualizar la lista\n");
			 printf("\n S. salir\n");
		 }
