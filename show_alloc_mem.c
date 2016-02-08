/*
** show_alloc_mem.c for show_alloc_mem in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 15:27:29 2016 Erwan Dupard
** Last update Mon Feb  8 14:17:19 2016 Erwan Dupard
*/

#include "ressources.h"

t_block			*g_data;

void			show_alloc_mem()
{
  t_block		*iterator;
  int			i = 0;

  printf("break : %p\n", sbrk(0));
  iterator = g_data;
  while (iterator)
    {
      printf("%p - %p : %lu bytes\n",
	     iterator->data,
	     (iterator->next ? iterator->next : sbrk(0)),
	     iterator->size);
      iterator = iterator->next;
      i++;
    }
}
