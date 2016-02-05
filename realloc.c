/*
** realloc.c for realloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Feb  1 14:44:26 2016 Erwan Dupard
** Last update Fri Feb  5 16:10:28 2016 Erwan Dupard
*/

#include "ressources.h"

extern t_block		*g_data;

static void	*copyBlock(t_block *d, t_block *s)
{
  size_t	i;

  i = 0;
  while (i < s->size)
    {
      d->data[i] = s->data[i];
      ++i;
    }
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
  original = get_elem_by_ptr(ptr);
  if (original->size >= size)
    return (original->data);
  iterator = g_data;
  while (iterator)
    {
      if (iterator->size >= size && iterator->free == STATUS_FREE)
	{
	  iterator->free = STATUS_NFREE;
	  return (copyBlock(iterator, original));
	}
      iterator = iterator->next;
    }
  if ((newBlock = my_extend_memory(size)) == NULL)
    return (NULL);
  newBlock = get_elem_by_ptr(newBlock);
  return (copyBlock(newBlock, original));
}
