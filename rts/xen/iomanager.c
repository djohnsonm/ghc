#include "Rts.h"
#include "Prelude.h"

static int controlFd = -1;
static int wakeupFd = -1;

void setIOManagerControlFd(int fd)
{
  printf("setIOManagerControlFd()\n");
  controlFd = fd;
}

void setIOManagerWakeupFd(int fd)
{
  printf("setIOManagerWakeupFd()\n");
  wakeupFd = fd;
}

void ioManagerWakeup(void)
{
  printf("ioManagerWakeup()\n");
  // FIXME
}

#ifdef THREADED_RTS
void ioManagerDie(void)
{
  if(controlFd >= 0) {
    printf("ioManagerDie: controlFd: %d wakeupFd: %d\n", controlFd, wakeupFd);
  }
}

void ioManagerStart(void)
{
  Capability *cap;

  if(controlFd < 0 || wakeupFd < 0) {
    cap = rts_lock();
    rts_evalIO(&cap, &base_GHCziConcziIO_ensureIOManagerIsRunning_closure,NULL);
    rts_unlock(cap);
  }
}
#endif
