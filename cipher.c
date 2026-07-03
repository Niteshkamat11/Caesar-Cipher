#include<stdio.h>
#include<string.h>
int  encrypt(char  *address_of_array , int shift );
int  decrypt(char  *address_of_array , int shift );
int main(void){
    char message[50];
    printf("Enter your message :\n\n");
    fgets(message,50,stdin);


    int len = strlen(message);

    if(len>0 && *(message + (len-1)) =='\n'){
        *(message + (len-1)) = '\0';
    }
    
    int shift;
    printf("Enter the number to which you want to shift your message or decode if shift = 3 then A->D: ");
    
    
    
    scanf("%d",&shift);

    encrypt(message,shift);
    printf("your encrypted message is : ");
    puts(message);
    
    int option ;
    printf("press 1 to decrypt and 0 to reject :");
    scanf("%d" , &option);



    switch(option){
        case 1:
            decrypt(message,shift);
            printf("Your decrypted message is : ");
            puts(message);
        default: 
            break;
    }
    
    return 0;
    
}

int  encrypt(char  *address_of_array , int shift ){
    int len = strlen(address_of_array);
    for(int i  = 0 ; i<len; i++ ){

        char c = *(address_of_array + i);
    
        if(c >= 'A' && c<= 'Z'){


            int position = c - 'A';

            int shifted_position = ((position + shift)%26 +26) % 26;
                 
            char result  = (shifted_position + 'A');
            *(address_of_array + i) = result; 
        }else if(c>= 'a' && c<= 'z'){

            int position = c-'a';
            
            int shifted_position  = ((position + shift)%26 + 26) % 26;
            
            char result = (shifted_position + 'a');
            *(address_of_array + i) = result; 
        }
    
    }
    return 0;
}


int  decrypt(char  *address_of_array , int shift ){
    int len = strlen(address_of_array);
    for(int i  = 0 ; i<len; i++ ){
        char c = *(address_of_array + i);

        if(c >= 'A' && c<= 'Z'){

                int position = c - 'A';
                int shifted_position = ((position - shift)%26 + 26) % 26;

                char result = (shifted_position + 'A');
                *(address_of_array +i) = result; 
        }else if(c>='a' && c<= 'z'){
            int position = c - 'a';
            int shifted_position = ((position - shift)%26 + 26) % 26;
            char result = (shifted_position + 'a');
            *(address_of_array+ i) = result;
        }else{
            continue;
        }

    }
    
    return 0;
}





