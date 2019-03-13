/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 08:32:47 by bchoukri          #+#    #+#             */
/*   Updated: 2015/06/11 14:38:53 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_1_H
# define SH_1_H
# include <unistd.h>

typedef	struct	s_list
{
	char		**env;
}				t_list;

int				my_epur(char *str);
int				find_pos(t_list *var, char *str);
int				find_bultins(char *str);
int				looking_for_path(t_list *var, char ***tab_path, char *line);
void			execute_cmd(t_list *var, char **ta_pa, char **t_li, int pos_pa);
void			make_env(t_list *var);
char			**execute_bultins(t_list *var, char **tab_line, int bultins_nb);
void			make_cd(t_list *var, char **tab_line);
char			**make_setenv(t_list *var, char *str, char *str2);
char			**make_unsetenv(t_list *var, char *str);
void			make_env(t_list *var);
char			**erase_line_env(t_list **var, int pos);
char			**new_line_env(t_list **var, char *str);
void			error(char *command);
char			**copy_env(char **env);
void			ft_block_sign(void);
void			ft_minishell(t_list *var, int bultins);
int				no_file_or_previous_file(t_list *var, char *str);
void			quit();
void			ft_exit(char **tab);
void			free_double_tabv2(t_list *var);
void			init(int *j, int *i);

#endif
