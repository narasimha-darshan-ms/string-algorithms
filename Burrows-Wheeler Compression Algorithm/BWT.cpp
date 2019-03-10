#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string BurrowsWheelerTransform(string text){
    vector<string> BWT(text.size());
    string result = "" ;
    for(int i=0 ; i < text.size() ; i++){
        BWT[i] = text.substr(i) + text.substr(0,i);
    }
    
    sort(BWT.begin() , BWT.end());
    
    for(int i=0 ; i < BWT.size() ; i++)
        result += BWT[i][text.size() - 1];
    return result;
}

int main(){
    string text;
    cin>>text;
    string result = BurrowsWheelerTransform(text);
    cout<<result;
    return 0;
}
