#include <openssl/ssl.h>

#include <event2/event.h>
#include <event2/bufferevent_ssl.h>

int
main ()
{
  struct event_base* base = event_base_new ();
  if (base == NULL)
    return 1;

  SSL_CTX* ssl_ctx = SSL_CTX_new (TLS_method ());
  if (ssl_ctx == NULL)
    return 1;

  SSL* ssl = SSL_new (ssl_ctx);
  if (ssl == NULL)
    return 1;

  struct bufferevent* buf =
      bufferevent_openssl_socket_new (base, -1, ssl, 0, 0);
  if (buf == NULL)
    return 1;

  bufferevent_free (buf);
  SSL_free (ssl);
  SSL_CTX_free (ssl_ctx);
  event_base_free (base);

  return 0;
}
