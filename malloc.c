/*
** malloc.c for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jan 26 23:51:05 2016 Erwan Dupard
** Last update Mon Feb  8 15:02:20 2016 Erwan Dupard
*/

#include <errno.h>
#include <unistd.h>
#include "ressources.h"

extern t_block	*g_data;
extern t_block	*g_last;

t_block		*get_last()
{
  t_block	*iterator;

  iterator = g_data;
  while (iterator->next)
    iterator = iterator->next;
  return (iterator);
}

void		*my_extend_memory(size_t size)
{
  t_block	*new;

  if ((new = sbrk(0)) == (void *) -1)
    return (NULL);
  if (sbrk(NODE_SIZE + size) == (void *) -1)
    return (NULL);
  new->size = size;
  new->free = STATUS_NFREE;
  new->next = NULL;
  if (g_data == NULL)
    {
      g_data = new;
      new->prev = NULL;
      return (new->data);
    }
  if (!g_last)
    g_last = get_last();
  g_last->next = new;
  new->prev = g_last;
  return (new->data);
}

static void	*find_free_block(size_t size)
{
  t_block	*iterator;

  iterator = g_data;
  if (iterator == NULL)
    return (NULL);
  while (iterator)
    {
      if (iterator->free == STATUS_FREE && iterator->size >= size)
	{
	  iterator->free = STATUS_NFREE;
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
      if ((allocated_block = my_extend_memory(size)) == NULL)
	return (NULL);
    }
  return (allocated_block);
}
