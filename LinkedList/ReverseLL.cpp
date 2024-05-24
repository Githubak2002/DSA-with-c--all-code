// Reverse Linked list and doubley linked list



#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node()
  {
  }

  Node(int x)
  {
    data = x;
    next = nullptr;
  }
};

void traverse(Node *head)
{
  cout << "Element in linked list are - \n";
  Node *tmp = new Node();
  tmp = head;
  while (tmp->next != NULL)
  {
    cout << tmp->data << " -> ";
    tmp = tmp->next;
  }
  cout << tmp->data << " -> null" << endl;
}

void insertHead(Node *&head, int data)
{
  Node *newNode = new Node(data);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  newNode->next = head;
  head = newNode;
}

void insertEnd(Node *&head, int data)
{
  Node *tmp = head;
  Node *newNode = new Node(data);
  // if No head
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = newNode;
}

void insertAtPos(Node *head, int data, int pos)
{
  if (pos == 1)
  {
    insertHead(head, data);
    return;
  }
  Node *newNode = new Node(data);
  Node *curr = head;
  Node *tmp = NULL;
  while (pos - 1 > 1)
  {
    curr = curr->next;
    pos--;
  }
  tmp = curr->next;
  curr->next = newNode;
  newNode->next = tmp;
}

Node *deleteHead(Node *head)
{
  if (head == NULL)
    return head;
  Node *tmp = head->next;
  delete head;
  return tmp;
}

Node *deleteEnd(Node *head)
{
  if (head == NULL)
    return NULL;
  if (head->next == NULL)
  {
    delete head;
    return NULL;
  }
  Node *tmp = head;
  Node *prev = tmp;
  while (tmp->next != NULL)
  {
    prev = tmp;
    tmp = tmp->next;
  }
  delete tmp;
  prev->next = NULL;
  return head;
}

Node *deletePos(Node *head, int pos)
{
  if (pos == 1)
  {
    head = deleteHead(head);
    return head;
  }
  Node *curr = head;
  Node *prev = curr;
  Node *nxt;
  while (pos - 1 > 0)
  {
    prev = curr;
    curr = curr->next;
    pos--;
  }
  nxt = curr->next;
  delete curr;
  prev->next = nxt;
  return head;
}

void reverseLl(Node *&head)
{
  if(head == NULL || head->next == NULL)
    return;
  Node *pre = NULL,*curr = head,*nxt = head->next;
  while(curr != NULL){
    curr->next = pre;
    pre = curr;
    curr = nxt;
    if (nxt != NULL) 
      nxt = nxt->next;
  }
  head = pre;
}

int main()
{
  cout << "======================\n\n";
  Node *head = NULL;

  insertHead(head, 1);
  insertEnd(head, 2);
  insertEnd(head, 3);
  insertEnd(head, 4);
  traverse(head);

  insertAtPos(head, 5, 5);
  traverse(head);

  // head = deleteHead(head);
  // head = deleteEnd(head);
  head = deletePos(head, 5);
  traverse(head);


  cout<<"\nreverse linked list:\n";
  reverseLl(head);
  traverse(head);

  cout << "\n\n=======================";
  return 0;
}