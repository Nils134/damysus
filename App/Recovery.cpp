#include "Recovery.h"

Recovery::Recovery() {
  this->set   = false;
  this->view = 0;
  this->nonce = 0;
  this->sign = Sign();
}

std::string Recovery::prettyPrint() {
    return ("RECOVERY[" + std::to_string(this->set) + "," + std::to_string(this->view) +  "," + std::to_string(this->nonce)+ ","+ (this->sign).prettyPrint() + "]");
}
  
std::string Recovery::toString() {
    return (std::to_string(this->set) + std::to_string(this->view) +  std::to_string(this->nonce) +(this->sign).prettyPrint() );
}