#ifndef MYSTRING_H
#define MYSTRING_H

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef NULL
#define NULL ((void*)0)
#endif /* NULL */

//#ifndef _SIZE_T_DEFINED
//#ifdef  _WIN64
//typedef unsigned __int64    size_t;
//#else
typedef unsigned int   size_t;
//#endif
//#define _SIZE_T_DEFINED
//#endif

#define SIZE_T_MAX ( (size_t)-1 )

size_t StrLen( const char* str );
char *StrCpy( char *dst, const char *src );
char *StrNCpy( char *dst, const char *src, size_t num );
char *StrCat( char *dst, const char *src );
char *StrNCat( char *dst, const char *src, size_t num );
int StrCmp( const char *str1, const char *str2 );
int StrNCmp( const char *str1, const char *str2, size_t num );
char *StrChr( const char *str, char chr );
char *StrRChr( const char *str, char chr );
size_t StrSpn( const char *str, const char *charSet );
size_t StrCSpn( const char *str, const char *charSet );
char *StrPBrk( const char *str, const char *charSet );
char *StrStr( const char *str1, const char *str2 );
char *StrTok( char *str, const char *delim );

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* MYSTRING_H */