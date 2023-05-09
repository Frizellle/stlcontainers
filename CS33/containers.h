#include <stdio.h>
#include <stdlib.h>

// Vector (To do: pseudo-templatize by converting data to void*)

typedef struct
{
	int* data;
	int size;
	int capacity;
} vector;

vector createVector(int initialCapacity)
{
	vector vec;
	vec.data = malloc(sizeof(int) * initialCapacity);
	vec.capacity = initialCapacity;
	vec.size = 0;
	return vec;
}

void addElement(vector* vec, int value)
{
	// reallocate every 5 elements
	if (vec->size == vec->capacity)
	{
		vec->capacity += 5;
		vec->data = realloc(vec->data, sizeof(int) * vec->capacity); 
	}

	*(vec->data + vec->size) = value;
	vec->size++;
}

void removeElement(vector* vec, int index)
{
	if (index >= vec->size || index < 0) return; // OOB
	else
	{
		memmove(vec->data + index, vec->data + index + 1, sizeof(int) * (vec->size - index - 1));
	}
	vec->size--;
}

void resize(vector* vec, int value)
{
	vec->capacity = value;
	vec->size = (vec->size > vec->capacity) ? vec->capacity : vec->size;
}

int element(vector* vec, int index) { return (index >= vec->size) ? -1 : *(vec->data + index); }

void freeVector(vector* vec)
{
	if (vec->data != NULL)
	{
		free(vec->data);
		vec->data = NULL;
	}
	vec->size = 0;
	vec->capacity = 0;
}

// Linked List (non-contiguous, can contain multiple data types))

typedef struct ListNode
{
	void* m_data;
	struct ListNode* next;
	size_t dataSize;
} ListNode;

ListNode* newList(void* data, size_t elementSize)
{
	ListNode* top = malloc(sizeof(ListNode));
	top->next = NULL;
	top->m_data = data;
	top->dataSize = elementSize;
	return top;
}

ListNode* newNode(ListNode* cur, void* data, size_t elementSize)
{
	cur->next = malloc(sizeof(ListNode));
	cur = cur->next;
	cur->m_data = data;
	cur->dataSize = elementSize;
	cur->next = NULL;
	return cur;
}

void freeList(ListNode* head)
{
	ListNode* cur = head;
	ListNode* temp = head;
	while (cur != NULL)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
}

// Binary Search Tree (To do: pseudo-templatize)

typedef struct TreeNode
{
	int value;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

TreeNode* newTree(int val)
{
	TreeNode* head = malloc(sizeof(TreeNode));
	head->value = val;
	head->left = NULL;
	head->right = NULL;
}

void insert(TreeNode* head, int val)
{
	TreeNode* newNode = malloc(sizeof(int));
	while (head != NULL)
	{
		if (val > head->value)
		{
			if (head->right != NULL) head = head->right;
			else (head->right) = newTree(val);
		}
		else if (val < head->value)
		{
			if (head->left != NULL) head = head->left;
			else (head->left) = newTree(val);
		}
		else return;
	}
	return;
}

void preorderTraversal(TreeNode* head)
{
	if (head == NULL) return;
	printf("%d\n", head->value);
	preorderTraversal(head->left);
	preorderTraversal(head->right);
}

void inorderTraversal(TreeNode* head)
{
	if (head == NULL) return;
	inorderTraversal(head->left);
	printf("%d\n", head->value);
	inorderTraversal(head->right);
}

void postorderTraversal(TreeNode* head)
{
	if (head == NULL) return;
	postorderTraversal(head->left);
	postorderTraversal(head->right);
	printf("%d\n", head->value);
}

void freeTree(TreeNode* head)
{
	if (head == NULL) return;
	freeTree(head->left);
	freeTree(head->right);
	free(head);
}

// To do: hash map/set, stack, queue, priority queue, heap, max heap





