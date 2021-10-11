OBJS=sanSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libsanSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libsanSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libsanSAN.a: FORCE
	$(MAKE) lib TARGET=libsanSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libsanSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libsanSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

