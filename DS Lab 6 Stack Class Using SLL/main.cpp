#include <iostream>
#include<string>
#include<sstream>
using namespace std;
template<class T>
class Node
{
private:
    T info;
    Node<T>*next;
public:
    Node()
    {
        next=NULL;
    }
    Node(T n,Node<T>*pt=0)
    {
        info=n;
        next=pt;
    }
    Node<T>*getNext()
    {
        return next;
    }
    void setNext(Node<T>*pt)
    {
        next=pt;
    }
    T getInfo()
    {
        return info;
    }
    void setInfo(T n)
    {
        info=n;
    }
};
template<class T>
class myStack
{
private:
    Node<T>*head,*tail;
public:
    myStack()
    {
        head=tail=NULL;
    }
    void Push(T value)
    {
        Node<T>*myNode;
        myNode=new Node<T>(value,NULL);
        if(head==NULL)
        {
            head=tail=myNode;
        }
        else
        {
            myNode->setNext(tail);
            tail=myNode;
        }
    }
    bool isEmpty()
    {
        return head==NULL;
    }
    T pop()
    {
        if(isEmpty())
        {
            cout<<"Error can't pop ,stack is empty"<<endl;
            return -1;
        }
        T deleted;
        if(head==tail)
        {
            deleted=head->getInfo();
            delete tail;
            head=tail=NULL;
        }
        else
        {
            Node<T>*toDelete;
            toDelete=new Node<T>;
            toDelete=tail;
            deleted=toDelete->getInfo();
            tail=toDelete->getNext();
            delete toDelete;
        }
        return deleted;
    }
    T top()
    {
        if(head==NULL)
            return -1;
        return tail->getInfo();
    }
    void print()
    {
        if(head==NULL)
            cout<<"Stack is empty."<<endl;
        else
        {
            Node<T>*loop;
            loop=new Node<T>;
            loop=tail;
            while(loop)
            {
                cout<<loop->getInfo()<<" ";
                loop=loop->getNext();
            }
            cout<<endl;
        }
    }
};
template<class T>
int reversePolishNotation(string exp)
{
    string noSpaceString="";
    myStack<T>s;
    for(int i=0; i<exp.length(); i++)
    {
        if(isspace(exp[i]))
            continue;
        noSpaceString+=exp[i];
    }
    for(int i=0; i<noSpaceString.length(); i++)
    {
        if(isdigit(noSpaceString[i]))
        {
            stringstream str;
            str << noSpaceString[i];
            int x;
            str >> x;
            s.Push(x);
        }
        else
        {
            if(noSpaceString[i]=='+')
                s.Push(s.pop()+s.pop());
            else if(noSpaceString[i]=='-')
                s.Push(s.pop()-s.pop());
            else if(noSpaceString[i]=='*')
                s.Push(s.pop()*s.pop());
            else if(noSpaceString[i]=='/')
                s.Push(s.pop()/s.pop());
            else
                s.Push(s.pop()%s.pop());
        }
    }
    return s.top();
}
int main()
{
    myStack<int> s;
    s.Push(100);
    s.Push(200);
    s.Push(300);
    s.Push(400);
    s.print();
    cout<<s.isEmpty()<<endl;
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    s.print();
    cout<<s.isEmpty()<<endl;
    cout<<s.top()<<endl;
    cout<<reversePolishNotation<int>("6 5 2 3+8*+3+*")<<endl;
    cout<<endl<<"Now let's try with double "<<endl;
    myStack<double> s2;
    s2.Push(1.1);
    s2.Push(2.2);
    s2.Push(3.3);
    s2.Push(4.44);
    s2.print();
    cout<<s2.isEmpty()<<endl;
    cout<<s2.top()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    s2.print();
    cout<<s2.isEmpty()<<endl;
    cout<<s2.top()<<endl;
    cout<<reversePolishNotation<int>("5 5 5 3+6*+8+*")<<endl;
    cout<<reversePolishNotation<int>("4 5 6*+")<<endl;
    return 0;
}
