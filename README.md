# libevent

An event notification C library.

The `libevent` API provides a mechanism to execute a callback function when a
specific event occurs on a file descriptor or after a timeout has been
reached. Furthermore, `libevent` also supports callbacks due to signals or
regular timeouts.

`libevent` is meant to replace the event loop found in event driven network
servers. An application just needs to call `event_dispatch()` and then add or
remove events dynamically without having to change the event loop.

Currently, `libevent` supports `/dev/poll`, `kqueue(2)`, event ports, POSIX
`select(2)`, Windows `select()`, `poll(2)`, and `epoll(4)`.

`libevent` additionally provides a sophisticated framework for buffered
network IO, with support for sockets, filters, rate-limiting, SSL, zero-copy
file transmission, and IOCP. `libevent` includes support for several useful
protocols, including DNS, HTTP, and a minimal RPC framework.

For more information see:

- Website:     http://libevent.org/
- Manual/book: http://www.wangafu.net/~nickm/libevent-book/
