#include <stdio.h>

int main(){
    char arr[30];
    int i, j;
    int count1=0,count2=0;

    printf("Enter string: ");
    fgets(arr, sizeof(arr), stdin);

    for (i = 0, j = 0; arr[i] != '\0'; i++) {
        if (arr[i] != ' ') {
            arr[j++] = arr[i];
        }
    }

    arr[j] = '\0';
    for(i=0;arr[i]!='\0';i++){
        if(arr[i]=='A'&& arr[i]=='Z'){
            count1++;
        }
        else{
            (arr[i]=='a'&& arr[i]=='z');
                count2++;
        }

    }
    if(count1>count2){
        for(i=0;arr[i]!='\0';i++){
        if(arr[i] >= 'a' && arr[i] <= 'z') {
            arr[i] = arr[i] + 32;
        }
    }
    else
        arr[i]=arr[i]-32;

    printf("The string  is:\n");
    puts(arr);

    return 0;
}
