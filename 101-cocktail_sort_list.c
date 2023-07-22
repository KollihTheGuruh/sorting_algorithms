#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @h: Pointer to the head of the list
* @n1: Pointer to the first node to swap
* @n2: Pointer to the second node to swap
*/
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
listint_t *n2_next = n2->next;
listint_t *n2_prev = n2->prev;

if (*n1 == n2)
{
return;
}

if ((*n1)->prev)
{
(*n1)->prev->next = n2;
}
else
{
*h = n2;
}
if (n2->prev)
{
n2->prev->next = *n1;
}
else
{
*h = *n1;
}

if ((*n1)->next == n2)
{
(*n1)->next = n2_next;
n2->prev = *n1;
n2->next = *n1;
}
else
{
(*n1)->next->prev = n2;
(*n1)->next = n2_next;
n2->prev = (*n1)->prev;
n2->next = *n1;
}

(*n1)->prev = n2_prev;
}

/**
* cocktail_sort_list - Sorts a doubly linked list of integers
*                      in ascending order using the Cocktail shaker sort.
*
* @list: Double pointer to the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
int swapped = 1;
listint_t *current;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = *list;
while (swapped)
{
swapped = 0;
while (current->next != NULL)
{
if (current->n > current->next->n)
{
swap_nodes(list, &current, current->next);
print_list(*list);
swapped = 1;
}
else
{
current = current->next;
}
}
if (!swapped)
break;
swapped = 0;
while (current->prev != NULL)
{
if (current->prev->n > current->n)
{
swap_nodes(list, &current->prev, current);
print_list(*list);
swapped = 1;
}
else
{
current = current->prev;
}
}
}
}

