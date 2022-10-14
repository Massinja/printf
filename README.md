# Welcome to My Printf  
(almost) replicates C library printf function  
***

## Task
Recreate the functionality of printf function in C language.

## Description
This function writes the output under the control of a format string that specifies how subsequent arguments  
(or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.  

The format string is composed of zero or more directives:  
**ordinary characters (not %)**, which are copied unchanged to the output stream;  
**conversion specifications**, each of which results in fetching zero or more subsequent arguments.  
Each conversion specification is introduced by the % character.  
The arguments must correspond properly (after type promotion) with the conversion specifier.   
After the %, the following appear in sequence:

**doux** - int argument is converted to   
signed decimal (d);   
unsigned octal (o);  
unsigned decimal (u);  
unsigned hexadecimal (x).  
**c**  - int argument is converted to an unsigned char, and the resulting character is written.  
**s**  - char * argument is expected to be a pointer to an array of character type (pointer to a string).  
**p**  - void * pointer argument is printed in hexadecimal.  

my_printf() is also mindful of escape sequences:  
**\n \t \\ \0 \\' \\"**


## Installation
Include directive "my_printf.c" to your main file

## Usage
Use the function "my_printf" instead of a regular "printf" (at your own caution :) )
```
#include "my_printf.c"

my_printf("oh, hello there!\nI'd like %d %s, please!", 5, "chocolates");

==> oh, hello there!  
I'd like 5 chocolates, please!
```

## Further considerations
Instead of making a call to write() for every character, buffer must be created. It will output everything in 1 write() call.
Also, pointer specification (%p) has not been correctly figured out.


### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar Silicon Valley</a></i></span>
<span><img alt='Qwasar Silicon Valley Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
