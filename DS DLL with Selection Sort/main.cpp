#include <iostream>
using namespace std;
template<class T>
class Node
{
private:
    T info;
    Node*next;
    Node*previous;
public:
    Node()
    {
        previous=next=NULL;
    }
    Node(T n,Node*in=0,Node*pr=0)
    {
        next=in;
        info=n;
        previous=pr;
    }
    Node *getNext()
    {
        return next;
    }
    Node *getPrevious()
    {
        return previous;
    }
    void setNext(Node*pt)
    {
        next=pt;
    }
    void setPrevious(Node*pt)
    {
        previous=pt;
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
class List
{
private:
    Node<T>*head,*tail;
    int Count;
public:
    class Iterator
    {
    private:
        Node<T>*pointer;
    public:
        Iterator()
        {
            pointer=new Node<T>;
            pointer=NULL;
        }
        Iterator(const Iterator&obj)
        {
            pointer=new Node<T>;
            pointer=obj.pointer;
        }
        Iterator(Node<T>*pt)
        {
            pointer=new Node<T>;
            pointer=pt;
        }
        class IncrementError {};
        class DecrementError {};
        Iterator* operator++(int x)
        {
            if(pointer==NULL)
                throw IncrementError();
            pointer=(pointer->getNext());
            Iterator *it;
            it=new Iterator;
            it->setPointer(pointer);
            return it;
        }
        Iterator *operator--(int x)
        {
            if(pointer->getPrevious()==NULL)
                throw DecrementError();
            pointer=(pointer->getPrevious());
            Iterator *it;
            it=new Iterator;
            it->setPointer(pointer);
            return it;
        }
        void setPointer(Node<T>*p)
        {
            pointer=p;
        }
        Node<T>*getPointer()
        {
            return pointer;
        }
        ~Iterator()
        {
            delete pointer;
        }
    };
    List()
    {
        head=tail=NULL;
        Count=0;
    }
    void addToTail(T info)
    {
        Node<T>*elem;
        if(tail==NULL)
        {
            elem=new Node<T>(info,NULL,NULL);
            head=tail=elem;
        }
        else
        {
            elem=new Node<T>(info,NULL,tail);
            tail->setNext(elem);
            tail=elem;
        }
        Count++;
    }
    void addToHead(T info)
    {
        Node<T>* node = new Node<T>(info,NULL,NULL);
        if(head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            head->setPrevious(node);
            node->setNext (head);
            head = node;
        }
        Count++;
    }
    List(T value,int initial_size)
    {
        Count=0;
        head=tail=NULL;
        addToHead(value);
        for(int i=2; i<=initial_size; i++)
            addToTail(value);

    }
    int Size()
    {
        return Count;
    }
    List<T>&operator=(const List<T>&another_list)
    {
        if(this==&another_list)
            return *this;
        Node<T>*loop,*loop2;
        loop=new Node<T>;
        loop=another_list.head;
        this->Count=0;
        if(this->head!=NULL)
        {
            Node<T>*ahead;
            ahead=new Node<T>;
            ahead=head;
            while(ahead)
            {
                delete ahead;
                ahead=ahead->getNext();
            }
            head=NULL;
        }
        for(int i=1; loop!=NULL; i++)
        {
            if(i==1)
            {
                this->addToHead(loop->getInfo());
                loop=loop->getNext();
                continue;
            }
            this->addToTail(loop->getInfo());
            loop=loop->getNext();
        }
        return *this;
    }
    void Insert(T value, Iterator *position)
    {
        Node<T>*elem,*shift;
        shift=new Node<T>;
        shift=(position->getPointer());
        elem=new Node<T>(value,shift,shift->getPrevious());
        shift=shift->getPrevious();
        shift->setNext(elem);
        position->setPointer(elem);
        Count++;

    }
    void add(int location,T info)
    {
        Node<T>*elem2,*loop1;
        elem2=new Node<T>(info,NULL,NULL);
        loop1=new Node<T>;
        loop1=head;
        for(int i=1; i<location-1; i++)
        {
            loop1=loop1->getNext();
        }
        elem2->setNext(loop1->getNext());
        elem2->setPrevious(loop1);
        loop1->getNext()->setPrevious(elem2);
        loop1->setNext(elem2);
        Count++;
        cout<<"List before Selection Sort :"<<endl;
        cout<<*this<<endl;
        //Let's use selection sort best easy for linked lists
        Node<T>*first,*last;
        first=new Node<T>;
        last=new Node<T>;
        int i,j;
        T temp;
        for(i=0, first=head; i<Count-1; i++)
        {
            for(j=i+1,last=first->getNext(); j<Count; j++)
            {
                if(last->getInfo() < first->getInfo())
                {
                    temp=last->getInfo();
                    last->setInfo(first->getInfo());
                    first->setInfo(temp);
                }
                if(last==tail)
                    break;
                last=last->getNext();

            }
            if(first==tail)
                break;
            first=first->getNext();
        }
        cout<<"List after Selection Sort :"<<endl;
        cout<<*this<<endl;
    }
    class eraseError {};
    Iterator *iteratorErase(Iterator *position)
    {
        if(position->getPointer()==tail)
            throw eraseError();
        if(position->getPointer()==head)
        {
            removeFromHead();
            (*position)++;
            return position;
        }
        Node<T>*shift,*beforeShift,*deleted;
        shift=new Node<T>;
        deleted=new Node<T>;
        deleted=shift=(position->getPointer());
        beforeShift=new Node<T>;
        beforeShift=shift->getPrevious();
        beforeShift->setNext(shift->getNext());
        shift=shift->getNext();
        shift->setPrevious(beforeShift);
        (*position)++;
        delete deleted;
        Count--;
        return position;
    }
    void Remove(int location)
    {
        Node<T>*loop1,*loop;
        loop1=new Node<T>;
        loop=new Node<T>;
        loop1=head;
        for(int i=1; i<location-1; i++)
        {
            loop1=loop1->getNext();
        }
        loop=loop1->getNext()->getNext();
        loop1->setNext(loop);
        delete (loop->getPrevious());
        loop->setPrevious(loop1);
        Count--;
    }
    void removeFromHead()
    {
        if(head != NULL)
        {
            Node<T>*toDelete;
            toDelete= new Node<T>;
            toDelete=head;
            head = head->getNext();
            head->setPrevious(NULL);
            delete(toDelete);
            Count--;
        }
    }
    void removeFromTail()
    {
        Node<T>*loop1;
        loop1=new Node<T>;
        loop1= tail->getPrevious();
        loop1->setNext(NULL);
        delete(tail);
        tail=loop1;
        Count--;
    }
    bool Search(T info)
    {
        Node<T>*loop;
        loop=new Node<T>;
        loop=head;
        for(; loop!=NULL; loop=loop->getNext())
            if(loop->getInfo()==info)
            {
                return true;
            }
        return false;
    }
    Iterator Begin()
    {
        Iterator *it;
        it=new  List<T>::Iterator(head);
        return *it;
    }
    Iterator End()
    {
        Iterator *it;
        it=new  List<T>::Iterator(tail);
        return *it;
    }
    ~List()
    {
        delete head;
    }
    void printInReverse()
    {
        Node<T>*loop;
        loop=new Node<T>;
        loop=tail;
        for(; loop!=NULL; loop=loop->getPrevious())
        {
            cout<<loop->getInfo()<<" -> ";
        }
        cout<<endl;
    }
    template<class T2>
    friend ostream&operator<<(ostream&os,const List<T2>& obj);
};
template<class T2>
ostream&operator<<(ostream&os,const List<T2> &obj)
{
    if(obj.head==NULL)
        return os;
    Node<T2>*loop;
    loop=new Node<T2>;
    loop=obj.head;
    for(; loop!=NULL; loop=loop->getNext())
    {
        os<<loop->getInfo()<<" -> ";
    }
    return os;
}
int main()
{
    List<int>n1(5,4);
    n1.addToHead(8);
    n1.addToTail(9);
    cout<<n1<<endl;
    List<int>::Iterator *it;
    it=new List<int>::Iterator(n1.Begin());
    try
    {
        (*it)++;
    }
    catch(List<int>::Iterator::IncrementError)
    {
        cout<<"The iterator is pointing after last element,can't increment::ERROR"<<endl;
    }
    n1.Insert(2,it);
    cout<<"Size of n1= "<<n1.Size()<<endl;
    cout<<n1<<endl;
    try
    {
        (*it)--;
    }
    catch(List<int>::Iterator::DecrementError)
    {
        cout<<"The iterator is pointing at first element,can't decrement::ERROR"<<endl;
    }
    try
    {
        (*it)++;
    }
    catch(List<int>::Iterator::IncrementError)
    {
        cout<<"The iterator is pointing after last element,can't decrement::ERROR"<<endl;
    }
    List<int>::Iterator *it2;
    it2=new List<int>::Iterator(n1.End());
    it=n1.iteratorErase(it);
    cout<<"Size of n1= "<<n1.Size()<<endl;
    cout<<n1<<endl;
    cout<<"n1 in reverse "<<endl;
    n1.printInReverse();
    List<int>n2(2,4);
    n2=n1;
    cout<<"Size of n2= "<<n2.Size()<<endl;
    cout<<n2<<endl;
    n2.add(3,88);
    n2.removeFromHead();
    cout<<n2<<endl;
    n2.Remove(4);
    n2.removeFromTail();
    cout<<"Size of n2= "<<n2.Size()<<endl;
    cout<<n2<<endl;
    cout<<"n2 in reverse :"<<endl;
    n2.printInReverse();
    cout<<n2.Search(88)<<endl;
    cout<<n2.Search(5)<<endl;
    cout<<endl<<"Now let's try with doubles"<<endl;
    List<double>n3(5.55,4);
    n3.addToHead(8.8);
    n3.addToTail(9.988);
    cout<<n3<<endl;
    List<double>::Iterator *it3;
    it3=new List<double>::Iterator(n3.Begin());
    try
    {
        (*it3)++;
    }
    catch(List<double>::Iterator::IncrementError)
    {
        cout<<"The iterator is pointing after last element,can't increment::ERROR"<<endl;
    }
    n3.Insert(2.3546,it3);

    cout<<"Size of n3= "<<n3.Size()<<endl;
    cout<<n3<<endl;
    try
    {
        (*it3)--;
    }
    catch(List<double>::Iterator::DecrementError)
    {
        cout<<"The iterator is pointing at first element,can't decrement::ERROR"<<endl;
    }
    try
    {
        (*it3)++;
    }
    catch(List<double>::Iterator::IncrementError)
    {
        cout<<"The iterator is pointing after last element,can't decrement::ERROR"<<endl;
    }
    List<double>::Iterator *it4;
    it4=new List<double>::Iterator(n3.End());
    it3=n3.iteratorErase(it3);
    cout<<"Size of n3= "<<n3.Size()<<endl;
    cout<<n3<<endl;
    cout<<"n3 in reverse "<<endl;
    n3.printInReverse();
    List<double>n4;
    n4=n3;
    cout<<"Size of n4= "<<n4.Size()<<endl;
    cout<<n4<<endl;
    n4.add(3,88.978);
    n4.removeFromHead();
    n4.Remove(3);
    n4.removeFromTail();
    cout<<"Size of n4= "<<n4.Size()<<endl;
    cout<<n4<<endl;
    cout<<"n4 in reverse "<<endl;
    n4.printInReverse();
    cout<<n4.Search(88.978)<<endl;
    cout<<n4.Search(5.55)<<endl;
    return 0;
}
