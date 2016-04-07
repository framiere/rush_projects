/*
** get_next_line.h for  in /home/bonett_w/Documents/rendu/CPE_2015_getnextline
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.net>
**
** Started on  Mon Jan  4 15:22:38 2016 Walter Bonetti
** Last update Sat Feb 27 00:10:05 2016 Walter Bonetti
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (1024)
# endif /* !READ_SIZE */

# define BUFFER_SIZE 1024

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
