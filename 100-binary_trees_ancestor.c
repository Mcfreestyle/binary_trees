#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: the depth of a node, otherwise 0 if @tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !(tree->parent))
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	int first_depth, second_depth, dif_depth;
	binary_tree_t *deep, *shallow;

	if (!first || !second)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	if (first_depth > second_depth)
	{
		deep = (binary_tree_t *)first;
		shallow = (binary_tree_t *)second;
	}
	else
	{
		deep = (binary_tree_t *)second;
		shallow = (binary_tree_t *)first;
	}

	dif_depth = first_depth - second_depth;
	if (dif_depth < 0)
		dif_depth *= -1;

	while (dif_depth != 0)
	{
		if (deep == shallow)
			return (deep);
		deep = deep->parent;
		dif_depth--;
	}
	while (deep)
	{
		if (deep == shallow)
			return (deep);
		deep = deep->parent;
		shallow = shallow->parent;
	}
	return (NULL);
}
