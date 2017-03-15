#include <stdio.h>
#include "vector.h"

int main()
{
	int new_num;
    int input_capacity, input_item, input_change_num, input_new_num, new_capacity, new_size;
    int h = 1, counter = 0;

    printf("Введите емкость вектора: ");
    scanf("%d", &input_capacity);
    IntVector *v = int_vector_new(input_capacity);

    scanf("%d", &counter);

    while(h) {
        int_vector_clear();
        switch (counter) {
            case 1:
                //enter elements or add elements
                scanf("%d", &input_item);
                int_vector_push_back(v, input_item);
                printf("Введенный элемент:[%d] - %d\n", input_item, v -> data[input_item]);
                menu(counter);
                scanf("%d", &counter);
                break;
            case 2:
                //change element
                printf("Введите номер элемента и новое значение: ");
                scanf("%d %d", &input_change_num, &input_new_num);
                int_vector_set_item(v, input_change_num, input_new_num);
                printf("Изменен элемент [%d]-%d", input_change_num, v -> data[input_change_num]);
                menu(counter);
                scanf("%d", &counter);
                break;
            case 3:
                //Delete last element
                int_vector_pop_back(v);
                printf("Последний элемент был удален\n");
                menu(counter);
                scanf("%d", &counter);
                break;
            case 4:
                //Change capacity
                printf("Введите новую емкость вектора: ");
                scanf("%d", &new_capacity);
                int_vector_reserve(v, new_capacity);
                printf("Новая емкость вектора: %zu\n", v -> capacity);
                menu(counter);
                scanf("%d", &counter);
                break;
            case 5:
                //Change size
                printf("Введите новый размер вектора: ");
                scanf("%d", &new_size);
                int_vector_resize(v, new_size);
                printf("Новый размер вашего вектора: %zu\n", v -> size);
                menu(counter);
                scanf("%d", &counter);
                break;
            case 6:
                //Copy vector
                printf("Текущий вектор: \n");
                for (int i = 0; i < int_vector_get_size(v); ++i) {
                    printf("%d", v -> data[i]);
                }
                printf("\n");

                int_vector_copy(v);
                printf("Скопированный массив: \n");
                for (int j = 0; j < int_vector_get_size(v); ++j) {
                    printf("%d", v -> data[j]);
                }
                printf("\n");
                menu(counter);
                scanf("%d", &counter);
                break;
            case 7:
                //Shrink vector
                int_vector_shrink_to_fit(v);
                printf("Полный вектор: \n");
                for (int i = 0; i < int_vector_get_capacity(v); ++i) {
                    printf("%d", v -> data[i]);
                }
                printf("\n");
                printf("Ваша емкость вектора была уменьшена до его размера");
                for (int i = 0; i < int_vector_get_size(v); ++i) {
                    printf("%d", v -> data[i]);
                }
                printf("\n");
                menu(counter);
                scanf("%d", &counter);
                break;
            case 8:
                //Get item
                printf("Какой элемент вы хотите получить?");
                scanf("%d", &new_num);
                int_vector_get_item(v, new_num);
                printf("Ваш элемент [%d] - %d\n", new_num, v -> data[new_num]);
                menu(counter);
                scanf("%d", &counter);
                break;
            case 9:
                h = 0;
                break;
            default:
                printf("Неправильный пункт меню.\n");
                menu(counter);
                scanf("%d", &counter);
                break;
        }
    }
    int_vector_free(v);

    return 0;
}