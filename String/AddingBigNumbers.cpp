/*
Problem: Adding Big Numbers - 4 Kyu
Links: https://www.codewars.com/kata/525f4206b73515bffb000b21

Detail:

// We need to sum big numbers and we require your help.

// Write a function that returns the sum of two numbers. The input numbers are strings and the function must return a string.

// Example
// add("123", "321"); -> "444"
// add("11", "99");   -> "110"

// Notes:
// The input numbers are big.
// The input is a string of only digits
// The numbers are positives

*/

#include <string>

using namespace std;
string add(const string& a, const string& b) {
  string result="";
  int ia=a.size()-1, ib=b.size()-1;
  bool up=0;
  while(ia>=0 or ib>=0){
    int tmp=(int)((ia>=0? a[ia] -'0' : 0) + (ib>=0? b[ib] -'0' : 0)) + (up?1:0);
    up=0;
    ia--;
    ib--;
    if(tmp>=10 and (ia>=0 or ib>=0)){
      result= to_string(tmp-10) + result;
      up=1;
    }
    else
      result= to_string(tmp) + result;
  }
  return result;
}
