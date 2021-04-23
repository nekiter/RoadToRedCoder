#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the cookies function below.
 */ 
 

#include <iostream>

int lastElement = 0;
void printHeap(int* arr){
    cout << "heap(" << lastElement << "): \t";
    for(int i = 1; i <= lastElement; i++){
        cout << arr[i] << " ";
    }        
    cout << "\n";
}

// O(1)
void swapElements(int* arr, int a, int b){
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
    cout << "Removido\t" << ret << endl;
    while(elementPosition < lastElement){
        int right = 2*elementPosition+1;
        int left = right-1;

        cout << "------------------" << endl;
        printHeap(arr);
        cout << "Fazendo swap do elemento(" << elementPosition << "): " << arr[elementPosition] << endl;
        cout << "Right: " << right << " left: " << left << endl;
        cout << "Last element: " << lastElement << endl;
        
        if(right > lastElement){
            if(left > lastElement){
                cout << "Saindo pq estou na ultima camada" << endl;
                break;
            }
            cout << "Swap com no da esquerda pq nao existe na direita" << endl;
            if(arr[left] < arr[elementPosition]){
                cout << "Swap feito entre " << arr[elementPosition] << " e " << arr[left]  << endl;
                swapElements(arr, elementPosition, left);
                elementPosition = left;            
            }                
            break;
        } 
        
        if( arr[left] <= arr[right]){
            cout << "Swap com o da esquerda" << endl;
            if(arr[left] < arr[elementPosition]){
                cout << "Swap feito entre " << arr[elementPosition] << " e " << arr[left]  << endl;
                swapElements(arr, elementPosition, left);
                elementPosition = left;
            } else{
                break;
            }                
        } else if( arr[left] > arr[right]) {
            cout << "Swap com o da direita" << endl;
            if(arr[right] < arr[elementPosition]){
                cout << "Swap feito entre " << arr[elementPosition] << " e " << arr[right]  << endl;
                swapElements(arr, elementPosition, right);
                elementPosition = right;
            } else{
                break;
            }                
        } else {
            cout << "Finalizando sem swap" << endl;
            break;  
        }

         
    }
    
    printHeap(arr);
    return ret;
}

// int cookies(int k, vector<int> A) {
//     //creating a min heap
//     int minHeap[A.size()];
    
//     for (int i = 0; i < A.size(); i++)
//     {
//         insertElement(minHeap, A[i]);
//     }

//     int operations = 0;
//     while(true)
//     {       
//         cout << "==========================" << endl;
//         printHeap(minHeap);
//         if(lastElement < 1)
//             return -1;

//         int smaller = popElement(minHeap);
//         if(smaller >= k ){
//             break;
//         }        
//         int secondSmaller = popElement(minHeap);
//         int sweetness = smaller + 2*secondSmaller;
//         cout << "sweetness \t" << smaller<< " + 2*" << secondSmaller<< " = " << sweetness << endl;
//         insertElement(minHeap, sweetness);
//         operations++;
//     }

//     return operations;
// }

int cookies(int k, vector<int> A) {
    // Creates a min heap
    priority_queue <int, vector<int>, greater<int> > pq;

    for (int i = 0; i < A.size(); i++)
    {
        pq.push(A[i]);
    }

    int smaller = 0;
    int secondSmaller = 0;
    int sweetness = 0;
    int operations = 0;
    while(true){
        if(pq.size() < 1 || (pq.top() < k && pq.size() == 1)){
            return -1;
        }
        smaller = pq.top();
        if(smaller > k){
            return operations;
        }
        pq.pop();
        secondSmaller = pq.top();
        pq.pop();

        sweetness = smaller + 2*secondSmaller;

        pq.push(sweetness);

        operations++;
    }
    
}

int main()
{
    vector<int> A = { 2, 7, 3, 6, 4, 6 };
    // A = { 2, 3 };
    // A = { 6, 9};
    A = {18};
    // A = { 1, 2, 3, 9, 10, 12 };
    A = { 1, 1, 1, 1, 1, 1, 1 };
    int ret = cookies(700, A);
    // A = {6214, 8543, 9266, 1150, 7498, 7209, 9398, 1529, 1032, 7384, 6784, 34, 1449, 7598, 8795, 756, 
    // 7803, 4112, 298, 4967, 1261, 1724, 4272, 1100, 9373};
    // int ret = cookies(3581, A);
    cout << "Awnser: " << ret << endl;
}

