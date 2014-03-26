#include "mystring.h"

//#include <memory.h>

#define MIN(a, b) ( (a) < (b) ) ? (a) : (b)

void *memcpy( void *dest, const void *src, size_t count );
void *memmove( void *dest, const void *src, size_t count );
void *memset( void *dest, int c, size_t count );
void *memchr( const void *s, int c, size_t n );
int memcmp( const void *buf1, const void *buf2, size_t count );

size_t StrLen( const char* str )
{
#define USE_MEMCHR
#ifndef USE_MEMCHR
	size_t i;
	for( i=0; str[i]; i++ )
	{
		; /* NULL */
	}
#else /* USE_MEMCHR */
#undef USE_MEMCHR
	return (char*)memchr( str, 0, SIZE_T_MAX ) - str;
#endif /* USE_MEMCHR */
}

char *StrCpy( char *dst, const char *src )
{
	return (char*) memcpy( dst, src, StrLen(src) );
}

char *StrNCpy( char *dst, const char *src, size_t num )
{
	return (char*) memcpy( dst, src, MIN( num, StrLen(src) ) );
}

char *StrCat( char *dst, const char *src )
{
	return (char*) memcpy( memchr( dst, 0, SIZE_T_MAX ), src, StrLen( src ) );
}

char *StrNCat( char *dst, const char *src, size_t num )
{
	return (char*) memcpy( memchr( dst, 0, SIZE_T_MAX ), src, MIN( num, StrLen(src) ) );
}

int StrCmp( const char *str1, const char *str2 )
{
	return memcmp( str1, str2, StrLen( str1 ) );
}

int StrNCmp( const char *str1, const char *str2, size_t num )
{
	return memcmp( str1, str2, MIN( num, StrLen( str1 ) ) );
}

char *StrChr( const char *str, char chr )
{
	return (char*) memchr( str, chr, StrLen( str ) );
}

char *StrRChr( const char *str, char chr )
{
	const char *ptr;
	for( ptr = (const char*)memchr( str, 0, StrLen( str ) );
		ptr >= str;
		ptr-- )
	{
		if( *ptr == chr )
		{
			return (char*)ptr;
		}
	}
	
	return NULL;
}

size_t StrSpn( const char *str, const char *charSet )
{
	size_t count;

	for( count = 0; *str != '\0'; count++ ) {
		if( StrChr( charSet, *str++ ) == NULL ) {
			return count;
		}
	}

	return count;
}

size_t StrCSpn( const char *str, const char *charSet )
{
	size_t count;

	for( count = 0; *str != '\0'; count++ )
	{
		if( StrChr( charSet, *str++ ) != NULL )
		{
			return count;
		}
	}

	return count;
}

char *StrPBrk( const char *str, const char *charSet )
{
	for( ; *str != '\0'; str++ )
	{
		if( StrChr( charSet, *str ) != NULL )
		{
			return (char*)str;
		}
	}

	return NULL;
}

char *StrStr( const char *str1, const char *str2 )
{
	const char *ptr1, *ptr2;
	while( *str1 != '\0' )
	{
		ptr1 = str1;
		ptr2 = str1;
		while( *str2 != '\0' )
		{
			if( *ptr1++ != *ptr2++ )
			{
				break;
			}
		}
		if( ptr2[-1] == '\0' )
		{
			return (char*)str1;
		}
	}
	return NULL;
}

char *StrTok( char *str, const char *delim )
{
	static char *last=NULL;
	char* found;
	if( str == NULL )
	{
		str = last;
	}
	found = StrPBrk( str, delim );
	if( found == NULL )
	{
		last = NULL;
		return NULL;
	}
	else
	{
		last = found + 1;
		*found = '\0';
		return str;
	}
}