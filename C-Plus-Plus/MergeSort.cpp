#include<iostream>
using namespace std;
void Merge(int left[],int right[],int arr[],int lr,int ll)
{
    int i=0,j=0,k=0;
    while(i<lr && j<ll)
    {
        if(right[i]<left[j])
        {
            arr[k]=right[i];
            i++;
        }
        else
        {
            arr[k]=left[j];
            j++;
        }
        k++;
    }
    while(i<lr)
    {
        arr[k]=right[i];
        k++;
        i++;
    }
    while(j<ll)
    {
        arr[k]=left[j];
        k++;
        j++;
    }
}
int mergeSort(int arr[],int length)
{
    if(length==1)
        return 0;
    int mid=length/2;
    int right[mid];
    int left[length-mid];
    for(int i=0;i<mid;i++)
        right[i]=arr[i];
    for(int i=0;i<length-mid;i++)
        left[i]=arr[mid+i];
    mergeSort(right,mid);
    mergeSort(left,length-mid);
    Merge(left,right,arr,mid,length-mid);
}
int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergeSort(arr,n);
    cout<<"Sorted array:";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

/*
Sample I/O:

Enter the size of array:5
Enter the elements of array
5 1 4 2 3

Sorted array:1 2 3 4 5

Time Complexity:O(nlogn)
Space Complexity:O(logn)
*/
