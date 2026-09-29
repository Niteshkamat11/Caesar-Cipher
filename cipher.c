#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int  encrypt(FILE *fp,FILE *fp1 ,int shift );
int  decrypt(FILE *fp, FILE *fp1 ,int shift );


int main(int argc , char *argv[]){

    if(argc <3 ){
        printf("less number of argument\n");
        return 0;
    }

    FILE *fp = fopen(argv[2],"r");
    if(!fp){
        perror("could not open file");
        return 1;
    }

    FILE *fp1 = fopen("./input.enc","w");

    if(!fp1){
        perror("fopen");
        return 1;
    }

    int shift = atoi(argv[3]);

    if(strcmp(argv[1],"-e" ) == 0){
        encrypt(fp,fp1,shift);
        fclose(fp);
        fclose(fp1);
        return 0;

    }
    if(strcmp(argv[1],"-d" ) == 0){
        decrypt(fp,fp1,shift);
        fclose(fp);
        fclose(fp1);
        return 0;
    }   
    return 0;    
}

int  encrypt(FILE *fp,FILE *fp1, int shift ){

    fseek(fp , 0 , SEEK_SET);
    char c;


    while((c = fgetc(fp))!= EOF){

        if(c == ' ') {
            fputc( c , fp1);
            continue;
        }

        if(c >= 'A' && c<= 'Z'){
            int position = c - 'A';
            int shifted_position = ((position + shift)%26 +26) % 26;
            char result  = (shifted_position + 'A');

           fputc(result, fp1) ;

        }else if(c>= 'a' && c<= 'z'){
            int position = c-'a';
            int shifted_position  = ((position + shift)%26 + 26) % 26;
            char result = (shifted_position + 'a');
            fputc(result, fp1) ;
        }else{
            fputc(c , fp1);
        }   

    }            
    return 0;
    }


int  decrypt(FILE  *fp , FILE *fp1,int shift ){
    encrypt(fp ,fp1, -shift );
        
    return 0;
}

