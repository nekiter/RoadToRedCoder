#include <bits/stdc++.h>
/*
    This code is a example of how to sort an array using merge sort
    the expected input is:
    ./out <number of elements (<1000)> <0 1 ... n elements>
*/

typedef long long ll;

using namespace std;

int to_sort[1000];
int n;

void swap_values(int n, int m){
    int number_holder = to_sort[m];
    to_sort[m] = to_sort[n];
    to_sort[n] = number_holder;
}
void print_array(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void merge_sort(int f, int l){
    // cout << "Iniciando merge sort para array(" << f << " " << l <<"):\n";
    // print_array(to_sort+f, l-f+1);
    if(to_sort[f] == to_sort[l]){
        return;
    }
    if(l-f <= 2){
        if(to_sort[f] > to_sort[l])
            swap_values(f,l);
        return;
    }
    int k = floor( (f+l)/2 );

    merge_sort(f, k);
    merge_sort(k+1, l);
    // cout << "Resultado intermediario do sort(" << f << " " << l <<"):\n";
    // print_array(to_sort+f, l-f+1);

    int array_l[k-f+1], array_r[l-k];

    for (int i = 0; i < k-f+1; i++)
    {
        array_l[i] = to_sort[i+f];
    }
    for (int i = 0; i < l-k; i++)
    {
        array_r[i] = to_sort[k+1+i];
    }
    
    // cout << "Megiando as arrays(" << f << " " << l <<" -> k: "<< k << "):\n";
    // print_array(array_l, k-f+1);
    // print_array(array_r, l-k);


    int elements_to_sort = 0;
    int index_l = 0, index_r = 0;
    while(elements_to_sort < l-f+1){
        if(index_r >= l-k){
            to_sort[f+elements_to_sort] = array_l[index_l];
            index_l++;
        } else if(index_l >= k-f+1){
            to_sort[f+elements_to_sort] = array_r[index_r];
            index_r++; 
        }else if(array_l[index_l] > array_r[index_r]){
            to_sort[f+elements_to_sort] = array_r[index_r];
            index_r++;
        }else{
            to_sort[f+elements_to_sort] = array_l[index_l];
            index_l++;
        }
        elements_to_sort++;
    }
    // cout << "Resultado do merge sort para array(" << f << " " << l <<"):\n";
    // print_array(to_sort+f, l-f+1);

}

int main(){
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> to_sort[i];
    }
    cout << "Before sort: \n";
    print_array(to_sort, n);
    merge_sort(0, n-1);
    cout << "After sort: \n";
    print_array(to_sort, n);

}

//g++ -std=c++11 -O2 -Wall merge_sort.cpp -o out