#include <bits/stdc++.h>
/*
    This code is a example of how to sort an array using bubble sort
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

void bubble_sort(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if(to_sort[j] > to_sort[j+1]){
                swap_values(j, j+1);
            }
        }
        
    }
    
}

void print_array(){
    for (int i = 0; i < n; i++)
    {
        cout << to_sort[i] << " ";
    }
    cout << "\n";
}

int main(){
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> to_sort[i];
    }
    cout << "Before sort: \n";
    print_array();
    bubble_sort();
    cout << "After sort: \n";
    print_array();

}

//g++ -std=c++11 -O2 -Wall bubble_sort.cpp -o out