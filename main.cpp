#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"


//冒泡排序
template <typename T>
void bubble_sort(T A[],int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N ;j++)
        {
            if(A[i]>A[j])
                swap(A[i],A[j]);
        }

    }
}


//选择排序
template <typename  T>
void select_sort(T A[],int N)
{
    for(int i=0;i<N;++i)
    {
        int min_pos=i;
        for(int j=i+1;j<N;++j)
        {
            if(A[j]<A[min_pos])
                min_pos = j;
        }
        std::swap(A[min_pos],A[i]);
    }
}

//插入排序
template <typename  T>
void insert_sort(T A[],int N)
{//存在较多的交换次数
    for(int i=1;i<N;++i)
    {
        for(int j=i;j > 0 && A[j] < A[j-1];j--)
        {
            swap(A[j],A[j-1]);
        }
    }
}

//优化版插入排序
template <typename  T>
void insert_sort_prom(T A[],int N)
{//减少交换次数的改进版
    for(int i=1;i<N;++i)
    {
        int j=i;
        T itemp = A[j];

        for(;j > 0 && itemp < A[j-1];j--)
        {
            A[j]=A[j-1];
        }
        A[j]=itemp;
    }
}

//希尔排序
template <typename  T>
void shell_sort(T A[],int N)
{
    int h=1;
    while(h < N/3)
        h=3*h+1;

    while(h>=1)
    {
        for(int i=0;i<N;++i)
        {
            int j=i+h;
            T itemp = A[j];

            for(;j > 0 && itemp < A[j-h];j-=h)
            {
                A[j]=A[j-h];
            }
            A[j]=itemp;
        }

        h = h/3;
    }
}


int main() {

    int n = 10000;
    //int *arr1 = SortTestHelper::genetateRandomArray(n,0,n);
    int *arr1 = SortTestHelper::generateNearlyOrderArray(n,100);
    int *arr2 = SortTestHelper::copyIntArray(arr1,n);
    int *arr3 = SortTestHelper::copyIntArray(arr1,n);
    int *arr4 = SortTestHelper::copyIntArray(arr1,n);
    int *arr5 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("bubble sort",bubble_sort,arr4,n);
    SortTestHelper::testSort("select sort",select_sort,arr1,n);
    SortTestHelper::testSort("insert sort",insert_sort,arr2,n);
    SortTestHelper::testSort("insert sort prom",insert_sort_prom,arr3,n);
    SortTestHelper::testSort("shell sort",shell_sort,arr5,n);

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    delete []arr5;
    return 0;
}