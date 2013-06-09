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
protected:
  ~OpNewCreator()
  {
    std::cout << "OpNewCreator is deleted" << std::endl;
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
protected:
  ~MallocCreator()
  {
    std::cout << "MallocCreator is deleted" << std::endl;
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
protected:
  ~PrototypeCreator()
  {
    std::cout << "Prototype is deleted" << std::endl;
  }
};

#endif				// __CREATOR_HPP__
