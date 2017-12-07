#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "fs.h"


char*
alamat(char *path);

void
ls(char *path);
int fStrStr(char* str, char* strSub)
{
    int i=0, j=0;
    int nTemp = i;
    int nStrLen = strlen(str);
    int nStrSubLen = strlen(strSub);
    for(i=0; i<nStrLen-nStrSubLen; i++)
    {
        nTemp = i;
        for(j=0; j<nStrSubLen; j++)
        {
             
            if(str[nTemp]==strSub[j])
            {
                if(j==nStrSubLen-1)
                    return 1;
                nTemp++;
            }
            else
                break;
        }
    }
    return 0;
}
 

int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2){
    ls(".");
    exit();
  }
  for(i=1; i<argc; i++)
    ls(argv[i]);
  exit();
}

char*
alamat(char *path)
{
  static char buf[DIRSIZ+1];
  char *p;

  // Find first character after last slash.
  for(p=path+strlen(path); p >= path && *p != '/'; p--)
    ;
  p++;

  // Return blank-padded name.
  //if(strlen(p) >= DIRSIZ)
    //return p;
  memmove(buf, p, strlen(p));
  memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));
  return buf;
}

void
ls(char *path)
{
  char buf[512], *p;
  int fd;
  struct dirent de;
  struct stat st;

  if((fd = open(path, 0)) < 0){
    printf(2, "%s file tidak ditemukan \n", path);
    return;
  }

  if(fstat(fd, &st) < 0){
    printf(2, "ls: cannot stat %s\n", path);
    close(fd);
    return;
  }

  switch(st.type){
  case T_FILE:
    printf(1, "%s \t", alamat(path));
	printf(1,"\n");
    break;

  case T_DIR:
    if(strlen(path) + 1 + DIRSIZ + 1 > sizeof buf){
      printf(1, "ls: path too long\n");
      break;
    }
    strcpy(buf, path);
    p = buf+strlen(buf);
    *p++ = '/';

    while(read(fd, &de, sizeof(de)) == sizeof(de)){
      if(de.inum == 0)
        continue;
      memmove(p, de.name, DIRSIZ);
      p[DIRSIZ] = 0;
      if(stat(buf, &st) < 0){
        printf(1, "ls: cannot stat %s\n", buf);
        continue;
      }
	if (fStrStr(alamat(buf),path)){
	printf(1, "file ada");
      printf(1, "%s", alamat(buf));}}

    
	printf(1, "\n");
    break;
  }
  close(fd);

}
