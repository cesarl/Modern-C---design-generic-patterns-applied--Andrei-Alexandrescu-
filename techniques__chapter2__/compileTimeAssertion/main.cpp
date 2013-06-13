#include			"CompileTimeAssertion.hh"
#include			<string>

struct				Test
{
  int				i;
  int				j;
  char				k;
};

int				main(void)
{
  ///////////////////////
  // compilation error //
  ///////////////////////

  // void				*somePointer = new Test;
  // char				c = safe_reinterpret_cast<char>(somePointer);

  ///////////////////////
  // compilation is ok //
  ///////////////////////

  char					c = 'a';
  int					i = safe_reinterpret_cast<int>(c);

  (void)c;
  (void)i;
  return 0;
}
