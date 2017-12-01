#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "types.h"

int
main(int argc, char *argv[])
{
	if (argc <2) {
		printf(1, "masukkan [touch file_name1 file_name2 ...]\n");
	}

	int i, count = 0;
	for (i = 1; i < argc; i++) {		
		int a;
		
		if ((fd = open(argv[i], O_RDONLY)) < 0) {
			
			a = open(argv[i], O_CREATE|O_RDONLY);
			count++;
		}
		close(a);
	}

	printf(1, "%d file(s) terbuat, %d file(s) terlewati.\n", count, argc - 1 - count);

	exit();
}
