#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *add_node(struct node *root, int value) {
	if (!root) {
		root = malloc(sizeof(struct node));
		root->value = value;
		root->next = NULL;
		return root;
	}
	struct node *new_node = malloc(sizeof(struct node));
	new_node->value = value;
	new_node->next = NULL;
	struct node *iter = root;
	while (iter->next) {
		iter = iter->next;
	}
	iter->next = new_node;
	return root;
}

void print_list(struct node *root) {
	while (root) {
		printf("%d\n", root->value);
		root = root->next;
	}
}

void free_list(struct node *root) {
	while (root) {
		struct node *iter = root;
		root = root->next;
		free(iter);
	}
}

struct node *delete_from_list(struct node *root, int value) {
	if (root->value == value) {
		struct node *iter = root->next;
		free(root);
		return iter;
	}
	printf("DEL: %d\n", value);
	struct node *iter = root;
	while (iter) {
		if (iter->next && (iter->next->value == value)) {
			printf("FOUND: %d\n", iter->next->value);
			struct node *tmp = iter->next;
			iter->next = iter->next->next;
			free(tmp);
		}
		iter = iter->next;
	}
	return root;
}

int main() {
	struct node *root = add_node(NULL, 10);
	root = add_node(root, 15);
	root = add_node(root, 3);
	root = add_node(root, 8);
	root = add_node(root, 0);
	root = add_node(root, 148);
	print_list(root);
	printf("\n\n\n");
	root = delete_from_list(root, 15);
	root = delete_from_list(root, 8);
	print_list(root);
	free_list(root);

	return 0;
}
