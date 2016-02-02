/*
** free.c for free in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 14:24:02 2016 Erwan Dupard
** Last update Tue Feb  2 14:47:26 2016 Barthelemy Gouby
*/

#include "ressources.h"

t_block			*get_elem_by_ptr(void *ptr)
{
  return ((ptr - NODE_SIZE));
}

static void		fusion_next_block(t_block *currentElem)
{
  currentElem->size += NODE_SIZE + currentElem->next->size;
  currentElem->next = currentElem->next->next;
  if (currentElem->next)
    currentElem->next->prev = currentElem;
}

void			free(void *ptr)
{
  t_block		*currentElem;

  if (ptr != NULL)
    {
      currentElem = get_elem_by_ptr(ptr);
      currentElem->free = 1;
      printf("ptr: %p\n", ptr);
      printf("currentElem: %p\n", currentElem);
      if (currentElem->prev && currentElem->prev->free) 
	{
	  currentElem = currentElem->prev;
	  fusion_next_block(currentElem);
	}
      if (currentElem->next && currentElem->next->free) 
	fusion_next_block(currentElem);
      if (!currentElem->next) 
	{
	  if (currentElem->prev)
	    currentElem->prev->next = NULL;
	  else 
	    g_data = NULL;
	  sbrk(-(NODE_SIZE + currentElem->size));
	}
    }
}
