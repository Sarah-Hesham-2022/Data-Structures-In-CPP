#include <iostream>

using namespace std;
int Fib(int x);
int main()
{
    cout<<Fib(0)<<endl;
    cout<<Fib(1)<<endl;
    cout<<Fib(2)<<endl;
    cout<<Fib(3)<<endl;
    cout<<Fib(4)<<endl;
    cout<<Fib(0)<<endl;
    cout<<Fib(5)<<endl;
    cout<<Fib(6)<<endl;
    return 0;
}
int Fib(int x)
{
    int*arr;
    arr=new int[x+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2; i<=x; i++)
        arr[i]=arr[i-1]+arr[i-2];
    return arr[x];
}
