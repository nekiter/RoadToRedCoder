#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int getMaxCost(vector<int> cost, vector<string> labels, int dailyCount){
    int ans = 0;
    int costOfDay = 0;
    int legalOfDay = 0;
    for(int i = 0; i < labels.size(); i++){
        costOfDay += cost[i];
        if(labels[i] == "legal"){
            legalOfDay++;
            if(legalOfDay >= dailyCount){
                if(costOfDay > ans){
                    ans = costOfDay;
                }
                costOfDay = 0;
                legalOfDay = 0;
            }
        }
    }

    return ans;
}

int main(){
    // vector<int> cost = {0, 3, 2, 3, 4};
    // vector<string> labels = {"legal", "legal", "illegal", "legal", "legal"};
    // int dailyCount = 1;
    // ans = 5

    // vector<int> cost = {2, 5, 3, 11, 1};
    // vector<string> labels = {"legal", "illegal", "legal", "illegal", "legal"};
    // int dailyCount = 2;
    // ans = 10


    // vector<int> cost = {2, 5, 3, 11, 1};
    // vector<string> labels = {"legal", "illegal", "illegal", "illegal", "legal"};
    // int dailyCount = 1;
    // ans = 22

    vector<int> cost = {2, 5, 3, 11, 1};
    vector<string> labels = {"illegal", "illegal", "illegal", "illegal", "legal"};
    int dailyCount = 2;
    // ans = 0

    cout << getMaxCost(cost, labels, dailyCount) << endl;
}