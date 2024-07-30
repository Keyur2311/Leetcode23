class Solution {
public:
    int minimumDeletions(string s) {
        int len = s.length();
        vector<int> Va(len, 0);
        int cnt = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == 'a') {
                cnt++;
            }
            Va[i] = cnt;
        }
        vector<int> Vb(len, 0);
        cnt = 0;
        int n = len;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                cnt++;
            }
            Vb[i] = cnt;
        }
        int ans = len;
        for (int i = -1; i < n; i++) {
            int a = 0;
            if (i < n - 1) 
                a = Va[i + 1];
            
            int b = 0;
            if (i >= 0) 
                b = Vb[i];
            
            ans = min(ans, a + b);
        }
        return ans;
    }
};