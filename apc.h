#ifndef APC_H
#define APC_H

// Define success and failure constants
#define SUCCESS 0
#define FAILURE -1

// Include necessary libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define a structure for doubly linked list node
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Dlist;

/* Function prototypes */

// Validate if the given string is a valid numeric operand
int validate_operand(char *str);

// Convert digits from input strings to doubly linked lists
void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);

// Insert a node at the end of the list
int dl_insert_last(Dlist **head, Dlist **tail, int data);

// Insert a node at the beginning of the list
int dl_insert_first(Dlist **head, Dlist **tail, int data);

// Compare two numeric strings
int compareNumericStrings(char *str1, char *str2);

// Convert a doubly linked list to a string
int list_to_str(Dlist *head, char *str);

// Print the doubly linked list
void print_list(Dlist *head);

/* Arithmetic operations */

// Addition of two numbers represented as linked lists
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

// Check which number is larger for subtraction
int check_largest(char **str1, char **str2, int *flag);

// Perform subtraction operation
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

// Perform multiplication operation
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

// Perform division operation
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *argv[]);

// Check which number is larger
int check_large(char *str1, char *str2);

// Delete the entire list
int dl_delete_list(Dlist **head, Dlist **tail);

// Handle leading zeros in the second operand
void zero(Dlist **head2, Dlist **tail2, int count);

#endif
