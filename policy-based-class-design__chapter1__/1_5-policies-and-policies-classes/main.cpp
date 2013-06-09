#include			"Creator.hpp"

///////////////////////////
// widget class for test //
///////////////////////////

class				Widget
{
public:
  Widget			*clone()
  {
    return new Widget;
  }
};


//////////////////
// FIRST METHOD //
//////////////////

//// host class //

// template			<class CreationPolicy>
// class				WidgetManager : public CreationPolicy
// {
// };


//// we define 3 widgetmanager using different Policies //

// typedef				WidgetManager<OpNewCreator<Widget> > WidgetManagerNew;
// typedef				WidgetManager<MallocCreator<Widget> > WidgetManagerMalloc;
// typedef				WidgetManager<PrototypeCreator<Widget> > WidgetManagerProto;


///////////////////
// SECOND METHOD //
///////////////////

//// we also can define or hostclass like this //
//// with template template parameters	     //

template			<template <class Created> class CreationPolicy>
class				WidgetManager : public CreationPolicy<Widget>
{};

//// we define 3 widgetmanager using different Policies //

typedef				WidgetManager<OpNewCreator> WidgetManagerNew;
typedef				WidgetManager<MallocCreator> WidgetManagerMalloc;
typedef				WidgetManager<PrototypeCreator> WidgetManagerProto;



int				main(void)
{
  WidgetManagerNew		n;
  WidgetManagerMalloc		m;
  WidgetManagerProto		p;
  Widget			*w;

  w = n.create();
  if (w)
    {
      std::cout << "Widget created with NEW" << std::endl;
      delete w;
    }
  w = m.create();
  if (w)
    {
      std::cout << "Widget created with MALLOC" << std::endl;
    }

  p.setPrototype(w);

  free(w);
  w = NULL;

  std::cout << p.getPrototype() << std::endl;
  w = p.create();
  if (w)
    {
      std::cout << "Widget created with PROTOTYPE" << std::endl;
      delete w;
    }
  return 0;
}
