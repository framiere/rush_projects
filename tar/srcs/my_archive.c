/*
** my_archive.c for my_arhive in /home/bouama_r/rendu/bouama_r/Rush1/step_1
** 
** Made by Ryan Bouamara
** Login   <bouama_r@epitech.net>
** 
** Started on  Fri Jan  8 21:13:22 2016 Ryan Bouamara
** Last update Sun Jan 10 05:29:45 2016 Matthias RIGAUD
*/

#include <my_tar.h>

char	*info(char *file, t_stt *sb)
{
  t_i	in;

  in.inf = full();
  in.perm = per(sb);
  in.name = filename(file);
  if (!S_ISDIR(sb->st_mode))  
    in.size = size(sb);
  else
    {
      if (!(in.size = malloc(1)))
	my_puterror("malloc", 1);
      in.size[0] = 0;
    }
  in.time = timecaps(sb);
  getinfo(&in, sb);
  return (in.inf);
}

char	*stopen(char *file, t_stt *sb)
{
  int	fd;
  char	*cont;

  if (stat(file, sb) == -1 )
    {
      perror("stat");
      exit(-1);
    }
  if (!(cont = malloc(sb->st_size)))
    my_puterror("malloc", 1);
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      perror("open");
      exit(-1);
    }
  if ((read(fd, cont, sb->st_size)) < 0)
    {
      perror("read");
      exit(-1);
    }
  close(fd);
  return (cont);
}

void	algo(char *file, t_stt *sb, int fdp, int nb_slash)
{
  char	*inf;
  char	*content;

  if (!S_ISDIR(sb->st_mode))
    content = stopen(file, sb);
  inf = info(&file[nb_slash + 1], sb);
  if (write(fdp, inf, 132) <= 0)
    {
      perror("write");
      exit(-1);
    }
  if (!S_ISDIR(sb->st_mode))
    if (write(fdp, content, sb->st_size) < 0)
      {
	perror("write");
	exit(-1);
      }
}

void	dir(char *ndir, int fdp, int nb_slash)
{
  DIR	*dirp;
  t_dir	*entry;
  t_stt	sb;

  stat(ndir, &sb);
  algo(ndir, &sb, fdp, nb_slash);
  if (!S_ISDIR(sb.st_mode))
    return ;
  if ((dirp = opendir(ndir)) == NULL)
    my_puterror("opendir", 1);
  while ((entry = readdir(dirp)) != NULL)
    {
      if (my_strcmp(entry->d_name, ".") && my_strcmp(entry->d_name, ".."))
	dir(add_dir(entry->d_name, ndir), fdp, nb_slash);
    }
  closedir(dirp);
}

void	archmain(char **av, char *name, int v)
{
  int	fdp;
  int	i;

  if ((fdp = open(name, O_CREAT | O_WRONLY, 0666)) < 0)
    my_puterror("erreur creation fichier", 1);
  i = -1;
  if (v)
    printf("--> Create archive from ");
  while (av[++i])
    {
      dir(av[i], fdp, prep_str(av[i]));
      if (v)
	printf("%s, ", av[i]);
    }
  if (v)
    printf("in %s\n--> done\n", name);
  close(fdp);
}
