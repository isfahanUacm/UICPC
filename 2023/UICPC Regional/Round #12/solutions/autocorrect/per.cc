#include <bits/stdc++.h>

struct trie {
  trie *next[26];
  int aut_len;
  char aut_sym;

  trie(): aut_len(-1), aut_sym(0) { memset(next, 0, sizeof(next)); }

  trie *get_next(char c) {
    return next[c-'a'] ? next[c-'a'] : NULL;
  }
  
  void add(const char *s) {
    if (*s) {
      if (!next[*s-'a']) next[*s-'a'] = new trie();
      next[*s-'a']->add(s+1);
    }
    if (aut_len == -1) {
      aut_len = *s ? next[*s-'a']->aut_len + 1 : 0;
      aut_sym = *s;     
    }
  }
};

char buf[1<<24];
trie *seq[1<<24];
int opt[1<<24];

int solve(const char *word, trie *t) {
  int L = 0;
  for ( ; word[L] && t; seq[L] = t, t = t->get_next(word[L++]));
  opt[L] = strlen(word)-L;
  for (int i = L-1, nxtb = L; i >= 0; --i) {
    opt[i] = 1 + opt[i+1];
    if (!i || seq[i]->aut_sym != word[i])
      nxtb = i;
    else
      opt[i] = std::min(opt[i], 1 + seq[i]->aut_len - (nxtb-i) + opt[nxtb]);
  }
  return opt[0];
}

int main(void) {
  int n, m;
  trie *t = new trie;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    t->add(buf);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%s", buf);
    printf("%d\n", solve(buf, t));
  }
}
