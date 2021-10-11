OBJS=safe_restore_rate_G_SetStudySetStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libsafe_restore_rate_G_SetStudySetStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libsafe_restore_rate_G_SetStudySetStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libsafe_restore_rate_G_SetStudySetStudy.a: FORCE
	$(MAKE) lib TARGET=libsafe_restore_rate_G_SetStudySetStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libsafe_restore_rate_G_SetStudySetStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libsafe_restore_rate_G_SetStudySetStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

