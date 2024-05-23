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
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory if free for node with data = " << value << endl;
    }
};

// INSERTION 
void printDll(node *head)
{
    if(head == NULL)
        cout<<"Linked list is empty\n";
    else
    {
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    }
}

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

void insertAtBeg(int newdata, node *&head)
{
    node *newNode = new node(newdata);
    if(head == NULL)
        head = newNode;
    else{
    // cout<<"Inserting "<<newdata<<" at the start\n";
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    }
}

void insertAtEnd(int newdata, node *&head)
{
    node *newNode = new node(newdata);
    if(head == NULL)
        head = newNode;
    else{
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
    if(temp->next == NULL){
        insertAtEnd(newdata,head);
        return;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
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
    cout << "\n\n";

    node *head = new node(30);
    lengthDll(head);
    insertAtBeg(20, head);
    insertAtBeg(10, head);
    insertAtEnd(40, head);
    printDll(head);
    // lengthDll(head);

    cout << "\nInserting 99 at 5\n";
    insertAtPosition(99, head, 5);
    printDll(head);

    /*
    cout << "\nDeleting node at 3\n";
    deletePos(3, head);
    printLL(head);
    */

    cout << "\n\n";
    return 0;
}
