#include "stdio.h"

void shift_bits(unsigned char* adr, int n, int shift)
{
	if ((n <= 0) || (shift <= 0))
		return;
	for (size_t i = 0; i < shift; ++i)
	{
		unsigned char last_one = (unsigned char) *(adr + n - 1) & 1;
		for (size_t j = n - 1; ; --j)
		{
			if (j == 0)	
			{
				*adr = *adr >> 1;
				if (last_one)
					*adr = *adr + (unsigned char)(1 << (sizeof(char) - 1));
				break;
			}
			else
			{
				unsigned char previous_one = (unsigned char) *(adr + j - 1) & 1;
				*(adr + j) = *(adr + j) >> 1;
				if (previous_one)
					*(adr + j) = *(adr + j) +  (unsigned char) (1 << (sizeof(char) - 1));
			}
		}
	}
}

int main (void)
{
	char *string = "asdfasdf";
	size_t len = strlen (string);
	unsigned char *pool = (unsigned char *) malloc (len);
	memcpy (pool, string, len);
	shift_bits (pool, len - 1, sizeof (char));		//shift for one char, \n untouched
	printf ("%s", (char *)pool);
	free (pool);
}
