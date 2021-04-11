#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    int arr[125] = { 0 };
    int found = 0;
    for(int i = 0; i < s1.size(); i++){
        if(arr[s1[i]] <= 0){
            arr[s1[i]]++;

            for(int j = 0; j < s2.size(); j++){
                if(s2[j] == s1[i]){
                    found = 1;
                    break;
                }
            }
            if(found){
                break;
            }
        }
    }

    if(found){
        return "YES";
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
