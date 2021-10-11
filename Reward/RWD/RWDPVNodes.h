#ifndef _RWD_PVS_
#define _RWD_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/san/sanSAN.h"
#include "Cpp/Performance_Variables/SteadyState.hpp"


class RWDPV0Worker:public SteadyState
{
 public:
  sanSAN *san;
  
  RWDPV0Worker();
  ~RWDPV0Worker();
  double Reward_Function();
};

class RWDPV0:public PerformanceVariableNode
{
 public:
  sanSAN *ThesanSAN;

  RWDPV0Worker *RWDPV0WorkerList;

  RWDPV0(int timeindex=0);
  ~RWDPV0();
  void CreateWorkerList(void);
};

class RWDPV1Worker:public SteadyState
{
 public:
  sanSAN *san;
  
  RWDPV1Worker();
  ~RWDPV1Worker();
  double Reward_Function();
};

class RWDPV1:public PerformanceVariableNode
{
 public:
  sanSAN *ThesanSAN;

  RWDPV1Worker *RWDPV1WorkerList;

  RWDPV1(int timeindex=0);
  ~RWDPV1();
  void CreateWorkerList(void);
};

class RWDPV2Worker:public SteadyState
{
 public:
  sanSAN *san;
  
  RWDPV2Worker();
  ~RWDPV2Worker();
  double Reward_Function();
};

class RWDPV2:public PerformanceVariableNode
{
 public:
  sanSAN *ThesanSAN;

  RWDPV2Worker *RWDPV2WorkerList;

  RWDPV2(int timeindex=0);
  ~RWDPV2();
  void CreateWorkerList(void);
};

#endif
