#include <cstdio>
#include <cstdint>

int main()
{
	uint8_t	n = 151;
	printf("151 as binary : ");
	for (int i = 0; n; i++)
	{
		printf("%d ", n & 1);
		n >>= 1;
	}
	printf("\n");

	n = 151;
	uint32_t result = 0;
	uint32_t addend = 1;
	uint32_t idx = 1;

	while (idx < 256)
	{
		if (idx & n)
			result += addend;
		addend *= 2;
		idx <<= 1;
	}
	printf("Double and add from LSB to MSB : %d \n", result);


	n = 151;
	result = 0;
	idx = 256;
	while (idx > 1)
	{
		result *= 2;
		idx >>= 1;

		if (idx & n)
			result += 1;
	}

	printf("Double and add from MSB to LSB : %d \n", result);
	return 0;
}