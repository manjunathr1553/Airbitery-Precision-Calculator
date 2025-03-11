#include "apc.h"

int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char *argv[])
{
	int count=check_large(argv[1],argv[3]); // Compare the two numbers
	if(count==-1)
	{
		dl_insert_first(headR, tailR, 0); // Insert 0 if dividend is 0
		print_list(*headR);
	}
	else if(count==-2)
	{
		printf("\nINFINITY\n"); // Handle division by zero case
	}
	else if(count == 0)
	{
		dl_insert_first(headR, tailR, count); // If numbers are equal, quotient is 1
		print_list(*headR);
	}
	else if(count == 1)
	{
		dl_insert_first(headR, tailR, count); // If divisor is greater, quotient is 0
		print_list(*headR);
	}
	else if(count >= 1)
	{
		count=0;
		char str[100];
		strcpy(str,argv[1]); // Copy dividend to string
		
		list_to_str(*head1,str); // Convert list to string
	
		while(check_large(str,argv[3]) >= 1)
		{
			subtraction(head1,tail1,head2,tail2,headR,tailR); // Perform subtraction
			dl_delete_list(head1,tail1); // Delete previous list
			
			*head1=*headR;
			*tail1=*tailR;
			Dlist *temp=*head1;
			list_to_str(temp,str); // Convert updated list to string
			(*headR)=NULL;
			(*tailR)=NULL;
			
			count++; // Increase quotient count
		}
		while(count !=0)
		{
			int rem = count%10;
			dl_insert_first(headR, tailR, rem); // Store quotient in list
			count=count/10;
		}
	}
} 

int check_large(char *str1,char *str2)
{
    while(*str1 == '0')(str1)++; // Remove leading zeros from first number
    while(*str2 == '0') (str2)++; // Remove leading zeros from second number
	if(*str1 == '\0')
	{
		return -1; // If first number is zero
	}
	if(*str2 == '\0')
	{
		return -2; // If second number is zero
	}
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 < len2) return 0; // str1 is smaller
    if (len1 > len2) return 2; // str1 is larger
    
    return strcmp(str1, str2) > 0 ? 2 : (strcmp(str1, str2) < 0 ? 0 : 1); // Compare strings
}

// Function to delete all nodes in the list
int dl_delete_list(Dlist **head, Dlist **tail) {
    if (*head == NULL)
        return FAILURE;

    Dlist *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp); // Free allocated memory
    }
    *tail = NULL;
    return SUCCESS;
}

// Convert linked list to string
int list_to_str(Dlist *head, char *str) {
    int i = 0;
    Dlist *current = head; 

    if (head == NULL) {
        str[0] = '\0'; // Empty string if list is NULL
        return SUCCESS;
    }

    while (current != NULL) {
        if (current->data >= 0 && current->data <= 9) {
            str[i] = current->data + '0'; // Convert integer to char
            i++;
            current = current->next;
        } else {
            return FAILURE; // Invalid data
        }
    }

    str[i] = '\0'; // Null terminate string
    return SUCCESS;
}
