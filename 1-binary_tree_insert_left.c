#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the new node, otherwise NULL if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node_left;

	if (!parent)
		return (NULL);

	node_left = binary_tree_node(parent, value);
	if (parent->left)
	{
		(parent->left)->parent = node_left;
		node_left->left = parent->left;
	}
	parent->left = node_left;

	return (node_left);
}
