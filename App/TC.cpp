#include "TC.h"

TC::TC() {
  this->set   = false;
  this->view = 0;
  this->signs = Signs();
}

TC::TC(View view, Signs signs) {
  this->set = true;
  this->view = view;
  this->sign = sign;
}

bool  TC::isSet() { return this->set;}
View TC::getView() { return this->view;}
Signs TC::getSigns() {return this->signs;}

void TC::serialize(salticidae::DataStream &data) const {
  data << this->set << this->view << this->signs;
}


void TC::unserialize(salticidae::DataStream &data) {
  data >> this->set >> this->view >> this->signs;
}

std::string TC::prettyPrint() {
    return ("TC[" + std::to_string(this->set) + "," + std::to_string(this->view) +  ","+ (this->signs).prettyPrint() + "]");
}
  
std::string TC::toString() {
    return (std::to_string(this->set) + std::to_string(this->view) +(this->signs).prettyPrint() );
}