class Solution {
public:
  bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }

  string tobinary(int val) {
    string x = "";

    int idx = -1;
    for (int i = 31; i >= 0; i--) {
      if (CheckBit(val, i)) {
        idx = i;
        break;
      }
    }

    for (int i = idx; i >= 0; i--) {
      if (CheckBit(val, i))
        x += '1';
      else
        x += '0';
    }
    return x;
  }
  string convertDateToBinary(string date) {
    int n = (int)date.size();

    string y = tobinary(stoi(date.substr(0, 4)));
    string m = tobinary(stoi(date.substr(5, 2)));
    string d = tobinary(stoi(date.substr(8)));

    string ans = y;
    ans += '-';
    ans += m;
    ans += '-';
    ans += d;

    return ans;
  }
};