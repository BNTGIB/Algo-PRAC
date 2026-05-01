


#include <vector>
#include <iostream>
using namespace std;

vector<int> snail(const vector<vector<int>> &snail_map) {
  vector<int> result;
  
  
  bool down=1, right=1, vertical=1;;
  
  int n=snail_map.size()-1, k = snail_map.size()-1;
  if(n==0){
    cout<<snail_map[0][0]<<',';
    result.push_back(snail_map[0][0]);
  }
    

  int i=0,j=0;
  
  while(k>0){
    if(vertical){
      if(right){
        j=n-k;  ///Begin
        for( ;j<=k;j++ ){
            result.push_back(snail_map[i][j]);
            cout<<snail_map[i][j]<<',';
        }
        j--;
        cout<<"--> end right \n";
      }
      else{
        j--;
        for( ; j >= n-k; j--){
            result.push_back(snail_map[i][j]);
            cout<<snail_map[i][j]<<',';
        }
        j++;
        cout<<"--> end left \n";
      }
      right=!right;
    }
    else{
      if(down){
        i++;
        for( ;i<=k;i++ ){
            result.push_back(snail_map[i][j]);
            cout<<snail_map[i][j]<<',';
        }
        i--;
        cout<<"--> end down \n";
      }
      else{
        i--;
        k--; //end
        for( ;i>=n-k;i--){
            result.push_back(snail_map[i][j]);
            cout<<snail_map[i][j]<<',';
        }
        i++;
        cout<<"--> end up =>>k= "<<k<<"\n";
      }
      down=!down;
    }
    vertical=!vertical;
  }
  
  return result;
}

int main(){
    cout<<"Hello"<<endl;
    vector<vector<int>>     tmp{{1,2}, {4,3}};
    cout<<"the array"<<endl;
    vector<int> res= snail(tmp);
    for(size_t i=0;i<res.size();i++)
        cout << res[i] <<' ';    
    cout<<"Good Bye"<<endl;                     
}