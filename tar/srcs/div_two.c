/*
** div_two.c for my_archive in /home/rigaud_b/rendu/Rush1/step_2/srcs
** 
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
** 
** Started on  Sat Jan  9 07:17:07 2016 Matthias RIGAUD
** Last update Sun Jan 10 05:23:33 2016 Matthias RIGAUD
*/

#include <my_tar.h>

int     prep_str(char *str)
{
  int   i;
  int   nb_sl;

  i = -1;
  nb_sl = -1;
  while (str[++i])
    if (str[i] == '/' && str[i + 1])
      nb_sl = i;
  return (nb_sl);
}

char    *add_dir(char *file, char *dir)
{
  char  *returner;
  int   i;
  int   sizedir;

  sizedir = stlen(dir);
  if (!(returner = malloc(stlen(file) + sizedir + 2)))
    my_puterror("malloc", 1);
  i = -1;
  while (dir[++i])
    returner[i] = dir[i];
  if (returner[i - 1] != '/')
    returner[sizedir++] = '/';
  i = -1;
  while (file[++i])
    returner[i + sizedir] = file[i];
  returner[i + sizedir] = 0;
  return (returner);
}

void	free_arch(char **size, t_file *f)
{
  free(f->name);
  free(*size);
  free(f->content);
  free(f->right);
  free(f->time);
}
