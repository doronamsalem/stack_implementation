#ifndef __STACKT_H
#include <stddef.h>

struct stack_t * Create(size_t number_of_elements, size_t element_size);
void Destroy (struct stack_t *current_stack);
void Pop (struct stack_t *current_stack);
void Push (struct stack_t *current_stack, void *new_element);
void *Peek (const struct stack_t *current_stack);
size_t Size (const struct stack_t *current_stack);
int IsEmpty (const struct stack_t *current_stack);
size_t Capacity (const struct stack_t *current_stack);

#endif
