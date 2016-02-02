/*
** realloc.c for realloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Feb  1 14:44:26 2016 Erwan Dupard
** Last update Tue Feb  2 11:16:49 2016 Barthelemy Gouby
*/

#include "ressources.h"

static void	*find_free_block(size_t size)
{
  t_block	*iterator;

  iterator = g_data;
  if (!iterator)
    return (NULL);
  while (iterator->next)
    {
      if (iterator->free && iterator->size >= size)
	{
	  iterator->free = 0;
	  return (iterator->data);
	}
      iterator = iterator->next;
    }
  return (NULL);
}

void		*realloc(void *ptr, size_t size)
{
  t_block	*currentElem;

  if (ptr == NULL)
    return (malloc(size));
  currentElem = get_elem_by_ptr(ptr);
  if (currentElem->size >= size)
    return (currentElem);
  else
    currentElem = find_free_block(currentElem, size);
  return (NULL);
}
