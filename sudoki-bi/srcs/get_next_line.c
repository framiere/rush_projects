/*
** my_getnextline.c for  in /home/bonett_w/rendu/CPE/CPE_2015_BSQ/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Dec  3 15:36:28 2015 walter bonetti
** Last update Sat Feb 27 21:02:52 2016 Matthias RIGAUD
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*my_realloc(char *tmp, size_t size)
{
  char		*ptr;
  register int	i;

  if ((ptr = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  i = 0;
  while (tmp[++i])
    ptr[i] = tmp[i];
  free(tmp);
  return (ptr);
}

int		get_next_char(const int fd)
{
  int		c;
  static int	rd;
  static char	*ptr;
  static char	buff[BUFFER_SIZE];

  if (rd == 0)
    {
      rd = read(fd, buff, READ_SIZE);
      ptr = (char*)&buff;
      if (rd == 0 || buff[0] == 4)
	return (-8500);
    }
  c = *ptr;
  ptr++;
  rd--;
  return (c);
}

char		*get_next_line(const int fd)
{
  int		c;
  size_t	cursor;
  char		*line;

  cursor = 0;
  if ((line = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
    return (NULL);
  while ((c = get_next_char(fd)) != '\n')
    {
      if (c == -8500 || c == 4 || c == 3)
	return ((cursor) ? line : NULL);
      line[cursor++] = c;
      if (cursor % (BUFFER_SIZE + 1) == 0)
	if ((line = my_realloc(line, cursor + BUFFER_SIZE + 1)) == NULL)
	  return (NULL);
    }
  line[cursor] = '\0';
  return (line);
}
