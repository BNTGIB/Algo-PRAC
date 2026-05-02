/*
Problem: Moving Zeros To The End - 5 Kyu
Links: www.codewars.com/kata/52597aa56021e91c93000cb0

Detail:

// Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

// move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}

*/

#include <vector>
using namespace std;

vector<int> move_zeroes(const vector<int>& input) {
  vector<int> result;
  int cs=0;
  for(size_t i=0;i<input.size();i++){
    if(input[i]!=0) 
      result.push_back(input[i]);
    else 
      cs++;
  }
  for(int i=0;i<cs;i++) result.push_back(0);
  return result;
}
