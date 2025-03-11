#include "apc.h"

// Function to perform subtraction of two numbers stored as doubly linked lists
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int data, borrow = 0;
    Dlist *temp1 = *tail1; // Pointer to traverse first number
    Dlist *temp2 = *tail2; // Pointer to traverse second number
    
    // Traverse the lists from the last digit to the first
    while (temp1 != NULL || temp2 != NULL)
    {
        int num1 = 0, num2 = 0;

        // Get the digit from the first number
        if (temp1 != NULL)
        {
            num1 = temp1->data;
        }

        // Get the digit from the second number
        if (temp2 != NULL)
        {
            num2 = temp2->data;
        }
        else
        {  
            num2 = 0;
        }

        // Handle borrowing if needed
        if (borrow == 1)
        {
            num1 = num1 - 1;
            borrow = 0;
        }

        // If num1 is smaller than num2, borrow from the next higher digit
        if (num1 < num2)
        {
            num1 = num1 + 10;
            borrow = 1;
        }

        // Subtract and store the result
        data = num1 - num2;
        dl_insert_first(headR, tailR, data);

        // Move to the previous digit
        if (temp1 != NULL)
        {
            temp1 = temp1->prev;
        }
        else
        {
            temp1 = NULL;
        }
        if (temp2 != NULL)
        {
            temp2 = temp2->prev;
        }
        else
        {
            temp2 = NULL;
        }
    }
    return SUCCESS;
}

// Function to determine the larger number and swap if necessary
int check_largest(char **str1, char **str2, int *flag)
{
    // Remove leading zeros from both numbers
    while (**str1 == '0') (*str1)++;
    while (**str2 == '0') (*str2)++;

    int num1 = strlen(*str1); // Length of first number
    int num2 = strlen(*str2); // Length of second number
    char *temp;

    // Compare lengths to determine the larger number
    if (num1 < num2)
    {
        *flag = 1;  // Indicate that swapping occurred
        temp = *str1;
        *str1 = *str2;
        *str2 = temp;
    }
    else if (num1 == num2)
    {
        // If lengths are equal, compare the strings lexicographically
        int check = strcmp(*str1, *str2);
        if (check > 0)
        {
            *str1 = *str1;
            *str2 = *str2;
        }
        else if (check < 0)
        {
            *flag = 1;  // Indicate swapping
            temp = *str1;
            *str1 = *str2;
            *str2 = temp;
        }
    }
    return SUCCESS;
}
