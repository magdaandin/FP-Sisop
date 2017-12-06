#include "types.h"
#include "stat.h"
#include "user.h"



int
main(int argc, char *argv[])
{
  int i;

  if(argc <= 1){
    printf(2, "masukkan: rm namafiles...\n");
    exit();
  }




  for(i = 1; i < argc; i++){
    if(unlink(argv[i]) < 0){
      printf(2, "tidak dapat menghapus %s\n", argv[i]);
     continue;
    }
  }

  exit();
}
