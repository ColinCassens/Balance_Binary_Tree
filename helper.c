#include "main.h"

//METHOD: DETERMINE IF THERE ARE RIGHT AND LEFT NODES THE HEIGHT OF THIS NODE IS MAX(left|right)+1
void update_height(Node * head)
{
	if(head->rightChild != NULL)
	{
		if(head->leftChild == NULL || head->rightChild->height > head->leftChild->height)
		{
				head->height = 1 + head->rightChild->height;
		}
		else
		{
			head->height = 1 + head->leftChild->height;
		}
	}
	else if(head->leftChild != NULL)
	{
		head->height = 1 + head->leftChild->height;
	}
	else
	{
		head->height = 0;
	}
}

//UPDATE THE BALANCE OF THE NODE
void update_balance(Node * head)
{
	if(head->rightChild != NULL)
	{
		if(head->leftChild == NULL)
		{
			head->bal = -1 - head->rightChild->height;
		}
		else
		{
			head->bal = head->leftChild->height - head->rightChild->height;
		}
	}
	else if (head->leftChild != NULL)
	{
		if(head->rightChild == NULL)
		{
			head->bal = head->leftChild->height - (-1);
		}
		else
		{
			head->bal = head->leftChild->height - head->rightChild->height;
		}
	}
	else
	{
		head->bal = 0;
	}
}

//Rotate the node HEAD to the left
Node * rotate_left(Node * head)
{
	Node * newRoot = head->rightChild;
	head->rightChild = newRoot->leftChild;
	newRoot->leftChild = head;
	head = newRoot;
	update_all(head);
	return head;
}

//Rotate the node HEAD to the right
Node * rotate_right(Node * head)
{
	Node * newRoot = head->leftChild;
	head->leftChild = newRoot->rightChild;
	newRoot->rightChild = head;
	head = newRoot;
	update_all(head);
	return head;
}

void update_all(Node * head)
{
	if(head->leftChild != NULL)
	{
		update_all(head->leftChild);
	}
	if(head->rightChild != NULL)
	{
		update_all(head->rightChild);
	}
	update_height(head);
	update_balance(head);
}

//Find the immediate predecessor
Node * find_pred(Node * head)
{
	Node * temp = head;
	while(head->rightChild != NULL)
	{
		temp = head;
		head = head->rightChild;
	}
	if(head->rightChild == NULL)
	{
		temp->rightChild = NULL;
		if(head->leftChild != NULL)
		{
			temp->rightChild = head->leftChild;
			head->leftChild = NULL;
		}
	}
	update_height(temp);
	update_height(head);
	update_balance(temp);
	update_balance(head);

	//Rotate Right
  	if(temp->bal == 2)
  	{
    	temp = rotate_right(temp);
  	}
  	//Rotate Left
  	else if(temp->bal == -2)
  	{
    	temp = rotate_left(temp);
  	}

	return head;
}

void printTreeFile(Node * head, FILE * outfile)
{
	int num = 0;
	if(head->rightChild != NULL && head->leftChild != NULL)
	{
		num = 3;
	}
	if(head->rightChild == NULL && head->leftChild != NULL)
	{
		num = 2;
	}
	if(head->rightChild != NULL && head->leftChild == NULL)
	{
		num = 1;
	}
	fprintf(outfile, "%i %i\n", head->key, num);
	
	if(head->leftChild != NULL)
	{
		printTreeFile(head->leftChild, outfile);
	}
	if(head->rightChild != NULL)
	{
		printTreeFile(head->rightChild, outfile);
	}

}