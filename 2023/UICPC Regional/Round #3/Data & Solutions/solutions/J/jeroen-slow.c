/* 
 * @EXPECTED_RESULTS@: TIMELIMIT
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXN 50

struct node {
	struct node *next, *prev;
	int a;
} *begin, nodes[MAXN];

void delete(struct node *node) {
	if(node->prev)
		node->prev->next = node->next;
	if(node->next)
		node->next->prev = node->prev;
}

void addbefore(struct node *other, struct node *node) {
	node->prev = other->prev;
	if(node->prev)
		node->prev->next = node;
	node->next = other;
	other->prev = node;
	if(other == begin)
		begin = node;
}

int main() {
	int t;
	scanf("%d\n", &t);
	while(t--) {
		int i, n;
		struct node *cur;
		uint64_t ret = 0;
		scanf("%d\n", &n);
		for(i = 0; i < n; i++) {
			scanf("%d",&nodes[i].a);
			nodes[i].prev = i > 0     ? &nodes[i-1] : NULL;
			nodes[i].next = i < n - 1 ? &nodes[i+1] : NULL;
		}
		begin = &nodes[0];
		cur = begin;
		while(cur) {
			if(cur->next && cur->next->a < cur->a) {
				cur = cur->next;
				delete(cur);
				addbefore(begin,cur);
				ret++;
			} else cur = cur->next;
		}
		printf("%llu\n", ret);
	}
	return 0;
}
