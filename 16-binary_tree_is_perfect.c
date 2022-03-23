#include "binary_trees.h"

/**
 * subtree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, otherwise -1 if @tree is NULL
 */
int subtree_height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (-1);

	left_height = subtree_height(tree->left);
	right_height = subtree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}

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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, otherwise 0 or if @tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height, left_full, right_full;

	if (!tree)
		return (0);

	left_height = subtree_height(tree->left);
	right_height = subtree_height(tree->right);
	left_full = binary_tree_is_full(tree->left);
	right_full = binary_tree_is_full(tree->right);

	if (left_height == right_height && left_full == right_full)
		return (1);
	return (0);
}
