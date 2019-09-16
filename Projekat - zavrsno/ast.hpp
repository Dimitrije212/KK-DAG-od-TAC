#ifndef __AST_HPP__
#define __AST_HPP__ 1

#include <string>
#include <vector>
using namespace std;

class SynTree {
public:
  virtual void ispisi() const = 0;
  virtual ~SynTree() {

  }
};

class Broj : public SynTree {
public:
  Broj(int num)
    :_num(num)
  {}
  void ispisi() const;
private:
  int _num;
};

class Prom : public SynTree {
public:
  Prom(string name)
    :_name(name)
  {}
  void ispisi() const;
private:
  string _name;
};

class InnerSynTree : public SynTree {
public:
  InnerSynTree(vector<SynTree*> v)
    :_v(v)
  {}
  InnerSynTree(SynTree *t);
  InnerSynTree(SynTree *l, SynTree *r);
  ~InnerSynTree();
private:
  InnerSynTree(const InnerSynTree&);
  InnerSynTree& operator=(const InnerSynTree&);
protected:
  vector<SynTree*> _v;
};

class Saberi : public InnerSynTree {
public:
  Saberi(string s, SynTree *l, SynTree *r)
    :InnerSynTree(l, r), _s(s)
  {}
  void ispisi() const;
private:
  string _s;
};

class Oduzmi : public InnerSynTree {
public:
  Oduzmi(string s, SynTree *l, SynTree *r)
    :InnerSynTree(l, r), _s(s)
  {}
  void ispisi() const;
private:
  string _s;
};

class Pomnozi : public InnerSynTree {
public:
  Pomnozi(string s, SynTree *l, SynTree *r)
    :InnerSynTree(l, r), _s(s)
  {}
  void ispisi() const;
private:
  string _s;
};

class Podeli : public InnerSynTree {
public:
  Podeli(string s, SynTree *l, SynTree *r)
    :InnerSynTree(l, r), _s(s)
  {}
  void ispisi() const;
private:
  string _s;
};

class Dodeli : public InnerSynTree {
public:
  Dodeli(string id, SynTree *t)
    :InnerSynTree(t), _id(id)
  {}
  void ispisi() const;
private:
  string _id;
};

class Negacija : public InnerSynTree {
public:
  Negacija(string id, SynTree *t)
    :InnerSynTree(t), _id(id)
  {}
  void ispisi() const;
private:
  string _id;
};

class Stampaj : public InnerSynTree {
public:
  Stampaj(SynTree* t)
    :InnerSynTree(t)
  {}
  void ispisi() const;
};

class Labela : public SynTree {
public:
  Labela(string s)
    :_s(s)
  {}
  void ispisi() const;
private:
  string _s;
};

class IfGtGoto : public InnerSynTree {
public:
  IfGtGoto(SynTree *l, SynTree *r, string s)
    :InnerSynTree(l, r), _s(s)
  {}
  void ispisi() const;
private:
  string _s;
};

class IfLtGoto : public InnerSynTree {
public:
  IfLtGoto(SynTree *l, SynTree *r, string s)
    :InnerSynTree(l, r), _s(s)
  {}
  void ispisi() const;
private:
  string _s;
};

class GoTo : public SynTree {
public:
  GoTo(string s)
    :_s(s)
  {}
  void ispisi() const;
private:
  string _s;
};
#endif
