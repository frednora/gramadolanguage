// globals.h
// Created by Fred Nora.

#ifndef __GLOBALS_H
#define __GLOBALS_H    1


// Size of buffers inside the metadata_d structure.
#define METATAG_COUNT_MAX  64
#define NAME_COUNT_MAX  64
#define CONTENT_COUNT_MAX  128
// ...


// This is the global data structure for the metadata.
// We need at least two statement inside a box[] block  
// in order to fill a single structure. name="" and content="",
// but maybe we're gonna allow more of these.
struct metadata_d
{
    int initialized;

// Tag identification
    int id;
    char meta_tag[64];
    size_t tag_size;

// name="" element.
    char name[64];
    size_t name_size;

// content="" element.
    char content[128];
    size_t content_size;

    // ...

// Each meta thingy(){} can have a return value,
// just like a function.
    unsigned long return_value;
};

//#define METADATA_COUNT_MAX  32
//#define METADATA_COUNT_MAX  1024
// This is the global data structure for the metadata.
extern struct metadata_d  metadata[32];

// Contador para não estourar a lista. 
extern int keyword_count; 
extern int identifier_count; 
extern int constant_count; 
extern int string_count; 
extern int separator_count; 
extern int special_count;

extern int maxtoken;       /* Current length of token buffer */
extern char *token_buffer; /* Pointer to token buffer */

// #todo: Change this MAXTOKEN name.
#define MAXTOKEN  256 
extern char real_token_buffer[MAXTOKEN];

// ----------------------------------------------
// ## stack support ##
// #testando 
// Isso será a pilha para os argumentos ou expressões matemáticas.
// #todo: agora o arquivo tree.c lida com pilha.
// Não precismos mais disso.
extern long stack[1024];
//xxx() if(((( ))))       ... tem que dar zero no final. 
extern int stack_count;
extern int stack_index;   //current index.
extern int stack_flag;    //aciona para sinalizar que devemos colocar o próximo elemento na pilha.

//#debug
//flag para mostrar o arquivo em assembly.
extern int asm_flag;

extern FILE *finput; 

#define INFILE_MAX_SIZE  512
extern unsigned long infile_size;
extern char infile[INFILE_MAX_SIZE];

#define OUTFILE_MAX_SIZE  512
extern unsigned long outfile_size;
extern char outfile[OUTFILE_MAX_SIZE];


// #importante
// Esses dois buffers serão copiados no final do buffer outfile.
extern char TEXT[1024];
extern char DATA[1024];
extern char BSS[1024];

extern unsigned long program_header_address;
extern unsigned long program_text_address;
extern unsigned long program_data_address;
extern unsigned long program_bss_address;


// Arquivo intermediário
extern char file_i[512];
// Arquivo em assembly.
extern char file_s[512];

/* Length of the prefix.  */
extern int temp_filename_length;

//current tmp file.
extern char *temp_filename;


/* Define the list of temporary files to delete.  */
struct temp_file
{
    char *name;
    struct temp_file *next;
};
extern struct temp_file *temp_file_queue;


#endif    


