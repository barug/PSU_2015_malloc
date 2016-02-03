/*
** realloc.c for realloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Feb  1 14:44:26 2016 Erwan Dupard
** Last update Wed Feb  3 16:38:58 2016 Erwan Dupard
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
  return (d->data);
}

void		*realloc(void *ptr, size_t size)
{
  t_block	*iterator;
  t_block	*original;
  t_block	*newBlock;

  if (ptr == NULL)
    return (malloc(size));

  if (size == 0)
    {
      free (ptr);
      return (NULL);
    }

  original = get_elem_by_ptr(ptr);
  if (original->size >= size)
    return (original->data);
  iterator = g_data;
  while (iterator)
    {
      if (iterator->size >= size && iterator->free == 1)
	{
	  iterator->free = 0;
	  return (copyBlock(iterator, original));
	}
      iterator = iterator->next;
    }
  newBlock = extend_memory(size);
  return (copyBlock(newBlock, original));
}
