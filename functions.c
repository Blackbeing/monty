#include "monty.h"

int stack_size(stack_t **stack)
{
	int counter;
	stack_t *s = *stack;
	counter = 0;

	while(s != NULL)
	{
		counter++;
		s = s->next;
	}
		
	return (counter);
}

void stack_push(stack_t **stack, unsigned int i)
{
	stack_t *temp_stack = *stack;
	stack_t *end_node = malloc(sizeof(size_t));

	if (end_node == NULL)
		exit(EXIT_FAILURE);
	end_node->n = i;
	end_node->next = NULL;

	if (temp_stack == NULL)
		*stack = end_node;
	else
	{
		while (temp_stack->next != NULL)
			temp_stack = temp_stack->next;
		temp_stack->next = end_node;
		end_node->prev = temp_stack;
	}

}

void stack_pall(stack_t **stack, unsigned int i )
{
	stack_t *current;
	(void)i;
	current = *stack;

	if (current == NULL)
		return;

	while(current->next != NULL)
		current = current->next;

	while(current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}

}
/* int main(void) */
/* { */
/* 	stack_t *t = NULL; */
/* 	stack_push(&t, 1); */
/* 	stack_push(&t, 4); */
/* 	stack_push(&t, 5); */
/* 	stack_push(&t, 6); */
/* 	stack_pall(&t, 0); */
/* 	return (0); */
/* } */
