/*
Problem: Large Factorials - 4 Kyu
Links: https://www.codewars.com/kata/557f6437bf8dcdd135000010
Time Complexity: O(N^2.logN)
Space Complexity: O(NlogN)

Detail:

In mathematics, the factorial of integer n is written as n!. It is equal to the product of n and every integer preceding it. For example: 5! = 1 x 2 x 3 x 4 x 5 = 120

Your mission is simple: write a function that takes an integer n and returns the value of n!.

You are guaranteed an integer argument. For any values outside the non-negative range, return null, nil or None (return an empty string "" in C and C++). 
For non-negative numbers a full length number is expected for example, return 25! =  "15511210043330985984000000"  as a string.

For more on factorials, see http://en.wikipedia.org/wiki/Factorial

NOTES:
  The use of BigInteger or BigNumber functions has been disabled, this requires a complex solution
  I have removed the use of require in the javascript language.

*/

#include <string>
#include <algorithm> //for reverse()
using namespace std;

string mul(string a, int b){
  string res="";
  int boost=0;
  for(int i=a.size()-1;i>=0;i--){
    long long value= (a[i]-'0') * b + boost;
    res+= to_string(value%10);
    boost=value/10;
  }
  while (boost > 0) {
        res += to_string(boost % 10);
        boost /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}

string factorial(int factorial){
  if (factorial<0) return "";
  if (factorial==0) return "1";
  if (factorial<=2) return to_string(factorial);
  
  string result=to_string(factorial);
  
  for(int i = factorial-1; i>=2; i--){
    result= mul(result,i);
  }
  
  return result;
}