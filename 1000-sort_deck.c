#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
* _strcmp - Compare two strings
* @s1: Pointer to the first string
* @s2: Pointer to the second string
*
* Description:
* This function compares the two strings pointed to by s1 and s2.
* It returns an integer less than, equal to, or greater than zero
* if s1 is found to be less than, match, or greater than s2,
* respectively.
*
* Return:
*     If the function succeeds, it returns an integer value as follows:
*     - A value less than 0 if s1 is less than s2
*     - 0 if s1 is equal to s2
*     - A value greater than 0 if s1 is greater than s2
*/
int _strcmp(const char *s1, const char *s2)
{
while (*s1 && *s2 && *s1 == *s2)
{
s1++;
s2++;
}

if (*s1 != *s2)
return (*s1 - *s2);
return (0);
}

/**
* get_value - Retrieve the value of a card in the deck.
* @card: Pointer to the deck_node_t representing the card.
*
* This function takes a deck_node_t pointer as input and returns
* the character value of the card. The deck_node_t struct contains
* information about the card, including its value.
*
* Return: The character value of the card.
*/
char get_value(deck_node_t *card)
{
if (_strcmp(card->card->value, "Ace") == 0)
return (0);
if (_strcmp(card->card->value, "1") == 0)
return (1);
if (_strcmp(card->card->value, "2") == 0)
return (2);
if (_strcmp(card->card->value, "3") == 0)
return (3);
if (_strcmp(card->card->value, "4") == 0)
return (4);
if (_strcmp(card->card->value, "5") == 0)
return (5);
if (_strcmp(card->card->value, "6") == 0)
return (6);
if (_strcmp(card->card->value, "7") == 0)
return (7);
if (_strcmp(card->card->value, "8") == 0)
return (8);
if (_strcmp(card->card->value, "9") == 0)
return (9);
if (_strcmp(card->card->value, "10") == 0)
return (10);
if (_strcmp(card->card->value, "Jack") == 0)
return (11);
if (_strcmp(card->card->value, "Queen") == 0)
return (12);
return (13);
}


/**
 * insertion_sort_deck_kind - Sorts a deck of cards based on their kinds
 *                            using the Insertion Sort algorithm.
 *
 * @deck: Double pointer to the head of the deck.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
deck_node_t *iter, *insert, *tmp;

for (iter = (*deck)->next; iter != NULL; iter = tmp)
{
tmp = iter->next;
insert = iter->prev;
while (insert != NULL && insert->card->kind > iter->card->kind)
{
insert->next = iter->next;
if (iter->next != NULL)
iter->next->prev = insert;
iter->prev = insert->prev;
iter->next = insert;
if (insert->prev != NULL)
insert->prev->next = iter;
else
*deck = iter;
insert->prev = iter;
insert = iter->prev;
}
}
}

/**
 * insertion_sort_deck_value - Sorts a deck of cards based on their values
 *                            using the Insertion Sort algorithm.
 *
 * @deck: Double pointer to the head of the deck.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
deck_node_t *iter, *insert, *tmp;

for (iter = (*deck)->next; iter != NULL; iter = tmp)
{
tmp = iter->next;
insert = iter->prev;
while (insert != NULL &&
insert->card->kind == iter->card->kind &&
get_value(insert) > get_value(iter))
{
insert->next = iter->next;
if (iter->next != NULL)
iter->next->prev = insert;
iter->prev = insert->prev;
iter->next = insert;
if (insert->prev != NULL)
insert->prev->next = iter;
else
*deck = iter;
insert->prev = iter;
insert = iter->prev;
}
}
}

/**
 * sort_deck - Sorts a deck of cards in ascending order using Merge Sort.
 *
 * @deck: Double pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
return;

insertion_sort_deck_kind(deck);
insertion_sort_deck_value(deck);
}
