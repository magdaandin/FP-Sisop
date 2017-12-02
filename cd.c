#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int
main(int argc, char *argv[])
{
	if (argc ==0 ) {
		chdir("/home");
	}

	else {
	chdir(*argv);
	}

	

	exit();
}
