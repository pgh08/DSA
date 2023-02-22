#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n){
    for(int i=0; i<n; i++){
        bool isSwapped = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                isSwapped = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(isSwapped == false){
            break;
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}

void insertionSort(int *arr, int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0){
            if(temp < arr[j]){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
    }
}

void merge(int *arr, int s, int e){
    int mid = s + (e-s)/2;
    int firstLen = mid - s + 1;
    int secondLen = e - mid;
    int mainIndex = s;

    int *first = new int[firstLen];
    int *second = new int[secondLen];
    
    for(int i=0; i<firstLen; i++){
        first[i] = arr[mainIndex++];
    }
    for(int i=0; i<secondLen; i++){
        second[i] = arr[mainIndex++];
    }

    mainIndex = s;
    int firstIndex = 0;
    int secondIndex = 0;

    while(firstIndex < firstLen && secondIndex < secondLen){
        if(first[firstIndex] < second[secondIndex]){
            arr[mainIndex++] = first[firstIndex++];
        }
        else{
            arr[mainIndex++] = second[secondIndex++];
        }
    }

    while(firstIndex < firstLen){
        arr[mainIndex++] = first[firstIndex++];
    }
    while(secondIndex < secondLen){
        arr[mainIndex++] = second[secondIndex++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int arr[], int s, int e){
    if(s >= e){
        return;
    }
    int mid = s + (e-s)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);
}

int partition(int *arr, int s, int e){
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot){
            count++;        
        }
    }
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int index1 = s, index2 = e;
    while(index1 < pivotIndex && index2 > pivotIndex){
        while(arr[index1] <= pivot){
            index1++;
        }
        while(arr[index2] > pivot){
            index2--;
        }
        if(index1 < pivotIndex && index2 > pivotIndex){
            swap(arr[index1++],arr[index2--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if(s >= e){
        return;
    }
    int pos = partition(arr, s, e);
    quickSort(arr, s, pos-1);
    quickSort(arr, pos+1, e);
}

void heapify(int *arr, int i, int n){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr, largest, n);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, i, n);
    }

    int size = n-1;
    while(size > 0){
        swap(arr[0], arr[size]);

        heapify(arr, 0, size);
        size--;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[10] = {12,12,-1,0,-23,123,0,5457,3,2};
    int n = 10;

    cout<<"Array before sorting"<<endl;
    printArray(arr, n);

    //bubbleSort(arr, n);
    //selectionSort(arr, n);
    //insertionSort(arr, n);
    //mergeSort(arr, 0, n-1);
    //quickSort(arr, 0, n-1);
    heapSort(arr, n);

    cout<<"Array After sorting"<<endl;
    printArray(arr, n);

    return 0;
}