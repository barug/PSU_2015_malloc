
/*
** free.c for free in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 14:24:02 2016 Erwan Dupard
** Last update Fri Feb  5 13:10:17 2016 Erwan Dupard
*/

#include "ressources.h"

void			*heap_start;
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
  return ((t_block *)(ptr - (char)NODE_SIZE));
}

int			valid_addr(void *p)
{
  if (g_data)
    {
      if (p <= sbrk(0) && p >= heap_start)
	return (p == (get_elem_by_ptr(p))->data);
    }
  return (0);
}

void			free(void *ptr)
{
  t_block		*currentElem;

  if (ptr != NULL && valid_addr(ptr) && 1==0)
    {
      currentElem = get_elem_by_ptr(ptr);
      currentElem->free = STATUS_FREE;
      if (currentElem->prev && currentElem->prev->free == STATUS_FREE)
      	{
      	  currentElem = currentElem->prev;
      	  fusion_next_block(currentElem);
      	}
      if (currentElem->next && currentElem->next->free == STATUS_FREE)
      	fusion_next_block(currentElem);
      /* if (!currentElem->prev)  */
      /* 	{ */
      /* 	  if (currentElem->next) */
      /* 	    { */
      /* 	      currentElem->next->prev = NULL; */
      /* 	      g_data = currentElem->next; */
      /* 	    } */
      /* 	  else  */
      /* 	    g_data = NULL; */
      /* 	  (void)sbrk(-(NODE_SIZE + currentElem->size)); */
      /* 	} */
    }
}
