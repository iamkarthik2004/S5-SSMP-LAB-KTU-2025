#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char label[20],mnemonic[20],operand[20],location[20],totlen[20];
    char opcode[20],opaddress[20],symbol[20],symboladdress[20];
    int start=0;

    FILE *intermediate=fopen("intermediate.txt","r");
    FILE *symtab=fopen("symtab.txt","r");
    FILE *optab=fopen("optab.txt","r");
    FILE *length=fopen("length.txt","r");
    FILE *object=fopen("object.txt","w");

    if(!intermediate||!symtab||!optab||!length||!object)
    {
        printf("Error opening files....");
        exit(1);
    }

    fscanf(intermediate,"%s%s%s%s",location,label,mnemonic,operand);

    if(strcmp(mnemonic,"START")==0)
    {
        start=atoi(location);
        fscanf(length,"%s",totlen);
        fprintf(object,"H^%s^%06X^%06s\n",label,start,totlen);
        fprintf(object,"T^%06X",start);
        fscanf(intermediate,"%s%s%s%s",location,label,mnemonic,operand);
    }
    else
    {
        printf("Start symbol not found...");
        exit(1);
    }

    while(strcmp(mnemonic,"END")!=0)
    {
        int found=0;
        rewind(optab);
        while (fscanf(optab,"%s%s",opcode,opaddress)!=EOF)
        {
            if(strcmp(opcode,mnemonic)==0)
            {
                found=1;
                fprintf(object,"^%s",opaddress);
                rewind(symtab);
                int sym_found=0;
            while (fscanf(symtab,"%s%s",symbol,symboladdress)!=EOF)
        {
            if(strcmp(symbol,operand)==0)
            {
                sym_found=1;
                fprintf(object,"%s",symboladdress);
                break;
            }
        }
        if(!sym_found)
        {
            fprintf(object,"0000");
        }
        break;
        }
        }
        if(!found)
        {
            if(strcmp(mnemonic,"WORD")==0)
            {
                fprintf(object,"^%06x",atoi(operand));
            }
            else if(strcmp(mnemonic,"BYTE")==0)
            {
                for(int i=2;operand[i]!='\'';i++)
                {
                    fprintf(object,"^%02x",atoi(operand));         
                }
            }
        }
        fscanf(intermediate,"%s%s%s%s",location,label,mnemonic,operand);
    }
    fprintf(object,"\nE^%06x",start);
    fclose(intermediate);
    fclose(optab);
    fclose(symtab);
    fclose(length);
    fclose(object);
    return 0;
}
