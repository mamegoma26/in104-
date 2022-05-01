#include "../include/lexer.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
uint8_t *read_entry(char* filename){
    FILE *f=fopen(filename,"r");
    uint8_t *content= malloc(sizeof (2048));
    uint8_t *tmp=content;
    char c;
    if(f!=NULL){
        while((c=(char) fgetc(f))!= EOF){
            *tmp++=c;
        }
    }else{
        printf("unable to open file %s",filename);
        exit(1);
    }
    *tmp='\0';
    return content;
}
Tokens *new_tokens(){

}
void add_token(Tokens **tokens,uint8_t *val,size_t size_val){

}