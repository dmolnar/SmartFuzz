include $(top_srcdir)/Makefile.tool.am

SUBDIRS += perf

bin_SCRIPTS = ms_print

noinst_PROGRAMS = 
noinst_DSYMS =
if VGCONF_PLATFORMS_INCLUDE_X86_LINUX
noinst_PROGRAMS += massif-x86-linux vgpreload_massif-x86-linux.so
endif
if VGCONF_PLATFORMS_INCLUDE_AMD64_LINUX
noinst_PROGRAMS += massif-amd64-linux vgpreload_massif-amd64-linux.so
endif
if VGCONF_PLATFORMS_INCLUDE_PPC32_LINUX
noinst_PROGRAMS += massif-ppc32-linux vgpreload_massif-ppc32-linux.so
endif
if VGCONF_PLATFORMS_INCLUDE_PPC64_LINUX
noinst_PROGRAMS += massif-ppc64-linux vgpreload_massif-ppc64-linux.so
endif
if VGCONF_PLATFORMS_INCLUDE_PPC32_AIX5
noinst_PROGRAMS += massif-ppc32-aix5 vgpreload_massif-ppc32-aix5.so
endif
if VGCONF_PLATFORMS_INCLUDE_PPC64_AIX5
noinst_PROGRAMS += massif-ppc64-aix5 vgpreload_massif-ppc64-aix5.so
endif
if VGCONF_PLATFORMS_INCLUDE_X86_DARWIN
noinst_PROGRAMS += massif-x86-darwin vgpreload_massif-x86-darwin.so
noinst_DSYMS    +=                   vgpreload_massif-x86-darwin.so
endif
if VGCONF_PLATFORMS_INCLUDE_AMD64_DARWIN
noinst_PROGRAMS += massif-amd64-darwin vgpreload_massif-amd64-darwin.so
noinst_DSYMS    +=                     vgpreload_massif-amd64-darwin.so
endif

vgpreload_massif_x86_linux_so_SOURCES      = 
vgpreload_massif_x86_linux_so_CPPFLAGS     = $(AM_CPPFLAGS_X86_LINUX)
vgpreload_massif_x86_linux_so_CFLAGS       = $(AM_CFLAGS_X86_LINUX) $(AM_CFLAGS_PIC)
vgpreload_massif_x86_linux_so_DEPENDENCIES = $(LIBREPLACEMALLOC_X86_LINUX)
vgpreload_massif_x86_linux_so_LDFLAGS      = \
	$(PRELOAD_LDFLAGS_X86_LINUX) \
	$(LIBREPLACEMALLOC_LDFLAGS_X86_LINUX)

vgpreload_massif_amd64_linux_so_SOURCES      = 
vgpreload_massif_amd64_linux_so_CPPFLAGS     = $(AM_CPPFLAGS_AMD64_LINUX)
vgpreload_massif_amd64_linux_so_CFLAGS       = $(AM_CFLAGS_AMD64_LINUX) $(AM_CFLAGS_PIC)
vgpreload_massif_amd64_linux_so_DEPENDENCIES = $(LIBREPLACEMALLOC_AMD64_LINUX)
vgpreload_massif_amd64_linux_so_LDFLAGS      = \
	$(PRELOAD_LDFLAGS_AMD64_LINUX) \
	$(LIBREPLACEMALLOC_LDFLAGS_AMD64_LINUX)

vgpreload_massif_ppc32_linux_so_SOURCES      = 
vgpreload_massif_ppc32_linux_so_CPPFLAGS     = $(AM_CPPFLAGS_PPC32_LINUX)
vgpreload_massif_ppc32_linux_so_CFLAGS       = $(AM_CFLAGS_PPC32_LINUX) $(AM_CFLAGS_PIC)
vgpreload_massif_ppc32_linux_so_DEPENDENCIES = $(LIBREPLACEMALLOC_PPC32_LINUX)
vgpreload_massif_ppc32_linux_so_LDFLAGS      = \
	$(PRELOAD_LDFLAGS_PPC32_LINUX) \
	$(LIBREPLACEMALLOC_LDFLAGS_PPC32_LINUX)

vgpreload_massif_ppc64_linux_so_SOURCES      = 
vgpreload_massif_ppc64_linux_so_CPPFLAGS     = $(AM_CPPFLAGS_PPC64_LINUX)
vgpreload_massif_ppc64_linux_so_CFLAGS       = $(AM_CFLAGS_PPC64_LINUX) $(AM_CFLAGS_PIC)
vgpreload_massif_ppc64_linux_so_DEPENDENCIES = $(LIBREPLACEMALLOC_PPC64_LINUX)
vgpreload_massif_ppc64_linux_so_LDFLAGS      = \
	$(PRELOAD_LDFLAGS_PPC64_LINUX) \
	$(LIBREPLACEMALLOC_LDFLAGS_PPC64_LINUX)

vgpreload_massif_ppc32_aix5_so_SOURCES      = 
vgpreload_massif_ppc32_aix5_so_CPPFLAGS     = $(AM_CPPFLAGS_PPC32_AIX5)
vgpreload_massif_ppc32_aix5_so_CFLAGS       = $(AM_CFLAGS_PPC32_AIX5) $(AM_CFLAGS_PIC)
vgpreload_massif_ppc32_aix5_so_DEPENDENCIES = $(LIBREPLACEMALLOC_PPC32_AIX5)
vgpreload_massif_ppc32_aix5_so_LDFLAGS      = \
	$(PRELOAD_LDFLAGS_PPC32_AIX5) \
	$(LIBREPLACEMALLOC_LDFLAGS_PPC32_AIX5)

vgpreload_massif_ppc64_aix5_so_SOURCES      = 
vgpreload_massif_ppc64_aix5_so_CPPFLAGS     = $(AM_CPPFLAGS_PPC64_AIX5)
vgpreload_massif_ppc64_aix5_so_CFLAGS       = $(AM_CFLAGS_PPC64_AIX5) $(AM_CFLAGS_PIC)
vgpreload_massif_ppc64_aix5_so_DEPENDENCIES = $(LIBREPLACEMALLOC_PPC64_AIX5)
vgpreload_massif_ppc64_aix5_so_LDFLAGS      = \
	$(PRELOAD_LDFLAGS_PPC64_AIX5) \
	$(LIBREPLACEMALLOC_LDFLAGS_PPC64_AIX5)

vgpreload_massif_x86_darwin_so_SOURCES      = 
vgpreload_massif_x86_darwin_so_CPPFLAGS     = $(AM_CPPFLAGS_X86_DARWIN)
vgpreload_massif_x86_darwin_so_CFLAGS       = $(AM_CFLAGS_X86_DARWIN) $(AM_CFLAGS_PIC)
vgpreload_massif_x86_darwin_so_DEPENDENCIES = $(LIBREPLACEMALLOC_X86_DARWIN)
vgpreload_massif_x86_darwin_so_LDFLAGS      = \
	$(PRELOAD_LDFLAGS_X86_DARWIN) \
	$(LIBREPLACEMALLOC_LDFLAGS_X86_DARWIN)

vgpreload_massif_amd64_darwin_so_SOURCES      = 
vgpreload_massif_amd64_darwin_so_CPPFLAGS     = $(AM_CPPFLAGS_AMD64_DARWIN)
vgpreload_massif_amd64_darwin_so_CFLAGS       = $(AM_CFLAGS_AMD64_DARWIN) $(AM_CFLAGS_PIC)
vgpreload_massif_amd64_darwin_so_DEPENDENCIES = $(LIBREPLACEMALLOC_AMD64_DARWIN)
vgpreload_massif_amd64_darwin_so_LDFLAGS      = \
	$(PRELOAD_LDFLAGS_AMD64_DARWIN) \
	$(LIBREPLACEMALLOC_LDFLAGS_AMD64_DARWIN)

MASSIF_SOURCES_COMMON = ms_main.c

massif_x86_linux_SOURCES      = $(MASSIF_SOURCES_COMMON)
massif_x86_linux_CPPFLAGS     = $(AM_CPPFLAGS_X86_LINUX)
massif_x86_linux_CFLAGS       = $(AM_CFLAGS_X86_LINUX)
massif_x86_linux_DEPENDENCIES = $(COREGRIND_LIBS_X86_LINUX)
massif_x86_linux_LDADD        = $(TOOL_LDADD_X86_LINUX)
massif_x86_linux_LDFLAGS      = $(TOOL_LDFLAGS_X86_LINUX)

massif_amd64_linux_SOURCES      = $(MASSIF_SOURCES_COMMON)
massif_amd64_linux_CPPFLAGS     = $(AM_CPPFLAGS_AMD64_LINUX)
massif_amd64_linux_CFLAGS       = $(AM_CFLAGS_AMD64_LINUX)
massif_amd64_linux_DEPENDENCIES = $(COREGRIND_LIBS_AMD64_LINUX)
massif_amd64_linux_LDADD        = $(TOOL_LDADD_AMD64_LINUX)
massif_amd64_linux_LDFLAGS      = $(TOOL_LDFLAGS_AMD64_LINUX)

massif_ppc32_linux_SOURCES      = $(MASSIF_SOURCES_COMMON)
massif_ppc32_linux_CPPFLAGS     = $(AM_CPPFLAGS_PPC32_LINUX)
massif_ppc32_linux_CFLAGS       = $(AM_CFLAGS_PPC32_LINUX)
massif_ppc32_linux_DEPENDENCIES = $(COREGRIND_LIBS_PPC32_LINUX)
massif_ppc32_linux_LDADD        = $(TOOL_LDADD_PPC32_LINUX)
massif_ppc32_linux_LDFLAGS      = $(TOOL_LDFLAGS_PPC32_LINUX)

massif_ppc64_linux_SOURCES      = $(MASSIF_SOURCES_COMMON)
massif_ppc64_linux_CPPFLAGS     = $(AM_CPPFLAGS_PPC64_LINUX)
massif_ppc64_linux_CFLAGS       = $(AM_CFLAGS_PPC64_LINUX)
massif_ppc64_linux_DEPENDENCIES = $(COREGRIND_LIBS_PPC64_LINUX)
massif_ppc64_linux_LDADD        = $(TOOL_LDADD_PPC64_LINUX)
massif_ppc64_linux_LDFLAGS      = $(TOOL_LDFLAGS_PPC64_LINUX)

massif_ppc32_aix5_SOURCES      = $(MASSIF_SOURCES_COMMON)
massif_ppc32_aix5_CPPFLAGS     = $(AM_CPPFLAGS_PPC32_AIX5)
massif_ppc32_aix5_CFLAGS       = $(AM_CFLAGS_PPC32_AIX5)
massif_ppc32_aix5_DEPENDENCIES = $(COREGRIND_LIBS_PPC32_AIX5)
massif_ppc32_aix5_LDADD        = $(TOOL_LDADD_PPC32_AIX5)
massif_ppc32_aix5_LDFLAGS      = $(TOOL_LDFLAGS_PPC32_AIX5)

massif_ppc64_aix5_SOURCES      = $(MASSIF_SOURCES_COMMON)
massif_ppc64_aix5_CPPFLAGS     = $(AM_CPPFLAGS_PPC64_AIX5)
massif_ppc64_aix5_CFLAGS       = $(AM_CFLAGS_PPC64_AIX5)
massif_ppc64_aix5_DEPENDENCIES = $(COREGRIND_LIBS_PPC64_AIX5)
massif_ppc64_aix5_LDADD        = $(TOOL_LDADD_PPC64_AIX5)
massif_ppc64_aix5_LDFLAGS      = $(TOOL_LDFLAGS_PPC64_AIX5)

massif_x86_darwin_SOURCES      = $(MASSIF_SOURCES_COMMON)
massif_x86_darwin_CPPFLAGS     = $(AM_CPPFLAGS_X86_DARWIN)
massif_x86_darwin_CFLAGS       = $(AM_CFLAGS_X86_DARWIN)
massif_x86_darwin_DEPENDENCIES = $(COREGRIND_LIBS_X86_DARWIN)
massif_x86_darwin_LDADD        = $(TOOL_LDADD_X86_DARWIN)
massif_x86_darwin_LDFLAGS      = $(TOOL_LDFLAGS_X86_DARWIN)

massif_amd64_darwin_SOURCES      = $(MASSIF_SOURCES_COMMON)
massif_amd64_darwin_CPPFLAGS     = $(AM_CPPFLAGS_AMD64_DARWIN)
massif_amd64_darwin_CFLAGS       = $(AM_CFLAGS_AMD64_DARWIN)
massif_amd64_darwin_DEPENDENCIES = $(COREGRIND_LIBS_AMD64_DARWIN)
massif_amd64_darwin_LDADD        = $(TOOL_LDADD_AMD64_DARWIN)
massif_amd64_darwin_LDFLAGS      = $(TOOL_LDFLAGS_AMD64_DARWIN)
