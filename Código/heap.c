#include "heap.h"

int verifica_heapmax(int aux[],int x){
	int i=0,verif=0;
	for(i=0;i<x;i++){
		if(2*i+1>x-1){
			break;
		}
		if(aux[2*i+1]>aux[i]||aux[2*i+2]>aux[i]){
		verif = 1;
		return 0;		
		}
	}
	if(verif==0){
		return 1;
	}
}

void balancear_heapmax(int aux[],int x){
	int i=0,y=0;
	for(i=0;i<x;i++){
		if((2*i+1)>(x-1)){
			break;
		}else if((2*i+2)>(x-1)){
			if(aux[2*i+1]>aux[i]){
				y = aux[i];
				aux[i] = aux[2*i+1];
				aux[2*i+1] = y;
				i=0;
				balancear_heapmax(aux,x);
			}
		}else		
			if(aux[2*i+1]>aux[i]&&aux[2*i+2]>aux[i]){
				if(aux[2*i+1]>aux[2*i+2]){
					y = aux[i];
					aux[i] = aux[2*i+1];
					aux[2*i+1] = y;
				}else if(aux[2*i+1]<aux[2*i+2]){
					y = aux[i];
					aux[i] = aux[2*i+2];
					aux[2*i+2] = y;
				}
				balancear_heapmax(aux,x);
			}else if(aux[2*i+1]>aux[i]){
				y = aux[i];
				aux[i] = aux[2*i+1];
				aux[2*i+1] = y;
				i=0;
				balancear_heapmax(aux,x);
			}else if(aux[2*i+2]>aux[i]){
				y = aux[i];
				aux[i] = aux[2*i+2];
				aux[2*i+2] = y;
				i=0;
				balancear_heapmax(aux,x);
			}
	}	
}

void remove_prioritario(int aux[],int x){
	printf("\nElemento removido: %d\n\n",aux[0]);
	aux[0] = aux[x-1];
	aux[x-1] = -1;
	balancear_heapmax(aux,x);
}

void imprimir_arranjo(int aux[],int x){
	int i=0;
	printf("\nArranjo: ");
	for(i=0;i<x;i++){
	printf("%d ",aux[i]);
	}
	printf("\n\n");
}

void imprimir_decrescente(int aux[],int x){
	int i=0,a[x],temp=0;
	for(i=0;i<x;i++){
		a[i] = aux[i];
	}
	for(i=0;i<x;i++){
		if(i+1>x-1){
			break;
		}
		if(a[i]<a[i+1]){
			temp=a[i+1];
			a[i+1]=a[i];
			a[i]=temp;
			i = 0;
		}
	}
	printf("\nArranjo em ordem decrescente: ");
	for(i=0;i<x;i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");
}	
