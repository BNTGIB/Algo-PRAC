#include <vector>
using namespace std;

long long solve(const vector<int> &arr) {
  long long result=0, sum=0;
  for(size_t i=0;i<arr.size();i++){
    sum=0;
    vector<int> tmp;
    for(int j=i;j<arr.size();j++){
      if(find(tmp.begin(), tmp.end(),arr[j])!=tmp.end() or tmp.empty()){
        tmp.push_back(arr[i]);
        sum+=arr[j];
        result+= sum;
      }
    }
  }
  return result;
}