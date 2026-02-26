#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define N 200000000

long long somaSequencial(int *array){
    long long total = 0;

    for(long i = 0; i < N; i++){
        total += array[i];
    }

    return total;
}

int *genRandArray(){
    srand(time(NULL)); // Seed baseada no horário atual
    int *randArray = malloc(N * sizeof(int));

    for(long i = 0; i < N; i++){
        randArray[i] = (rand() % 100);
    }

    srand(time(NULL));

    return randArray;
}

void printLongArray(int *arrayPtr){
    for(long j = 0; j < N; j++){
        printf("%lld", arrayPtr[j]);
    }
}

int main(){

    int *array = malloc(N * sizeof(int)); /// 800 milhões de bytes para uma arquitetura 32 bits

    if(array == NULL){
        printf("Erro na alocação");
        return 1;
    }

    for(long long i = 0; i < N; i++){ // Para validar verificando se a soma do array é igual a N
        array[i] = 1;
    }

    long long resultSeq = somaSequencial(array);
    printf("Resultado da soma sequencial: %lld", resultSeq);

    free(array);

    int *randArray = genRandArray();

    printLongArray(randArray);

    free(randArray);

    return 0;
}
