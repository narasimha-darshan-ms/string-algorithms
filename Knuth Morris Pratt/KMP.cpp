#include <bits/stdc++.h> 
#include<string>

using namespace std;

void computeLPSArray(string pattern, int M, int* lps); 

vector<int> KMPSearch(string pattern, string text) 
{ 
  int M = pattern.size(); 
  int N = text.size(); 
    vector<int> result;

  int lps[M]; 

  computeLPSArray(pattern, M, lps); 

  int i = 0; 
  int j = 0; 
  while (i < N) { 
    if (pattern[j] == text[i]) { 
      j++; 
      i++; 
    } 

    if (j == M) { 
       result.push_back(i - j); 
      j = lps[j - 1]; 
    } 

    else if (i < N && pattern[j] != text[i]) { 
      if (j != 0) 
        j = lps[j - 1]; 
      else
        i = i + 1; 
    } 
  }
  return result;
} 


void computeLPSArray(string pattern, int M, int* lps) 
{ 
 
  int len = 0; 

  lps[0] = 0; 


  int i = 1; 
  while (i < M) { 
    if (pattern[i] == pattern[len]) { 
      len++; 
      lps[i] = len; 
      i++; 
    } 
    else
      if (len != 0) { 
        len = lps[len - 1]; 

      
      } 
      else
      { 
        lps[i] = 0; 
        i++; 
      } 
    } 
} 

int main() 
{ 
  string text; 
  string pattern ;
  cin>>pattern>>text;
  
  vector<int> result = KMPSearch(pattern, text); 
  
  for(int i=0;i<result.size();i++)
      cout<<result[i]<<" ";
  return 0; 
} 
