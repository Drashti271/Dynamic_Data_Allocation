#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    public:
        int size;
        Node *head;

    LinkedList()
    {
        this->head = NULL;
        this->size = 0;
    }

    void insertAtBeginning(int element)
    {
        Node *newNode = new Node(element);
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
    }

    void searchNode(int key) 
    {
        Node *ptr = this->head;

        while(ptr != NULL) 
        {
            if(ptr->data == key) 
            {
                cout<<"Element found: "<<key<<endl;
                return;
            }
            ptr = ptr->next;
        }

        cout<<"Element not found: "<<key<<endl;
    }

    void deleteNode(int index)
    {
        if(index < 0 || index >= size) 
        {
            cout<<"Invalid Index."<<endl;
            return;
        }

        if(index == 0) 
        {
            Node *temp = this->head;
            this->head = this->head->next;
            delete temp;
        } 
        else 
        {
            Node *ptr = this->head;

            for (int i = 0; i < index - 1; i++) 
            {
                ptr = ptr->next;
            }

            Node *temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
        }
        this->size--;
    }

    void reverseList()
    {
        Node *prev = NULL, *ptr = this->head, *next = NULL;

        while(ptr != NULL) 
        {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        this->head = prev;
    }

    void displayList()
    {
        Node *ptr = this->head;

        cout<<"Linked List: ";

        while(ptr != NULL)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};

int main()
{
    LinkedList list;
    int choice,index,element;

    do{

        cout<<endl<<"-------------------"<<endl;
        cout<<"Enter 1 for insert at beginning"<<endl;
        cout<<"Enter 2 for search"<<endl;
        cout<<"Enter 3 for delete node"<<endl;
        cout<<"Enter 4 for reverse the linked list"<<endl;
        cout<<"Enter 5 for view Linked list"<<endl;
        cout<<"Enter 0 for exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"Enter a element: ";
            cin>>element;
            list.insertAtBeginning(element);
        break;

        case 2:
            cout<<"Enter a key to search: ";
            cin>>element;
            list.searchNode(element);
        break;

        case 3:
            cout<<"Enter a index: ";
            cin>>index;
            list.deleteNode(index);
        break;

        case 4:
            list.reverseList();
        break;

        case 5:
            list.displayList();
        break;

        case 0:
            cout<<"Exiting.";
        break;

        default:
            cout<<"Wrong Choice.";
        break;
        }

    }while(choice != 0);

    return 0;
}