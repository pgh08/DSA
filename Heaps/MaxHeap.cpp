//Insertion and Deletion time complexity : O(log(n)), space complexity : O(1);
#include<iostream>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;

    heap(){
        this->arr[0] = -1;
        this->size = 0;
    }

    void insert(int value){
        size = size + 1;
        int index = size;
        arr[size] = value;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deleteFromHeap(){
        if(size == 0){
            cout<<"No element found for deletion"<<endl;
            return;
        }
        //Put last element in root node.
        arr[1] = arr[size];
        size--;

        //Taking root element to its correct position.
        int i = 1;
        
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }

    void printing(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(2);
    h.insert(5);
    h.insert(100);

    h.printing();

    h.deleteFromHeap();

    h.printing();

    return 0;
}