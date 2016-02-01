/*
** malloc.c for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jan 26 23:51:05 2016 Erwan Dupard
** Last update Mon Feb  1 12:09:02 2016 Barthelemy Gouby
*/

#include <unistd.h>
#include "ressources.h"

void		*g_data = NULL;

static void	*extend_memory(size_t size)
{
  t_block	*new;
  t_block	*iterator;
  void		*test_ptr;

  size += 50;
  new = sbrk(0);
  printf("node size: %lu, size: %lu\n", NODE_SIZE, size);
  if (sbrk(NODE_SIZE + size) == (void *) -1)
    {
      printf("increment failed\n");
      return (NULL);
    }
  test_ptr = sbrk(0);
  printf("supposed allocated block size: %lu\n", NODE_SIZE + size);
  printf("new node ptr: %p\n", new);
  printf("heap break point: %p\n", test_ptr);
  printf("real allocated block size: %lu\n", (long unsigned int) (test_ptr) - (long unsigned int) (new));
  new->data = (char *)(new + NODE_SIZE);
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

  printf("executing malloc\n");
  printf("raw data size: %lu\n", size);
  size = align4(size);
  printf("aligned data size: %lu\n", size);
  if (size <= 0)
    return (NULL);
  if ((allocated_block = find_free_block(size)) == NULL)
    {
      if ((allocated_block = extend_memory(size)) == NULL)
	return (NULL);
    }
  printf("----------------\n");
  return (allocated_block);
}
