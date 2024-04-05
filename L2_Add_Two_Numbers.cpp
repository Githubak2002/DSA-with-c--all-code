// L2 Add Two Numbers - 100% correct 

#include <iostream>
#include <math.h>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLL(ListNode *head)
{
  if(head == NULL){
    cout<<"LL is empty"<<endl;
    return;
  }
  ListNode *temp;
  temp = head;
  while (temp->next != NULL)
  {
    cout << temp->val << "->";
    temp = temp->next;
  }
  cout << temp->val << "->"
       << "NULL" << endl;
}

void addAtEnd(ListNode *&head, int newData)
{
  ListNode *newNode = new ListNode(newData);
  if (head == nullptr)
  {
    head = newNode;
    return;
  }
  ListNode *current = head;
  while (current->next != nullptr)
  {
    current = current->next;
  }
  current->next = newNode;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  ListNode *result = nullptr;
  int sum=0,rem=0,carry = 0;
  while(l1 != NULL && l2 != NULL ){
    sum = 0;  rem = 0;
    sum = l1->val + l2->val + carry;
    if(sum%10 != sum){
      rem = sum%10;
      carry = 1;
      addAtEnd(result,rem);
    }
    else{
      carry = 0;
      addAtEnd(result,sum);
    }
    l1 = l1->next;
    l2 = l2->next;
  }

  while(l1 != NULL){
    // if(carry == 1)
    sum = carry+l1->val;

    if(sum%10 != sum){
      rem = sum%10;
      carry = 1;
      addAtEnd(result,rem);
    }
    else{
      carry = 0;
      addAtEnd(result,sum);
    }
    l1 = l1->next;
  }

  while(l2 != NULL){
    // if(carry == 1)
    sum = carry+l2->val;

    if(sum%10 != sum){
      rem = sum%10;
      carry = 1;
      addAtEnd(result,rem);
    }
    else{
      carry = 0;
      addAtEnd(result,sum);
    }
    l2 = l2->next;
  }

  if(carry == 1)
    addAtEnd(result,1);

  return result;
}

int main()
{
  cout << "\n\n";

  // ListNode *head = new ListNode;
  ListNode *n1 = nullptr;
  ListNode *n2 = nullptr;
  ListNode *result;

  addAtEnd(n1,1);
  addAtEnd(n1,8);
  addAtEnd(n2,0);

  /*
  addAtEnd(n1,9);
  addAtEnd(n1,9);
  addAtEnd(n1,9);
  addAtEnd(n1,9);

  addAtEnd(n2,9);
  addAtEnd(n2,9);
  addAtEnd(n2,9);
  addAtEnd(n2,9);
  addAtEnd(n2,9);
  addAtEnd(n2,9);
  */
  
  cout << "First ll" << endl;
  printLL(n1);
  cout << "Second ll" << endl;
  printLL(n2);

  result = addTwoNumbers(n1,n2);
  cout<<"result ll "<<endl;
  printLL(result);

  cout << "\n\n";
  return 0;
}
