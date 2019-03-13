

#ifndef FT_LS_H
# define FT_LS_H
#include <sys/stat.h>
#include <unistd.h>

typedef struct s_option
{
    int option_l;
    int option_R;
    int option_a;
    int option_t;
    int option_r;
}               t_option;

typedef struct s_garbage
{
    int     check;
    int     check2;
}               t_garbage;

typedef struct  s_list
{
    struct s_list *prev;
    struct s_list *next;
    char    *date;
    time_t  dateInt;
    char    *name;
}               t_list;

#include "ft_ls.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"


int     check_option(t_option *opt, int ac, char **av);
int     init_optVar(t_option *opt, int ac, char **av);
t_list  *create_root();
void    add_new_elem(struct s_list *elem, char *name);
void    Maksimplyls(DIR *path, struct dirent *file, t_list **lk, t_option *opt);
void    Sort_ascii(struct s_list *elem);
void    see_ls(struct s_list *lk, t_option *opt);
void    Check_file(int ac, int nb, char **av);
void    add_new_elem_with_option(struct s_list *elem, struct dirent *file);
void    ft_error(int nb);
void    print_type(mode_t protection);
void    see_lsl(struct s_list *lk, t_option *opt);
void    sort_date(struct s_list *elem);
void    sort_simple_ascii(struct s_list *elem);
char    *Make_path(char *str);

#endif