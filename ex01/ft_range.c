#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	if (min >= max)
		return (0);
	range = malloc(sizeof(int) * (max - min));
  
	i = 0;
	while (min < max)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
#include <stdio.h>
int main(void)
{
  int *range  = ft_range(1, 10);
  int i = 0;
  while (range[i])
  {
    printf("%d", range[i]);
    i++;
  }
  printf("\n");
}



//to allocate space of an array, just copy the array size 
//malloc(sizeof(*src));
//to allocate space for a number of variables, sizeof(variabletype) * number of variables
//sizeof(int) * (max - min)