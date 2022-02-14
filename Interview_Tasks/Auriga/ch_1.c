/*
 * The following code compiles on Linux. It has a number of problems, however.
 * Please locate as many of those problems as you are able and provide your
 * recommendations regarding how they can be resolved.
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct list_s
{
	struct list_s *next; /* NULL for the last item in a list */
	int data;
} list_t;

/*
 * Counts the number of items in a list.
 */
int count_list_items(const list_t *head) {
	if (head->next) {
		return count_list_items(head->next) + 1; // recursion
	} else {
		return 1;
	}
}

/* Inserts a new list item after the one specified as the argument.
 */
void insert_next_to_list(list_t *item, int data) {
	/*(item->next = malloc(sizeof(list_t)))->next = item->next;
	item->next->data = data;
	*/
	// operation on ‘item->next’ may be undefined
	list_t *new = (list_t *) malloc(sizeof(list_t));
	if (new == NULL)
		exit(1);
	new->next = item->next;
	new->data = data;
	item->next = new;
}

/* Removes an item following the one specificed as the argument.
 */
void remove_next_from_list(list_t *item) {
	if (item->next) {
		// free(item->next); //!!!
		// item->next = item->next->next;
		list_t *tmp = item->next->next;
		free(item->next);
		item->next = tmp;
	}
}

/* Returns item data as text.
 */
/*
char *item_data(const list_t *list)
{
	char buf[12];

	sprintf(buf, "%d", list->data);
	return buf; // function returns address of local variable
}
*/
char *item_data(const list_t *list, char *buf) {
	//char buf[12];

	sprintf(buf, "%d", list->data);
	return buf; // function returns address of local variable
}

void display(list_t *item) {
	int n = 0;
	char str[12];
	while (item) {
		n++;
		if (n % 2 != 0) {
			remove_next_from_list(item); // list odd item
			continue;
		}
		printf("Current: %s\n", item_data(item, str));
		//printf("Current: %s\n", item->data);

		item = item->next;
	}
}

int main(void) {
	list_t LIST = {NULL, 1};

	for (int i = 50; i > 1; --i)
		insert_next_to_list(&LIST, i);

	printf("Count %d\n", count_list_items(&LIST));
	display(&LIST);

	return 0;
}
