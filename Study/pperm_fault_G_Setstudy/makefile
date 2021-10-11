OBJS=pperm_fault_G_SetstudySetStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libpperm_fault_G_SetstudySetStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libpperm_fault_G_SetstudySetStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libpperm_fault_G_SetstudySetStudy.a: FORCE
	$(MAKE) lib TARGET=libpperm_fault_G_SetstudySetStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libpperm_fault_G_SetstudySetStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libpperm_fault_G_SetstudySetStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

