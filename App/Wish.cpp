#include "Wish.h"

Wish::Wish() {
  this->set   = false;
  this->view = 0;
  this->recoveredView = 0;
  this->sign = Sign();
}

Wish::Wish(View view, View recoveredView, Sign sign) {
  this->set = true;
  this->view = view;
  this->recoveredView = recoveredView;
  this->sign = sign;
}

void Wish::serialize(salticidae::DataStream &data) const {
  data << this->set << this->view << this->recoveredView << this->sign;
}


void Wish::unserialize(salticidae::DataStream &data) {
  data >> this->set >> this->view >> this->recoveredView >> this->sign;
}

std::string Wish::prettyPrint() {
    return ("WISH[" + std::to_string(this->set) + "," + std::to_string(this->view) +  "," + std::to_string(this->recoveredView)+ ","+ (this->sign).prettyPrint() + "]");
}
  
std::string Wish::toString() {
    return (std::to_string(this->set) + std::to_string(this->view) +  std::to_string(this->recoveredView) +(this->sign).prettyPrint() );
}