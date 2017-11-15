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

//插入排序范围版
template <typename T>
void insert_sort_scope(T arr[],int l,int r)
{
    for(int i=l+1;i<=r;++i)
    {
        int j=i;
        T itemp = arr[j];

        for(;j > l && itemp < arr[j-1];j--)
        {
            arr[j]=arr[j-1];
        }
        arr[j]=itemp;
    }
}

//希尔排序
template<typename T>
void shellSort(T arr[], int n) {

	// 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
	int h = 1;
	while (h < n / 3)
		h = 3 * h + 1;

	while (h >= 1) {

		// h-sort the array
		for (int i = h; i < n; i++) {

			// 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
			T e = arr[i];
			int j;
			for (j = i; j >= h && e < arr[j - h]; j -= h)
				arr[j] = arr[j - h];
			arr[j] = e;
		}

		h /= 3;
	}
}


template <typename T>
void __merge(T arr[],int l,int mid,int r);

//归并排序辅助函数,对范围arr[l...r]进行排序
template <typename T>
void __mergeSort(T arr[],int l,int r)
{
    //if( l>=r )
    //    return;
    if(r - l <= 15)
    {
        insert_sort_scope(arr, l, r);
        return;
    }

    int mid = (l+r)/2;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    //优化对近乎有序数组的排序
    if(arr[mid] > arr[mid+1])
		__merge(arr,l,mid,r);
}

//归并排序辅助函数,归并两个已经排好续的数组arr[l...mid]和arr[mid+1,r]
template <typename T>
void __merge(T arr[],int l,int mid,int r)
{
    T *aux = new T[r-l+1];

    for(int i=l;i<=r;i++)
        aux[i-l] = arr[i];

    int i=l,j=mid+1;
    for(int k=l;k<=r;k++)
    {
        if(i>mid)
        {
            arr[k] = aux[j-l];
            j++;
        }
        else if(j>r)
        {
            arr[k] = aux[i-l];
            i++;
        }
        else if(aux[i-l] < aux[j-l])
        {
            arr[k] = aux[i-l];
            i++;
        }
        else
        {
            arr[k] = aux[j-l];
            j++;
        }
    }
    delete []aux;
}
//自顶向下归并排序
template <typename T>
void mergeSortUB(T arr[],int n)
{
    __mergeSort(arr,0,n-1);
}
//自底向上的归并排序
template <typename T>
void mergeSortBU(T arr[], int n)
{
	for (int sz = 1; sz < n; sz += sz)
	{
		for (int i = 0; i + sz < n; i += sz + sz)
		{
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1,n-1));
		}
	}
}

//快速排序
template<typename T>
int __partition(T arr[], int l, int r)
{
	T v = arr[l];
	
	//arr[l+1...j]<v;arr[j+1...i)>v
	int j = l;
	for (int i=l+1;i<=r;i++)
	{
		if (arr[i]<v)
		{
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

//对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort(T arr[], int l, int r)
{
	if (l>=r)
	{
		return;
	}
	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template<typename T>
void QuickSortSimple(T arr[], int n)
{
	__quickSort(arr, 0, n - 1);
}




int main() {

    int n = 1000;
    //int *arr1 = SortTestHelper::genetateRandomArray(n,0,n);
    int *arr1 = SortTestHelper::generateNearlyOrderArray(n,5);
    int *arr2 = SortTestHelper::copyIntArray(arr1,n);
    int *arr3 = SortTestHelper::copyIntArray(arr1,n);
    int *arr4 = SortTestHelper::copyIntArray(arr1,n);
    int *arr5 = SortTestHelper::copyIntArray(arr1,n);
    int *arr6 = SortTestHelper::copyIntArray(arr1,n);
	int *arr7 = SortTestHelper::copyIntArray(arr1, n);
	int *arr8 = SortTestHelper::copyIntArray(arr1, n);
    //SortTestHelper::testSort("bubble sort",bubble_sort,arr4,n);
    //SortTestHelper::testSort("select sort",select_sort,arr1,n);
    //SortTestHelper::testSort("insert sort",insert_sort,arr2,n);
    //SortTestHelper::testSort("insert sort prom",insert_sort_prom,arr3,n);
    SortTestHelper::testSort("shell sort", shellSort,arr5,n);
    SortTestHelper::testSort("merge sort UB", mergeSortUB,arr6,n);
	SortTestHelper::testSort("merge sort BU", mergeSortBU,arr7, n);
	SortTestHelper::testSort("quick sort simple", QuickSortSimple, arr8, n);

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    delete []arr5;
    delete []arr6;
	delete []arr7;
	delete []arr8;
	system("pause");
    return 0;
}