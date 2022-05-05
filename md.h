#include <cstdlib> 
#include <iostream> 
#include <sys/types.h> 
#include <sys/stat.h>   // библиотека для вызова функции mkdir (создания каталога)

using namespace std;

// Первый параметр имя для создания нового каталога
void makedir(char *path) 
{
if(mkdir(path,0777)==0)
    cout<<"Directory created\n";
else
    err1();
}