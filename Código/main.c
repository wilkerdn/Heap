#include "heap.h"

int main(){
	int tam=0,var=0,i=0,opcao=0,opcao2=0,opcao3=0,verifica=0;
	printf("Digite o tamanho do seu vetor: ");
	scanf("%d",&tam);
	int vetor[tam];
	printf("\nDigite os numeros do seu vetor\n");
	for(i=0;i<tam;i++){
		printf("Numero = ");
		scanf("%d",&vetor[i]);
	}
	printf("\n");
	while(opcao==0){
		printf("Verificar se e um heap maximo = 1\n");
		printf("Remover elemento prioritario = 2\n");
		printf("Imprimir em ordem decrescente = 3\n");
		printf("Imprimir arranjo = 4\n");
		printf("Encerrar o programa = 0\n");
		printf("Opcao = ");
		scanf("%d",&opcao2);
		if(opcao2==1){
			verifica = verifica_heapmax(vetor,tam);
			if(verifica==1){
			printf("\nO vetor e um heap maximo\n");
			}else if(verifica==0){
			printf("\nO vetor nao e um heap maximo\n\n");
			printf("Transformar o vetor em heap maximo = 1\n");
			printf("Voltar ao menu de opcoes = 2\n");
			printf("Opcao = ");
			scanf("%d",&opcao3);
				if(opcao3==1){
					balancear_heapmax(vetor,tam);
				}
			}
			printf("\n");
			opcao = 0;
		}else if(opcao2==2){
			verifica = verifica_heapmax(vetor,tam);
			if(verifica==0){
				balancear_heapmax(vetor,tam);
			}
			remove_prioritario(vetor,tam);
			opcao = 0;
		}else if(opcao2==3){
			imprimir_decrescente(vetor,tam);
			opcao = 0;
		}else if(opcao2==4){
			imprimir_arranjo(vetor,tam);
			opcao = 0;
		}else if(opcao2==0){
			printf("Programa finalizado!\n");
			opcao = 1;
		}else{
			printf("\nOpcao invalida, digite novamente\n\n");
			opcao = 0;
		}
	}
	return 0;
}
