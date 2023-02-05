class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
    long long n = (long long)gifts.size();
    multiset<long long, greater<long long>> st(gifts.begin(), gifts.end());

    long long ans = 0;
    while (k--)
    {
        long long val = *st.begin();
        long long sq = ((long long)sqrt(val));
        long long add = val - sq;
        st.erase(st.begin());
        st.insert(sq);
    }

    for (auto &x : st)
        ans += x;

    return ans;
    }
};