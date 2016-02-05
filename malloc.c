/*
** malloc.c for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jan 26 23:51:05 2016 Erwan Dupard
** Last update Fri Feb  5 12:57:43 2016 Barthelemy Gouby
*/

#include <errno.h>
#include <unistd.h>
#include "ressources.h"

void		*heap_start = NULL;
t_block		*g_data = NULL;

void		*extend_memory(size_t size)
{
  t_block	*new;

  if ((new = sbrk(0)) == (void*) -1)
    {
      printf("THIS SBRK FAILED!! NEW IS INVALID!! WTF?!\n");
      perror(NULL);
      return (NULL);
    }
  if (g_data == NULL)
    heap_start = new;
  if (sbrk(NODE_SIZE + size) == (void *) -1)
    {
      printf("SBRK FAILED!! ABORT!!! ABORT!!!\n");
      printf("size demanded at failed call: %lu\n", NODE_SIZE + size);
      perror(NULL);
    }
  return (NULL);
  new->size = size;
  new->free = STATUS_NFREE;
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
  while (iterator)
    {
      if (iterator->next == (void *)0x1)
	{
	  printf("prev : %p\n", iterator->prev);
	  printf("next : %p\n", iterator->next);
	  printf("size : %lu\n", iterator->size);
	  printf("free : %d\n\n", iterator->free);
	}
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
  (void)find_free_block;
  if ((allocated_block = find_free_block(size)) == NULL)
    {
      if ((allocated_block = extend_memory(size)) == NULL)
	return (NULL);
    }
  return (allocated_block);
}
