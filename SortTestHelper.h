//
// Created by sunyake on 17-11-10.
//

#ifndef ALOGRITHM_LEARN_SORTTESTHELPER_H
#define ALOGRITHM_LEARN_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
using namespace std;

namespace SortTestHelper{

    //[rangeL,rangeR]生成随机数组
    int * genetateRandomArray(int n,int rangeL,int rangeR){

        assert(rangeL <= rangeR);
        int *arr=new int[n];
        srand(time(NULL));
        for(int i=0;i<n;i++)
            arr[i] = rand()%(rangeR-rangeL+1) + rangeL;
        return arr;
    }

    int *generateNearlyOrderArray(int n,int swapTimes)
    {
        int *arr = new int[n];
        for(int i=0;i<n;i++)
            arr[i] = i;
        srand(time(NULL));
        for(int i=0;i<swapTimes;i++)
        {
            int posx = rand()%n;
            int posy = rand()%n;
            swap(arr[posx],arr[posy]);
        }
        return arr;
    }

    template <typename T>
    void printArray(T arr[],int n){

        for(int i=0;i<n;++i)
            cout<<arr[i]<<" ";
        cout<<endl;

        return;
    }

    template <typename T>
    bool isSorted(T arr[],int n){

        for(int i=0;i<n-1;i++)
            if(arr[i] > arr[i+1])
                return false;
        return true;
    }

    template <typename T>
    void testSort(string sortName,void (*sort)(T [],int),T arr[],int n){

        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();

        assert( isSorted(arr,n));
        cout<<sortName<<" "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    int* copyIntArray(int a[],int n)
    {
        int *arr = new int[n];
        copy(a,a+n,arr);
        return arr;
    }

}


#endif //ALOGRITHM_LEARN_SORTTESTHELPER_H
