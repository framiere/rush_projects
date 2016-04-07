/*
** my_tar.c for my_tar in /home/rigaud_b/rendu/Rush1/step_3/srcs
** 
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
** 
** Started on  Sun Jan 10 02:57:54 2016 Matthias RIGAUD
** Last update Sun Jan 10 06:12:30 2016 Matthias RIGAUD
*/

#include <my_tar.h>

int	is_option(char c, char *options)
{
  int	i;

  i = -1;
  while (options[++i])
    if (c == options[i])
      return (1);
  return (0);
}

char	*get_name(char ***av, char *options, int *i)
{
  char	*name;

  *i = 0;
  while (av[0][++(*i)][0] == '-')
  if (!av[0][*i + 1])
    my_puterror("Usage : -xcvftp (arch_name) (file1) ...\n", 0);
  if (is_option('f', options))
    {
      name = str_dup(av[0][*i]);
      (*i)++;
    }
  else
    name = str_dup("time_lord_arch");
  return (name);
}

int	main(int ac, char **av)
{
  char	*options;
  char	*name;
  int	i;

  if (ac == 1)
    my_puterror("Usage : -xcvftp (arch_name) (file1) ...\n", 0);
  options = take_options(av, ac);
  name = get_name(&av, options, &i);
  av = &av[i];
  if (is_option('x', options) && is_option('f', options))
    unarchmain(&av[-1], is_option('v', options));
  else if (is_option('x', options))
    unarchmain(av, is_option('v', options));
  else if (ac - i <= 0)
    my_puterror("Usage : -xcvftp (arch_name) (file1) ...\n", 0);
  else if (is_option('c', options))
    archmain(av, name, is_option('v', options));
  else if (is_option('t', options))
    flag_t(1, av);
  free(name);
  free(options);
  return (0);
}
