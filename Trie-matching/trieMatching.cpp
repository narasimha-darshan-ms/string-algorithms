#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct Trie{
    struct Trie *Children[4];
    bool isEndOfWord;
};
char ATGC[4]={'A','C','G','T'};
int getIndex(char data){
    switch(data -'A'+1){
        case 1: return 0;
                
        case 3: return 1;
                
        case 7: return 2;
                
        case 20: return 3;
    }
}

struct Trie* NewTrieNode(){
    struct Trie *root=(struct Trie*)malloc(sizeof(struct Trie));
    for (int i = 0; i < 4; i++) 
        root->Children[i] = NULL; 
    root->isEndOfWord=false;
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
    for(int i=0;i<4;i++)
        if(root->Children[i]!=0)
            return i;
    return -1;
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

int CheckPresence(struct Trie *root,char text){
    int index;
    for(int i=0;i<4;i++)
        if(ATGC[i]==text)
            index=i;
    if(root->Children[index])   return index;
    return -1;
}

bool PrefixTrieMatching(struct Trie *root, string text){
    char symbol;
    int i=0,index;
    while(1){
        symbol=text[i]; index=CheckPresence(root,text[i]);
        if(root->isEndOfWord==true)     return true;
        else if(text[i]=='\0' && root->isEndOfWord!=true)     return false;
        else if(index!=-1 ){     i++; symbol=text[i]; root=root->Children[index];    }
        else    return false;
    }
}

void TrieMatching(struct Trie *root, string text){
    vector<int> index;
    int Count1=0;
    while(text!=""){
        if(PrefixTrieMatching(root,text))   index.push_back(Count1);
        text.erase(text.begin());
        Count1++;
    } 
    sort(index.begin(),index.end());
    for(int i=0;i<index.size();i++)
        cout<<index[i]<<" ";
}

int main() {
    int n;
    string text,pattern;
    cin>>text;
    cin>>n;
    struct Trie *root=NewTrieNode();
    
    for(int i=0;i<n;i++){
        cin>>pattern;
        Insert(root,pattern);
    }
    TrieMatching(root,text);
    deleteTrie(root);
    return 0;
}
