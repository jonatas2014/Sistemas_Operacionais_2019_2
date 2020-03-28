#include <iostream>

/* Número de processos na fila */
#define N 6

using namespace std;

/* Função que retorna o índice do processo com menor process ratio 
   process ratio = tempo acumulado de uso da cpu por processo */
    /* O sistema seleciona o menor proceess_ratio, para os processos em que process[i] > 0, 
       ou seja, processos que ainda nao acabaram */
int smallest_process_ratio_index(float process_ratio[],
                                 float process[],
                                 int number_of_current_process )
{
    int smallest_ratio = INT32_MAX;
    int smallest_index;
    for (int i = 0; i < number_of_current_process; i++)
    {
        if ((process_ratio[i] < smallest_ratio) && (process[i] > 0))
        {
            smallest_index = i;
            smallest_ratio = process_ratio[i];
        }
            
        
    }
    return smallest_index;
}

int main()
{

    float process[N] = {4, 2, 7, 10, 6, 5};

    /* contador de número de excuções de cada processo */
    float count_execution[N] = {2, 2, 2, 2, 2, 2}; 

    float cpu_cycle = 1;
    
    float number_of_current_process = N; 

    /* Variável que recebe o processo com menor ratio */
    int choosen_process_index; 

    float process_ratio[N] = {0, 0, 0, 0, 0, 0};

    /* Inicaliza os process ratio */
    for (int i = 0; i < N; i++)
        process_ratio[i] = 1/(number_of_current_process);

    /* Ha 6 processos na fila */
    int runnable_process = N; 
    
    /* Fatia de tempo inicial da cpu para cada processo */
    float cpu_time = 1.0/runnable_process; 

    float total_work;

    /* Registra o total de trabalho a se fazer.
       Apenas para saber quando encerrar o programa, ou seja,
       qaundo não houver mais processo a ser executado */
    for (int i = 0; i < N; i++) 
        total_work += process[i];

    /* Equanto houver trabalho */
    while (total_work > 0)
    {
        /* O sistem verifica todos os processos em fila */
        for (int i = 0; i < number_of_current_process ; i++)
        {
            /* O sistema seleciona o menor process_ratio, para os processos em que process[i] > 0, 
               ou seja, processos que ainda não acabaram */
            choosen_process_index = smallest_process_ratio_index(process_ratio,
                                                                 process, 
                                                                 number_of_current_process);

            
            /* O sistema executa o processo com menor process ratio, ou seja,
               aquele que teve menos tempo de cpu */
            total_work = total_work - cpu_time;  
            process[choosen_process_index] -= cpu_time;
            /* O process ratio do processo executado é atualizado */
            process_ratio[choosen_process_index] *= (count_execution[choosen_process_index]/cpu_cycle);
            count_execution[choosen_process_index] += 1;
            cout << "Processo " << choosen_process_index << " Executando\n";

            /* Aqui verifica se o processo executando terminou sua execução */
            if (process[choosen_process_index] <= 0)
            {
                cout << "\nProcesso " << choosen_process_index << " Finalizado\n\n";
                
                /* Quando um processo finaliza, 
                   o tempo permitido de execução para cada processo eh atualizado */
                runnable_process -= 1;
                cpu_time = 1.0/runnable_process;
            }
            else
                cout << "Processo " << choosen_process_index << " Preemptado\n\n";  
        }
        
        cpu_cycle += 1;
    }
    return 0;
}