#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct Node
{
	int value;
	struct Node* next;
}Node;


Node* LinkedList_Init(int value)
{
	Node* new_node = NULL;

	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		//malloc fails to allocate memory
		return NULL;
	}

	new_node->value = value;
	new_node->next = NULL;

	return new_node;
}

Node* LinkedList_AddNodeToTail(Node* head, int value)
{
	Node* curr_node;
	Node* new_node;
	
	//head is not initialized
	if (head == NULL)
	{
		//linked list is not init;
		return head = LinkedList_Init(value);
	}

	curr_node = head;

	//iterate til end of the list
	while (curr_node->next != NULL)
	{
		curr_node = curr_node->next;
	}

	//allocate memory for new node
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		//malloc failed
		return new_node;
	}

	//passing data to the node
	new_node->next = NULL;
	new_node->value = value;
	curr_node->next = new_node;

	return head;
}

Node* LinkedList_AddNodeToHead(Node* head, int value)
{
	Node* curr_node;
	Node* new_node;

	if (head == NULL)
	{
		//empty head, init it
		head = LinkedList_Init(value);
		return head;
	}

	curr_node = head;

	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		//malloc failed
		return new_node;
	}

	new_node->value = value;
	new_node->next = curr_node;

	return new_node;
}

Node* LinkedList_AddNodeAtIndex(Node* head, int index, int value)
{
	Node* curr_node;
	Node* next;
	Node* new_node;

	assert(index > -1);

	if (head == NULL)
	{
		//list is empty, create node
		return NULL;
	}

	curr_node = head;
	next = curr_node->next;

	if (next == NULL && index != 0)
	{
		//have only one node and index is not the fisrt node
		// return NULL, aka error
		return NULL;
	}

	if (index == 0)
	{
		//add node to head
		return LinkedList_AddNodeToHead(head, value);
	}

	while (--index)
	{
		//advance one node
		curr_node = next;
		next = curr_node->next;
		if (curr_node->next == NULL)
		{
			//we reach end of the node. Means index is larger than linked list size
			//return NULL = error
			return NULL;
		}
	}

	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		//malloc fail
		return NULL;
	}
	new_node->value = value;
	new_node->next = next;
	curr_node->next = new_node;

	return head;
}


Node* LinkedList_DeleteTail(Node* head)
{
	Node* curr_node;
	Node* next;
	
	
	if (head == NULL)
	{
		//head is empty, nothing to be done here
		return NULL;
	}

	curr_node = head;
	next = curr_node->next;

	if (next == NULL)
	{
		//one element, head = tail
		free(curr_node);
		return NULL;
	}

	while ( next->next != NULL)
	{
		curr_node = next;
		next = curr_node->next;
	}

	free(next);
	curr_node->next = NULL;

	return head;
}

Node* LinkedList_DeleteHead(Node* head)
{
	Node* curr_node;
	

	if (head == NULL)
	{
		//head is empty, nothing to be done here
		return NULL;
	}

	curr_node = head->next;
	free(head);

	return curr_node;

}

Node* LinkedList_DeleteAtIndex(Node* head, int index)
{
	Node* curr_node;
	Node* next;
	
	assert(index > -1);

	


	if (head == NULL)
	{
		//list is empty, nothing to delete;
		return NULL;
	}

	curr_node = head;
	next = curr_node->next;

	if (next == NULL && index != 0)
	{
		//have one node and index is not the fisrt node
		return NULL;
	}

	if (index == 0)
	{
		return LinkedList_DeleteHead(head);
	}

	while (--index)
	{
		//advance one node
		curr_node = next;
		next = curr_node->next;
		if (curr_node->next == NULL)
		{
			//we reach end of the node. Means index is larger than linked list size
			return NULL;
		}
	}

	curr_node->next = next->next;
	free(next);

	return head;
}



void LinkedList_Print(Node*head)
{
	Node* curr_node;
	curr_node = head;
	
	while (curr_node != NULL)
	{
		printf("%d -> ", curr_node->value);
		curr_node = curr_node->next;
	}
	printf("\n");
}

int main(void)
{
	Node* head;
	
	printf("Linked List test\n");

	head = LinkedList_Init(0);
	for (int i = 1; i < 10; i++)
	{
		head = LinkedList_AddNodeToTail(head, i);
	}

	LinkedList_Print(head);

	head = LinkedList_AddNodeToHead(head, -1);
	head = LinkedList_AddNodeToHead(head, -2);
	LinkedList_Print(head);

	head = LinkedList_DeleteHead(head);
	head = LinkedList_DeleteHead(head);
	LinkedList_Print(head);

	head = LinkedList_DeleteTail(head);
	head = LinkedList_DeleteTail(head);
	LinkedList_Print(head);

	head = LinkedList_DeleteAtIndex(head, 7);
	LinkedList_Print(head);
	head = LinkedList_DeleteAtIndex(head, 3);
	LinkedList_Print(head);
	head = LinkedList_DeleteAtIndex(head, 4);
	LinkedList_Print(head);
	head = LinkedList_DeleteAtIndex(head, 0);
	LinkedList_Print(head);

	head = LinkedList_AddNodeAtIndex(head, 0, 100);
	LinkedList_Print(head);

	head = LinkedList_AddNodeAtIndex(head, 2, 101);
	LinkedList_Print(head);

	head = LinkedList_AddNodeAtIndex(head, 3, 102);
	LinkedList_Print(head);

	return 0;
}