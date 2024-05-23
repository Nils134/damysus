#ifndef TRUSTEDFUN_H
#define TRUSTEDFUN_H


#include "Hash.h"
#include "Just.h"
#include "Stats.h"
#include "Wish.h"
#include "TC.h"
#include "QC.h"
#include "Recovery.h"


class TrustedFun {

 private:
  Hash   lockh;          // hash of the last locked block
  View   lockv;          // lockh's view
  Hash   preph;          // hash of the last prepared block
  View   prepv;          // preph's view
  View   view;           // current view
  Phase1 phase;          // current phase
  PID    id;             // unique identifier
  KEY    priv;           // private key
  unsigned int qsize;    // quorum size

  Just sign(Hash h1, Hash h2, View v2);
  void increment();

 public:
  TrustedFun();
  TrustedFun(unsigned int id, KEY priv, unsigned int q);

  Just TEEsign(Stats &stats);
  Just TEEprepare(Stats &stats, Nodes nodes, Hash hash, Just just);
  Just TEEstore(Stats &stats, Nodes nodes, Just just);
  bool TEEverify(Stats &stats, Nodes nodes, Just just);

  //TODO: add epoch functions
  void TEErollback(Stats & stats, View v);
  Wish TEEwish(Stats &stats);
  Recovery TEErecovery(Stats &stats);
  TC TEEreceiveTC(TC incomingTC, Stats &stats);
  int TEEreceiveQC(QC qc, Stats &stats);

  TC TEEleaderWish(Signs wishes, Stats &stats);
  QC TEEcreateQuorum(TC tc);
};


#endif
