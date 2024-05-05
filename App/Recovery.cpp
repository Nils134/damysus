#include "Recovery.h"

Recovery::Recovery() {
  this->set   = false;
  this->view = 0;
  this->nonce = 0;
  this->sign = Sign();
}

Recovery::Recovery(View view, u_int32_t nonce, Sign sign) {
  this->set = true;
  this->view = view;
  this->nonce = nonce;
  this->sign = sign;
}

bool  isSet() { return this->set;}
View getView() {return this->view;}
uint32_t getNonce() {return this->nonce;}
Sign getSign() { return this->sign;}

void Wish::serialize(salticidae::DataStream &data) const {
  data << this->set << this->view << this->nonce << this->sign;
}


void Wish::unserialize(salticidae::DataStream &data) {
  data >> this->set >> this->view >> this->nonce >> this->sign;
}

std::string Recovery::prettyPrint() {
    return ("RECOVERY[" + std::to_string(this->set) + "," + std::to_string(this->view) +  "," + std::to_string(this->nonce)+ ","+ (this->sign).prettyPrint() + "]");
}
  
std::string Recovery::toString() {
    return (std::to_string(this->set) + std::to_string(this->view) +  std::to_string(this->nonce) +(this->sign).prettyPrint() );
}