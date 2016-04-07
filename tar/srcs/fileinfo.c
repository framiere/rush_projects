/*
** fileinfo.c for my_archive in /home/bouama_r/rendu/bouama_r/Rush1/step_3/srcs
** 
** Made by Ryan Bouamara
** Login   <bouama_r@epitech.net>
** 
** Started on  Sat Jan  9 20:03:28 2016 Ryan Bouamara
** Last update Sun Jan 10 05:27:46 2016 Matthias RIGAUD
*/

#include <my_tar.h>

char	*per(t_stt *sb)
{
  char	*perm;

  if (!(perm = malloc(8)))
    my_puterror("malloc", 1);
  sprintf(perm, "%#o", (int)sb->st_mode);
  return (perm);
}

char	*full()
{
  int	j;
  char	*inf;

  if (!(inf = malloc(132)))
    my_puterror("malloc", 1);
  j = -1;
  while (++j < 132)
    inf[j] = '\0';
  return (inf);
}

char	*size(t_stt *sb)
{
  char	*s;

  if (!(s = malloc(12)))
    my_puterror("malloc", 1);
  sprintf(s, "%d", (int)sb->st_size);
  return (s);
}

char	*filename(char *file)
{
  int	i;
  char	*s;

  if (!(s = malloc(100)))
    my_puterror("malloc", 1);
  while (i < 100)
    {
      s[i] = '\0';
      i++;
    }
  i = 0;
  while (file[i] != '\0')
    {
      s[i] = file[i];
      i++;
    }
  return (s);
}

char	*timecaps(t_stt *sb)
{
  char	*time;
  int	i;

  i = 0;
  if (!(time = malloc(12)))
    my_puterror("malloc", 1);
  while (i <= 12)
    {
      time[i] = '\0';
      i++;
    }
  sprintf(time, "%d", (int)sb->st_mtime);
  return (time);
}
