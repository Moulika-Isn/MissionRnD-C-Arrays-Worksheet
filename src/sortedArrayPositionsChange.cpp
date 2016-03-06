
/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
void find(int s[], int n, int *x, int *y)
{
	int i, z = 1, j;
	for (i = n-1; i > 0; i--)
	{
		if (s[i] < s[i - 1])
		{
			j = i - 1;
			while (j >= 0 && s[i] < s[j])
				j--;
			*x = i;
			*y = j + 1;
			break;
		}
	}

}
void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i, x, y, c = 0;
	if ((Arr == NULL) || (len < 1))
		return NULL;
	else
	{
		for (i = 0; i < len - 1; i++)
		{
			if (*(Arr + i) > *(Arr + i + 1))
			{
				c = 1;
				break;
			}
		}
		if (c == 0)
			return Arr;
		else
		{
			if ((*Arr > *(Arr + 1)) && (*(Arr + len - 2) > (*(Arr + len - 1))))
			{
				x = 0;
				y = len - 1;
			}
			else
			{
				find(Arr, len, &x, &y);
			}
			swap((Arr + x), (Arr + y));
			return Arr;
		}
	}
}