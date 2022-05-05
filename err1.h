#include <iostream> 
#include <errno.h> 
#include <string.h> 

using namespace std;

void err1()
{
    cout<<"Error: "<<strerror(errno)<<"\n";  
    return;
}