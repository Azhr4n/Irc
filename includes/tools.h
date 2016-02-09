/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 16:32:19 by pivanovi          #+#    #+#             */
/*   Updated: 2015/11/17 16:32:19 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

typedef struct		s_list
{
	struct s_list	*next;
	char			*data;
}					t_list;

/*
***ft_atoi.c
*/
int					ft_atoi(char *str);

/*
***strings.c
*/
int					ft_strlen(char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, int size);
void				ft_print(char *str, int fd);
void				ft_bzero(char *str, int size);

/*
***strings2.c
*/
char				**ft_split(char *s1);
int					ft_table_len(char **tab);
char				*ft_strcpy(char *dest, char *src);

/*
***strings3.c
*/
char				*ft_strncpy(char *dest, char *src, int n);
char				*ft_strcat(char *dest, char *src);
char				*ft_strdup(char *src);
void				ft_strcpynon(char *dest, char *src);
void				free_tab_2d(char **tab);

/*
***list.c
*/
t_list				*create_elem(char *data);
void				list_push_back(t_list **list, char *data);
void				list_remove(t_list **list, char *data);
int					is_in_list(t_list *list, char *data);
t_list				*list_last_elem(t_list *list);

/*
***list2.c
*/
int					size_of_list(t_list *list);

#endif
