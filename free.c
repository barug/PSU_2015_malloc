/*
** free.c for free in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 14:24:02 2016 Erwan Dupard
** Last update Tue Feb  2 13:06:35 2016 Erwan Dupard
Mon Feb  1 15:23:46 2016 Barthelemy Gouby
*/

#include "ressources.h"

t_block			*get_elem_by_ptr(void *ptr)
{
  return ((t_block *)(ptr - NODE_SIZE));
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
	  currentElem->prev->next = currentElem->next;
	  currentElem->prev->size += NODE_SIZE + currentElem->size;
	  currentElem = currentElem->prev;
	}
      if (currentElem->next && currentElem->next->free) 
	{
	  currentElem->size += NODE_SIZE + currentElem->next->size;
	  currentElem->next = currentElem->next->next;
	}
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
