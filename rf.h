#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h> 

#define BS 1 //Размер буфера

using namespace std ;

void renamefile(char *path, char *nname) //На вход 2 параметра, первый имя файла, второй, новое имя файла
{
char buf1[BS];
int i=0, ffd, sfd;
ssize_t count;

ffd=open(path, O_RDONLY); //Открываем файл, для чтения

	if(ffd==-1)  //Если ошибка, вызываем функцию из заголовочного файла
		err1();

	sfd=open(nname, O_WRONLY|O_CREAT|O_EXCL, 0644); //Открываем(создаем файл)
	
	if ( sfd ==-1) //Если ошибка, вызываем функцию из заголовочного файла
		err1();

	while((count=read(ffd,buf1,BS))>0) //Побайтово считываем данные из исходного файла

	{
		write(sfd, buf1, count); //Записываем данные в новый файл
		i++; //Считываем байты

	}

	if(count==-1)
		err1(); //Если ошибка, обрабатываем ее

	cout<<"Copy sucсesfull\n"; //Сообщаем о копировании
    // Добавил проверку на создание нового файла
    // В зависимости от ситуации будет разное сообщение
    if (i > 0)
	    cout<<"Bytes copyed:"<<i; //Количество скопированных байт
    else 
        cout<<"The file was not found, a new file was created."; //сообщим о создании пустого файла
	close(ffd); 
	unlink(path); //Удаление исходного файла
	cout<<"\nSource file sucsefully deleted\n"; //Сообщаем об удалении
	close (sfd);
}