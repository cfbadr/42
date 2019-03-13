#include "ft_ls.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <sys/stat.h>
#include <time.h>

void    Makels(DIR *path, struct dirent *file, t_list **lk, t_option *opt)
{
     *lk = create_root();
    while ((file = readdir(path)) != NULL)
    {
        if (opt->option_l == 1 || opt->option_t == 1)
            addNewElemWithOption(*lk, file);
        else
            add_new_elem(*lk, file->d_name);
        *lk = (*lk)->next;
    }
    *lk = (*lk)->next->next;
    if (opt->option_t == 1)// coder la fonction de tri par Size
        sortDate(*lk);
    else if (opt->option_l == 1)
        Sort_ascii(*lk);
    else
        sortSimpleAscii(*lk);
    if (opt->option_l == 1)
        seeLsL(*lk, opt);
    else
        see_ls(*lk, opt);
    return;
}

void    Maksimplyls(DIR *path, struct dirent *file, t_list **lk, t_option *opt)
{
    *lk = create_root();
    path = opendir(".");
    while ((file = readdir(path)) != NULL)
    {
        add_new_elem(*lk, file->d_name);
        *lk = (*lk)->next;
    }
    *lk = (*lk)->next->next;
    sortSimpleAscii(*lk);
    see_ls(*lk, opt);
    return;
}


int main(int ac, char **av)
{
    t_option opt;
    t_list *linked_list;
    DIR *path;
    struct dirent *file;
    t_garbage       garb;
    
    garb.check2 = 0;
    path = NULL;
    file = NULL;
    if (ac == 1)
    {
        Maksimplyls(path, file, &linked_list, &opt);
        return (0);
    }
    garb.check = init_optVar(&opt, ac, av);
    checkFile(ac, garb.check, av);
    while (garb.check < ac)
    {
        printf("[%s]\n", Make_path(av[garb.check]));
        if ((path = opendir(Make_path(av[garb.check]))) != NULL)
            Makels(path, file, &linked_list, &opt);
        garb.check++;
        if (garb.check != ac)
            ft_putchar('\n');
        garb.check2 = 1;
    }
    if (garb.check2 == 0)
        Makels(opendir("."), file, &linked_list, &opt);
    return (0);
}