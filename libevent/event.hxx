#pragma once

#include <iosfwd>
#include <string>

#include <libevent/export.hxx>

namespace event
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  LIBEVENT_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
