#include <iostream>
using namespace std;
template<class T>
class Node
{
private:
    T info;
    Node<T>*next;
    int priority;
public:
    Node()
    {
        next=NULL;
        priority=1;
    }
    Node(T n,Node<T>*ptr=NULL,int p=0)
    {
        next=ptr;
        info=n;
        priority=p;
    }
    void setInfo(T n)
    {
        info=n;
    }
    void setPriority(int n)
    {
        priority=n;
    }
    void setNext(Node<T>*ptr)
    {
        next=ptr;
    }
    T getInfo()
    {
        return info;
    }
    int getPriority()
    {
        return priority;
    }
    Node<T>*getNext()
    {
        return next;
    }
};
template<class T>
class myQueue
{
private:
    Node<T>*head,*tail;
public:
    myQueue()
    {
        head=tail=NULL;
    }
    void enqueue(T value,int Setpriority)
    {
        Node<T>*node;
        node=new Node<T>(value,NULL,Setpriority);
        if(head==NULL)
            head=tail=node;
        else
        {
            tail->setNext(node);
            tail=node;
        }
    }
    void print()
    {
        if(head==NULL)
            cout<<"Stack is empty."<<endl;
        else if(head==tail)
            cout<<head->getInfo()<<endl;
        else
        {
            Node<T>*loop;
            loop=new Node<T>;
            loop=head;
            while(loop)
            {
                cout<<loop->getInfo()<<" ";
                loop=loop->getNext();
            }
            cout<<endl;
        }
    }
    int mySize()
    {
        if(head==NULL)
            return 0;
        else if(head==tail!=NULL)
            return 1;
        else
        {
            int Size=0;
            Node<T>*loop;
            loop=new Node<T>;
            loop=head;
            while(loop)
            {
                loop=loop->getNext();
                Size++;
            }
            return Size;
        }

    }
    T &Front(T&var)
    {
        if(head==NULL)
            return var;
        var=head->getInfo();
        return var;
    }
    myQueue(T value,int Size)
    {
        head=tail=NULL;
        for(int i=1; i<=Size; i++)
            enqueue(value,1);
    }
    bool isEmpty()
    {
        return head==NULL;
    }
    bool Search(T value)
    {
        Node<T>*loop;
        loop=new Node<T>;
        loop=head;
        while(loop)
        {
            if(loop->getInfo()==value);
            return true;
            loop=loop->getNext();
        }
        return false;
    }
    void dequeue()
    {
        if(isEmpty())
            cout<<"Queue is empty."<<endl;
        else
        {
            int minP=9999;
            Node<T>*loop,*minloop;
            loop=new Node<T>;
            loop=head;
            minloop=new Node<T>;
            minloop=head;
            while(loop)
            {
                if(minP > loop->getPriority())
                {
                    minP=loop->getPriority();
                    minloop=loop;
                }
                loop=loop->getNext();
            }
            if(minloop==head)
            {
                Node<T>*beforeDelete;
                beforeDelete=new Node<T>;
                beforeDelete=head;
                cout<<head->getInfo()<<endl;
                head=head->getNext();
                delete beforeDelete;
            }
            else if(minloop==tail)
            {
                Node<T>*beforeDelete;
                beforeDelete=new Node<T>;
                beforeDelete=head;
                while(beforeDelete->getNext()!=tail)
                    beforeDelete=beforeDelete->getNext();
                cout<<tail->getInfo()<<endl;
                beforeDelete->setNext(NULL);
                delete tail;
                tail=beforeDelete;
            }
            else
            {
                Node<T>*beforeDelete;
                beforeDelete=new Node<T>;
                beforeDelete=head;
                while(beforeDelete->getNext()!=minloop)
                    beforeDelete=beforeDelete->getNext();
                beforeDelete->setNext(minloop->getNext());
                cout<<minloop->getInfo()<<endl;
                minloop->setNext(NULL);
                delete minloop;
            }
        }
    }
    ~myQueue()
    {
        delete head;
        delete tail;
    }
};
int main()
{
    myQueue<string> q;
    string x="";
    q.enqueue("first",2);
    q.enqueue("second",3);
    q.enqueue("third",3);
    q.enqueue("fourth",4);
    q.enqueue("fifth",1);
    q.enqueue("Sixth",5);
    q.print();
    cout<<q.mySize()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<"Front is: "<<q.Front(x)<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();
    cout<<q.mySize()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.Front(x)<<endl;
    cout<<q.Search("NotExist")<<endl;
    cout<<endl<<"Now let's try with integers."<<endl<<endl;
    myQueue<int> q2(3,3);
    int x2=-1;
    q2.enqueue(1,2);
    q2.enqueue(2,3);
    q2.enqueue(3,3);
    q2.enqueue(4,4);
    q2.enqueue(5,1);
    q2.enqueue(6,5);
    q2.print();
    cout<<q2.mySize()<<endl;
    cout<<q2.isEmpty()<<endl;
    cout<<"Front is: "<<q2.Front(x2)<<endl;
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.print();
    cout<<q2.mySize()<<endl;
    cout<<q2.isEmpty()<<endl;
    cout<<q2.Front(x2)<<endl;
    cout<<q2.Search(3)<<endl;
    return 0;
}
