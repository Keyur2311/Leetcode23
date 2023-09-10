class Solution {
public:
  void merge(vector<pair<int, int>> &arr, int l, int mid, int r,
             vector<int> &count) {
    int i = l;
    int j = mid + 1;
    int k = 0;

    vector<pair<int, int>> b(r - l + 1);

    while (i <= mid && j <= r) {
      if (arr[i].first <= arr[j].first)
        b[k++] = arr[j++];
      else {
        count[arr[i].second] += (r - j + 1);
        b[k++] = arr[i++];
      }
    }

    while (j <= r) {
      b[k++] = arr[j++];
    }

    while (i <= mid) {
      b[k++] = arr[i++];
    }

    k = 0;
    for (i = l; i <= r; i++) {
      arr[i] = b[k++];
    }
  }

  void mergeSort(vector<pair<int, int>> &arr, int l, int r,
                 vector<int> &count) {
    if (l >= r)
      return;

    long long int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid, count);
    mergeSort(arr, mid + 1, r, count);
    merge(arr, l, mid, r, count);
  }

  vector<int> countSmaller(vector<int> &nums) {
    int n = (int)nums.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
      arr[i] = {nums[i], i};

    vector<int> count(n, 0);
    mergeSort(arr, 0, n - 1, count);

    return count;
  }
};