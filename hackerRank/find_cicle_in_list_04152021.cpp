/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    Node* alreadyViseted[100];
    int amountVisited = 0;
    while(head != nullptr){
        alreadyViseted[amountVisited] = head;
        for(int i = 0; i <= amountVisited; i++){
            if(head->next == alreadyViseted[i]){
                return true;
            }
        }
        head = head->next;
        amountVisited++;
        
    }
    
    return false;
}