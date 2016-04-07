/*
** gitinfo.c for my_archive in /home/bouama_r/rendu/bouama_r/Rush1/step_3/srcs
** 
** Made by Ryan Bouamara
** Login   <bouama_r@epitech.net>
** 
** Started on  Sat Jan  9 23:02:57 2016 Ryan Bouamara
** Last update Sun Jan 10 01:41:49 2016 Matthias RIGAUD
*/

#include <my_tar.h>

void	getinfo(t_i *in, t_stt *sb)
{
  int	i;

  i = -1;
  while (in->name[++i])
    in->inf[i] = in->name[i];
  if (S_ISDIR(sb->st_mode) && in->inf[i - 1] != '/')
    in->inf[i] = '/';
  i = 99;
  while (in->size[++i - 100])
    in->inf[i] = in->size[i - 100];
  i = 111;
  while (in->perm[++i - 112])
    in->inf[i] = in->perm[i - 112];
  i = 119;
  while (in->time[++i - 120])
    in->inf[i] = in->time[i - 120];
}
