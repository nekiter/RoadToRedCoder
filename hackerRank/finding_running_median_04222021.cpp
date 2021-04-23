#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
void runningMedian(vector<int> arr) {
    // Creates a min heap
    priority_queue <int, vector<int>, greater<int> > minHeap;
    // Creates a max heap
    priority_queue <int> maxHeap;
    cout << fixed << setprecision(1);

    for(int i = 0; i < arr.size(); i++){
        if(maxHeap.size() <= minHeap.size()){
            if(minHeap.size() == 0){
               minHeap.push(arr[i]); 
            } else if(minHeap.top() < arr[i]) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(arr[i]);
            } else {
                maxHeap.push(arr[i]);
            }
        } else {
            if(maxHeap.top() > arr[i]) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(arr[i]);
            } else {
                minHeap.push(arr[i]);
            }
        }

        if(i == 0){
            cout << (float)arr[i] << endl;
            continue;
        } 
        if(maxHeap.size() > minHeap.size()){
            cout << (float)maxHeap.top() << endl;
        } else if(maxHeap.size() < minHeap.size()){
            cout << (float)minHeap.top() << endl;
        } else{
            cout << (float)(maxHeap.top()+minHeap.top()) /(float)2.0 << endl;
        } 
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    runningMedian(a);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
