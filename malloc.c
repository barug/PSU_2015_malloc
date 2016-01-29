/*
** malloc.c for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jan 26 23:51:05 2016 Erwan Dupard
** Last update Fri Jan 29 15:10:18 2016 Erwan Dupard
*/

#include <unistd.h>
#include "ressources.h"

void		*g_data = NULL;

static int	extend_memory(size_t size)
{
  t_block	*new;
  t_block	*iterator;

  if ((new = sbrk(NODE_SIZE + size)) == (void *) -1)
    return (RETURN_FAILURE);
  new->data = (new + NODE_SIZE);
  new->size = size;
  new->next = NULL;
  if (g_data == NULL)
    {
      g_data = new;
      return (RETURN_SUCCESS);
    }
  iterator = g_data;
  while (iterator->next)
    iterator = iterator->next;
  iterator->next = new;
  return (RETURN_SUCCESS);
}

static t_block	*get_last_elem()
{
  t_block	*iterator;

  iterator = g_data;
  if (!iterator)
    return (NULL);
  while (iterator->next)
    iterator = iterator->next;
  return (iterator);
}

void		*malloc(size_t size)
{
  t_block		*last;

  if (size <= 0)
    return (NULL);
  if (extend_memory(size) == RETURN_FAILURE)
    return (NULL);
  if ((last = get_last_elem()) == NULL)
    return (NULL);
  return (last->data);
}
