# libevent - An event notification C library

This is a `build2` package for the [`libevent`](https://libevent.org) C
library. It provides a mechanism to execute a callback function when
a specific event occurs on a file descriptor or after a timeout has been
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


## Usage

To start using this library in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libevent ^2.1.12
```

Then import the library in your `buildfile`:

```
import libs = libevent%lib{event_core}
```

If you need one or more of the optional libraries (discussed below), then you
will need to use the dependency configuration mechanism to enable them. For
example, if you wish to use both `lib{event_core}` and `lib{event_extra}` in
your project, then you can add the following to your `manifest`:

```
depends:
\
libevent ^2.1.12
{
  require
  {
    config.libevent.extra = true
  }
}
\
```

And the following to your `buildfile`:

```
import libs = libevent%lib{event_core event_extra}
```

## Importable targets

This package provides the following importable targets (see the upstream
documentation for background):

```
lib{event_core}
lib{event_extra}
lib{event_openssl}
lib{event_pthreads}
```

All the libraries except `lib{event_core}` are optional, disabled by
default, and can be enabled with the corresponding configuration variables
(discussed below).


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libevent.extra    ?= false
[bool] config.libevent.openssl  ?= false
[bool] config.libevent.pthreads ?= false
```

These variables can be used to enable the corresponding optional libraries
(discussed above). Note that an attempt to enable the `lib{event_pthreads}`
library on Windows has no effect.

Note also that the `lib{event_core}` library provides `build2` metadata that
describes the effective configuration:

```
lib{event_core}:
{
  libevent.extra    = $config.libevent.extra
  libevent.openssl  = $config.libevent.openssl
  libevent.pthreads = $config.libevent.pthreads
}
```
