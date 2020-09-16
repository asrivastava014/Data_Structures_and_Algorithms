/*********************************************************************
* Created By: Ankur Srivastava
* About:      Main Program for Array ADT
* 
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_adt.h"

int main()
{
    Array my_arr;

    memset(&my_arr, 0, sizeof(my_arr));
    init_array(&my_arr, 10);

    for(int i = 0; i < 10; i++)
    {
        my_arr.A[i] = 0;
    }

    printf("%d\n", delete_item(&my_arr, 2));
    //printf("%d\n", linear_search(my_arr, 3));
    //printf("%d\n", linear_search_transposition(&my_arr, 3));
    //printf("%d\n", linear_search_move_to_head(&my_arr, 3));
    printf("%d\n", binary_search(my_arr, 3));
    printf("%d\n", binary_search_rec(my_arr, 3));

    display(my_arr);
    append(&my_arr, 4);
    append(&my_arr, 5);
    append(&my_arr, 6);
    append(&my_arr, 7);
    append(&my_arr, 8);
    append(&my_arr, 9);
    append(&my_arr, 10);
    display(my_arr);
    printf("%d\n", binary_search(my_arr, 9));
    //printf("%d\n", linear_search(my_arr, 9));
    display(my_arr);
    printf("%d\n", binary_search_rec(my_arr, 9));
    //printf("%d\n", linear_search_transposition(&my_arr, 9));
    display(my_arr);
    //printf("%d\n", linear_search_move_to_head(&my_arr, 9));
    //display(my_arr);

    append(&my_arr, 11);
    display(my_arr);
    insert(&my_arr, 0, 13);
    insert(&my_arr, 9, 13);
    insert(&my_arr, 4, 13);
    display(my_arr);
    insert(&my_arr, 9, 99);
    append(&my_arr, 12);
    display(my_arr);
    printf("%d\n", delete_item(&my_arr, 11));
    display(my_arr);
    printf("%d\n", delete_item(&my_arr, 4));
    display(my_arr);
    printf("%d\n", delete_item(&my_arr, 8));
    display(my_arr);
    printf("%d\n", delete_item(&my_arr, 5));
    display(my_arr);
    printf("%d\n", delete_item(&my_arr, 6));
    display(my_arr);
    printf("%d\n", delete_item(&my_arr, 0));
    display(my_arr);
    printf("%d\n", delete_item(&my_arr, 0));
    display(my_arr);
    printf("%d\n", delete_item(&my_arr, 0));
    display(my_arr);
    printf("%d\n", delete_item(&my_arr, 0));
    display(my_arr);
    printf("%d\n", delete_item(&my_arr, 0));
    display(my_arr);
    printf("%d\n", delete_item(&my_arr, 0));
    display(my_arr);


    delete_array(&my_arr);

    return 0;
}
