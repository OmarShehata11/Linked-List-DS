#include <iostream>
using namespace std;

// Here we defined the struct of every node in the linked list
struct ListNode
{
    float Data;
    ListNode* next;  // this is the pointer that point to the next node , because it pointing to a node which it's data type is a struct ; so it's data type must also be a struct .

};

// this is the function that will add anew node to the linked list
void AddNode(ListNode*& Head, float data)
{
    ListNode* NewNode, * Nodeptr;

    //add the new node
    NewNode = new ListNode;
    NewNode->Data = data;
    NewNode->next = NULL;

    /* put the node in the end
    **************************************
         1)condition one: that there is no nodes in the whole linked list , so we have no choice other adding the new node after the header ,
         and this node will be the first ; then we add this statement ::
    */
    if (Head == NULL)
        Head = NewNode;

    // second condition : that there is nodes in the linked list ; so we have to go to the last node then add the new node at the end of the linked list ::
    else
    {
        Nodeptr = Head;
        while (Nodeptr->next != NULL)
        {
            Nodeptr = Nodeptr->next;
        }
        Nodeptr->next = NewNode;
    }


}

// this function is showing all the data in the nodes in the linked list ::
void ShowNodes(ListNode* Head)
{
    ListNode* Nodeptr;
    int counter = 1; // this variable is just to count how many nodes in the linked list
    Nodeptr = Head;

    /*
      in this state too , we have two conditions ,,
      the first : that there is no nodes in the whole linked list ; so there is no data to be shown ::

    */
    if (Head == NULL)
        cout << " there is no data in the linked list \n";
    /*
 -  and the second : is there is nodes in the liked list , so we have to move from the Header then the first node then the second and so on ;
    and in every node u reach ; show the data in it by using the pointer  ::::
   */
    else
        while (Nodeptr != NULL)
        {
            cout << "the data for the node number " << counter << " is ==>  " << Nodeptr->Data << endl;
            counter++;
            Nodeptr = Nodeptr->next;
        }

    cout << "---------------------------------------------------------------------\n";
}

//this function adding new node in the linked list but in a special number  :::
void AddNodeInNum(ListNode*& Header, int num, float data)
{
    ListNode* NewNode, * Newptr;
    bool check = true; // this var is just checking if the number the user entered is valid in the liked list

    NewNode = new ListNode;
    NewNode->Data = data;

    /*

    here we have three conditions :
    1) that the user want to add the node at the first of the linked list
    2) that the user want to add the node at any order in the linked list
    3) that the user want to add the node but in wrong order in the linked list

    so we have to check every condition to know what the user want ::::

    */

    // checking if the user want to add the node at the first
    if (num == 1 || num == 0)
    {
        NewNode->next = Header;
        Header = NewNode;
    }

    // if he want to add the node in a special number or a special order ::::
    else
    {
        Newptr = Header;
        for (int i = 0; i < (num - 2); i++)
        {
            Newptr = Newptr->next;

            // here i will check if the order the user entered is valid in the linked list ::
            if (Newptr == NULL)
            {
                cout << "*******************\n there is no node has the number " << num << " in the linked list to be added in  !! \n*******************" << endl;
                check = false;
                break;
            }
        }

        // just to check that also the number is valid to continue ::
        if (check != false)
        {
            NewNode->next = Newptr->next;
            Newptr->next = NewNode;
        }
    }
}

void DeleteNode(ListNode*& Header, int num)
{
    ListNode* Lastptr, * BeforeLastptr;
    bool check = true;

    Lastptr = Header;
    Lastptr = Lastptr->next;
    BeforeLastptr = Header;

    if (num == 1 || num == 0)
    {
        Header = Lastptr;
        delete BeforeLastptr;
    }

    else
    {
        for (int i = 0; i < (num - 2); i++)
        {
            Lastptr = Lastptr->next;
            BeforeLastptr = BeforeLastptr->next;

            if (Lastptr == NULL)
            {
                cout << "*******************\n there is no node number " << num << " in the linked list to be deleted !! \n*******************" << endl;
                check = false;
                break;
            }
        }
        if (check != false)
        {
            BeforeLastptr->next = Lastptr->next;
            delete Lastptr;
        }
    }
}


int main()
{
    // here i defined the Header of the linked list , it's our start ::
    ListNode* Head = NULL;

    // here i added nodes with it's values
    AddNode(Head, 1.5);
    AddNode(Head, 2.68);
    AddNode(Head, 38);
    AddNode(Head, 41);
    AddNode(Head, 51.2);
    AddNodeInNum(Head, 9, 2548.1);

    // and at the last , we will show all the data we added in the last steps
    ShowNodes(Head);

    cout << "\n";
    DeleteNode(Head, 10);
    ShowNodes(Head);

    return 0;

    // Run the code to see what happened .
}