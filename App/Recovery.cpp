#include "Recovery.h"

Recovery::Recovery() {
  this->set   = false;
  this->view = 0;
  this->nonce = 0;
  this->sign = Sign();
}