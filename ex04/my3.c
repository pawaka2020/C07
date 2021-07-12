#include <stdlib.h>
#include <unistd.h>

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