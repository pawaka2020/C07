#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(*src));
	if (copy == NULL) return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may subsequently be used as an argument to the function free(3).
If insufficient memory is available, NULL is returned and errno is set to ENOMEM. The strndup() function copies at most n characters from the string s1 always NUL terminating the copied string.
---
Create copy of str
malloc memory same to the size of src
copy contents of src to copy
return copy
*/