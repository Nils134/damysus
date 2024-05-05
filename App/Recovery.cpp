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

bool  Recovery::isSet() { return this->set;}
View Recovery::getView() {return this->view;}
uint32_t Recovery::getNonce() {return this->nonce;}
Sign Recovery::getSign() { return this->sign;}

void Recovery::serialize(salticidae::DataStream &data) const {
  data << this->set << this->view << this->nonce << this->sign;
}


void Recovery::unserialize(salticidae::DataStream &data) {
  data >> this->set >> this->view >> this->nonce >> this->sign;
}

std::string Recovery::prettyPrint() {
    return ("RECOVERY[" + std::to_string(this->set) + "," + std::to_string(this->view) +  "," + std::to_string(this->nonce)+ ","+ (this->sign).prettyPrint() + "]");
}
  
std::string Recovery::toString() {
    return (std::to_string(this->set) + std::to_string(this->view) +  std::to_string(this->nonce) +(this->sign).prettyPrint() );
}