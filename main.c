#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"

/* Code description:
*    
*    1, and 2. Takes sum or multiplication of even/odd integers on a closed interval given by the user. 
*    3. calculate as many prime numbers as the user wishes, while displaying the least divisor of the non-prime 
*        values that have been tested for prime-ity
*    4. displays the number sequence written in the file.
*    5. sorts the file 3 by 3 (This was a requirement, this code sorts by picking the 3 smallest at each turn, 
        and deleting the picked values.)
* NOTICE: Arrays were forbidden and we must have sorted the file 3 by 3 
*as a given condition, so a monstrosity like this happened. I'm sorry. 
*(pointers were forbidden as well but I learnt about it only after completing the code)
*/

int main(void) {

    /* this creates results.txt file if it's nonexistent */
    FILE * test_results_file = fopen("results.txt", "a+");
    fclose(test_results_file);
    int operation;

    int selection;
    int flag;
    int n1, n2;

    int a;
    int n;
    int k;

    int sum_return;
    int multi_return;
    /* it exists from loop by exit() when EXIT is selected */
    while(1){
    printf("Select operation:\n");
    printf("0. Exit program\n");
    printf("1. Calculate sum/multiplication between two numbers\n");
    printf("2. Calculate prime numbers\n");
    printf("3. Show number sequence in file\n");
    printf("4. Sort number sequence in file\n");
    printf("----------------\n");

    take_int(&operation);
           if(operation != 0)
                if(operation != 1)
                    if(operation != 2)
                        if(operation != 3)
                            if(operation != 4){
                            printf("Invalid operation selection \n");
                            }
    switch (operation){
        case EXIT:
        printf("exitting\n");
        return 0;
        exit(0); 
        break;
        
        case sum_multi:

            printf("Enter '0' for sum, '1' for multiplication\n");
            take_int(&selection);

            if(selection == 0) {
                printf("Enter '0' to work on even numbers, '1' to work on odd numbers\n");
                take_int(&flag);
                printf("Enter two different positive numbers: \n");
                printf("Num 1: ");
                take_int(&n1);
                printf("Num2 : ");
                take_int(&n2);
                if (n1 < 0 || n2 < 0 || n1 == n2) {
                    printf("Num1 and Num2 must be different positive.\n");
                    exit(1);
                }
                printf("Result: ");
                sum_return = sum(n1, n2, flag);
                if(sum_return == 0) {
                     printf("printing result to file.\n");
                }
                else{
                    printf("INVALID result. NOT printing to file.\n");
                }
            }            

            else if(selection == 1) {
                printf("Enter '0' to work on even numbers, '1' to work on odd numbers\n");
                take_int(&flag);
                printf("Enter two different numbers: \n");
                printf("Num 1: ");
                take_int(&n1);
                printf("Num2 : ");
                take_int(&n2);
                if (n1 < 0 || n2 < 0 || n1 == n2) {
                    printf("Num1 and Num2 must be different positive.\n");
                    exit(1);
                }
                printf("Result: "); 
                multi_return = multi(n1, n2, flag);
                if(multi_return == 0) {
                    printf("printing result to file.\n");
                }
                else{
                    printf("INVALID result. NOT printing to file.\n");
                }
            }

            else{
                printf("Bad selection, exitting program.\n");
                exit(1);
            }
        break;
        
        case prime:
            k = 1;
            printf("Please enter an integer: ");
            take_int(&n);
            if (n <= 1) {
                printf("Select a valid value, try again.\n");
            }
            else {
                while(k < n){
                    if (isprime(k) == TRUE) {
                        printf("%d is a prime number\n", k);
                    }
                    else {
                        printf("%d is not a prime number,", k);
                        printf(" it is divisible by %d.\n", ld_calc(k));
                    }
                    k++;
                }
            }
            break;
        
        case display:
            print_file();
            break;

        case sort:
            sort_file();
            break;

        
    }
    }
/* code shouldn't have come here since there's while(1) and exit() */
return 1;
}
