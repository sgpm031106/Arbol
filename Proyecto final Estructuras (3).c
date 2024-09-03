

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

main(){
	//Declaracion de variables
	int i,j,x=0,xx=0,op=0,q=0,niv=0,uln=0,posnod=0,todosnod=0,h1=0,h2=0,cont=0,nod=1,totnod=0,anch=0,anchmax=0;
	
	//Introduce los niveles del árbol
	setlocale(LC_ALL, "");
	printf("Programa que determina si el árbol ingresado es completo o no completo, te da su altura y su anchura\n");
	do{
		printf("\nIntroduce cuántos niveles tiene tu árbol: ");
		scanf("%d",&niv);
		if (niv<0){
				printf("\nNo puede haber niveles negativos\n");
		}
		else if (niv==0){
			printf("\nNo existen árboles sin niveles\n");
		}
		else if (niv==1){
			printf("No puedes ingresar un árbol con solo un nodo\n");
		}
	}while (niv<2);
	
	//Calcula la cantidad de nodos que tiene el árbol.
	for (i=0;i<niv;i++){
		totnod+=pow(2,i);
	}
	int arbol[totnod];//Declaracion del vector dende se almacenará el árbol
	do{
		printf("\nIntroduce el valor de la raiz (nivel 0) de tu árbol que sea diferente a cero (0): ");
		scanf("%d",&arbol[0]);
		printf("\n");
		if (arbol[0]==0){
			printf("El valor de la raiz debe ser diferente a 0\n");	
		}
	}while(arbol[0]==0);
	
	for (i=1;i<niv; i++){
		printf ("Introduce el valor de los nodos del nivel %d de tu arbol de izquierda a derecha. Si no hay nodo coloca un cero (0)\n",i);
		nod*=2;
		anch=0;
		for (j=0; j<nod; j++){
			cont++;
			printf ("Nodo %d: ",j+1);
			scanf("%d",&arbol[cont]);
			if(arbol[cont]!=0){
				anch++;
			}
		}
		if (anch>anchmax){
			anchmax=anch;
		}
		printf ("\n");
	}
	printf ("El arbol tiene una altura de: %d\n",niv);
	printf ("El árbol tiene una anchura de: %d\n",anchmax);
	printf ("\n");
		
	//Imprimir si el arbol binario es completo o no.
	nod=1;
	todosnod=1;
	uln=0;
	cont=0;
	q=0;
	for (i=0;i<niv; i++){
		if(i!=niv-1){
			for (j=0; j<nod; j++){//Recorre los niveles del arbol menos el último.
				if (arbol[cont] == 0){
					printf("El árbol no es completo.\n");
					q=30;
					break;
				}
				cont++;
			}
			if (q==30){
				break;
			}
		}
		else if (i==niv-1){
			uln=todosnod-nod;//Primer nodo del ultimo nivel.
			for (j=0; j<nod-1; j++){//Recorre el ultimo nivel de izquierda a derecha.
				if(arbol[uln]==0 && arbol[uln+1]!=0){
					printf("El árbol no es completo.\n");
					break;
				}
				uln++;
			}
			if (uln==todosnod-1){
				printf ("El árbol es completo.\n");
				break;
			}
		}
		nod*=2;//Número de nodos por nivel.
		todosnod+=nod;//Numero de nodos recorridos.
	}
	
	do{
		//Ingresar el valor de un nodo e imprimir si este está dentro del arbol ademas de sus hijos.
		printf ("\nIngresa el valor que almacena un nodo: ");
		scanf("%d", &x);
		xx=-1;
		for(cont=0; cont<=totnod; cont++){
			if(x==0){
				printf("\nEl nodo no existe dentro del árbol.\n");
				break;
			}
			else if(x == arbol[cont]){
				printf("\nEl nodo %d existe dentro del árbol.\n",x);
				xx=cont;
				//Encontrar posición de los hijos.
				nod=1;
				todosnod=1;
				posnod=0;
				h1=0;
				h2=0;
				for(i=0; i<niv; i++){
					if (xx<todosnod){
						posnod=nod-((todosnod-1)-xx);//Posicion del nodo buscado en el nivel.
						h1=(todosnod-1)+((posnod*2)-1);//Posición de hijo izquierdo.
						h2=(todosnod-1)+(posnod*2);//Posición del hijo derecho.
						if (i<niv-1){
							if (arbol[h1]==0 && arbol[h2]==0){
								printf ("\nEl nodo con valor %d no tiene hijos\n",x);
							}
							else if (arbol[h1]==0){
								printf("\nEl hijo izquierdo del nodo con valor %d no existe",x);
								printf("\nEl hijo derecho del nodo con valor %d es: %d\n",x,arbol[h2]);
							}
							else if (arbol[h2]==0){
								printf("\nEl hijo izquierdo del nodo con valor %d es: %d",x,arbol[h1]);
								printf("\nEl hijo derecho del nodo con valor %d no existe\n",x);
							}
							else{
								printf("\nEl hijo izquierdo del nodo con valor %d es: %d",x,arbol[h1]);
								printf("\nEl hijo derecho del nodo con valor %d es: %d\n",x,arbol[h2]);	
							}
						}
						else{
							printf ("\nLos hijos del nodo con valor %d no existen\n");
						}
						break;
					}
					nod*=2;//Número de nodos por nivel.
					todosnod+=nod;//Numero de nodos recorridos.
				}
			}
		}
		if (x==0){
			continue;
		}
		else if(xx==-1){
			printf("\nEl nodo no existe dentro del árbol.\n");
		}
		printf("\nDeseas buscar otro nodo (Escribe 1 para si y cualquier otro número para no): ");
		scanf ("%d",&op);
	}while(op==1);
	printf("\n");
	system("pause");
}
