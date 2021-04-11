#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    int arr[125] = { 0 };

    for (size_t i = 0; i < s.size(); i++)
    {
        arr[(int)s[i]]++;
    }
    
    bool already_has_odd = false;
    for (size_t i = 0; i < 125; i++)
    {
        if(arr[i]%2 != 0){
            if(already_has_odd)
                return "NO";
            already_has_odd = true;
        }
    }
    return "YES";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
