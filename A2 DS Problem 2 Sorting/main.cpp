#include <iostream>
using namespace std;
#include<stdlib.h>//for different random number generation each time you run the code
#include<ctime>
#include <chrono>//to calculate time taken by a certain function
using namespace std::chrono;
#include <thread>
class TestSorting
{
    int *myarr;
    int mySize;
    static int change;
public:
    TestSorting()
    {
        myarr=new int[0];
        mySize=0;
    }
    int partition1(int arr[], int l, int h)
    {
        int p = arr[l];
        int i = l;
        int j = h;
        while (i < j)
        {
            do
            {
                i++;
            }
            while (arr[i] <= p);
            do
            {
                j--;
            }
            while (arr[j] > p);

            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[l], arr[j]);
        return j;
    }
    void quickSort1(int arr[], int l, int h)
    {

        if (l < h)
        {
            int piv = partition1(arr, l, h);
            quickSort1(arr, l, piv);
            quickSort1(arr, piv + 1, h);
        }

    }

    int partition2(int arr[], int iBegin, int jEnd)
    {
        int i = iBegin;
        int j = jEnd;
        int pivLoc = i;
        while (true)
        {
            while (arr[pivLoc] <= arr[j] && pivLoc != j)
            {
                j--;
            }
            if (pivLoc == j)
                break;
            else if (arr[pivLoc] > arr[j])
            {
                swap(arr[j], arr[pivLoc]);
                pivLoc = j;
            }

            while (arr[pivLoc] >= arr[i] && pivLoc != i)
            {
                i++;
            }
            if (pivLoc == i)
                break;
            else if (arr[pivLoc] < arr[i])
            {
                swap(arr[i], arr[pivLoc]);
                pivLoc = i;
            }
        }
        return pivLoc;
    }


    void quickSort2(int arr[], int l, int h)
    {

        if (l < h)
        {
            int piv = partition2(arr, l, h);
            quickSort2(arr, l, piv - 1);
            quickSort2(arr, piv + 1, h);
        }

    }
    void SelectionSort(int arr[],int mySize)
    {
        int i,j,minindex,temp;
        for(int i=0; i<mySize-1; i++)
        {
            minindex=i;
            for(j=i+1; j<mySize; j++)
            {
                if(arr[j]<arr[minindex])
                    minindex=j;
            }
            if(minindex!=i)
            {
                temp=arr[i];
                arr[i]=arr[minindex];
                arr[minindex]=temp;
            }
        }
    }
    int *generateRandomList(int minNo,int maxNo,int Size)
    {
        int*newarr=new int[Size];
        for(int i=0; i<Size; i++)
        {
            srand(change++);//to change the algorithm and have different random numbers each time ,so we need a static variable
            newarr[i]=rand()%(maxNo-minNo+1)+(minNo);
        }
        delete []myarr;
        mySize=Size;
        myarr=newarr;
        cout<<"The random array generated is :"<<endl;
        for(int i=0; i<Size; i++)
            cout<<myarr[i]<<" ";
        cout<<endl;
        return myarr;
    }
    int RunOnce(string sorter, int data[], int Size)
    {
        if(sorter=="Quick Sort" || sorter=="Quick sort"|| sorter=="quick sort"|| sorter=="quick Sort"||sorter=="QUICK SORT")
        {
            auto start = high_resolution_clock::now();
            quickSort2(data,0,Size-1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
        }
        else if(sorter=="Selection Sort" || sorter=="Selection sort"|| sorter=="selection sort"|| sorter=="selection Sort"||sorter=="SELECTION SORT")
        {
            auto start =high_resolution_clock::now();
            SelectionSort(data,Size);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<std::chrono::microseconds>(stop - start);
            return double(duration.count());
        }
        else
            cout<<"Incorrect sorter input"<<endl;
        return -1;
    }
    void  RunAndAverage(string sorter,int minNo,int maxNo,int Size,int sets_num)
    {
        int*arr=new int[Size];
        double sum=0.0;
        for(int i=0; i<sets_num; i++)
        {
            arr=generateRandomList(minNo,maxNo,Size);//array having arrays inside it
            sum+=RunOnce(sorter,arr,Size);//enable function re-usability
            cout<<"Array after sorting no."<<i+1<<endl;
            for(int j=0; j<Size; j++)
                cout<<arr[j]<<" ";
            cout<<endl<<endl;
        }
        cout<<"Average time taken by different arrays to be sorted is: "<<sum/sets_num<<endl;
    }
    ~TestSorting()
    {
        delete[]myarr;
    }
};
int TestSorting::change=100;
int main()
{
    TestSorting class1;
    int *arr=new int[20];
    arr=class1.generateRandomList(1,100,20);
    cout<<"Time taken by Quick sort is : ";
    cout<<class1.RunOnce("Quick sort",arr,20)<<endl<<"After Quick sort: "<<endl;
    for(int i=0; i<20; i++)
        cout<<(arr[i])<<" ";
    cout<<endl;
    cout<<"Time taken by Selection sort is : ";
    cout<<class1.RunOnce("Selection sort",arr,20)<<endl<<"After Selection sort: "<<endl;
    for(int i=0; i<20; i++)
        cout<<(arr[i])<<" ";
    cout<<endl<<endl;
    class1.RunAndAverage("Quick Sort",1,100,20,5);

    return 0;
}
