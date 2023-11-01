#include "binary_trees.h"

/**
 * heap_size - Calculates the size of the heap
 * @heap: Pointer to the root node of the heap
 * Return: Size of the heap
 */
size_t heap_size(heap_t *heap)
{
    if (!heap)
        return (0);
    return (1 + heap_size(heap->left) + heap_size(heap->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 * Return: Pointer to the sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted;
    size_t i;

    if (!heap)
        return (NULL);

    *size = heap_size(heap);
    sorted = malloc(sizeof(int) * (*size));
    if (!sorted)
        return (NULL);

    for (i = 0; i < *size; i++)
        sorted[i] = heap_extract(&heap);

    return (sorted);
}

