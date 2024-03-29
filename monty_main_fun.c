#include "monty.h"
/**
 * push - push number to stack
 * @stack: the stack
 * @line_number: line of command
 */
void push(stack_t **stack, unsigned int line_number)
{
	parser->value = _atoi(*parser->str);
	if (parser->is_converted)
	{
		add_dnodeint(stack, parser->value);
		parser->success = 1;
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints all element on the stack
 * @stack: the stack
 * @line_number: line of command
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stk(*stack);
	parser->success = 1;
}
/**
 * pint - prints top elem of stack
 * @stack: the stack
 * @line_number: line of command
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		print_top(*stack);
		parser->success = 1;
	}
	else
	{
		parser->success = 0;
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - pops element from stack
 * @stack: the stack
 * @line_number: line of command
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		delete_dnodeint_at_index(stack, 0);
		parser->success = 1;
	}
	else
	{
		parser->success = 0;
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}


}
/**
 * _swap - swaps first 2 element
 * @stack: the stack
 * @line_number: line of command
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	if (*stack && dlen(*stack) >= 2)
	{
		_swapp(stack);
		parser->success = 1;
	}
	else
	{
		parser->success = 0;
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
