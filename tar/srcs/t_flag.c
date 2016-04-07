/*
** t_flag.c for my_archive in /home/bouama_r/rendu/bouama_r/Rush1/step_3/srcs
** 
** Made by Ryan Bouamara
** Login   <bouama_r@epitech.net>
** 
** Started on  Sun Jan 10 05:25:37 2016 Ryan Bouamara
** Last update Sun Jan 10 06:06:46 2016 Matthias RIGAUD
*/

#include <my_tar.h>

void	get_list(int ac, char **av, int fd)
{
  char	*cont;
  int	size;
  char	*name;
  char	*s;

  if (!(name = malloc(100)))
    my_puterror("malloc", 1);
  if (!(s = malloc(12)))
    my_puterror("malloc", 1);
  if ((read(fd, s, 12)) == 0)
    exit(-1);
  size = atoi(s);
  if (!(cont = malloc(size + 20)))
    my_puterror("malloc", 1);
  if ((read(fd, cont, size + 20)) == 0)
    exit(-1);
  if ((read(fd, name, 100)) == 0)
    exit(-1);
  printf("%s\n", name);
  free(name);
  free(s);
  free(cont);
  get_list(ac, av, fd);
}

void	flag_t(int ac, char **av)
{
  int	fd;
  char	*cont;

  if (!(cont = malloc(100)))
    my_puterror("malloc", 1);
  if ((fd = open(av[ac - 1], O_RDONLY)) == -1)
    {
      perror("open");
      exit(-1);
    }
  if ((read(fd, cont, 100)) == -1)
    {
      perror("read");
      exit(-1);
    }
  printf("%s\n", cont);
  free(cont);
  get_list(ac, av, fd);
}
