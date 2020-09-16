#ifndef ARRAY_ADT_H
#define ARRAY_ADT_H

#define MAX_SIZE 10
#define ERR      -1


typedef struct Array
{
    int  *A;
    int   size;
    int   length;
} Array, *Array_ptr;

void init_array(Array_ptr array, int size);
void delete_array(Array_ptr array);
void display(Array array);
void append(Array_ptr array, int item);
void insert(Array_ptr array, int idx, int item);
int delete_item(Array_ptr array, int idx);
int linear_search(Array array, int item);
int linear_search_transposition(Array_ptr array, int item);
int linear_search_move_to_head(Array_ptr array, int item);
int binary_search(Array array, int item);
int binary_search_rec(Array array, int item);


/*
int  get_item_at_index(int idx);
void set_index(int idx);
int Max();
int Min();
void reverse();
void shift();
void rotate();
};
*/

#endif
