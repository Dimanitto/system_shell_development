#include <cstdlib> 
#include <unistd.h> 
#include <iostream> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h> 
#include <errno.h> 
#include <string.h> 

using namespace std;

// в 1м параметре приходит название файла, во 2м путь для перемещения
void cutefile(char *path, char *nname)
{
int i=0, ffd, sfd;
ssize_t count;
// Открываем файл только для чтения для последующего копирования
ffd=open(path,O_RDONLY);
if(ffd==-1) //Вызов функции обработки ошибок, если не удалось открыть файл
    err1();
// Добавил условие else для продолжения работы
// Если файл не существует - копировать не чего
else
{
    char b[128];
    char *core;
    core = getcwd(b, 128);      // запомнить путь к исходному файлу, для последуюущего удаления
    if(chdir(nname) == -1)    // переход в каталог
        err1();      // если не удалось перейти в каталог вызовем ошибку
    else{
     //Создаем файл для записи
    sfd=open(path, O_WRONLY|O_CREAT|O_EXCL, 0644);
    if(sfd==-1)
        err1(); //Вызов функции обработки ошибок, если не удалось создать файл
    while(count=read(ffd,buf,BS)>0) // Побайтовое считывание информации
    { 	
        write(sfd,buf,count);   // записываем данные в новый файл
        i++;        // счетчик считанных байт
    }
    if(count==-1)
        err1(); // вызов функции обработки ошибок, если запись файла не удалась
    cout<<"Successfully cut\n";
    // Добавил проверку на кол-во скопирванных байт
    if (i > 0)
        cout<<"Bytes copyed: "<<i<<endl;
    else    // если был вырезан пустой файл будет выведено:
        cout<<"A new empty file has been copied.\n";
    close(sfd);
    }
    chdir(core);    // вернемся в исходный каталог, для последующего удаления исходного файла
}
close(ffd);
//char s[100];
//cout<<getcwd(s, 100)<<endl;
unlink(path); //Удаление исходного файла
}