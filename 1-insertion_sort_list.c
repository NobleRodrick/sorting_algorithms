#include "sort.h"

/**
 * interchange_nodes - Function swaps the value of two nodes in a doubly linked list
 * @head: A pointer to the head of the doubly-linked list.
 * @first_node: A pointer to the first node to swap.
 * @second_node: precising the second node to swap.
 */
void interchange_nodes(listint_t **head, listint_t **first_node, listint_t **second_node)
{
	(*first_node)->next = second_node->next;
	if (second_node->next != NULL)
		second_node->next->prev = *first_node;
	second_node->prev = (*first_node)->prev;
	second_node->next = *first_node;
	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = second_node;
	else
		*head = second_node;
	(*first_node)->prev = second_node;
	*first_node = second_node->prev;
}

/**
 * insertion_sort_list - function to sort
 * using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *input, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		input = iter->prev;
		while (input != NULL && iter->n < input->n)
		{
			interchange_nodes(list, &input, iter);
			print_list((const listint_t *)*list);
		}
	}
}
