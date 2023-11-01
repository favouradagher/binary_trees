#include "binary_trees.h"
/**
 * find_parent - finds the parent to insert a new node
 * @root: pointer to the root node
 * @depth: depth of the tree
 * @value: the value of the new node
 * Return: pointer to the parent
 */
binary_tree_t *find_parent(binary_tree_t *root, int depth, int value)
{
    if (!root)
        return (NULL);

    if (depth == 1)
    {
        if (root->left && root->right)
            return (NULL);
        return (root);
    }
    return (find_parent(root->left, depth - 1, value) ?:
            find_parent(root->right, depth - 1, value));
}

/**
 * create_node - creates a new node
 * @parent: the parent node
 * @value: the value to store in the new node
 * Return: pointer to the new node
 */
heap_t *create_node(binary_tree_t *parent, int value)
{
    heap_t *node;

    node = binary_tree_node(parent, value);
    if (!node)
        return (NULL);
    if (parent->left)
        parent->right = node;
    else
        parent->left = node;
    return (node);
}

/**
 * max_heapify - maintain max-heap property
 * @node: pointer to the heap
 * Return: pointer to the root
 */
heap_t *max_heapify(heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }
    return (node);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: pointer to the root of the heap
 * @value: value to be inserted
 * Return: pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
    binary_tree_t *parent;
    heap_t *node;

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }
    node = *root;
    parent = find_parent(*root, 1, value);
    node = create_node(parent, value);
    if (!node)
        return (NULL);
    return (max_heapify(node));
}

