
/* in this function the goal is to create a .log file that will contain the information requested. */
/* first we have to handle the request, then create the file */
/* <header> */

#include "ft_db.h"

char *index_log(char *path, char *log, int i)
{
  char *tmp;

  log = ft_strjoin("log", ft_itoa(i));
  tmp = log;
  // log = ft_strjoin(log, ".txt");
  free (tmp);
  return (ft_strjoin(path, log));
}

char *db_query(char *path)
{
  int i;
  char *tmp;
  char *log;
  char *tmp2;
  
  i = 1;
  tmp = ft_strjoin(path, "log");
  while (mkdir(tmp, S_IRWXU | S_IRWXG | S_IRWXO) == -1)
    {
      tmp2 = tmp;
      tmp = index_log(path, "log" , i);
      free(tmp2);
      i++;
    }
  if (i == 1)
    printf("log created\n");
  else
    printf("log%i created\n", (i - 1));
  return (tmp);
}

void time_created(FILE *log)
{
    char buff[30];
    struct tm *sTm;

    time_t now = time (0);
    sTm = gmtime (&now);

    strftime (buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);
    fprintf(log, "Log created at: %s\n", buff);
}

void write_to_log_file(char *path, char *q_path)
{
  char *tmp;
  int fd;
  char *line;
  FILE *log;

  if ((fd = open(q_path, O_RDONLY)) == -1)
    {
      write(1, "file not found\n", 15);
      exit(1);
    }
  //  printf("read: %s\n", q_path);
  line = (char*)malloc(100);
  tmp = path;
  path = ft_strjoin(path, "/log.txt");
  log = fopen(path, "w");
  time_created(log);
  while(get_next_line(fd, &line))
    fprintf(log, "%s\n", line);
  fclose(log);
}

int main(int ac, char **av)
{
  char *path;
  char *q_path;
  char *tmp;

  if (ac != 2)
    {
      write(1, "usage: ./query 'name of data entry'\n", 37);
      return (0);
    }
  path = "/nfs/2016/s/sdarsie/ft_db/database/logs/";
  path = db_query(path);
  q_path = ft_strjoin("/nfs/2016/s/sdarsie/ft_db/database/", av[1]);
  tmp = q_path;
  q_path = ft_strjoin(q_path, "/info.txt");
  free (tmp);
  write_to_log_file(path, q_path);
  free (path);
}
