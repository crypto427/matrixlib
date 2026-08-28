// matrix.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int size;
    int ndims;
    int* dims;
    int* values;
} Matrix;


void init(Matrix *m, int dims[], int ndims);
void print(Matrix *m);
void matmul(Matrix *a, Matrix *b, Matrix * res);


int main() {
    Matrix mat, mat2, res;
    int dims[] = {2, 2};
    int values[] = {1, 2, 3, 4,};
    init(&mat, dims, 2);
    for(int i = 0; i < mat.size; i++)
        *(mat.values+i) = values[i];
    print(&mat);
    int values2[] = {5, 6, 7, 8,};
    init(&mat2, dims, 2);
    for(int i = 0; i < mat.size; i++)
        *(mat2.values+i) = values2[i];
    print(&mat2);

    matmul(&mat, &mat2, &res);

    free((&mat)->values);
    free((&mat)->dims);
    free((&mat2)->values);
    free((&mat2)->dims);
    return 0;
}

void init(Matrix *m, int dims[], int ndims) {
    int size = 0;
    m->ndims = ndims;
    m->dims = malloc(ndims * sizeof(int)); // check this todo
    for(int i = 0; i < ndims; i++) {
        *(m->dims+i) = dims[i];
        size += dims[i];
    }
    
    m->size = size;
    m->values = malloc(size * sizeof(int)); // this needs to be checked if successful, todo later
}

void print(Matrix *m) {
    for(int i = 0; i < m->size; i++)
        printf("%d ", *(m->values+i));
    printf("\n");
}

void matmul(Matrix *a, Matrix *b, Matrix *res)
{
    if((a)->dims[a->ndims-1] == b->dims[0])
    {
        printf("Multiplicable\n");
    }
}
