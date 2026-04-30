#include <stdio.h>
#include <string.h>

#define SIZE 10 

struct DataStore {
    char data[SIZE];
    int head; // مكان الكتابة
    int tail; // مكان القراءة
    int count; // عداد الحروف  
};   //هون الاضافة 
void setup_buffer(struct DataStore *b) {
    b->head = 0;
    b->tail = 0;
    b->count = 0;
}

int addToBuffer(struct DataStore *b, char val) {
    
    if (b->count == SIZE) {
        printf("Full! cant add: %c\n", val); 
        return 0; // فشل الإضافة
    }
    
    b->data[b->head] = val; 
    b->head = (b->head + 1) % SIZE;
    b->count++;
    return 1;
}


int getFromBuffer(struct DataStore *b, char *out) {
   
    if (b->count == 0) {
        return 0; 
    }
    
    *out = b->data[b->tail]; //اخد الحرف 
    b->tail = (b->tail + 1) % SIZE; 
    b->count--; 
    return 1;
}

int main() {
    struct DataStore my_buff; 
    setup_buffer(&my_buff);

    char name[40];
    char final_text[60];
    char temp;

    
    printf("Enter your name: ");
    scanf("%s", name); 

    
    strcpy(final_text, name);
    strcat(final_text, " CE-ESY");

    printf("\nFinal Text: %s\n", final_text);
    printf("---------------------------\n");

   
    for (int i = 0; i < strlen(final_text); i++) {
        addToBuffer(&my_buff, final_text[i]);
    }

    
    printf("\nOutput from buffer: ");
    while (getFromBuffer(&my_buff, &temp)) {
        printf("%c", temp);
    }

    
    if (my_buff.count == 0) {
        printf("\n\nDone. Buffer is empty now.\n");
    }

    return 0;
}