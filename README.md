# Sincronizacao do Metro

Implementacao das funcoes de sincronizacao entre vagoes e passageiros usando pthreads, um so mutex por estacao e variaveis de condicao

## Arquivos
- `sync_car.h`: definicao da `struct station` e prototipos das funcoes
- `sync_car.c`: implementacao de `station_init`, `station_load_car`, `station_wait_for_car` e `station_on_board`
- `sync_car-runner.c`: programa de testes fornecido pelo professor (contem o `main`)
- `Makefile`: compila o projeto e gera o executavel `sync_car`

## Compilar
    make

## Executar e testar
    ./sync_car

Se tudo estiver certo `Looks good!` vai estar escrito na ultima linha
Para rodar o teste 100 vezes seguidas e contar quantas dessas execucoes passaram:

    for i in $(seq 1 100); do ./sync_car > /dev/null 2>&1 && echo ok; done | wc -l

## Limpar
    make clean

## Sistema operacional
Implementado e testado com o Linux (Ubuntu 24.04 por WSL no Windows), gcc e make
