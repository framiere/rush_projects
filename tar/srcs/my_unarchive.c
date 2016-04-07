/*
** my_unarchive.c for my_unarchive in /home/rigaud_b/rendu/Rush1/step_1/srcs
** 
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
** 
** Started on  Fri Jan  8 21:13:29 2016 Matthias RIGAUD
** Last update Sun Jan 10 04:45:46 2016 Matthias RIGAUD
*/

#include <my_tar.h>

void	write_file(t_file *f)
{
  int	fd;
  t_tim	time;
  t_stt	sb;

  time.modtime = gtnb(f->time);
  if (f->name[stlen(f->name) - 1] == '/')
    {
      if (mkdir(f->name, strtol(f->right, NULL, 8)) < 0
	  && stat(f->name, &sb))
	my_puterror("mkdir", 1);
    }
  else if ((fd = open(f->name, O_CREAT | O_WRONLY,
		      strtol(f->right, NULL, 8))) < 0)
    {
      my_puterror("open", 1);
    }
  else if (write(fd, f->content, f->size) < 0)
    my_puterror("write", 1);
  if (utime(f->name, &time) < 0)
    my_puterror("utime", 1);
  if (f->name[stlen(f->name) - 1] != '/')
    close(fd);
}

int	my_read(int fd, char **str, int size)
{
  int	reader;

  reader = read(fd, *str, size);
  if (reader == -1)
    my_puterror("read", 1);
  return (reader);
}

void		read_archive(int fd, int v)
{
  t_file	f;
  char		*size;

  f.name = malloc(100);
  size = malloc(12);
  f.content = malloc(1);
  f.right = malloc(8);
  f.time = malloc(12);
  while (my_read(fd, &f.name, 100) > 0)
    {
      if (v)
	printf("%s, ", f.name);
      my_read(fd, &size, 12);
      f.size = gtnb(size);
      my_read(fd, &f.right, 8);
      my_read(fd, &f.time, 12);
      free(f.content);
      f.content = malloc(f.size);
      my_read(fd, &f.content, f.size);
      write_file(&f);
    }
  free_arch(&size, &f);
}

void	my_unarchive(char *namear, int v)
{
  int	fd;

  if ((fd = open(namear, O_RDONLY)) == -1)
    my_puterror("open", 1);
  read_archive(fd, v);
  close(fd);
}

void	unarchmain(char **av, int v)
{
  int	i;

  i = -1;
  while (av[++i])
    {
      if (v)
	printf("--> Get ");
      my_unarchive(av[i], v);
      if (v)
	printf(" from %s\n", av[i]);
    }
  if (v)
    printf("--> done\n");
}
