#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function traverses a binary tree in level-order, calling
 * the specified function for each node in the tree.
 *
 * If `tree` or `func` is NULL, do nothing.
 *
 * @tree: A pointer to the root node of the tree.
 * @func: A pointer to a function that takes an integer as a parameter.
 *
 * Return: Void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/* Create a queue for level-order traversal */
	void *queue[2048];
	size_t front = 0, rear = 0;
	const binary_tree_t *current;

	/* Enqueue the root node */
	queue[rear++] = (void *)tree;

	/* Continue until the queue is empty */
	while (front < rear)
	{
		/* Dequeue the front node */
		current = (const binary_tree_t *)queue[front++];
		func(current->n);

		/* Enqueue the left child if it exists */
		if (current->left)
			queue[rear++] = (void *)current->left;

		/* Enqueue the right child if it exists */
		if (current->right)
			queue[rear++] = (void *)current->right;
	}
}

