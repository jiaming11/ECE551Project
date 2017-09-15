#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortData(char ** data, size_t count);

int printData(char ** buffer,size_t size){
  for(int i=0;i<size;i++){
    printf("%s/n",buffer[i]);
  }
  return EXIT_SUCCESS;
}

int freeData(char ** buffer,size_t size){
  for(int i=0;i<size;i++){
    free(buffer[i]);
  }
  free(buffer);
  return EXIT_SUCCESS;
}

int screenread(){
  char ** buffer=malloc(sizeof(*buffer));
  size_t bufsize=1;
  int i=0;
  size_t stringlength=0;
  while(getline(&(buffer[i]),&stringlength,stdin)==-1){
    i++;
    if(bufsize==i){
      buffer=realloc(buffer,(bufsize+1)*sizeof(*buffer));
      bufsize++;
    }
  }
  sortData(buffer,bufsize);
  printData(buffer,bufsize);
  freeData(buffer,bufsize);
  return EXIT_SUCCESS;
}

int fileread(FILE *f){
  char ** buffer=malloc(sizeof(*buffer));
  size_t bufsize=1;
  int i=0;
  size_t stringlength=0;
  while(!feof(f)){
    if(bufsize==i){
      buffer=realloc(buffer,(bufsize+1)*sizeof(*buffer));
      bufsize++;
    }
    if(getline(&(buffer[i]),&stringlength,f)==-1) exit(EXIT_FAILURE);
    i++;
  }
  sortData(buffer,bufsize);
  printData(buffer,bufsize);
  freeData(buffer,bufsize);
  return EXIT_SUCCESS;
}

//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  FILE *f=NULL;
  if(argc==1) screenread();
  else{
    for(int i=1;i<argc;i++){
      if((f=fopen(argv[i],"r")) == NULL){
	perror("Could not open file");
	return EXIT_FAILURE;
      }
      fileread(f);
      if (fclose(f) != 0) {
	perror("Failed to close the input file!");
	return EXIT_FAILURE;
      }
    }
  }
  return EXIT_SUCCESS;
}
