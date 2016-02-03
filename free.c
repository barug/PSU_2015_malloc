/*
** free.c for free in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 14:24:02 2016 Erwan Dupard
** Last update Wed Feb  3 16:47:36 2016 Erwan Dupard
*/

#include "ressources.h"

t_block			*g_data;

static void		fusion_next_block(t_block *currentElem)
{
  currentElem->size += NODE_SIZE + currentElem->next->size;
  currentElem->next = currentElem->next->next;
  if (currentElem->next)
    currentElem->next->prev = currentElem;
}

t_block			*get_elem_by_ptr(void *ptr)
{
  char			*tmp;

  tmp = ptr;
  return (ptr = tmp -= NODE_SIZE);
}

void			free(void *ptr)
{
  t_block		*currentElem;

  if (ptr != NULL)
    {
      currentElem = get_elem_by_ptr(ptr);
      currentElem->free = 1;
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
	  (void)sbrk(-(NODE_SIZE + currentElem->size));
	}
    }
}
