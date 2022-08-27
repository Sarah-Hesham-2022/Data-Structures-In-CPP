#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

public:

    LinkedList()
    {
        head = NULL;
    }

    LinkedList(int value)
    {
        head = new Node();
        head->value = value;
        head->next = head;
    }

    void insertFirst(int value)
    {
        Node* node = new Node();
        node->value = value;
        node->next = NULL;

        if(head == NULL)
        {
            head = node;
            head->next = head;
        }
        else
        {
            node->next = head;
            Node* itr = head;

            while(itr->next != head)
            {
                itr = itr->next;
            }

            itr->next = node;
            head = node;
        }
    }

    void insertLast(int value)
    {
        Node* node = new Node();
        node->value = value;
        node->next = NULL;

        if(head == NULL)
        {
            head = node;
            head->next = head;

        }
        else
        {
            Node* itr = head;
            while (itr->next != head)
            {
                itr = itr->next;
            }

            itr->next = node;
            node->next = head;
        }
    }

    void insertAt(int value, int index)
    {
        if(index == 0)
        {
            insertFirst(value);

        }
        else
        {
            Node* node = new Node();
            node->value = value;
            node->next = NULL;

            Node* prev = NULL;
            Node* current = head;

            int i = 0;

            while (current->next != head && i < index)
            {
                prev = current;
                current = current->next;
                i++;
            }

            if(i == index)
            {
                node->next = current;

                if(current == head)
                {
                    head = node;
                }

                prev->next = node;
            }

        }

    }

    void deleteFirst()
    {
        if(head != NULL)
        {
            if(head == head->next)
            {
                delete head;
                head = NULL;
            }
            else
            {

                Node* current = head;
                while (current->next != head)
                {
                    current = current->next;
                }

                current->next = head->next;

                delete head;

                head = current->next;
            }

        }
    }

    void deleteLast()
    {
        if(head != NULL)
        {
            if(head == head->next)
            {
                delete head;
                head = NULL;
            }
            else
            {
                Node* current = head;
                Node* prev = NULL;

                while (current->next != head)
                {
                    prev = current;
                    current = current->next;
                }

                prev->next = head;
                delete current;
            }

        }
    }

    void deleteAt(int index)
    {
        if(head != NULL)
        {
            if(index == 0)
            {
                deleteFirst();
            }
            else
            {

                Node* itr = head;
                Node* prev = NULL;
                int i = 0;

                while(itr->next != head && i < index)
                {
                    prev = itr;
                    itr = itr->next;
                    i++;
                }

                if(i == index)
                {
                    prev->next = itr->next;
                    delete itr;
                }
            }


        }
    }

    int search(int value)
    {
        Node* itr = head;
        int i = 0;

        while (itr->next != head)
        {
            if(itr->value == value)
            {
                return i;
            }

            itr = itr->next;
            i++;
        }

        if(itr->value == value)
        {
            return i;
        }

        return -1;

    }

    void printLinkedList()
    {
        Node* itr = head;
        int i = 0;
        while (i < 10)
        {
            cout << itr->value << " -> ";
            itr = itr->next;
            i++;
        }

        cout << endl;
    }


};

int main()
{
    LinkedList* list = new LinkedList(1);
    list->printLinkedList();

    list->insertFirst(0);
    list->printLinkedList();

    list->insertLast(2);
    list->printLinkedList();

    list->insertAt(3, 2);
    list->printLinkedList();

    list->deleteFirst();
    list->printLinkedList();

    list->deleteLast();
    list->printLinkedList();

    list->deleteAt(1);
    list->printLinkedList();

    cout << list->search(1) << endl;
    cout << list->search(0) << endl;

    return 0;
}
