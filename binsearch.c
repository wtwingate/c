#include <stdio.h>

#define VSIZE 1000

int binsearch(int x, int v[], int n);

int main(void)
{
	int num;
	int res;
	int vector[VSIZE];
	
	for (int i = 0; i < VSIZE; i++)
		vector[i] = i + 1;

	printf("What number are you searching for? ");
	scanf("%d", &num);

	if ((res = binsearch(num, vector, VSIZE)) != -1)
		printf("Found at index %d.\n", res);
	else
		printf("Not found.\n");

	return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else  /* found match */
			return mid;
	}
	return -1;  /* no match */
}
