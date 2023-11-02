#include <stdio.h>
#include <string.h>

int conn[500][500];
int nconn[500];
double prob[500], probtemp[500];
int N,L;
int walk[500];

void Walk(double* pd, double* ps)
{
	for(int i = 0; i < N; ++i)
	{
		pd[i] = 0;
		for(int j = 0; j < nconn[i]; ++j)
			pd[i] += ps[conn[i][j]] / nconn[conn[i][j]];
	}
	for(int i = 0; i < N; ++i)
		pd[i] = (2*pd[i] + ps[i])/3;
}

double abs(double x)
{
	return (x < 0 ? -x : x);
}

double max(double a, double b)
{
	return (a > b ? a : b);
}

int main()
{
	scanf("%d %d", &N, &L);
	for(int i = 0; i < L; ++i)
		scanf("%d", &walk[i]);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &nconn[i]);
		for(int j = 0; j < nconn[i]; ++j)
			scanf("%d", &conn[i][j]);
		prob[i] = 1.0/N;
	}

	int loops = 0;
	for(double diff = 1; diff > 1e-12;)
	{
		++loops;
		Walk(probtemp, prob);
		Walk(prob, probtemp);
		diff = 0;
		for(int i = 0; i < N; ++i)
			diff = max(diff, abs(prob[i] - probtemp[i]));
	}

	double ret = 0;
	for(int i = 0; i < L-1; ++i)
	{
		int curr = walk[i];
		int next = walk[i+1];

		ret += prob[curr]; // Same room
		// From now on, assume that the sentry wasn't here
		prob[curr] = 0;

		// Swapping (Sentry: walk[i+1] -> walk[i])
		ret += prob[next]/nconn[next];
		// From now on, assume that the sentry didn't walk this way
		// Walk one step
		for(int j = 0; j < N; ++j)
			probtemp[j] = prob[j];
		for(int j = 0; j < N; ++j) // Sentry destination
		{
			prob[j] = 0;
			for(int k = 0; k < nconn[j]; ++k)
			{
				int other = conn[j][k];
				if(j != curr || other != next) // Sentry didn't walk this way
					prob[j] += probtemp[other] / nconn[other];
			}
		}
	}
	ret += prob[walk[L-1]]; // Same room
	printf("%.6lf\n", 1-ret);
	return 0;
}
