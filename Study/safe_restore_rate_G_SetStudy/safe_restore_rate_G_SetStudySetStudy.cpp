
#include "Study/safe_restore_rate_G_SetStudy/safe_restore_rate_G_SetStudySetStudy.h"

//******************************************************
//Global Variables
//******************************************************
Double pperm_fault_G;
Double safe_restore_rate_G;
Double test_execution_rate_G;

//********************************************************
//safe_restore_rate_G_SetStudySetStudy Constructor
//********************************************************
safe_restore_rate_G_SetStudySetStudy::safe_restore_rate_G_SetStudySetStudy() {

  // define arrays of global variable names and types
  NumGVs = 3;
  NumExps = 10;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("pperm_fault_G");
  GVTypes[0]=strdup("double");
  GVNames[1]=strdup("safe_restore_rate_G");
  GVTypes[1]=strdup("double");
  GVNames[2]=strdup("test_execution_rate_G");
  GVTypes[2]=strdup("double");

  // create the arrays to store the values of each gv
  pperm_fault_GValues = new double[NumExps];
  safe_restore_rate_GValues = new double[NumExps];
  test_execution_rate_GValues = new double[NumExps];

  // call methods to assign values to each gv
  SetValues_pperm_fault_G();
  SetValues_safe_restore_rate_G();
  SetValues_test_execution_rate_G();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//safe_restore_rate_G_SetStudySetStudy Destructor
//******************************************************
safe_restore_rate_G_SetStudySetStudy::~safe_restore_rate_G_SetStudySetStudy() {
  delete [] pperm_fault_GValues;
  delete [] safe_restore_rate_GValues;
  delete [] test_execution_rate_GValues;
  delete ThePVModel;
}


//******************************************************
// set values for pperm_fault_G
//******************************************************
void safe_restore_rate_G_SetStudySetStudy::SetValues_pperm_fault_G() {
  pperm_fault_GValues[0] = 0.1;
  pperm_fault_GValues[1] = 0.1;
  pperm_fault_GValues[2] = 0.1;
  pperm_fault_GValues[3] = 0.1;
  pperm_fault_GValues[4] = 0.1;
  pperm_fault_GValues[5] = 0.1;
  pperm_fault_GValues[6] = 0.1;
  pperm_fault_GValues[7] = 0.1;
  pperm_fault_GValues[8] = 0.1;
  pperm_fault_GValues[9] = 0.1;
}


//******************************************************
// set values for safe_restore_rate_G
//******************************************************
void safe_restore_rate_G_SetStudySetStudy::SetValues_safe_restore_rate_G() {
  safe_restore_rate_GValues[0] = 10.0;
  safe_restore_rate_GValues[1] = 100.0;
  safe_restore_rate_GValues[2] = 20.0;
  safe_restore_rate_GValues[3] = 30.0;
  safe_restore_rate_GValues[4] = 40.0;
  safe_restore_rate_GValues[5] = 50.0;
  safe_restore_rate_GValues[6] = 60.0;
  safe_restore_rate_GValues[7] = 70.0;
  safe_restore_rate_GValues[8] = 80.0;
  safe_restore_rate_GValues[9] = 90.0;
}


//******************************************************
// set values for test_execution_rate_G
//******************************************************
void safe_restore_rate_G_SetStudySetStudy::SetValues_test_execution_rate_G() {
  test_execution_rate_GValues[0] = 1000.0;
  test_execution_rate_GValues[1] = 1000.0;
  test_execution_rate_GValues[2] = 1000.0;
  test_execution_rate_GValues[3] = 1000.0;
  test_execution_rate_GValues[4] = 1000.0;
  test_execution_rate_GValues[5] = 1000.0;
  test_execution_rate_GValues[6] = 1000.0;
  test_execution_rate_GValues[7] = 1000.0;
  test_execution_rate_GValues[8] = 1000.0;
  test_execution_rate_GValues[9] = 1000.0;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void safe_restore_rate_G_SetStudySetStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
  cout << "pperm_fault_G\tdouble\t" << pperm_fault_G << endl;
  cout << "safe_restore_rate_G\tdouble\t" << safe_restore_rate_G << endl;
  cout << "test_execution_rate_G\tdouble\t" << test_execution_rate_G << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *safe_restore_rate_G_SetStudySetStudy::GetGVValue(char *TheGVName) {
  if (strcmp("pperm_fault_G", TheGVName) == 0)
    return &pperm_fault_G;
  else if (strcmp("safe_restore_rate_G", TheGVName) == 0)
    return &safe_restore_rate_G;
  else if (strcmp("test_execution_rate_G", TheGVName) == 0)
    return &test_execution_rate_G;
  else 
    cerr<<"!! safe_restore_rate_G_SetStudySetStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void safe_restore_rate_G_SetStudySetStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("pperm_fault_G", TheGVName) == 0)
    SetGvValue(pperm_fault_G, *(double *)TheGVValue);
  else if (strcmp("safe_restore_rate_G", TheGVName) == 0)
    SetGvValue(safe_restore_rate_G, *(double *)TheGVValue);
  else if (strcmp("test_execution_rate_G", TheGVName) == 0)
    SetGvValue(test_execution_rate_G, *(double *)TheGVValue);
  else 
    cerr<<"!! safe_restore_rate_G_SetStudySetStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void safe_restore_rate_G_SetStudySetStudy::SetGVs(int expNum) {
  SetGvValue(pperm_fault_G, pperm_fault_GValues[expNum]);
  SetGvValue(safe_restore_rate_G, safe_restore_rate_GValues[expNum]);
  SetGvValue(test_execution_rate_G, test_execution_rate_GValues[expNum]);
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new safe_restore_rate_G_SetStudySetStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* safe_restore_rate_G_SetStudySetStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new RWDPVModel(expandTimeArrays);
  return ThePVModel;
}


