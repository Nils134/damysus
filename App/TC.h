#ifndef WISH_H
#define WISH_H


#include "Sign.h"

#include "salticidae/stream.h"


class Wish {

 private:
  bool set = false;
  View view;
  View recoveredView;
  Sign sign; // signature

 public:
  TC();
  TC(View view, Signs signs);

  bool  isSet();
  View getView(); 
  View getRecView();
  Signs getSigns();

  void serialize(salticidae::DataStream &data) const;
  void unserialize(salticidae::DataStream &data);

  std::string prettyPrint();
  std::string toString();

  // bool wellFormedInit();
  // bool wellFormedNv();
  // bool wellFormedPrep(unsigned int qsize);
  // bool wellFormed(unsigned int qsize);
  // View getCView();
  // Hash getCHash();
};


#endif