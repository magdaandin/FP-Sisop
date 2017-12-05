#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
    

	if (argc ==0 ) {
		if(chdir("/home")<0) printf(1,"error");
	}

	else {
	
	
	if(chdir(*argv)<0)printf(1,"error");
	}

	

	exit();
}
