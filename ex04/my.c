#include <stdlib.h>
#include <stdio.h>
char	*fromdecimal(int nbr, char *base);
char* print(int *sign, int *nbr3, char *base, int i);
void setbaselen(int *baselen, char *base);
void adjustsign(int *sign, int *nbr);
char	*fromdecimal(int nbr, char *base);

int isnumber(char c)
{
  if ((c > 47) &&(c < 58))
  {
    return (1);
  }
  else
  {
    return (0);
  }
}

int afternumbers(char c, char d, int i)
{
  if (!isnumber(c) && isnumber(d) && i >0 )
  {
    return (1);
  }
  else
  {
    return (0);
  }
}

int ft_atoi(char *str)
{
  int i;
  int sign;
  int res;

  i = 0;
  sign = 1;
  res = 0;
  while (str[i] && i != -1)
  {
    if (str[i] == '-')
    {
      sign = -1;
    }
    else if (isnumber(str[i]))
    {
      res = (res * 10) + (str[i] -'0');
    }
    else if (afternumbers(str[i], str[i - 1], i))
    {
      i = -2;
    }
    i++;
  }
  return (res * sign);
}

int todecimal(int nbr, char *base_from)
{
  int res;
  int sign;
  int multiplier;
  int divider;
  int length;
  int i;

  multiplier = 1;
  divider = 1;
  length = 0;
  i = 0;
  res = 0;
  sign = 1;
  if (nbr < 0)
  {
    sign = -1;
    nbr = nbr * -1;
  }
  while (base_from[i])
  {
    length++;
    i++;
  }
  i = 0;
  while (nbr / divider > 1)
  {
    divider *=10;
    i++;
  }
  while(i > 0)
  {
    multiplier *= length;
    i--;
  }
  while (divider > 0)
  {
    res = res + ((nbr/divider) * multiplier);
    nbr = nbr - ((nbr / divider) * divider);
    multiplier = multiplier / length;
    divider = divider / 10;
  }
  return (res * sign);
}







char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
  char *res;
  char *temp;
  
  //todecimal(ft_atoi(nbr), base_from);

  fromdecimal(todecimal(ft_atoi(nbr), base_from), base_to);

  //malloc res;

  //res = nbr;
  return (res);
}

int main(void)
{
  char *str = ft_convert_base("   +-+--+--10101010", "OI", "aieou");
  printf("%s\n", str);
}