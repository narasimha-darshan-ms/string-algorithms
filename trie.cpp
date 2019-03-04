#include <iostream>
using namespace std;

int count=0;
struct Trie{
    struct Trie *Children[4];
    int number;
    char data;
    bool isEndOfWord;
};
char text[4]={'A','C','G','T'};
int getIndex(char data){
    switch(data-'A'+1){
        case 1: return 0;
                
        case 3: return 1;
                
        case 7: return 2;
                
        case 20: return 3;
    }
}

struct Trie* NewTrieNode(){
    struct Trie *root=(struct Trie*)malloc(sizeof(struct Trie));
    root->number= count++;
    root->data=0;
    for (int i = 0; i < 4; i++) 
        root->Children[i] = NULL; 
    return root;
} 

void Insert(struct Trie *root, string pattern){
    struct Trie *temp = root; 

    for (int i = 0; i < pattern.length(); i++) 
    { 
        int index = getIndex(pattern[i]); 
        if (!temp->Children[index]) 
            temp->Children[index] = NewTrieNode();
        
        temp = temp->Children[index]; 
    } 

    temp->isEndOfWord = true; 
}
int isIndex(struct Trie *root){
    
}
void printTrie(struct Trie *root){
    int index= isIndex(root);
    if(index!=-1){
        for(int i=0;i<4;i++){
            if(root->Children[i]){
                cout<<root->number<<"_>"<<root->Children[i]->number<<":"<<text[i]<<endl;
                printTrie(root->Children[i]);
            }
        }
    }
    return;
}

void deleteTrie(struct Trie *root){
    int index= isIndex(root);
    if(index!=-1){
        for(int i=0;i<4;i++){
            if(root->Children[i]){
               deleteTrie(root->Children[i]);
            }
        }
    }
    free(root);
    return;
}
int main() {
    int n;
    string pattern;
    cin>>n;
    struct Trie *root=NewTrieNode();
    
    for(int i=0;i<n;i++){
        cin>>pattern;
        Insert(root,pattern);
    }
    printTrie(root);
    deleteTrie(root);
    return 0;
}