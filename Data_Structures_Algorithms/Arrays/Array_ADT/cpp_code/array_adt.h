#ifndef ARRAY_ADT_H
#define ARRAY_ADT_H

#define MAX_SIZE 10
#define ERR      -1


/*********************************************************************
* Class Array decleration, with all the member variables and 
* member functions. 
**********************************************************************/
class Array
{
    private:
        int  *A      = NULL;
        int   size   = 0;
        int   length = 0;

        int  _binary_search(int low, int high, int key);
        int  _binary_search_rec(int low, int high, int key);
        int  _sum_rec(int n);
        void swap_array_item(int curr_idx, int new_idx);

    public:
        Array();
        Array(int size);
        ~Array();
        void init_array(int size);
        void delete_array();
        void display();
        void append(int item);
        void insert(int idx, int item);
        void insert_sorted(int item);
        void set_number_pos_neg();
        void set_index(int idx);
        void reverse();
        void reverse_opt();
        void left_shift();
        void right_shift();
        void left_rotate();
        void right_rotate();
        void set_item_at_index(int idx, int item);
        int  delete_item(int idx);
        int  linear_search(int key);
        int  linear_search_transposition(int key);
        int  linear_search_move_to_head(int key);
        int  binary_search(int key);
        int  binary_search_rec(int key);
        int  get_item_at_index(int idx);
        int  Max();
        int  Min();
        int  sum();
        int  sum_rec();
        float  avg();
        bool is_sorted();

        friend void merge_sort(Array& A, Array& B);
        friend void set_union_unsorted(Array& A, Array& B);
        friend void set_union_sorted(Array& A, Array& B);
        friend void set_intersec_unsorted(Array& A, Array& B);
        friend void set_intersec_sorted(Array& A, Array& B);
        friend void set_diff_unsorted(Array& A, Array& B);
        friend void set_diff_sorted(Array& A, Array& B);
};

#endif