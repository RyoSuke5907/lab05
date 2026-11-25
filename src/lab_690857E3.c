#include <stdio.h>
#include <string.h>

#include "lab_690857E3.h"

void copy(char *psource, char *ptarget, unsigned num_char)
{
    unsigned copied = 0;                   

    while (copied < num_char && *psource != '\0')
    {
        *ptarget = *psource;              
        ptarget++;                
        psource++;                     
        copied++;             
    }

    *ptarget = '\0';                      
}

void concatenate(char *psrc1, char *psrc2, char *ptarget, unsigned buffer_size)
{
     char *p;                               
    unsigned room;                          
    unsigned used = 0;                    

    if (buffer_size == 0)                  
        return;

    room = buffer_size - 1;                
    p = psrc1;
    while (used < room && *p != '\0')
    {
        p++;                               
        used++;
    }

    copy(psrc1, ptarget, room);

    if (used < room)
    {
        copy(psrc2, ptarget + used, room - used);
    }
}

// DO NOT change the code below
#ifndef ___TEST___
int main(void)
{
    char buffer[100];
    char *source = "This is the first sentence.  ";
    char *target = "This is the second sentence.";

    concatenate(source, target, buffer, 70);

    printf("%s", buffer);
    return 0;
}
#endif
// DO NOT change the code above