#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include<errno.h>
#define N 10 //número de vagas no buffer



void remove_item()
{
	printf("Item removido\n");
}
void consume_item()
{
	// item consumido
}

int main ()
{
  	key_t shm_key_mutex = 6166529;// chave da área compartilhada para o mutex
	key_t shm_key_empty = 6166500;// chave da área compartilhada para o empty
	key_t shm_key_full = 6166600;// chave da área compartilhada para o full
  	
	const int shm_size = 1024;// tamanho de cada área compartilhada

  	int shm_id_mutex, shm_id_empty, shm_id_full;
  	int* mutex;
	int* empty;
	int* full;
  
  	/* Alocar um segmento de memória compartilhada para o mutex. */
  	shm_id_mutex = shmget (shm_key_mutex, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);
	if(shm_id_mutex < 0)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no alocamento de um segmento de memória para o mutex: ");
 		exit(1);
 	}

	/* Alocar um segmento de memória compartilhada para o empty. */
  	shm_id_empty = shmget (shm_key_empty, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);
	if(shm_id_empty < 0)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no alocamento de um segmento de memória para o empty: ");
 		exit(1);
 	}

	/* Alocar um segmento de memória compartilhada para o full. */
  	shm_id_full = shmget (shm_key_full, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);
	if(shm_id_full < 0)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no alocamento de um segmento de memória para o full: ");
 		exit(1);
 	}


  	/* Acoplar mutex ao seu segmento de memória compartilhado. */
  	mutex = (int*) shmat (shm_id_mutex, 0, 0);
	if(mutex == (int*)-1)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no acoplamento de segmento de memória para o mutex: ");
 		exit(1);
 	}
	
	/* Acoplar empty ao seu segmento de memória compartilhado. */
  	empty = (int*) shmat (shm_id_empty, 0, 0);
	if(empty == (int*)-1)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no acoplamento de segmento de memória para o empty: ");
 		exit(1);
 	}

	/* Acoplar full ao seu segmento de memória compartilhado. */
  	full = (int*) shmat (shm_id_full, 0, 0);
	if(full == (int*)-1)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no acoplamento de segmento de memória para o full: ");
 		exit(1);
 	}
	*full = 0; //o buffer está inicialemte vazio
	
  	/*Código do consumidor*/
	while (1)
	{
	
		while (*full == 0); // buffer vazio
		*full = *full - 1; //down no full
		while (*mutex == 0);
		*mutex = *mutex - 1; //down no mutex
		remove_item();
		while (*mutex == 1);
		*mutex = *mutex + 1; //up no mutex
		while (*empty == N); //buffer vazio
		*empty = *empty + 1;
		
	}

  	return 0;
}
