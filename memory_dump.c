/*
** memory_dump.c for memory_dump in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Feb  1 17:21:36 2016 Erwan Dupard
** Last update Fri Feb  5 16:29:13 2016 Erwan Dupard
*/

#include "ressources.h"

# define IS_PRINTABLE(c) ((c >= ' ' && c <= '~'))

t_block			*g_data;

void			dump_node(t_block *node)
{
  printf("node : %p\n", node);
  printf("node->next : %p\n", node->next);
  printf("node->prev : %p\n", node->prev);
  printf("node->size : %lu\n", node->size);
  printf("node->free : %d\n", node->free);
  printf("node->data : %p\n\n", node->data);
}

static void		display_block_data(t_block *block)
{
  size_t		i = 0;

  printf("[+] ASCII :\n");
  while (i < block->size)
    {
      printf("%c", (IS_PRINTABLE(block->data[i]) ? block->data[i] : '.'));
      if (i % 10 == 0)
	printf("\n");
      ++i;
    }
  printf("\n");
  printf("[+] HEX :\n");
  i = 0;
  while (i < block->size)
    {
      printf("%x ", block->data[i] > 0 ? block->data[i] : 255);
      if (i % 10 == 0)
	printf("\n");
      ++i;
    }
  printf("\n");
}

void			my_memory_dump()
{
  t_block		*iterator;

  iterator = g_data;
  while (iterator)
    {
      printf("\n\n[^] Block {%p} %lu bytes\n", iterator, iterator->size);
      display_block_data(iterator);
      iterator = iterator->next;
    }
}

void			heap_dump()
{
  t_block		*iterator;

  iterator = g_data;
  printf("Heap start at : %p\n", iterator);
  while (iterator)
    {
      printf("--> node %p\n", iterator);
      iterator = iterator->next;
    }
}
