#include "QC.h"

QC::QC() {
  this->set   = false;
  this->view = 0;
  this->signs = Signs();
}

QC::QC(View view, Signs signs) {
  this->set = true;
  this->view = view;
  this->signs = signs;
}

bool  QC::isSet() { return this->set;}
View QC::getView() { return this->view;}
Signs QC::getSigns() {return this->signs;}

void QC::serialize(salticidae::DataStream &data) const {
  data << this->set << this->view << this->signs;
}


void QC::unserialize(salticidae::DataStream &data) {
  data >> this->set >> this->view >> this->signs;
}

std::string QC::prettyPrint() {
    return ("QC[" + std::to_string(this->set) + "," + std::to_string(this->view) +  ","+ (this->signs).prettyPrint() + "]");
}
  
std::string QC::toString() {
    return (std::to_string(this->set) + std::to_string(this->view) +(this->signs).prettyPrint() );
}