#include "stack.h"
#include <stdlib.h>    /* alocation funcs  malloc() */
#include <string.h>    /* memcpy() */
#include <assert.h>    /* assert() */

struct stack_t
{
	void *elements_array;
	int  top_element_index;
	size_t capacity;
	size_t element_size;
};

struct stack_t * Create(size_t number_of_elements, size_t element_size)
{
	struct stack_t *new_stack = (struct stack_t *)malloc( sizeof(struct stack_t) );
	if (new_stack == NULL)
        {
                return NULL;
        }

	new_stack -> top_element_index = -1;
	new_stack -> capacity = element_size * number_of_elements;
        new_stack -> elements_array = (void *)malloc(new_stack->capacity);
	new_stack -> element_size = element_size;
	if (new_stack->elements_array == NULL)
	{
		free(new_stack);
        	new_stack = NULL;
		return NULL;
	}
	return new_stack;
}


void Destroy (struct stack_t *current_stack)
{
        assert( current_stack != NULL );
	free(current_stack->elements_array);
        current_stack->elements_array = NULL;
	free(current_stack);
	current_stack = NULL;
}

void Pop (struct stack_t *current_stack)
{
        assert( current_stack != NULL );
	assert( current_stack->top_element_index >=  0 );
	--(current_stack->top_element_index);
}

void Push (struct stack_t *current_stack, void *new_element)
{
        assert( current_stack != NULL );
/*	assert( current_stack -> top_element_index < (current_stack -> capacity) / (current_stack -> element_size) );
*/	current_stack->top_element_index += 1;
	memcpy ( (char *)(current_stack ->elements_array) + current_stack -> top_element_index * current_stack -> element_size ,
 		new_element,
		current_stack -> element_size );
}


void *Peek (const struct stack_t *current_stack)
{
        assert( current_stack != NULL );
	assert(current_stack->top_element_index >= 0);
	return ( (char *)(current_stack -> elements_array) + current_stack -> top_element_index * current_stack -> element_size);
}

size_t Size (const struct stack_t *current_stack)
{
        assert( current_stack != NULL );
	return (current_stack->top_element_index + 1 );
}

int IsEmpty (const struct stack_t *current_stack)
{
        assert( current_stack != NULL );
	return (current_stack->top_element_index == -1);
}

size_t Capacity (const struct stack_t *current_stack)
{
        assert( current_stack != NULL );
	return (current_stack->capacity);
}

