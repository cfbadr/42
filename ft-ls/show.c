#include "ft_ls.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <sys/stat.h> 
#include <pwd.h>
#include <grp.h>
#include <time.h>

static void printRight(mode_t protection)
{
    ft_putchar(protection & S_IRUSR ? 'r' : '-');
    ft_putchar(protection & S_IWUSR ? 'w' : '-');
    ft_putchar(protection & S_IXUSR ? 'x' : '-');
    ft_putchar(protection & S_IRGRP ? 'r' : '-');
    ft_putchar(protection & S_IRGRP ? 'w' : '-');
    ft_putchar(protection & S_IRGRP ? 'x' : '-');
    ft_putchar(protection & S_IROTH ? 'r' : '-');
    ft_putchar(protection & S_IROTH ? 'w' : '-');
    ft_putchar(protection & S_IROTH ? 'x' : '-');
}

void   printType(mode_t protection)
{
    char c;
    
    c = '?';
    c = S_ISDIR(protection) ? 'd' : c;
    c = S_ISREG (protection) ? '-': c;
    c = S_ISCHR(protection) ? 'c' : c;
    c = S_ISBLK(protection) ? 'b' : c;
    c = S_ISLNK(protection) ? 'l' : c;
    c = S_ISFIFO(protection) ? 'p' : c;
    c = S_ISSOCK(protection) ? 's': c;
    write(1, &c, 1);
    printRight(protection);
    ft_putchar(' ');
}

static  void makeBlanc(int st_nlink, int st_size)
{
    if (st_nlink != -1)
    {
    if (st_nlink > 9999)
	    ft_putstr("");
	else if (st_nlink > 999)
		ft_putstr(" ");
    else if (st_nlink > 99)
	    ft_putstr("  ");
	else if (st_nlink > 9)
		ft_putstr("   ");
	else if(st_nlink <= 9)
		ft_putstr(" ");
		return ;
    }
	if (st_size > 9999)
    	ft_putstr("  ");
	else if (st_size > 999)
		ft_putstr("   ");
	else if (st_size > 99)
		ft_putstr("    ");
	else if (st_size > 9)
		ft_putstr("     ");
	else 
		ft_putstr("      ");
}

void    printOption2(nlink_t st_nlink, uid_t st_uid, gid_t st_gid, off_t st_siz)
{
    struct passwd	*owner;
	struct group	*group;

	owner = getpwuid(st_uid);
	group = getgrgid(st_gid);
    ft_putnbr((int)st_nlink);
    makeBlanc((int)st_nlink, 0);
	if (owner != NULL && group != NULL)
	{
		ft_putchar(' ');
		ft_putstr(owner->pw_name);
		ft_putchar(' ');
		ft_putstr(group->gr_name);
	}
	makeBlanc(-1, (int)st_siz);
    ft_putnbr((int)st_siz);
}

void    printDate(char *date)
{
    char **timeLs;
    
    timeLs = ft_strsplit(date, ' ');
    ft_putchar(' ');
    ft_putstr(timeLs[1]);
    ft_putchar(' ');
    ft_putstr(timeLs[2]);
    ft_putchar(' ');
    ft_putstr(ft_strsub(timeLs[3], 0, 5));
    ft_putchar(' ');
}

void    seeLsL(struct s_list *lk,t_option *opt)
{
    struct stat info;

    if (opt->option_r == 1)
        lk = lk->prev->prev;
     while (lk->name != NULL)
    {
        if (lk->name[0] != '.' || opt->option_a == 1)
        {
           // printf("[%s]\n", lk->name);
           //printf("Ici lk->name vaut [%s]\n", lk->name);
            if (stat(lk->name, &info) == -1)
                printf("Error\n");
//                ft_error(1);
            //printf("[Name:%s Date:%s][Name:%s Date:%s]\n", lk->name, ctime(&lk->dateInt), lk->name, ctime(&info.st_mtime));
            printType(info.st_mode);
            printOption2(info.st_nlink, info.st_uid, info.st_gid, info.st_size);
            printDate(ctime(&lk->dateInt));
            ft_putendl(lk->name);
        }
        if (opt->option_r == 1)
            lk = lk->prev;
        else
            lk = lk->next;
    }
}

void    see_ls(struct s_list *lk, t_option *opt)
{
    if (opt->option_r == 1)
        lk = lk->prev->prev;
    while (lk->name != NULL)
    {
        if (lk->name[0] != '.')
            ft_putendl(lk->name);
        if (opt->option_r == 1)
            lk = lk->prev;
        else
            lk = lk->next;
    }
}

void    ft_error(int nb)
{
    if (nb == 1)
    {
        ft_putstr("La permission de parcours est refusée pour un des ");
        ft_putendl("répertoires contenu dans le chemin path");
      //  exit(-1);
    }
}

void    checkFile(int ac, int nb, char **av)
{
    while (nb < ac)
    {
        if (opendir(av[nb]) == NULL)
            {
                ft_putstr("ls: cannot access ");
                ft_putstr(av[nb]);
                ft_putendl(": No such file or directory");
            }
        nb++;
    }
}