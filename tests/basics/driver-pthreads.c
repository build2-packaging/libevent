#include <event2/event.h>
#include <event2/thread.h>

int
main ()
{
  evthread_use_pthreads ();

  struct event_base* base = event_base_new ();
  if (base == NULL)
    return 1;

  event_base_free (base);

  return 0;
}
