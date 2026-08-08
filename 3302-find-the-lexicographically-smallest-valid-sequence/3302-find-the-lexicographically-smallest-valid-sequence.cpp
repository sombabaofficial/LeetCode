class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
      int n = w1.size(), m = w2.size(), idx = n, k = 0;
      vector<int> res;
      res.reserve(m + 1);
      res.emplace_back(-1);
      while (k < m && w1[k] == w2[k]) res.emplace_back(k++);
      if (res.size() == m + 1) goto out;
      for (int i = k; i < n; ++i) {
        if (w1[i] != w2[res.size() - 1]) continue;
        res.emplace_back(i);
      }
      if (res.size() == m) idx = res.back() + 1;
      for (int i = n - 1, j = m - 1; i >= k; --i) {
        if (res.back() == i) res.pop_back();
        if (w1[i] != w2[j]) continue;
        if (res.size() + m - j == m && i - res.back() > 1) {
          idx = res.back() + 1;
        }
        if (--j < k) {
          break;
        }
      }
      if (idx == n) idx = k;
      res.erase(res.begin() + k + 1, res.end());
      for (int i = k; i < idx; ++i) {
        if (w1[i] != w2[res.size() - 1]) continue;
        res.emplace_back(i);
      }
      res.emplace_back(idx);
      for (int i = idx + 1; i < n; ++i) {
        if (w1[i] != w2[res.size() - 1]) continue;
        res.emplace_back(i);
      }
out:
    if (res.size() != m + 1) {
      return vector<int>();
    }
    res.erase(res.begin());
    return res;
  }
};