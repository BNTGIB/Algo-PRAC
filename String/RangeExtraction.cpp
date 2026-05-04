/*
Problem: Range Extraction - 4 Kyu
Links: https://www.codewars.com/kata/51ba717bb08c1cd60f00002f
Time Complexity: O(n)
Space Complexity: O(n)


Detail:

A format for expressing an ordered list of integers is to use a comma separated list of either

individual integers or a range of integers denoted by the starting integer separated from the end integer in the range by a dash, '-'. 
The range includes all integers in the interval including both endpoints. 
It is not considered a range unless it spans at least 3 numbers. For example "12,13,15-17"
Complete the solution so that it takes a list of integers in increasing order and returns a correctly formatted string in the range format.

Example:

//range_extraction({-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20});
// =>> returns "-10--8,-6,-3-1,3-5,7-11,14,15,17-20"

Courtesy of rosettacode.org
*/
#include <string>
#include <vector>
using namespace std;
string range_extraction(const vector<int> &arr) {
  if(arr.empty()) return "";

  string result=to_string(arr[0]);
  int cs=1;
  for(size_t i=1;i<arr.size();i++){
    
      if(arr[i]-arr[i-1]>=2){   //the present element is not in the range, so the last element is the end of range.
        if(cs>1){               //the first number in range has been added, so we only need "the last" if the range has more than 1 number.
          
        result+= cs>=3? '-': ',';       // If streak >= 3 use '-', otherwise use ','
          result+=to_string(arr[i-1]);  // EX: [1,2]=>1,2 ; [1,2,3] => 1-3.
        } 
        result+= ',' + to_string(arr[i]); //add "the first" of the next range
        cs=1;       //reset count variable
      }
      else         //the present element is the next number of range
        cs++;
      
      if(cs>1 and i==arr.size()-1){     // Edge case for the end of array, because there is no "next element" to check the end of range.
        result+= cs==2?',':'-' ;
        result+= to_string(arr[i]);
      }
  }
  return result;
}
