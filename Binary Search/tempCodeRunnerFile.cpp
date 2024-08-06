pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {
//     int firstIndex = -1,lastIndex = -1;
//     int firstIndex = lower_bound(arr.begin(),arr.end(),k)-arr.begin();
//     if(arr[firstIndex] != k)  return {-1,-1};
//     lastIndex = upper_bound(arr.begin(),arr.end(),k)-arr.begin();
//     lastIndex -= 1;
//     return {firstIndex,lastIndex};
// }
