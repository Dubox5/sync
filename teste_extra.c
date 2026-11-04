#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "sync_car.h"

struct station st;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int embarcaram = 0;

void *passageiro(void *arg)
{
    station_wait_for_car(&st);
    pthread_mutex_lock(&m);
    embarcaram++;
    pthread_mutex_unlock(&m);
    station_on_board(&st);
    return NULL;
}

void travou(int s)
{
    printf("FALHOU: travou (deadlock)\n");
    exit(1);
}

int main(void)
{
    pthread_t t[5];
    signal(SIGALRM, travou);
    station_init(&st);

    for (int i = 0; i < 5; i++)
        pthread_create(&t[i], NULL, passageiro, NULL);
    sleep(1);

    alarm(2);
    station_load_car(&st, -3);
    printf("Caso invalido (carro com -3 assentos): embarcaram %d (esperado 0)\n", embarcaram);

    station_load_car(&st, 2);
    printf("Caso limite (carro com 2 assentos, 5 esperando): embarcaram %d (esperado 2)\n", embarcaram);

    station_load_car(&st, 3);
    printf("Caso limite (carro com 3 assentos, 3 esperando): embarcaram %d (esperado 5)\n", embarcaram);

    station_load_car(&st, 4);
    printf("Caso limite (carro com 4 assentos, ninguem esperando): embarcaram %d (esperado 5)\n", embarcaram);
    alarm(0);

    for (int i = 0; i < 5; i++)
        pthread_join(t[i], NULL);
    printf("Testes extras OK\n");
    return 0;
}
