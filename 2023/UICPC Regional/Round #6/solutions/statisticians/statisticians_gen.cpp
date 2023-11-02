#include <stdio.h>
#include <stdlib.h>

#define VerifyInput(x) DoVerifyInput(x, #x)

void DoVerifyInput(bool test, const char* expression)
{
	if(!test)
	{
		fprintf(stderr, "Erroneous input: %s\n", expression);
		exit(1);
	}
}

int GenerateNum(int mi, int ma)
{
	int num = (rand() << 15) | (rand() % 0xffff);
	return mi + (num % (ma-mi+1));
}

bool AreaExists(int h, int w, int minArea, int maxArea)
{
	for(int y = 1; y <= h; ++y)
	{
		for(int x = 1; x <= w; ++x)
		{
			if(x*y >= minArea && maxArea <= maxArea)
				return true;
		}
	}
	return false;
}

int main()
{
	int seed;
	fprintf(stderr, "Seed: ");
	scanf("%d", &seed);
	srand(seed);

	int h, w, minArea, maxArea, minSquare, maxSquare;

	fprintf(stderr, "Height, width: ");
	scanf("%d %d", &h, &w);
	fprintf(stderr, "Area (min, max): ");
	scanf("%d %d", &minArea, &maxArea);
	fprintf(stderr, "StatPerSquare (min, max): ");
	scanf("%d %d", &minSquare, &maxSquare);

	VerifyInput(1 <= h && h <= 140);
	VerifyInput(1 <= w && w <= 120);
	VerifyInput(1 <= minArea && minArea <= maxArea && maxArea <= h*w);
	VerifyInput(0 <= minSquare && minSquare <= maxSquare && maxSquare <= 10000);
	VerifyInput(AreaExists(h, w, minArea, maxArea));

	printf("%d %d\n", h, w);
	printf("%d %d\n", minArea, maxArea);
	// Fill in img
	for(int y = 0; y < h; ++y)
	{
		printf("%d", GenerateNum(minSquare, maxSquare));
		for(int x = 1; x < w; ++x)
			printf(" %d", GenerateNum(minSquare, maxSquare));
		printf("\n");
	}
	return 0;
}
