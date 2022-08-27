#include <iostream>
using namespace std;
template<class T>
class myQueue
{
private:
    int Front;
    int rear;
    int Count;
    int Size;
    T*arr;
public:
    myQueue()
    {
        Front=rear=Size=Count=0;
        arr=new T[0];
    }
    myQueue(int s)
    {
        Front=rear=Count=0;
        Size=s+1;
        arr=new T[s];
    }
    void enqueue(T value)
    {
        if(Count==Size-1)
            cout<<"Can't enqueue size filled"<<endl;
        else
        {
            arr[rear]=value;
            rear=(rear+1)%Size;
            Count++;
        }
    }
    bool isEmpty()
    {
        return Count==0;
    }
    void dequeue()
    {
        if(isEmpty())
            cout<<"Queue is already empty ,can't dequeue."<<endl;
        else
        {
            Front=(Front+1)%Size;
            Count--;
        }
    }
    T front()
    {
        if(isEmpty())
            return -1000;
        return arr[Front];
    }
    T Rear()
    {
        if(isEmpty())
            return -1000;
        return arr[rear-1];
    }
    int printCurrentSize()
    {
        return Count;
    }
    void Print()
    {
        for(int i=Front; i!=rear; i=(i+1)%Size)
            cout<<arr[i]<<" -> ";
        cout<<endl;
    }

};
int main()
{
    myQueue<int>q1(6);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.Print();
    cout<<"Size : "<<q1.printCurrentSize()<<endl;
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Rear: "<<q1.Rear()<<endl;
    q1.dequeue();
    q1.dequeue();
    q1.Print();
    cout<<"Size : "<<q1.printCurrentSize()<<endl;
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Rear: "<<q1.Rear()<<endl;
    q1.enqueue(77);
    q1.enqueue(88);
    q1.enqueue(66);
    q1.Print();
    cout<<"Size : "<<q1.printCurrentSize()<<endl;
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Rear: "<<q1.Rear()<<endl;
    cout<<q1.isEmpty()<<endl;
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    cout<<q1.isEmpty()<<endl;
    cout<<endl<<"Now let's try with double"<<endl<<endl;
    myQueue<double>q(6);
    q.enqueue(1.11);
    q.enqueue(2.21);
    q.enqueue(3.32);
    q.enqueue(4.44);
    q.enqueue(5);
    q.enqueue(6.0);
    q.Print();
    cout<<"Size : "<<q.printCurrentSize()<<endl;
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Rear: "<<q.Rear()<<endl;
    q.dequeue();
    q.dequeue();
    q.Print();
    cout<<"Size : "<<q.printCurrentSize()<<endl;
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Rear: "<<q.Rear()<<endl;
    q.enqueue(77.8);
    q.enqueue(88.9);
    q.enqueue(66.78);
    q.Print();
    cout<<"Size : "<<q.printCurrentSize()<<endl;
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Rear: "<<q.Rear()<<endl;
    cout<<q.isEmpty()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.isEmpty()<<endl;
    return 0;
}
