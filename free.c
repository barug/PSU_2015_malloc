/*
** free.c for free in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 14:24:02 2016 Erwan Dupard
** Last update Fri Feb 12 14:52:25 2016 Barthelemy Gouby
*/

#include "ressources.h"

extern t_block		*g_data;
extern t_block		*g_last;
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
      if (currentElem == g_last)
	currentPrev = g_last;
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
  /* size_t		page_size; */
  /* size_t		size_to_reduce; */

  pthread_mutex_lock(&g_mutex);
  if (valid_addr(ptr))
    {
      currentElem = get_elem_by_ptr(ptr);
      currentElem->free = STATUS_FREE;
      currentElem = fusion_prev_block(currentElem);
      if (currentElem && currentElem->next && currentElem->next->free)
	currentElem = fusion_prev_block(currentElem->next);
      /* if (currentElem && !currentElem->next) */
      /* 	{ */
      /* 	  page_size = getpagesize(); */
      /* 	  if (currentElem->size > 2 * page_size) */
      /* 	    { */
      /* 	      if (currentElem->prev) */
      /* 		{ */
      /* 		  g_last = currentElem->prev; */
      /* 		  currentElem->prev->next = NULL; */
      /* 		} */
      /* 	      else */
      /* 		g_data = NULL; */
      /* 	      size_to_reduce = (currentElem->size / page_size - 1)  * page_size; */
      /* 	      sbrk(size_to_reduce); */
      /* 	      currentElem->size = currentElem->size - size_to_reduce; */
      /* 	    } */
      /* 	} */
    }
  pthread_mutex_unlock(&g_mutex);
}
