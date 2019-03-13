

char **fillCalender()
{
    char **calender;

    if ((calender = malloc(sizeof(char *) * 13)) == NULL)
        return (-1);
    calender[0] = ft_strdup("Jan");
    calender[1] = ft_strdup("Feb");
    calender[2] = ft_strdup("Mar");
    calender[3] = ft_strdup("Apr");
    calender[4] = ft_strdup("May");
    calender[5] = ft_strdup("Jun");
    calender[6] = ft_strdup("Jul");
    calender[7] = ft_strdup("Aug");
    calender[8] = ft_strdup("Sep");
    calender[9] = ft_strdup("Oct");
    calender[10] = ft_strdup("Nov");
    calender[11] = ft_strdup("Dec");
    calender[12] = NULL;
    return (calender);
}


int ft_strcmpDate(char *date, char *date2)
{
    char **calender;
    int i;
    int j;
    
    calender = fillCalender()
    while (i < 11)
        {
            if (ft_strcmp(date, calender[i]) == 0)
                break ;
        }
    while (j < 11)
      {
        if (ft_strcmp(date, calender[j]) == 0)
                break ;
        }
    if (i < j)
        return (-1);
    else if (i > j)
        return (1);
    return (0);
}
/*
static  int ask(char **date, char **date2)
{
    char *str;
    char *str2;
    
    str = ft_strsub(date[3], 3, 2);
    str2 = ft_strsub(date2[3], 3, 2); 
    (void)str;
    if (ft_intcmp(ft_atoi(date[4]), ft_atoi(date2[4])) > 0)
        return(1);
    else if (ft_intcmp(ft_atoi(date[4]), ft_atoi(date2[4])) < 0)
        return(-1);
    if (ft_cmpDate(date[1], date2[1] > 0)
        return (1);
    else if (ft_cmpDate(date[1], date2[1] < 0)
        //Fonction compare les mois retourne -1 si le premier et plus grand ou 0 ou 1
    if (ft_cmpDate(date[1], date2[1]))
    printf("[%s] [%s]\n",date[1], date2[3]);
    if (ft_intcmp(ft_atoi(date[2]), ft_atoi(date2[2])) > 0)
        return (1);
    else if (ft_intcmp(ft_atoi(date[2]), ft_atoi(date2[2])) < 0)
        return(-1);
    if (ft_strncmp(date[3], date2[3], 2) < 0)
        return (1);
    if (ft_strncmp(date[3], date2[3], 2) > 0)
        return (-1);
    if (ft_strcmp(str, str2) < 0)
        return(1);
    else if (ft_strcmp(str, str2) > 0)
        return(-1);
    str = ft_strsub(date[3], 6, 2);
    str2 = ft_strsub(date2[3], 6, 2); 
     if (ft_strcmp(str, str2) < 0)
        return(1);
    else if (ft_strcmp(str, str2) > 0)
        return(-1);
    return(0);
}
*/