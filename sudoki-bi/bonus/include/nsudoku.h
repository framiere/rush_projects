/*
** nsudoku.h for  in /home/bonett_w/Documents/rendu/ncurses/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Feb 28 12:37:35 2016 Walter Bonetti
** Last update Sun Feb 28 22:03:38 2016 Walter Bonetti
*/

#ifndef NSUDOKU_H_
# define NSUDOKU_H_

# include "../../include/sudoki-bi.h"
# include <stdlib.h>
# include <unistd.h>
# include <ncurses.h>
# include <time.h>
# include <string.h>

# define GRID_SYMBOLE_MIDDLE	"+++"
# define GRID_SYMBOLE_DELIM	"+"
# define GRID_SYMBOLE_CONTACT_E	"   |"
# define GRID_SYMBOLE_CONTACT_S	"|"
# define EMPTY_SYMBOL		" "
# define GRID_LINES		19
# define GRID_COLS		37
# define GRID_Y			3
# define GRID_X			5 + STATS_X + STATS_COLS
# define STATS_LINES		19
# define STATS_COLS		20
# define STATS_Y		3
# define STATS_X		3
# define GRID_START_Y		1
# define GRID_START_X		2
# define GRID_LINE_DELTA	4
# define GRID_COL_DELTA		2
# define STATUS_LINES		1
# define STATUS_COLS		GRID_COLS + STATS_COLS
# define STATUS_Y		1
# define STATUS_X		GRID_X

typedef struct	s_nc_window
{
  WINDOW	*grid;
  WINDOW	*infobox;
  WINDOW	*status;
  t_sudoku	solved;
  t_sudoku	unsolved;
  t_sudoku	player;
  short int	run;
  short int	help;
  int		key;
  int		x;
  int		y;
  int		posx;
  int		posy;
}		t_nc_window;

void	init_windows(t_nc_window *window);
void	init_game_loop(t_nc_window *window);
void	init_nrcuses(void);

void	draw_concat(t_nc_window *w, int *i, int *j);
void	draw_symbole(t_nc_window *w, int *i, int *j);
void	draw_fill_grid(t_nc_window *w);
void	draw_grid(t_nc_window *w);
void	draw_fill_help(t_nc_window *w);

void	list_input_event(t_nc_window *w);
void	listen_event(t_nc_window *w);

int	reset_player(t_nc_window *win);
int	reset_game(t_nc_window *win);

void	app_game(t_nc_window *win);
void	app_load_map(t_nc_window *win);
void	maps_random(t_nc_window *win);

int	check_is_okay(t_nc_window *window);
void	cleanup(void);

void	resolver_demo(int (*sudoku)[9], int nb_void, t_nc_window *win);

#endif /* !NSUDOKU_H_ */
