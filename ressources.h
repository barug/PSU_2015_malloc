/*
** ressources.h for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jan 28 10:25:45 2016 Erwan Dupard
<<<<<<< HEAD
// Last update Fri Feb  5 12:44:05 2016 Barthelemy Gouby
=======
// Last update Thu Feb  4 18:26:00 2016 Erwan Dupard
>>>>>>> bb8843987d54e7948b7a04910b746c5c1f361ec2
*/

#ifndef RESSOURCES_H_
# define RESSOURCES_H_

# include <stdio.h>
# include <unistd.h>

# define RETURN_SUCCESS (0)
# define RETURN_FAILURE (1)

# define STATUS_FREE	(1)
# define STATUS_NFREE	(0)

# define align4(x) (((((x) - 1) >> 2) << 2) + 4)

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
void			*extend_memory(size_t size);

/*
 * Retreive Block by data pointer
 */
t_block			*get_elem_by_ptr(void *ptr);

/*
 * Dump Memory (HEX && ASCII)
 */
void			my_memory_dump();
void			heap_dump();
/*
 * Heap Linked list ((META-DATA) DATA ) ---> ((META-DATA) DATA ) ---> NIL
 */
extern t_block		*g_data;
extern void		*heap_start;

#endif /* ! RESSOURCES_H_ */
