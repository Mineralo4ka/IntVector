#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int *v;
	int size;
	int capacity;

} IntVector;

IntVector *int_vector_new(size_t initial_capacity)
{
	//Создание массива
	IntVector *o = malloc(sizeof(IntVector));
	o -> v = calloc(initial_capacity, initial_capacity * sizeof(int));
	o -> size = 0;
	o -> capacity = initial_capacity;
	return o;
}

IntVector *int_vector_copy(const IntVector *d)
{
	//Копирование массива
	IntVector *o = malloc(sizeof(IntVector));
	o -> v =  malloc(o -> capacity * sizeof(int));
	memcpy(o -> v, d -> v, sizeof(int_vector_get_size(d -> size)));
	o -> size = int_vector_get_size(d -> size);
	o -> capacity = int_vector_get_capacity(d -> capacity);
	return o;
}


int main()
{
	int i, N;
	N = 6;

	IntVector *w = int_vector_new(N);
	IntVector *h = int_vector_copy(w);

	printf("Созданный массив: \n");
	for (i = 0; i < N; ++i) {
		printf("%d", w -> v[i]);
	}
	printf("\n");
	
	printf("Скопированный массив: \n");
	for (i = 0; i < N; ++i) {
		printf("%d", h -> v[i]);
	}
	printf("\n");

	return 0;
}