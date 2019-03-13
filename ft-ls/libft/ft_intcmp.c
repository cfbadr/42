
#include "libft.h"
#include <stdio.h>
int     ft_intcmp(time_t nb1, time_t nb2, char *str1, char *str2)
{
//    printf("[%d] [%d]\n", (int)nb1, (int)nb2);
    if (nb1 < nb2)
        return (-1);
    else if (nb1 > nb2)
        return (1);
    if (ft_strcmp(str1, str2) < 0)
        return(1);
  //  printf("---------------\n");
    //sleep(1);
    return(-1);
}