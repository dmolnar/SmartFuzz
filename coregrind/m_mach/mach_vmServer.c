/*
 * IDENTIFICATION:
 * stub generated Mon Jun 15 19:50:16 2009
 * with a MiG generated Tue Feb 19 02:01:43 PST 2008 by root@b75.local
 * OPTIONS: 
 */

/* Module mach_vm */

#define	__MIG_check__Request__mach_vm_subsystem__ 1
#define	__NDR_convert__Request__mach_vm_subsystem__ 1

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>

#include <mach/std_types.h>
#include <mach/mig.h>
#include <mach/mig.h>
#include <mach/mach_types.h>
#include <mach_debug/mach_debug_types.h>

#ifndef	mig_internal
#define	mig_internal	static __inline__
#endif	/* mig_internal */

#ifndef	mig_external
#define mig_external
#endif	/* mig_external */

#if	!defined(__MigTypeCheck) && defined(TypeCheck)
#define	__MigTypeCheck		TypeCheck	/* Legacy setting */
#endif	/* !defined(__MigTypeCheck) */

#if	!defined(__MigKernelSpecificCode) && defined(_MIG_KERNEL_SPECIFIC_CODE_)
#define	__MigKernelSpecificCode	_MIG_KERNEL_SPECIFIC_CODE_	/* Legacy setting */
#endif	/* !defined(__MigKernelSpecificCode) */

#ifndef	LimitCheck
#define	LimitCheck 0
#endif	/* LimitCheck */

#ifndef	min
#define	min(a,b)  ( ((a) < (b))? (a): (b) )
#endif	/* min */

#if !defined(_WALIGN_)
#define _WALIGN_(x) (((x) + 3) & ~3)
#endif /* !defined(_WALIGN_) */

#if !defined(_WALIGNSZ_)
#define _WALIGNSZ_(x) _WALIGN_(sizeof(x))
#endif /* !defined(_WALIGNSZ_) */

#ifndef	UseStaticTemplates
#define	UseStaticTemplates	0
#endif	/* UseStaticTemplates */

#ifndef	__DeclareRcvRpc
#define	__DeclareRcvRpc(_NUM_, _NAME_)
#endif	/* __DeclareRcvRpc */

#ifndef	__BeforeRcvRpc
#define	__BeforeRcvRpc(_NUM_, _NAME_)
#endif	/* __BeforeRcvRpc */

#ifndef	__AfterRcvRpc
#define	__AfterRcvRpc(_NUM_, _NAME_)
#endif	/* __AfterRcvRpc */

#ifndef	__DeclareRcvSimple
#define	__DeclareRcvSimple(_NUM_, _NAME_)
#endif	/* __DeclareRcvSimple */

#ifndef	__BeforeRcvSimple
#define	__BeforeRcvSimple(_NUM_, _NAME_)
#endif	/* __BeforeRcvSimple */

#ifndef	__AfterRcvSimple
#define	__AfterRcvSimple(_NUM_, _NAME_)
#endif	/* __AfterRcvSimple */

#define novalue void

#define msgh_request_port	msgh_local_port
#define MACH_MSGH_BITS_REQUEST(bits)	MACH_MSGH_BITS_LOCAL(bits)
#define msgh_reply_port		msgh_remote_port
#define MACH_MSGH_BITS_REPLY(bits)	MACH_MSGH_BITS_REMOTE(bits)

#define MIG_RETURN_ERROR(X, code)	{\
				((mig_reply_error_t *)X)->RetCode = code;\
				((mig_reply_error_t *)X)->NDR = NDR_record;\
				return;\
				}

/* typedefs for all requests */

#ifndef __Request__mach_vm_subsystem__defined
#define __Request__mach_vm_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		int flags;
	} __Request__mach_vm_allocate_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
	} __Request__mach_vm_deallocate_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		boolean_t set_maximum;
		vm_prot_t new_protection;
	} __Request__mach_vm_protect_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		vm_inherit_t new_inheritance;
	} __Request__mach_vm_inherit_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
	} __Request__mach_vm_read_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_read_entry_t data_list;
		natural_t count;
	} __Request__mach_vm_read_list_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t data;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_msg_type_number_t dataCnt;
	} __Request__mach_vm_write_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t source_address;
		mach_vm_size_t size;
		mach_vm_address_t dest_address;
	} __Request__mach_vm_copy_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		mach_vm_address_t data;
	} __Request__mach_vm_read_overwrite_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		vm_sync_t sync_flags;
	} __Request__mach_vm_msync_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		vm_behavior_t new_behavior;
	} __Request__mach_vm_behavior_set_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t object;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		mach_vm_offset_t mask;
		int flags;
		memory_object_offset_t offset;
		boolean_t copy;
		vm_prot_t cur_protection;
		vm_prot_t max_protection;
		vm_inherit_t inheritance;
	} __Request__mach_vm_map_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		vm_machine_attribute_t attribute;
		vm_machine_attribute_val_t value;
	} __Request__mach_vm_machine_attribute_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t src_task;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_vm_address_t target_address;
		mach_vm_size_t size;
		mach_vm_offset_t mask;
		boolean_t anywhere;
		mach_vm_address_t src_address;
		boolean_t copy;
		vm_inherit_t inheritance;
	} __Request__mach_vm_remap_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_offset_t offset;
	} __Request__mach_vm_page_query_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		natural_t nesting_depth;
		mach_msg_type_number_t infoCnt;
	} __Request__mach_vm_region_recurse_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		vm_region_flavor_t flavor;
		mach_msg_type_number_t infoCnt;
	} __Request__mach_vm_region_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t parent_handle;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		memory_object_size_t size;
		memory_object_offset_t offset;
		vm_prot_t permission;
	} __Request___mach_make_memory_entry_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		vm_purgable_t control;
		int state;
	} __Request__mach_vm_purgable_control_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Request__mach_vm_subsystem__defined */

/* typedefs for all replies */

#ifndef __Reply__mach_vm_subsystem__defined
#define __Reply__mach_vm_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		mach_vm_address_t address;
	} __Reply__mach_vm_allocate_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__mach_vm_deallocate_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__mach_vm_protect_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__mach_vm_inherit_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t data;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t dataCnt;
	} __Reply__mach_vm_read_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		mach_vm_read_entry_t data_list;
	} __Reply__mach_vm_read_list_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__mach_vm_write_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__mach_vm_copy_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		mach_vm_size_t outsize;
	} __Reply__mach_vm_read_overwrite_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__mach_vm_msync_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__mach_vm_behavior_set_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		mach_vm_address_t address;
	} __Reply__mach_vm_map_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		vm_machine_attribute_val_t value;
	} __Reply__mach_vm_machine_attribute_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		mach_vm_address_t target_address;
		vm_prot_t cur_protection;
		vm_prot_t max_protection;
	} __Reply__mach_vm_remap_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		integer_t disposition;
		integer_t ref_count;
	} __Reply__mach_vm_page_query_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		mach_vm_address_t address;
		mach_vm_size_t size;
		natural_t nesting_depth;
		mach_msg_type_number_t infoCnt;
		int info[19];
	} __Reply__mach_vm_region_recurse_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t object_name;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		mach_msg_type_number_t infoCnt;
		int info[10];
	} __Reply__mach_vm_region_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t object_handle;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		memory_object_size_t size;
	} __Reply___mach_make_memory_entry_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		int state;
	} __Reply__mach_vm_purgable_control_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Reply__mach_vm_subsystem__defined */


/* union of all replies */

#ifndef __ReplyUnion__mach_vm_subsystem__defined
#define __ReplyUnion__mach_vm_subsystem__defined
union __ReplyUnion__mach_vm_subsystem {
	__Reply__mach_vm_allocate_t Reply_mach_vm_allocate;
	__Reply__mach_vm_deallocate_t Reply_mach_vm_deallocate;
	__Reply__mach_vm_protect_t Reply_mach_vm_protect;
	__Reply__mach_vm_inherit_t Reply_mach_vm_inherit;
	__Reply__mach_vm_read_t Reply_mach_vm_read;
	__Reply__mach_vm_read_list_t Reply_mach_vm_read_list;
	__Reply__mach_vm_write_t Reply_mach_vm_write;
	__Reply__mach_vm_copy_t Reply_mach_vm_copy;
	__Reply__mach_vm_read_overwrite_t Reply_mach_vm_read_overwrite;
	__Reply__mach_vm_msync_t Reply_mach_vm_msync;
	__Reply__mach_vm_behavior_set_t Reply_mach_vm_behavior_set;
	__Reply__mach_vm_map_t Reply_mach_vm_map;
	__Reply__mach_vm_machine_attribute_t Reply_mach_vm_machine_attribute;
	__Reply__mach_vm_remap_t Reply_mach_vm_remap;
	__Reply__mach_vm_page_query_t Reply_mach_vm_page_query;
	__Reply__mach_vm_region_recurse_t Reply_mach_vm_region_recurse;
	__Reply__mach_vm_region_t Reply_mach_vm_region;
	__Reply___mach_make_memory_entry_t Reply__mach_make_memory_entry;
	__Reply__mach_vm_purgable_control_t Reply_mach_vm_purgable_control;
};
#endif /* __RequestUnion__mach_vm_subsystem__defined */
/* Forward Declarations */


mig_internal novalue _Xmach_vm_allocate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_deallocate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_protect
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_inherit
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_read
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_read_list
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_write
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_copy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_read_overwrite
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_msync
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_behavior_set
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_map
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_machine_attribute
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_remap
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_page_query
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_region_recurse
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_region
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _X_mach_make_memory_entry
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_vm_purgable_control
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);


#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_allocate_t__defined)
#define __MIG_check__Request__mach_vm_allocate_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_allocate_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_allocate_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_allocate_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_allocate_t__size__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_allocate_t__flags__defined
#if	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_allocate_t__flags__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_allocate_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_allocate_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_allocate_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_allocate_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_allocate_t__flags__defined
#if	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_allocate_t__flags__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_allocate_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_allocate_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_allocate_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_allocate_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_allocate_t__flags__defined
#if	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_allocate_t__flags(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_allocate_t__flags__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_allocate_t(__attribute__((__unused__)) __Request__mach_vm_allocate_t *In0P)
{

	typedef __Request__mach_vm_allocate_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_allocate_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_allocate_t__size__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_allocate_t__flags__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_allocate_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_allocate_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_allocate_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_allocate_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_allocate_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_allocate_t__size__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_allocate_t__flags__defined)
		__NDR_convert__int_rep__Request__mach_vm_allocate_t__flags(&In0P->flags, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_allocate_t__flags__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_allocate_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_allocate_t__size__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_allocate_t__flags__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_allocate_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_allocate_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_allocate_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_allocate_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_allocate_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_allocate_t__size__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_allocate_t__flags__defined)
		__NDR_convert__char_rep__Request__mach_vm_allocate_t__flags(&In0P->flags, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_allocate_t__flags__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_allocate_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_allocate_t__size__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_allocate_t__flags__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_allocate_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_allocate_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_allocate_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_allocate_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_allocate_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_allocate_t__size__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_allocate_t__flags__defined)
		__NDR_convert__float_rep__Request__mach_vm_allocate_t__flags(&In0P->flags, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_allocate_t__flags__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_allocate_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_allocate */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_allocate
(
	vm_task_entry_t target,
	mach_vm_address_t *address,
	mach_vm_size_t size,
	int flags
);

/* Routine mach_vm_allocate */
mig_internal novalue _Xmach_vm_allocate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		int flags;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_allocate_t __Request;
	typedef __Reply__mach_vm_allocate_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_allocate_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_allocate_t__defined */

	__DeclareRcvRpc(4800, "mach_vm_allocate")
	__BeforeRcvRpc(4800, "mach_vm_allocate")

#if	defined(__MIG_check__Request__mach_vm_allocate_t__defined)
	check_result = __MIG_check__Request__mach_vm_allocate_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_allocate_t__defined) */

	OutP->RetCode = mach_vm_allocate(In0P->Head.msgh_request_port, &In0P->address, In0P->size, In0P->flags);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->address = In0P->address;

	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(4800, "mach_vm_allocate")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_deallocate_t__defined)
#define __MIG_check__Request__mach_vm_deallocate_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_deallocate_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_deallocate_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_deallocate_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_deallocate_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_deallocate_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_deallocate_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_deallocate_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_deallocate_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_deallocate_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_deallocate_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_deallocate_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_deallocate_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_deallocate_t__size__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_deallocate_t(__attribute__((__unused__)) __Request__mach_vm_deallocate_t *In0P)
{

	typedef __Request__mach_vm_deallocate_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_deallocate_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_deallocate_t__size__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_deallocate_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_deallocate_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_deallocate_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_deallocate_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_deallocate_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_deallocate_t__size__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_deallocate_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_deallocate_t__size__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_deallocate_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_deallocate_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_deallocate_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_deallocate_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_deallocate_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_deallocate_t__size__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_deallocate_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_deallocate_t__size__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_deallocate_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_deallocate_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_deallocate_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_deallocate_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_deallocate_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_deallocate_t__size__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_deallocate_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_deallocate */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_deallocate
(
	vm_task_entry_t target,
	mach_vm_address_t address,
	mach_vm_size_t size
);

/* Routine mach_vm_deallocate */
mig_internal novalue _Xmach_vm_deallocate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_deallocate_t __Request;
	typedef __Reply__mach_vm_deallocate_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_deallocate_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_deallocate_t__defined */

	__DeclareRcvRpc(4801, "mach_vm_deallocate")
	__BeforeRcvRpc(4801, "mach_vm_deallocate")

#if	defined(__MIG_check__Request__mach_vm_deallocate_t__defined)
	check_result = __MIG_check__Request__mach_vm_deallocate_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_deallocate_t__defined) */

	OutP->RetCode = mach_vm_deallocate(In0P->Head.msgh_request_port, In0P->address, In0P->size);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(4801, "mach_vm_deallocate")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_protect_t__defined)
#define __MIG_check__Request__mach_vm_protect_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_protect_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_protect_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_protect_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_protect_t__size__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_protect_t__set_maximum__defined
#if	defined(__NDR_convert__int_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__set_maximum__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__set_maximum(a, f) \
	__NDR_convert__int_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__set_maximum__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__set_maximum(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_protect_t__set_maximum__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__int_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_protect_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_protect_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_protect_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_protect_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_protect_t__set_maximum__defined
#if	defined(__NDR_convert__char_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__set_maximum__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__set_maximum(a, f) \
	__NDR_convert__char_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__set_maximum__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__set_maximum(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_protect_t__set_maximum__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__char_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_protect_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_protect_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_protect_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_protect_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_protect_t__set_maximum__defined
#if	defined(__NDR_convert__float_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__set_maximum__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__set_maximum(a, f) \
	__NDR_convert__float_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__set_maximum__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__set_maximum(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_protect_t__set_maximum__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__float_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_protect_t(__attribute__((__unused__)) __Request__mach_vm_protect_t *In0P)
{

	typedef __Request__mach_vm_protect_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_protect_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_protect_t__size__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_protect_t__set_maximum__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_protect_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_protect_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_protect_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_protect_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_protect_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_protect_t__size__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_protect_t__set_maximum__defined)
		__NDR_convert__int_rep__Request__mach_vm_protect_t__set_maximum(&In0P->set_maximum, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_protect_t__set_maximum__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection__defined)
		__NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection(&In0P->new_protection, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_protect_t__new_protection__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_protect_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_protect_t__size__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_protect_t__set_maximum__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_protect_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_protect_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_protect_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_protect_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_protect_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_protect_t__size__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_protect_t__set_maximum__defined)
		__NDR_convert__char_rep__Request__mach_vm_protect_t__set_maximum(&In0P->set_maximum, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_protect_t__set_maximum__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection__defined)
		__NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection(&In0P->new_protection, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_protect_t__new_protection__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_protect_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_protect_t__size__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_protect_t__set_maximum__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_protect_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_protect_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_protect_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_protect_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_protect_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_protect_t__size__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_protect_t__set_maximum__defined)
		__NDR_convert__float_rep__Request__mach_vm_protect_t__set_maximum(&In0P->set_maximum, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_protect_t__set_maximum__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection__defined)
		__NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection(&In0P->new_protection, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_protect_t__new_protection__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_protect_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_protect */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_protect
(
	vm_task_entry_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	boolean_t set_maximum,
	vm_prot_t new_protection
);

/* Routine mach_vm_protect */
mig_internal novalue _Xmach_vm_protect
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		boolean_t set_maximum;
		vm_prot_t new_protection;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_protect_t __Request;
	typedef __Reply__mach_vm_protect_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_protect_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_protect_t__defined */

	__DeclareRcvRpc(4802, "mach_vm_protect")
	__BeforeRcvRpc(4802, "mach_vm_protect")

#if	defined(__MIG_check__Request__mach_vm_protect_t__defined)
	check_result = __MIG_check__Request__mach_vm_protect_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_protect_t__defined) */

	OutP->RetCode = mach_vm_protect(In0P->Head.msgh_request_port, In0P->address, In0P->size, In0P->set_maximum, In0P->new_protection);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(4802, "mach_vm_protect")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_inherit_t__defined)
#define __MIG_check__Request__mach_vm_inherit_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_inherit_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_inherit_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_inherit_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_inherit_t__size__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_inherit_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_inherit_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__int_rep__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_inherit_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_inherit_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_inherit_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_inherit_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_inherit_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_inherit_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__char_rep__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_inherit_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_inherit_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_inherit_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_inherit_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_inherit_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_inherit_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__float_rep__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_inherit_t(__attribute__((__unused__)) __Request__mach_vm_inherit_t *In0P)
{

	typedef __Request__mach_vm_inherit_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_inherit_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_inherit_t__size__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_inherit_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_inherit_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_inherit_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_inherit_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_inherit_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_inherit_t__size__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance__defined)
		__NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance(&In0P->new_inheritance, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_inherit_t__new_inheritance__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_inherit_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_inherit_t__size__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_inherit_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_inherit_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_inherit_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_inherit_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_inherit_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_inherit_t__size__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance__defined)
		__NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance(&In0P->new_inheritance, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_inherit_t__new_inheritance__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_inherit_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_inherit_t__size__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_inherit_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_inherit_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_inherit_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_inherit_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_inherit_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_inherit_t__size__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance__defined)
		__NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance(&In0P->new_inheritance, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_inherit_t__new_inheritance__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_inherit_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_inherit */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_inherit
(
	vm_task_entry_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	vm_inherit_t new_inheritance
);

/* Routine mach_vm_inherit */
mig_internal novalue _Xmach_vm_inherit
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		vm_inherit_t new_inheritance;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_inherit_t __Request;
	typedef __Reply__mach_vm_inherit_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_inherit_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_inherit_t__defined */

	__DeclareRcvRpc(4803, "mach_vm_inherit")
	__BeforeRcvRpc(4803, "mach_vm_inherit")

#if	defined(__MIG_check__Request__mach_vm_inherit_t__defined)
	check_result = __MIG_check__Request__mach_vm_inherit_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_inherit_t__defined) */

	OutP->RetCode = mach_vm_inherit(In0P->Head.msgh_request_port, In0P->address, In0P->size, In0P->new_inheritance);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(4803, "mach_vm_inherit")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_read_t__defined)
#define __MIG_check__Request__mach_vm_read_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_read_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_read_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_read_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_read_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_read_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_read_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_read_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_read_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_read_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_read_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_read_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_read_t__size__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_read_t(__attribute__((__unused__)) __Request__mach_vm_read_t *In0P)
{

	typedef __Request__mach_vm_read_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_read_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_read_t__size__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_read_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_read_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_read_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_read_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_read_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_read_t__size__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_read_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_read_t__size__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_read_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_read_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_read_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_read_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_read_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_read_t__size__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_read_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_read_t__size__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_read_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_read_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_read_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_read_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_read_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_read_t__size__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_read_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_read */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_read
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	vm_offset_t *data,
	mach_msg_type_number_t *dataCnt
);

/* Routine mach_vm_read */
mig_internal novalue _Xmach_vm_read
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_read_t __Request;
	typedef __Reply__mach_vm_read_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_read_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_read_t__defined */

#if	UseStaticTemplates
	const static mach_msg_ool_descriptor_t dataTemplate = {
		/* addr = */		(void *)0,
		/* size = */		0,
		/* deal = */		FALSE,
		/* copy = */		MACH_MSG_VIRTUAL_COPY,
		/* pad2 = */		0,
		/* type = */		MACH_MSG_OOL_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(4804, "mach_vm_read")
	__BeforeRcvRpc(4804, "mach_vm_read")

#if	defined(__MIG_check__Request__mach_vm_read_t__defined)
	check_result = __MIG_check__Request__mach_vm_read_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_read_t__defined) */

#if	UseStaticTemplates
	OutP->data = dataTemplate;
#else	/* UseStaticTemplates */
	OutP->data.deallocate =  FALSE;
	OutP->data.copy = MACH_MSG_VIRTUAL_COPY;
	OutP->data.type = MACH_MSG_OOL_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = mach_vm_read(In0P->Head.msgh_request_port, In0P->address, In0P->size, (vm_offset_t *)&(OutP->data.address), &OutP->dataCnt);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}
	OutP->data.size = OutP->dataCnt;


	OutP->NDR = NDR_record;


	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(4804, "mach_vm_read")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_read_list_t__defined)
#define __MIG_check__Request__mach_vm_read_list_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_read_entry_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_read_entry_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__int_rep__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__int_rep__mach_vm__mach_vm_offset_t)
#elif	defined(__NDR_convert__int_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__int_rep__mach_vm_offset_t)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__int_rep__mach_vm__uint64_t)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__int_rep__uint64_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_read_list_t__count__defined
#if	defined(__NDR_convert__int_rep__mach_vm__natural_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__int_rep__mach_vm__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__int_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__int_rep__mach_vm__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__int_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_read_list_t__count__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_read_entry_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_read_entry_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__char_rep__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__char_rep__mach_vm__mach_vm_offset_t)
#elif	defined(__NDR_convert__char_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__char_rep__mach_vm_offset_t)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__char_rep__mach_vm__uint64_t)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__char_rep__uint64_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_read_list_t__count__defined
#if	defined(__NDR_convert__char_rep__mach_vm__natural_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__char_rep__mach_vm__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__char_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__char_rep__mach_vm__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__char_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_read_list_t__count__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_read_entry_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_read_entry_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__float_rep__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__float_rep__mach_vm__mach_vm_offset_t)
#elif	defined(__NDR_convert__float_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__float_rep__mach_vm_offset_t)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__float_rep__mach_vm__uint64_t)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__float_rep__uint64_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_read_list_t__count__defined
#if	defined(__NDR_convert__float_rep__mach_vm__natural_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__float_rep__mach_vm__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__float_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__float_rep__mach_vm__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__count__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_list_t__count(a, f) \
	__NDR_convert__float_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_read_list_t__count__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_read_list_t(__attribute__((__unused__)) __Request__mach_vm_read_list_t *In0P)
{

	typedef __Request__mach_vm_read_list_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_read_list_t__count__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list__defined)
		__NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list(&In0P->data_list, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_read_list_t__data_list__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_read_list_t__count__defined)
		__NDR_convert__int_rep__Request__mach_vm_read_list_t__count(&In0P->count, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_read_list_t__count__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_read_list_t__count__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list__defined)
		__NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list(&In0P->data_list, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_read_list_t__data_list__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_read_list_t__count__defined)
		__NDR_convert__char_rep__Request__mach_vm_read_list_t__count(&In0P->count, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_read_list_t__count__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_read_list_t__count__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list__defined)
		__NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list(&In0P->data_list, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_read_list_t__data_list__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_read_list_t__count__defined)
		__NDR_convert__float_rep__Request__mach_vm_read_list_t__count(&In0P->count, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_read_list_t__count__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_read_list_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_read_list */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_read_list
(
	vm_map_t target_task,
	mach_vm_read_entry_t data_list,
	natural_t count
);

/* Routine mach_vm_read_list */
mig_internal novalue _Xmach_vm_read_list
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_read_entry_t data_list;
		natural_t count;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_read_list_t __Request;
	typedef __Reply__mach_vm_read_list_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_read_list_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_read_list_t__defined */

	__DeclareRcvRpc(4805, "mach_vm_read_list")
	__BeforeRcvRpc(4805, "mach_vm_read_list")

#if	defined(__MIG_check__Request__mach_vm_read_list_t__defined)
	check_result = __MIG_check__Request__mach_vm_read_list_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_read_list_t__defined) */

	OutP->RetCode = mach_vm_read_list(In0P->Head.msgh_request_port, In0P->data_list, In0P->count);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	{   typedef struct { char data[4096]; } *sp;
	    * (sp) OutP->data_list = * (sp) In0P->data_list;
	}

	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(4805, "mach_vm_read_list")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_write_t__defined)
#define __MIG_check__Request__mach_vm_write_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_write_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_write_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_write_t__data__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__data__defined
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__data(a, f, c) \
	__NDR_convert__int_rep__mach_vm__vm_offset_t((vm_offset_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__data__defined
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__data(a, f, c) \
	__NDR_convert__int_rep__vm_offset_t((vm_offset_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_write_t__data__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_write_t__dataCnt__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__dataCnt__defined
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__dataCnt(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__dataCnt__defined
#define	__NDR_convert__int_rep__Request__mach_vm_write_t__dataCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_write_t__dataCnt__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_write_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_write_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_write_t__data__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__data__defined
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__data(a, f, c) \
	__NDR_convert__char_rep__mach_vm__vm_offset_t((vm_offset_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__data__defined
#define	__NDR_convert__char_rep__Request__mach_vm_write_t__data(a, f, c) \
	__NDR_convert__char_rep__vm_offset_t((vm_offset_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_write_t__data__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_write_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_write_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_write_t__data__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__data__defined
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__data(a, f, c) \
	__NDR_convert__float_rep__mach_vm__vm_offset_t((vm_offset_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__data__defined
#define	__NDR_convert__float_rep__Request__mach_vm_write_t__data(a, f, c) \
	__NDR_convert__float_rep__vm_offset_t((vm_offset_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_write_t__data__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_write_t(__attribute__((__unused__)) __Request__mach_vm_write_t *In0P)
{

	typedef __Request__mach_vm_write_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->data.type != MACH_MSG_OOL_DESCRIPTOR)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_write_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_write_t__data__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_write_t__dataCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_write_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_write_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_write_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_write_t__dataCnt__defined)
		__NDR_convert__int_rep__Request__mach_vm_write_t__dataCnt(&In0P->dataCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_write_t__dataCnt__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_write_t__data__defined)
		__NDR_convert__int_rep__Request__mach_vm_write_t__data((vm_offset_t)(In0P->data.address), In0P->NDR.int_rep, In0P->dataCnt);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_write_t__data__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_write_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_write_t__data__defined) || \
	0
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_write_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_write_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_write_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_write_t__data__defined)
		__NDR_convert__char_rep__Request__mach_vm_write_t__data((vm_offset_t)(In0P->data.address), In0P->NDR.char_rep, In0P->dataCnt);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_write_t__data__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_write_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_write_t__data__defined) || \
	0
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_write_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_write_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_write_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_write_t__data__defined)
		__NDR_convert__float_rep__Request__mach_vm_write_t__data((vm_offset_t)(In0P->data.address), In0P->NDR.float_rep, In0P->dataCnt);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_write_t__data__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_write_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_write */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_write
(
	vm_map_t target_task,
	mach_vm_address_t address,
	vm_offset_t data,
	mach_msg_type_number_t dataCnt
);

/* Routine mach_vm_write */
mig_internal novalue _Xmach_vm_write
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t data;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_msg_type_number_t dataCnt;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_write_t __Request;
	typedef __Reply__mach_vm_write_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_write_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_write_t__defined */

	__DeclareRcvRpc(4806, "mach_vm_write")
	__BeforeRcvRpc(4806, "mach_vm_write")

#if	defined(__MIG_check__Request__mach_vm_write_t__defined)
	check_result = __MIG_check__Request__mach_vm_write_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_write_t__defined) */

	OutP->RetCode = mach_vm_write(In0P->Head.msgh_request_port, In0P->address, (vm_offset_t)(In0P->data.address), In0P->dataCnt);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(4806, "mach_vm_write")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_copy_t__defined)
#define __MIG_check__Request__mach_vm_copy_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_copy_t__source_address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_copy_t__source_address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_copy_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_copy_t__size__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_copy_t__source_address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_copy_t__source_address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_copy_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_copy_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_copy_t__source_address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__source_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__source_address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_copy_t__source_address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_copy_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_copy_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_copy_t(__attribute__((__unused__)) __Request__mach_vm_copy_t *In0P)
{

	typedef __Request__mach_vm_copy_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_copy_t__source_address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_copy_t__size__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_copy_t__source_address__defined)
		__NDR_convert__int_rep__Request__mach_vm_copy_t__source_address(&In0P->source_address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_copy_t__source_address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_copy_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_copy_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_copy_t__size__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address__defined)
		__NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address(&In0P->dest_address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_copy_t__dest_address__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_copy_t__source_address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_copy_t__size__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_copy_t__source_address__defined)
		__NDR_convert__char_rep__Request__mach_vm_copy_t__source_address(&In0P->source_address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_copy_t__source_address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_copy_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_copy_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_copy_t__size__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address__defined)
		__NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address(&In0P->dest_address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_copy_t__dest_address__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_copy_t__source_address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_copy_t__size__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_copy_t__source_address__defined)
		__NDR_convert__float_rep__Request__mach_vm_copy_t__source_address(&In0P->source_address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_copy_t__source_address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_copy_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_copy_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_copy_t__size__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address__defined)
		__NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address(&In0P->dest_address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_copy_t__dest_address__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_copy_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_copy */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_copy
(
	vm_map_t target_task,
	mach_vm_address_t source_address,
	mach_vm_size_t size,
	mach_vm_address_t dest_address
);

/* Routine mach_vm_copy */
mig_internal novalue _Xmach_vm_copy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t source_address;
		mach_vm_size_t size;
		mach_vm_address_t dest_address;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_copy_t __Request;
	typedef __Reply__mach_vm_copy_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_copy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_copy_t__defined */

	__DeclareRcvRpc(4807, "mach_vm_copy")
	__BeforeRcvRpc(4807, "mach_vm_copy")

#if	defined(__MIG_check__Request__mach_vm_copy_t__defined)
	check_result = __MIG_check__Request__mach_vm_copy_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_copy_t__defined) */

	OutP->RetCode = mach_vm_copy(In0P->Head.msgh_request_port, In0P->source_address, In0P->size, In0P->dest_address);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(4807, "mach_vm_copy")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_read_overwrite_t__defined)
#define __MIG_check__Request__mach_vm_read_overwrite_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data__defined
#define	__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_read_overwrite_t(__attribute__((__unused__)) __Request__mach_vm_read_overwrite_t *In0P)
{

	typedef __Request__mach_vm_read_overwrite_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__size__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data__defined)
		__NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data(&In0P->data, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_read_overwrite_t__data__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__size__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data__defined)
		__NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data(&In0P->data, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_read_overwrite_t__data__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__size__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data__defined)
		__NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data(&In0P->data, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_read_overwrite_t__data__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_read_overwrite_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_read_overwrite */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_read_overwrite
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	mach_vm_address_t data,
	mach_vm_size_t *outsize
);

/* Routine mach_vm_read_overwrite */
mig_internal novalue _Xmach_vm_read_overwrite
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		mach_vm_address_t data;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_read_overwrite_t __Request;
	typedef __Reply__mach_vm_read_overwrite_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_read_overwrite_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_read_overwrite_t__defined */

	__DeclareRcvRpc(4808, "mach_vm_read_overwrite")
	__BeforeRcvRpc(4808, "mach_vm_read_overwrite")

#if	defined(__MIG_check__Request__mach_vm_read_overwrite_t__defined)
	check_result = __MIG_check__Request__mach_vm_read_overwrite_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_read_overwrite_t__defined) */

	OutP->RetCode = mach_vm_read_overwrite(In0P->Head.msgh_request_port, In0P->address, In0P->size, In0P->data, &OutP->outsize);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(4808, "mach_vm_read_overwrite")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_msync_t__defined)
#define __MIG_check__Request__mach_vm_msync_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_msync_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_msync_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_msync_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_msync_t__size__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_sync_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_sync_t((vm_sync_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_sync_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__int_rep__vm_sync_t((vm_sync_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_msync_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_msync_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_msync_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_msync_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_sync_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_sync_t((vm_sync_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_sync_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__char_rep__vm_sync_t((vm_sync_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_msync_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_msync_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_msync_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_msync_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_sync_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_sync_t((vm_sync_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_sync_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__float_rep__vm_sync_t((vm_sync_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_msync_t(__attribute__((__unused__)) __Request__mach_vm_msync_t *In0P)
{

	typedef __Request__mach_vm_msync_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_msync_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_msync_t__size__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_msync_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_msync_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_msync_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_msync_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_msync_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_msync_t__size__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags__defined)
		__NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags(&In0P->sync_flags, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_msync_t__sync_flags__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_msync_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_msync_t__size__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_msync_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_msync_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_msync_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_msync_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_msync_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_msync_t__size__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags__defined)
		__NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags(&In0P->sync_flags, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_msync_t__sync_flags__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_msync_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_msync_t__size__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_msync_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_msync_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_msync_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_msync_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_msync_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_msync_t__size__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags__defined)
		__NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags(&In0P->sync_flags, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_msync_t__sync_flags__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_msync_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_msync */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_msync
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	vm_sync_t sync_flags
);

/* Routine mach_vm_msync */
mig_internal novalue _Xmach_vm_msync
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		vm_sync_t sync_flags;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_msync_t __Request;
	typedef __Reply__mach_vm_msync_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_msync_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_msync_t__defined */

	__DeclareRcvRpc(4809, "mach_vm_msync")
	__BeforeRcvRpc(4809, "mach_vm_msync")

#if	defined(__MIG_check__Request__mach_vm_msync_t__defined)
	check_result = __MIG_check__Request__mach_vm_msync_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_msync_t__defined) */

	OutP->RetCode = mach_vm_msync(In0P->Head.msgh_request_port, In0P->address, In0P->size, In0P->sync_flags);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(4809, "mach_vm_msync")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_behavior_set_t__defined)
#define __MIG_check__Request__mach_vm_behavior_set_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_behavior_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_behavior_t((vm_behavior_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_behavior_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__int_rep__vm_behavior_t((vm_behavior_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_behavior_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_behavior_t((vm_behavior_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_behavior_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__char_rep__vm_behavior_t((vm_behavior_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_behavior_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_behavior_t((vm_behavior_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_behavior_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__float_rep__vm_behavior_t((vm_behavior_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior__defined
#define	__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_behavior_set_t(__attribute__((__unused__)) __Request__mach_vm_behavior_set_t *In0P)
{

	typedef __Request__mach_vm_behavior_set_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_behavior_set_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_behavior_set_t__size__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior__defined)
		__NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior(&In0P->new_behavior, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_behavior_set_t__new_behavior__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_behavior_set_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_behavior_set_t__size__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior__defined)
		__NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior(&In0P->new_behavior, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_behavior_set_t__new_behavior__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_behavior_set_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_behavior_set_t__size__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior__defined)
		__NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior(&In0P->new_behavior, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_behavior_set_t__new_behavior__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_behavior_set_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_behavior_set */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_behavior_set
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	vm_behavior_t new_behavior
);

/* Routine mach_vm_behavior_set */
mig_internal novalue _Xmach_vm_behavior_set
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		vm_behavior_t new_behavior;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_behavior_set_t __Request;
	typedef __Reply__mach_vm_behavior_set_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_behavior_set_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_behavior_set_t__defined */

	__DeclareRcvRpc(4810, "mach_vm_behavior_set")
	__BeforeRcvRpc(4810, "mach_vm_behavior_set")

#if	defined(__MIG_check__Request__mach_vm_behavior_set_t__defined)
	check_result = __MIG_check__Request__mach_vm_behavior_set_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_behavior_set_t__defined) */

	OutP->RetCode = mach_vm_behavior_set(In0P->Head.msgh_request_port, In0P->address, In0P->size, In0P->new_behavior);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(4810, "mach_vm_behavior_set")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_map_t__defined)
#define __MIG_check__Request__mach_vm_map_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_map_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_map_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_map_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_map_t__size__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_map_t__mask__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__int_rep__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_map_t__mask__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_map_t__flags__defined
#if	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_map_t__flags__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_map_t__offset__defined
#if	defined(__NDR_convert__int_rep__mach_vm__memory_object_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__int_rep__mach_vm__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__memory_object_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__int_rep__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_map_t__offset__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_map_t__copy__defined
#if	defined(__NDR_convert__int_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__copy__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__copy(a, f) \
	__NDR_convert__int_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__copy__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__copy(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_map_t__copy__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__int_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_map_t__max_protection__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__int_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_map_t__max_protection__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_map_t__inheritance__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_inherit_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_inherit_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__int_rep__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_map_t__inheritance__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_map_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_map_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_map_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_map_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_map_t__mask__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__char_rep__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_map_t__mask__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_map_t__flags__defined
#if	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_map_t__flags__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_map_t__offset__defined
#if	defined(__NDR_convert__char_rep__mach_vm__memory_object_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__char_rep__mach_vm__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__memory_object_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__char_rep__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_map_t__offset__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_map_t__copy__defined
#if	defined(__NDR_convert__char_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__copy__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__copy(a, f) \
	__NDR_convert__char_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__copy__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__copy(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_map_t__copy__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__char_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_map_t__max_protection__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__char_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_map_t__max_protection__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_map_t__inheritance__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_inherit_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_inherit_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__char_rep__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_map_t__inheritance__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_map_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_map_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_map_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_map_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_map_t__mask__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__float_rep__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__mask__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__mask(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_map_t__mask__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_map_t__flags__defined
#if	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__flags__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__flags(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_map_t__flags__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_map_t__offset__defined
#if	defined(__NDR_convert__float_rep__mach_vm__memory_object_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__float_rep__mach_vm__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__memory_object_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__float_rep__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__offset__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__offset(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_map_t__offset__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_map_t__copy__defined
#if	defined(__NDR_convert__float_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__copy__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__copy(a, f) \
	__NDR_convert__float_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__copy__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__copy(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_map_t__copy__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__float_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_map_t__max_protection__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__float_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_map_t__max_protection__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_map_t__inheritance__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_inherit_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_inherit_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__float_rep__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_map_t__inheritance__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_map_t(__attribute__((__unused__)) __Request__mach_vm_map_t *In0P)
{

	typedef __Request__mach_vm_map_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->object.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->object.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_map_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_map_t__size__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_map_t__mask__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_map_t__flags__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_map_t__offset__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_map_t__copy__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_map_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_map_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_map_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_map_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_map_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_map_t__size__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_map_t__mask__defined)
		__NDR_convert__int_rep__Request__mach_vm_map_t__mask(&In0P->mask, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_map_t__mask__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_map_t__flags__defined)
		__NDR_convert__int_rep__Request__mach_vm_map_t__flags(&In0P->flags, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_map_t__flags__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_map_t__offset__defined)
		__NDR_convert__int_rep__Request__mach_vm_map_t__offset(&In0P->offset, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_map_t__offset__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_map_t__copy__defined)
		__NDR_convert__int_rep__Request__mach_vm_map_t__copy(&In0P->copy, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_map_t__copy__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection__defined)
		__NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection(&In0P->cur_protection, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_map_t__cur_protection__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection__defined)
		__NDR_convert__int_rep__Request__mach_vm_map_t__max_protection(&In0P->max_protection, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_map_t__max_protection__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance__defined)
		__NDR_convert__int_rep__Request__mach_vm_map_t__inheritance(&In0P->inheritance, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_map_t__inheritance__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_map_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_map_t__size__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_map_t__mask__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_map_t__flags__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_map_t__offset__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_map_t__copy__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_map_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_map_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_map_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_map_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_map_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_map_t__size__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_map_t__mask__defined)
		__NDR_convert__char_rep__Request__mach_vm_map_t__mask(&In0P->mask, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_map_t__mask__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_map_t__flags__defined)
		__NDR_convert__char_rep__Request__mach_vm_map_t__flags(&In0P->flags, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_map_t__flags__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_map_t__offset__defined)
		__NDR_convert__char_rep__Request__mach_vm_map_t__offset(&In0P->offset, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_map_t__offset__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_map_t__copy__defined)
		__NDR_convert__char_rep__Request__mach_vm_map_t__copy(&In0P->copy, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_map_t__copy__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection__defined)
		__NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection(&In0P->cur_protection, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_map_t__cur_protection__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection__defined)
		__NDR_convert__char_rep__Request__mach_vm_map_t__max_protection(&In0P->max_protection, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_map_t__max_protection__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance__defined)
		__NDR_convert__char_rep__Request__mach_vm_map_t__inheritance(&In0P->inheritance, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_map_t__inheritance__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_map_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_map_t__size__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_map_t__mask__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_map_t__flags__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_map_t__offset__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_map_t__copy__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_map_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_map_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_map_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_map_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_map_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_map_t__size__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_map_t__mask__defined)
		__NDR_convert__float_rep__Request__mach_vm_map_t__mask(&In0P->mask, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_map_t__mask__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_map_t__flags__defined)
		__NDR_convert__float_rep__Request__mach_vm_map_t__flags(&In0P->flags, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_map_t__flags__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_map_t__offset__defined)
		__NDR_convert__float_rep__Request__mach_vm_map_t__offset(&In0P->offset, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_map_t__offset__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_map_t__copy__defined)
		__NDR_convert__float_rep__Request__mach_vm_map_t__copy(&In0P->copy, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_map_t__copy__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection__defined)
		__NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection(&In0P->cur_protection, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_map_t__cur_protection__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection__defined)
		__NDR_convert__float_rep__Request__mach_vm_map_t__max_protection(&In0P->max_protection, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_map_t__max_protection__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance__defined)
		__NDR_convert__float_rep__Request__mach_vm_map_t__inheritance(&In0P->inheritance, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_map_t__inheritance__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_map_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_map */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_map
(
	vm_task_entry_t target_task,
	mach_vm_address_t *address,
	mach_vm_size_t size,
	mach_vm_offset_t mask,
	int flags,
	mem_entry_name_port_t object,
	memory_object_offset_t offset,
	boolean_t copy,
	vm_prot_t cur_protection,
	vm_prot_t max_protection,
	vm_inherit_t inheritance
);

/* Routine mach_vm_map */
mig_internal novalue _Xmach_vm_map
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t object;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		mach_vm_offset_t mask;
		int flags;
		memory_object_offset_t offset;
		boolean_t copy;
		vm_prot_t cur_protection;
		vm_prot_t max_protection;
		vm_inherit_t inheritance;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_map_t __Request;
	typedef __Reply__mach_vm_map_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_map_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_map_t__defined */

	__DeclareRcvRpc(4811, "mach_vm_map")
	__BeforeRcvRpc(4811, "mach_vm_map")

#if	defined(__MIG_check__Request__mach_vm_map_t__defined)
	check_result = __MIG_check__Request__mach_vm_map_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_map_t__defined) */

	OutP->RetCode = mach_vm_map(In0P->Head.msgh_request_port, &In0P->address, In0P->size, In0P->mask, In0P->flags, In0P->object.name, In0P->offset, In0P->copy, In0P->cur_protection, In0P->max_protection, In0P->inheritance);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->address = In0P->address;

	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(4811, "mach_vm_map")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_machine_attribute_t__defined)
#define __MIG_check__Request__mach_vm_machine_attribute_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_machine_attribute_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_machine_attribute_t((vm_machine_attribute_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_machine_attribute_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__int_rep__vm_machine_attribute_t((vm_machine_attribute_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_machine_attribute_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_machine_attribute_t((vm_machine_attribute_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_machine_attribute_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__char_rep__vm_machine_attribute_t((vm_machine_attribute_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_machine_attribute_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_machine_attribute_t((vm_machine_attribute_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_machine_attribute_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__float_rep__vm_machine_attribute_t((vm_machine_attribute_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_machine_attribute_t(__attribute__((__unused__)) __Request__mach_vm_machine_attribute_t *In0P)
{

	typedef __Request__mach_vm_machine_attribute_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__size__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute__defined)
		__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute(&In0P->attribute, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__attribute__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value__defined)
		__NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value(&In0P->value, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_machine_attribute_t__value__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__size__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute__defined)
		__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute(&In0P->attribute, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__attribute__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value__defined)
		__NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value(&In0P->value, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_machine_attribute_t__value__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__size__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute__defined)
		__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute(&In0P->attribute, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__attribute__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value__defined)
		__NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value(&In0P->value, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_machine_attribute_t__value__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_machine_attribute_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_machine_attribute */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_machine_attribute
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	vm_machine_attribute_t attribute,
	vm_machine_attribute_val_t *value
);

/* Routine mach_vm_machine_attribute */
mig_internal novalue _Xmach_vm_machine_attribute
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		vm_machine_attribute_t attribute;
		vm_machine_attribute_val_t value;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_machine_attribute_t __Request;
	typedef __Reply__mach_vm_machine_attribute_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_machine_attribute_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_machine_attribute_t__defined */

	__DeclareRcvRpc(4812, "mach_vm_machine_attribute")
	__BeforeRcvRpc(4812, "mach_vm_machine_attribute")

#if	defined(__MIG_check__Request__mach_vm_machine_attribute_t__defined)
	check_result = __MIG_check__Request__mach_vm_machine_attribute_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_machine_attribute_t__defined) */

	OutP->RetCode = mach_vm_machine_attribute(In0P->Head.msgh_request_port, In0P->address, In0P->size, In0P->attribute, &In0P->value);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->value = In0P->value;

	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(4812, "mach_vm_machine_attribute")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_remap_t__defined)
#define __MIG_check__Request__mach_vm_remap_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_remap_t__target_address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_remap_t__target_address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_remap_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_remap_t__size__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_remap_t__mask__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__int_rep__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_remap_t__mask__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_remap_t__anywhere__defined
#if	defined(__NDR_convert__int_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__anywhere__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__anywhere(a, f) \
	__NDR_convert__int_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__anywhere__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__anywhere(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_remap_t__anywhere__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_remap_t__src_address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_remap_t__src_address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_remap_t__copy__defined
#if	defined(__NDR_convert__int_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__copy__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__copy(a, f) \
	__NDR_convert__int_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__copy__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__copy(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_remap_t__copy__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_inherit_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_inherit_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__int_rep__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_remap_t__target_address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_remap_t__target_address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_remap_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_remap_t__size__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_remap_t__mask__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__char_rep__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_remap_t__mask__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_remap_t__anywhere__defined
#if	defined(__NDR_convert__char_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__anywhere__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__anywhere(a, f) \
	__NDR_convert__char_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__anywhere__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__anywhere(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_remap_t__anywhere__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_remap_t__src_address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_remap_t__src_address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_remap_t__copy__defined
#if	defined(__NDR_convert__char_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__copy__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__copy(a, f) \
	__NDR_convert__char_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__copy__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__copy(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_remap_t__copy__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_inherit_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_inherit_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__char_rep__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_remap_t__target_address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_remap_t__target_address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_remap_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__size__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_remap_t__size__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_remap_t__mask__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__float_rep__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__mask__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__mask(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_remap_t__mask__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_remap_t__anywhere__defined
#if	defined(__NDR_convert__float_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__anywhere__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__anywhere(a, f) \
	__NDR_convert__float_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__anywhere__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__anywhere(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_remap_t__anywhere__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_remap_t__src_address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__src_address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__src_address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_remap_t__src_address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_remap_t__copy__defined
#if	defined(__NDR_convert__float_rep__mach_vm__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__copy__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__copy(a, f) \
	__NDR_convert__float_rep__mach_vm__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__copy__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__copy(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_remap_t__copy__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_inherit_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_inherit_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__float_rep__vm_inherit_t((vm_inherit_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance__defined
#define	__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_remap_t(__attribute__((__unused__)) __Request__mach_vm_remap_t *In0P)
{

	typedef __Request__mach_vm_remap_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->src_task.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->src_task.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__target_address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__size__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__mask__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__anywhere__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__src_address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__copy__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__target_address__defined)
		__NDR_convert__int_rep__Request__mach_vm_remap_t__target_address(&In0P->target_address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_remap_t__target_address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__size__defined)
		__NDR_convert__int_rep__Request__mach_vm_remap_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_remap_t__size__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__mask__defined)
		__NDR_convert__int_rep__Request__mach_vm_remap_t__mask(&In0P->mask, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_remap_t__mask__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__anywhere__defined)
		__NDR_convert__int_rep__Request__mach_vm_remap_t__anywhere(&In0P->anywhere, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_remap_t__anywhere__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__src_address__defined)
		__NDR_convert__int_rep__Request__mach_vm_remap_t__src_address(&In0P->src_address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_remap_t__src_address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__copy__defined)
		__NDR_convert__int_rep__Request__mach_vm_remap_t__copy(&In0P->copy, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_remap_t__copy__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance__defined)
		__NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance(&In0P->inheritance, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_remap_t__inheritance__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__target_address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__size__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__mask__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__anywhere__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__src_address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__copy__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__target_address__defined)
		__NDR_convert__char_rep__Request__mach_vm_remap_t__target_address(&In0P->target_address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_remap_t__target_address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__size__defined)
		__NDR_convert__char_rep__Request__mach_vm_remap_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_remap_t__size__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__mask__defined)
		__NDR_convert__char_rep__Request__mach_vm_remap_t__mask(&In0P->mask, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_remap_t__mask__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__anywhere__defined)
		__NDR_convert__char_rep__Request__mach_vm_remap_t__anywhere(&In0P->anywhere, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_remap_t__anywhere__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__src_address__defined)
		__NDR_convert__char_rep__Request__mach_vm_remap_t__src_address(&In0P->src_address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_remap_t__src_address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__copy__defined)
		__NDR_convert__char_rep__Request__mach_vm_remap_t__copy(&In0P->copy, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_remap_t__copy__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance__defined)
		__NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance(&In0P->inheritance, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_remap_t__inheritance__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__target_address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__size__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__mask__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__anywhere__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__src_address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__copy__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__target_address__defined)
		__NDR_convert__float_rep__Request__mach_vm_remap_t__target_address(&In0P->target_address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_remap_t__target_address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__size__defined)
		__NDR_convert__float_rep__Request__mach_vm_remap_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_remap_t__size__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__mask__defined)
		__NDR_convert__float_rep__Request__mach_vm_remap_t__mask(&In0P->mask, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_remap_t__mask__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__anywhere__defined)
		__NDR_convert__float_rep__Request__mach_vm_remap_t__anywhere(&In0P->anywhere, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_remap_t__anywhere__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__src_address__defined)
		__NDR_convert__float_rep__Request__mach_vm_remap_t__src_address(&In0P->src_address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_remap_t__src_address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__copy__defined)
		__NDR_convert__float_rep__Request__mach_vm_remap_t__copy(&In0P->copy, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_remap_t__copy__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance__defined)
		__NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance(&In0P->inheritance, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_remap_t__inheritance__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_remap_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_remap */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_remap
(
	vm_map_t target_task,
	mach_vm_address_t *target_address,
	mach_vm_size_t size,
	mach_vm_offset_t mask,
	boolean_t anywhere,
	vm_map_t src_task,
	mach_vm_address_t src_address,
	boolean_t copy,
	vm_prot_t *cur_protection,
	vm_prot_t *max_protection,
	vm_inherit_t inheritance
);

/* Routine mach_vm_remap */
mig_internal novalue _Xmach_vm_remap
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t src_task;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_vm_address_t target_address;
		mach_vm_size_t size;
		mach_vm_offset_t mask;
		boolean_t anywhere;
		mach_vm_address_t src_address;
		boolean_t copy;
		vm_inherit_t inheritance;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_remap_t __Request;
	typedef __Reply__mach_vm_remap_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_remap_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_remap_t__defined */

	__DeclareRcvRpc(4813, "mach_vm_remap")
	__BeforeRcvRpc(4813, "mach_vm_remap")

#if	defined(__MIG_check__Request__mach_vm_remap_t__defined)
	check_result = __MIG_check__Request__mach_vm_remap_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_remap_t__defined) */

	OutP->RetCode = mach_vm_remap(In0P->Head.msgh_request_port, &In0P->target_address, In0P->size, In0P->mask, In0P->anywhere, In0P->src_task.name, In0P->src_address, In0P->copy, &OutP->cur_protection, &OutP->max_protection, In0P->inheritance);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->target_address = In0P->target_address;

	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(4813, "mach_vm_remap")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_page_query_t__defined)
#define __MIG_check__Request__mach_vm_page_query_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_page_query_t__offset__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__int_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__int_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__int_rep__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__int_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__int_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_page_query_t__offset__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_page_query_t__offset__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__char_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__char_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__char_rep__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__char_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__char_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_page_query_t__offset__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_page_query_t__offset__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__float_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__float_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__float_rep__mach_vm_offset_t((mach_vm_offset_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__float_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_page_query_t__offset__defined
#define	__NDR_convert__float_rep__Request__mach_vm_page_query_t__offset(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_page_query_t__offset__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_page_query_t(__attribute__((__unused__)) __Request__mach_vm_page_query_t *In0P)
{

	typedef __Request__mach_vm_page_query_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_page_query_t__offset__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_page_query_t__offset__defined)
		__NDR_convert__int_rep__Request__mach_vm_page_query_t__offset(&In0P->offset, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_page_query_t__offset__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_page_query_t__offset__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_page_query_t__offset__defined)
		__NDR_convert__char_rep__Request__mach_vm_page_query_t__offset(&In0P->offset, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_page_query_t__offset__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_page_query_t__offset__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_page_query_t__offset__defined)
		__NDR_convert__float_rep__Request__mach_vm_page_query_t__offset(&In0P->offset, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_page_query_t__offset__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_page_query_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_page_query */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_page_query
(
	vm_map_t target_map,
	mach_vm_offset_t offset,
	integer_t *disposition,
	integer_t *ref_count
);

/* Routine mach_vm_page_query */
mig_internal novalue _Xmach_vm_page_query
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_offset_t offset;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_page_query_t __Request;
	typedef __Reply__mach_vm_page_query_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_page_query_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_page_query_t__defined */

	__DeclareRcvRpc(4814, "mach_vm_page_query")
	__BeforeRcvRpc(4814, "mach_vm_page_query")

#if	defined(__MIG_check__Request__mach_vm_page_query_t__defined)
	check_result = __MIG_check__Request__mach_vm_page_query_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_page_query_t__defined) */

	OutP->RetCode = mach_vm_page_query(In0P->Head.msgh_request_port, In0P->offset, &OutP->disposition, &OutP->ref_count);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(4814, "mach_vm_page_query")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_region_recurse_t__defined)
#define __MIG_check__Request__mach_vm_region_recurse_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#if	defined(__NDR_convert__int_rep__mach_vm__natural_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__int_rep__mach_vm__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__int_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__int_rep__mach_vm__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__int_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_region_recurse_t__infoCnt__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__infoCnt__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__infoCnt(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__infoCnt__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__infoCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_region_recurse_t__infoCnt__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#if	defined(__NDR_convert__char_rep__mach_vm__natural_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__char_rep__mach_vm__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__char_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__char_rep__mach_vm__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__char_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#if	defined(__NDR_convert__float_rep__mach_vm__natural_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__float_rep__mach_vm__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__float_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__float_rep__mach_vm__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__float_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_region_recurse_t(__attribute__((__unused__)) __Request__mach_vm_region_recurse_t *In0P)
{

	typedef __Request__mach_vm_region_recurse_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__infoCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_region_recurse_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined)
		__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth(&In0P->nesting_depth, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__infoCnt__defined)
		__NDR_convert__int_rep__Request__mach_vm_region_recurse_t__infoCnt(&In0P->infoCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_region_recurse_t__infoCnt__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined) || \
	0
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_region_recurse_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined)
		__NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth(&In0P->nesting_depth, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined) || \
	0
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_region_recurse_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined)
		__NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth(&In0P->nesting_depth, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_region_recurse_t__nesting_depth__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_region_recurse_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_region_recurse */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_region_recurse
(
	vm_map_t target_task,
	mach_vm_address_t *address,
	mach_vm_size_t *size,
	natural_t *nesting_depth,
	vm_region_recurse_info_t info,
	mach_msg_type_number_t *infoCnt
);

/* Routine mach_vm_region_recurse */
mig_internal novalue _Xmach_vm_region_recurse
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		natural_t nesting_depth;
		mach_msg_type_number_t infoCnt;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_region_recurse_t __Request;
	typedef __Reply__mach_vm_region_recurse_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_region_recurse_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_region_recurse_t__defined */

	__DeclareRcvRpc(4815, "mach_vm_region_recurse")
	__BeforeRcvRpc(4815, "mach_vm_region_recurse")

#if	defined(__MIG_check__Request__mach_vm_region_recurse_t__defined)
	check_result = __MIG_check__Request__mach_vm_region_recurse_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_region_recurse_t__defined) */

	OutP->infoCnt = 19;
	if (In0P->infoCnt < OutP->infoCnt)
		OutP->infoCnt = In0P->infoCnt;

	OutP->RetCode = mach_vm_region_recurse(In0P->Head.msgh_request_port, &In0P->address, &OutP->size, &In0P->nesting_depth, OutP->info, &OutP->infoCnt);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->address = In0P->address;

	OutP->nesting_depth = In0P->nesting_depth;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply) - 76) + (((4 * OutP->infoCnt)));

	__AfterRcvRpc(4815, "mach_vm_region_recurse")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_region_t__defined)
#define __MIG_check__Request__mach_vm_region_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_region_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_region_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_region_t__flavor__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_region_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_region_flavor_t((vm_region_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_region_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__int_rep__vm_region_flavor_t((vm_region_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_region_t__flavor__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_region_t__infoCnt__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__infoCnt__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__infoCnt(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__infoCnt__defined
#define	__NDR_convert__int_rep__Request__mach_vm_region_t__infoCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_region_t__infoCnt__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_region_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_region_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_region_t__flavor__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_region_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_region_flavor_t((vm_region_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_region_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__char_rep__vm_region_flavor_t((vm_region_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__char_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_region_t__flavor__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_region_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_region_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_region_t__flavor__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_region_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_region_flavor_t((vm_region_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_region_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__float_rep__vm_region_flavor_t((vm_region_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor__defined
#define	__NDR_convert__float_rep__Request__mach_vm_region_t__flavor(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_region_t__flavor__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_region_t(__attribute__((__unused__)) __Request__mach_vm_region_t *In0P)
{

	typedef __Request__mach_vm_region_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_region_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_region_t__flavor__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_region_t__infoCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_region_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_region_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_region_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_region_t__flavor__defined)
		__NDR_convert__int_rep__Request__mach_vm_region_t__flavor(&In0P->flavor, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_region_t__flavor__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_region_t__infoCnt__defined)
		__NDR_convert__int_rep__Request__mach_vm_region_t__infoCnt(&In0P->infoCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_region_t__infoCnt__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_region_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_region_t__flavor__defined) || \
	0
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_region_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_region_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_region_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_region_t__flavor__defined)
		__NDR_convert__char_rep__Request__mach_vm_region_t__flavor(&In0P->flavor, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_region_t__flavor__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_region_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_region_t__flavor__defined) || \
	0
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_region_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_region_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_region_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_region_t__flavor__defined)
		__NDR_convert__float_rep__Request__mach_vm_region_t__flavor(&In0P->flavor, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_region_t__flavor__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_region_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_region */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_region
(
	vm_map_t target_task,
	mach_vm_address_t *address,
	mach_vm_size_t *size,
	vm_region_flavor_t flavor,
	vm_region_info_t info,
	mach_msg_type_number_t *infoCnt,
	mach_port_t *object_name
);

/* Routine mach_vm_region */
mig_internal novalue _Xmach_vm_region
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		vm_region_flavor_t flavor;
		mach_msg_type_number_t infoCnt;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_region_t __Request;
	typedef __Reply__mach_vm_region_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_region_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_region_t__defined */

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t object_nameTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		17,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(4816, "mach_vm_region")
	__BeforeRcvRpc(4816, "mach_vm_region")

#if	defined(__MIG_check__Request__mach_vm_region_t__defined)
	check_result = __MIG_check__Request__mach_vm_region_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_region_t__defined) */

#if	UseStaticTemplates
	OutP->object_name = object_nameTemplate;
#else	/* UseStaticTemplates */
	OutP->object_name.disposition = 17;
	OutP->object_name.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	OutP->infoCnt = 10;
	if (In0P->infoCnt < OutP->infoCnt)
		OutP->infoCnt = In0P->infoCnt;

	RetCode = mach_vm_region(In0P->Head.msgh_request_port, &In0P->address, &OutP->size, In0P->flavor, OutP->info, &OutP->infoCnt, &OutP->object_name.name);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->address = In0P->address;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply) - 40) + (((4 * OutP->infoCnt)));

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(4816, "mach_vm_region")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request___mach_make_memory_entry_t__defined)
#define __MIG_check__Request___mach_make_memory_entry_t__defined
#ifndef __NDR_convert__int_rep__Request___mach_make_memory_entry_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__memory_object_size_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__memory_object_size_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__int_rep__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request___mach_make_memory_entry_t__size__defined */

#ifndef __NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset__defined
#if	defined(__NDR_convert__int_rep__mach_vm__memory_object_offset_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__int_rep__mach_vm__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__memory_object_offset_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__int_rep__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset__defined */

#ifndef __NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__int_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission__defined */

#ifndef __NDR_convert__char_rep__Request___mach_make_memory_entry_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__memory_object_size_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__memory_object_size_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__char_rep__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request___mach_make_memory_entry_t__size__defined */

#ifndef __NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset__defined
#if	defined(__NDR_convert__char_rep__mach_vm__memory_object_offset_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__char_rep__mach_vm__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__memory_object_offset_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__char_rep__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset__defined */

#ifndef __NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__char_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission__defined */

#ifndef __NDR_convert__float_rep__Request___mach_make_memory_entry_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__memory_object_size_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__memory_object_size_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__float_rep__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request___mach_make_memory_entry_t__size__defined */

#ifndef __NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset__defined
#if	defined(__NDR_convert__float_rep__mach_vm__memory_object_offset_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__float_rep__mach_vm__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__memory_object_offset_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__float_rep__memory_object_offset_t((memory_object_offset_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset__defined */

#ifndef __NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__float_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission__defined
#define	__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission__defined */


mig_internal kern_return_t __MIG_check__Request___mach_make_memory_entry_t(__attribute__((__unused__)) __Request___mach_make_memory_entry_t *In0P)
{

	typedef __Request___mach_make_memory_entry_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->parent_handle.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->parent_handle.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request___mach_make_memory_entry_t__size__defined) || \
	defined(__NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset__defined) || \
	defined(__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request___mach_make_memory_entry_t__size__defined)
		__NDR_convert__int_rep__Request___mach_make_memory_entry_t__size(&In0P->size, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request___mach_make_memory_entry_t__size__defined */
#if defined(__NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset__defined)
		__NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset(&In0P->offset, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request___mach_make_memory_entry_t__offset__defined */
#if defined(__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission__defined)
		__NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission(&In0P->permission, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request___mach_make_memory_entry_t__permission__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request___mach_make_memory_entry_t__size__defined) || \
	defined(__NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset__defined) || \
	defined(__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request___mach_make_memory_entry_t__size__defined)
		__NDR_convert__char_rep__Request___mach_make_memory_entry_t__size(&In0P->size, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request___mach_make_memory_entry_t__size__defined */
#if defined(__NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset__defined)
		__NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset(&In0P->offset, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request___mach_make_memory_entry_t__offset__defined */
#if defined(__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission__defined)
		__NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission(&In0P->permission, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request___mach_make_memory_entry_t__permission__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request___mach_make_memory_entry_t__size__defined) || \
	defined(__NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset__defined) || \
	defined(__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request___mach_make_memory_entry_t__size__defined)
		__NDR_convert__float_rep__Request___mach_make_memory_entry_t__size(&In0P->size, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request___mach_make_memory_entry_t__size__defined */
#if defined(__NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset__defined)
		__NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset(&In0P->offset, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request___mach_make_memory_entry_t__offset__defined */
#if defined(__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission__defined)
		__NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission(&In0P->permission, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request___mach_make_memory_entry_t__permission__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request___mach_make_memory_entry_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine _mach_make_memory_entry */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _mach_make_memory_entry
(
	vm_map_t target_task,
	memory_object_size_t *size,
	memory_object_offset_t offset,
	vm_prot_t permission,
	mem_entry_name_port_move_send_t *object_handle,
	mem_entry_name_port_t parent_handle
);

/* Routine _mach_make_memory_entry */
mig_internal novalue _X_mach_make_memory_entry
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t parent_handle;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		memory_object_size_t size;
		memory_object_offset_t offset;
		vm_prot_t permission;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request___mach_make_memory_entry_t __Request;
	typedef __Reply___mach_make_memory_entry_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request___mach_make_memory_entry_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request___mach_make_memory_entry_t__defined */

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t object_handleTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		17,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(4817, "_mach_make_memory_entry")
	__BeforeRcvRpc(4817, "_mach_make_memory_entry")

#if	defined(__MIG_check__Request___mach_make_memory_entry_t__defined)
	check_result = __MIG_check__Request___mach_make_memory_entry_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request___mach_make_memory_entry_t__defined) */

#if	UseStaticTemplates
	OutP->object_handle = object_handleTemplate;
#else	/* UseStaticTemplates */
	OutP->object_handle.disposition = 17;
	OutP->object_handle.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = _mach_make_memory_entry(In0P->Head.msgh_request_port, &In0P->size, In0P->offset, In0P->permission, &OutP->object_handle.name, In0P->parent_handle.name);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->size = In0P->size;

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(4817, "_mach_make_memory_entry")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__mach_vm_subsystem__
#if !defined(__MIG_check__Request__mach_vm_purgable_control_t__defined)
#define __MIG_check__Request__mach_vm_purgable_control_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_purgable_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_purgable_t((vm_purgable_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_purgable_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__int_rep__vm_purgable_t((vm_purgable_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control__defined */

#ifndef __NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state__defined
#if	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_purgable_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_purgable_t((vm_purgable_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_purgable_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__char_rep__vm_purgable_t((vm_purgable_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control__defined */

#ifndef __NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state__defined
#if	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_purgable_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_purgable_t((vm_purgable_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_purgable_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__float_rep__vm_purgable_t((vm_purgable_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control__defined */

#ifndef __NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state__defined
#if	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state__defined */


mig_internal kern_return_t __MIG_check__Request__mach_vm_purgable_control_t(__attribute__((__unused__)) __Request__mach_vm_purgable_control_t *In0P)
{

	typedef __Request__mach_vm_purgable_control_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control__defined) || \
	defined(__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address__defined)
		__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address(&In0P->address, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_purgable_control_t__address__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control__defined)
		__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control(&In0P->control, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_purgable_control_t__control__defined */
#if defined(__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state__defined)
		__NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state(&In0P->state, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_vm_purgable_control_t__state__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control__defined) || \
	defined(__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address__defined)
		__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address(&In0P->address, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_purgable_control_t__address__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control__defined)
		__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control(&In0P->control, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_purgable_control_t__control__defined */
#if defined(__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state__defined)
		__NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state(&In0P->state, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__mach_vm_purgable_control_t__state__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control__defined) || \
	defined(__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address__defined)
		__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address(&In0P->address, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_purgable_control_t__address__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control__defined)
		__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control(&In0P->control, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_purgable_control_t__control__defined */
#if defined(__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state__defined)
		__NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state(&In0P->state, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__mach_vm_purgable_control_t__state__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_vm_purgable_control_t__defined) */
#endif /* __MIG_check__Request__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_purgable_control */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_purgable_control
(
	vm_map_t target_task,
	mach_vm_address_t address,
	vm_purgable_t control,
	int *state
);

/* Routine mach_vm_purgable_control */
mig_internal novalue _Xmach_vm_purgable_control
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		vm_purgable_t control;
		int state;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_vm_purgable_control_t __Request;
	typedef __Reply__mach_vm_purgable_control_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_vm_purgable_control_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_vm_purgable_control_t__defined */

	__DeclareRcvRpc(4818, "mach_vm_purgable_control")
	__BeforeRcvRpc(4818, "mach_vm_purgable_control")

#if	defined(__MIG_check__Request__mach_vm_purgable_control_t__defined)
	check_result = __MIG_check__Request__mach_vm_purgable_control_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_vm_purgable_control_t__defined) */

	OutP->RetCode = mach_vm_purgable_control(In0P->Head.msgh_request_port, In0P->address, In0P->control, &In0P->state);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->state = In0P->state;

	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(4818, "mach_vm_purgable_control")
}


extern boolean_t mach_vm_server(
		mach_msg_header_t *InHeadP,
		mach_msg_header_t *OutHeadP);

extern mig_routine_t mach_vm_server_routine(
		mach_msg_header_t *InHeadP);


/* Description of this subsystem, for use in direct RPC */
const struct mach_vm_subsystem {
	mig_server_routine_t 	server;	/* Server routine */
	mach_msg_id_t	start;	/* Min routine number */
	mach_msg_id_t	end;	/* Max routine number + 1 */
	unsigned int	maxsize;	/* Max msg size */
	vm_address_t	reserved;	/* Reserved */
	struct routine_descriptor	/*Array of routine descriptors */
		routine[19];
} mach_vm_subsystem = {
	mach_vm_server_routine,
	4800,
	4819,
	(mach_msg_size_t)sizeof(union __ReplyUnion__mach_vm_subsystem),
	(vm_address_t)0,
	{
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_allocate, 5, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_allocate_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_deallocate, 5, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_deallocate_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_protect, 7, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_protect_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_inherit, 6, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_inherit_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_read, 7, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_read_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_read_list, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_read_list_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_write, 5, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_write_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_copy, 7, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_copy_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_read_overwrite, 8, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_read_overwrite_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_msync, 6, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_msync_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_behavior_set, 6, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_behavior_set_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_map, 14, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_map_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_machine_attribute, 7, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_machine_attribute_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_remap, 14, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_remap_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_page_query, 5, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_page_query_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_region_recurse, 6, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_region_recurse_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_region, 7, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_region_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _X_mach_make_memory_entry, 7, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply___mach_make_memory_entry_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_vm_purgable_control, 5, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_vm_purgable_control_t)},
	}
};

mig_external boolean_t mach_vm_server
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	register mig_routine_t routine;

	OutHeadP->msgh_bits = MACH_MSGH_BITS(MACH_MSGH_BITS_REPLY(InHeadP->msgh_bits), 0);
	OutHeadP->msgh_remote_port = InHeadP->msgh_reply_port;
	/* Minimal size: routine() will update it if different */
	OutHeadP->msgh_size = (mach_msg_size_t)sizeof(mig_reply_error_t);
	OutHeadP->msgh_local_port = MACH_PORT_NULL;
	OutHeadP->msgh_id = InHeadP->msgh_id + 100;

	if ((InHeadP->msgh_id > 4818) || (InHeadP->msgh_id < 4800) ||
	    ((routine = mach_vm_subsystem.routine[InHeadP->msgh_id - 4800].stub_routine) == 0)) {
		((mig_reply_error_t *)OutHeadP)->NDR = NDR_record;
		((mig_reply_error_t *)OutHeadP)->RetCode = MIG_BAD_ID;
		return FALSE;
	}
	(*routine) (InHeadP, OutHeadP);
	return TRUE;
}

mig_external mig_routine_t mach_vm_server_routine
	(mach_msg_header_t *InHeadP)
{
	register int msgh_id;

	msgh_id = InHeadP->msgh_id - 4800;

	if ((msgh_id > 18) || (msgh_id < 0))
		return 0;

	return mach_vm_subsystem.routine[msgh_id].stub_routine;
}
