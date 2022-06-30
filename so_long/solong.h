/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:01:30 by buozdemi          #+#    #+#             */
/*   Updated: 2022/06/20 13:39:40 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# define BUFFER_SIZE 42
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./mlx/mlx.h"
# include "./ftprintf/ft_printf.h"

typedef struct s_map
{
	char	**line;
	void	*mlx;
	void	*win;
	void	*bellick;
	void	*scofield;
	void	*wall;
	void	*escape;
	void	*scob;
	void	*scorig;
	void	*scolef;
	void	*b;
	int		i;
	int		m;
	int		totalc;
	int		existc;
	int		imgident;
	int		fd;
	size_t	step;
}	t_map;

char			*ft_get_line(char *save);
char			*ft_save(char *save);
char			*ft_read_and_save(int fd, char *save, t_map *map);
int				has_return(char *str);
char			*get_next_line(int fd, t_map *map);
char			*ft_strjoingnl(char *s1, char const *s2);
size_t			ft_strlengnl(const char *s);
void			ctrltopbot(t_map *map);
void			ctrlecp(char *s, char *set, t_map *map);
void			checkmap(t_map *map);
void			read_map(t_map *map);
int				main(int argc, char **argv);
void			free_map(t_map *map, int i);
void			extension(t_map *map, char *berfile);
int				ft_ctrlinwall(char *s1, char *set);
int				ft_midarea(char *s1);
char			**ft_split(char *s, char c);
int				ft_strchrnew(const char *s, int c);
char			*ft_strdup(char *s1);
size_t			ft_strlen(char *s);
size_t			ft_strlenline(char **s);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
void			*ft_memset(void *b, int c, size_t len);
void			quadrictl(t_map *map);
int				satirsaydir(char *berfile);
void			free_map_work(t_map *map);
void			mapwrite(t_map *map);
void			whpicturewr(t_map *map, char c, int i, int m);
void			key_press_r(t_map *a);
void			key_press_l(t_map *a);
void			key_press_u(t_map *a);
void			key_press_d(t_map *a);
int				whtouch(int keycode, void *p);
void			cnumber(char *lines, t_map *map);
void			earlyfree(t_map *map);
void			onlyp(char *lines, t_map *map);
void			fillvalue(t_map *map);
void			read_map2(t_map *map, char *lines);
void			doorandexitfree(t_map *map);
void			fillvaluereal(t_map *map);
void			parttwofree(t_map *map);

#endif
