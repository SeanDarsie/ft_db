/* Header */

#include "ft_db.h"

void print_file(int fd)
{
  char *line;

  line = (char*)malloc(100);
  while (get_next_line(fd, &line))
    printf("%s\n", line);
  
}

int main(int ac, char **av)
{
  int fd;
  char *path;
  char *tmp;
  
  if (ac != 2)
    {
      write(1, "usage: ./edit entry_name\n", 25);
      return (0);
    }
  path = "/nfs/2016/s/sdarsie/ft_db/database/";
  path = ft_strjoin(path, av[1]);
  tmp = path;
  path = ft_strjoin(path, "/info.txt");
  free(tmp);
  if ((fd = open(path, O_RDONLY)) == -1)
    {
      write(1, "file not found\n", 15);
      exit(1);
    }
  print_file(fd);
}
