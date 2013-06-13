#ifndef				__TYPELIST_HPP__
# define			__TYPELIST_HPP__

/////////////////////////
// typelist definition //
/////////////////////////

template			<class H, class T>
struct				typelist
{
  typedef H			head;
  typedef T			tail;
};

//////////////////////////////
// null_typelist definition //
// for end typelist tail    //
//////////////////////////////

class				null_typelist
{};

/////////////////////////////////
// typelist creation templates //
/////////////////////////////////

template <class Fun>
struct cons;

template <class T1>
struct cons<void (*)(T1)>
{
  typedef typelist<T1, null_typelist> type;
};

template <class T1, class T2>
struct cons<void (*)(T1, T2)>
{
  typedef typelist<T1, typelist<T2, null_typelist> > type;
};

template <class T1, class T2, class T3>
struct cons<void (*)(T1, T2, T3)>
{
  typedef typelist<T1, typelist<T2, typelist<T3, null_typelist> > > type;
};

template <class T1, class T2, class T3, class T4>
struct cons<void (*)(T1, T2, T3, T4)>
{
  typedef typelist<T1, typelist<T2, typelist<T3, typelist<T4, null_typelist> > > > type;
};

#define				TYPELIST(a) cons< void (*)a >::type;

// template			<class T1>
// struct				cons<T1, null_typelist, null_typelist, null_typelist>
// {
//   typedef typelist<T1, null_typelist> type;
// };

// template			<class T1, class T2>
// struct				cons<T1,
// 				     T2,
// 				     null_typelist,
// 				     null_typelist>
// {
//   typedef typelist<T1, typelist<T2, null_typelist> > type;
// };

// template			<class T1, class T2, class T3>
// struct				cons<T1,
// 				     T2,
// 				     T3,
// 				     null_typelist>
// {
//   typedef typelist<T1, typelist<T2, typelist<T3, null_typelist> > > type;
// };

// template			<class T1, class T2, class T3, class T4>
// struct				cons<T1,
// 				     T2,
// 				     T3,
// 				     T4>
// {
//   typedef typelist<T1, typelist<T2, typelist<T3, typelist<T4, null_typelist> > > > type;
// };



#endif				// __TYPELIST_HPP__
