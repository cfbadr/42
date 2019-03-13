#include "ft_ls.h"

char *Make_path(char *str)
{
    char *str2;
    
    if (ft_strncmp(str, "../", 2) == 0)
        str2 = ft_strdup("");
    else
        str2 = ft_strdup("./");
    str2 = ft_strjoin(str2, str);
    return (str2);
}