#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string InverseBurrowsWheelerTransform(string text){
 
    vector<pair<char , int>> IBWT(text.size());
    string result;
    
    for(int i=0; i < text.size() ; i++)
        IBWT[i] = make_pair(text[i] , i);
    
    sort(IBWT.begin() , IBWT.end());
    
    pair<char , int> location = IBWT[0];    
    for(int i=0; i < text.size() ; i++){
        location = IBWT[location.second];
        result += location.first;
    }
        
    return result;
}

int main(){
    string text;
    cin>>text;
    string result = InverseBurrowsWheelerTransform(text);
    cout<<result;
    return 0;
}