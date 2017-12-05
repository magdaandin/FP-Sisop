<<<<<<< HEAD
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
=======
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "types.h"
>>>>>>> 1db582599307ae341dd46834e58b4ad4b46ebde0

int
main(int argc, char *argv[])
{
<<<<<<< HEAD
	if (argc <= 1) {
		printf(1, "Please input this command as [touch file_name1 file_name2 ...]\n");
=======
	if (argc <2) {
		printf(1, "masukkan [touch file_name1 file_name2 ...]\n");
>>>>>>> 1db582599307ae341dd46834e58b4ad4b46ebde0
	}

	int i, count = 0;
	for (i = 1; i < argc; i++) {		
<<<<<<< HEAD
		int fd;
		
		if ((fd = open(argv[i], O_RDONLY)) < 0) {
			
			fd = open(argv[i], O_CREATE|O_RDONLY);
			count++;
		}
		close(fd);
	}

	printf(1, "%d file(s) created, %d file(s) skiped.\n", count, argc - 1 - count);
=======
		int a;
		
		if ((fd = open(argv[i], O_RDONLY)) < 0) {
			
			a = open(argv[i], O_CREATE|O_RDONLY);
			count++;
		}
		close(a);
	}

	printf(1, "%d file(s) terbuat, %d file(s) terlewati.\n", count, argc - 1 - count);
>>>>>>> 1db582599307ae341dd46834e58b4ad4b46ebde0

	exit();
}
