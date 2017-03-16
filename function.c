#include "stdio.h"
#include <stdlib.h>
#include "vector.h"
#include "string.h"

IntVector *int_vector_new(size_t init_capacity)
{
    //Создание массива
    IntVector *o = malloc(sizeof(IntVector));
    o -> data = calloc(init_capacity, init_capacity * sizeof(int));
    o -> size = 0;
    o -> capacity = init_capacity;
    return o;
    /*IntVector *v = (IntVector *) malloc(sizeof(IntVector));
	if (v != NULL) {
		v->data = calloc(init_capacity, sizeof(size_t));
		if (v->data != NULL) {
			v->size = 0;
			v->capacity = init_capacity;
			return v;
		} else {
			return NULL;
			exit(0);
		}
	} else
		return NULL;
		exit(0);*/
}

IntVector *int_vector_copy(const IntVector *v)
{
    //Копирование массива
    IntVector *o = malloc(sizeof(IntVector));
    o -> data =  malloc(o -> capacity * sizeof(int));
    memcpy(o -> data, v -> data, sizeof(int) * o -> size);
    o -> size = int_vector_get_size(v);
    o -> capacity = int_vector_get_capacity(v);
    return o;
    /*IntVector *v_copy = (IntVector *) malloc(sizeof(IntVector));
	if (v_copy != NULL) {
		v_copy->data = (int *) malloc (v->capacity * sizeof(int));
		if (v_copy->data != NULL) {
			size_t c_num = int_vector_get_capacity(v) * sizeof(size_t);
			memcpy(v_copy->data, v->data, c_num);
			v_copy->size = int_vector_get_size(v);
			v_copy->capacity = int_vector_get_capacity(v);
			return v_copy;
		} else {
			return NULL;
			exit (0);
		}
	} else
		return NULL;
		exit(0);*/
}

void int_vector_free(IntVector *v)
{
    free(v -> data);
    free(v);
}

size_t int_vector_get_capacity(const IntVector *v)
{
    return v -> capacity;
}

size_t int_vector_get_size(const IntVector *v)
{
    return v -> size;
}

int int_vector_push_back(IntVector *v, int item)
{
    if (v->size >= v->capacity) {
        int_vector_reserve(v, int_vector_get_capacity(v) * 2);
        v->data[v->size] = item;
        v->size++;
        return 0;
    } else {
        v->data[v->size] = item;
        v->size++;
        return 0;
    }
}

void int_vector_pop_back(IntVector *v)
{
    if ((v->size != 0)) {
        v->data[v->size - 1] = 0;
        v->size--;
    } else {
        printf("\nОШИБКА! (в %p). Нет элементов для удаления\n", v->data);
    }
}

int int_vector_get_item(const IntVector *v, size_t index)
{
    return v -> data[index - 1];
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{
    v -> data[index - 1] = item;
}

int int_vector_shrink_to_fit(IntVector *v)
{
    /*if ((v->data = (int *) realloc(v->data, v->size * sizeof(int))) != NULL) {
        v->capacity = v->size;
        return 0;
    } else {
        return -1;
    }*/
    if (v -> size == 0) {
        v -> capacity = v -> size;
    }else{
        v -> data = realloc (v -> data, ( v -> size) * sizeof(int)); 
    }

    if ( v -> data == NULL) {
        return -1;
    }else {
        v -> capacity = v -> size;
        return 0;
    }
}

int int_vector_resize(IntVector *v, size_t new_size)
{
    if (new_size >= (v->size)) {
        int increment = 0;
        while (increment < new_size) {
            int_vector_push_back(v, 0);
            ++increment;
        }
        v->size = new_size;
        return 0;
    } else if (new_size < v->size) {
        int_vector_shrink_to_fit(v);
        return 0;
    } else if (new_size > (v->capacity)) {
        int n_def = int_vector_get_capacity(v) * 2;
        int_vector_reserve(v, n_def);
        int_vector_push_back(v, 0);
        v->size = new_size;
        return 0;
    } else
        return -1;
}

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
    if (new_capacity <= int_vector_get_capacity(v)) {
        return -1;
    } else {
        if ((v->data = (int *) realloc(v->data, new_capacity * sizeof(int)))) {
            v->capacity = new_capacity;
            return 0;
        } else {
            return -1;
        }
    }
}
int menu(int input_counter)
{
    printf("Введите нужную вам опцию: \n");
    printf("\t1 <- Добавить элемент.\n");
    printf("\t2 <- Изменение элемента.\n");
    printf("\t3 <- Удаление последнего элемента.\n");
    printf("\t4 <- Изменение емкости\n");
    printf("\t5 <- Изменение размера.\n");
    printf("\t6 <- Копирование вектора.\n");
    printf("\t7 <- Уменьшает емкость массива до его размера.\n");
    printf("\t8 <- Получение элемента.\n");
    printf("\t9 <- Выход\n");

    switch(input_counter) {
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 4;
			break;
		case 5:
			return 5;
			break;
		case 6:
			return 6;
			break;
		case 7:
			return 7;
			break;
		case 8:
			return 8;
			break;
        case 9:
            return 9;
            break;
		default:
			return 0;
	}
}

void int_vector_clear()
{
    system("clear");
}