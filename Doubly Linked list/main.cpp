#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* next;
    Node* prev;
};

class LinkedList
{
private:
    Node* head;
    Node* tail;

public:

    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    LinkedList(int value)
    {
        head = new Node();
        head->value = value;
        head->next = NULL;
        head->prev = NULL;

        tail = head;
    }

    void insertFirst(int value)
    {
        Node* node = new Node();
        node->value = value;
        node->next = NULL;
        node->prev = NULL;

        if(head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            head->prev = node;
            node->next = head;
            head = node;
        }
    }

    void insertLast(int value)
    {
        Node* node = new Node();
        node->value = value;
        node->next = NULL;
        node->prev = NULL;

        if(head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }


};

int main()
{

    return 0;
}
