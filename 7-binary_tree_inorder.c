#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs an in-order traversal of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    binary_tree_inorder(tree->left, func);   // Traverse left subtree
    func(tree->n);                          // Call the function with the current node's value
    binary_tree_inorder(tree->right, func);  // Traverse right subtree
}

