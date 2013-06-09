#ifndef				__CREATOR_HPP__
# define			__CREATOR_HPP__

#include			<iostream>
#include			<cstdlib>


//////////////////////////////////
// --------		        //
// 3 different creator policies //
// --------		        //
//////////////////////////////////


template			<class T>
struct				OpNewCreator
{
  static T			*create()
  {
    return new T;
  }
};

template			<class T>
struct				MallocCreator
{
  static T			*create()
  {
    void			*buf = malloc(sizeof(T));

    if (!buf)
      return NULL;
    return new(buf) T;
  }
};

template			<class T>
struct				PrototypeCreator
{
  PrototypeCreator(T *pObj = NULL) :
    prototype_(pObj)
  {}

  T				*create()
  {
    return this->prototype_ ? this->prototype_->clone() : NULL;
  }

  T				*getPrototype()
  {
    return this->prototype_;
  }

  void				setPrototype(T *obj)
  {
    this->prototype_ = obj;
  }

private:
  T				*prototype_;
};

#endif				// __CREATOR_HPP__
