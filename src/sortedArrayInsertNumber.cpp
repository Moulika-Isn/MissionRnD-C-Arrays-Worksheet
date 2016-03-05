/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

void traverse(int s[], int len, int index)
{
	int i = 0;
	for (i = len; i > index; i--)
		s[i] = s[i - 1];
}
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i, index;
	if ((len < 1) || (Arr == NULL))
		return NULL;
	if (num < *Arr)
		index = 0;
	else if (num > *(Arr + len - 1))
		index = len;
	else
	{
		for (i = 0; i < len; i++)
		{
			if ((num>*(Arr + i)) && (num < *(Arr + i + 1)))
			{
				index = i + 1;
				break;
			}
		}
	}
	traverse(Arr, len, index);
	*(Arr + index) = num;
	return Arr;
}