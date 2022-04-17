#ifndef _UTIL_H_
#define _UTIL_H_

#define ODD 1
#define EVEN 0
#define TRUE 1
#define FALSE 0

enum menu {EXIT, sum_multi, prime, display, sort};



/* scan an int from stdin, check if it's viable if so return that,
else ask another integer from the user.  */
int take_int(int * n);

/* sum/multi prototypes START.*/
/* flag determines whether to work on odd or even numbers. */
int sum(int n1, int n2, int flag);
void print_even_sum(int n1, int n2, int * result);
void print_odd_sum(int n1, int n2, int * result);

/* flag determines whether to work on odd or even numbers. */
int multi(int n1, int n2, int flag);
void print_even_multi(int n1, int n2, int * result);
void print_odd_multi(int n1, int n2, int * result);

void print_result(FILE * result_file, int result);
/* sum/multi prototypes END.*/

/* prime checker prototypes start. */
int isprime(int a);
/* prime checker prototypes end. */

/* calculates the least divisor of a number */
int ld_calc(int value);

/* prints the result, that's read from results.txt file*/
void print_file(void);

/* sort_file funcs prototypes start. */
void print_last_3(FILE * temp_file, int min1, int min2, int min3);

void find_remaining_last_3(FILE * unsorted_file, int * min1, int * min2, int * min3);

void overwrite(FILE * unsorted_fileint, int minx_start, int minx_end);

void find_remaining_last_3_position(FILE * unsorted_file,
int min1, int *min1_start, int *min1_end, 
int min2, int *min2_start, int *min2_end,
int min3, int *min3_start, int *min3_end);

void delete_last_3(FILE * unsorted_file, int * min1, int * min2, int * min3);

void check_file(FILE * file_pointer);

void swap(int *a, int *b);

void sort_triple(int *num1, int *num2, int *num3);

void sort_file(void);

void delete_unsorted(void);

void rename_temp(void);
/* sort_file funcs prototypes end. */

#endif /* _UTIL_H_ */