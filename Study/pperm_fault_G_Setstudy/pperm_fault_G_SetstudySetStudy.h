
#ifndef pperm_fault_G_SetstudySetSTUDY_H_
#define pperm_fault_G_SetstudySetSTUDY_H_

#include "Reward/RWD/RWDPVNodes.h"
#include "Reward/RWD/RWDPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Double pperm_fault_G;
extern Double safe_restore_rate_G;
extern Double test_execution_rate_G;

class pperm_fault_G_SetstudySetStudy : public BaseStudyClass {
public:

pperm_fault_G_SetstudySetStudy();
~pperm_fault_G_SetstudySetStudy();

private:

double *pperm_fault_GValues;
double *safe_restore_rate_GValues;
double *test_execution_rate_GValues;

void SetValues_pperm_fault_G();
void SetValues_safe_restore_rate_G();
void SetValues_test_execution_rate_G();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

