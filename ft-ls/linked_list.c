#include "ft_ls.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <sys/stat.h> 
#include <unistd.h>
#include <time.h>

t_list *create_root()
{
    t_list *root;
    
    if ((root = malloc(sizeof(t_list))) == NULL)
        return (NULL);
    root->prev = root;
    root->next = root;
    root->name = NULL;
    return (root);
}

void    add_new_elem(struct s_list *elem, char *name)
{
    t_list  *newElem;
    
     if ((newElem = malloc(sizeof(t_list))) == NULL)
        return ;
    newElem->name = name;
    newElem->next = elem->next;
    newElem->prev = elem;
    elem->next->prev = newElem;
    elem->next = newElem;
}


void    addNewElemWithOption(struct s_list *elem, struct dirent *file)
{
    t_list  *newElem;
    struct  stat info;
    
    stat(file->d_name, &info);
    if ((newElem = malloc(sizeof(t_list))) == NULL)
        return ;
    newElem->name = ft_strdup(file->d_name);
    newElem->date = ft_strdup(ctime(&info.st_mtime));
    newElem->dateInt = info.st_mtime;
    newElem->next = elem->next;
    newElem->prev = elem;
    elem->next->prev = newElem;
    elem->next = newElem;
}