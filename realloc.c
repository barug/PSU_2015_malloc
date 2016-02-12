/*
** realloc.c for realloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Feb  1 14:44:26 2016 Erwan Dupard
** Last update Fri Feb 12 15:31:23 2016 Barthelemy Gouby
*/

#include "ressources.h"

extern t_block		*g_data;
extern pthread_mutex_t	g_mutex;
extern char		g_mutex_initialized;

static void	*copyBlock(t_block *d, t_block *s)
{
  size_t	i;

  i = 0;
  while (i < s->size && i < d->size)
    {
      d->data[i] = s->data[i];
      ++i;
    }
  free(s->data);
  return (d->data);
}

void		*realloc(void *ptr, size_t size)
{
  t_block	*original;
  t_block	*newBlock;

  if (ptr == NULL && size == 0)
    {
      free (ptr);
      return (NULL);
    }
  if (ptr == NULL && size > 0)
    return (malloc(size));
  original = get_elem_by_ptr(ptr);
  if (original->size >= size)
    return (original->data);
  if ((newBlock = malloc(size)) == NULL)
    return (NULL);
  newBlock = get_elem_by_ptr(newBlock);
  return (copyBlock(newBlock, original));
}
