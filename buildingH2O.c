#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void releaseHydrogen(void) {
    printf("H");
}

void releaseOxygen(void) {
    printf("O");
}

typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t oxygen_lock;
    pthread_mutex_t hydrogen_lock;
    int hydrogen_atoms;
} H2O;

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    
    // Initialize user defined data here.
    pthread_mutex_init(&obj->oxygen_lock, NULL);
    pthread_mutex_init(&obj->hydrogen_lock, NULL);
    pthread_mutex_lock(&obj->oxygen_lock);
    obj->hydrogen_atoms = 0;
    
    return obj;
}

void hydrogen(H2O* obj) {
    pthread_mutex_lock(&obj->hydrogen_lock);
    
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    obj->hydrogen_atoms += 1;

    pthread_mutex_unlock((obj->hydrogen_atoms % 2 == 0) ? &obj->oxygen_lock : &obj->hydrogen_lock);
}

void oxygen(H2O* obj) {
    pthread_mutex_lock(&obj->oxygen_lock);
    
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    
    pthread_mutex_unlock(&obj->hydrogen_lock);
}

void h2oFree(H2O* obj) {
    // User defined data may be cleaned up here.
    pthread_mutex_destroy(&obj->oxygen_lock);
    pthread_mutex_destroy(&obj->hydrogen_lock);
}

int main(int argc, char **argv) {
    H2O* obj = h2oCreate();
    pthread_t *threads = (pthread_t *) calloc(strlen(argv[1]), sizeof(pthread_t));

    for (size_t i = 0; i < strlen(argv[1]); i++) {
        pthread_create(&threads[i], NULL, argv[1][i] == 'H' ? (void *) hydrogen : (void *) oxygen, obj);
    }

    for (int i = 0; i < strlen(argv[1]); i += 1) {
        pthread_join(threads[i], NULL);
    }
    printf("\n");
    
    h2oFree(obj);
    free(threads);
    
    return 0;
}