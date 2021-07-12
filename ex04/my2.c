#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char* print(int *sign, int *nbr3, char *base, int i)
{
  int x;

  x = 0;
  char *res;
  if (*sign == -1)
  {
    res = malloc(i+2);
    res[0] = '-';
    x++;
  }
  else
  {
    res = malloc(i+1);
  }
  while (i > -1)
  {
    res[x] = base[nbr3[i]];
    x++;
    i--;
  }
  return (res);
}

void setbaselen(int *baselen, char *base)
{
  int j;

  j = 0;
  *baselen = 0;
  while(base[*baselen])
  {
    if ((base[*baselen] == base[j]) && (*baselen != j))
    {
      return;
    }
    else if ((base[*baselen] == '+') || (base[*baselen] == '-'))
    {
      return;
    }
    j++;
    if (base[j] == '\0')
    {
      j = 0;
      *baselen = *baselen + 1;
    }
  }
}

void adjustsign(int *sign, int *nbr)
{
  if (*nbr < 0)
  {
    *nbr = *nbr * -1;
    *sign = -1;
  }
}

char	*fromdecimal(int nbr, char *base)
{
  char *result;
  int baselen;
  int sign;
  int i;
  
  adjustsign(&sign, &nbr);
  setbaselen(&baselen, base);
  if (baselen != 0)
  {
    int nbr3[baselen * sizeof(int)];

    i = -1;
    while (i++, nbr != 0)
    {
      nbr3[i] = nbr % baselen;
      nbr = nbr / baselen;
    }
    result = print(&sign, nbr3, base, (i -1));
  }
  return (result);
}

int main(void)
{
  printf("%s\n", fromdecimal(-5, "0123456789"));
}