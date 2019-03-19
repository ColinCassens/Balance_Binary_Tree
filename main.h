#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stddef.h>
#include <stdarg.h>
#include "main.h"

typedef struct _Node{
  struct _Node * rightChild;
  struct _Node * leftChild;
  int key;
  int bal;
  int height;
} Node;

int main(int argc, char ** argv);
void build_balanced_tree(Node * head, FILE * infile);
Node * insert_node(Node * head, Node * newNode);
void update_height(Node * head);
void update_balance(Node * head);
Node * rotate_left(Node * head);
Node * rotate_right(Node * head);
void update_all(Node * head);


#endif
