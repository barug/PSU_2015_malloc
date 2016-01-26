//
// ressources.h for malloc in /home/dupard_e/rendus/PSU_2015_malloc
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Jan 26 23:51:38 2016 Erwan Dupard
// Last update Tue Jan 26 23:54:51 2016 Erwan Dupard
//

#ifndef RESSOURCES_H_
# define RESSOURCES_H_

# include <unistd.h>

void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		free(void *ptr);

#endif /* ! RESSOURCES_H_ */
