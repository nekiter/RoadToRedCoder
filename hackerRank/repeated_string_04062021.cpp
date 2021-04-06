#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long long int amount_of_as = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a'){
            amount_of_as++;
        }
    }
    
    long long int result = amount_of_as * (long long int)(n/s.size());

    for(int i = 0; i < n%s.size(); i++){
        if(s[i] == 'a'){
            result++;
        }
    }
    cout << result;
    return result;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
