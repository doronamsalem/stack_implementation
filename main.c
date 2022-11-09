#include "stack.h"
#include <stdio.h>

int main ()
{
        int a = 3, b = 4, c = 9;
        struct stack_t *my_stack;
        my_stack = Create ( 3, 4 );
	if ( my_stack == NULL )
	{
		printf("malloc failed");
		return 1;
	}
	else
	{
		printf("Before pushing:\n capacity is:%ld   number of elements:%ld\n",Capacity(my_stack) , Size(my_stack));
        	Push(my_stack, &a);
        	Push(my_stack, &b);
        	Push(my_stack, &c);
/*      	Push(my_stack, &c);     /*pusing to full stack*/
        	printf("After pushing:\n capacity is:%ld   number of elements:%ld  first element:%d\n",Capacity(my_stack) , Size(my_stack), *((int *)Peek(my_stack)) );
        	Pop(my_stack);
        	Pop(my_stack);
        	printf("After poping:\n capacity is:%ld   number of elements:%ld  first element:%d\n",Capacity(my_stack) , Size(my_stack), *((int *)Peek(my_stack)) );
/*      	Pop(my_stack);
        	Pop(my_stack);          /*poping from empty stack*/
        	Destroy(my_stack);
/*      	Pop(my_stack);     /*pushing to unexist stack*/
	}
	return 0;
}
