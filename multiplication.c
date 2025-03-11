#include "apc.h"

// Function to perform multiplication of two numbers represented as doubly linked lists
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *headR1 = NULL, *tailR1 = NULL;  // Stores intermediate results
    Dlist *headR2 = NULL, *tailR2 = NULL;  // Stores the result of current multiplication step
    Dlist *temp1 = *tail1, *temp2 = *tail2;
    int count = 0;  // Used to add trailing zeros for place value adjustment

    while (temp1 != NULL)
    {
        int rem = 0;  // Carry for multiplication
        int data;
        int num2, num1;

        // Add trailing zeros based on the current digit position
        zero(&headR2, &tailR2, count);

        while (temp2 != NULL || rem != 0)
        {
            if (temp2 == NULL && rem == 0)
                break;

            num1 = temp1->data;
            num2 = (temp2 != NULL) ? temp2->data : 0;  

            // Multiply digits and add carry
            int num = (num1 * num2) + rem;
            data = num % 10;  // Extract last digit
            rem = num / 10;    // Update carry

            // Insert digit into the result list
            if(temp1->next == NULL)
            {
                dl_insert_first(&headR1, &tailR1, data);
            }
            else
            {
                dl_insert_first(&headR2, &tailR2, data);
            }

            // Move to the previous digit in second number
            if (temp2 != NULL)
            {
                temp2 = temp2->prev;
            }
        }

        // Add intermediate result to the final result
        if (headR1 != NULL)
        {
            addition(&headR1, &tailR1, &headR2, &tailR2, headR, tailR);

            // Delete temporary lists
            dl_delete_list(&headR1, &tailR1);
            dl_delete_list(&headR2, &tailR2);

            headR1 = tailR1 = NULL;
            headR2 = tailR2 = NULL;

            // Update the final result pointers
            if (*headR != NULL)
            {
                headR1 = *headR;
                tailR1 = *tailR;
            }
            else
            {
                headR1 = tailR1 = NULL;
            }

            *headR = NULL;
            *tailR = NULL;
        }

        // Move to the previous digit in first number
        if (temp1 != NULL)
        {
            temp1 = temp1->prev;
        }
        else
        {
            break;
        }

        count++;  // Increase position for next digit multiplication
        temp2 = *tail2;  // Reset temp2 pointer to last digit of second number
    }

    *headR = headR1;
    *tailR = tailR1;

    return 0;
}

// Function to insert trailing zeros in the list for place value adjustment
void zero(Dlist **head2, Dlist **tail2, int count)
{
    while (count > 0)
    {
        dl_insert_first(head2, tail2, 0);
        count = count - 1;
    }
}
