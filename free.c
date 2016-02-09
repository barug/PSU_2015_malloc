/*
** free.c for free in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 14:24:02 2016 Erwan Dupard
** Last update Tue Feb  9 14:14:07 2016 Erwan Dupard
*/

#include "ressources.h"

extern t_block		*g_data;
extern pthread_mutex_t	g_mutex;

t_block			*fusion_prev_block(t_block *currentElem)
{
  t_block		*currentPrev;

  currentPrev = currentElem->prev;
  if (currentPrev && currentPrev->free == STATUS_FREE)
    {
      currentPrev->size += currentElem->size + NODE_SIZE;
      currentPrev->next = currentElem->next;
      if (currentElem->next)
	currentElem->next->prev = currentPrev;
    }
  return (currentPrev);
}

t_block			*get_elem_by_ptr(void *ptr)
{
  return ((t_block *)(ptr - (char)NODE_SIZE));
}

int			valid_addr(void *p)
{
  return (p != NULL && p <= sbrk(0));
}

void			free(void *ptr)
{
  t_block		*currentElem;
  
  pthread_mutex_lock(&g_mutex);
  if (valid_addr(ptr))
    {
      currentElem = get_elem_by_ptr(ptr);
      currentElem->free = 1;
      currentElem = fusion_prev_block(currentElem);
      if (currentElem && currentElem->next && currentElem->next->free)
	currentElem = fusion_prev_block(currentElem->next);
      if (currentElem && !currentElem->next)
	{
	  if (currentElem->prev)
	    currentElem->prev->next = NULL;
	  else
	    g_data = NULL;
	  brk(currentElem);
	}
    }
  pthread_mutex_unlock(&g_mutex);
}
