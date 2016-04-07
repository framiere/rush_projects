/*
** div.c for my_unarchive in /home/rigaud_b/rendu/Rush1/step_1/srcs
** 
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
** 
** Started on  Fri Jan  8 21:22:57 2016 Matthias RIGAUD
** Last update Sat Jan  9 19:36:12 2016 Matthias RIGAUD
*/

#include <my_tar.h>

void	my_puterror(char *str, int type)
{
  if (type == 1)
    perror(str);
  else
    write(2, str, stlen(str));
  exit(1);
}

int     power(int nb, int pow)
{
  if (!pow)
    return (1);
  return (power(nb, pow - 1) * nb);
}

int     stlen(char *str)
{
  if (!(*str))
    return (0);
  return (stlen(&str[1]) + 1);
}

int     gtnb(char *str)
{
  if (!(*str))
    return (0);
  if (*str < 48 || *str > 57)
    my_puterror("Size is corrupted.\n", 0);
  return (gtnb(&str[1]) + (*str - 48) * power(10, stlen(str) - 1));
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = -1;
  while (s1[++i])
    if (s1[i] != s2[i])
      return (s1[i] - s2[i]);
  return (0);
}
