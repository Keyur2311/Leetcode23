class Solution {
public:
  bool isPathCrossing(string path) {
    set<pair<int, int>> st;
    
    pair<int, int> p = {0, 0};
    st.insert(p);
    for (auto ch : path) {
     
      if (ch == 'N')
        p.second += 1;
      if (ch == 'S')
        p.second -= 1;
      if (ch == 'E')
        p.first += 1;
      if (ch == 'W')
        p.first -= 1;

      if (st.count(p))
        return true;
      st.insert(p);
    }

    return false;
  }
};