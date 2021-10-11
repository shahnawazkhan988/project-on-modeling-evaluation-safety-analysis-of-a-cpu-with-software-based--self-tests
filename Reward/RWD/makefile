OBJS=RWDPVNodes.o RWDPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libRWDPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libRWDPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libRWDPV.a: FORCE
	$(MAKE) lib TARGET=libRWDPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libRWDPV_debug.a: FORCE
	$(MAKE) lib TARGET=libRWDPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

