##
## Makefile for MallocMakefile in /home/dupard_e/rendus/PSU_2015_malloc
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Tue Jan 26 23:48:36 2016 Erwan Dupard
## Last update Tue Jan 26 23:54:05 2016 Erwan Dupard
##

CC		= gcc

RM		= rm -f

NAME		= libmy_malloc.so

SRCS		= malloc.c	\

OBJS		= $(SRCS:.c=.o)

CFLAGS		+= -Wall -Werror -Wextra

LDFLAGS		+= -fpic -shared

all: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
