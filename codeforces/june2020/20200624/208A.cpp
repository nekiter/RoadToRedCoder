#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    string music;
    cin >> music;

    int pos = music.find("WUBWUB");
    while(pos != string::npos){
        music.replace(pos, string("WUBWUB").size(), " ");
        pos = music.find("WUBWUB");
    }
    pos = music.find("WUB");
    while(pos != string::npos){
        music.replace(pos, string("WUB").size(), " ");
        pos = music.find("WUB");
    }

    if(music[0] == ' '){
        music.replace(0, string(" ").size(), "");
    }
    if(music[music.size()-1] == ' '){
        music.replace(music.size()-1, string(" ").size(), "");
    }
    cout << music << endl;
}

//g++ -std=c++11 -O2 -Wall 208A.cpp -o out