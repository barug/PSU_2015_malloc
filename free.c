/*
** free.c for free in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 14:24:02 2016 Erwan Dupard
** Last update Mon Feb  1 11:59:17 2016 Barthelemy Gouby
*/

#include "ressources.h"

static t_block		*get_elem_by_ptr(void *ptr)
{
  return ((t_block *)ptr - NODE_SIZE);
}

void			free(void *ptr)
{
  t_block		*currentElem;

  if (ptr != NULL)
    {
      printf("executing free\n");
      currentElem = get_elem_by_ptr(ptr);
      currentElem->free = 1;
      if (!currentElem->next) {
	printf("reducing heap size\n");
	if (currentElem->prev)
	  currentElem->prev->next = NULL;
	else {
	  printf("heap is empty\n");
	  g_data = NULL;
	}
	sbrk(-(NODE_SIZE + currentElem->size));
      }
      printf("--------------\n");
    }
}
