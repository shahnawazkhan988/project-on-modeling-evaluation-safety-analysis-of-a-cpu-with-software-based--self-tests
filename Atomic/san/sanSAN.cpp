

// This C++ file was created by SanEditor

#include "Atomic/san/sanSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         sanSAN Constructor             
******************************************************************/


sanSAN::sanSAN(){


  fault_occurrence_rateGroup.initialize(3, "fault_occurrence_rateGroup");
  fault_occurrence_rateGroup.appendGroup((BaseGroupClass*) &fault_occurrence_rate_case1);
  fault_occurrence_rateGroup.appendGroup((BaseGroupClass*) &fault_occurrence_rate_case2);
  fault_occurrence_rateGroup.appendGroup((BaseGroupClass*) &fault_occurrence_rate_case3);

  test_execution_rateGroup.initialize(2, "test_execution_rateGroup");
  test_execution_rateGroup.appendGroup((BaseGroupClass*) &test_execution_rate_case1);
  test_execution_rateGroup.appendGroup((BaseGroupClass*) &test_execution_rate_case2);

  test_execution_rate_RGroup.initialize(2, "test_execution_rate_RGroup");
  test_execution_rate_RGroup.appendGroup((BaseGroupClass*) &test_execution_rate_R_case1);
  test_execution_rate_RGroup.appendGroup((BaseGroupClass*) &test_execution_rate_R_case2);

  test_execution_rate_CGroup.initialize(2, "test_execution_rate_CGroup");
  test_execution_rate_CGroup.appendGroup((BaseGroupClass*) &test_execution_rate_C_case1);
  test_execution_rate_CGroup.appendGroup((BaseGroupClass*) &test_execution_rate_C_case2);

  fault_rate_LGroup.initialize(2, "fault_rate_LGroup");
  fault_rate_LGroup.appendGroup((BaseGroupClass*) &fault_rate_L_case1);
  fault_rate_LGroup.appendGroup((BaseGroupClass*) &fault_rate_L_case2);

  fault_rate_RGroup.initialize(2, "fault_rate_RGroup");
  fault_rate_RGroup.appendGroup((BaseGroupClass*) &fault_rate_R_case1);
  fault_rate_RGroup.appendGroup((BaseGroupClass*) &fault_rate_R_case2);

  fault_rate_CGroup.initialize(2, "fault_rate_CGroup");
  fault_rate_CGroup.appendGroup((BaseGroupClass*) &fault_rate_C_case1);
  fault_rate_CGroup.appendGroup((BaseGroupClass*) &fault_rate_C_case2);

  Activity* InitialActionList[23]={
    &fault_rate_L_case1, //0
    &fault_rate_L_case2, //1
    &fault_rate_R_case1, //2
    &fault_rate_R_case2, //3
    &fault_rate_C_case1, //4
    &fault_rate_C_case2, //5
    &fault_occurrence_rate_case1, //6
    &fault_occurrence_rate_case2, //7
    &fault_occurrence_rate_case3, //8
    &fault_activatation_rate_L, //9
    &fault_activatation_rate_R, //10
    &fault_activatation_rate_C, //11
    &error_prop_rate_L, //12
    &error_prop_rate_R, //13
    &error_prop_rate_C, //14
    &cat_rest_rate, //15
    &test_execution_rate_case1, //16
    &test_execution_rate_case2, //17
    &safe_restore_rate, //18
    &test_execution_rate_R_case1, //19
    &test_execution_rate_R_case2, //20
    &test_execution_rate_C_case1, //21
    &test_execution_rate_C_case2  // 22
  };

  BaseGroupClass* InitialGroupList[15]={
    (BaseGroupClass*) &(fault_occurrence_rateGroup), 
    (BaseGroupClass*) &(fault_activatation_rate_L), 
    (BaseGroupClass*) &(fault_activatation_rate_R), 
    (BaseGroupClass*) &(fault_activatation_rate_C), 
    (BaseGroupClass*) &(error_prop_rate_L), 
    (BaseGroupClass*) &(error_prop_rate_R), 
    (BaseGroupClass*) &(error_prop_rate_C), 
    (BaseGroupClass*) &(cat_rest_rate), 
    (BaseGroupClass*) &(test_execution_rateGroup), 
    (BaseGroupClass*) &(safe_restore_rate), 
    (BaseGroupClass*) &(test_execution_rate_RGroup), 
    (BaseGroupClass*) &(test_execution_rate_CGroup), 
    (BaseGroupClass*) &(fault_rate_LGroup), 
    (BaseGroupClass*) &(fault_rate_RGroup), 
    (BaseGroupClass*) &(fault_rate_CGroup)
  };

  HW = new Place("HW" ,1);
  L = new Place("L" ,0);
  R = new Place("R" ,0);
  C = new Place("C" ,0);
  perm_fault_L = new Place("perm_fault_L" ,0);
  perm_fault_R = new Place("perm_fault_R" ,0);
  perm_fault_C = new Place("perm_fault_C" ,0);
  P_error_L = new Place("P_error_L" ,0);
  P_error_R = new Place("P_error_R" ,0);
  P_error_C = new Place("P_error_C" ,0);
  catastrophic_failure = new Place("catastrophic_failure" ,0);
  Test_L = new Place("Test_L" ,1);
  safe_failure = new Place("safe_failure" ,0);
  Test_R = new Place("Test_R" ,0);
  Test_C = new Place("Test_C" ,0);
  BaseStateVariableClass* InitialPlaces[15]={
    HW,  // 0
    L,  // 1
    R,  // 2
    C,  // 3
    perm_fault_L,  // 4
    perm_fault_R,  // 5
    perm_fault_C,  // 6
    P_error_L,  // 7
    P_error_R,  // 8
    P_error_C,  // 9
    catastrophic_failure,  // 10
    Test_L,  // 11
    safe_failure,  // 12
    Test_R,  // 13
    Test_C   // 14
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("san", 15, InitialPlaces, 
                        0, InitialROPlaces, 
                        23, InitialActionList, 15, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[75][2]={ 
    {1,0}, {4,0}, {1,1}, {7,1}, {2,2}, {5,2}, {2,3}, {8,3}, {3,4}, 
    {6,4}, {3,5}, {9,5}, {0,6}, {1,6}, {0,7}, {2,7}, {0,8}, {3,8}, 
    {4,9}, {7,9}, {5,10}, {8,10}, {6,11}, {9,11}, {7,12}, {10,12}, 
    {8,13}, {10,13}, {9,14}, {10,14}, {10,15}, {0,15}, {11,15}, 
    {13,15}, {14,15}, {4,15}, {5,15}, {6,15}, {7,15}, {8,15}, 
    {9,15}, {12,15}, {11,16}, {4,16}, {10,16}, {12,16}, {13,16}, 
    {11,17}, {13,17}, {12,18}, {0,18}, {11,18}, {13,18}, {14,18}, 
    {4,18}, {5,18}, {6,18}, {7,18}, {8,18}, {9,18}, {10,18}, 
    {13,19}, {5,19}, {10,19}, {12,19}, {14,19}, {13,20}, {14,20}, 
    {14,21}, {6,21}, {10,21}, {12,21}, {11,21}, {14,22}, {11,22}
  };
  for(int n=0;n<75;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[23][2]={ 
    {1,0}, {1,1}, {2,2}, {2,3}, {3,4}, {3,5}, {0,6}, {0,7}, {0,8}, 
    {4,9}, {5,10}, {6,11}, {7,12}, {8,13}, {9,14}, {10,15}, {11,16}, 
    {11,17}, {12,18}, {13,19}, {13,20}, {14,21}, {14,22}
  };
  for(int n=0;n<23;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<23;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void sanSAN::CustomInitialization() {

}
sanSAN::~sanSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void sanSAN::assignPlacesToActivitiesInst(){
  fault_rate_L_case1.L = (Place*) LocalStateVariables[1];
  fault_rate_L_case1.perm_fault_L = (Place*) LocalStateVariables[4];
  fault_rate_L_case2.L = (Place*) LocalStateVariables[1];
  fault_rate_L_case2.P_error_L = (Place*) LocalStateVariables[7];
  fault_rate_R_case1.R = (Place*) LocalStateVariables[2];
  fault_rate_R_case1.perm_fault_R = (Place*) LocalStateVariables[5];
  fault_rate_R_case2.R = (Place*) LocalStateVariables[2];
  fault_rate_R_case2.P_error_R = (Place*) LocalStateVariables[8];
  fault_rate_C_case1.C = (Place*) LocalStateVariables[3];
  fault_rate_C_case1.perm_fault_C = (Place*) LocalStateVariables[6];
  fault_rate_C_case2.C = (Place*) LocalStateVariables[3];
  fault_rate_C_case2.P_error_C = (Place*) LocalStateVariables[9];
}
void sanSAN::assignPlacesToActivitiesTimed(){
  fault_occurrence_rate_case1.HW = (Place*) LocalStateVariables[0];
  fault_occurrence_rate_case1.L = (Place*) LocalStateVariables[1];
  fault_occurrence_rate_case2.HW = (Place*) LocalStateVariables[0];
  fault_occurrence_rate_case2.R = (Place*) LocalStateVariables[2];
  fault_occurrence_rate_case3.HW = (Place*) LocalStateVariables[0];
  fault_occurrence_rate_case3.C = (Place*) LocalStateVariables[3];
  fault_activatation_rate_L.perm_fault_L = (Place*) LocalStateVariables[4];
  fault_activatation_rate_L.P_error_L = (Place*) LocalStateVariables[7];
  fault_activatation_rate_R.perm_fault_R = (Place*) LocalStateVariables[5];
  fault_activatation_rate_R.P_error_R = (Place*) LocalStateVariables[8];
  fault_activatation_rate_C.perm_fault_C = (Place*) LocalStateVariables[6];
  fault_activatation_rate_C.P_error_C = (Place*) LocalStateVariables[9];
  error_prop_rate_L.P_error_L = (Place*) LocalStateVariables[7];
  error_prop_rate_L.catastrophic_failure = (Place*) LocalStateVariables[10];
  error_prop_rate_R.P_error_R = (Place*) LocalStateVariables[8];
  error_prop_rate_R.catastrophic_failure = (Place*) LocalStateVariables[10];
  error_prop_rate_C.P_error_C = (Place*) LocalStateVariables[9];
  error_prop_rate_C.catastrophic_failure = (Place*) LocalStateVariables[10];
  cat_rest_rate.catastrophic_failure = (Place*) LocalStateVariables[10];
  cat_rest_rate.HW = (Place*) LocalStateVariables[0];
  cat_rest_rate.Test_L = (Place*) LocalStateVariables[11];
  cat_rest_rate.Test_R = (Place*) LocalStateVariables[13];
  cat_rest_rate.Test_C = (Place*) LocalStateVariables[14];
  cat_rest_rate.perm_fault_L = (Place*) LocalStateVariables[4];
  cat_rest_rate.perm_fault_R = (Place*) LocalStateVariables[5];
  cat_rest_rate.perm_fault_C = (Place*) LocalStateVariables[6];
  cat_rest_rate.P_error_L = (Place*) LocalStateVariables[7];
  cat_rest_rate.P_error_R = (Place*) LocalStateVariables[8];
  cat_rest_rate.P_error_C = (Place*) LocalStateVariables[9];
  cat_rest_rate.safe_failure = (Place*) LocalStateVariables[12];
  test_execution_rate_case1.Test_L = (Place*) LocalStateVariables[11];
  test_execution_rate_case1.perm_fault_L = (Place*) LocalStateVariables[4];
  test_execution_rate_case1.catastrophic_failure = (Place*) LocalStateVariables[10];
  test_execution_rate_case1.safe_failure = (Place*) LocalStateVariables[12];
  test_execution_rate_case1.Test_R = (Place*) LocalStateVariables[13];
  test_execution_rate_case2.Test_L = (Place*) LocalStateVariables[11];
  test_execution_rate_case2.Test_R = (Place*) LocalStateVariables[13];
  safe_restore_rate.safe_failure = (Place*) LocalStateVariables[12];
  safe_restore_rate.HW = (Place*) LocalStateVariables[0];
  safe_restore_rate.Test_L = (Place*) LocalStateVariables[11];
  safe_restore_rate.Test_R = (Place*) LocalStateVariables[13];
  safe_restore_rate.Test_C = (Place*) LocalStateVariables[14];
  safe_restore_rate.perm_fault_L = (Place*) LocalStateVariables[4];
  safe_restore_rate.perm_fault_R = (Place*) LocalStateVariables[5];
  safe_restore_rate.perm_fault_C = (Place*) LocalStateVariables[6];
  safe_restore_rate.P_error_L = (Place*) LocalStateVariables[7];
  safe_restore_rate.P_error_R = (Place*) LocalStateVariables[8];
  safe_restore_rate.P_error_C = (Place*) LocalStateVariables[9];
  safe_restore_rate.catastrophic_failure = (Place*) LocalStateVariables[10];
  test_execution_rate_R_case1.Test_R = (Place*) LocalStateVariables[13];
  test_execution_rate_R_case1.perm_fault_R = (Place*) LocalStateVariables[5];
  test_execution_rate_R_case1.catastrophic_failure = (Place*) LocalStateVariables[10];
  test_execution_rate_R_case1.safe_failure = (Place*) LocalStateVariables[12];
  test_execution_rate_R_case1.Test_C = (Place*) LocalStateVariables[14];
  test_execution_rate_R_case2.Test_R = (Place*) LocalStateVariables[13];
  test_execution_rate_R_case2.Test_C = (Place*) LocalStateVariables[14];
  test_execution_rate_C_case1.Test_C = (Place*) LocalStateVariables[14];
  test_execution_rate_C_case1.perm_fault_C = (Place*) LocalStateVariables[6];
  test_execution_rate_C_case1.catastrophic_failure = (Place*) LocalStateVariables[10];
  test_execution_rate_C_case1.safe_failure = (Place*) LocalStateVariables[12];
  test_execution_rate_C_case1.Test_L = (Place*) LocalStateVariables[11];
  test_execution_rate_C_case2.Test_C = (Place*) LocalStateVariables[14];
  test_execution_rate_C_case2.Test_L = (Place*) LocalStateVariables[11];
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================fault_rate_LActivity_case1========================*/


sanSAN::fault_rate_LActivity_case1::fault_rate_LActivity_case1(){
  ActivityInitialize("fault_rate_L_case1",12,Instantaneous , RaceEnabled, 2,1, false);
}

void sanSAN::fault_rate_LActivity_case1::LinkVariables(){
  L->Register(&L_Mobius_Mark);
  perm_fault_L->Register(&perm_fault_L_Mobius_Mark);
}

bool sanSAN::fault_rate_LActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(L_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_rate_LActivity_case1::Weight(){ 
  return pperm_fault_G;
}

bool sanSAN::fault_rate_LActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_rate_LActivity_case1::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_rate_LActivity_case1::SampleDistribution(){
  return 0;
}

double* sanSAN::fault_rate_LActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int sanSAN::fault_rate_LActivity_case1::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_rate_LActivity_case1::Fire(){
  (*(L_Mobius_Mark))--;
  (*(perm_fault_L_Mobius_Mark))++;
  return this;
}

/*======================fault_rate_LActivity_case2========================*/


sanSAN::fault_rate_LActivity_case2::fault_rate_LActivity_case2(){
  ActivityInitialize("fault_rate_L_case2",12,Instantaneous , RaceEnabled, 2,1, false);
}

void sanSAN::fault_rate_LActivity_case2::LinkVariables(){
  L->Register(&L_Mobius_Mark);
  P_error_L->Register(&P_error_L_Mobius_Mark);
}

bool sanSAN::fault_rate_LActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(L_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_rate_LActivity_case2::Weight(){ 
  return 1-pperm_fault_G;
}

bool sanSAN::fault_rate_LActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_rate_LActivity_case2::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_rate_LActivity_case2::SampleDistribution(){
  return 0;
}

double* sanSAN::fault_rate_LActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int sanSAN::fault_rate_LActivity_case2::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_rate_LActivity_case2::Fire(){
  (*(L_Mobius_Mark))--;
  (*(P_error_L_Mobius_Mark))++;
  return this;
}

/*======================fault_rate_RActivity_case1========================*/


sanSAN::fault_rate_RActivity_case1::fault_rate_RActivity_case1(){
  ActivityInitialize("fault_rate_R_case1",13,Instantaneous , RaceEnabled, 2,1, false);
}

void sanSAN::fault_rate_RActivity_case1::LinkVariables(){
  R->Register(&R_Mobius_Mark);
  perm_fault_R->Register(&perm_fault_R_Mobius_Mark);
}

bool sanSAN::fault_rate_RActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(R_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_rate_RActivity_case1::Weight(){ 
  return pperm_fault_G;
}

bool sanSAN::fault_rate_RActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_rate_RActivity_case1::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_rate_RActivity_case1::SampleDistribution(){
  return 0;
}

double* sanSAN::fault_rate_RActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int sanSAN::fault_rate_RActivity_case1::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_rate_RActivity_case1::Fire(){
  (*(R_Mobius_Mark))--;
  (*(perm_fault_R_Mobius_Mark))++;
  return this;
}

/*======================fault_rate_RActivity_case2========================*/


sanSAN::fault_rate_RActivity_case2::fault_rate_RActivity_case2(){
  ActivityInitialize("fault_rate_R_case2",13,Instantaneous , RaceEnabled, 2,1, false);
}

void sanSAN::fault_rate_RActivity_case2::LinkVariables(){
  R->Register(&R_Mobius_Mark);
  P_error_R->Register(&P_error_R_Mobius_Mark);
}

bool sanSAN::fault_rate_RActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(R_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_rate_RActivity_case2::Weight(){ 
  return 1-pperm_fault_G;
}

bool sanSAN::fault_rate_RActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_rate_RActivity_case2::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_rate_RActivity_case2::SampleDistribution(){
  return 0;
}

double* sanSAN::fault_rate_RActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int sanSAN::fault_rate_RActivity_case2::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_rate_RActivity_case2::Fire(){
  (*(R_Mobius_Mark))--;
  (*(P_error_R_Mobius_Mark))++;
  return this;
}

/*======================fault_rate_CActivity_case1========================*/


sanSAN::fault_rate_CActivity_case1::fault_rate_CActivity_case1(){
  ActivityInitialize("fault_rate_C_case1",14,Instantaneous , RaceEnabled, 2,1, false);
}

void sanSAN::fault_rate_CActivity_case1::LinkVariables(){
  C->Register(&C_Mobius_Mark);
  perm_fault_C->Register(&perm_fault_C_Mobius_Mark);
}

bool sanSAN::fault_rate_CActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(C_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_rate_CActivity_case1::Weight(){ 
  return pperm_fault_G;
}

bool sanSAN::fault_rate_CActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_rate_CActivity_case1::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_rate_CActivity_case1::SampleDistribution(){
  return 0;
}

double* sanSAN::fault_rate_CActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int sanSAN::fault_rate_CActivity_case1::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_rate_CActivity_case1::Fire(){
  (*(C_Mobius_Mark))--;
  (*(perm_fault_C_Mobius_Mark))++;
  return this;
}

/*======================fault_rate_CActivity_case2========================*/


sanSAN::fault_rate_CActivity_case2::fault_rate_CActivity_case2(){
  ActivityInitialize("fault_rate_C_case2",14,Instantaneous , RaceEnabled, 2,1, false);
}

void sanSAN::fault_rate_CActivity_case2::LinkVariables(){
  C->Register(&C_Mobius_Mark);
  P_error_C->Register(&P_error_C_Mobius_Mark);
}

bool sanSAN::fault_rate_CActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(C_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_rate_CActivity_case2::Weight(){ 
  return 1-pperm_fault_G;
}

bool sanSAN::fault_rate_CActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_rate_CActivity_case2::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_rate_CActivity_case2::SampleDistribution(){
  return 0;
}

double* sanSAN::fault_rate_CActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int sanSAN::fault_rate_CActivity_case2::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_rate_CActivity_case2::Fire(){
  (*(C_Mobius_Mark))--;
  (*(P_error_C_Mobius_Mark))++;
  return this;
}

/*======================fault_occurrence_rateActivity_case1========================*/

sanSAN::fault_occurrence_rateActivity_case1::fault_occurrence_rateActivity_case1(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("fault_occurrence_rate_case1",0,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::fault_occurrence_rateActivity_case1::~fault_occurrence_rateActivity_case1(){
  delete[] TheDistributionParameters;
}

void sanSAN::fault_occurrence_rateActivity_case1::LinkVariables(){
  HW->Register(&HW_Mobius_Mark);
  L->Register(&L_Mobius_Mark);
}

bool sanSAN::fault_occurrence_rateActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(HW_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_occurrence_rateActivity_case1::Rate(){
  return (double)1/1000000 *HW->Mark();
  return 1.0;  // default rate if none is specified
}

double sanSAN::fault_occurrence_rateActivity_case1::Weight(){ 
  return 0.34;
}

bool sanSAN::fault_occurrence_rateActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_occurrence_rateActivity_case1::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_occurrence_rateActivity_case1::SampleDistribution(){
  return TheDistribution->Exponential((double)1/1000000 *HW->Mark());
}

double* sanSAN::fault_occurrence_rateActivity_case1::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::fault_occurrence_rateActivity_case1::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_occurrence_rateActivity_case1::Fire(){
  (*(HW_Mobius_Mark))--;
  (*(L_Mobius_Mark))++;
  return this;
}

/*======================fault_occurrence_rateActivity_case2========================*/

sanSAN::fault_occurrence_rateActivity_case2::fault_occurrence_rateActivity_case2(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("fault_occurrence_rate_case2",0,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::fault_occurrence_rateActivity_case2::~fault_occurrence_rateActivity_case2(){
  delete[] TheDistributionParameters;
}

void sanSAN::fault_occurrence_rateActivity_case2::LinkVariables(){
  HW->Register(&HW_Mobius_Mark);
  R->Register(&R_Mobius_Mark);
}

bool sanSAN::fault_occurrence_rateActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(HW_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_occurrence_rateActivity_case2::Rate(){
  return (double)1/1000000 *HW->Mark();
  return 1.0;  // default rate if none is specified
}

double sanSAN::fault_occurrence_rateActivity_case2::Weight(){ 
  return 0.33;
}

bool sanSAN::fault_occurrence_rateActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_occurrence_rateActivity_case2::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_occurrence_rateActivity_case2::SampleDistribution(){
  return TheDistribution->Exponential((double)1/1000000 *HW->Mark());
}

double* sanSAN::fault_occurrence_rateActivity_case2::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::fault_occurrence_rateActivity_case2::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_occurrence_rateActivity_case2::Fire(){
  (*(HW_Mobius_Mark))--;
  (*(R_Mobius_Mark))++;
  return this;
}

/*======================fault_occurrence_rateActivity_case3========================*/

sanSAN::fault_occurrence_rateActivity_case3::fault_occurrence_rateActivity_case3(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("fault_occurrence_rate_case3",0,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::fault_occurrence_rateActivity_case3::~fault_occurrence_rateActivity_case3(){
  delete[] TheDistributionParameters;
}

void sanSAN::fault_occurrence_rateActivity_case3::LinkVariables(){
  HW->Register(&HW_Mobius_Mark);
  C->Register(&C_Mobius_Mark);
}

bool sanSAN::fault_occurrence_rateActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(HW_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_occurrence_rateActivity_case3::Rate(){
  return (double)1/1000000 *HW->Mark();
  return 1.0;  // default rate if none is specified
}

double sanSAN::fault_occurrence_rateActivity_case3::Weight(){ 
  return 0.33;
}

bool sanSAN::fault_occurrence_rateActivity_case3::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_occurrence_rateActivity_case3::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_occurrence_rateActivity_case3::SampleDistribution(){
  return TheDistribution->Exponential((double)1/1000000 *HW->Mark());
}

double* sanSAN::fault_occurrence_rateActivity_case3::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::fault_occurrence_rateActivity_case3::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_occurrence_rateActivity_case3::Fire(){
  (*(HW_Mobius_Mark))--;
  (*(C_Mobius_Mark))++;
  return this;
}

/*======================fault_activatation_rate_LActivity========================*/

sanSAN::fault_activatation_rate_LActivity::fault_activatation_rate_LActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("fault_activatation_rate_L",1,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::fault_activatation_rate_LActivity::~fault_activatation_rate_LActivity(){
  delete[] TheDistributionParameters;
}

void sanSAN::fault_activatation_rate_LActivity::LinkVariables(){
  perm_fault_L->Register(&perm_fault_L_Mobius_Mark);
  P_error_L->Register(&P_error_L_Mobius_Mark);
}

bool sanSAN::fault_activatation_rate_LActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(perm_fault_L_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_activatation_rate_LActivity::Rate(){
  return (double) 3600 * perm_fault_L->Mark();
  return 1.0;  // default rate if none is specified
}

double sanSAN::fault_activatation_rate_LActivity::Weight(){ 
  return 1;
}

bool sanSAN::fault_activatation_rate_LActivity::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_activatation_rate_LActivity::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_activatation_rate_LActivity::SampleDistribution(){
  return TheDistribution->Exponential((double) 3600 * perm_fault_L->Mark());
}

double* sanSAN::fault_activatation_rate_LActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::fault_activatation_rate_LActivity::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_activatation_rate_LActivity::Fire(){
  (*(perm_fault_L_Mobius_Mark))--;
  (*(P_error_L_Mobius_Mark))++;
  return this;
}

/*======================fault_activatation_rate_RActivity========================*/

sanSAN::fault_activatation_rate_RActivity::fault_activatation_rate_RActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("fault_activatation_rate_R",2,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::fault_activatation_rate_RActivity::~fault_activatation_rate_RActivity(){
  delete[] TheDistributionParameters;
}

void sanSAN::fault_activatation_rate_RActivity::LinkVariables(){
  perm_fault_R->Register(&perm_fault_R_Mobius_Mark);
  P_error_R->Register(&P_error_R_Mobius_Mark);
}

bool sanSAN::fault_activatation_rate_RActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(perm_fault_R_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_activatation_rate_RActivity::Rate(){
  return (double) 3600 * perm_fault_R->Mark();
  return 1.0;  // default rate if none is specified
}

double sanSAN::fault_activatation_rate_RActivity::Weight(){ 
  return 1;
}

bool sanSAN::fault_activatation_rate_RActivity::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_activatation_rate_RActivity::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_activatation_rate_RActivity::SampleDistribution(){
  return TheDistribution->Exponential((double) 3600 * perm_fault_R->Mark());
}

double* sanSAN::fault_activatation_rate_RActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::fault_activatation_rate_RActivity::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_activatation_rate_RActivity::Fire(){
  (*(perm_fault_R_Mobius_Mark))--;
  (*(P_error_R_Mobius_Mark))++;
  return this;
}

/*======================fault_activatation_rate_CActivity========================*/

sanSAN::fault_activatation_rate_CActivity::fault_activatation_rate_CActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("fault_activatation_rate_C",3,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::fault_activatation_rate_CActivity::~fault_activatation_rate_CActivity(){
  delete[] TheDistributionParameters;
}

void sanSAN::fault_activatation_rate_CActivity::LinkVariables(){
  perm_fault_C->Register(&perm_fault_C_Mobius_Mark);
  P_error_C->Register(&P_error_C_Mobius_Mark);
}

bool sanSAN::fault_activatation_rate_CActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(perm_fault_C_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::fault_activatation_rate_CActivity::Rate(){
  return (double) 3600 * perm_fault_C->Mark();
  return 1.0;  // default rate if none is specified
}

double sanSAN::fault_activatation_rate_CActivity::Weight(){ 
  return 1;
}

bool sanSAN::fault_activatation_rate_CActivity::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::fault_activatation_rate_CActivity::ReactivationFunction(){ 
  return false;
}

double sanSAN::fault_activatation_rate_CActivity::SampleDistribution(){
  return TheDistribution->Exponential((double) 3600 * perm_fault_C->Mark());
}

double* sanSAN::fault_activatation_rate_CActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::fault_activatation_rate_CActivity::Rank(){
  return 1;
}

BaseActionClass* sanSAN::fault_activatation_rate_CActivity::Fire(){
  (*(perm_fault_C_Mobius_Mark))--;
  (*(P_error_C_Mobius_Mark))++;
  return this;
}

/*======================error_prop_rate_LActivity========================*/

sanSAN::error_prop_rate_LActivity::error_prop_rate_LActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("error_prop_rate_L",4,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::error_prop_rate_LActivity::~error_prop_rate_LActivity(){
  delete[] TheDistributionParameters;
}

void sanSAN::error_prop_rate_LActivity::LinkVariables(){
  P_error_L->Register(&P_error_L_Mobius_Mark);
  catastrophic_failure->Register(&catastrophic_failure_Mobius_Mark);
}

bool sanSAN::error_prop_rate_LActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(P_error_L_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::error_prop_rate_LActivity::Rate(){
  return 3600;
  return 1.0;  // default rate if none is specified
}

double sanSAN::error_prop_rate_LActivity::Weight(){ 
  return 1;
}

bool sanSAN::error_prop_rate_LActivity::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::error_prop_rate_LActivity::ReactivationFunction(){ 
  return false;
}

double sanSAN::error_prop_rate_LActivity::SampleDistribution(){
  return TheDistribution->Exponential(3600);
}

double* sanSAN::error_prop_rate_LActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::error_prop_rate_LActivity::Rank(){
  return 1;
}

BaseActionClass* sanSAN::error_prop_rate_LActivity::Fire(){
  (*(P_error_L_Mobius_Mark))--;
  (*(catastrophic_failure_Mobius_Mark))++;
  return this;
}

/*======================error_prop_rate_RActivity========================*/

sanSAN::error_prop_rate_RActivity::error_prop_rate_RActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("error_prop_rate_R",5,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::error_prop_rate_RActivity::~error_prop_rate_RActivity(){
  delete[] TheDistributionParameters;
}

void sanSAN::error_prop_rate_RActivity::LinkVariables(){
  P_error_R->Register(&P_error_R_Mobius_Mark);
  catastrophic_failure->Register(&catastrophic_failure_Mobius_Mark);
}

bool sanSAN::error_prop_rate_RActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(P_error_R_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::error_prop_rate_RActivity::Rate(){
  return 360;
  return 1.0;  // default rate if none is specified
}

double sanSAN::error_prop_rate_RActivity::Weight(){ 
  return 1;
}

bool sanSAN::error_prop_rate_RActivity::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::error_prop_rate_RActivity::ReactivationFunction(){ 
  return false;
}

double sanSAN::error_prop_rate_RActivity::SampleDistribution(){
  return TheDistribution->Exponential(360);
}

double* sanSAN::error_prop_rate_RActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::error_prop_rate_RActivity::Rank(){
  return 1;
}

BaseActionClass* sanSAN::error_prop_rate_RActivity::Fire(){
  (*(P_error_R_Mobius_Mark))--;
  (*(catastrophic_failure_Mobius_Mark))++;
  return this;
}

/*======================error_prop_rate_CActivity========================*/

sanSAN::error_prop_rate_CActivity::error_prop_rate_CActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("error_prop_rate_C",6,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::error_prop_rate_CActivity::~error_prop_rate_CActivity(){
  delete[] TheDistributionParameters;
}

void sanSAN::error_prop_rate_CActivity::LinkVariables(){
  P_error_C->Register(&P_error_C_Mobius_Mark);
  catastrophic_failure->Register(&catastrophic_failure_Mobius_Mark);
}

bool sanSAN::error_prop_rate_CActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(P_error_C_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::error_prop_rate_CActivity::Rate(){
  return 36;
  return 1.0;  // default rate if none is specified
}

double sanSAN::error_prop_rate_CActivity::Weight(){ 
  return 1;
}

bool sanSAN::error_prop_rate_CActivity::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::error_prop_rate_CActivity::ReactivationFunction(){ 
  return false;
}

double sanSAN::error_prop_rate_CActivity::SampleDistribution(){
  return TheDistribution->Exponential(36);
}

double* sanSAN::error_prop_rate_CActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::error_prop_rate_CActivity::Rank(){
  return 1;
}

BaseActionClass* sanSAN::error_prop_rate_CActivity::Fire(){
  (*(P_error_C_Mobius_Mark))--;
  (*(catastrophic_failure_Mobius_Mark))++;
  return this;
}

/*======================cat_rest_rateActivity========================*/

sanSAN::cat_rest_rateActivity::cat_rest_rateActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("cat_rest_rate",7,Exponential, RaceEnabled, 12,1, false);
}

sanSAN::cat_rest_rateActivity::~cat_rest_rateActivity(){
  delete[] TheDistributionParameters;
}

void sanSAN::cat_rest_rateActivity::LinkVariables(){
  catastrophic_failure->Register(&catastrophic_failure_Mobius_Mark);
  HW->Register(&HW_Mobius_Mark);
  Test_L->Register(&Test_L_Mobius_Mark);
  Test_R->Register(&Test_R_Mobius_Mark);
  Test_C->Register(&Test_C_Mobius_Mark);
  perm_fault_L->Register(&perm_fault_L_Mobius_Mark);
  perm_fault_R->Register(&perm_fault_R_Mobius_Mark);
  perm_fault_C->Register(&perm_fault_C_Mobius_Mark);
  P_error_L->Register(&P_error_L_Mobius_Mark);
  P_error_R->Register(&P_error_R_Mobius_Mark);
  P_error_C->Register(&P_error_C_Mobius_Mark);
  safe_failure->Register(&safe_failure_Mobius_Mark);
}

bool sanSAN::cat_rest_rateActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(catastrophic_failure_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::cat_rest_rateActivity::Rate(){
  return (double) 100 * safe_restore_rate_G;
  return 1.0;  // default rate if none is specified
}

double sanSAN::cat_rest_rateActivity::Weight(){ 
  return 1;
}

bool sanSAN::cat_rest_rateActivity::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::cat_rest_rateActivity::ReactivationFunction(){ 
  return false;
}

double sanSAN::cat_rest_rateActivity::SampleDistribution(){
  return TheDistribution->Exponential((double) 100 * safe_restore_rate_G);
}

double* sanSAN::cat_rest_rateActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::cat_rest_rateActivity::Rank(){
  return 1;
}

BaseActionClass* sanSAN::cat_rest_rateActivity::Fire(){
  (*(catastrophic_failure_Mobius_Mark))--;
  HW->Mark()=1;
Test_L->Mark()=1;
Test_R->Mark()=0;
Test_C->Mark()=0;
perm_fault_L->Mark()=0;
perm_fault_R->Mark()=0;
perm_fault_C->Mark()=0;
P_error_L->Mark()=0;
P_error_R->Mark()=0;
P_error_C->Mark()=0;
safe_failure->Mark()=0;
catastrophic_failure->Mark()=0;
  return this;
}

/*======================test_execution_rateActivity_case1========================*/

sanSAN::test_execution_rateActivity_case1::test_execution_rateActivity_case1(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("test_execution_rate_case1",8,Exponential, RaceEnabled, 5,1, false);
}

sanSAN::test_execution_rateActivity_case1::~test_execution_rateActivity_case1(){
  delete[] TheDistributionParameters;
}

void sanSAN::test_execution_rateActivity_case1::LinkVariables(){
  Test_L->Register(&Test_L_Mobius_Mark);
  perm_fault_L->Register(&perm_fault_L_Mobius_Mark);
  catastrophic_failure->Register(&catastrophic_failure_Mobius_Mark);
  safe_failure->Register(&safe_failure_Mobius_Mark);
  Test_R->Register(&Test_R_Mobius_Mark);
}

bool sanSAN::test_execution_rateActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(Test_L_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::test_execution_rateActivity_case1::Rate(){
  return test_execution_rate_G;
  return 1.0;  // default rate if none is specified
}

double sanSAN::test_execution_rateActivity_case1::Weight(){ 
  return 0.7;
}

bool sanSAN::test_execution_rateActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::test_execution_rateActivity_case1::ReactivationFunction(){ 
  return false;
}

double sanSAN::test_execution_rateActivity_case1::SampleDistribution(){
  return TheDistribution->Exponential(test_execution_rate_G);
}

double* sanSAN::test_execution_rateActivity_case1::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::test_execution_rateActivity_case1::Rank(){
  return 1;
}

BaseActionClass* sanSAN::test_execution_rateActivity_case1::Fire(){
  (*(Test_L_Mobius_Mark))--;
  if (perm_fault_L->Mark() > 0 && catastrophic_failure->Mark() == 0 )
{
	safe_failure->Mark()++;
	perm_fault_L->Mark() = 0;
}
else
{
	Test_R->Mark()++;
}   
  return this;
}

/*======================test_execution_rateActivity_case2========================*/

sanSAN::test_execution_rateActivity_case2::test_execution_rateActivity_case2(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("test_execution_rate_case2",8,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::test_execution_rateActivity_case2::~test_execution_rateActivity_case2(){
  delete[] TheDistributionParameters;
}

void sanSAN::test_execution_rateActivity_case2::LinkVariables(){
  Test_L->Register(&Test_L_Mobius_Mark);
  Test_R->Register(&Test_R_Mobius_Mark);
}

bool sanSAN::test_execution_rateActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(Test_L_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::test_execution_rateActivity_case2::Rate(){
  return test_execution_rate_G;
  return 1.0;  // default rate if none is specified
}

double sanSAN::test_execution_rateActivity_case2::Weight(){ 
  return 0.3;
}

bool sanSAN::test_execution_rateActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::test_execution_rateActivity_case2::ReactivationFunction(){ 
  return false;
}

double sanSAN::test_execution_rateActivity_case2::SampleDistribution(){
  return TheDistribution->Exponential(test_execution_rate_G);
}

double* sanSAN::test_execution_rateActivity_case2::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::test_execution_rateActivity_case2::Rank(){
  return 1;
}

BaseActionClass* sanSAN::test_execution_rateActivity_case2::Fire(){
  (*(Test_L_Mobius_Mark))--;
  (*(Test_R_Mobius_Mark))++;
  return this;
}

/*======================safe_restore_rateActivity========================*/

sanSAN::safe_restore_rateActivity::safe_restore_rateActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("safe_restore_rate",9,Exponential, RaceEnabled, 12,1, false);
}

sanSAN::safe_restore_rateActivity::~safe_restore_rateActivity(){
  delete[] TheDistributionParameters;
}

void sanSAN::safe_restore_rateActivity::LinkVariables(){
  safe_failure->Register(&safe_failure_Mobius_Mark);
  HW->Register(&HW_Mobius_Mark);
  Test_L->Register(&Test_L_Mobius_Mark);
  Test_R->Register(&Test_R_Mobius_Mark);
  Test_C->Register(&Test_C_Mobius_Mark);
  perm_fault_L->Register(&perm_fault_L_Mobius_Mark);
  perm_fault_R->Register(&perm_fault_R_Mobius_Mark);
  perm_fault_C->Register(&perm_fault_C_Mobius_Mark);
  P_error_L->Register(&P_error_L_Mobius_Mark);
  P_error_R->Register(&P_error_R_Mobius_Mark);
  P_error_C->Register(&P_error_C_Mobius_Mark);
  catastrophic_failure->Register(&catastrophic_failure_Mobius_Mark);
}

bool sanSAN::safe_restore_rateActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(safe_failure_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::safe_restore_rateActivity::Rate(){
  return safe_restore_rate_G;
  return 1.0;  // default rate if none is specified
}

double sanSAN::safe_restore_rateActivity::Weight(){ 
  return 1;
}

bool sanSAN::safe_restore_rateActivity::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::safe_restore_rateActivity::ReactivationFunction(){ 
  return false;
}

double sanSAN::safe_restore_rateActivity::SampleDistribution(){
  return TheDistribution->Exponential(safe_restore_rate_G);
}

double* sanSAN::safe_restore_rateActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::safe_restore_rateActivity::Rank(){
  return 1;
}

BaseActionClass* sanSAN::safe_restore_rateActivity::Fire(){
  (*(safe_failure_Mobius_Mark))--;
  HW->Mark()=1;
Test_L->Mark()=1;
Test_R->Mark()=0;
Test_C->Mark()=0;
perm_fault_L->Mark()=0;
perm_fault_R->Mark()=0;
perm_fault_C->Mark()=0;
P_error_L->Mark()=0;
P_error_R->Mark()=0;
P_error_C->Mark()=0;
safe_failure->Mark()=0;
catastrophic_failure->Mark()=0;
  return this;
}

/*======================test_execution_rate_RActivity_case1========================*/

sanSAN::test_execution_rate_RActivity_case1::test_execution_rate_RActivity_case1(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("test_execution_rate_R_case1",10,Exponential, RaceEnabled, 5,1, false);
}

sanSAN::test_execution_rate_RActivity_case1::~test_execution_rate_RActivity_case1(){
  delete[] TheDistributionParameters;
}

void sanSAN::test_execution_rate_RActivity_case1::LinkVariables(){
  Test_R->Register(&Test_R_Mobius_Mark);
  perm_fault_R->Register(&perm_fault_R_Mobius_Mark);
  catastrophic_failure->Register(&catastrophic_failure_Mobius_Mark);
  safe_failure->Register(&safe_failure_Mobius_Mark);
  Test_C->Register(&Test_C_Mobius_Mark);
}

bool sanSAN::test_execution_rate_RActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(Test_R_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::test_execution_rate_RActivity_case1::Rate(){
  return test_execution_rate_G;
  return 1.0;  // default rate if none is specified
}

double sanSAN::test_execution_rate_RActivity_case1::Weight(){ 
  return 0.7;
}

bool sanSAN::test_execution_rate_RActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::test_execution_rate_RActivity_case1::ReactivationFunction(){ 
  return false;
}

double sanSAN::test_execution_rate_RActivity_case1::SampleDistribution(){
  return TheDistribution->Exponential(test_execution_rate_G);
}

double* sanSAN::test_execution_rate_RActivity_case1::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::test_execution_rate_RActivity_case1::Rank(){
  return 1;
}

BaseActionClass* sanSAN::test_execution_rate_RActivity_case1::Fire(){
  (*(Test_R_Mobius_Mark))--;
  if (perm_fault_R->Mark() > 0 && catastrophic_failure->Mark() == 0 )
{
	safe_failure->Mark()++;
	perm_fault_R->Mark() = 0;
}
else
{
	Test_C->Mark()++;
}   
  return this;
}

/*======================test_execution_rate_RActivity_case2========================*/

sanSAN::test_execution_rate_RActivity_case2::test_execution_rate_RActivity_case2(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("test_execution_rate_R_case2",10,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::test_execution_rate_RActivity_case2::~test_execution_rate_RActivity_case2(){
  delete[] TheDistributionParameters;
}

void sanSAN::test_execution_rate_RActivity_case2::LinkVariables(){
  Test_R->Register(&Test_R_Mobius_Mark);
  Test_C->Register(&Test_C_Mobius_Mark);
}

bool sanSAN::test_execution_rate_RActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(Test_R_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::test_execution_rate_RActivity_case2::Rate(){
  return test_execution_rate_G;
  return 1.0;  // default rate if none is specified
}

double sanSAN::test_execution_rate_RActivity_case2::Weight(){ 
  return 0.3;
}

bool sanSAN::test_execution_rate_RActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::test_execution_rate_RActivity_case2::ReactivationFunction(){ 
  return false;
}

double sanSAN::test_execution_rate_RActivity_case2::SampleDistribution(){
  return TheDistribution->Exponential(test_execution_rate_G);
}

double* sanSAN::test_execution_rate_RActivity_case2::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::test_execution_rate_RActivity_case2::Rank(){
  return 1;
}

BaseActionClass* sanSAN::test_execution_rate_RActivity_case2::Fire(){
  (*(Test_R_Mobius_Mark))--;
  (*(Test_C_Mobius_Mark))++;
  return this;
}

/*======================test_execution_rate_CActivity_case1========================*/

sanSAN::test_execution_rate_CActivity_case1::test_execution_rate_CActivity_case1(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("test_execution_rate_C_case1",11,Exponential, RaceEnabled, 5,1, false);
}

sanSAN::test_execution_rate_CActivity_case1::~test_execution_rate_CActivity_case1(){
  delete[] TheDistributionParameters;
}

void sanSAN::test_execution_rate_CActivity_case1::LinkVariables(){
  Test_C->Register(&Test_C_Mobius_Mark);
  perm_fault_C->Register(&perm_fault_C_Mobius_Mark);
  catastrophic_failure->Register(&catastrophic_failure_Mobius_Mark);
  safe_failure->Register(&safe_failure_Mobius_Mark);
  Test_L->Register(&Test_L_Mobius_Mark);
}

bool sanSAN::test_execution_rate_CActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(Test_C_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::test_execution_rate_CActivity_case1::Rate(){
  return test_execution_rate_G;
  return 1.0;  // default rate if none is specified
}

double sanSAN::test_execution_rate_CActivity_case1::Weight(){ 
  return 0.7;
}

bool sanSAN::test_execution_rate_CActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::test_execution_rate_CActivity_case1::ReactivationFunction(){ 
  return false;
}

double sanSAN::test_execution_rate_CActivity_case1::SampleDistribution(){
  return TheDistribution->Exponential(test_execution_rate_G);
}

double* sanSAN::test_execution_rate_CActivity_case1::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::test_execution_rate_CActivity_case1::Rank(){
  return 1;
}

BaseActionClass* sanSAN::test_execution_rate_CActivity_case1::Fire(){
  (*(Test_C_Mobius_Mark))--;
  if (perm_fault_C->Mark() > 0 && catastrophic_failure->Mark() == 0 )
{
	safe_failure->Mark()++;
	perm_fault_C->Mark() = 0;
}
else
{
	Test_L->Mark()++;
}   

  return this;
}

/*======================test_execution_rate_CActivity_case2========================*/

sanSAN::test_execution_rate_CActivity_case2::test_execution_rate_CActivity_case2(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("test_execution_rate_C_case2",11,Exponential, RaceEnabled, 2,1, false);
}

sanSAN::test_execution_rate_CActivity_case2::~test_execution_rate_CActivity_case2(){
  delete[] TheDistributionParameters;
}

void sanSAN::test_execution_rate_CActivity_case2::LinkVariables(){
  Test_C->Register(&Test_C_Mobius_Mark);
  Test_L->Register(&Test_L_Mobius_Mark);
}

bool sanSAN::test_execution_rate_CActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(Test_C_Mobius_Mark)) >=1));
  return NewEnabled;
}

double sanSAN::test_execution_rate_CActivity_case2::Rate(){
  return test_execution_rate_G;
  return 1.0;  // default rate if none is specified
}

double sanSAN::test_execution_rate_CActivity_case2::Weight(){ 
  return 0.3;
}

bool sanSAN::test_execution_rate_CActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool sanSAN::test_execution_rate_CActivity_case2::ReactivationFunction(){ 
  return false;
}

double sanSAN::test_execution_rate_CActivity_case2::SampleDistribution(){
  return TheDistribution->Exponential(test_execution_rate_G);
}

double* sanSAN::test_execution_rate_CActivity_case2::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int sanSAN::test_execution_rate_CActivity_case2::Rank(){
  return 1;
}

BaseActionClass* sanSAN::test_execution_rate_CActivity_case2::Fire(){
  (*(Test_C_Mobius_Mark))--;
  (*(Test_L_Mobius_Mark))++;
  return this;
}

