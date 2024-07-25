class Solution {
public:
    void merge(int l, int mid, int r, vector<int>& nums) {
        int i = l, j = mid + 1, k = 0;
        vector<int> ans(r - l + 1);

        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j])
                ans[k++] = nums[i++];
            else
                ans[k++] = nums[j++];
        }
        while (i <= mid)
            ans[k++] = nums[i++];

        while (j <= r)
            ans[k++] = nums[j++];

        k = 0;
        for (int i = l; i <= r; i++)
            nums[i] = ans[k++];
    }
    void mergeSort(int l, int r, vector<int>& nums) {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(l, mid, nums);
        mergeSort(mid + 1, r, nums);
        merge(l, mid, r, nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = (int)nums.size();

        mergeSort(0, n - 1, nums);

        return nums;
    }
};