/*
Problem: ROT13 -5 kyu
Link: https://www.codewars.com/kata/530e15517bc88ac656000716
Time Complexity: O(n)
Space Complexity: O(n)

Detail:

// ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. 
// ROT13 is an example of the Caesar cipher.

// Create a function that takes a string and returns the string ciphered with Rot13. 
// If there are numbers or special characters included in the string, they should be returned as they are. 
// Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".

*/

#include <string>
#include <iostream>
using namespace std;

string rot13(string msg)
{
  for(size_t i=0;i<msg.size();i++){
    cout<<msg[i]<<'-';
    if(msg[i]>='A' and msg[i]<='Z')
      msg[i]= (msg[i]+13)>'Z'? (msg[i]-13) : (msg[i]+13);
    else if(msg[i]>='a' and msg[i]<='z')
      msg[i]= (msg[i]+13)>'z'? (msg[i]-13) : (msg[i]+13);
    cout<<msg[i]<<'\n';
  }
  return msg;
}
