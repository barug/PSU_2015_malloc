/*
** show_alloc_mem.c for show_alloc_mem in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 15:27:29 2016 Erwan Dupard
** Last update Thu Feb  4 12:56:46 2016 Barthelemy Gouby
*/

#include "ressources.h"

t_block			*g_data;

void			show_alloc_mem()
{
  t_block		*iterator;
  int			i = 0;

  printf("break : %p\n", sbrk(0));
  iterator = g_data;
  if (iterator)
    {
      while (iterator)
	{
	  if (iterator->next)
	    printf("block %i at  %p - %p : %d bytes\n", i, iterator->data, iterator->next, (int)iterator->size);
	  else
	    printf("block %i at %p - %p : %d bytes\n", i, iterator->data, sbrk(0), (int)iterator->size);	    
	  iterator = iterator->next;
	  i++;
	}
    }
}
