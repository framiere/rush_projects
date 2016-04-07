/*
** take_options.c for my_tar in /home/rigaud_b/rendu/Rush1/step_3/srcs
** 
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
** 
** Started on  Sat Jan  9 09:31:33 2016 Matthias RIGAUD
** Last update Sun Jan 10 05:32:19 2016 Matthias RIGAUD
*/

#include <my_tar.h>

int     is_handle_option(char c)
{
  if (c == 'x' ||
      c == 'c' ||
      c == 'v' ||
      c == 'f' ||
      c == 't' ||
      c == 'p')
    return (1);
  return (0);
}

char	*str_dup(char *str)
{
  char *returner;
  int	i;

  if (!(returner = malloc(stlen(str) + 1)))
    my_puterror("malloc", 1);
  i = -1;
  while (++i <= stlen(str))
    returner[i] = str[i];
  return (returner);
}

char    *take_options(char **av, int ac)
{
  int   i;
  int   j;
  char  *options;

  options = str_dup("");
  i = 0;
  if (ac > 1)
    if (av[1][0] == '-')
      while (av[++i][0] == '-')
        {
          j = 0;
          while (av[i][++j] != 0)
            {
              is_car_in_str(options, av[i][j]);
              if (is_handle_option(av[i][j]) == 0)
                my_puterror("Options handled are only -xcvftp\n", 0);
              add_car_to_str(&options, av[i][j]);
            }
          if (j == 1)
            my_puterror("Syntax error\n", 0);
          if (av[i + 1] == NULL)
            return (options);
        }
  return (options);
}

void    add_car_to_str(char **str, char car)
{
  char  *cpy;
  int   i;

  if (!(cpy = malloc(stlen(*str) + 2)))
    my_puterror("malloc", 1);
  i = -1;
  while (str[0][++i] != 0)
    cpy[i] = str[0][i];
  cpy[i] = car;
  cpy[i + 1] = 0;
  free(*str);
  *str = cpy;
}

void	is_car_in_str(char *str, char car)
{
  int   i;

  i = -1;
  while (str[++i] != 0)
    if (str[i] == car || ((str[i] == 'c' || str[i] == 'x' || str[i] == 't') &&
			  (car == 'c' || car == 'x' || car == 't')))
      my_puterror("c, x & t are uncompatible & you can't"
		  "enter twice the same option.\n", 0);
}
