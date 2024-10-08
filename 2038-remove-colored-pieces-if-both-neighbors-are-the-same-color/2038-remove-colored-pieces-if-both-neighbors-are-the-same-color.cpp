class Solution {
public:
    bool winnerOfGame(string colors) {
    int a = 0, b = 0, cnt_a = 0, cnt_b = 0;
    for (auto ch : colors) {
        if (ch == 'A') {
            if (++cnt_a > 2)
                ++a;
            cnt_b = 0;
        } else {
            if (++cnt_b > 2)
                ++b;
            cnt_a = 0;
        }
    }
    return a > b;
  }
};