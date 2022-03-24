#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, otherwise 0 if @tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_height = binary_tree_height(tree->left) + 1;
	if (tree->right)
		right_height = binary_tree_height(tree->right) + 1;
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * print_current_level - prints the nodes in the current level of binary tree
 * @tree: pointer to the root node
 * @level: level of the binary tree
 * @func: pointer to a function to call each node
 */
void print_current_level(const binary_tree_t *tree, int level,
				void (*func)(int))
{
	if (!tree)
		return;

	if (level == 0)
		func(tree->n);
	else
	{
		print_current_level(tree->left, level - 1, func);
		print_current_level(tree->right, level - 1, func);
	}

}

/**
 * binary_tree_levelorder - goes through a binary tree
 *				using level-order traversal
 * @tree: pointer to the root node
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);

	for (i = 0; i <= height; i++)
		print_current_level(tree, i, func);
}

