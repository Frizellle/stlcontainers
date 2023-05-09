#include <stdio.h>
#include "containers.h"

int killKthBit(int n, int k);
void vectorDemo();
void linkedListDemo();
void bstDemo();

int main()
{
	printf("%d\n", killKthBit(37, 3));
	vectorDemo();
	linkedListDemo();
	bstDemo();
}

int killKthBit(int n, int k)
{
	printf("Removing %dth bit from %d-> ", k, n);
	int comp = 1;
	comp = comp << (k - 1);
	return (n ^ comp);
}

void vectorDemo()
{
	printf("Vector Demo (add 0-4, remove 3)\n");
	vector numberLine = createVector(5);
	for (int i = 0; i < numberLine.capacity; i++)
	{
		addElement(&numberLine, i);
		printf("%d\n", *(numberLine.data + i));
	}
	printf("%d\n", *(numberLine.data + 3));
	removeElement(&numberLine, 3);
	printf("%d\n", *(numberLine.data + 3));

	freeVector(&numberLine);
}

void linkedListDemo()
{
	printf("Linked List Demo (add 0-5, iterate)\n");
	ListNode* head = newList(0, sizeof(int));
	ListNode* cur = head;
	for (int i = 1; i <= 5; i++)
	{
		cur = newNode(cur, i, sizeof(int));
	}
	cur = head;

	while (cur != NULL)
	{
		printf("%d\n", cur->m_data);
		cur = cur->next;
	}

	freeList(head);
}

void bstDemo()
{
	printf("BST Demo (insert numbers in the range 0-25, print in order (other orders available))\n");
	TreeNode* head = newTree(13);
	for (int i = 1; i < 11; i++)
	{
		insert(head, (111 * i) % 25);
	}
	inorderTraversal(head);
}