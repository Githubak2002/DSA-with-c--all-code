// Doubly LL - Deletion remaning
// with no implimentation of tail/end node

#include <iostream>
#include <math.h>
using namespace std;

class node
{
public:
    int data;
    node *next, *prev;

    // constructor
    node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~node()
    {
        int value = this->data;
        cout << "Memory is free for node with data = " << value << endl;
        // if (this->next != NULL)
        // {
        //     delete next;
        //     this->next = NULL;
        // }
    }
};

// INSERTION
void printDll(node *head)
{
    if (head == NULL)
        cout << "Linked list is empty\n";
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}
// Length
void lengthDll(node *&head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    cout << "Length of DLL = " << len << endl;
}

// INSERTION
void insertAtBeg(int newdata, node *&head)
{
    node *newNode = new node(newdata);
    if (head == NULL)
        head = newNode;
    else
    {
        // cout<<"Inserting "<<newdata<<" at the start\n";
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(int newdata, node *&head)
{
    node *newNode = new node(newdata);
    if (head == NULL)
        head = newNode;
    else
    {
        // cout<<"Inserting "<<newdata<<" at the end\n";
        node *tailNode = head;
        while (tailNode->next != NULL)
            tailNode = tailNode->next;
        tailNode->next = newNode;
        newNode->prev = tailNode;
    }
}

void insertAtPosition(int newdata, node *&head, int position)
{
    if (position == 1)
    {
        insertAtBeg(newdata, head);
        return;
    }
    node *newNode = new node(newdata);
    node *temp = head;
    int initialpos = 1;
    while (initialpos < position - 1)
    {
        initialpos++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        insertAtEnd(newdata, head);
        return;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// DELETION
void deleteHead(node *&head)
{
    if (head == NULL)
        return;
    else
    {
        node *nxt = head->next;
        delete head;
        if (nxt != NULL)
            nxt->prev = NULL;
        head = nxt;
    }
}

void deleteEnd(node *head)
{
    if (head == NULL)
        return;
    else
    {
        node *last = head, *pre = head;
        while (last->next != NULL)
        {
            pre = last;
            last = last->next;
        }
        pre->next = NULL;
        delete last;
    }
}

// ⚠️ ERROR IN THE BELOW CODE ⚠️
void deletePos(node *head, int pos)
{
    if (pos == 1)
    {
        deleteHead(head);
        return;
    }
    node *curr = head;
    node *pre;
    node *nxt;
    while (pos - 1 > 1)
    {
        curr = curr->next;
        pos--;
    }
    pre = curr->prev;
    nxt = curr->next;

    pre->next = nxt;
    nxt->prev = pre;
    delete curr;
}

/*
// DELETION
void deletePos(int position, node* &head){
    node* currNode = head;
    node* prevNode;
    if(position == 1){
        head = head->next;
        currNode->next = NULL;
        delete currNode;
        return;
    }
    int pos = 1;
    while(pos < position){
        prevNode = currNode;
        currNode = currNode->next;
        pos++;
    }
    if(currNode->next == NULL)
        prevNode->next = NULL;
    else
        prevNode->next = currNode->next;
    currNode->next = NULL;
    delete currNode;
}
*/

int main()
{
    cout << "==============================\n\n";

    node *head = new node(3);
    insertAtBeg(2, head);
    insertAtBeg(1, head);
    insertAtEnd(4, head);
    printDll(head);
    lengthDll(head);
    // lengthDll(head);

    cout << "\nInserting 5 at 5\n";
    insertAtPosition(5, head, 5);
    printDll(head);

    // deleteHead(head);
    // printDll(head);

    // deleteEnd(head);
    // printDll(head);

    deletePos(head, 1);
    printDll(head);

    /*
    cout << "\nDeleting node at 3\n";
    deletePos(3, head);
    printLL(head);
    */

    cout << "\n\n==============================";
    return 0;
}
