#include "Wish.h"

Wish::Wish() {
  this->set   = false;
  this->view = 0;
  this->recoveredView = 0;
  this->sign = Sign();
}


std::string Wish::prettyPrint() {
    return ("WISH[" + std::to_string(this->set) + "," + std::to_string(this->view) +  "," + std::to_string(this->recoveredView)+ ","+ (this->sign).prettyPrint() + "]");
}
  
std::string Wish::toString() {
    return (std::to_string(this->set) + std::to_string(this->view) +  std::to_string(this->recoveredView) +(this->sign).prettyPrint() );
}