#include "binary_trees.h"

/**
 * swap_values - Swaps values between two nodes
 * @a: First node
 * @b: Second node
 */
void swap_values(heap_t *a, heap_t *b)
{
    int tmp = a->n;

    a->n = b->n;
    b->n = tmp;
}

/**
 * heapify_down - Fixes the max heap property by moving the root down
 * @root: Pointer to the root of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *child, *largest;

    while (1)
    {
        largest = root;
        if (root->left && root->left->n > largest->n)
            largest = root->left;
        if (root->right && root->right->n > largest->n)
            largest = root->right;
        if (largest == root)
            break;
        swap_values(root, largest);
        root = largest;
    }
}

/**
 * get_last_node - Retrieves the last node of the heap in level-order
 * @root: Pointer to the root of the heap
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
    heap_t *last = root;

    while (last->left || last->right)
    {
        if (last->right)
            last = last->right;
        else
            last = last->left;
    }
    return (last);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node
 */
int heap_extract(heap_t **root)
{
    heap_t *last, *temp;
    int value;

    if (!root || !*root)
        return (0);

    last = get_last_node(*root);
    swap_values(*root, last);

    if (last->parent && last->parent->right == last)
        last->parent->right = NULL;
    else if (last->parent)
        last->parent->left = NULL;

    value = last->n;
    free(last);
    heapify_down(*root);
    return (value);
}

