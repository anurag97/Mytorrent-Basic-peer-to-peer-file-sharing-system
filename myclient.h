#include<bits/stdc++.h>
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>
#include <arpa/inet.h>
#define CHUNK_SIZE 512*1024

struct client_addr{
	char *filename;
	char *IP;
	char *bit_vector;
	int PORT;
	int start;
	int interval;
	int filesize;
	bool first_client = false;
};

std::map<char*, vector<struct client_addr *> *,compare> download_map;
struct mutex_struct{
	int no_of_client;
 bool mutex;
};

std::map<char *, struct mutex_struct *, compare> mutex_map;



void upload_command(){
	char *filename = new char[256];
	cin>>filename;

	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(tracker_port);
	serv_addr.sin_addr.s_addr = inet_addr(tracker_IP);
	if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0){
		cout<<"Error in connecting tracker"<<endl;
		pthread_exit(NULL)''
	}

send(sockfd,"upload_file",strlen("upload_file"),0)
bool ackn = false;
recv(sockfd,&ackn,sizeof(ackn),0);

FILE *fileptr = fopen(filename,"rb");
fseek(fileptr,0,SEEK_END);
int size = ftell(fileptr);
rewind(fileptr);

int chunk_count = ((size-1)/CHUNK_SIZE)+1;
char *bit_vector = new char[chunk_count];
for(int i=0;i<chunk_count;i++){
	bit_vector[j]='1';
}
struct filedetails *fv= new filedetails();
fv->size = size;
fv->bit_vector = bit_vector;
fv->no_of_chunks=chunk_count;
filedetails_map.insert({filename,fv});

send(sockfd,&filename,strlen(filename),0);
recv(sockfd, &ackn, sizeof(ackn),0);
send(sockfd,&size,sizeof(size),0);
recv(sockfd, &ackn, sizeof(ackn),0);

send(sockfd,&PORT,sizeof(PORT),0);
recv(sockfd, &ackn, sizeof(ackn),0);


send(sockfd,&userid,strlen(userid),0);
recv(sockfd, &ackn, sizeof(ackn),0);

fclose(fileptr);
close(sockfd);

}


void piece_selection(char *filename){
	auto ptr  = download_map.find(filename);
	std::vector<struct client_addr *> *temp = ptr->second;
   
   for(int i=0;i<5;i++) cout<<filename<<" size: "<<temp->size();
   
   for(int i=0;i<temp->size();i++){
   	cout<<"\n"<<temp->at(i)->IP<<" ";
   	cout<<temp->at(i)->PORT<<" "<<temp->at(i)->start<<" "
   	<<temp->at(i)->interval<<" "<<temp->at(i)->filesize<<" "<<temp->at(i)->bit_vector<<end;
   }

   int no_bits_one[temp->size()] ={0};
   int no_of_ones_used[temp->size()]={0};

   int chunk_count = strlen(temp->at(0)->bit_vector)-1;
   cout<<"\nChunk count:"<<chunk_count<<endl;

   for(int i=0;i<temp->size();i++){
   	cout<<"Check!!"<<endl;
   	for(int j=0;j<chunk_count;j++){
   		if(temp->at(i)->bit_vector[j]=='1')
   			no_bits_one[i]++;
   	}
   	cout<<no_bits_one[i]<<" "<<temp->at(i)->bit_vector;
    }

   for(int i=0;i<chunk_count;i++){
   	int rslt_client =0 ;
   	int temp_no_of_ones =INT_MAX;
   	int temp_no_of_ones_used =INT_MAX;
   	for(int j=0;j<temp->size();j++){
   		if(temp->at(j)->bit_vector[i]=='1'){
   			if(temp_no_of_ones>no_bits_one[j])
   			{
   				rslt_client = j;
   				temp_no_of_ones = no_bits_one[j];
   				temp_no_of_ones_used = no_of_ones_used[j];
   			}
   			if(temp_no_of_ones==no_bits_one[j]&& temp_no_of_ones_used > no_of_ones_used[j])
   			{
   				rslt_client=j;
   				temp_no_of_ones = no_bits_one[j];
   				temp_no_of_ones_used = no_of_ones_used[j];
   			}
   		}
   	}


   }

cout<<"\t check2"<<endl;
char * bit_vector = new char[chunk_count];
struct filedetails *f = new filedetails();
f->size =  temp->at(0)->filesize;
f->bit_vector = bit_vector;
f->no_of_chunks = chunk_count;


for(int i =0;i<chunk_count;i++){
	bit_vector[i]='0';
}

filedetails_map.insert({filename,f});
cout<<"uploading file details"<<endl;
int sockfd = socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in serv_addr;
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(tracker_port);
serv_addr.sin_addr.s_addr=inet_addr(tracker_IP);

if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
	printf("\nConnection Failed with Tracker\n"); 
        pthread_exit(NULL);
}




}


