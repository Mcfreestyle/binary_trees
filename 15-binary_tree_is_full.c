#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is full, otherwise 0 or if @tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_full, right_full;

	if (!tree)
		return (0);

	left_full = binary_tree_is_full(tree->left);
	right_full = binary_tree_is_full(tree->right);

	if (left_full == right_full)
		return (1);
	return (0);
}
