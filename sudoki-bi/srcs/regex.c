/*
** regex.c for  in /home/bonett_w/Documents/rendu/sudoki-bi/srcs/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sat Feb 27 08:14:27 2016 Walter Bonetti
** Last update Sat Feb 27 08:16:43 2016 Walter Bonetti
*/

#include "parser.h"

int	check(char *str, regex_t *regex)
{
  int	reti;

  reti = regexec(regex, str, 0, NULL, 0);
  if (!reti)
    return (1);
  else if (reti == REG_NOMATCH)
    return (0);
  else
    {
      printf("Regex match failed\n");
      return (0);
    }
}

int	regex_compilation(regex_t *regex, char *pattern)
{
  int	reti;

  reti = regcomp(regex, pattern, REG_EXTENDED);
  if (reti)
    {
      fprintf(stderr, "%s\n", "Error regcomp\n");
      exit(-1);
    }
  return (0);
}

void	regex_set_all(regex_t *a, regex_t *b, char *pattrn_a, char *pattrn_b)
{
  regex_compilation(a, pattrn_a);
  regex_compilation(b, pattrn_b);
}

void	regex_free_all(regex_t *a, regex_t *b)
{
  regfree(a);
  regfree(b);
}
