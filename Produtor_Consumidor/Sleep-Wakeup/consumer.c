#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include<errno.h>
#define N 10 //números de itens máximos para o buffer


void remove_item(int *count)
{
	printf("Item removido\n");
	*count = *count - 1;
}
void consume_item(int *count, int *b)
{
	if (*count > 0)
	{
		remove_item(count);	
	}
	else
	{
		*b = 0;
	}
}
int main ()
{
  	key_t shm_key_count = 6166529;// chave da área compartilhada para o count
	key_t shm_key_proc_var_A = 6166500;// chave da área compartilhada para proc_var_A
	key_t shm_key_proc_var_B = 6166600;// chave da área compartilhada para proc_var_B
  	
	const int shm_size = 1024;

  	int shm_id_count, shm_id_proc_var_A, shm_id_proc_var_B;
  	int* count;
	int* proc_var_A; //variável usada para dar um wakeup no processo A (produtor)
	int* proc_var_B; //variável usada para dar um wakeup no processo B (consumidor)
	
  	/* Alocar um segmento de memória compartilhada para o count. */
  	shm_id_count = shmget (shm_key_count, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);
	if(shm_id_count < 0)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no alocamento de um segmento de memória para o count: ");
 		exit(1);
 	}

	/* Alocar um segmento de memória compartilhada para o proc_var_A. */
  	shm_id_proc_var_A = shmget (shm_key_proc_var_A, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);
	if(shm_id_proc_var_A < 0)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no alocamento de um segmento de memória para o proc_var_A: ");
 		exit(1);
 	}

	/* Alocar um segmento de memória compartilhada para o proc_var_B. */
  	shm_id_proc_var_B = shmget (shm_key_proc_var_B, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);
	if(shm_id_proc_var_B < 0)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no alocamento de um segmento de memória para o proc_var_B: ");
 		exit(1);
 	}

  	/* Acoplar count a um segmento de memória compartilhado. */
  	count = (int*) shmat (shm_id_count, 0, 0);
	if(count == (int*)-1)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no acoplamento de segmento de memória para o count: ");
 		exit(1);
 	}
	*count = 0; //iniciando com count = 0

	/* Acoplar proc_var_A a um segmento de memória compartilhado. */
  	proc_var_A = (int*) shmat (shm_id_proc_var_A, 0, 0);
	if(proc_var_A == (int*)-1)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no acoplamento de segmento de memória para o proc_var_A: ");
 		exit(1);
 	}
	*proc_var_A = 1; //iniciando proc_var_A com 1

	/* Acoplar proc_var_B a um segmento de memória compartilhado. */
  	proc_var_B = (int*) shmat (shm_id_proc_var_B, 0, 0);
	if(proc_var_B == (int*)-1)
 	{
 		printf("%s",strerror(errno));
 		perror("Erro no acoplamento de segmento de memória para o proc_var_B: ");
 		exit(1);
 	}
	*proc_var_B = 0; //iniciando proc_var_B com 0

	/*Codigo do consumidor*/
	while (1)
	{

		if (*proc_var_B == 1)
		{
			consume_item(count, proc_var_B);
		}
		else
		{
			sleep(2);//sleep(consumer)
		}
		if (*count == (N - 1))
		{
			*proc_var_A = 1;// wakeup(producer)
		}
		
	}

  	return 0;
}
