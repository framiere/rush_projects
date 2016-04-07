/*
** puterror.c for sudoki-bi in /home/rigaud_b/rendu/sudoki-bi/srcs
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Fri Feb 26 22:15:21 2016 Matthias RIGAUD
** Last update Fri Feb 26 23:42:09 2016 Walter Bonetti
*/

#include "sudoki-bi.h"

void	my_puterror(char *str, int n_exit)
{
  fprintf(stderr, "%s\n", str);
  exit(n_exit);
}
