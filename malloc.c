/*
** malloc.c for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jan 26 23:51:05 2016 Erwan Dupard
** Last update Wed Feb  3 17:03:33 2016 Barthelemy Gouby
*/

#include <unistd.h>
#include "ressources.h"

void		*g_data;

void		*extend_memory(size_t size)
{
  t_block	*new;
  t_block	*iterator;

  new = sbrk(0);
  if (sbrk(NODE_SIZE + size) == (void *) -1)
    return (NULL);
  new->size = size;
  new->free = 0;
  new->next = NULL;
  if (g_data == NULL)
    {
      g_data = new;
      new->prev = NULL;
      return (new->data);
    }
  iterator = g_data;
  while (iterator->next)
    iterator = iterator->next;
  new->prev = iterator;
  iterator->next = new;
  return (new->data);
}

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

void		*malloc(size_t size)
{
  void		*allocated_block;

  size = align4(size);
  printf("size: %lu\n", size);
  if (size <= 0) {
    printf("invalid size\n");
    return (NULL);
  }
  if ((allocated_block = find_free_block(size)) == NULL)
    {
      if ((allocated_block = extend_memory(size)) == NULL) {
	printf("malloc failed\n");
	return (NULL);
      }
    }
  return (allocated_block);
}
