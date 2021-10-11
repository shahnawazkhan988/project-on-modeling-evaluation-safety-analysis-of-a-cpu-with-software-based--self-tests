#include "RWDPVNodes.h"

RWDPV0Worker::RWDPV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&san);
}

RWDPV0Worker::~RWDPV0Worker() {
  delete [] TheModelPtr;
}

double RWDPV0Worker::Reward_Function(void) {

if(san->catastrophic_failure->Mark()>0||san->safe_failure->Mark()>0)
{
	return 1;
}

return (0);



}

RWDPV0::RWDPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThesanSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("Cpu_Failure",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("catastrophic_failure","san");
  AddVariableDependency("safe_failure","san");
}

RWDPV0::~RWDPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RWDPV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RWDPV0Worker;
}
RWDPV1Worker::RWDPV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&san);
}

RWDPV1Worker::~RWDPV1Worker() {
  delete [] TheModelPtr;
}

double RWDPV1Worker::Reward_Function(void) {

if(san->catastrophic_failure->Mark()>0||san->safe_failure->Mark()>0)
{
//P_cond_catast=p_catastrop/(p_cpu_fail)
//p_fail_catast/(p_fail_catast+p_fail_safe)
	return ((san->catastrophic_failure->Mark())/(san->catastrophic_failure->Mark()+san->safe_failure->Mark()));
	
}


return (0);



}

RWDPV1::RWDPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThesanSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("cpu_catastrophic_failure",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("catastrophic_failure","san");
  AddVariableDependency("safe_failure","san");
}

RWDPV1::~RWDPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RWDPV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RWDPV1Worker;
}
RWDPV2Worker::RWDPV2Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&san);
}

RWDPV2Worker::~RWDPV2Worker() {
  delete [] TheModelPtr;
}

double RWDPV2Worker::Reward_Function(void) {

if(san->catastrophic_failure->Mark()>0||san->safe_failure->Mark()>0)
{
	return (1-(san->catastrophic_failure->Mark())/(san->catastrophic_failure->Mark()+san->safe_failure->Mark()));	
}

return (0);



}

RWDPV2::RWDPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThesanSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("cpu_safe_failure",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("catastrophic_failure","san");
  AddVariableDependency("safe_failure","san");
}

RWDPV2::~RWDPV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RWDPV2::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RWDPV2Worker;
}
