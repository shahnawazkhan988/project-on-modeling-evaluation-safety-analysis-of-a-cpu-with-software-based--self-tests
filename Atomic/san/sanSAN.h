#ifndef sanSAN_H_
#define sanSAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Double safe_restore_rate_G;
extern Double test_execution_rate_G;
extern Double pperm_fault_G;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               sanSAN Submodel Definition                   
*********************************************************************/

class sanSAN:public SANModel{
public:

class fault_rate_LActivity_case1:public Activity {
public:

  Place* L;
  short* L_Mobius_Mark;
  Place* perm_fault_L;
  short* perm_fault_L_Mobius_Mark;

  double* TheDistributionParameters;
  fault_rate_LActivity_case1();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // fault_rate_LActivity_case1Activity

class fault_rate_LActivity_case2:public Activity {
public:

  Place* L;
  short* L_Mobius_Mark;
  Place* P_error_L;
  short* P_error_L_Mobius_Mark;

  double* TheDistributionParameters;
  fault_rate_LActivity_case2();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // fault_rate_LActivity_case2Activity

class fault_rate_RActivity_case1:public Activity {
public:

  Place* R;
  short* R_Mobius_Mark;
  Place* perm_fault_R;
  short* perm_fault_R_Mobius_Mark;

  double* TheDistributionParameters;
  fault_rate_RActivity_case1();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // fault_rate_RActivity_case1Activity

class fault_rate_RActivity_case2:public Activity {
public:

  Place* R;
  short* R_Mobius_Mark;
  Place* P_error_R;
  short* P_error_R_Mobius_Mark;

  double* TheDistributionParameters;
  fault_rate_RActivity_case2();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // fault_rate_RActivity_case2Activity

class fault_rate_CActivity_case1:public Activity {
public:

  Place* C;
  short* C_Mobius_Mark;
  Place* perm_fault_C;
  short* perm_fault_C_Mobius_Mark;

  double* TheDistributionParameters;
  fault_rate_CActivity_case1();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // fault_rate_CActivity_case1Activity

class fault_rate_CActivity_case2:public Activity {
public:

  Place* C;
  short* C_Mobius_Mark;
  Place* P_error_C;
  short* P_error_C_Mobius_Mark;

  double* TheDistributionParameters;
  fault_rate_CActivity_case2();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // fault_rate_CActivity_case2Activity

class fault_occurrence_rateActivity_case1:public Activity {
public:

  Place* HW;
  short* HW_Mobius_Mark;
  Place* L;
  short* L_Mobius_Mark;

  double* TheDistributionParameters;
  fault_occurrence_rateActivity_case1();
  ~fault_occurrence_rateActivity_case1();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // fault_occurrence_rateActivity_case1Activity

class fault_occurrence_rateActivity_case2:public Activity {
public:

  Place* HW;
  short* HW_Mobius_Mark;
  Place* R;
  short* R_Mobius_Mark;

  double* TheDistributionParameters;
  fault_occurrence_rateActivity_case2();
  ~fault_occurrence_rateActivity_case2();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // fault_occurrence_rateActivity_case2Activity

class fault_occurrence_rateActivity_case3:public Activity {
public:

  Place* HW;
  short* HW_Mobius_Mark;
  Place* C;
  short* C_Mobius_Mark;

  double* TheDistributionParameters;
  fault_occurrence_rateActivity_case3();
  ~fault_occurrence_rateActivity_case3();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // fault_occurrence_rateActivity_case3Activity

class fault_activatation_rate_LActivity:public Activity {
public:

  Place* perm_fault_L;
  short* perm_fault_L_Mobius_Mark;
  Place* P_error_L;
  short* P_error_L_Mobius_Mark;

  double* TheDistributionParameters;
  fault_activatation_rate_LActivity();
  ~fault_activatation_rate_LActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // fault_activatation_rate_LActivityActivity

class fault_activatation_rate_RActivity:public Activity {
public:

  Place* perm_fault_R;
  short* perm_fault_R_Mobius_Mark;
  Place* P_error_R;
  short* P_error_R_Mobius_Mark;

  double* TheDistributionParameters;
  fault_activatation_rate_RActivity();
  ~fault_activatation_rate_RActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // fault_activatation_rate_RActivityActivity

class fault_activatation_rate_CActivity:public Activity {
public:

  Place* perm_fault_C;
  short* perm_fault_C_Mobius_Mark;
  Place* P_error_C;
  short* P_error_C_Mobius_Mark;

  double* TheDistributionParameters;
  fault_activatation_rate_CActivity();
  ~fault_activatation_rate_CActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // fault_activatation_rate_CActivityActivity

class error_prop_rate_LActivity:public Activity {
public:

  Place* P_error_L;
  short* P_error_L_Mobius_Mark;
  Place* catastrophic_failure;
  short* catastrophic_failure_Mobius_Mark;

  double* TheDistributionParameters;
  error_prop_rate_LActivity();
  ~error_prop_rate_LActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // error_prop_rate_LActivityActivity

class error_prop_rate_RActivity:public Activity {
public:

  Place* P_error_R;
  short* P_error_R_Mobius_Mark;
  Place* catastrophic_failure;
  short* catastrophic_failure_Mobius_Mark;

  double* TheDistributionParameters;
  error_prop_rate_RActivity();
  ~error_prop_rate_RActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // error_prop_rate_RActivityActivity

class error_prop_rate_CActivity:public Activity {
public:

  Place* P_error_C;
  short* P_error_C_Mobius_Mark;
  Place* catastrophic_failure;
  short* catastrophic_failure_Mobius_Mark;

  double* TheDistributionParameters;
  error_prop_rate_CActivity();
  ~error_prop_rate_CActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // error_prop_rate_CActivityActivity

class cat_rest_rateActivity:public Activity {
public:

  Place* catastrophic_failure;
  short* catastrophic_failure_Mobius_Mark;
  Place* HW;
  short* HW_Mobius_Mark;
  Place* Test_L;
  short* Test_L_Mobius_Mark;
  Place* Test_R;
  short* Test_R_Mobius_Mark;
  Place* Test_C;
  short* Test_C_Mobius_Mark;
  Place* perm_fault_L;
  short* perm_fault_L_Mobius_Mark;
  Place* perm_fault_R;
  short* perm_fault_R_Mobius_Mark;
  Place* perm_fault_C;
  short* perm_fault_C_Mobius_Mark;
  Place* P_error_L;
  short* P_error_L_Mobius_Mark;
  Place* P_error_R;
  short* P_error_R_Mobius_Mark;
  Place* P_error_C;
  short* P_error_C_Mobius_Mark;
  Place* safe_failure;
  short* safe_failure_Mobius_Mark;

  double* TheDistributionParameters;
  cat_rest_rateActivity();
  ~cat_rest_rateActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // cat_rest_rateActivityActivity

class test_execution_rateActivity_case1:public Activity {
public:

  Place* Test_L;
  short* Test_L_Mobius_Mark;
  Place* perm_fault_L;
  short* perm_fault_L_Mobius_Mark;
  Place* catastrophic_failure;
  short* catastrophic_failure_Mobius_Mark;
  Place* safe_failure;
  short* safe_failure_Mobius_Mark;
  Place* Test_R;
  short* Test_R_Mobius_Mark;

  double* TheDistributionParameters;
  test_execution_rateActivity_case1();
  ~test_execution_rateActivity_case1();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // test_execution_rateActivity_case1Activity

class test_execution_rateActivity_case2:public Activity {
public:

  Place* Test_L;
  short* Test_L_Mobius_Mark;
  Place* Test_R;
  short* Test_R_Mobius_Mark;

  double* TheDistributionParameters;
  test_execution_rateActivity_case2();
  ~test_execution_rateActivity_case2();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // test_execution_rateActivity_case2Activity

class safe_restore_rateActivity:public Activity {
public:

  Place* safe_failure;
  short* safe_failure_Mobius_Mark;
  Place* HW;
  short* HW_Mobius_Mark;
  Place* Test_L;
  short* Test_L_Mobius_Mark;
  Place* Test_R;
  short* Test_R_Mobius_Mark;
  Place* Test_C;
  short* Test_C_Mobius_Mark;
  Place* perm_fault_L;
  short* perm_fault_L_Mobius_Mark;
  Place* perm_fault_R;
  short* perm_fault_R_Mobius_Mark;
  Place* perm_fault_C;
  short* perm_fault_C_Mobius_Mark;
  Place* P_error_L;
  short* P_error_L_Mobius_Mark;
  Place* P_error_R;
  short* P_error_R_Mobius_Mark;
  Place* P_error_C;
  short* P_error_C_Mobius_Mark;
  Place* catastrophic_failure;
  short* catastrophic_failure_Mobius_Mark;

  double* TheDistributionParameters;
  safe_restore_rateActivity();
  ~safe_restore_rateActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // safe_restore_rateActivityActivity

class test_execution_rate_RActivity_case1:public Activity {
public:

  Place* Test_R;
  short* Test_R_Mobius_Mark;
  Place* perm_fault_R;
  short* perm_fault_R_Mobius_Mark;
  Place* catastrophic_failure;
  short* catastrophic_failure_Mobius_Mark;
  Place* safe_failure;
  short* safe_failure_Mobius_Mark;
  Place* Test_C;
  short* Test_C_Mobius_Mark;

  double* TheDistributionParameters;
  test_execution_rate_RActivity_case1();
  ~test_execution_rate_RActivity_case1();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // test_execution_rate_RActivity_case1Activity

class test_execution_rate_RActivity_case2:public Activity {
public:

  Place* Test_R;
  short* Test_R_Mobius_Mark;
  Place* Test_C;
  short* Test_C_Mobius_Mark;

  double* TheDistributionParameters;
  test_execution_rate_RActivity_case2();
  ~test_execution_rate_RActivity_case2();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // test_execution_rate_RActivity_case2Activity

class test_execution_rate_CActivity_case1:public Activity {
public:

  Place* Test_C;
  short* Test_C_Mobius_Mark;
  Place* perm_fault_C;
  short* perm_fault_C_Mobius_Mark;
  Place* catastrophic_failure;
  short* catastrophic_failure_Mobius_Mark;
  Place* safe_failure;
  short* safe_failure_Mobius_Mark;
  Place* Test_L;
  short* Test_L_Mobius_Mark;

  double* TheDistributionParameters;
  test_execution_rate_CActivity_case1();
  ~test_execution_rate_CActivity_case1();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // test_execution_rate_CActivity_case1Activity

class test_execution_rate_CActivity_case2:public Activity {
public:

  Place* Test_C;
  short* Test_C_Mobius_Mark;
  Place* Test_L;
  short* Test_L_Mobius_Mark;

  double* TheDistributionParameters;
  test_execution_rate_CActivity_case2();
  ~test_execution_rate_CActivity_case2();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // test_execution_rate_CActivity_case2Activity

  //List of user-specified place names
  Place* HW;
  Place* L;
  Place* R;
  Place* C;
  Place* perm_fault_L;
  Place* perm_fault_R;
  Place* perm_fault_C;
  Place* P_error_L;
  Place* P_error_R;
  Place* P_error_C;
  Place* catastrophic_failure;
  Place* Test_L;
  Place* safe_failure;
  Place* Test_R;
  Place* Test_C;

  // Create instances of all actvities
  fault_rate_LActivity_case1 fault_rate_L_case1;
  fault_rate_LActivity_case2 fault_rate_L_case2;
  fault_rate_RActivity_case1 fault_rate_R_case1;
  fault_rate_RActivity_case2 fault_rate_R_case2;
  fault_rate_CActivity_case1 fault_rate_C_case1;
  fault_rate_CActivity_case2 fault_rate_C_case2;
  fault_occurrence_rateActivity_case1 fault_occurrence_rate_case1;
  fault_occurrence_rateActivity_case2 fault_occurrence_rate_case2;
  fault_occurrence_rateActivity_case3 fault_occurrence_rate_case3;
  fault_activatation_rate_LActivity fault_activatation_rate_L;
  fault_activatation_rate_RActivity fault_activatation_rate_R;
  fault_activatation_rate_CActivity fault_activatation_rate_C;
  error_prop_rate_LActivity error_prop_rate_L;
  error_prop_rate_RActivity error_prop_rate_R;
  error_prop_rate_CActivity error_prop_rate_C;
  cat_rest_rateActivity cat_rest_rate;
  test_execution_rateActivity_case1 test_execution_rate_case1;
  test_execution_rateActivity_case2 test_execution_rate_case2;
  safe_restore_rateActivity safe_restore_rate;
  test_execution_rate_RActivity_case1 test_execution_rate_R_case1;
  test_execution_rate_RActivity_case2 test_execution_rate_R_case2;
  test_execution_rate_CActivity_case1 test_execution_rate_C_case1;
  test_execution_rate_CActivity_case2 test_execution_rate_C_case2;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup fault_rate_LGroup;
  PostselectGroup fault_rate_RGroup;
  PostselectGroup fault_rate_CGroup;
  PostselectGroup fault_occurrence_rateGroup;  PostselectGroup test_execution_rateGroup;  PostselectGroup test_execution_rate_RGroup;  PostselectGroup test_execution_rate_CGroup;
  sanSAN();
  ~sanSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end sanSAN

#endif // sanSAN_H_
