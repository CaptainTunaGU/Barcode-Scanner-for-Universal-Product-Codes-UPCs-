/* ---- UPCs Barcode scanner ---- */
    /* Statement of input(s) 12 digit barcode*/
    /* Statement of output(s) valid or invalid response after calculations*/

/* Problem Statement: A barcode scanner for Universal Product Codes (UPCs) verifies the 12-digit code scanned by comparing the code’s last digit (called a check digit) to its own computation of the check digit .*/
/* Author: Ian Langelett */
/* Created Date: 04/02/2024 */
/* Revised by: Ian Langelett */
/* Revision Date: 04/19/2024 */



/* ---- Preprocessor Directives ---- */

    /* ---- Required libraries ---- */

#include <stdio.h>      /* printf, scanf definitions */
#include <math.h>
    /* ---- Function prototype definitions ---- */

int odd_numbers(int array[], int barcode_size);
int even_numbers(int array[], int barcode_size);

/* ---- Main Function ---- */
int
main(void)
{
/* ---- Declare Local variables ---- */
int barcode_size = 12;
int array[barcode_size];
int odd;
int even;
int step_one;
int step_two;
int checkdigit;
int digita;
int i=0;
/**************************************************************************/
/* ---- Executable Statements ---- */
 /*Get the data*/
    printf("Enter %d Bar-Code Digits Separated By: <ENTER>\n", barcode_size);

    for (i = 0; i < barcode_size; ++i)
        scanf("%d", &array[i]);
/*Data is sent to subprograms to be calculated*/
/**************************************************************************/
/*Call Functions*/
                                                        /*Print Executables to help me troubleshoot exactly WHERE the data was going after collecting it*/
    odd = odd_numbers(array, barcode_size);
                                                                            /*printf("Returned odd = %d\n", odd);*/
    even = even_numbers(array, barcode_size);
                                                                            /*printf("Returned even = %d\n", even);*/
/*Calculate Bar-Code Check-Digit*/
    step_one = 3 * odd;
                                                                            /*printf("Step One: %d\n", step_one);*/
    step_two = step_one + even;
                                                                            /*printf("Step Two: %d\n", step_two);*/
    checkdigit = step_two % 10;
                                                                            /*printf("Checkdigit: %d\n", checkdigit);*/

    if (checkdigit != 0)
        digita = 10 - checkdigit;

    else
        digita = checkdigit;

/*************************************************************************/
/*Check if Bar-Code's Check-Digit = Final Bar-Code Number for Validation
If Check-Digit does not = Final Bar-Code Number, then Bar-Code is invalid (error)*/

    if (checkdigit = array[11])
        printf("\nBar-Code is Validated.\n");
    else
        printf("\nError in Bar-Code.\n");
/*Print Odd and Even Bar-Code calculations for Potential User Troubleshooting*/
    printf("\nOdd Number Bar-Code Value is %d.\n\nEven Number Bar-Code Value is %d.\n", step_one, step_two);
}
/**************************************************************************/

/* ---- Function subprograms ---- */

/*Use gathered data to find the odd digits
Then return the sum of said digits to main function*/
int
odd_numbers(int array[], int barcode_size)
{
/*Declare local variables*/
int i;
int odd;
odd = 0;
/**************************************************************************/
/*Find the sum of odd digits, store as "odd"*/
for (i = 0; i <= 10; i += 2)
    odd += array[i];

/*Return odd value to main function*/                                                                            /*printf("Odd Sum: %d\n", odd);*/
return(odd);
}
/**************************************************************************/

/*Use gathered data to find the even digits (except the last digit)
Then return the sum of said digits to main function*/
int
even_numbers(int array[], int barcode_size)
{
/*Declare local variables*/
int i;
int even;
even = 0;
/**************************************************************************/
/*Find the sum of even digits (not the last digit), store as "even"*/
for (i = 1; i <= 9; i += 2)
    even += array[i];
/**************************************************************************/
/*Return even value to main function*/                                                                            /*printf("Even Sum: %d\n", even);*/
return(even);
}
