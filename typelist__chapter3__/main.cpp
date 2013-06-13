////////////////////////////////////////////////////////////////////////////////////////////////////////////
// usefull readings											  //
// 													  //
// http://metacpp.codeplex.com/wikipage?title=Typelists%20basics					  //
// 													  //
// https://docs.google.com/viewer?url=http%3A%2F%2Fwww.semantics.org%2Fonce_weakly%2Fw12_tlalgorithms.pdf //
// 													  //
// http://loulou.developpez.com/tutoriels/cpp/metaprog/							  //
// 													  //
// http://alpmestan.wordpress.com/2009/12/03/functional-compile-time-templates-based-type-lists-in-c/	  //
// 													  //
// http://www.drdobbs.com/generic-programmingtypelists-and-applica/184403813#disqus_thread		  //
// 													  //
// http://www.icce.rug.nl/documents/cplusplus/cplusplus22.html						  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include			"Typelist.hpp"

typedef				cons< void (*) (float, double, long double, int) >::type floatingPointTypes;

int				main()
{

  return 0;
}
