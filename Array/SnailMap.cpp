/*
Problem: Snail - 4 Kyu
Links: https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1

Detail:

Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]

NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].

LESSION:
 NOTE2 means: snail_map =[[]] -> snail_map.size() ==1 & snail_map[0].size() == 0
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> snail(const vector<vector<int>> &snail_map) {
  
  if(snail_map.empty() or snail_map[0].empty())return {};

  vector<int> result;

  bool down=1, right=1, vertical=1;;
  
  int n=snail_map.size()-1, k = snail_map.size()-1;
  if(n==0)
    result.push_back(snail_map[0][0]);

  int i=0,j=0;
  
  while((n+1)*(n+1) > (int)result.size()){
    if(vertical){
      if(right){
        j=n-k;  ///Begin
        for( ;j<=k and j>=0;j++ )
            result.push_back(snail_map[i][j]);
        j--;
      }
      else{
        j--;
        for( ; j >= n-k and j<=n; j--)
            result.push_back(snail_map[i][j]);
        j++;
      }
      right=!right;
    }
    else{
      if(down){
        i++;
        for( ;i<=k and i>=0;i++ )
            result.push_back(snail_map[i][j]);
        i--;
      }
      else{
        i--;
        k--; //end
        for( ;i>=n-k and i<=n;i--)
            result.push_back(snail_map[i][j]);
        i++;
      }
      down=!down;
    }
    vertical=!vertical;
  }
  return result;
}