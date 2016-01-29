/*
** show_alloc_mem.c for show_alloc_mem in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 15:27:29 2016 Erwan Dupard
** Last update Fri Jan 29 15:33:45 2016 Erwan Dupard
*/

#include "ressources.h"

void			*g_data;

void			show_alloc_mem()
{
  t_block		*iterator;

  printf("break : %p\n", g_data);
  iterator = g_data;
  if (iterator != NULL)
    {
      while (iterator->next)
	{
	  printf("%p - %p : %d bytes\n", iterator, iterator->next, (int)iterator->size);
	  iterator = iterator->next;
	}
    }
}
