#include <stdlib.h>

int		ft_seplen(int size, char *sep)
{
	int i;

	i = 0;
	while (sep[i])
	{
		i++;
	}
	return (i * (size - 1));
}

int		ft_strlen(int size, char **strs)
{
	int letter;
	int i;
	int j;

	letter = 1;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[j])
		{
			letter++;
			j++;
		}
		i++;
	}
	return (letter);
}

char	*ft_strcat(int size, char *join, char **strs, char *sep)
{
  int i;
  int j;
  int k;

  i = 0;
  j = 0;
  k = 0;
  while (i < size)
  {
    while (strs[i][j])
    {
      join[k] = strs[i][j];
      k++;
      j++;
    }
    i++;
    j = 0;
    if (size - i > 0)
    {
      while (sep[j])
      {
        join[k] = sep[j];
        k++;
        j++;
      }
    }
    j = 0;
  }
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
  char	*join;
  
  if (size == 0)
	{
		join = (char *)malloc(sizeof(char));
		return (join);
	}
  join = malloc(1 + ft_strlen(size, strs) + ft_seplen(size, sep));
	if (!join)
		return (NULL);
	join[0] = '\0';
  
  join = ft_strcat(size, join, strs, sep);
  return (join);
}
/*
#include <stdio.h>
int main(void)
{
  char *strs[] = {"H13242", "Hihi", "Hxvxuhu", "jasdasd", "Hsda", "HSSDS", "122fhsh", "lala", "lili", "lulu"};
  char *sep = ", ";

  printf("%s\n", ft_strjoin(5, strs, sep));
}
*/