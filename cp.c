#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "fs.h"

#define BUF_SIZE 256



int main(int argc, char *argv[])
{
	
	if (argc !=3)
	{
		printf(1, "masukkan [cp src_file dest_file]\n");
		exit();
	}
	
	
	int fd_src = open(argv[1], O_RDONLY);
	if (fd_src == -1)
	{
		printf(1, "file asal tidak bisa dibuka\n");
		exit();
	}
	
	
	struct stat st;
	fstat(fd_src, &st);
	if (st.type == T_DIR)
	{
		printf(1, "file asal adalah direktori\n");
		
		exit();
	}

	
	char com[128] = {};
	strcpy(com, argv[2]);
	int len1 = strlen(argv[1]);
	int len2 = strlen(argv[2]);
	if (argv[2][len2-1] == '/')
	{
		
		int i = len1 - 1;
		for (; i >= 0; i--)
			if (argv[1][i] == '/')
				break;
		i++;
		strcpy(&com[len2], &argv[1][i]);
	}
	

	int fd_dest = open(com, O_WRONLY|O_CREATE);
	if (fd_dest == -1)
	{
		printf(1, "gagal membuat file baru\n");
		exit();
	}
	
	
	char buf[BUF_SIZE] = {};
	int len = 0;
	while((len = read(fd_src, buf, BUF_SIZE)) > 0)
		write(fd_dest, buf, len);
	
	
	close(fd_src);
	close(fd_dest);
	exit();
}


