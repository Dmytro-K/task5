#ifndef MYSTRING_H
#define MYSTRING_H

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef NULL
#define NULL ((void*)0)
#endif /* NULL */

#ifndef _SIZE_T_DEFINED
#ifdef  _WIN64
typedef unsigned __int64    size_t;
#else /* _WIN64 */
typedef unsigned int   size_t;
#endif /* _WIN64 */
#define _SIZE_T_DEFINED
#endif /* _SIZE_T_DEFINED */

#include <errno.h>

#ifndef _ERRNO_T_DEFINED
#define _ERRNO_T_DEFINED
typedef enum
{
	EPERM = 1,
	ENOENT = 2,
	ESRCH = 3,
	EINTR = 4,
	EIO = 5,
	ENXIO = 6,
	E2BIG = 7,
	ENOEXEC = 8,
	EBADF = 9,
	ECHILD = 10,
	EAGAIN = 11,
	ENOMEM = 12,
	EACCES = 13,
	EFAULT = 14,
	EBUSY = 16,
	EEXIST = 17,
	EXDEV = 18,
	ENODEV = 19,
	ENOTDIR = 20,
	EISDIR = 21,
	ENFILE = 23,
	EMFILE = 24,
	ENOTTY = 25,
	EFBIG = 27,
	ENOSPC = 28,
	ESPIPE = 29,
	EROFS = 30,
	EMLINK = 31,
	EPIPE = 32,
	EDOM = 33,
	EDEADLK = 36,
	ENAMETOOLONG = 38,
	ENOLCK = 39,
	ENOSYS = 40,
	ENOTEMPTY = 41,
	/* Error codes used in the Secure CRT functions */

#ifndef RC_INVOKED
#if !defined (_SECURECRT_ERRCODE_VALUES_DEFINED)
#define _SECURECRT_ERRCODE_VALUES_DEFINED
	EINVAL = 22,
	ERANGE = 34,
	EILSEQ = 42,
	STRUNCATE = 80,
#endif  /* !defined (_SECURECRT_ERRCODE_VALUES_DEFINED) */
#endif  /* RC_INVOKED */

	/* Support EDEADLOCK for compatibility with older MS-C versions */
	EDEADLOCK = EDEADLK,

	/* POSIX SUPPLEMENT */
	EADDRINUSE = 100,
	EADDRNOTAVAIL = 101,
	EAFNOSUPPORT = 102,
	EALREADY = 103,
	EBADMSG = 104,
	ECANCELED = 105,
	ECONNABORTED = 106,
	ECONNREFUSED = 107,
	ECONNRESET = 108,
	EDESTADDRREQ = 109,
	EHOSTUNREACH = 110,
	EIDRM = 111,
	EINPROGRESS = 112,
	EISCONN = 113,
	ELOOP = 114,
	EMSGSIZE = 115,
	ENETDOWN = 116,
	ENETRESET = 117,
	ENETUNREACH = 118,
	ENOBUFS = 119,
	ENODATA = 120,
	ENOLINK = 121,
	ENOMSG = 122,
	ENOPROTOOPT = 123,
	ENOSR = 124,
	ENOSTR = 125,
	ENOTCONN = 126,
	ENOTRECOVERABLE = 127,
	ENOTSOCK = 128,
	ENOTSUP = 129,
	EOPNOTSUPP = 130,
	EOTHER = 131,
	EOVERFLOW = 132,
	EOWNERDEAD = 133,
	EPROTO = 134,
	EPROTONOSUPPORT = 135,
	EPROTOTYPE = 136,
	ETIME = 137,
	ETIMEDOUT = 138,
	ETXTBSY = 139,
	EWOULDBLOCK = 140,
} errno_t;

#endif  /* _ERRNO_T_DEFINED */

#define SIZE_T_MAX ( (size_t)-1 )

#define STREND ((char)0x1F)

const char *StrError_us( errno_t err );
errno_t StrError_s( char *buffer, size_t buffLen, errno_t err );

size_t StrLen_us( const char* str );
char *StrCpy_us( char *dst, const char *src );
char *StrNCpy_us( char *dst, const char *src, size_t num );
char *StrCat_us( char *dst, const char *src );
char *StrNCat_us( char *dst, const char *src, size_t num );
int StrCmp( const char *str1, const char *str2 );
int StrNCmp( const char *str1, const char *str2, size_t num );
char *StrChr( const char *str, char chr );
char *StrRChr( const char *str, char chr );
size_t StrSpn( const char *str, const char *charSet );
size_t StrCSpn( const char *str, const char *charSet );
char *StrPBrk( const char *str, const char *charSet );
char *StrStr( const char *str1, const char *str2 );
char *StrTok_us( char *str, const char *delim );

size_t StrNLen( const char* str, size_t buffLen );
errno_t StrCpy_s( char *dst, size_t buffLen, const char *src );
errno_t StrNCpy_s( char *dst, size_t buffLen, const char *src, size_t num );
errno_t StrCat_s( char *dst, size_t buffLen, const char *src );
errno_t StrNCat_s( char *dst, size_t buffLen, const char *src, size_t num );
char *StrTok_s( char *str, const char *delim, char **context );

#ifndef USE_SAFE

#define StrLen StrLen_us
#define StrCpy StrCpy_us
#define StrNCpy StrNCpy_us
#define StrCat StrCat_us
#define StrNCat StrNCat_us
#define StrTok StrTok_u
#define StrError StrError_us

#else /* USE_SAFE */

#define StrLen StrNLen
#define StrCpy StrCpy_s
#define StrNCpy StrNCpy_s
#define StrCat StrCat_s
#define StrNCat StrNCat_s
#define StrTok StrTok_s
#define StrError StrError_s

#endif /* USE_SAFE */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* MYSTRING_H */