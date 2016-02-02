##
## Makefile for MallocMakefile in /home/dupard_e/rendus/PSU_2015_malloc
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Tue Jan 26 23:48:36 2016 Erwan Dupard
## Last update Tue Feb  2 18:01:35 2016 Barthelemy Gouby
##

CC		= gcc

RM		= rm -f

NAME		= libmy_malloc.so

SRCS		= malloc.c		\
		  free.c		\
		  show_alloc_mem.c	\
		  memory_dump.c		\
	 	  realloc.c		\
		  calloc.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		+= -g3 -fPIC -Wall -Werror -Wextra

LDFLAGS		+= -shared

all: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
