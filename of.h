#include <cstdlib> 
#include <iostream> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 

using namespace std;


void openfile(char *path)
{ 
int fd;
if(fd=open(path, O_CREAT, S_IRWXU)==-1)
    err1();
else 
    cout<<"File opening/creation succesfull\n";
} 