# LC1637-Tutorial
Widest Vertical Area Between Two Points Containing No Points

## Solution

``` C++
  class Solution {
  public:
      int maxWidthOfVerticalArea(vector<vector<int>>& points) {
          set<int> xAxis;
          for(auto &x: points) {
              xAxis.insert(x[0]);
          }
          int ans = 0;
          int prev = INT_MAX;
          for(auto x: xAxis) {
              ans = max(ans, x - prev);
              prev = x;
          }
          return ans;
      }
  };
  ```
  
## Explanation

- y coordinate of the point doesn't play any role in the problem. Thus we may transform this into an array of integer x coordinates of the points.

- Now we need to find the maximum distance (along x-axis) between two consecutive points, when this array is sorted.

- To achieve this, we can use a ordered set, where the elements are unique and can be iterated in ascending order.

- We keep the track of the last point and use it to update the ans. Note that we take ```ans = max(ans, x - prev)``` which stores the maximum of the difference between adjacent elements.

## Complexity Analysis

Here, ```n``` represents the number of elements in the vector ```points```.

### Time Complexity

- There are two major parts of the algorithm: insertion into the set and iteration of the set.
- Insertions costs a total of **```O(n*log(n))```**.
- Iterating over a set has a complexity of **```O(n)```** \[Note 1\]
- Overall complexity is thus, **```O(n*log(n))```**

### Space Complexity

- Since we use an additional set, that requires **```O(n)```** space.
  
 
Note 1: All iterator operations have an amortized constant time complexity. Thus, iterating over the set has a complexity of **```O(n)```**
