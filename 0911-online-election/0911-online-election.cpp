class TopVotedCandidate {
public:
  vector<int> persons, times;
  vector<pair<int, int>> winAtTime;
  map<int, int> mp;
  TopVotedCandidate(vector<int> &persons, vector<int> &times) {
    persons = persons;
    times = times;

    int n = persons.size();
    int mx = 0, winner = -1;

    for (int i = 0; i < n; i++) {
      mp[persons[i]]++;
      if (mp[persons[i]] >= mx) {
        mx = mp[persons[i]];
        winner = persons[i];
      }
      winAtTime.push_back({times[i], winner});
    }
  }

  int q(int t) {
    pair<int, int> key = {t, 0};
    auto it = lower_bound(winAtTime.begin(), winAtTime.end(), key,
                          [](const pair<int, int> &a, const pair<int, int> &b) {
                            return a.first < b.first;
                          });

    if (it->first != t)
      it--;

    return it->second;
  }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */