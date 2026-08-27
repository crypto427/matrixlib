// matrix.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int size;
    int* values;
} Matrix;

void init(Matrix *m, int size) {
    m->size = size;
    m->values = malloc(size * sizeof(int)); // this needs to be checked if successful, todo later
}

void print(Matrix *m) {
    for(int i = 0; i < m->size; i++)
        printf("%d ", *(m->values+i));
    printf("\n");
}

int main() {
    Matrix mat;
    init(&mat, 4);
    print(&mat);
    free((&mat)->values);
    return 0;
}
