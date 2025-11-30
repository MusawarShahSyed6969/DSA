#include <iostream>
using namespace std;

class Node{
  public:
    int value;
    Node* next;
    
    Node(int value)
    {
      this->value = value;
      next = nullptr;
    }
};

class LinkedList{
  public:
    Node* head;
    Node* tail;
    int length;
    
    LinkedList(int val)
    {
      Node* newnode = new Node(val);
      head = newnode;
      tail = newnode;
      length = 1;
    }
    
   void print()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    void reverse()
    {
      Node* temp = head;
      head = tail;
      tail = temp;
      Node* after = temp->next;
      Node* before = nullptr;
      
      for(int i = 0; i < length; i++)
      {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
      }
      
    }
    
    void append(int val)
    {
      Node* newnode = new Node(val);
      if(length == 0)
      {
        head = newnode;
        tail = newnode;
        return;
      }else
      {
        tail->next = newnode;
        tail = newnode;
        length++;
      }
    }
    
    Node* get(int index)
    {
      if(index < 0 || index >= length) return nullptr;
      
      Node* temp = head;
      for (int i = 0; i < index ; i++) {
        temp = temp->next;
      }
      return temp;
    }
    
    bool set(int index,int val)
    {
      Node* node = get(index);
      
      if(length == 0)
        return false;
      if(node != nullptr)
      {
        node->value = val;
        return true;
      }
      return false;
    }
    
    void deleteFirst()
  {
    if(length == 0) return;
    
     Node* temp = head;
    if(length == 1)
    {
      head = nullptr;
      tail == nullptr;
    }
    else
    {
     head = head->next;
    }
    
    delete temp;
    length--;
  }
  
  
  void deleteLast()
{
  if(length == 0) return;
   Node* temp = head;
   
   if(length == 1)
   {
     head = nullptr;
     tail = nullptr;
   }
   else
  {
    tail->next = nullptr;
     Node* t = tail; 
     Node* pre = get(length - 1);
     pre->next = pre;
     tail = pre;
     delete t;
     length--;
  }
}


void findMiddleNode()
{
  if(!head) return;
  
  Node* slow = head;
  Node* fast = head;
  
  while(fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
}


void removeSortedDuplicate()
{
  Node* curr = head;
  
  
  while(curr->next)
  {
    if(curr->value == curr->next->value)
    {
      Node* dup = curr->next;
      curr->next = curr->next->next;
      delete dup;
    }else{
      curr = curr->next;
    }
  }
}

bool hasLoop()
{
  if(!head) return false;
  
  Node* slow = head;
  Node* fast = head;
  
  while(fast != nullptr && fast->next)
  {

    fast = fast->next->next;;
    slow = slow->next;
    
    if(slow == fast)
    {
      return true;
    }
    
  }
  
  return false;
}

};


int main() 
{
  LinkedList* l1 = new LinkedList(1);
  l1->append(2);
  l1->append(3);
  l1->append(4);
  l1->append(5);

  
  l1->print();
  // l1->hasLoop();
  
  cout << l1->hasLoop() <<endl;

  

  
  
    // cout << "Hello, World!";
    return 0;
}