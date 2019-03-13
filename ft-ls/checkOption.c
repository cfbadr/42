#include "ft_ls.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

static     int find_char_in_string(char *str, char c)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

static void    check_option2(t_option *opt,char **av, int i)
{
    if (opt->option_a == 0)
    {
        if (find_char_in_string(av[i], 'a') == 1)
            opt->option_a = 1;
    }
    if (opt->option_r == 0)
    {
        if (find_char_in_string(av[i], 'r') == 1)
            opt->option_r = 1;
    }
    if (opt->option_t == 0)
    {
        if (find_char_in_string(av[i], 't') == 1)
            opt->option_t = 1;
    }
}

int    check_option(t_option *opt, int ac, char **av)
{
    int i;
    
    i = 1;
    while (i < ac)
    {
        if (av[i][0] == '-')
        {
            if (opt->option_l == 0)
            {
                if (find_char_in_string(av[i], 'l') == 1)
                    opt->option_l = 1;
            }
            if (opt->option_R == 0)
            {
                if (find_char_in_string(av[i], 'R') == 1)
                    opt->option_R = 1;
            }
            check_option2(opt, av, i);
        }
        else
            break;
        i++;
    }
    return (i);
}

int    init_optVar(t_option *opt, int ac, char **av)
{
    opt->option_R = 0;
    opt->option_a = 0;
    opt->option_l = 0;
    opt->option_r = 0;
    opt->option_t = 0;
    return (check_option(opt, ac, av));
}