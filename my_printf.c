#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>



#define UINT_MAX 4294967295
#define INT_MAX 2147483647
#define UINT_MIN 0
#define INT_MIN -2147483648

int* my_putchar(char c, int*count){
     write(1, &c , 1);
     *count +=1;
     return count;
}

int * my_putstr(char *param, int *count){
    int index = 0;
    while(param[index] != '\0'){
        write(1, &param[index], 1);
        *count +=1;
        index++;
    }
    return count;
}

char my_itoa(int number){
        if(number==0){
            number = 48;
        }
        else if(number==1){
            number = 49;
        }
        else if(number == 2){
            number = 50;
        }
        else if(number == 3){
            number = 51;
        }
        else if(number == 4){
            number = 52;
        }
        else if(number == 5){
            number = 53;
        }
        else if(number == 6){
            number = 54;
        }
        else if(number == 7){
            number = 55;
        }
        else if(number == 8){
            number = 56;
        }
        else if(number == 9){
            number = 57;
        }
      
    return number;
}

void print_buffer(int *sorted_buffer, int *count){
    int index = 0;
        while(sorted_buffer[index] != 'e' ){
            char int_char = my_itoa(sorted_buffer[index]);
            my_putchar(int_char, count);
            index++; 
        }
}

int *my_base_converter(unsigned number, int base, int *sorted_buffer){
    int reverse_buffer[20];
    int index = -1;
    while (number != 0) {
        index++;
        int remainder = number%base;
        reverse_buffer[index] = remainder;
        number =  (number - remainder) / base;
    }
    int buf_index = 0;
    while (index != -1) {
        sorted_buffer[buf_index] = reverse_buffer[index];
        index--;
        buf_index++;
    }
    sorted_buffer[buf_index] = 'e';
   
    return sorted_buffer;
}

void hexa_print(int *sorted_buffer, int *count){
    char hexa[] = "0123456789abcdef";
    int index = 0;
        while(sorted_buffer[index] != 'e'){
            int hexa_index = sorted_buffer[index];
            char hexa_char = hexa[hexa_index];
            my_putchar(hexa_char, count);
            index++; 
        }
}


void my_putd(char spec, int num, int *count){
    int *sorted_buffer = malloc(128);
    if(num==0){
        my_putchar('0', count);
    }

    else if(spec == 'd'|| spec == 'i'){
        if(num<0){
            my_putchar('-', count);
            num = num * -1;   
        }
        my_base_converter((unsigned)num, 10, sorted_buffer);
        print_buffer(sorted_buffer, count);
    }

    else if(spec == 'x'){
        if(num<0){
            num = UINT_MAX + num + 1;
        }
        my_base_converter((unsigned)num, 16, sorted_buffer);
        hexa_print(sorted_buffer, count);
    }

    else if(spec == 'o'){
        my_base_converter(num, 8, sorted_buffer);
        print_buffer(sorted_buffer, count);
    }
    
    else if(spec == 'u'){
        if(num > 0){
            my_base_converter((unsigned)num, 10, sorted_buffer);
            print_buffer(sorted_buffer, count);
        }
        else{
            unsigned int unsigned_num = UINT_MAX + num + 1;
            my_base_converter(unsigned_num, 10, sorted_buffer);
            print_buffer(sorted_buffer, count);
        }
    }
    free(sorted_buffer);
}

int* sequence_escape(char escape, int *count){
    if(escape == 'n'){
        my_putchar('\n', count);
    }
    else if(escape == 't'){
        my_putchar('\t', count);
    }
    else if(escape == '\\'){
        my_putchar('\\', count);
    }
    else if(escape == '\''){
        my_putchar('\'', count);
    }
    else if(escape == '\"'){
        my_putchar('\"', count);
    }
    return count;
}

int *conversion_spec(va_list a_list, char spec, int *count){
    unsigned num;
    char *str;
    char *ptr;
    if(spec == '%'){
        my_putchar('%', count);    
    }
    else if(spec == 's'){
        str = va_arg(a_list, char*);
        if(str){
            my_putstr(str, count);
        }
        else{
            my_putstr("(null)", count);
        }
    }
    else if(spec == 'c'){
        num = va_arg(a_list, int);
        my_putchar(num, count);
    }
    else if(spec == 'p'){
        ptr = va_arg(a_list, void *);
        if(ptr){
            my_putstr("0x", count);
            my_putstr("_address_not_found - lazy&tired developer\n", count);
        }
        else{
            my_putstr("(nil)", count);
        }
     
    }
    else if(spec == 'd' || spec == 'i' || spec == 'x' || spec == 'o' || spec == 'u'){
        num = va_arg(a_list, int);
        my_putd(spec, (unsigned)num, count);     
    }
   
    return count;
}


int my_printf(char *restrict format, ...){
    int *count = malloc(32);
    *count = 0;
    
    va_list a_list;
    va_start(a_list, format);
    int i = 0;
    while(format[i] != '\0'){
        while (format[i] != '%'){ 
            if(format[i] == '\\'){
                i++;
                sequence_escape(format[i], count);
            }

            my_putchar(format[i], count);
            i++;
            if(format[i] == '\0'){
                break;
            }
        }

        if(format[i] == '%'){ 
            i++;
            conversion_spec(a_list,format[i], count);
        }
        

        if(format[i] == '\0'){
            break;
        }
        i++;
    } 
    
    va_end(a_list);

    int count_1 = *count;
    free(count);

    return count_1;
}
