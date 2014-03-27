#include "mystring.h"

//#include <memory.h>

#define MIN(a, b) ( (a) < (b) ) ? (a) : (b)

void *memcpy( void *dest, const void *src, size_t count );
void *memmove( void *dest, const void *src, size_t count );
void *memset( void *dest, int c, size_t count );
void *memchr( const void *s, int c, size_t n );
int memcmp( const void *buf1, const void *buf2, size_t count );

size_t StrLen_us( const char* str )
{
#define USE_MEMCHR
#ifndef USE_MEMCHR
	size_t i;
	for( i=0; str[i] != STREND; i++ )
	{
		; /* NULL */
	}
#else /* USE_MEMCHR */
#undef USE_MEMCHR
	return (char*)memchr( str, STREND, SIZE_T_MAX ) - str;
#endif /* USE_MEMCHR */
}

char *StrCpy_us( char *dst, const char *src )
{
	return (char*) memcpy( dst, src, StrLen_us(src) );
}

char *StrNCpy_us( char *dst, const char *src, size_t num )
{
	return (char*) memcpy( dst, src, MIN( num, StrLen_us(src) ) );
}

char *StrCat_us( char *dst, const char *src )
{
	return (char*) memcpy( memchr( dst, STREND, SIZE_T_MAX ), src, StrLen_us( src ) );
}

char *StrNCat_us( char *dst, const char *src, size_t num )
{
	return (char*) memcpy( memchr( dst, STREND, SIZE_T_MAX ), src, MIN( num, StrLen_us(src) ) );
}

int StrCmp( const char *str1, const char *str2 )
{
	return memcmp( str1, str2, StrLen_us( str1 ) );
}

int StrNCmp( const char *str1, const char *str2, size_t num )
{
	return memcmp( str1, str2, MIN( num, StrLen_us( str1 ) ) );
}

char *StrChr( const char *str, char chr )
{
	return (char*) memchr( str, chr, StrLen_us( str ) );
}

char *StrRChr( const char *str, char chr )
{
	const char *ptr;
	for( ptr = (const char*)memchr( str, STREND, StrLen_us( str ) );
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

	for( count = 0; *str != STREND; count++ ) {
		if( StrChr( charSet, *str++ ) == NULL ) {
			return count;
		}
	}

	return count;
}

size_t StrCSpn( const char *str, const char *charSet )
{
	size_t count;

	for( count = 0; *str != STREND; count++ )
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
	for( ; *str != STREND; str++ )
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
	
	while( *str1 != STREND )
	{
		ptr1 = str1;
		ptr2 = str1;
		while( *str2 != STREND )
		{
			if( *ptr1++ != *ptr2++ )
			{
				break;
			}
		}
		if( ptr2[-1] == STREND )
		{
			return (char*)str1;
		}
	}
	
	return NULL;
}

char *StrTok_us( char *str, const char *delim )
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
		*found = STREND;
		return str;
	}
}

size_t StrNLen( const char* str, size_t buffLen )
{
	size_t i;

	for( i = 0; i < buffLen; i++ )
	{
		if( str[i] == STREND )
		{
			return i;
		};
	};
	return buffLen;
}

errno_t StrCpy_s( char *dst, size_t buffLen, const char *src )
{
	size_t len;

	if( dst == NULL )
	{
		return EINVAL;
	}

	if( src == NULL )
	{
		*dst = STREND;
		return EINVAL;
	}

	len = StrLen_us( src );
	
	if( len < buffLen ) {
		memcpy( dst, src, len + 1 );
		return 0;
	}

	*dst = STREND;
	return ERANGE;
}

errno_t StrNCpy_s( char *dst, size_t buffLen, const char *src, size_t num )
{
	size_t len;
	
	if( dst == NULL || buffLen == 0 )
	{
		return EINVAL;
	}
	
	if( src == NULL )
	{
		*dst = STREND;
		return EINVAL;
	}
	
	len = MIN( num, StrLen_us( src ) );
	
	if( len < buffLen )
	{
		memcpy( dst, src, len + 1 );
		return 0;
	}
	
	*dst = STREND;
	return ERANGE;
}

errno_t StrCat_s( char *dst, size_t buffLen, const char *src )
{
	size_t len;

	if( dst == NULL )
	{
		return EINVAL;
	}

	if( src == NULL )
	{
		*dst = STREND;
		return EINVAL;
	}

	len = StrLen_us( src );

	if( len < buffLen )
	{
		memcpy( memchr( dst, STREND, buffLen ), src, len );
	}
	
	*dst = STREND;
	return ERANGE;
}

errno_t StrNCat_s( char *dst, size_t buffLen, const char *src, size_t num )
{
	size_t len;

	if( dst == NULL )
	{
		return EINVAL;
	}

	if( src == NULL )
	{
		*dst = STREND;
		return EINVAL;
	}

	len = StrLen_us( src );

	if( len < buffLen )
	{
		memcpy( memchr( dst, STREND, buffLen ), src, len );
	}

	*dst = STREND;
	return ERANGE;
}

char *StrTok_s( char *str, const char *delim, char **context )
{
	return NULL;
}

const char *_get_sys_err_msg( int m );

const char *StrError_us( errno_t err )
{
	return _get_sys_err_msg( err );
	//return _sys_errlist[err];
}

errno_t StrError_s( char *buffer, size_t buffLen, errno_t err )
{
	const char *errstr;
	if( buffer == NULL || buffLen == 0 )
	{
		return EINVAL;
	}
	errstr = _get_sys_err_msg( err );
	if( StrLen_us( errstr ) >= buffLen )
	{
		StrCpy_us( buffer, errstr );
		return 0;
	}

	*buffer = STREND;
	return ERANGE;
}
