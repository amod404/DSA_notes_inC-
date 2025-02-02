#include<iostream>
using namespace std;
class Node
{

public:
    // creating our node
    int data;   // stores data of urrent object
    Node *next; // store address of next obj

    // construcutor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        this->next = NULL;
        delete next;
        cout << "Memory is free for node with data " << value << endl;
    }
};

class Dnode
{
public:
    int data;
    Dnode *prev;
    Dnode *next;

    Dnode(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
    ~Dnode()
    {
        int value = this->data;
        // memory free
        this->next = NULL;
        this->prev = NULL;
        delete next;
        delete prev;
        cout << "Memory is free for node with data " << value << endl;
    }
};

class Cnode
{
public:
    int data;
    Cnode *next;

    // constructor
    Cnode(int d)
    {
        data = d;
        next = this;
    }

    // destructor
    ~Cnode()
    {
        int value = this->data;
        // memory free
        this->next = NULL;
        delete next;
        cout << "Memory is free for node with data " << value << endl;
    }
};

class Cdnode
{
public:
    int data;
    Cdnode *next;
    Cdnode *prev;

    // constructor~
    Cdnode(int d)
    {
        this->data = d;
        this->next = this;
        this->prev = this;
    }

    // destructor~
    ~Cdnode()
    {
        int value = this->data;
        // memory free
        this->next = NULL;
        this->prev = NULL;
        delete next;
        delete prev;
        cout << "Memory is free for node with data " << value << endl;
    }
};

// singly linked list
void insertAtHead(Node *&head, int d)
{

    Node *temp = new Node(d); // new node to be inserted
    temp->next = head;        // point the next of new node at head of old one
    head = temp;              // now head will go to that new node
}
void insertAtTail(Node *&tail, int d)
{

    Node *temp = new Node(d); // new node to be inserted
    tail->next = temp;        // point the next of tail to new mode
    tail = temp;              // now tail will go to that new node
}
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    Node *to_insert = new Node(d);

    // starting case
    if (position == 1)
    {
        to_insert->next = head;
        head = to_insert;
        // can use insertAthead(head,d);
        return;
    }

    // in between case
    Node *temp = head;
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
        // ending case
    }
    if (temp == tail)
    {
        tail = to_insert;
        // can use insertAttail(tail,d);
    }
    to_insert->next = temp->next;
    temp->next = to_insert;
}
void deletePosition(Node *&head, Node *&tail, int position)
{
    // starting case
    if (position == 1)
    {
        Node *waste = head;
        head = head->next;
        // memory free
        delete waste;
    }
    // other case
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
            if (curr == tail)
            {
                tail = prev;
            }
        }

        prev->next = curr->next;
        delete curr;
    }

    // // in between case
    // Node* temp= head;
    // int i=2;
    // while(i<position){
    //     temp=temp->next;
    //     i++;
    //     //ending case
    //     if(temp->next==tail){
    //         tail=temp;
    //     }
    // }
    // Node* waste=temp->next;
    // temp->next = temp->next->next;
    // delete waste;
}
void deleteValue(Node *&head, Node *&tail, int d)
{
    // starting case
    if (head->data == d)
    {
        Node *waste = head;
        head = head->next;
        // memory free
        delete waste;
    }
    // other case
    else
    {
        Node *curr = head;
        Node *prev = head;
        while (curr->data != d && prev->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev->next == NULL)
        {
            cout << "Data not found" << endl;
            return;
        }
        if (curr == tail)
        {
            tail = prev;
        }
        prev->next = curr->next;
        delete curr;
    }
}
void print(Node *&head)
{
    // since we are calling by reference, we dont want our head to go anywhere
    // so we will make a temp to iterate the nodal path
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // to go to next node
        // visualize it ~ ~
    }
    cout << endl;
}

// doubly linked list
void print(Dnode *&head)
{
    Dnode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int D_length(Dnode *&head)
{
    Dnode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void D_insertAtHead(Dnode *&head, int d)
{
    Dnode *temp = new Dnode(d);
    temp->next = head;
    if(head)
    head->prev = temp;
    head = temp;
}
void D_insertAtTail(Dnode *&tail, int d)
{
    Dnode *temp = new Dnode(d);
    if(tail){
        tail->next = temp;
    }
    temp->prev = tail;
    tail = temp;
}
void D_insertAtPosition(Dnode *&head, Dnode *&tail, int position, int d)
{
    Dnode *to_insert = new Dnode(d);
    if (position == 1)
    {
        to_insert->next = head;
        head->prev = to_insert;
        head = to_insert;
        return;
    }
    Dnode *temp = head;
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp == tail)
    {
        tail->next = to_insert;
        to_insert->prev = tail;
        tail = to_insert;
        return;
    }
    Dnode *temp2 = temp->next;
    to_insert->next = temp2;
    to_insert->prev = temp;
    temp2->prev = to_insert;
    temp->next = to_insert;
}
void D_deleteAtPosition(Dnode *&head, Dnode *&tail, int position)
{
    if (position == 1)
    {
        Dnode *waste = head;
        Dnode *temp = head->next;
        temp->prev = NULL;
        head = temp;
        delete waste;
    }
    else
    {
        Dnode *back = head;
        Dnode *curr = head;
        int i = 1;
        while (i < position)
        {
            back = curr;
            curr = curr->next;
            i++;
        }
        if (curr == tail)
        {
            tail = back;
            back->next = NULL;
            delete curr;
            return;
        }
        Dnode *front = curr->next;
        back->next = front;
        front->prev = back;
        delete curr;
    }
}
void D_deleteAtValue(Dnode *&head, Dnode *&tail, int value)
{
    if (head == NULL)
    {
        return;
    }
    if (head->data == value)
    {
        Dnode *waste = head;
        head = head->next;
        delete waste;
        head->prev = NULL;
        return;
    }
    if (tail->data == value)
    {
        Dnode *waste = tail;
        tail = tail->prev;
        delete waste;
        tail->next = NULL;
        return;
    }

    Dnode *curr = head;
    Dnode *forw = head;

    while (forw != NULL)
    {
        if (forw->data == value)
        {
            forw->next->prev = curr;
            curr->next = forw->next;
            delete forw;
            forw = curr->next;
        }
    }
}

// circular node
void C_insertAtPosition(Cnode *&tail, int position, int d)
{
    Cnode *temp = new Cnode(d);
    if (tail == NULL)
    {
        temp->next = temp;
        tail = temp;
    }
    else if (position == 1)
    {
        Cnode *back = tail;
        while (1)
        {
            back = back->next;
            if (back->next == tail)
            {
                break;
            }
        }
        temp->next = tail;
        back->next = temp;
        tail = temp;
    }
    else
    {
        Cnode *curr = tail;
        int i = 1;
        while (i < position - 1)
        {
            curr = curr->next;
            i++;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}
void C_insertAtValue(Cnode *&tail, int element, int d)
{
    Cnode *temp = new Cnode(d);
    if (tail == NULL)
    {
        tail = temp;
        temp->next = temp;
    }
    else
    {
        Cnode *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Cnode *&tail)
{
    if (tail == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    Cnode *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}
void C_deleteAtValue(Cnode *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Cnode *curr = tail;
    Cnode *prev = tail;
    if (tail->data == element)
    {
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        tail = tail->next;
        prev->next = curr->next;
        delete curr;
    }
    else
    {
        do
        {
            prev = curr;
            curr = curr->next;
        } while (curr->data != element && curr != tail);
        if (curr == tail)
        {
            cout << "You entered an invalid value" << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }
}

// circular doubly node
void print(Cdnode *&tail)
{

    if (tail == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    Cdnode *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}
void C_D_insertAtHead(Cdnode *&head, int d)
{
    Cdnode *temp = new Cdnode(d);
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    head = temp;
}
void C_D_insertAtPosition(Cdnode *&head, int position, int d)
{
    Cdnode *temp = new Cdnode(d);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    if (position == 1)
    {
        temp->prev = head->prev;
        temp->next = head;
        head->prev->next = temp;
        head->prev = temp;
        head = temp;
        return;
    }
    int i = 1;
    Cdnode *curr = head;
    while (i < position - 1)
    {
        curr = curr->next;
    }

    temp->prev = curr;
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
}
void C_D_insertAtValue(Cdnode *&head, int value, int d)
{
    Cdnode *temp = new Cdnode(d);
    if (head == NULL)
    {
        head = temp;
        return;
    }

    Cdnode *curr = head;
    while (curr->data != value)
    {
        curr = curr->next;
    }
    temp->prev = curr;
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
}
void C_D_deleteAtValue(Cdnode *&head, int value)
{
    if (head->data == value)
    {
        Cdnode *waste = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete waste;
        return;
    }
    Cdnode *curr = head->next;
    while (curr->data != value && curr != head)
    {
        curr = curr->next;
    }
    if (curr == head)
    {
        cout << "The value " << value << " is not present" << endl;
        return;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}

