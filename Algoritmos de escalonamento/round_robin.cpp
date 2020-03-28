#include <iostream>

/* Número de processos */
#define N 4 

using namespace std;

int main()
{
    int process[N];

    int quanta_remaining = 0;

    /* O quantum será 2 */
    int quantum = 2;

    /* O processo 0 precisa de 5 quanta para ser executado */
    process[0] = 10; 
    /* O processo 1 precisa de 4 quanta para ser executado */
    process[1] = 8;
    /* O processo 2 precisa de 10 quanta para ser executado */
    process[2] = 20; 
    /* O processo 3 precisa de 2 quanta para ser executado */
    process[3] = 4;

    /* Armazena o tempo total (quanta somado de cada processo) 
       para a execução de todos os processos.
       Usado para saber se ainda ha processos na fila*/
    for (int i = 0; i < N; i++)
        quanta_remaining += process[i];

    /* Enquanto algum processo estiver na fila */
    while (quanta_remaining > 0)
    {
        /* Ordem de execucao dos processos: 0,1,2....N */
        for (int i = 0; i < N; i++)

            /* Cada processo executa durante o intervalo de tempo definido pelo quantum */
            if (process[i] >= 2)
            {
                process[i] -= 2;
                cout << "Processo " << i << " Executando\n";
                quanta_remaining -= 2;
                if (process[i] == 0)
                    cout << "\nProcesso " << i << " Finalizado\n\n";
                else
                    cout << "Processo " << i << " Preemptado\n\n";
            }
            /* Se o tempo restante de execução do processo eh menor que o quantum: */
            else
                if (process[i] == 1)
                {
                    process[i] = 0;
                    cout << "Processo " << i << " Executando\n";
                    quanta_remaining -= 1;
                    if (process[i] == 0)
                        cout << "\nProcesso " << i << " Finalizado\n\n";
                }
    }
    return 0;
}