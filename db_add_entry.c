

#include "ft_db.h"

t_character *add_character(char *name, char *class, char *job, char *title)
{
  t_character *new;

  new = (t_character*)malloc(sizeof(t_character));
  new->next = NULL;
  new->name = name;
  new->class = class;
  new->job = job;
  new->title = title;
  return (new);
}

char *add_entry(char *str)
{
  char *path;
  int result_code;
  
  path = "/nfs/2016/s/sdarsie/ft_db/database/";
  path = ft_strjoin(path, str);
  //  ft_putstr(path);
  result_code = mkdir(path, S_IRWXU | S_IRWXG | S_IRWXO);
  printf("%d\n", result_code);
  return (path);
}

int main(int ac, char **av)
{
  if (ac != 6)
    {
      write(1, "usage: ./new_entry 'dir_name' 'name' 'class' 'occupation' 'title'\n", 66);
      return (0);
    }
  int fd;
  char *path;
  t_character *dets;

  dets = add_character(av[2], av[3], av[4], av[5]);
  /* close(fd); */
  path = add_entry(av[1]);
  db_details(dets, path);
  return (0);
}
