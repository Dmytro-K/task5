#undef USE_SAFE
#include "mystring.h"
#include <stdio.h>

int main()
{
	errno_t i = EINVAL;
	puts( StrError( i ) );
	printf("%X\n", SIZE_T_MAX );
	return 0;
}