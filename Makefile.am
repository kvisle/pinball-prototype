SUBDIRS = lib src

CODER       = coder$(EXEEXT)

CLEANFILES = $(CODER)

EXTRA_DIST = autogen.sh include

all-local: $(CODER)

$(CODER):
	$(LN_S) "src/$(CODER)" "$(CODER)"

