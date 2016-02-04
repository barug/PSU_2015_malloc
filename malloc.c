/*
** malloc.c for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jan 26 23:51:05 2016 Erwan Dupard
** Last update Thu Feb  4 16:12:58 2016 Erwan Dupard
*/

#include <unistd.h>
#include "ressources.h"

t_block		*g_data = NULL;

void		*extend_memory(size_t size)
{
  t_block	*new;

  new = sbrk(0);
  if (sbrk(NODE_SIZE + size) == (void *) -1)
    return (NULL);
  new->size = size;
  new->free = 0;
  new->next = g_data;
  if (g_data)
    g_data->prev = new;
  new->prev = NULL;
  g_data = new;
  return (new->data);
}

static void	*find_free_block(size_t size)
{
  t_block	*iterator;

  iterator = g_data;
  if (iterator == NULL)
    return (NULL);
  while (iterator->next)
    {
      if (iterator->free == 1 && iterator->size >= size)
	{
	  iterator->free = 0;
	  return (iterator->data);
	}
      iterator = iterator->next;
    }
  return (NULL);
}

void		*malloc(size_t size)
{
  void		*allocated_block;

  size = align4(size);
  if (size <= 0)
    return (NULL);
  if ((allocated_block = find_free_block(size)) == NULL)
    {
      if ((allocated_block = extend_memory(size)) == NULL)
	return (NULL);
    }
  return (allocated_block);
}
