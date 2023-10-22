class Solution {
public:
  void merge(vector<int> &arr, int l, int mid, int r, int &count) {
    int i = l;
    int j = mid + 1;
    int k = 0;

    for (i = l; i <= mid; i++) {
      while (j <= r && arr[i] > 2 * (long long)arr[j]) {
        j++;
      }
      count += j - (mid + 1);
    }

    i = l;
    j = mid + 1;
    vector<int> b(r - l + 1);

    while (i <= mid && j <= r) {
      if (arr[i] < arr[j])
        b[k++] = arr[i++];
      else
        b[k++] = arr[j++];
    }

    while (i <= mid) {
      b[k++] = arr[i++];
    }
    while (j <= r) {
      b[k++] = arr[j++];
    }

    k = 0;
    for (i = l; i <= r; i++)
      arr[i] = b[k++];
  }

  void mergeSort(vector<int> &arr, int l, int r, int &count) {
    if (l >= r)
      return;

    long long int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid, count);
    mergeSort(arr, mid + 1, r, count);
    merge(arr, l, mid, r, count);
  }
  int reversePairs(vector<int> &nums) {
    int reversePairsCount = 0;
    mergeSort(nums, 0, nums.size() - 1, reversePairsCount);
    return reversePairsCount;
  }
};