#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, double> state_to_prob;
int assassin_mask = 0;
int red_mask = 0;
int blue_mask = 0;

int compute_state(const bool red_team, const int board_state) {
  return (board_state << 1) + (int)red_team;
}

int game_ends(const bool red_team, const int board_state) {
  if ((assassin_mask & board_state) != 0) {
    return 1;
  }
  if (red_mask == (red_mask & board_state)) {
    return red_team ? 1 : -1;
  }
  if (blue_mask == (blue_mask & board_state)) {
    return red_team ? -1 : 1;
  }
  return 0;
}

vector<int> compute_remaining(const int board_state, const vector<int>& hints) {
  vector<int> remaining;
  for (int i = 0; i < hints.size(); ++i) {
    if ((board_state & (1 << hints[i])) == 0) {
      remaining.push_back(hints[i]);
    }
  }
  return remaining;
}

bool turn_ends(const bool red_team, const int index, int* board_state) {
  const int winning_mask = red_team ? red_mask : blue_mask;
  (*board_state) |= (1 << index);
  return ((winning_mask & (1 << index)) == 0) ||
         (winning_mask == (winning_mask & (*board_state)));
}

double prob(const bool red_team, const int board_state,
            const vector<vector<int> >& hints);

void dfs(const vector<vector<int> >& hints, const vector<int>& remaining,
         const bool red_team, const int board_state, const int j, double factor,
         vector<bool>* visited, vector<double>* k_to_odds) {
  if (j == remaining.size()) return;
  factor *= (remaining.size() - j);
  for (int i = 0; i < remaining.size(); ++i) {
    const int index = remaining[i];
    if ((*visited)[index]) continue;
    (*visited)[index] = true;
    int nb = board_state;
    const bool ends =
        turn_ends(red_team, index, &nb) || (j + 1 == remaining.size());
    const double p = prob(!red_team, nb, hints);
    (*k_to_odds)[j] += (1.0 - p) / factor;
    if (!ends) {
      dfs(hints, remaining, red_team, nb, j + 1, factor, visited, k_to_odds);
    } else {
      int k = j + 1;
      while (k < remaining.size()) {
        (*k_to_odds)[k] += (1.0 - p) / factor;
        ++k;
      }
    }
    (*visited)[index] = false;
  }
}

double prob(const bool red_team, const int board_state,
            const vector<vector<int> >& hints) {
  int state = compute_state(red_team, board_state);
  if (state_to_prob.find(state) != state_to_prob.end()) {
    return state_to_prob.at(state);
  }
  double result;
  int game_result = game_ends(red_team, board_state);
  if (game_result != 0) {
    result = (game_result == 1) ? 1.0 : 0.0;
  } else {
    vector<vector<double> > hint_to_k_to_odds(hints.size());
    for (int i = 0; i < hints.size(); ++i) {
      vector<int> remaining = compute_remaining(board_state, hints[i]);
      hint_to_k_to_odds[i].resize(remaining.size());
      if (remaining.empty()) continue;
      vector<bool> visited(remaining.size());
      dfs(hints, remaining, red_team, board_state, 0, 1.0, &visited,
          &(hint_to_k_to_odds[i]));
    }
    result = 0.0;
    // int max_i, max_j;
    for (int i = 0; i < hint_to_k_to_odds.size(); ++i) {
      for (int j = 0; j < hint_to_k_to_odds[i].size(); ++j) {
        // if (hint_to_k_to_odds[i][j] > result) {
        //   result = hint_to_k_to_odds[i][j];
        //   max_i = i;
        //   max_j = j;
        // }
        result = max(result, hint_to_k_to_odds[i][j]);
      }
    }
    // cout << "max_i: " << max_i << " max_j: " << max_j << endl;
  }
  // cout << (red_team ? "R" : "B") << " " << bitset<6>(board_state) << " " <<
  // result << endl;
  state_to_prob.insert(make_pair(state, result));
  return result;
}

int main() {
  int n, m;
  string team;
  cin >> n >> team;
  unordered_map<string, int> word_to_index;
  for (int i = 0; i < n; ++i) {
    string word;
    cin >> word;
    word_to_index.insert(make_pair(word, i));
  }
  vector<string> word_team;
  for (int i = 0; i < n; ++i) {
    string team;
    cin >> team;
    word_team.push_back(team);
  }
  cin >> m;
  vector<vector<int> > hints(m);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      string word;
      cin >> word;
      int index = word_to_index.at(word);
      hints[i].push_back(index);
    }
    sort(hints[i].begin(), hints[i].end());
  }
  state_to_prob.clear();
  for (int i = 0; i < word_team.size(); ++i) {
    if (word_team[i] == "A") {
      assassin_mask |= (1 << i);
    }
    if (word_team[i] == "R") {
      red_mask |= (1 << i);
    }
    if (word_team[i] == "B") {
      blue_mask |= (1 << i);
    }
  }

  cout << fixed << setprecision(4) << prob(team == "R", 0, hints) << endl;
  return 0;
}