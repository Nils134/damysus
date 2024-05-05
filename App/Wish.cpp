#include "Wish.h"

Wish::Wish() {
  this->set   = false;
  this->view = 0;
  this->recoveredView = 0;
  this->sign = Sign();
}