#include <iostream>

using namespace std;

/* Número de processos em cada uma das prioridades iniciais */
#define N_P1  4 // 4 processos iniciarão com prioridade 1
#define N_P2  6 // 6 processos iniciarão com prioridade 2
#define N_P3  4 // 4 processos iniciarão com prioridade 3

int main()
{
    /* Processos 0, 1, 2 ,3 */
    int process_P1[N_P1] = {100, 52, 25, 6};
    /* Processos 4, 5, 6, 7, 8, 9 */
    int process_P2[N_P2] = {8, 11, 61, 49, 36, 51};
    /* Processos 10, 11, 12, 13 */
    int process_P3[N_P3] = {96, 49, 32, 4};

    int quantum_1 = 1; //quantum inicial da fila 1
    int quantum_2 = 2; //quantum inicial da fila 2
    int quantum_3 = 4; //quantum inicial da fila 3

    int total_work = 0;

    for (int i = 0; i < N_P1; i++)
        total_work += process_P1[i];

    for (int i = 0; i < N_P2; i++)
        total_work += process_P2[i];

    for (int i = 0; i < N_P3; i++)
        total_work += process_P3[i]; 

    while (total_work > 0)
    {
        /* Processos do nível inicial de prioridade 1 */
         if ((quantum_1 <= quantum_2) && (quantum_1 <= quantum_3)) 
        {
            for (int i = 0; i < N_P1; i++)
                /* O processo ainda tem trabalho a fazer */
                if (process_P1[i] > 0)
                {
                    if (process_P1[i] > quantum_1)
                    {
                        cout << "Processo " << i << " Executando\n";
                        process_P1[i] -= quantum_1;
                        total_work -= quantum_1;
                        cout << "Processo " << i << " Preemptado\n\n";
                    }
                    /* Se o tempo que falta ao processo eh menor que seu quantum atual atribuido.
                       Ele apenas executa o tempo restante de sua execução,
                       ou seja, nao usa todo o quantum disponível */
                    else
                    {
                        cout << "Processo " << i << " Executando\n";
                        total_work -= process_P1[i];
                        process_P1[i] -= process_P1[i];
                        cout << "\nProcesso " << i << " Finalizado\n\n";
                    }
                        
                }
            /* Após uma execução de todos os processo dessa fila eles perdem um nível de prioridade,
               ou seja, o quantum para os proceesos dessa fila aumenta */
            quantum_1 *= 2;
        } 
        /* Processos do nível inicial de prioridade 2 */
        if ((quantum_2 <= quantum_1) && (quantum_2 <= quantum_3))
        {
            for (int i = 0; i < N_P2; i++)
                /* O processo ainda tem trabalho a fazer */
                if (process_P2[i] > 0)
                {
                    if (process_P2[i] > quantum_2)
                    {
                        cout << "Processo " << i + N_P1 << " Executando\n";
                        process_P2[i] -= quantum_2;
                        total_work -= quantum_2;
                        cout << "Processo " << i + N_P1<< " Preemptado\n\n";
                    }
                    /* Se o tempo que falta ao processo eh menor que seu quantum atual atribuído.
                       Ele apenas executa o tempo restante de sua execução,
                       ou seja, nao usa todo o quantum disponível */
                    else
                    {
                        cout << "Processo " << i + N_P1 << " Executando\n";
                        total_work -= process_P2[i];
                        process_P2[i] -= process_P2[i];
                        cout << "\nProcesso " << i + N_P1<< " Finalizado\n\n";
                    }
                        
                }
            /* Após uma execução de todos os processo dessa fila eles perdem um nível de prioridade,
               ou seja, o quantum para os proceesos dessa fila aumenta */
            quantum_2 *= 2;
        }
        /* Processos do nível inicial de prioridade 3 */
        if ((quantum_3 <= quantum_1) && (quantum_3 <= quantum_2))
        {
            for (int i = 0; i < N_P3; i++)
                /* O processo ainda tem trabalho a fazer */
                if (process_P3[i] > 0)
                {
                    if (process_P3[i] > quantum_3)
                    {
                        cout << "Processo " << i + N_P1 + N_P2 << " Executando\n";
                        process_P3[i] -= quantum_3;
                        total_work -= quantum_3;
                        cout << "Processo " << i + N_P1 + N_P2 << " Preemptado\n\n";
                    }
                    /* Se o tempo que falta ao processo eh menor que seu quantum atual atribuído.
                       Ele apenas executa o tempo restante de sua execução,
                       ou seja, nao usa todo o quantum disponível */
                    else
                    {
                        cout << "Processo " << i + N_P1 + N_P2 << " Executando\n";
                        total_work -= process_P3[i];
                        process_P3[i] -= process_P3[i];
                        cout << "\nProcesso " << i + N_P1 + N_P2 << " Finalizado\n\n";
                    } 
                        
                }
            /* Após uma execução de todos os processo dessa fila eles perdem um nível de prioridade,
               ou seja, o quantum para os proceesos dessa fila aumenta */
            quantum_3 *= 2;
        } 
    }

    return 0;
}