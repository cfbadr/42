#include "ft_ls.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

//date2 n° jour
//date 3 heure
//date 4 année



void    sortDate(struct s_list *elem)
{
    char    *tmp;
    int     check;
    int     check2;
    time_t  tmpDate;
    
    check = 0;
    while (check == 0)
    {
        while (elem->next->name != NULL)
        { // ici ca marhe pas du tout 
            //printf("[%s[%s%s\n", elem->date, elem->next->date, elem->name);
            if (ft_intcmp(elem->dateInt, elem->next->dateInt, elem->name, elem->next->name) == -1)
            {
               // printf("A l'entré [%s] [%s]\n", elem->name, elem->next->name);
            //    printf("[%d] [%d]\n", elem->dateInt, elem->next->dateInt);
                tmp = ft_strdup(elem->name);
                tmpDate = elem->dateInt;
                elem->name = ft_strdup(elem->next->name);
                elem->dateInt = elem->next->dateInt;
                elem->next->name = ft_strdup(tmp);
                elem->next->dateInt = tmpDate;
                check2 = 1;
            }
            elem = elem->next;
            //printf("ma date vaut [%d]\n", (int)elem->dateInt);
        }
         if (check2 == 0)
                check = 1;
            check2 = 0;
        elem = elem->next->next;
    }
 }


void    Sort_ascii(struct s_list *elem)
{
    char *tmp;
    int check;
    int check2;
    char *tmpDate;
    
    check = 0;
    while (check == 0) 
    {
        while (elem->next->name != NULL)
        {
            if (ft_strcmp(elem->name, elem->next->name) > 0)
            {
                tmp = ft_strdup(elem->name);
                tmpDate = ft_strdup(elem->date);
                elem->name = ft_strdup(elem->next->name);
                elem->date = ft_strdup(elem->next->date);
                elem->next->name = ft_strdup(tmp);
                elem->next->date = ft_strdup(tmpDate);
                check2 = 1;
            }
            elem = elem->next;
        }
         if (check2 == 0)
                check = 1;
            check2 = 0;
        elem = elem->next->next;
    }
}

void    sortSimpleAscii(struct s_list *elem)
{
    char *tmp;
    int check;
    int check2;
    
    check = 0;    
    while (check == 0) 
    {
        while (elem->next->name != NULL)
        {
            if (ft_strcmp(elem->name, elem->next->name) > 0)
            {
                tmp = ft_strdup(elem->name);
                elem->name = ft_strdup(elem->next->name);
                elem->next->name = ft_strdup(tmp);
                check2 = 1;
            }
            elem = elem->next;
        }
         if (check2 == 0)
                check = 1;
            check2 = 0;
        elem = elem->next->next;
    }
}