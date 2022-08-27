#include <iostream>
#include <bits/stdc++.h> //I have included this library to use the built-in function sort(str.begin(),str.end()) to sort my strings
using namespace std;

//Let us create a single linked list class
//First we create a structure called Node
class Node
{
public:
    string value;
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

    LinkedList(string value)
    {
        head = new Node();
        head->value = value;
        head->next = NULL;
    }

    void insertFirst(string value)
    {
        Node* node = new Node();
        node->value = value;
        node->next = NULL;

        if(head == NULL)
        {
            head = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
    }

    void insertLast(string value)
    {
        Node* node = new Node();
        node->value = value;
        node->next = NULL;


        if(head == NULL)
        {
            head = node;
        }
        else
        {
            Node* itr = head;
            while (itr->next != NULL)
            {
                itr = itr->next;
            }

            itr->next = node;
        }
    }

    void insertAt(string value, int index)
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

            while (current != NULL && i < index)
            {
                prev = current;
                current = current->next;
                i++;
            }

            node->next = current;
            prev->next = node;
        }

    }

    void deleteFirst()
    {
        if(head != NULL)
        {
            Node* toDelete = head;

            head = head->next;

            delete toDelete;
        }
    }

    void deleteLast()
    {
        if(head != NULL)
        {
            Node* itr = head;

            Node* prev = NULL;

            while(itr->next != NULL)
            {
                prev = itr;
                itr = itr->next;
            }

            if(prev == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {
                prev->next = NULL;
                delete itr;
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

                while(itr->next != NULL && i < index)
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

    int search(string value)
    {
        Node* itr = head;
        int i = 0;

        while (itr != NULL)
        {
            if(itr->value == value)
            {
                return i;
            }

            itr = itr->next;
            i++;
        }

        return -1;

    }

    void printLinkedList()
    {
        Node* itr = head;
        while (itr != NULL)
        {
            cout << itr->value << "   ";
            itr = itr->next;
        }
        cout<<endl;
    }
    bool IsHead() //this function to determine whether the linked list is having values or it is empty and we know this if head pointer is NULL or if not
    {
        if(head)
            return 1;
        return 0;
    }

};
//Let us create the hash table function down at the end of the code
void HashTable(string*arr,int mysize);

//A function to return the total number of ascii codes of each single letter added to the other letters of the same word
int ASCII(string word)
{
    int ascii=0;
    for(int i=0; i<word.length(); i++)
        ascii+=word[i];
    return ascii;
}
int main()
{
    //Our test cases, i chose 3 different test cases with different hash table size

    string MyAnagrams[23]= {"hello","tar","rat","sarah","art","arc","car","elbow", "below","state","taste","cider","cried","dusty","study","rta","angel","stressed","save","bored","tra","brag","rasha"};
    HashTable(MyAnagrams,23);
    cout<<endl<<" ---------------------"<<endl;
    string MyAnagrams2[20]= {"hello","tar","rat","sarah","art","arc","car","elbow", "below","state","taste","cider","cried","dusty","study","rta","angel","stressed","save","bored"};
    HashTable(MyAnagrams2,20);
    cout<<endl<<" ---------------------"<<endl;
    string MyAnagrams3[15]= {"hello","tar","rat","sarah","art","arc","car","elbow", "below","state","taste","cider","cried","dusty","study"};
    HashTable(MyAnagrams3,15);


    return 0;
}
void HashTable(string*arr,int mysize)
{
    LinkedList*myarr;
    myarr=new LinkedList[mysize];//create an array of empty linked list where each index is parallel to each element in the array of strings
    string*hasharray;
    hasharray=new string[mysize];
    for(int i=0; i<mysize; i++)
        hasharray[i]="";
    int index=0;
    string word;
    string wordInarr;
    for(int i=0; i<mysize; i++)
    {
        word=arr[i];
        sort(word.begin(),word.end());
        index=ASCII(word)%mysize;
        for(int j=0; j<mysize; j++)
        {
            wordInarr=hasharray[index];
            sort(wordInarr.begin(),wordInarr.end());
            if(hasharray[index]=="")
            {
                hasharray[index]=arr[i];
                break;
            }
            else if(hasharray[index]!="" && wordInarr!=word )
            {
                index=(ASCII(word)+j)%mysize;
                continue;
            }
            else
            {
                if(myarr[index].IsHead())
                {
                    myarr[index].insertLast(arr[i]);
                }
                else
                {
                    myarr[index].insertFirst(hasharray[index]);
                    myarr[index].insertLast(arr[i]);
                }
                break;
            }

        }
    }
    for(int i=0; i<mysize; i++)
    {
        if(hasharray[i]!="")
        {
            if(myarr[i].IsHead())
                myarr[i].printLinkedList();
            else
                cout<<hasharray[i]<<endl;
        }
    }
}
