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
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor of a binary tree, 0 if @tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = subtree_height(tree->left);
	right_height = subtree_height(tree->right);

	return (left_height - right_height);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, otherwise 0 or if @tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_perfect = 1, right_perfect = 1;
	int balance;

	if (!tree)
		return (0);

	if (tree->left)
		left_perfect = binary_tree_is_perfect(tree->left);
	if (tree->right)
		right_perfect = binary_tree_is_perfect(tree->right);
	balance = binary_tree_balance(tree);
	if (balance == 0 && left_perfect == 1 && right_perfect == 1)
		return (1);
	return (0);
}
