/*
QUESTION:
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
Note: The second largest element should not be equal to the largest element.

Examples:
Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
*/

//CODE:
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = -1;
        int secondlar=-1;
        int n = arr.size();
        for(int i =0; i<n; i++){
            if(arr[i] > largest){
                secondlar = largest;
                largest = arr[i];
            }
            else if(arr[i] < largest && arr[i] > secondlar){
                secondlar = arr[i];
            }
        }
        
        return secondlar;
        
    }
};
