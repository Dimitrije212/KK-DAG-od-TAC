#include "ast.hpp"

#include <iostream>
#include <map>
#include <string>
using namespace std;

map<int, string> odlazno;
map<string, int> dolazno;
int br = 1;
int trenutni = 0;
bool prethodnoGoTo = false;

InnerSynTree::~InnerSynTree() {
  for (unsigned i = 0; i < _v.size(); i++)
    delete _v[i];
}

InnerSynTree::InnerSynTree(SynTree *t) {
  _v.push_back(t);
}


InnerSynTree::InnerSynTree(SynTree *l, SynTree *r) {
  _v.push_back(l);
  _v.push_back(r);
}

void Broj::ispisi() const {
  cout  << _num;
}

void Prom::ispisi() const {
  cout << _name;
}

void Saberi::ispisi() const {
  if(prethodnoGoTo) {
    cout << br << " [label = \"";
    trenutni = br;
  }
  // cout << br << ": ";
  cout << _s << " := ";
  _v[0]->ispisi();
  cout << " + ";
  _v[1]->ispisi();
  cout << endl;
  br++;
  prethodnoGoTo = false;
}
void Oduzmi::ispisi() const {
  if(prethodnoGoTo) {
    cout << br << " [label = \"";
    trenutni = br;
  }
  // cout << br << ": ";
  cout << _s << " := ";
  _v[0]->ispisi();
  cout << " - ";
  _v[1]->ispisi();
  cout << endl;
  br++;
  prethodnoGoTo = false;
}
void Pomnozi::ispisi() const {
  if(prethodnoGoTo) {
    cout << br << " [label = \"";
    trenutni = br;
  }
  // cout << br << ": ";
  cout << _s << " := ";
  _v[0]->ispisi();
  cout << " * ";
  _v[1]->ispisi();
  cout << endl;
  br++;
  prethodnoGoTo = false;
}
void Podeli::ispisi() const {
  if(prethodnoGoTo) {
    cout << br << " [label = \"";
    trenutni = br;
  }
  // cout << br << ": ";
  cout << _s << " := ";
  _v[0]->ispisi();
  cout << " / ";
  _v[1]->ispisi();
  cout << endl;
  br++;
  prethodnoGoTo = false;
}
void Dodeli::ispisi() const {
  if(prethodnoGoTo) {
    cout << br << " [label = \"";
    trenutni = br;
  }
  // cout << br << ": ";
  cout << _id << " := ";
  _v[0]->ispisi();
  cout << endl;
  br++;
  prethodnoGoTo = false;
}
void Negacija::ispisi() const {
  if(prethodnoGoTo) {
    cout << br << " [label = \"";
    trenutni = br;
  }
  // cout << br << ": ";
  cout << _id << " := - ";
  _v[0]->ispisi();
  cout << endl;
  br++;
  prethodnoGoTo = false;
}
void Stampaj::ispisi() const {
  if(prethodnoGoTo) {
    cout << br << " [label = \"";
    trenutni = br;
  }
  // cout << br << ": ";
  cout << "print ";
  _v[0]->ispisi();
  cout << endl;
  br++;
  prethodnoGoTo = false;
}
void Labela::ispisi() const {
  if(!prethodnoGoTo && br != 1)
    cout << "\"]\n" << trenutni << " -> " << br << endl;

  for(unsigned i = 0; i < odlazno.size(); i++)
    if(odlazno[i] == _s) {
      cout << i << " -> " << br << endl;
    }
  if(br != 1)
    cout << br << " [label = \"";
  trenutni = br;
  dolazno[_s] = trenutni;
  // if(!k) {
  //   dolazno[_s] = trenutni+1;
  // }
  // cout << br << ": ";
  cout << _s << ":" << endl;
  br++;
  prethodnoGoTo = false;
}
void IfGtGoto::ispisi() const {
  if(prethodnoGoTo) {
    cout << br << " [label = \"";
    trenutni = br;
  }
  // cout << br << ": ";
  cout << "if ";
  _v[0]->ispisi();
  cout << " > ";
  _v[1]->ispisi();
  cout << " goto " << _s << "\"]" << endl;
  if(dolazno[_s] < br && dolazno[_s] != 0)
    cout << trenutni << " -> " << dolazno[_s] << endl;

  odlazno[trenutni] = _s;
  cout << trenutni << " -> " << br+1 << endl;
  br++;
  prethodnoGoTo = true;
}
void IfLtGoto::ispisi() const {
  if(prethodnoGoTo) {
    cout << br << " [label = \"";
    trenutni = br;
  }
  // cout << br << ": ";
  cout << "if ";
  _v[0]->ispisi();
  cout << " < ";
  _v[1]->ispisi();
  cout << " goto " << _s << "\"]" << endl;
  if(dolazno[_s] < br && dolazno[_s] != 0)
    cout << trenutni << " -> " << dolazno[_s] << endl;

  odlazno[trenutni] = _s;
  cout << trenutni << " -> " << br+1 << endl;
  br++;
  prethodnoGoTo = true;
}
void GoTo::ispisi() const {
  if(prethodnoGoTo) {
    cout << br << " [label = \"";
    trenutni = br;
  }
  // cout << br << ": ";
  cout << "goto " << _s << "\"]" << endl;
  if(dolazno[_s] < br && dolazno[_s] != 0)
    cout << trenutni << " -> " << dolazno[_s] << endl;
  odlazno[trenutni] = _s;
  // cout << br << " -> " << br+1 << endl;
  br++;
  prethodnoGoTo = true;
}
