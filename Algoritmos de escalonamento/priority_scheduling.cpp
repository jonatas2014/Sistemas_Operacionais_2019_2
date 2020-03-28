#include <iostream>

/* Número de processos por prioridade*/
#define P1 3 // P1: prioridade mais alta (3 processos)
#define P2 4 // P2: segunda prioridade mais alta (4 processos)
#define P3 1 // P3: terceira prioridade mais alta (1 processo)
#define P4 1 // P4: quarta prioridade mais alta (1 processo)

using namespace std;

int main()
{
    /* Processos por nível de prioridade e seus tempos de execução restante */
    int process_P1[P1] = {7, 11, 17}; // processos da fila P1
    int process_P2[P2] = {19, 16, 10, 5}; // processos da fila P2
    int process_P3[P3] = {4}; // processos da fila P3
    int process_P4[P4] = {12}; // processos da fila P4

    /* Variáveis que serão utilizadas para saber se ainda há processos aguardando em cada fila */
    int quanta_remaining_P1 = 0;
    int quanta_remaining_P2 = 0;
    int quanta_remaining_P3 = 0;
    int quanta_remaining_P4 = 0;
    
    /* O quantum sera 2 */
    int quantum = 2;


    /* Armazena o tempo total (quanta total somado de cada processo da fila P1) 
       para a execução da fila de prioridade P1*/
    for (int i = 0; i < P1; i++)
    {
        quanta_remaining_P1 += process_P1[i];
    }
        
    /* Armazena o tempo total (quanta total somado de cada processo da fila P2) 
       para a execução da fila de prioridade P2*/
    for (int i = 0; i < P2; i++)
    {
        quanta_remaining_P2 += process_P2[i];
    }
        
    /* Armazena o tempo total (quanta total somado de cada processo da fila P3) 
       para a execução da fila de prioridade P3*/
    for (int i = 0; i < P3; i++)
    {
        quanta_remaining_P3 += process_P3[i];
    }
        
    /* Armazena o tempo total (quanta total somado de cada processo da fila P4) 
       para a execução da fila de prioridade P4*/
    for (int i = 0; i < P4; i++)
    {
        quanta_remaining_P4 += process_P4[i];
    }
        
    /* Processos da fila de prioridade P1 */
    while (quanta_remaining_P1 > 0)
    {
        for (int i = 0; i < P1; i++)
        /* Cada proceeso executa no intervalo definido pelo quantum */
           
            /* Se o tempo restante de execução do processo for maior que o quantum: */
            if (process_P1[i] >= 2)
            {
                process_P1[i] -= 2;
                cout << "Processo P1_" << i << " Executando\n";
                quanta_remaining_P1 -= 2;
                if (process_P1[i] == 0)
                    cout << "\nProcesso P1_" << i << " Finalizado\n\n";
                else
                    cout << "Processo P1_" << i << " Preemptado\n\n";
            }
            /* Se o tempo restante de execução do processo eh menor que o quantum: */
            else
                if (process_P1[i] == 1)
                {
                    process_P1[i] = 0;
                    cout << "Processo P1_" << i << " Executando\n";
                    quanta_remaining_P1 -= 1;
                    if (process_P1[i] == 0)
                        cout << "\nProcesso P1_" << i << " Finalizado\n\n";
                }
            
    }
    /* Processos da fila de prioridade P2 */
    while (quanta_remaining_P2 > 0)
    {
        for (int i = 0; i < P2; i++)
        /* Cada proceeso executa no intervalo definido pelo quantum */

            /* Se o tempo restante de execução do processo for maior que o quantum: */
            if (process_P2[i] >= 2)
            {
                process_P2[i] -= 2;
                cout << "Processo P2_" << i << " Executando\n";
                quanta_remaining_P2 -= 2;
                if (process_P2[i] == 0)
                    cout << "\nProcesso P2_" << i << " Finalizado\n\n";
                else
                    cout << "Processo P2_" << i << " Preemptado\n\n";
            }
            /* Se o tempo restante de execução do processo eh menor que o quantum: */
            else
                if (process_P2[i] == 1)
                {
                    process_P2[i] = 0;
                    cout << "Processo P2_" << i << " Executando\n";
                    quanta_remaining_P2 -= 1;
                    if (process_P2[i] == 0)
                        cout << "\nProcesso P2_" << i << " Finalizado\n\n";

                }
    }

    /* Processos da fila de prioridade P3 */
    while (quanta_remaining_P3 > 0)
    {
        for (int i = 0; i < P3; i++)
        /* Cada proceeso executa no intervalo definido pelo quantum */

            /* Se o tempo restante de execução do processo for maior que o quantum: */
            if (process_P3[i] >= 2)
            {
                process_P3[i] -= 2;
                cout << "Processo P3_" << i << " Executando\n";
                quanta_remaining_P3 -= 2;
                if (process_P3[i] == 0)
                    cout << "\nProcesso P3_" << i << " Finalizado\n\n";
                else
                    cout << "Processo P3_" << i << " Preemptado\n\n";
            }
            /* Se o tempo restante de execução do processo eh menor que o quantum: */
            else
                if (process_P3[i] == 1)
                {
                    process_P3[i] = 0;
                    cout << "Processo P3_" << i << " Executando\n";
                    quanta_remaining_P3 -= 1;
                    if (process_P3[i] == 0)
                        cout << "\nProcesso P3_" << i << " Finalizado\n\n";
                }
    }

    /* Processos da fila de prioridade P4 */
    while (quanta_remaining_P4 > 0)
    {
        for (int i = 0; i < P4; i++)
        /* Cada proceeso executa no intervalo definido pelo quantum */

            /* Se o tempo restante de execução do processo for maior que o quantum: */
            if (process_P4[i] >= 2)
            {
                process_P4[i] -= 2;
                cout << "Processo P4_" << i << " Executando\n";
                quanta_remaining_P4 -= 2;
                if (process_P4[i] == 0)
                    cout << "\nProcesso P4_" << i << " Finalizado\n\n";
                else
                    cout << "Processo p4_" << i << " Preemptado\n\n";
            }
            /* Se o tempo restante de execução do processo eh menor que o quantum: */
            else
                if (process_P4[i] == 1)
                {
                    process_P4[i] = 0;
                    cout << "Processo P4_" << i << " Executando\n";
                    quanta_remaining_P4 -= 1;
                    if (process_P4[i] == 0)
                        cout << "\nProcesso P4_" << i << " Finalizado\n\n";
                }   
    }   
    return 0;
}
