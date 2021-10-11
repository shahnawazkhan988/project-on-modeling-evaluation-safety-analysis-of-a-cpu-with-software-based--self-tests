#ifndef _RWD_PVMODEL_
#define _RWD_PVMODEL_
#include "RWDPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/san/sanSAN.h"
class RWDPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  RWDPVModel(bool expandtimepoints);
};

#endif
