#include <stdio.h>
#include <fcnt.l>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if(argc != 4)
    {
      printf("nr de argumente gresit");
      exit(-1);
    }

  int fd_in = open(argv[1], O_RDONLY);
  if(fd_in < 0)
    {
      perror("eroare la deschiderea fisierului");
      exit(-1);
    }

  char c = argv[3][0];
  char buff[1024];

  int l_mici = 0, l_mari = 0, cif = 0, ap_c = 0;
  int n;
  
  while(n = read(fd_in, buff, sizeof(buff))
    {
      for(int i = 0; i < n; i++)
	{
      if(buff[i] >= 'a' && buff[i] <= 'z')
	l_mici++;
      else
	if(buff[i] >= 'A' && buff[i] <= 'Z')
	  l_mari++;
	else
	  if(buff[i] >= '0' && buff[i] <= '9')
	    cif++;
	  else
	    if(buff[i] == c)
 	      ap_c++;
	}
    }

  int fd_out = open(argv[2], O_WRONLY);
  if(fd_out < 0)
    {
      perror("eroare la deschiderea fisierului");
      exit(-1);
    }

  char valori[512];
   

  close(fd_in);
  close(fd_out);
  return 0;
}
