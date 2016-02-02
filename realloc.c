/*
** realloc.c for realloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Feb  1 14:44:26 2016 Erwan Dupard
** Last update Tue Feb  2 16:53:36 2016 Barthelemy Gouby
*/

#include "ressources.h"

void		*g_data;

static void	*copyBlock(t_block *d, t_block *s)
{
  size_t	i;

  i = -1;
  while (++i < s->size)
    d->data[i] = s->data[i];
  free(s->data);
  return (d);
}

void		*realloc(void *ptr, size_t size)
{
  t_block	*iterator;
  t_block	*original;
  t_block	*newBlock;

  if (ptr == NULL)
    return (malloc(size));
  original = get_elem_by_ptr(ptr);
  if (original->size >= size)
    return (original);
  iterator = g_data;
  while (iterator)
    {
      if (iterator->size >= size && iterator->free == 1)
	return (copyBlock(iterator, original));
      iterator = iterator->next;
    }
  newBlock = extend_memory(size);
  return (copyBlock(newBlock, original));
}
