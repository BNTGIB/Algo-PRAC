/*
Problem: Roman Numerals Helper - 4 Kyu
Links: https://www.codewars.com/kata/51b66044bce5799a7f000003

Detail:

// Write two functions that convert a roman numeral to and from an integer value. Multiple roman numeral values will be tested for each function.

// Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero. In Roman numerals:

// 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC
// 2008 is written as 2000=MM, 8=VIII; or MMVIII
// 1666 uses each Roman symbol in descending order: MDCLXVI.
// Input range : 1 <= n < 4000

// In this kata 4 should be represented as IV, NOT as IIII (the "watchmaker's four").

*/

#include <string>
#include <vector>

using namespace std;

class RomanHelper{
  vector<unsigned int> value={1,4,5,9,10,40,50,90,100,400,500,900,1000};
  vector<string> roman={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
  public:
    std::string to_roman(unsigned int n){
      string result="";
      int i=roman.size()-1;
      while(n>0){
        if(value[i]<=n){
          n-=value[i];
          result+=roman[i];
        }
        else
          i--;
      }
      return result;
    }
  
    int from_roman(std::string rn){
      int res=0, k=roman.size()-1;
      for(size_t i=0;i<rn.size();){
        
        string tmp= "";
        tmp+= rn[i];
        
        if(i+1<rn.size()){
          tmp+=rn[i+1];
          if(tmp==roman[k]){
            res+=value[k];
            i+=2;
            continue;
          }
          tmp.pop_back();
        }
        if(roman[k]==tmp){
          res+=value[k];
          i++;
        }
        else
          k--;
      }
      return res;
    }
} RomanNumerals;