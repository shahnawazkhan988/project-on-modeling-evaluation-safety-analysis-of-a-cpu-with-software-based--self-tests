#include "RWDPVModel.h"

RWDPVModel::RWDPVModel(bool expandTimeArrays) {
  TheModel=new sanSAN();
  DefineName("RWDPVModel");
  CreatePVList(3, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* RWDPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new RWDPV0(timeindex);
    break;
  case 1:
    return new RWDPV1(timeindex);
    break;
  case 2:
    return new RWDPV2(timeindex);
    break;
  }
  return NULL;
}
