/*
Problem: Find the odd int - 6 Kyu
Links: www.codewars.com/kata/54da5a58ea159efa38000836
Time complexity: O(N);
Space complexity: O(N);

Detail:

// Given an array of integers, find the one that appears an odd number of times.

// There will always be only one integer that appears an odd number of times.

// Examples
// [7] should return 7, because it occurs 1 time (which is odd).
// [0] should return 0, because it occurs 1 time (which is odd).
// [1,1,2] should return 2, because it occurs 1 time (which is odd).
// [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
// [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).


*/

#include <vector>
#include <algorithm>
using namespace std;

int findOdd(const vector<int> numbers){
  vector<int> tmp(numbers);
  
  sort(tmp.begin(), tmp.end());
  
  int count=1;
  size_t i=1;
  
  for( ; i<tmp.size() ; i++ ){
    if(tmp[i]==tmp[i-1])
      count++;
    
    else if(count%2)
      return tmp[i-1];
    
    else
      count=1;
    
  }
  return tmp[i-1];
}