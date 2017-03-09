#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int *v;
	size_t size;
	size_t capacity;

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

size_t int_vector_get_size(const IntVector *v)
{
	return v -> size;
}

size_t int_vector_get_capacity(const IntVector *v)
{
	return v -> capacity;
}

IntVector *int_vector_copy(const IntVector *d)
{
	//Копирование массива
	IntVector *o = malloc(sizeof(IntVector));
	o -> v =  malloc(o -> capacity * sizeof(int));
	memcpy(o -> v, d -> v, sizeof(int) * o -> size);
	o -> size = int_vector_get_size(d);
	o -> capacity = int_vector_get_capacity(d);
	return o;
}

/*int int_vector_get_item(const IntVector *v, size_t index)
{
	return v -> v[index];
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{

}*/

void int_vector_free(IntVector *v)
{
	free(v);
}

int main()
{
	int i, N;
	N = 6;

	IntVector *w, *h, *c;
	w = int_vector_new(6);
	h = int_vector_copy(w);
	//c = int_vector_get_item(v, 2);
	//int_vector_set_item(w, 2, 3);
	int_vector_free(w);

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

	//printf("Вы получите второй элемент вектора: %d", c -> v);

	return 0;
}