/*
** free.c for free in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 14:24:02 2016 Erwan Dupard
<<<<<<< HEAD
** Last update Fri Jan 29 15:26:01 2016 Barthelemy Gouby
=======
** Last update Fri Jan 29 15:24:12 2016 Erwan Dupard
>>>>>>> bb85cff7f7d6a9ce142980f4c31455f80a7c6fe5
*/

#include "ressources.h"

static t_block		*get_elem_by_ptr(void *ptr)
{
  return ((t_block *)ptr - NODE_SIZE);
}

void			free(void *ptr)
{
  t_block		*currentElem;

  currentElem = get_elem_by_ptr(ptr);
  currentElem->free = 0;
  if (!currentElem->next) {
    currentElem->prev->next = NULL;
    sbrk(NODE_SIZE + currentElem->size);
  }
  (void)currentElem;
}
