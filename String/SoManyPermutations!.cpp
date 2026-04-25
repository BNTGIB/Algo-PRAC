/*
Problem: Adding Big Numbers - 4 Kyu
Links: https://www.codewars.com/kata/5254ca2719453dcc0b00027d

Detail:

In this kata, your task is to create all permutations of a non-empty input string and remove duplicates, if present.

Create as many "shufflings" as you can!

Examples:

// With input 'a':
// Your function should return: ['a']

// With input 'ab':
// Your function should return ['ab', 'ba']

// With input 'abc':
// Your function should return ['abc','acb','bac','bca','cab','cba']

// With input 'aabb':
// Your function should return ['aabb', 'abab', 'abba', 'baab', 'baba', 'bbaa']
// Note: The order of the permutations doesn't matter.

Good luck!

*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> permutations(string s, size_t i) {
  s.erase(i,1);
  if(s.size()==1) return {s};
  if(s.size()==2){
    if(s[0]==s[1])
      return {s};
    string re=s;
    swap(s[0],s[1]);
    return{re,s};
  } 
  vector<string> res;
  for(size_t i=0;i<s.size();i++){
    if(i!=0 and s.rfind(s[i],i-1)!=string::npos)
      continue;
    string tmp,res_res;
    tmp.push_back(s[i]);
    vector<string> res_tmp=permutations(s,i);
    for(size_t i=0;i<res_tmp.size();i++){
      res_res=tmp+res_tmp[i];
      if(find(res.begin(),res.end(),res_res)==res.end())
        res.push_back(res_res);
    }
  }
  return res;
}
vector<string> permutations(string s) {
  if(s.size()==1) return {s};
  if(s.size()==2){
    if(s[0]==s[1])
      return {s};
    string re=s;
    swap(s[0],s[1]);
    return{re,s};
  } 
  vector<string> res;
  for(size_t i=0;i<s.size();i++){
    if(i!=0 and s.rfind(s[i],i-1)!=string::npos)
      continue;
    string tmp,res_res;
    tmp.push_back(s[i]);
    vector<string> res_tmp=permutations(s,i);
    for(size_t i=0;i<res_tmp.size();i++){
      res_res=tmp+res_tmp[i];
      if(find(res.begin(),res.end(),res_res)==res.end()){
        res.push_back(res_res);
      }   
    }
  }
