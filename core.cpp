#include <cstdlib> 
#include <iostream> 
#include <string.h> 
#include "err1.h" /* Модуль – обработчик ошибок */
#include "of.h"   /* Mодуль - открытия файла */
#include "df.h"   /* Модуль - удаления файла */
#include "rf.h"   /* Модуль - переименования файла */
#include "cp.h"   /* Модуль - копирования файла */
#include "md.h"   /* Модуль - создания каталога */
#include "rd.h"   /* Модуль - удаления каталога */
#include "stfile.h" /* Модуль - вывода информации о модуле */
#include "cutef.h"  /* Модуль - вырезания файла */

using namespace std;


int main()
{
char path[300];
char nname[300];
char c[50];
cout <<"if you want delete file type \"del-f\"\n";
cout <<"if you want open file type \"op-f\"\n";
cout <<"if you want withdraw file stats type \"st-f\"\n";
cout <<"if you want copy file type \"cp-f\"\n";
cout <<"if you want rename file type \"rn-f\"\n";
cout <<"if you want delete dir type \"del-d\"\n";
cout <<"if you want create dir type \"cr-d\"\n";
cout <<"if you want to cut the file \"cut-f\"\n";
cout <<"if you want exit type \"exit\"\n";
// бесконечный цикл
while(1)
{ 
    cin>>c;
    // выход из цикла
    if(strcmp(c, "exit")==0) 
        return 0;
    // вызов функции открытия/закрытия файла
    if(strcmp(c, "op-f")==0)
    {
        cout<<"Enter path name\n";
        cin>>path;
        openfile(path);
        cout<<" Enter command\n";  
    }
    // вызов функции удаления файла
    if(strcmp(c, "del-f")==0)
    {
        cout<<"Enter path name\n";
        cin>>path;
        delfile(path);
        cout<<"Enter command\n";
    }
    // вызов функции переименования файла
    if(strcmp(c, "rn-f")==0)
    { 
        cout<<"Enter path name\n";
        cin>>path;
        cout<<"enter new name\n";
        cin>>nname;
        renamefile(path,nname);
        cout<<"Enter command\n";
    } 
    // вызов функции копирования файла
    if(strcmp(c,"cp-f")==0)
    {
        cout<<"Enter path name\n";
        cin>>path;
        cout<<"enter new name\n";
        cin>>nname;
        copyfile(path, nname);
        cout<<"Enter command\n";
    }
    // вызов функции создания каталога
    if(strcmp(c,"cr-d")==0) 
    {
        cout<<"Enter path name\n";
        cin>>path;
        makedir(path);
        cout<<"Enter command\n";
    }
    // вызов функции удаления каталога
    if(strcmp(c, "del-d")==0)
    { 
        cout<<"Enter path name\n";
        cin>>path;
        deldir(path);
        cout<<"Enter command\n";
    }
    // вызов функции вывода информации о файле или каталоге
    if(strcmp(c,"st-f")==0) 
    {
        cout<<"Enter path name\n";
        cin>>path;
        statfile(path);
        cout<<"Enter commаnd\n";
    }
    // вызов функции вырезания файла
    if(strcmp(c,"cut-f")==0) 
    {
        cout<<"Enter path name\n";
        cin>>path;
        cout<<"enter new directory (for example: home/user/ or ..)\n";
        cin>>nname;
        cutefile(path, nname);
        cout<<"Enter commаnd\n";
    }
}
}