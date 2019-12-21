#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define CHUNK_SIZE 512*1024


void *requestHandler(void *arg){
	//new socket fd
	int sockfd = *((int *)arg);


	char filename[256];
	int interval;
	int start;
	bool ackn = true;

	//receive start amd ack

	recv(sockfd, &start,sizeof(start),0);
	send(sockfd, &ackn, sizeof(ackn),0);



	memset(filename,'\0',sizeof(filename));

	//receive filename and send ackn

	recv(sockfd, &filename, sizeof(filename),0)
    send(sockfd, &ackn, sizeof(ackn),0)


// recceive interval

    recv(sockfd, &interval, sizeof(interval),0);
    send(sockfd,&ackn,sizeof(ackn),0);


    FILE *fileptr = fopen(filename,"rb");
    if(fileptr ==NULL){
    	cout<<"Could not open file "<<endl;
    }

    fseek(fileptr,0,SEEK_END);
  int size = ftell(fileptr);
  rewind(fileptr);

  auto ptr = filedetails_map.find(filename)
  struct filedetails var = ptr->second;
  cout<<"\n"<<var->bit_vector;


  //send size and recv ack

  send(sockfd, &size,sizeof(size),0);
  recv(sockfd, &ackn,sizeof(ackn),0);

  int chunk_count = ((size-1)/CHUNK_SIZE)-1;

  send(sockfd, &var->bit_vector,sizeof(var->bit_vector),0);
  recv(sockfd, ackn,sizeof(ackn),0);

  char bit_vector[chunk_count]="";
  recv(sockfd, &bit_vector,sizeof(bit_vector),0);
  send(sockfd, &ackn,sizeof(ackn),0);

//print
char buffer[BUFFERSIZE];
int n=0;

for(int i =0;i<chunk_count;i++){
   
   	fseek(fileptr, i*CHUNK_SIZE,SEEK_SET);
   	char chunk_buffer[CHUNK_SIZE];

   	if(bit_vector[i]=='1'){
   		cout<<"sending chunk : "<<i<<endl;
   		memset(chunk_buffer,'\0',CHUNK_SIZE);
   		int bytes_sent = 0;
   		int ackn =0;
   		while(CHUNK_SIZE >bytes_sent){
   			if((n=fread(buffer,sizeof(char),BUFFERSIZE,fileptr))>0){
   				cout<<n;
   				send(sockfd,buffer,n,0);
   				memset(buffer,'\0',BUFFERSIZE);
   				recv(sockfd, &ackn,sizeof(ackn),0);
   				bytes_sent +=BUFFERSIZE;
   			}
   			else{
   				cout<<"breaking while loop"<<endl;
					break;
   			}
   		}
   	}
 }

cout<<"Sending file complete!!"<<endl;

close(sockfd);
}





void *serverhandler(void *argv){
int server_fd = socket(AF_INET,SOCK_STREAM,0);
pthread_t thread_id;



struct sockaddr_in server_address,client_address;
server_address.sin_family = AF_INET;
server_address.sin_port = htons(server_port);
server_address.sin_addr.s_addr = inet_addr(server_IP);

int addrlen = sizeof(sockaddr);
cout<<"Server port : "<<ntohs(server_address.sin_port)<<endl;

if(bind(server_fd,(struct sockaddr *)&server_address,sizeof(server_address))!=0){
     cout<<"\nError in binding socket\n";
     exit(1);
}
mutex_for_server = true;
listen(server_fd,3);
cout<<"\nServer is Listening....."<<endl;


while(true){
	int sockfd = accept(server_fd, (struct sockaddr*)&client_address,(socklen_t *)&addrlen);
    cout<<"\nclient Port no : "<<ntohs(client_address.sin_port)<<endl;
    cout<<"\nclient Ip addre : "<<inet_ntoa(client_address.sin_addr)<<endl;
     cout<<"Connection established"<<endl;  
}

close(server_fd);
}