/*
** malloc.c for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jan 26 23:51:05 2016 Erwan Dupard
** Last update Fri Jan 29 15:15:23 2016 Barthelemy Gouby
*/

#include <unistd.h>
#include "ressources.h"

void		*g_data = NULL;

static void	*extend_memory(size_t size)
{
  t_block	*new;
  t_block	*iterator;

  if ((new = sbrk(NODE_SIZE + size)) == (void *) -1)
    return (NULL);
  new->data = (new + NODE_SIZE);
  new->size = size;
  new->free = 0;
  new->next = NULL;
  if (g_data == NULL)
    {
      g_data = new;
      return (new->data);
    }
  iterator = g_data;
  while (iterator->next)
    iterator = iterator->next;
  iterator->next = new;
  return (new->data);
}

/* static t_block	*get_last_elem() */
/* { */
/*   t_block	*iterator; */

/*   iterator = g_data; */
/*   if (!iterator) */
/*     return (NULL); */
/*   while (iterator->next) */
/*     iterator = iterator->next; */
/*   return (iterator); */
/* } */

static void*	find_free_block(size_t size)
{
  t_block	*iterator;

  iterator = g_data;
  if (!iterator)
    return (NULL);
  while (iterator->next)
    {
      if (iterator->free == 1 && iterator->size >= size)
	return (iterator->data);
      iterator = iterator->next;
    }
  return (NULL);
}

void		*malloc(size_t size)
{
  void		*allocated_block;

  if (size <= 0)
    return (NULL);
  if ((allocated_block = find_free_block(size)) == NULL)
    {
      if ((allocated_block = extend_memory(size)) == NULL)
	return (NULL);
    }
  return (allocated_block);
}
