class Solution {
public:
    
     int totalFruit(vector<int> &fruits)
{
    unordered_map<int, int> basket;
    int left, right;
    int ans = 0;

    for (left = 0, right = 0; right < fruits.size(); ++right)
    {
        // add a new value to sliding window
        basket[fruits[right]]++;

        // rapair the window if it violotes the constraints
        while (basket.size() > 2)
        {

            basket[fruits[left]]--; // remove the value from sliding window
            if (basket[fruits[left]] == 0)
                basket.erase(fruits[left]);
            left++;
        }
        // at this point you know that your sliding window is always valid
        //  check condition (max,min.. whatever)
        ans = max(ans, right - left + 1);
    }

    return ans;
}
};