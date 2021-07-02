#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countPairs' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
bool isPowerOfTwo(long n) {
    return n>0 && !(n & (n-1));
}
long countPairs(vector<int> arr) {
    long ans = 0;
    // Max arr[N] = 200000 = 18 bits
    vector<vector<int>> bitsRepresentation;
    for(int i = 0; i < 18; i++) {
        vector<int> aux;
        bitsRepresentation.push_back(aux);
    }
    for (int i = 0; i < arr.size(); i++) {
        //Getting each bit from the number
        for (int j = 1; j < 19; j++) {
            int currentBit = (arr[i] & ( 1 << j )) >> j;
            if(currentBit == 1){
                bitsRepresentation[j].push_back(i);
            }
        }
    }


    for (int i = 0; i < arr.size(); i++) {

    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = countPairs(arr);

    fout << result << "\n";

    fout.close();

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
