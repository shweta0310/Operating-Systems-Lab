//getuid() & geteuid returns the real user ID of the calling process.
#include <unistd.h>
#include <sys/types.h>
int main()
{
uid_t getuid(void);
printf("\ngetuid() = %d",getuid);
uid_t geteuid(void);
printf("\ngeteuid() = %d",geteuid);
gid_t getgid(void);
printf("\ngetgid() = %d",getgid);
gid_t getegid(void); 
printf("\ngetegid() = %d",getegid);
return 0;
}
/*
getgid() returns the real group ID of the current process.

getegid() returns the effective group ID of the current process. 
*/
