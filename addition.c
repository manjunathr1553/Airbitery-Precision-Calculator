#include "apc.h"

// Function to perform addition of two numbers stored as doubly linked lists
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) 
{
    int carry = 0;  // Variable to store carry value
    Dlist *temp1 = *tail1;  // Pointer to traverse first number
    Dlist *temp2 = *tail2;  // Pointer to traverse second number

    // Traverse the lists from the last digit to the first
    while (temp1 != NULL || temp2 != NULL || carry != 0) 
    {
        int data = carry;  // Start with carry value

        // Add digit from the first number if available
        if (temp1 != NULL) 
        {
            data += temp1->data;  
            temp1 = temp1->prev;   
        }

        // Add digit from the second number if available
        if (temp2 != NULL) 
        {
            data += temp2->data;  
            temp2 = temp2->prev;   
        }

        // Calculate new carry and store the last digit
        carry = data / 10;  
        data = data % 10;   

        // Insert result digit at the beginning of the result list
        dl_insert_first(headR, tailR, data);
    }

    return 0;  
}
