#pragma once
#include <inttypes.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct yaoosl_cstnode {
	uint64_t line;
	uint64_t column;
	uint64_t offset;

	char* value;

	struct yaoosl_cstnode* children;
	size_t children_capacity;
	size_t children_size;
} yaoosl_cstnode;

// Pushes a child to a parent node.
static bool yaoosl_cstnode_push_child(yaoosl_cstnode* parent, yaoosl_cstnode child)
{
	yaoosl_cstnode* tmp;
	if (!parent)
	{
		return true;
	}
	if (parent->children_size == parent->children_capacity)
	{
		tmp = realloc(
			parent->children,
			sizeof(yaoosl_cstnode) *
			  (parent->children_capacity + parent->children_capacity + 1));
		if (!tmp)
		{
			return false;
		}
		parent->children = tmp;
		parent->children_capacity = parent->children_capacity + parent->children_capacity + 1;
	}
	parent->children[parent->children_size++] = child;
	return true;
}

// Invalidates the nodes contents,
// clearing all fields that got allocated using
// malloc (or similar methods).
static void yaoosl_cstnode_invalidate(yaoosl_cstnode* parent)
{
	yaoosl_cstnode* tmp;
	size_t index;
	if (!parent)
	{
		return;
	}
	if (parent->value)
	{
		free(parent->children[index].value);
		parent->value = 0;
	}
	if (parent->children_size)
	{
		for (index = 0; index < parent->children_size; index++)
		{
			if (parent->children[index].value)
			{
				free(parent->children[index].value);
			}
			yaoosl_cstnode_invalidate(parent->children + index);
		}
		free(parent->children);
		parent->children = 0;
		parent->children_capacity = 0;
		parent->children_size = 0;
	}
}