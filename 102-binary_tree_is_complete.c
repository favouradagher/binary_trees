#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Description: This function checks if a binary tree is complete. A binary tree
 * is considered complete if all levels are completely filled, except possibly
 * for the last level, which is filled from left to right.
 *
 * If `tree` is NULL, the function returns 0.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* Create a queue for level-order traversal */
	void *queue[2048];
	size_t front = 0, rear = 0;
	int last_level = 0;

	/* Enqueue the root node */
	queue[rear++] = (void *)tree;

	/* Continue until the queue is empty */
	while (front < rear)
	{
		const binary_tree_t *current = (const binary_tree_t *)queue[front++];

		/* Enqueue the left child if it exists */
		if (current->left)
		{
			/* Check if a gap in levels is found */
			if (last_level != 0 && (current->level - last_level) > 1)
				return (0);

			queue[rear++] = (void *)current->left;
		}

		/* Enqueue the right child if it exists */
		if (current->right)
		{
			/* Check if a gap in levels is found */
			if (last_level != 0 && (current->level - last_level) > 1)
				return (0);

			queue[rear++] = (void *)current->right;
		}

		last_level = current->level;
	}

	return (1);
}

