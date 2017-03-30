#include <stdio.h>
#include "vector.h"

int main()
{
	int new_num;
    int init_capacity, input_item, input_change_num, input_new_num, New_capacity, New_size;
    int h = 1, counter = 0;
    int i = 0, j = 0;

    IntVector *l = NULL;
    //IntVector *k = NULL;

    printf("/*************************************************/\n");
    printf("/\tДобро пожаловать в наш скромный уголок!\t  /\n");
    printf("/*************************************************/\n\n");

    printf("Введите емкость вектора: ");
    scanf("%d", &init_capacity);
    IntVector *v = int_vector_new(init_capacity);
    v -> size = 0;

    menu(counter, v);
    scanf("%d", &counter);

    while(h != 0) {
        switch (counter) {
            case 1:
                //enter elements or add elements
                scanf("%d", &input_item);
                int_vector_push_back(v, input_item);
                //printf("Введенный элемент:[%d] - %d\n", input_item, w -> data[input_item]);
                menu(counter, v);
                scanf("%d", &counter);
                break;
            case 2:
                //change element
                printf("Введите номер элемента и новое значение: ");
                scanf("%d %d", &input_change_num, &input_new_num);
                int_vector_set_item(v, input_change_num, input_new_num);
                printf("Изменен элемент [%d] - %d\n", input_change_num, v -> data[input_change_num - 1]);
                menu(counter, v);
                scanf("%d", &counter);
                break;
            case 3:
                //Delete last element
                int_vector_pop_back(v);
                printf("Последний элемент был удален\n");
                menu(counter, v);
                scanf("%d", &counter);
                break;
            case 4:
                //Change capacity
                printf("Введите новую емкость вектора: ");
                scanf("%d", &New_capacity);

                int_vector_reserve(v, New_capacity);
                //printf("Новая емкость вектора: %zu\n", a -> capacity);
                menu(counter, v);
                scanf("%d", &counter);
                break;
            case 5:
                //Change size
                printf("Введите новый размер вектора: ");
                scanf("%d", &New_size);
                int_vector_resize(v, New_size);
                //printf("Новый размер вашего вектора: %zu\n", k -> size);
                menu(counter, v);
                scanf("%d", &counter);
                break;
            case 6:
                //Copy vector
                printf("Текущий вектор: \n");
                for (i = 0; i < int_vector_get_size(v); ++i) {
                    printf("%d ", v -> data[i]);
                }
                printf("\n");

                l = int_vector_copy(v);
                printf("Скопированный массив: \n");
                for (j = 0; j < int_vector_get_size(v); ++j) {
                    printf("%d ", l -> data[j]);
                }
                printf("\n");
                menu(counter, v);
                scanf("%d", &counter);
                break;
            case 7:
                //Shrink vector
                int_vector_shrink_to_fit(v);
                printf("Ваша емкость вектора была уменьшена до его размера");
                menu(counter, v);
                scanf("%d", &counter);
                break;
            case 8:
                //Get item
                printf("Какой элемент вы хотите получить?\n");
                scanf("%d", &new_num);
                int_vector_get_item(v, new_num);
                printf("Ваш элемент [%d] - %d\n", new_num, v -> data[new_num]);
                menu(counter, v);
                scanf("%d", &counter);
                break;
            case 9:
                //Quit
                printf("До скорых встреч!\n");
                h = 0;
                break;
            /*default:
                printf("Неправильный пункт меню.\n");
                menu(counter);
                scanf("%d", &counter);
                break;*/
        }
    }
    int_vector_free(v);

    return 0;
}