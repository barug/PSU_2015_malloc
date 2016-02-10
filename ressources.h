/*
** ressources.h for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jan 28 10:25:45 2016 Erwan Dupard
// Last update Wed Feb 10 16:33:05 2016 Barthelemy Gouby
*/

#ifndef RESSOURCES_H_
# define RESSOURCES_H_

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

# define RETURN_SUCCESS (0)
# define RETURN_FAILURE (1)

# define STATUS_FREE	(1)
# define STATUS_NFREE	(0)

# define align8(x) (((((x) - 1) >> 3) << 3) + 8)

/*
 * Definition of memory block (set in malloc , used for free)
 * We can call this "Meta-data"
 * 
 * Heap representation
 */
typedef struct		s_block
{
  size_t		size;    /* Size of allocated block */
  int			free;
  struct s_block	*next;   /* Next memory block */
  struct s_block	*prev;	 /* Prev memory block */
  char			data[1];/* Pointer on s_block + sizeof(s_block) to have data pointer */
}			t_block;

/*
 * Size to jump at block to get data pointer
 */
# define NODE_SIZE	(32)

/*
 * Malloc implementation
 */
void			*malloc(size_t size);

/*
 * Realloc implementation
 */
void			*realloc(void *ptr, size_t size);

/*
 * Free implementation
 */
void			free(void *ptr);

/*
 * User readable memory dump
 */
void			show_alloc_mem();

/*
 * Extend memory (Heap)
 */
void			*my_extend_memory(size_t size);

/*
 * Retreive Block by data pointer
 */
t_block			*get_elem_by_ptr(void *ptr);


/*
 * Fusion prev block
 */
t_block			*fusion_prev_block(t_block *currentElem);

/*
 * Get the head end pointer
 */
void			*get_heap_end();

/*
 * Split block of adequate size
 */
void			split_block(t_block *block, size_t size);


/*
 * Dump Memory (HEX && ASCII)
 */
void			my_memory_dump();
void			heap_dump();
void			dump_node(t_block *);

/*
 * Heap Linked list ((META-DATA) DATA ) ---> ((META-DATA) DATA ) ---> NIL
 */
t_block			*g_data;
t_block			*g_last;
pthread_mutex_t		g_mutex;
char			g_mutex_initialized;
size_t			g_page_left;

#endif /* ! RESSOURCES_H_ */
