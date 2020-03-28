#include <iostream>

/* Número de jobs */
#define N 4

using namespace std;

int main()
{
    /* Jobs com suas tarefas e tempos de execução de cada tarefa */
    int job0[5] = {16, 16, 13, 12, 20};
    int job1[3] = {10, 19, 7};
    int job2[2] = {4, 15};
    int job3[3] = {15, 20, 14};

    /* Tempo de execução total de cada job */
    int job_execution_time[N] = {77, 36, 19, 49};

    /* Vetor que armazena os identificadores dos jobs */
    int job_id[N] = {0, 1, 2, 3};

    /* Valor inicial de comparação */
    int shortest_job = job_execution_time[0];
    int aux;
    int j = 0;
    /* Execução dos jobs na fila de espera */
    while (j < N)
    {
        /* Valor inicial de comparação */
        shortest_job = job_execution_time[j];

        /* O sistema escolhe o menor job */
        for (int i = j; i < N; i++)
        {
            if (job_execution_time[i] < shortest_job)
            {
                aux = job_execution_time[i];
                job_execution_time[i] = shortest_job;
                shortest_job = aux;

                aux = job_id[i];
                job_id[i] = job_id[j];
                job_id[j] = aux;
            }
        }
        /* O sistema executa o menor job até ele acabar */
        cout << "Job " << job_id[j] << " executado e finalizado\n";
        j++;
    }
    return 0;
}