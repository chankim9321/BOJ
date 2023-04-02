#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	char* filename = argv[1];
	struct stat buf;
	stat(filename, &buf);

	printf("Mode = %o\n", (unsigned int)buf.st_mode);
	int kind = buf.st_mode & 0xF000;
	//printf("kind = %d\n", kind);
	if(kind == 0xA000) printf("%s : symbolic\n",filename);
	if(kind == 0x4000) printf("%s : Directory\n",filename);
	if(kind == 0x8000) printf("%s : Regular \n", filename);
	return 0;
}
