#ifndef RECOVERY_H
#define RECOVERY_H


#include "Signs.h"

#include "salticidae/stream.h"


class Recovery {

 private:
  bool set = false;
  View view = 0;
  uint32_t nonce = 0;
  Sign sign; // signature

 public:
  Recovery();
  Recovery(View view, View recoveredView, Sign sign);

  bool  isSet();
  Signs getSigns();

  void serialize(salticidae::DataStream &data) const;
  void unserialize(salticidae::DataStream &data);

  std::string prettyPrint();
  std::string toString();

  bool wellFormedInit();
  bool wellFormedNv();
  bool wellFormedPrep(unsigned int qsize);
  bool wellFormed(unsigned int qsize);
  View getCView();
  Hash getCHash();
};


#endif