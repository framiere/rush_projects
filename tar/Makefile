##
## Makefile for my_archive in /home/rigaud_b/rendu/Rush1/step_1
##
## Made by Matthias RIGAUD
## Login   <rigaud_b@epitech.net>
##
## Started on  Fri Jan 08 20:56:39 2016 Matthias RIGAUD
## Last update Sun Jan 10 05:53:43 2016 Matthias RIGAUD
##

RM		= \rm -f

CC		= gcc

NAME		= my_tar

SRCS		= srcs/my_archive.c \
		srcs/my_unarchive.c \
		srcs/div.c \
		srcs/div_two.c \
		srcs/fileinfo.c \
		srcs/gitinfo.c \
		srcs/take_options.c \
		srcs/my_tar.c \
		srcs/t_flag.c

OBJS		= $(SRCS:.c=.o)

SHEETIES	= $(OBJS) \
		$(SRCS:.c=.c~) \
		Makefile~

CFLAGS		= -W -Wall -Werror -Wextra -ansi -pedantic -Iinclude

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(SHEETIES)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

comp:		re
		$(RM) $(SHEETIES)
