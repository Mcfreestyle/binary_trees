#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node
 *
 * Return: pointer to the uncle node, NULL if @node or its uncle is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	if (!node)
		return (NULL);

	parent = node->parent;
	if (!parent)
		return (NULL);
	grandparent = parent->parent;
	if (!grandparent)
		return (NULL);

	if (grandparent->left != parent)
		return (grandparent->left);
	else
		return (grandparent->right);
}
