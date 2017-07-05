// http://stackoverflow.com/questions/19194224/adding-node-to-the-front-of-a-linked-list

#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *link;
};
class LinkList
{
    Node *headptr;
public:
    LinkList()
    {
        headptr=NULL;
    }

    void InsertatFirst(int val)
    {
        Node *newNode;
        newNode = new Node;
        newNode ->link =NULL;
        newNode ->data = val;
        newNode ->link=headptr;
        headptr = newNode;
    }

    void Display()
    {
        Node *disNode;
        disNode = headptr;
        while(disNode !=NULL)
        {
            cout<<"Display Node Value is "<<disNode ->data<<endl<<endl;
            disNode =  disNode->link;
        }
    }

};
int main()
{
    LinkList lobj;
    lobj.InsertatFirst(45);
    lobj.InsertatFirst(2);
    lobj.InsertatFirst(1);
    lobj.InsertatFirst(0);
    lobj.InsertatFirst(-1);
    lobj.Display();

	return 0;
}


