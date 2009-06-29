include $(top_srcdir)/Makefile.tool.am

noinst_PROGRAMS = 
if VGCONF_PLATFORMS_INCLUDE_X86_LINUX
noinst_PROGRAMS += catchconv-x86-linux vgpreload_catchconv-x86-linux.so
endif
if VGCONF_PLATFORMS_INCLUDE_AMD64_LINUX
noinst_PROGRAMS += catchconv-amd64-linux
endif
if VGCONF_PLATFORMS_INCLUDE_PPC32_LINUX
noinst_PROGRAMS += catchconv-ppc32-linux
endif
if VGCONF_PLATFORMS_INCLUDE_X86_DARWIN
noinst_PROGRAMS += catchconv-x86-darwin
endif

vgpreload_catchconv_x86_linux_so_SOURCES      =
vgpreload_catchconv_x86_linux_so_CPPFLAGS     = $(AM_CPPFLAGS_X86_LINUX)
vgpreload_catchconv_x86_linux_so_CFLAGS       = $(AM_CFLAGS_X86_LINUX) $(AM_CFLAGS_PIC)
vgpreload_catchconv_x86_linux_so_DEPENDENCIES = $(LIBREPLACEMALLOC_X86_LINUX)
vgpreload_catchconv_x86_linux_so_LDFLAGS      = \
        $(PRELOAD_LDFLAGS_X86_LINUX) \
        $(LIBREPLACEMALLOC_LDFLAGS_X86_LINUX)


CATCHCONV_SOURCES_COMMON = ca_main.c cgIR.c cgIRUnop.c cgIRBinop.c ogIR.c isIR.c ca_malloc_wrappers.c ca_interval_dumb.c ca_callbacks.c trackmemIR.c findRepMov.c ufOgIR.c ufInstOgIR.c cgIRCalcCondition.c

catchconv_x86_linux_SOURCES      = $(CATCHCONV_SOURCES_COMMON)
catchconv_x86_linux_CPPFLAGS     = $(AM_CPPFLAGS_X86_LINUX)
catchconv_x86_linux_CFLAGS       = $(AM_CFLAGS_X86_LINUX)
catchconv_x86_linux_DEPENDENCIES = $(COREGRIND_LIBS_X86_LINUX)
catchconv_x86_linux_LDADD        = $(TOOL_LDADD_X86_LINUX)
catchconv_x86_linux_LDFLAGS      = $(TOOL_LDFLAGS_X86_LINUX)

catchconv_amd64_linux_SOURCES      = $(CATCHCONV_SOURCES_COMMON)
catchconv_amd64_linux_CPPFLAGS     = $(AM_CPPFLAGS_AMD64_LINUX)
catchconv_amd64_linux_CFLAGS       = $(AM_CFLAGS_AMD64_LINUX)
catchconv_amd64_linux_DEPENDENCIES = $(COREGRIND_LIBS_AMD64_LINUX)
catchconv_amd64_linux_LDADD        = $(TOOL_LDADD_AMD64_LINUX)
catchconv_amd64_linux_LDFLAGS      = $(TOOL_LDFLAGS_AMD64_LINUX)

catchconv_ppc32_linux_SOURCES      = $(CATCHCONV_SOURCES_COMMON)
catchconv_ppc32_linux_CPPFLAGS     = $(AM_CPPFLAGS_PPC32_LINUX)
catchconv_ppc32_linux_CFLAGS       = $(AM_CFLAGS_PPC32_LINUX)
catchconv_ppc32_linux_DEPENDENCIES = $(COREGRIND_LIBS_PPC32_LINUX)
catchconv_ppc32_linux_LDADD        = $(TOOL_LDADD_PPC32_LINUX)
catchconv_ppc32_linux_LDFLAGS      = $(TOOL_LDFLAGS_PPC32_LINUX)

catchconv_x86_darwin_SOURCES      = $(CATCHCONV_SOURCES_COMMON)
catchconv_x86_darwin_CPPFLAGS     = $(AM_CPPFLAGS_X86_DARWIN)
catchconv_x86_darwin_CFLAGS       = $(AM_CFLAGS_X86_DARWIN)
catchconv_x86_darwin_DEPENDENCIES = $(COREGRIND_LIBS_X86_DARWIN)
catchconv_x86_darwin_LDADD        = $(TOOL_LDADD_X86_DARWIN)
catchconv_x86_darwin_LDFLAGS      = $(TOOL_LDFLAGS_X86_DARWIN)















