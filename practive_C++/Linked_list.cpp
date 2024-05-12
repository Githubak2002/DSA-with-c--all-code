// BASICS of LINKED LIST - Single linked list
// NOTE - no implimentation of tail and what if the head == NULL

#include <iostream>
#include <math.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory if free for node with data = "<<value<<endl;
    }

};

void printLL(node *head){  
    node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << "->"<< "NULL" << endl;
}

// INSERTION 
void insertAtEnd(int newdata, node *&head){
    node *newNode = new node(newdata);
    node *tailNode = head;
    while (tailNode->next != NULL)
        tailNode = tailNode->next;
    cout << "\nTail node data " << tailNode->data << endl;
    tailNode->next = newNode;
}

void insertAtBeg(int newdata, node *&head){
    node *temp = new node(newdata);
    temp->next = head;
    head = temp;
}

void insertAtPosition(int newdata, node *&head, int position){
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
    newNode->next = temp->next;
    temp->next = newNode;
}


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

int main()
{
    cout << "\n\n";

    node *head = new node(30);
    insertAtBeg(20, head);
    insertAtBeg(10, head);
    insertAtEnd(40, head);
    printLL(head);

    cout << "\nInserting 99 at 3\n";
    insertAtPosition(99, head, 3);
    printLL(head);

    cout << "\nDeleting node at 3\n";
    deletePos(3, head);
    printLL(head);

    cout << "\n\n";
    return 0;
}
