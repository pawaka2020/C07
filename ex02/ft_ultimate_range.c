#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	len = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = (int*)malloc(sizeof(int) * len);
	i = 0;
	while (min < max)
	{
	  //because *range[i] = min is forbidden
    range[0][i] = min;
		i++;
		min++;
	}
	return (len);
}
#include <stdio.h>
int main(void)
{
  int **range;
  
  int x = ft_ultimate_range(range, 1, 10);
  int i = 0;
  while (range[i])
  {
    printf("%d", *range[i]);
    i++;
  }
  printf("\n");
  printf("%d\n", x);
}