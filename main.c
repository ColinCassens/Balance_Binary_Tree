#include "main.h"

int main(int argc, char**argv)
{
  char * b = "-b";
  char * e = "-e";
  char * input1 = argv[1];

  if(strcmp(input1,b) == 0)
  {
    //CHECK FOR VALID NUMBER OF INPUTS
    if(argc != 4)
    {
      return EXIT_FAILURE;
    }

    FILE * infile = fopen(argv[2],"rb");
    if(infile == NULL)
    {
      int fail = -1;
      printf("%d\n",fail);
      return EXIT_FAILURE;
    }

    //Read the input file and build the balanced tree
    Node * head = malloc(sizeof(Node));
    build_balanced_tree(head, infile);
  }
  else if(strcmp(input1,e) == 0)
  {
    //Check for valid number of inputs

    //Read the input file and determine if the tree is balanced


  }
  return EXIT_SUCCESS;
}


//BUILD BALANCED TREE
//READS IN TREE DATA AND ADDS OR DELETES TO THE TREE
//THEN RE BALANCES THE TREE
void build_balanced_tree(Node * head, FILE * infile)
{
  int key;
  char operation;
  
  //GET THE HEAD VALUES
  fread(&key,sizeof(int),1,infile);
  fread(&operation,sizeof(char),1,infile);
  head->key = key;
  head->bal = 0;
  head->height = 0;
  
  //READ THE INPUT FILE
  while(fread(&key,sizeof(int),1,infile) != 0)
  {
    fread(&operation,sizeof(char),1,infile);

    //INSERT NEW NODE
    if(operation == 'i')
    {
      Node * temp = malloc(sizeof(Node));
      temp->key = key;
      //INSERT THE NEW NODE WORKING
      head = insert_node(head, temp);
    }

    //DELETE NODE
    else if(operation == 'd')
    {
      //REMOVE THE NODE

    }

  }
  return;
}



//INSERTS A NEW NODE INTO THE TREE IN THE CORRECT LOCATION
Node * insert_node(Node * head, Node * newNode)
{
  if(newNode->key > head->key)
  {
    if(head->rightChild != NULL)
    {
      head->rightChild = insert_node(head->rightChild, newNode);
    }
    else
    {
      head->rightChild = newNode;
    }
    //Update the height and balance of the node
    update_height(head);
    update_balance(head);
  }
  else if(newNode->key <= head->key)
  {
    if(head->leftChild != NULL)
    {
      head->leftChild = insert_node(head->leftChild, newNode);
    }
    else
    {
      head->leftChild = newNode;
    }
    //Update the height and balance of the node
    update_height(head);
    update_balance(head);
  }

  //Rotate Right
  if(head->bal == 2)
  {
    head = rotate_right(head);
  }
  //Rotate Left
  else if(head->bal == -2)
  {
    head = rotate_left(head);
  }
  return head;
}