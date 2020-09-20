#ifndef ARRAY_ADT_H
#define ARRAY_ADT_H

#define MAX_SIZE 10
#define ERR      -1

#include<stdbool.h>

/* Array Structure */
typedef struct Array
{
    int  *A;
    int   size;
    int   length;
} Array, *Array_ptr;


/* Array ADT Functions */
void  init_array(Array_ptr array, int size);
void  delete_array(Array_ptr array);
void  display(Array array);
void  append(Array_ptr array, int item);
void  insert(Array_ptr array, int idx, int item);
void  reverse(Array_ptr A);
void  reverse_opt(Array_ptr A);
void  left_shift(Array_ptr A);
void  right_shift(Array_ptr A);
void  left_rotate(Array_ptr A);
void  right_rotate(Array_ptr A);
void  insert_sorted(Array_ptr A, int item);
void  set_number_pos_neg(Array_ptr A);
void  merge_sort(Array A, Array B);
void  set_union_unsorted(Array A, Array B);
void  set_union_sorted(Array A, Array B);
void  set_intersec_unsorted(Array A, Array B);
void  set_intersec_sorted(Array A, Array B);
void  set_diff_unsorted(Array A, Array B);
void  set_diff_sorted(Array A, Array B);
void  set_item_at_index(Array_ptr A, int idx, int item);
int   delete_item(Array_ptr array, int idx);
int   linear_search(Array array, int item);
int   linear_search_transposition(Array_ptr array, int item);
int   linear_search_move_to_head(Array_ptr array, int item);
int   binary_search(Array array, int item);
int   binary_search_rec(Array array, int item);
int   get_item_at_index(Array A, int idx);
int   Max(Array A);
int   Min(Array A);
int   sum(Array A);
int   sum_rec(Array A);
float avg(Array A);
bool  is_sorted(Array A);

#endif
