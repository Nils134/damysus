#ifndef TC_H
#define TC_H


#include "Signs.h"

#include "salticidae/stream.h"


class TC {

 private:
  bool set = false;
  View view;
  Signs signs; // signature

 public:
  TC();
  TC(View view, Signs signs);

  bool  isSet();
  View getView(); 
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