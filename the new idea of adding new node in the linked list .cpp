#include <iostream>
using namespace std;

struct Node
{
    float data;
    Node* next;
};

int main()
{
    Node* Head, * NewNode, * ptr;
    Head = new Node;
    Head->data = 25.2;
    Head->next = NULL;



    NewNode = new Node;
    NewNode->data = 100.11;
    NewNode->next = NULL;

    Head->next = NewNode;

    ptr = Head;
    while (ptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }

    // from here i depended on the pointer of the last node to create a new node instead of depending on new pointer decleared in the stack memory ::::
    NewNode->next = new Node;
    (NewNode->next)->data = 999.11;
    (NewNode->next)->next = NULL;

    cout << "*************************************\n";
    ptr = Head;
    while (ptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }


}
