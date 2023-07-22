#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending
*                        order using the Insertion sort algorithm.
*
* @list: Double pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *c = *list, *n;

if (!list || !*list || !(*list)->next)
return;

while (c)
{
n = c->next;
while (c->prev && c->n < c->prev->n)
{
c->prev->next = c->next;
if (c->next)
c->next->prev = c->prev;
c->next = c->prev;
c->prev = c->prev->prev;
c->next->prev = c;
if (!c->prev)
*list = c;
else
c->prev->next = c;
print_list(*list);
}
if (!c->prev)
*list = c;
c = n;
}
}

