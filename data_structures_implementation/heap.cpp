#include <bits/stdc++.h>

using namespace std;

const int heapSize = 100;
int minHeap[heapSize+1];
int lastElement = 0;

void printHeap(){
    cout << "heap(" << lastElement << "): \t";
    for(int i = 1; i <= lastElement; i++){
        cout << minHeap[i] << " ";
    }        
    cout << "\n";
}

// O(1)
void swapElements(int* arr, int a, int b){
    cout << "Trocando " << arr[a] << " com " << arr[b] << endl;
    int value_holder = arr[a];
    arr[a] = arr[b];
    arr[b] = value_holder;
}

// log(N)
void insertElement(int* arr, int value){
    lastElement++;
    arr[lastElement] = value;

    int elementPosition = lastElement;
    while(lastElement > 1){
        int nodeBefore = (elementPosition-elementPosition%2)/2;
        if(arr[elementPosition] < arr[nodeBefore]){
            swapElements(arr, elementPosition, nodeBefore);
            elementPosition = nodeBefore;
        } else {
            break;
        }        
    }
}

// log(N)
int popElement(int* arr){
    int ret = arr[1];
    arr[1] = arr[lastElement];

    lastElement--;
    int elementPosition = 1;
    while(elementPosition < lastElement){
        int right = 2*elementPosition+1;
        int left = right-1;

        if(right > lastElement){
            if(arr[left] < arr[elementPosition]){
                swapElements(arr, elementPosition, left);
                elementPosition = left;            
            }                
            break;
        } 
        
        if( arr[left] < arr[right]){
            if(arr[left] < arr[elementPosition]){
                swapElements(arr, elementPosition, left);
                elementPosition = left;
            } else{
                break;
            }                
        }
        
        if( arr[left] > arr[right]) {
            if(arr[right] < arr[elementPosition]){
                swapElements(arr, elementPosition, right);
                elementPosition = right;
            } else{
                break;
            }                
        }
        break;   
    }
    return ret;
}

int main()
{
    vector<int> A = { 2, 7, 3, 6, 4, 6 };

    for (int i = 0; i < A.size(); i++)
    {
        insertElement(minHeap, A[i]);
    }
    
    int k = 9;
    int operations = 0;
    while(true)
    {
        int smaller = popElement(minHeap);
        if(smaller >= k){
            break;
        }
        int secondSmaller = popElement(minHeap);
        int sweetness = smaller + 2*secondSmaller;
        insertElement(minHeap, sweetness);
        operations++;
    }
}
