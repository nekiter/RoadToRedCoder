#include <bits/stdc++.h>

//https://www.urionlinejudge.com.br/judge/problems/view/1856
typedef long long ll;

#define MAX 1000000100

struct enemy
{
    int index;
    enemy * next_enemy;
    enemy * prev_enemy;
    bool is_last = false;
};

enemy enemy_list[MAX];

int last_enemy_index = -1;

using namespace std;

void print_enemy_list(void){
    if(last_enemy_index == -1){
        cout << "Doidao heim" << endl;
        return;
    }
    
    int first_index = enemy_list[last_enemy_index].next_enemy->index;

    while(true){
        if(enemy_list[first_index].next_enemy->is_last){
            first_index = enemy_list[first_index].next_enemy->next_enemy->index;
            break;
        }
            
        
        first_index = enemy_list[first_index].next_enemy->index;
        
    }
    int index = first_index;
    do{
        if(enemy_list[index].is_last)
            cout << "(L)";
        cout << index << " ";
        index = enemy_list[index].next_enemy->index;
    }while (index != first_index);
    cout << endl;
    
}


void insert_enemy(int prev_enemy, int enemy_index){
    cout << "Inserindo " << enemy_index << " depois do inimigo " << prev_enemy << endl;
    enemy_list[enemy_index].index = enemy_index;
    enemy_list[enemy_index].prev_enemy = &enemy_list[prev_enemy];
    enemy_list[enemy_index].next_enemy = enemy_list[prev_enemy].next_enemy;
    enemy_list[prev_enemy].next_enemy = &enemy_list[enemy_index];

    if(enemy_list[prev_enemy].is_last || prev_enemy == enemy_index){
        enemy_list[prev_enemy].is_last = false;
        enemy_list[enemy_index].is_last = true;
    }else{
        enemy_list[enemy_index].is_last = false;
    }
    print_enemy_list();
}

void remove_enemy(int index){
    cout << "Removendo elemento" << index << endl;
    if(enemy_list[index].is_last)
        enemy_list[index].prev_enemy->is_last = true;
    
    enemy_list[index].is_last = false;
    enemy_list[index].next_enemy->prev_enemy = enemy_list[index].prev_enemy;
    enemy_list[index].prev_enemy->next_enemy = enemy_list[index].next_enemy;
    
    print_enemy_list();
}

int query_enemies(int current_enemy, int last_enemy){
    cout << "Calculando distancia entre" << current_enemy << " e " << last_enemy << endl;
    print_enemy_list();
    int dist = -1;
    int first_enemy = current_enemy;
    while(true){
        if(current_enemy == last_enemy)
            break;
        
        if(enemy_list[current_enemy].is_last){
            return query_enemies(last_enemy, first_enemy);
        }
        current_enemy = enemy_list[current_enemy].next_enemy->index;
        dist++;
    }

    return dist;
}

int main(){
    int n;
    int index_current_enemy;
    cin >> n;

    while (n--)
    { 
        cin >> index_current_enemy;
        if(last_enemy_index == -1){
            last_enemy_index = index_current_enemy;
        }
        insert_enemy(last_enemy_index, index_current_enemy);
        last_enemy_index = index_current_enemy;
    }
    
    int q;
    cin >> q;

    while(q--){
        int n1, n2;
        char letter;
        cin >> letter;

        if(letter == 'Q'){
            cin >> n1 >> n2;
            cout << query_enemies(n1,n2) << "\n";
        } else if(letter == 'I'){
            cin >> n1 >> n2;
            insert_enemy(n2, n1);
        } else {
            //letter = 'R'
            cin >> n1;
            remove_enemy(n1);
        }
    }
    
}

//g++ -std=c++11 -O2 -Wall uri1856.cpp -o out