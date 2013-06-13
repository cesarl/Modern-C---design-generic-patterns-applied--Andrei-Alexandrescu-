class				Interface
{
public:
  virtual void			func() = 0;
};

template			<class T, class P>
Interface			*MakeAdapter(const T & obj, cont P & arg)
{
  class				Local : public Interface
  {
  public:
    Local(const T & obj, const P & arg) :
      obj_(obj), arg_(arg)
    {}

    virtual void		func()
    {
      obj_.call(this->arg_);
    }
  private:
    T				obj_;
    P				arg_;
  };
  return			new Local(obj, arg);
}
