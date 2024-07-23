#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
   priority_queue <int> left;
   priority_queue <int, vector <int>, greater<int>> right;
   public:
   void addNum(int num) {
      if(left.empty() || num<left.top()){
         left.push(num);
      }else right.push(num);
      if(left.size()<right.size()){
         double temp = right.top();
         right.pop();
         left.push(temp);
      }
      if(left.size()-right.size()>1){
         double temp = left.top();
         left.pop();
         right.push(temp);
      }
   }
   double findMedian() {
      if(left.size()>right.size()) return left.top();
      return (left.top()+right.top())*0.5;
   }
};
main(){
   MedianFinder ob;
   ob.addNum(10);
   ob.addNum(15);
   cout << ob.findMedian() << endl;
   ob.addNum(25);
   ob.addNum(30);
   cout << ob.findMedian() << endl;
   ob.addNum(40);
   cout << ob.findMedian();
}