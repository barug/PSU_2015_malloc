/*
** main.c for test main in /home/barthe_g/rendu/tek2/unix_Reseau/PSU_2015_malloc
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Jan 29 15:28:14 2016 Barthelemy Gouby
** Last update Fri Jan 29 16:47:45 2016 Barthelemy Gouby
*/

#include "ressources.h"

int	main()
{
  int	*int1;
  int	*int2;
  int	*int3;
  int	*int4;
  int	*int5;

  if (!(int1 = malloc(sizeof(int1))))
    printf("malloc failed\n");
  if (!(int2 = malloc(sizeof(int2))))
      printf("malloc failed\n");
  if (!(int3 = malloc(sizeof(int3))))
      printf("malloc failed\n");
  if (!(int4 = malloc(sizeof(int4))))
      printf("malloc failed\n");

  printf("int1: %p\n", int1);
  printf("int2: %p\n", int2);
  printf("int3: %p\n", int3);
  printf("int4: %p\n\n", int4);

  free(int2);

  if (!(int5 = malloc(sizeof(int5))))
      printf("malloc failed\n");
  printf("int1: %p\n", int1);
  printf("int5: %p\n", int5);
  printf("int3: %p\n", int3);
  printf("int4: %p\n\n", int4);
  free(int4);
  if (!(int4 = malloc(sizeof(int4))))
      printf("malloc failed\n");
  printf("int1: %p\n", int1);
  printf("int5: %p\n", int5);
  printf("int3: %p\n", int3);
  printf("int4: %p\n\n", int4);

  *int1 = 1;
  *int5 = 5;
  *int3 = 3;
  *int4 = 4;
  
  printf("int1: %i, int5: %i, int3: %i, int4: %i\n", *int1, *int5, *int3, *int4);
  return (0);
}
