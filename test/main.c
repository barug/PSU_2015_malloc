/*
** main.c for main_test in /home/dupard_e/rendus/PSU_2015_malloc/test
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jan 28 10:17:31 2016 Erwan Dupard
** Last update Mon Feb  1 17:38:49 2016 Erwan Dupard
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

# define align4(x) (((((x) - 1) >> 2) << 2) + 4)
# define TEST ("BARTHELEMIUUAAAAAAAAAAAAAAAAAABARTHELEMIUUAAAAAAAAAAAAAAAAAABARTHELEMIUUAAAAAAAAAAAAAAAAAABARTHELEMIUUAAAAAAAAAAAAAAAAAA")

int		main()
{
  char		*str;
  int		i = 0;

  while (i < 5)
    {
      if ((str = malloc(sizeof(*str) * (strlen(TEST) + 1))) == NULL)
	return (1);
      str = strcpy(str, TEST);
      printf("str : %s\n", str);
      ++i;
    }
  my_memory_dump();
  return (0);
}
