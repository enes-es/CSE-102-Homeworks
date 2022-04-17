#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"

int take_int(int * n) {
    int how_many_taken;

    do{
        how_many_taken = scanf("%d", n);
        while(getchar() != '\n');
        if(how_many_taken < 1)
            printf("Please enter a viable integer.\n");
    } while (how_many_taken < 1);

    return *n;
}

/* sum/multi functions START. */
void print_result(FILE * result_file, int result) {
    fprintf(result_file, "%d ", result);
}
int sum(int n1, int n2, int flag) {
    FILE * result_file = fopen("results.txt", "a+");
    int result = -1; /* default error value */

    if (flag == EVEN) {
        print_even_sum(n1, n2, &result);
    }

    else if (flag == ODD) {
        print_odd_sum(n1, n2, &result);
    }

    else {
        printf("bad even/num selection, try again.\n");
    }

    if (result != -1){
        print_result(result_file, result);
        return 0;
    }
    else {
        return 1;
    }
    fclose(result_file);
}

void print_odd_sum(int n1, int n2, int * result) {
    int nearest_n1 = n1;
    int nearest_n2 = n2;
    int how_many_times;
    int value;
    int sum_value;
    
    if(n1 % 2 == 0)
        nearest_n1 = n1 + 1;
    if(n2 % 2 == 0)
        nearest_n2 = n2 - 1;
    
    sum_value = nearest_n1;
    
    how_many_times = 1 + (nearest_n2 - nearest_n1) / 2;

    if (n2 - n1 <= 1){
        printf("No odd number between %d %d\n", n1, n2);
    }
    else if (how_many_times == 1) {
        printf("%d = %d\n", nearest_n1, nearest_n1);
        *result = nearest_n1;
    }

    else if (how_many_times == 2 ) {
        printf("%d + %d = %d\n", nearest_n1, nearest_n1 + 2, 2*nearest_n1 + 2);
        *result = 2*nearest_n1 + 2;
    }
    
    else if (how_many_times > 3) {
        printf("%d", nearest_n1);
        for (value = nearest_n1 + 2; value <= nearest_n2; value += 2) {
            printf(" + %d", value);
            sum_value += value;
        }
        printf(" = %d\n", sum_value);
        *result = sum_value;
    }

}

void print_even_sum(int n1, int n2, int * result) {
    int nearest_n1 = n1;
    int nearest_n2 = n2;
    int how_many_times;
    int value;
    int sum_value;
    
    if(n1 % 2 == 1)
    nearest_n1 = n1 + 1;

    if(n2 % 2 == 1)
    nearest_n2 = n2 - 1;
    sum_value = nearest_n1;
    
    how_many_times = 1 + (nearest_n2 - nearest_n1) / 2;

    if (n2 - n1 <= 1){
        printf("No even number between %d %d\n", n1, n2);
    }
    else if (how_many_times == 1) {
        printf("%d = %d\n", nearest_n1, nearest_n1);
        *result = nearest_n1;
    }

    else if (how_many_times == 2 ) {
        printf("%d + %d = %d\n", nearest_n1, nearest_n1 + 2, 2*nearest_n1 + 2);
        *result = 2*nearest_n1 + 2;
    }
    
    else if (how_many_times > 3) {
        printf("%d", nearest_n1);
        for (value = nearest_n1 + 2; value <= nearest_n2; value += 2) {
            printf(" + %d", value);
            sum_value += value;
        }
        printf(" = %d\n", sum_value);
        *result = sum_value;
    }

}

int multi(int n1, int n2, int flag) {
    FILE * result_file = fopen("results.txt", "a+");
    int result = -1;
    if (flag == EVEN) {
        print_even_multi(n1, n2, &result);
    }

    else if (flag == ODD) {
        print_odd_multi(n1, n2, &result);
    }

    else {
        printf("bad even/num selection, try again.\n");
    }

    if (result != -1){
    print_result(result_file, result);
    return 0;
    }
    else
        return 1;

    fclose(result_file);
}

void print_even_multi(int n1, int n2, int * result) {
    int nearest_n1 = n1;
    int nearest_n2 = n2;
    int how_many_times;
    int value;
    int multi_value;
    
    if(n1 % 2 == 1)
        nearest_n1 = n1 + 1;

    if(n2 % 2 == 1)
        nearest_n2 = n2 - 1;

    multi_value = nearest_n1;
    
    how_many_times = 1 + (nearest_n2 - nearest_n1) / 2;

    if (n2 - n1 <= 1){
        printf("No even number between %d %d\n", n1, n2);
    }
    else if (how_many_times == 1) {
        printf("%d = %d\n", nearest_n1, nearest_n1);
        *result = nearest_n1;
    }

    else if (how_many_times == 2 ) {
        printf("%d * %d = %d\n", nearest_n1, nearest_n1 + 2, nearest_n1*(nearest_n1+2));
        *result = nearest_n1*(nearest_n1+2);
    }
    
    else if (how_many_times > 3) {
        printf("%d", nearest_n1);
        for (value = nearest_n1 + 2; value <= nearest_n2; value += 2) {
            printf(" * %d", value);
            multi_value *= value;
        }
        printf(" = %d\n", multi_value);
        *result = multi_value;
    }
}

void print_odd_multi(int n1, int n2, int * result) {
    int nearest_n1 = n1;
    int nearest_n2 = n2;
    int how_many_times;
    int value;
    int multi_value;
    
    if(n1 % 2 == 0)
    nearest_n1 = n1 + 1;
    if(n2 % 2 == 0)
    nearest_n2 = n2 - 1;

    multi_value = nearest_n1;
    
    how_many_times = 1 + (nearest_n2 - nearest_n1) / 2;

    if (n2 - n1 <= 1){
        printf("No odd number between %d %d\n", n1, n2);
    }
    else if (how_many_times == 1) {
        printf("%d = %d\n", nearest_n1, nearest_n1);
        *result = nearest_n1;
    }

    else if (how_many_times == 2 ) {
        printf("%d * %d = %d\n", nearest_n1, nearest_n1 + 2, nearest_n1*(nearest_n1+2));
        *result = nearest_n1*(nearest_n1+2);
    }
    
    else if (how_many_times > 3) {
        printf("%d", nearest_n1);
        for (value = nearest_n1 + 2; value <= nearest_n2; value += 2) {
            printf(" * %d", value);
            multi_value *= value;
        }
        printf(" = %d\n", multi_value);
        *result = multi_value;
    }
}
/* sum/multi functions END. */


/* prime checker functions start. */
int isprime(int a) {
    int prime = TRUE;
    int least_div;

    for (int i = 2; (i <= sqrt(a)); i++) {
        if (a % i == 0) {
            prime = FALSE;
            break;
        }
    }

    return prime;
}

int ld_calc(int value) {
int ld_value;
    for (int m = 2; m < value; m++) {
        if (value % m) {
            ld_value;
            break;
        }
    }

return ld_value;
}
/* prime checker functions end. */

/* print_file start */
void print_file(void) {
    FILE * result_file = fopen("results.txt", "r");
    int value;
    printf("result : \n");
    while (fscanf(result_file, "%d", &value) == 1 ){
        printf("%d ", value);
    }
    printf("\n");
    

    fclose(result_file);
}
/* print_file end*/



/* sort_file funcs start. */
void print_last_3(FILE * temp_file, int min1, int min2, int min3) {
    fprintf(temp_file, "%d %d %d ", min1, min2, min3);
}

void find_remaining_last_3(FILE * unsorted_file, int * min1, int * min2, int * min3) {
    int temp;

    fscanf(unsorted_file, "%d", &*min1);
    fscanf(unsorted_file, "%d", &*min2);
    fscanf(unsorted_file, "%d", &*min3);
    sort_triple(&*min1, &*min2, &*min3);
    

    while(fscanf(unsorted_file, "%d", &temp) == 1) {
         /* in the first iteration we assigned the 4th element into temp here */
        fflush(unsorted_file);
        if (temp >= *min2 && temp <= *min3) {
            *min3 = temp;
        }

        else if (temp >= *min1 && temp <= *min2) {
            *min3 = *min2;
            *min2 = temp;
        }

        else if (temp <= *min1) {
            *min3 = *min2;
            *min2 = *min1;
            *min1 = temp;
        }
    }
}
void overwrite(FILE * unsorted_file, int minx_start, int minx_end){
    int pos;
    check_file(unsorted_file);
    fseek(unsorted_file, minx_start, SEEK_SET);
    /* overwrites the number digits with spaces, 
    * as many times as its length*/
    for (int i = 0; i < (minx_end - minx_start + 1); i++) {
        pos = ftell(unsorted_file);
        fputc(' ', unsorted_file);
        pos = ftell(unsorted_file);
    }
    rewind(unsorted_file);
}
/* this finds the start and end position of 
* 3 numbers (2 or 1 if there are less numbers left)  */
void find_remaining_last_3_position(FILE * unsorted_file,
int min1, int *min1_start, int *min1_end, 
int min2, int *min2_start, int *min2_end,
int min3, int *min3_start, int *min3_end) {

    int minx_start, minx_end;
    int temp;
    int found_num_count = 0;
    int entered_min1 = 0;
    int entered_min2 = 0;
    int entered_min3 = 0;
        check_file(unsorted_file);
        rewind(unsorted_file);
        fflush(unsorted_file);
        
    minx_start = 0;
            

/* this takes the beginning file position indicator(start coordinate) and
*the end file position indicator(end coordinate), which determine how muny 
*whitespaces are required to overwrite the whole number with whitespaces. */
    while ( !(feof(unsorted_file)) && found_num_count < 3) {
        /* continue until end of file is reached or until found_num_count becomes 3 */
        minx_start = ftell(unsorted_file);
        fscanf(unsorted_file, "%d", &temp);
        minx_end = ftell(unsorted_file);
        if (temp == min1 && entered_min1 == 0) {
            *min1_start = minx_start;            
            *min1_end = minx_end;
            found_num_count++;
            entered_min1 = 1;
        }
        else if (entered_min2 == 0 && temp == min2) {
            *min2_start = minx_start;
            *min2_end = minx_end;
            found_num_count++;
            entered_min2 = 1;
        }
        else if (entered_min3 == 0 && temp == min3) {
            *min3_start = minx_start;
            *min3_end = minx_end;
            found_num_count++;
            entered_min3 = 1;
        }

    }
        
}

/* this function overwrites min1 min2 min3 values' each and every single digit
* with spaces. 
* ATTENTION! It will delete 1 or 2 numbers if there are less
* than 3 numbers left! */
void  delete_last_3(FILE * unsorted_file, int * min1, int * min2, int * min3) {
    /* these variables show start-end colomn values of minimum numbers */
    int minx_start, minx_end;
    int min1_start, min1_end;
    int min2_start, min2_end;
    int min3_start, min3_end;

    int temp;

    find_remaining_last_3_position(unsorted_file,
    *min1, &min1_start, &min1_end,  
    *min2, &min2_start, &min2_end,
    *min3, &min3_start, &min3_end);
    
    overwrite(unsorted_file, min1_start, min1_end);
    overwrite(unsorted_file, min2_start, min2_end);
    overwrite(unsorted_file, min3_start, min3_end);
}
    
void check_file(FILE * file_pointer) {
    if (file_pointer == NULL) {
        printf("Can't open file.\n");
        exit(1);
    }
}


void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* A manual sorting algorithm for sorting 3 numbers.
* from smallest to biggest. */
void sort_triple(int *num1, int *num2, int *num3) {
    if (*num1 >= *num2 && *num1 >= *num3) {
        if (*num2 >= *num3) {
            swap(&*num1, &*num3);
        }
        else {
            swap(&*num1, &*num2);
            swap(&*num2, &*num3);
        }
    }
    else if (*num1 >= *num2 && *num1 <= *num3) {
        swap(&*num1, &*num2);
    }
    else if (*num1 <= *num2 && *num1 <= *num3) {
        if (*num2 >= *num3){
            swap(&*num1, &*num3);
            swap(&*num2, &*num3);
        }
        /* else it is sorted. */
    }
    else if (*num1 <= *num2 && *num1 >= *num3) {
        swap(&*num1, &*num3);
        swap(&*num2, &*num3);
    }
}
/* skims through whole file to determine how many numbers exist. */
int take_num_count(FILE * unsorted_file) {
    int how_many = 0;
    int garbage;
    rewind(unsorted_file);

    while (fscanf(unsorted_file, "%d", &garbage) == 1) {
        how_many++;
    }
    rewind(unsorted_file);
    return how_many;
}

void delete_unsorted(void) {
    if (remove("results.txt") == 0) {
        printf("results.txt removal SUCCESFUL.\n");
    }
    else printf("ERROR! Can't delete results.txt\n");
}

void rename_temp(void) {
    if(rename("temp.txt", "results.txt") == 0) {
        printf("Replacing temp.txt with results.txt SUCCESFUL.\n");
    }
    else printf("ERROR! Can't rename temp.txt into results.txt\n");
}

void sort_file(void) {
    FILE * unsorted_file = fopen("results.txt", "r+");
    FILE * temp_file = fopen("temp.txt", "a+");
    
    int min1, min2, min3, temp;
    int num_count;
    
    check_file(unsorted_file);
    check_file(temp_file);
    
    num_count = take_num_count(unsorted_file);
    
    while (num_count > 3) {
        find_remaining_last_3(unsorted_file, &min1, &min2, &min3);
        delete_last_3(unsorted_file, &min1, &min2, &min3);
        num_count = num_count - 3;
        print_last_3(temp_file , min1, min2, min3);
    }
    if (num_count == 3) {
        fscanf(unsorted_file, "%d %d %d", &min1, &min2, &min3);
        sort_triple(&min1, &min2, &min3);
        print_last_3(temp_file, min1, min2, min3);
    }

    if (num_count == 2) {
        fscanf(unsorted_file, "%d %d", &min1, &min2);
        if (min1 > min2) swap(&min1, &min2);
        fprintf(temp_file, "%d %d ", min1, min2);
    }
    else if (num_count == 1) {
        fscanf(unsorted_file, "%d", &min1);
        fprintf(temp_file, "%d ", min1);
    }
    
    delete_unsorted();
    rename_temp();
    
    printf("Finished sorting.\n");

    fclose(temp_file);
    fclose(unsorted_file);
}
/* sort_file funcs end. */