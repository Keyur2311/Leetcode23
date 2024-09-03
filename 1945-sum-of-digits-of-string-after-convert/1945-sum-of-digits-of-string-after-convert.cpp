class Solution {
public:
  int getLucky(string s, int k) {
    string temp = "";
    
    for (auto &ch : s) {
      int x = (int)(ch - 'a') + 1;
      temp += to_string(x);
    }
    
    while (k--) {
      int sum = 0;
      for (char &ch : temp) {
        sum += ch - '0';
      }
      temp = to_string(sum);
    }
    
    return stoi(temp);
  }
};
