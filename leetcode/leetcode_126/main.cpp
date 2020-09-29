#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
  unordered_set<string> S; // 判断单词是否在wordList中的hash表
  unordered_map<string, int> dist; // 保存到起点的距离
  queue<string> q; // bfs计算所有节点到起点的距离
  vector<vector<string>> ans; // dfs收集路径
  vector<string> path; // dfs记录路径
  string beginWord;

  vector<vector<string>> findLadders(string _beginWord, string endWord, vector<string>& wordList) {
    for (auto word: wordList) S.insert(word);
    beginWord = _beginWord;
    dist[beginWord] = 0;
    q.push(beginWord);
    while (q.size()) {
      auto t = q.front();
      q.pop();

      string r = t;
      for (int i = 0; i < t.size(); i++) {
	t = r;
	for (char j  = 'a'; j <= 'z'; j++) {
	  t[i] = j;
	  if (S.count(t) && dist.count(t) == 0) {
	    dist[t] = dist[r] + 1; // t到起点的距离，所以后面是从终点开始搜
	    if (t == endWord) break;
	    q.push(t);
	  }
	}
      }
    }
    
    if (dist.count(endWord) == 0) return ans;
    path.push_back(endWord);
    dfs(endWord);
    return ans;
  }

  void dfs(string t) {
    if (t == beginWord) {
      reverse(path.begin(), path.end());
      ans.push_back(path);
      reverse(path.begin(), path.end());
    } else {
      string r = t;
      for (int i = 0; i < t.size(); i++) {
	t = r;
	for (char j = 'a'; j <= 'z'; j++) {
	  t[i] = j;
	  if (dist.count(t) && dist[t] + 1 == dist[r]) {
	    path.push_back(t);
	    dfs(t);
	    path.pop_back();
	  }
	}
      }
    }
  }
};
