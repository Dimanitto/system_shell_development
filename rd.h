#include <cstdlib> 
#include <unistd.h> 
#include <iostream> 
#include <sys/types.h> 
#include <dirent.h> 
#include <errno.h> 
#include <string.h> 

using namespace std;

// в параметре приходит название каталога
void deldir(char *path)
{
DIR *dir;
int u;
struct dirent *sdir;
dir=opendir(path);  // открываем каталог
if(dir==NULL)   // если не удалось открыть каталог (не существует)
    err1();     // вызываем функцию обработки ошибок
// если же удалось открыть каталог идем дальше
// добавил ветку else, без нее в случае ошибки!!!!!!!!!!!!!!
// программный код завершался с ошибкой!!!!!!!!!!!!!
else {
chdir(path);    // chdir изменяет текущий каталог на path.
while((sdir=readdir(dir))!=NULL)    // функция readdir() возвращает указатель на структуру dirent
// Если достигнут конец потока каталога, то возвращается NULL
{ 
    u=unlink(sdir->d_name);        // функция unlink удаляет ссылки на файл
if(u==-1 && errno==EISDIR)      // если попытка не удалась
    {
        //Если родительский и текущий каталог совпадают, пропускаем итерацию
        if(strcmp(".", sdir->d_name)==0 || strcmp("..", sdir->d_name)==0) 
            continue;
        deldir(sdir->d_name);   // передаем имя сл. каталога
    } 
    if(u==-1 && errno==!EISDIR) // если снова попытка не удалась
        err1();     // вызываем функцию обработки ошибок
} 
closedir(dir);  //закрываем каталог
chdir("..");    // переход в родительский каталог
if(rmdir(path)==-1) // удаление каталога
    err1(); // в случае ошибки вызов функции обработки ошибок
}
cout<<"Directory deleted!\n";
}