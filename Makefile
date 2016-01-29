##
## Makefile for MallocMakefile in /home/dupard_e/rendus/PSU_2015_malloc
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Tue Jan 26 23:48:36 2016 Erwan Dupard
## Last update Fri Jan 29 12:54:59 2016 Erwan Dupard
##

CC		= gcc

RM		= rm -f

NAME		= libmy_malloc.so

SRCS		= malloc.c		\

OBJS		= $(SRCS:.c=.o)

CFLAGS		+= -fPIC -Wall -Werror -Wextra

LDFLAGS		+= -shared

all: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
