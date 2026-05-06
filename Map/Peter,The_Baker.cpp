/*
Problem: Pete, the baker - 5 kyu
Links: https://www.codewars.com/kata/525c65e51bf619685c000059
Time Complexity: O(N)
Space Complexity: O(N)

===Detail:

Pete likes to bake some cakes. He has some recipes and ingredients.
Unfortunately he is not good in maths. Can you help him to find out, how many cakes he could bake considering his recipes?


Write a function cakes(), which takes the recipe (unordered_map<string, int>) 
and the available ingredients (also an unordered_map<string, int>) and returns the maximum number of cakes Pete can bake (integer). 

For simplicity there are no units for the amounts (e.g. 1 lb of flour or 200 g of sugar are simply 1 or 200). 

Ingredients that are not present in the objects, can be considered as 0.

Examples:

// must return 2
cakes({{"flour", 500}, {"sugar", 200}, {"eggs", 1}}, {{"flour", 1200}, {"sugar", 1200}, {"eggs", 5}, {"milk", 200}});

// must return 0
cakes({{"apples", 3}, {"flour", 300}, {"sugar", 150}, {"milk", 100}, {"oil", 100}}, {{"sugar", 500}, {"flour", 2000}, {"milk", 2000}});

*/

#include <unordered_map>

using Ingredients = std::unordered_map<std::string, int>;

int cakes(const Ingredients& recipe, const Ingredients& available) {
  int res=0;
  for(auto [ingre,units] : recipe){
    if( units==0 )      // skip if we dont need that Ingerdients
      continue;

    auto inter=available.find(ingre);
    if( inter==available.end()  or   inter->second < units )      
      return 0;         // return 0 if any avalable ingredient doesn't enough for just 1 cake

    int possible=inter->second/units;   // possible number of cake can be baked with the present avalable ingredient.
    if( possible > 0  and  (res==0  or  possible < res)) 
      res = possible;   // update the possible cake can be baked if res wasn't updated before or the present possible is less than previous possibles.
  }
  return res;      
}