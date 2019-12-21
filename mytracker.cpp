#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<myclient.h>
#include<myserver.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
using namespace std;
#define BUFFERSIZE 2048
int tracker_port;
bool mutex_for_server=false;
char tracker_IP[20];


struct compare{
	bool operator()(char const *a, char const *b)const{
		return strcmp(a,b)<0;
	}
}
struct st_client
struct st_userid
struct st_upload
struct st_group;


int main(int argc , char** argv){
	/* INPUT
	1. Tracker IP
	2. Tracker port
	3. tracker_info.txt
	*/

	if(argc <4){
		cout<<"Invalid Input"<<endl;
		exit(EXIT_SUCCESS);
	}

strcpy(server_IP,argv[1]);
server_port = atoi(argv[2]);
FILE *fileptr = fopen(argv[3],"rb+");

char buffer[512];
memset(buffer, '\0',512);
fread(buffer,sizeof(char),512,fileptr);


char * temp  = strtok(buffer,"\n");
strcpy(tracker_IP,temp);
temp = strtok(NULL,"\n");
tracker_port = atoi(temp);





//create threads;

pthread_t client_thread_id,server_thread_id;

strcpy(userid ,"");

int server_success = pthread_create(&server_thread_id,NULL, &serverhandler,NULL);
if(server_success !=0){
cout<<"Server initialisation error"<<endl;
return -1;	
}
int client_success = pthread_create(&client_thread_id,NULL, &clienthandler,NULL);
if(client_success !=0){
cout<<"Client  initialisation error"<<endl;
return -1;	
}




pthread_join(server_thread_id,NULL);
return 0;
}

