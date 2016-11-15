#include <iostream>

//Nodes and lists use public data members for convenience
//This may make some software engineers froth at the mouth

class Node
{
public:
  int value;
  //class node with 2 pointers, towards the previous and the next node
  Node* next;
  Node* prev;

  Node(int val)
  {
    //in the constructor we set the pointers(next and prev) to NULL
    this->value=val;
    this->next=(Node*)NULL;
    this->prev=(Node*)NULL;
  }

};
class List
{

public:
  Node* head;
  Node* tail;

  List()
  {
    //in the constructor of the list we set the head  and the tail to NULL(list empty)
    this->head=NULL;
    this->tail=NULL;
  }

  void insert(Node* n, Node* x)
  {
    if (n!=0)
    {
      //if we don't insert at the begging of the list
      x->next=n->next;
      //the next pointer of x takes the value of the 'next' pointer of the node that you insert after
      n->next=x;
      //the 'next' pointer of the node that you insert after points now towards x
      x->prev=n;
      //the 'prev' pointer of x now points towards the node that you insert after
      if (x->next!=NULL)
        //if the 'next' pointer of x is not NULL - if x is not the last element in the list
        x->next->prev=x;
        //the 'prev' pointer of node that the 'next' pointer of x points towards , now points towards x;
    }
    else if((n==0)&&(this->head!=NULL))
    {
      //if we insert at the begging of the list and the list is not empty
      x->next=this->head;
      //the 'next' pointer of x points towards the node that used to be the head(the first element)
      this->head->prev=x;
      //the 'prev' pointer of the node that used to be the head points towards x
      x->prev=NULL;
      // and the 'prev' pointer of x points towards NULL
      this->head=x;
    }
    if (this->head==NULL)
    {
      //the list is empty
      this->head=x;
      this->tail=x;
      x->prev=NULL;
      x->next=NULL;
      //the head and tail point towards x
      // and the 'next' and 'prev' pointer point towards 0
    }
    else if (this->tail==n)
    {
      //if we insert at the end of the list
      this->tail=x;
      //the tail points towards x
    }
  }

  void remove(int x)
  {
        Node* current=this->head;
        while(current!=NULL)
        {
            //we have a current node that goes from the first to the last element
            if(current->value==x)
            {
                std::cout<<"The node with the value "<<x<<" was deleted"<<std::endl;
                //if we found the wanted value we change the pointers that points to it and from it
                if(current->prev!=NULL)
                    current->prev->next=current->next;
                else
                    this->head=current->next;
                if(current->next!=NULL)
                    current->next->prev=current->prev;
                else
                    this->tail=current->prev;
                //we empty the memory location
                delete current;
                //we exit de while loop because we found the element
                break;
            }
            current=current->next;
        }
  }

  void display()
  {
    Node* i=this->head;
    std::cout << "List: " ;
    while(i!=NULL)
    {
      std::cout << i->value << ",";
      i=i->next;
    }
    std::cout << std::endl;
  }
};

int main(int argc, char *argv[])
{
  List* l=new List();
  //Node* addres=new Node(10);
  l->insert(0,new Node(8));
  l->insert(l->head,new Node(4));
  //l->insert(0,addres);
  l->insert(0,new Node(6));
  l->insert(l->head,new Node(8));
  l->display();
  l->remove(8);
  l->display();
  delete l;

  return 0;
}
