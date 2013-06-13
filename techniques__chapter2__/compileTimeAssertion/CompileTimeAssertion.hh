#ifndef					__COMPILE_TIME_ASSERTION_HH__
# define				__COMPILE_TIME_ASSERTION_HH__

template				<bool>
struct					CompileTimeChecker
{
  CompileTimeChecker(...){};
};

template				<>
struct					CompileTimeChecker<false>
{};

#define					STATIC_CHECK(expr, msg) \
  { \
  class ERROR_##msg {}; \
  new CompileTimeChecker<(expr) != 0>((ERROR_##msg())); \
}

// dont work with g++

template				<class To, class From>
To					safe_reinterpret_cast(From from)
{
  STATIC_CHECK((sizeof(From) <= sizeof(To)), Destination_Type_Too_Narrow);
  return (reinterpret_cast<To>(from));
}

#endif					// __COMPILE_TIME_ASSERTION_HH__
