/*
** parser.c for  in /home/bonett_w/Documents/rendu/sudoki-bi/srcs/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Feb 26 21:07:40 2016 Walter Bonetti
** Last update Sat Feb 27 21:05:54 2016 Matthias RIGAUD
*/

#include "sudoki-bi.h"

int		put_line_tab(t_sudoku *sudoku, char *line, int nb_line)
{
  register int	i;
  int		tmp[10];

  i = 0;
  line++;
  memset(tmp, 0, sizeof(int) * 10);
  while (*line != '|')
    {
      if (*(line + 1) == ' ')
	{
	  sudoku->tab[nb_line][i] = 0;
	  sudoku->nb_void++;
	}
      else
	{
	  sudoku->tab[nb_line][i] = *(line + 1) - 48;
	  if (tmp[sudoku->tab[nb_line][i]] == 0)
	    tmp[sudoku->tab[nb_line][i]] = 1;
	  else
	    return (!(sudoku->valid = 0));
	}
      line += 2;
      i++;
    }
  return (1);
}

int		parser(t_params *params, t_sudoku *sudoku)
{
  register char	i;
  register int	valid[2];
  char		*line;

  i = 0;
  line = NULL;
  while ((line = get_next_line(0)) != NULL)
    {
      valid[0] = check(line, &params->head);
      if (valid[0] && i == -1)
	{
	  free(line);
	  return (1);
        }
      valid[1] = check(line, &params->line);
      if (strlen(line) != 20 || (!valid[0] && !valid[1]) || (i > 9))
	my_puterror("MAP ERROR", -1);
      if (valid[1] && put_line_tab(sudoku, line, i))
	(i == 8) ? (i = -1) : i++;
      free(line);
    }
  if (i != 0)
    my_puterror("MAP ERROR", -1);
  return ((line != NULL) ? (0) : (-1));
}

int		check_case(int (*sudoku)[9])
{
  register int	i;
  register int	j;
  int		p[9];

  i = -1;
  while (++i < 9)
    {
      memset(p, 0, 9 * sizeof(int));
      j = -1;
      while (++j < 9)
	{
	  if (sudoku[(i % 3) * 3 + (j % 3)][(i / 3) * 3 + (j / 3)])
	    {
	      if (p[sudoku[(i % 3) * 3 + (j % 3)][(i / 3) * 3 + (j / 3)] - 1])
		return (0);
	      else
		p[sudoku[(i % 3) * 3 + (j % 3)][(i / 3) * 3 + (j / 3)] - 1]++;
	    }
	}
    }
  return (1);
}

int		check_columns(t_sudoku *sudoku)
{
  register int	i;
  register int	j;
  int		tmp[10];
  int		p[9];

  i = -1;
  while (++i < 9 && (j = -1) < 0)
    {
      memset(tmp, 0, sizeof(int) * 10);
      memset(p, 0, sizeof(int) * 9);
      while (++j < 9)
	{
	  if (B[i][j] != 0 && tmp[B[i][j]] == 0)
	    tmp[B[i][j]] = 1;
	  else if (B[i][j] != 0)
	    return (!(sudoku->valid = 0));
	  if ((B[(i % 3) * 3 + (j % 3)][(i / 3) * 3 + (j / 3)]) &&
	      p[B[(i % 3) * 3 + (j % 3)][(i / 3) * 3 + (j / 3)] - 1])
	    return (!(sudoku->valid = 0));
	  else if ((B[(i % 3) * 3 + (j % 3)][(i / 3) * 3 + (j / 3)]))
	    p[B[(i % 3) * 3 + (j % 3)][(i / 3) * 3 + (j / 3)] - 1]++;
	}
    }
  return (0);
}

int	parser_init(t_list *list)
{
  int		status;
  t_params	params;
  t_sudoku	sudoku;

  status = 1;
  regex_set_all(&params.line, &params.head, REGEX_PARSER, REGEX_PARSER_HEAD);
  sudoku.nb_void = 0;
  sudoku.valid = 1;
  while ((status = parser(&params, &sudoku)) == 1)
    {
      if (sudoku.valid)
	check_columns(&sudoku);
      list_push(list, &sudoku);
      sudoku.nb_void = 0;
      sudoku.valid = 1;
    }
  regex_free_all(&params.line, &params.head);
  return (0);
}
