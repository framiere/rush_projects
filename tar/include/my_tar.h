/*
** my_tar.h for my_tar in /home/rigaud_b/rendu/Rush1/step_3/include
** 
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
** 
** Started on  Sat Jan  9 18:45:36 2016 Matthias RIGAUD
** Last update Sun Jan 10 05:56:20 2016 Matthias RIGAUD
*/

#ifndef MY_TAR_H_
# define MY_TAR_H_

/*
** Include
*/

#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <utime.h>
#include <fcntl.h>
#include <time.h>

/*
** struct && typedef
*/

typedef	struct stat	t_stt;

typedef struct dirent   t_dir;

typedef struct utimbuf	t_tim;

typedef struct	s_file
{
  char		*name;
  char		*content;
  int		size;
  char		*right;
  char		*time;
}		t_file;

typedef struct	s_i
{
  char          *inf;
  char          *size;
  char          *perm;
  char          *time;
  char          *name;
}               t_i;

/*
** Function
*/

void	my_puterror(char *str, int type);
int	power(int nb, int pow);
int	stlen(char *str);
int	gtnb(char *str);
void    write_file(t_file *f);
void    read_archive(int fd, int v);
void    my_unarchive(char *namear, int v);
void    algo(char *file, t_stt *sb, int fdp, int nb_slash);
char    *stopen(char *file, t_stt *sb);
char    *info(char *file, t_stt *sb);
int     my_strcmp(char *s1, char *s2);
int     prep_str(char *str);
char    *add_dir(char *file, char *dir);
void    is_car_in_str(char *str, char car);
void    add_car_to_str(char **str, char car);
char    *take_options(char **av, int ac);
char    *str_dup(char *str);
int     is_handle_option(char c);
char	*per(t_stt *sb);
char	*full();
char	*size(t_stt *b);
char	*filename(char *file);
char	*timecaps(t_stt *sb);
void	getinfo(t_i *in, t_stt *sb);
void	archmain(char **av, char *name, int v);
void	unarchmain(char **av, int v);
void	free_arch(char **size, t_file *f);
void	get_list(int ac, char **av, int fd);
void	flag_t(int ac, char **av);

/*
** end
*/

#endif /* !MY_TAR_H_ */
