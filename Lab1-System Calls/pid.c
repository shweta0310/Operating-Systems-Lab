#include <sys/types.h>
#include <unistd.h>
int main()
{
       pid_t getpid(void);
	printf("\ngetpid() = %d",getpid());
       pid_t getppid(void);
	printf("\ngetppid() = %d\n",getppid());
	return 0;
}
/*getpid() returns the process ID (PID) of the calling process.  (This
       is often used by routines that generate unique temporary filenames.)

       getppid() returns the process ID of the parent of the calling
       process.  This will be either the ID of the process that created this
       process using fork(), or, if that process has already terminated, the
       ID of the process to which this process has been reparented (either
       init(1) or a "subreaper" process defined via the prctl(2)
       PR_SET_CHILD_SUBREAPER operation).*/
