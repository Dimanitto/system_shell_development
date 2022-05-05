#include <cstdlib> 
#include <iostream> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 

using namespace std;

#define BS 1 
char buf[BS];
// Первый параметр имя исходного файла; второй параметр: имя файла куда будет записана информация
void copyfile(char *path, char *nname)
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
    //Создаем файл для записи
    sfd=open(nname,O_WRONLY|O_CREAT|O_EXCL,0644);
    if(sfd==-1)
        err1(); //Вызов функции обработки ошибок, если не удалось создать файл
    while(count=read(ffd,buf,BS)>0) // Побайтовое считывание информации
    { 	
        write(sfd,buf,count);   // записываем данные в новый файл
        i++;        // счетчик считанных байт
    }
    if(count==-1)
        err1(); // вызов функции обработки ошибок, если запись файла не удалась
    cout<<"Copy succefull\n";
    // Добавил проверку на кол-во скопирванных байт
    if (i > 0)
        cout<<"Bytes copyed: "<<i<<endl;
    else    // если был скопирован пустой файл будет выведено:
        cout<<"A new empty file has been copied.\n";
    close(sfd);
}
close(ffd);
}