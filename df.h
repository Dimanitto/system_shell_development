#include <cstdlib> 
#include <unistd.h>    // данная библиотека для вызова функции unlink 
#include <iostream> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 

using namespace std;

// функция удаления файла
void delfile(char *path) 
{
if(unlink(path)==-1)
    err1();
else
    cout<<"File deleting succesfull\n";
}