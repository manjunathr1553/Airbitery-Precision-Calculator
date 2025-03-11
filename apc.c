#include "apc.h"

// Function to validate if the given string contains only digits
int validate_operand(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		// If a non-digit character is found, return FAILURE
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return FAILURE;
		}
		i++;
	}
	// Return SUCCESS if all characters are digits
	return SUCCESS;
}

// Function to convert digits from strings into a doubly linked list
void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
	char *str1 = argv[1]; // First number as string
    char *str2 = argv[3]; // Second number as string
    int i = 0;

    // Convert first number string to linked list
    while (str1[i] != '\0')
    {
        int num = str1[i] - '0';
        dl_insert_last(head1, tail1, num);
        i++;
    }

    i = 0;
    // Convert second number string to linked list
    while (str2[i] != '\0')
    {
        int num = str2[i] - '0';
        dl_insert_last(head2, tail2, num);
        i++;
    }
}

// Function to insert a new node at the end of the list
int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    // Allocate memory for new node
    Dlist *new_node = malloc(sizeof(Dlist));

    // Check if memory allocation was successful
    if (new_node == NULL)
    {
        return FAILURE;
    }

    // Initialize new node's data and pointers
    new_node->data = data;
    new_node->next = new_node->prev = NULL;

    // If the list is empty, set the new node as both head and tail
    if (*head == NULL)
    {
        *head = *tail = new_node;
    }
    else
    {
        // Otherwise, insert the new node at the end
        new_node->prev = *tail;
        (*tail)->next = new_node;
        *tail = new_node;
    }

    return SUCCESS;
}

// Function to insert a new node at the beginning of the list
int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    // Allocate memory for new node
    Dlist *new_node = malloc(sizeof(Dlist));

    // Check if memory allocation was successful
    if (new_node == NULL)
    {
        return FAILURE;
    }

    // Initialize new node's data and pointers
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    // If the list is empty, set the new node as both head and tail
    if (*tail == NULL)
    {
        *tail = new_node;
        *head = new_node;
        return SUCCESS;
    }

    // Insert the new node at the beginning of the list
    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;

    return SUCCESS;
}

// Function to print the elements of the list
void print_list(Dlist *head)
{
	// Check if the list is empty
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    // Traverse and print the list elements
	    while (head)		
	    {
		    printf("%d", head->data);
		    head = head->next;
	    }
        printf("\n");
    }
}
