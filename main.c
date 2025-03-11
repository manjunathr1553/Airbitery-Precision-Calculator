/*  Name: Manjunath R
	Date: 26/02/2025
	Description: Arbitrary Precision Calculator
	Sample i/o: test case 1(addition): input - ./a.out 8793673463868160844 + 45445468454667458461
									   output - 54239141918535619305
									   
									   input - ./a.out 1234 + 1234
									   output - 2468  
				test case 2(substraction): input - ./a.out 8793673463868160844 - 454454684546
				    					   output - 8793673009413476298
										   
										   input - ./a.out 12 - 1459  
										   output - -1447
				test case 3(multiplication): input - ./a.out 484467463476784 x 46721445667
											 output - 22635020272259870571894928
											 
											 input - ./a.out 256 x 39
											 output - 9984
				test case 4(Division): input - ./a.out 2000000000000000 / 2000000000
									   output - 1000000
									   
									   input - ./a.out 288 / 12  
									   output - 24													*/
#include "apc.h"
#include<stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    // Check if the correct number of arguments is provided
    if (argc != 4)
    {
        printf("ERROR: INVALID NUMBER OF ARGUMENTS\n");
        return 1;
    }

    // Declare pointers for the doubly linked lists
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL; 
    Dlist *headR = NULL, *tailR = NULL;

    // Validate input operands
    if ((validate_operand(argv[1]) == FAILURE) || (validate_operand(argv[3]) == FAILURE))
    {
        printf("ERROR: Invalid input\n");
        return 1;
    }

    // Get the operator from input
    char operator = argv[2][0];
	if(argv[2][1] !='\0')
	{
		printf("ERROR: Invalid input\n");
        return 1;
	}

    // Perform the respective operation based on the operator
    switch (operator)
    {
        case '+':
            // Addition operation
            digit_to_list(&head1, &tail1, &head2, &tail2, argv);
            addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            print_list(headR);
            break;

        case '-':    
            // Subtraction operation
            int flag = 0;
            int num = check_largest(&argv[1], &argv[3], &flag);
            digit_to_list(&head1, &tail1, &head2, &tail2, argv);
            subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            if (flag)
                printf("-");
            print_list(headR);
            break;

        case 'x':    
            // Multiplication operation
            digit_to_list(&head1, &tail1, &head2, &tail2, argv);
            multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            print_list(headR);
            break;

        case '/':    
            // Division operation
            digit_to_list(&head1, &tail1, &head2, &tail2, argv);
            division(&head1, &tail1, &head2, &tail2, &headR, &tailR, argv);
            print_list(headR);
            break;

        default:
            // Invalid operator
            printf("Invalid Input: Try again...\n");
    }
    
    return 0;
}
