/*
Problem: The Lift - 3 Kyu
Links: https://www.codewars.com/kata/58905bfa1decb981da00009e

Detail:

I bet you won't ever catch a Lift (a.k.a. elevator) again without thinking of this Kata !

Synopsis
A multi-floor building has a Lift in it.

People are queued on different floors waiting for the Lift.

Some people want to go up. Some people want to go down.

The floor they want to go to is represented by a number (i.e. when they enter the Lift this is the button they will press)


BEFORE (people waiting in queues)               AFTER (people at their destinations)
                   +--+                                          +--+ 
  /----------------|  |----------------\        /----------------|  |----------------\
10|                |  | 1,4,3,2        |      10|             10 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 9|                |  | 1,10,2         |       9|                |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 8|                |  |                |       8|                |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 7|                |  | 3,6,4,5,6      |       7|                |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 6|                |  |                |       6|          6,6,6 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 5|                |  |                |       5|            5,5 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 4|                |  | 0,0,0          |       4|          4,4,4 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 3|                |  |                |       3|            3,3 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 2|                |  | 4              |       2|          2,2,2 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 1|                |  | 6,5,2          |       1|            1,1 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 G|                |  |                |       G|          0,0,0 |  |                |
  |====================================|        |====================================|

RULE:
//Lift Rules:
- The Lift only goes up or down!
- Each floor has both UP and DOWN Lift-call buttons (except top and ground floors which have only DOWN and UP respectively)
- The Lift never changes direction until there are no more people wanting to get on/off in the direction it is already travelling
- When empty the Lift tries to be smart. For example,
    + If it was going up then it will continue up to collect the highest floor person wanting to go down
    + If it was going down then it will continue down to collect the lowest floor person wanting to go up
- The Lift has a maximum capacity of people
- When called, the Lift will stop at a floor even if it is full, although unless somebody gets off nobody else can get on!

- If the lift is empty, and no people are waiting, then it will return to the ground floor
//People Rules:
- People are in "queues" that represent their order of arrival to wait for the Lift
- All people can press the UP/DOWN Lift-call buttons
- Only people going the same direction as the Lift may enter it
- Entry is according to the "queue" order, but those unable to enter do not block those behind them that can
- If a person is unable to enter a full Lift, they will press the UP/DOWN Lift-call button again after it has departed without them

Kata Task:

- Get all the people to the floors they want to go to while obeying the Lift rules and the People rules
- Return a list of all floors that the Lift stopped at (in the order visited!)
- NOTE: The Lift always starts on the ground floor (and people waiting on the ground floor may enter immediately)

I/O
Input:
    queues a list of queues of people for all floors of the building.
        The height of the building varies
        0 = the ground floor
        Not all floors have queues
        Queue index [0] is the "head" of the queue
        Numbers indicate which floor the person wants go to
        capacity maximum number of people allowed in the lift
    Parameter validation - All input parameters can be assumed OK. No need to check for things like:
        People wanting to go to floors that do not exist
        People wanting to take the Lift to the floor they are already on
        Buildings with < 2 floors
        Basements

Output:
    A list of all floors that the Lift stopped at (in the order visited!)


Example:
Refer to the example test cases.

Language Notes
Python : The object will be initialized for you in the tests

Good Luck -
DM
*/

#include <vector>

using namespace std;

vector<int> the_lift(const vector<vector<int>> &queues, int capacity) {
  vector<vector<int>> tmp(queues);
  
  vector<int> result={0};
  vector<int> lift;
  
  int floor=tmp.size();
  bool up=1;
  int people=0;
  
  for(int i=0;i<floor;i++)
      people+=queues[i].size();
  
  int top=floor-1, bot= 0;

  while(people>0){
    if(up){
      for(int i=bot;i<floor and people>0;i++){
        bool open=0;
        //People out
        for(size_t k=0; k<lift.size();k++){
          if(lift[k]==i){
            lift.erase(lift.begin()+k);
            k--;
            people--;
            open=1;
          }
        }
        
        //People in
        for(size_t j=0; j<tmp[i].size();j++){
          top=i;
          if(tmp[i][j]>i){
            open=1;
            if((int)lift.size()<capacity){
              lift.push_back(tmp[i][j]);
              tmp[i].erase(tmp[i].begin() + j);
              j--;
            }
          }
          
        }
        if(open and i!=result.back()){     
          result.push_back(i);
          top=i;
        }

      }
    }
    
    else{
      for(int i=top;i>=0 and people>0;i--){
        bool open=0;

        //People out
        for(size_t k=0; k<lift.size();k++){
          if(lift[k]==i){
            lift.erase(lift.begin()+k);
            k--;
            open=1;
            people--;
          }
        }
        
        //People in
        for(size_t j=0; j<tmp[i].size();j++){
          bot=i;
          if(tmp[i][j]<i){
            open=1;
            if((int)lift.size()<capacity){
              lift.push_back(tmp[i][j]);
              tmp[i].erase(tmp[i].begin() + j);
              j--;
            }
          }

        }
        if(open and i!=result.back()){     
          result.push_back(i);
          bot=i;
        }

      }
    }
    up=!up;
  }
  if(result.back()!=0) result.push_back(0);
  return result;
}