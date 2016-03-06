/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

int isDuplicate(int s[], int n, int ele)
{
	int x;
	for (x = 0; x < n; x++)
	{
		if (s[x] == ele)
			return 1;
	}
	return 0;
}
int removeArrayDuplicates(int *Arr, int len)
{
	int i, x = 1, m = 1;
	int b[100];
	
	if ((len < 1) || (Arr == NULL))
		return -1;
	else
	{
		b[0] = *Arr; 
		for (i = 1; i < len; i++)
		{
			if (!(isDuplicate(b, x, *(Arr + i))))
			{
				*(Arr + m) = *(Arr + i);
				b[x++] = *(Arr + i);
				m++;
			}
		}
	}
	return m;
}
