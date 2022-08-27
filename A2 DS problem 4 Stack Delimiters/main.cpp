#include <iostream>
#include<string>
using namespace std;
class Node
{
private:
    char info;
    Node*next;
public:
    Node()
    {
        next=NULL;
    }
    Node(char n,Node*pt=0)
    {
        info=n;
        next=pt;
    }
    Node*getNext()
    {
        return next;
    }
    void setNext(Node*pt)
    {
        next=pt;
    }
    char getInfo()
    {
        return info;
    }
    void setInfo(char n)
    {
        info=n;
    }
};
class myStack
{
private:
    Node*head,*tail;
    string myExp;
public:
    myStack()
    {
        head=tail=NULL;
        myExp="";
    }
    myStack(char value,int Size)
    {
        head=tail=NULL;
        myExp="";
        for(int i=1; i<=Size; i++)
            Push(value);
    }
    void Push(char value)
    {
        Node*myNode;
        myNode=new Node(value,NULL);
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
    void delimiter(string setDelimiter)
    {
        myExp=setDelimiter;
        bool comment=false;
        char x;
        for(int i=0; i< myExp.length(); i++)
        {
            if(comment && myExp[i]!='*' && myExp[i+1]!='/')
                continue;
            else if(myExp[i]=='*' && myExp[i+1]=='/')
            {
                pop();
                i++;
                pop();
                comment=false;
                continue;
            }
            if(myExp[i]=='(' || myExp[i]=='[' || myExp[i]=='{')// ({)}
                Push(myExp[i]);
            else if(myExp[i]=='/' &&  myExp[i+1]=='*')
            {
                Push(myExp[i]);
                Push(myExp[i+1]);
                i++;
                comment =true;
            }
            else if(myExp[i]==')' && top(x)=='(')
                pop();
            else if(myExp[i]==']' && top(x)=='[')
                pop();
            else if(myExp[i]=='}' && top(x)=='{')
                pop();
            else if(myExp[i]=='*' && top(x)=='*')
                pop();
            else if(myExp[i]=='/' && top(x)=='/')
                pop();
            else
                continue;
        }
        cout<<setDelimiter<<" is ";
        if(isEmpty())
            cout<<"Valid Expression."<<endl;
        else
            cout<<"Invalid Expression."<<endl;
        cout<<endl;
        this->clearStack();
    }
    char pop()
    {
        if(isEmpty())
        {
            cout<<"Error can't pop ,stack is empty"<<endl;
            return -1;
        }
        char deleted;
        if(head==tail)
        {
            deleted=head->getInfo();
            delete tail;
            head=tail=NULL;
        }
        else
        {
            Node*toDelete;
            toDelete=new Node;
            toDelete=tail;
            deleted=toDelete->getInfo();
            tail=toDelete->getNext();
            delete toDelete;
        }
        return deleted;
    }
    char &top(char&var)
    {
        if(head==NULL)
            return var;
        var=tail->getInfo();
        return var;
    }
    void print()
    {
        if(head==NULL)
            cout<<"Stack is empty."<<endl;
        else if(head==tail)
            cout<<head->getInfo()<<endl;
        else
        {
            Node*loop;
            loop=new Node;
            loop=tail;
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
            Node*loop;
            loop=new Node;
            loop=tail;
            while(loop)
            {
                loop=loop->getNext();
                Size++;
            }
            return Size;
        }

    }
    void clearStack()
    {
        Node*loop;
        loop=new Node;
        loop=tail;
        while(loop)
        {
            delete loop;
            loop=loop->getNext();
        }
        head=tail=NULL;
    }
    ~myStack()
    {
        delete(head);
        delete(tail);
    }
};
int main()
{
    myStack s;
    s.delimiter("([{}])(){}[]{[]}");
    s.delimiter("({)}");
    s.delimiter("({/*)}]]]]]]}*/})");
    s.delimiter("({/*[][[]]]]]})");
    s.delimiter("[{/*******/}]");
    s.delimiter("[{/* Hello try]");
    s.delimiter("[{/*(7+9]");
    s.delimiter("[{(8*9)}]");
    s.delimiter("[}");

    return 0;
}
