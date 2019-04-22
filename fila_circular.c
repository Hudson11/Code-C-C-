#include <stdio.h>
#include <stdlib.h>

#define TAM 8

struct fila {
	int dados[TAM];
	int inicio;
	int fim;
};


int empty(struct fila* f){
	if(f->inicio == f->fim){
		return 1;
	}else{
		return 0;
	}
}


void print_fila (struct fila* f){
	
	if (empty(f)){
		printf ("Fila Vazia.\n");
		return;
	}
	
	int i;
	
	if(f->inicio < f->fim){
		for (i = f->inicio; i < f->fim ; i++){
			printf("%d ", f->dados[i]);
		}
	}else{
		for (i = f->inicio; i < TAM ; i++){
			printf("%d ", f->dados[i]);
		}
		for (i = 0; i < f->fim + 1; i++){
			printf("%d ", f->dados[i]);
		}
	}	

	printf ("\n");
	
}

void enqueue(struct fila* f, int dado){
	
	f->dados[f->fim] = dado;
	
	int estado = f->fim;
	
	if (f->fim == TAM){
		f->fim = 0;
	}else{
		f->fim = f->fim+1;
	}
	
	//tratamento do overflow
	if(f->inicio == f->fim){
		printf("Estouro de fila. Insercao cancelada.\n");
		f->fim = estado;
		return;
	}
	
	//print_fila(f);
	return;
}

int dequeue (struct fila* f){
	
	if (empty(f)){
		print_fila(f);
		return -1;
	}
	
	int saida;
	
	saida = f->dados[f->inicio];
	
	if(f->inicio == TAM-1){
		f->inicio = 0;
	}else{
		f->inicio = f->inicio+1;
	}
	
	
	print_fila(f);
	return saida;
	
}

void anda_esquerda_direita(struct fila* f){
	
	if(f->inicio == TAM){
		f->inicio = 0;
		f->fim = f->fim + 1;
	}
	
	f->fim = f->inicio;
	f->inicio = f->inicio + 1;
	
}

void anda_direita_esquerda(struct fila* f){
	
	if(f->fim == 0){
		f->fim = TAM;
		f->inicio = f->inicio - 1;
	}
	
	f->inicio = f->fim;
	f->fim = f->fim - 1;
}


int main(){
	
	//inicializa
	struct fila f;
	f.fim = 0;
	f.inicio = 0;
	
	enqueue(&f, 1);
	enqueue(&f, 2);
	enqueue(&f, 3);
	enqueue(&f, 4);
	enqueue(&f, 5);
	enqueue(&f, 6);
	enqueue(&f, 7);
	enqueue(&f, 8);
	
	while(1){
		anda_direita_esquerda(&f);
		print_fila(&f);
		int i;
		for(i = 0; i < 300000000; i++){ // delay genérico, pelo amor de deus não repitam isso em casa crianças...
		}
	}
	

    return 0;
    
}
