OBJS=


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

BINDIR=
MAINLIB=-lgenMain
MAINLIB_debug=-lgenMain_debug
SIMLIB=gen
SIMLIB_debug=gen_debug
SIMLIB_trace=gen_trace
PROJECTLIBS=-ltest_execution_rate_G_SetStudySetStudy -lRWDPV -lsanSAN 
PROJECTLIBS_debug=-ltest_execution_rate_G_SetStudySetStudy_debug -lRWDPV_debug -lsanSAN_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV -lSAN -lbase -lstate -lmobutil -ldist 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug -lSAN_debug -lbase_debug -lstate_debug -lmobutil_debug -ldist_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
stSpcGenGen_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=stSpcGenGen_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
stSpcGenGen_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=stSpcGenGen_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
stSpcGenGen_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=stSpcGenGen_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Atomic/san/ && $(MAKE) clean
	cd ../../Reward/RWD/ && $(MAKE) clean
	cd ../../Study/test_execution_rate_G_SetStudy/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[san]"
	cd ../../Atomic/san/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[RWD]"
	cd ../../Reward/RWD/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[test_execution_rate_G_SetStudy]"
	cd ../../Study/test_execution_rate_G_SetStudy/ && $(MAKE) $(@F)


