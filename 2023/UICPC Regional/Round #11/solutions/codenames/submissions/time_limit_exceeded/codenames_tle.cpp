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

int next_board(const bool red_team, const int board_state,
               const vector<int>& indices, const int max_index) {
  const int winning_mask = red_team ? red_mask : blue_mask;
  int new_board_state = board_state;
  for (int i = 0; i < max_index; ++i) {
    int index = indices[i];
    new_board_state |= (1 << index);
    if ((winning_mask & (1 << index)) == 0) break;
    if (winning_mask == (winning_mask & new_board_state)) break;
  }
  return new_board_state;
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
      hint_to_k_to_odds[i].resize(remaining.size() + 1);
      if (remaining.empty()) continue;
      vector<int> indices = remaining;
      do {
        double factor = 1.0;
        for (int j = 1; j <= remaining.size(); ++j) {
          factor *= j;
        }
        for (int j = 1; j <= remaining.size(); ++j) {
          int nb = next_board(red_team, board_state, indices, j);
          double p = prob(!red_team, nb, hints);
          hint_to_k_to_odds[i][j] += (1.0 - p) / factor;
        }
      } while (next_permutation(indices.begin(), indices.end()));
    }
    result = 0.0;
    // int max_i, max_j;
    for (int i = 0; i < hint_to_k_to_odds.size(); ++i) {
      for (int j = 1; j < hint_to_k_to_odds[i].size(); ++j) {
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