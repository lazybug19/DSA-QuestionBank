#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Create a comparator function to perform key-value pair comparison
bool compare ( pair <string, int> &a, pair <string, int> &b ){
   return a.first < b.first;
}
 
//Define sorting function to sort given dictionary or map
map <string, int> sorting( map <string, int> givenMap ){
   vector<pair <string, int> > pairVec;
   map<string, int> newMap;
   
   for ( auto& it : givenMap ) {
      pairVec.push_back( it );
   }
   
   sort( pairVec.begin(), pairVec.end(), compare);
   
   for ( auto& it : pairVec ) {
      newMap.insert( { it.first, it.second } );
   }
   return newMap;
}

void display( map <string, int>& givenMap ){
   for ( auto& it : givenMap ) {
      cout << "Key: " << it.first << ", value: " << it.second << endl;
   }
}
   
int main(){ 
   map<string, int> givenMap;
   
   givenMap = { { "Three", 3 },
        { "Two", 2 },
        { "One", 1 } 
   };
   
   cout << "Before Sorting: " << endl;
   display( givenMap );
  
   cout << "After Sorting: " << endl;
   givenMap = sorting( givenMap );
   display( givenMap ); 
}