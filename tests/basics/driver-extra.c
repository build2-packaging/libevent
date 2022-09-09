#include <event2/event.h>
#include <event2/dns.h>

int
main ()
{
  struct event_base* event_base = event_base_new ();
  if (event_base == NULL)
    return 1;

  struct evdns_base* evdns_base =
      evdns_base_new (event_base, EVDNS_BASE_DISABLE_WHEN_INACTIVE);
  if (evdns_base == NULL)
    return 1;

  evdns_base_free (evdns_base, 1);
  event_base_free (event_base);

  return 0;
}
