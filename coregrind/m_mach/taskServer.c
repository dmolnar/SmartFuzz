/*
 * IDENTIFICATION:
 * stub generated Mon Jun 15 19:50:16 2009
 * with a MiG generated Tue Feb 19 02:01:43 PST 2008 by root@b75.local
 * OPTIONS: 
 */

/* Module task */

#define	__MIG_check__Request__task_subsystem__ 1
#define	__NDR_convert__Request__task_subsystem__ 1

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

#ifndef __Request__task_subsystem__defined
#define __Request__task_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_ports_descriptor_t ledgers;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t ledgersCnt;
		boolean_t inherit_memory;
	} __Request__task_create_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_terminate_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_threads_t;
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
		mach_msg_ool_ports_descriptor_t init_port_set;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t init_port_setCnt;
	} __Request__mach_ports_register_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__mach_ports_lookup_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_flavor_t flavor;
		mach_msg_type_number_t task_info_outCnt;
	} __Request__task_info_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_flavor_t flavor;
		mach_msg_type_number_t task_info_inCnt;
		integer_t task_info_in[10];
	} __Request__task_set_info_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_suspend_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_resume_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int which_port;
	} __Request__task_get_special_port_t;
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
		mach_msg_port_descriptor_t special_port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		int which_port;
	} __Request__task_set_special_port_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__thread_create_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		thread_state_flavor_t flavor;
		mach_msg_type_number_t new_stateCnt;
		natural_t new_state[144];
	} __Request__thread_create_running_t;
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
		mach_msg_port_descriptor_t new_port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		exception_mask_t exception_mask;
		exception_behavior_t behavior;
		thread_state_flavor_t new_flavor;
	} __Request__task_set_exception_ports_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		exception_mask_t exception_mask;
	} __Request__task_get_exception_ports_t;
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
		mach_msg_port_descriptor_t new_port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		exception_mask_t exception_mask;
		exception_behavior_t behavior;
		thread_state_flavor_t new_flavor;
	} __Request__task_swap_exception_ports_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int n_ulocks;
		int policy;
	} __Request__lock_set_create_t;
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
		mach_msg_port_descriptor_t lock_set;
		/* end of the kernel processed data */
	} __Request__lock_set_destroy_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int policy;
		int value;
	} __Request__semaphore_create_t;
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
		mach_msg_port_descriptor_t semaphore;
		/* end of the kernel processed data */
	} __Request__semaphore_destroy_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_policy_flavor_t flavor;
		mach_msg_type_number_t policy_infoCnt;
		integer_t policy_info[16];
	} __Request__task_policy_set_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_policy_flavor_t flavor;
		mach_msg_type_number_t policy_infoCnt;
		boolean_t get_default;
	} __Request__task_policy_get_t;
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
		mach_msg_port_descriptor_t reply;
		/* end of the kernel processed data */
	} __Request__task_sample_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		policy_t policy;
		mach_msg_type_number_t baseCnt;
		integer_t base[5];
		boolean_t set_limit;
		boolean_t change;
	} __Request__task_policy_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		vm_address_t routine_entry_pt;
		int routine_number;
	} __Request__task_set_emulation_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_get_emulation_vector_t;
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
		mach_msg_ool_descriptor_t emulation_vector;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		int vector_start;
		mach_msg_type_number_t emulation_vectorCnt;
	} __Request__task_set_emulation_vector_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		vm_address_t basepc;
		vm_address_t boundspc;
	} __Request__task_set_ras_pc_t;
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
		mach_msg_port_descriptor_t new_set;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		boolean_t assign_threads;
	} __Request__task_assign_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		boolean_t assign_threads;
	} __Request__task_assign_default_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_get_assignment_t;
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
		mach_msg_port_descriptor_t pset;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		policy_t policy;
		mach_msg_type_number_t baseCnt;
		integer_t base[5];
		mach_msg_type_number_t limitCnt;
		integer_t limit[1];
		boolean_t change;
	} __Request__task_set_policy_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Request__task_subsystem__defined */

/* typedefs for all replies */

#ifndef __Reply__task_subsystem__defined
#define __Reply__task_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t child_task;
		/* end of the kernel processed data */
	} __Reply__task_create_t;
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
	} __Reply__task_terminate_t;
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
		mach_msg_ool_ports_descriptor_t act_list;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t act_listCnt;
	} __Reply__task_threads_t;
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
	} __Reply__mach_ports_register_t;
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
		mach_msg_ool_ports_descriptor_t init_port_set;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t init_port_setCnt;
	} __Reply__mach_ports_lookup_t;
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
		mach_msg_type_number_t task_info_outCnt;
		integer_t task_info_out[10];
	} __Reply__task_info_t;
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
	} __Reply__task_set_info_t;
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
	} __Reply__task_suspend_t;
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
	} __Reply__task_resume_t;
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
		mach_msg_port_descriptor_t special_port;
		/* end of the kernel processed data */
	} __Reply__task_get_special_port_t;
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
	} __Reply__task_set_special_port_t;
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
		mach_msg_port_descriptor_t child_act;
		/* end of the kernel processed data */
	} __Reply__thread_create_t;
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
		mach_msg_port_descriptor_t child_act;
		/* end of the kernel processed data */
	} __Reply__thread_create_running_t;
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
	} __Reply__task_set_exception_ports_t;
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
		mach_msg_port_descriptor_t old_handlers[32];
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t masksCnt;
		exception_mask_t masks[32];
		exception_behavior_t old_behaviors[32];
		thread_state_flavor_t old_flavors[32];
	} __Reply__task_get_exception_ports_t;
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
		mach_msg_port_descriptor_t old_handlerss[32];
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t masksCnt;
		exception_mask_t masks[32];
		exception_behavior_t old_behaviors[32];
		thread_state_flavor_t old_flavors[32];
	} __Reply__task_swap_exception_ports_t;
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
		mach_msg_port_descriptor_t new_lock_set;
		/* end of the kernel processed data */
	} __Reply__lock_set_create_t;
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
	} __Reply__lock_set_destroy_t;
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
		mach_msg_port_descriptor_t semaphore;
		/* end of the kernel processed data */
	} __Reply__semaphore_create_t;
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
	} __Reply__semaphore_destroy_t;
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
	} __Reply__task_policy_set_t;
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
		mach_msg_type_number_t policy_infoCnt;
		integer_t policy_info[16];
		boolean_t get_default;
	} __Reply__task_policy_get_t;
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
	} __Reply__task_sample_t;
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
	} __Reply__task_policy_t;
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
	} __Reply__task_set_emulation_t;
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
		mach_msg_ool_descriptor_t emulation_vector;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		int vector_start;
		mach_msg_type_number_t emulation_vectorCnt;
	} __Reply__task_get_emulation_vector_t;
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
	} __Reply__task_set_emulation_vector_t;
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
	} __Reply__task_set_ras_pc_t;
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
	} __Reply__task_assign_t;
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
	} __Reply__task_assign_default_t;
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
		mach_msg_port_descriptor_t assigned_set;
		/* end of the kernel processed data */
	} __Reply__task_get_assignment_t;
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
	} __Reply__task_set_policy_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Reply__task_subsystem__defined */


/* union of all replies */

#ifndef __ReplyUnion__task_subsystem__defined
#define __ReplyUnion__task_subsystem__defined
union __ReplyUnion__task_subsystem {
	__Reply__task_create_t Reply_task_create;
	__Reply__task_terminate_t Reply_task_terminate;
	__Reply__task_threads_t Reply_task_threads;
	__Reply__mach_ports_register_t Reply_mach_ports_register;
	__Reply__mach_ports_lookup_t Reply_mach_ports_lookup;
	__Reply__task_info_t Reply_task_info;
	__Reply__task_set_info_t Reply_task_set_info;
	__Reply__task_suspend_t Reply_task_suspend;
	__Reply__task_resume_t Reply_task_resume;
	__Reply__task_get_special_port_t Reply_task_get_special_port;
	__Reply__task_set_special_port_t Reply_task_set_special_port;
	__Reply__thread_create_t Reply_thread_create;
	__Reply__thread_create_running_t Reply_thread_create_running;
	__Reply__task_set_exception_ports_t Reply_task_set_exception_ports;
	__Reply__task_get_exception_ports_t Reply_task_get_exception_ports;
	__Reply__task_swap_exception_ports_t Reply_task_swap_exception_ports;
	__Reply__lock_set_create_t Reply_lock_set_create;
	__Reply__lock_set_destroy_t Reply_lock_set_destroy;
	__Reply__semaphore_create_t Reply_semaphore_create;
	__Reply__semaphore_destroy_t Reply_semaphore_destroy;
	__Reply__task_policy_set_t Reply_task_policy_set;
	__Reply__task_policy_get_t Reply_task_policy_get;
	__Reply__task_sample_t Reply_task_sample;
	__Reply__task_policy_t Reply_task_policy;
	__Reply__task_set_emulation_t Reply_task_set_emulation;
	__Reply__task_get_emulation_vector_t Reply_task_get_emulation_vector;
	__Reply__task_set_emulation_vector_t Reply_task_set_emulation_vector;
	__Reply__task_set_ras_pc_t Reply_task_set_ras_pc;
	__Reply__task_assign_t Reply_task_assign;
	__Reply__task_assign_default_t Reply_task_assign_default;
	__Reply__task_get_assignment_t Reply_task_get_assignment;
	__Reply__task_set_policy_t Reply_task_set_policy;
};
#endif /* __RequestUnion__task_subsystem__defined */
/* Forward Declarations */


mig_internal novalue _Xtask_create
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_terminate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_threads
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_ports_register
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xmach_ports_lookup
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_info
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_set_info
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_suspend
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_resume
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_get_special_port
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_set_special_port
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xthread_create
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xthread_create_running
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_set_exception_ports
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_get_exception_ports
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_swap_exception_ports
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xlock_set_create
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xlock_set_destroy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xsemaphore_create
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xsemaphore_destroy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_policy_set
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_policy_get
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_sample
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_policy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_set_emulation
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_get_emulation_vector
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_set_emulation_vector
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_set_ras_pc
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_assign
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_assign_default
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_get_assignment
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xtask_set_policy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);


#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_create_t__defined)
#define __MIG_check__Request__task_create_t__defined
#ifndef __NDR_convert__int_rep__Request__task_create_t__ledgersCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_create_t__ledgersCnt__defined
#define	__NDR_convert__int_rep__Request__task_create_t__ledgersCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_create_t__ledgersCnt__defined
#define	__NDR_convert__int_rep__Request__task_create_t__ledgersCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_create_t__ledgersCnt__defined */

#ifndef __NDR_convert__int_rep__Request__task_create_t__inherit_memory__defined
#if	defined(__NDR_convert__int_rep__task__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_create_t__inherit_memory__defined
#define	__NDR_convert__int_rep__Request__task_create_t__inherit_memory(a, f) \
	__NDR_convert__int_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_create_t__inherit_memory__defined
#define	__NDR_convert__int_rep__Request__task_create_t__inherit_memory(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_create_t__inherit_memory__defined */

#ifndef __NDR_convert__char_rep__Request__task_create_t__inherit_memory__defined
#if	defined(__NDR_convert__char_rep__task__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_create_t__inherit_memory__defined
#define	__NDR_convert__char_rep__Request__task_create_t__inherit_memory(a, f) \
	__NDR_convert__char_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_create_t__inherit_memory__defined
#define	__NDR_convert__char_rep__Request__task_create_t__inherit_memory(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_create_t__inherit_memory__defined */

#ifndef __NDR_convert__float_rep__Request__task_create_t__inherit_memory__defined
#if	defined(__NDR_convert__float_rep__task__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_create_t__inherit_memory__defined
#define	__NDR_convert__float_rep__Request__task_create_t__inherit_memory(a, f) \
	__NDR_convert__float_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_create_t__inherit_memory__defined
#define	__NDR_convert__float_rep__Request__task_create_t__inherit_memory(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_create_t__inherit_memory__defined */


mig_internal kern_return_t __MIG_check__Request__task_create_t(__attribute__((__unused__)) __Request__task_create_t *In0P)
{

	typedef __Request__task_create_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->ledgers.type != MACH_MSG_OOL_PORTS_DESCRIPTOR ||
	    In0P->ledgers.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_create_t__ledgersCnt__defined) || \
	defined(__NDR_convert__int_rep__Request__task_create_t__inherit_memory__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_create_t__ledgersCnt__defined)
		__NDR_convert__int_rep__Request__task_create_t__ledgersCnt(&In0P->ledgersCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_create_t__ledgersCnt__defined */
#if defined(__NDR_convert__int_rep__Request__task_create_t__inherit_memory__defined)
		__NDR_convert__int_rep__Request__task_create_t__inherit_memory(&In0P->inherit_memory, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_create_t__inherit_memory__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Request__task_create_t__inherit_memory__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_create_t__inherit_memory__defined)
		__NDR_convert__char_rep__Request__task_create_t__inherit_memory(&In0P->inherit_memory, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_create_t__inherit_memory__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Request__task_create_t__inherit_memory__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_create_t__inherit_memory__defined)
		__NDR_convert__float_rep__Request__task_create_t__inherit_memory(&In0P->inherit_memory, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_create_t__inherit_memory__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_create_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_create */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_create
(
	task_t target_task,
	ledger_array_t ledgers,
	mach_msg_type_number_t ledgersCnt,
	boolean_t inherit_memory,
	task_t *child_task
);

/* Routine task_create */
mig_internal novalue _Xtask_create
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_ports_descriptor_t ledgers;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t ledgersCnt;
		boolean_t inherit_memory;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_create_t __Request;
	typedef __Reply__task_create_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_create_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_create_t__defined */

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t child_taskTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(3400, "task_create")
	__BeforeRcvRpc(3400, "task_create")

#if	defined(__MIG_check__Request__task_create_t__defined)
	check_result = __MIG_check__Request__task_create_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_create_t__defined) */

#if	UseStaticTemplates
	OutP->child_task = child_taskTemplate;
#else	/* UseStaticTemplates */
	OutP->child_task.disposition = 19;
	OutP->child_task.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = task_create(In0P->Head.msgh_request_port, (ledger_array_t)(In0P->ledgers.address), In0P->ledgersCnt, In0P->inherit_memory, &OutP->child_task.name);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(3400, "task_create")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_terminate_t__defined)
#define __MIG_check__Request__task_terminate_t__defined

mig_internal kern_return_t __MIG_check__Request__task_terminate_t(__attribute__((__unused__)) __Request__task_terminate_t *In0P)
{

	typedef __Request__task_terminate_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_terminate_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_terminate */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_terminate
(
	task_t target_task
);

/* Routine task_terminate */
mig_internal novalue _Xtask_terminate
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_terminate_t __Request;
	typedef __Reply__task_terminate_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_terminate_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_terminate_t__defined */

	__DeclareRcvRpc(3401, "task_terminate")
	__BeforeRcvRpc(3401, "task_terminate")

#if	defined(__MIG_check__Request__task_terminate_t__defined)
	check_result = __MIG_check__Request__task_terminate_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_terminate_t__defined) */

	OutP->RetCode = task_terminate(In0P->Head.msgh_request_port);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3401, "task_terminate")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_threads_t__defined)
#define __MIG_check__Request__task_threads_t__defined

mig_internal kern_return_t __MIG_check__Request__task_threads_t(__attribute__((__unused__)) __Request__task_threads_t *In0P)
{

	typedef __Request__task_threads_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_threads_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_threads */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_threads
(
	task_t target_task,
	thread_act_array_t *act_list,
	mach_msg_type_number_t *act_listCnt
);

/* Routine task_threads */
mig_internal novalue _Xtask_threads
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_threads_t __Request;
	typedef __Reply__task_threads_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_threads_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_threads_t__defined */

#if	UseStaticTemplates
	const static mach_msg_ool_ports_descriptor_t act_listTemplate = {
		/* addr = */		(void *)0,
		/* coun = */		0,
		/* deal = */		FALSE,
		/* copy is meaningful only in overwrite mode */
		/* copy = */		MACH_MSG_PHYSICAL_COPY,
		/* disp = */		19,
		/* type = */		MACH_MSG_OOL_PORTS_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(3402, "task_threads")
	__BeforeRcvRpc(3402, "task_threads")

#if	defined(__MIG_check__Request__task_threads_t__defined)
	check_result = __MIG_check__Request__task_threads_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_threads_t__defined) */

#if	UseStaticTemplates
	OutP->act_list = act_listTemplate;
#else	/* UseStaticTemplates */
	OutP->act_list.disposition = 19;
	OutP->act_list.deallocate =  FALSE;
	OutP->act_list.type = MACH_MSG_OOL_PORTS_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = task_threads(In0P->Head.msgh_request_port, (thread_act_array_t *)&(OutP->act_list.address), &OutP->act_listCnt);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}
	OutP->act_list.count = OutP->act_listCnt;


	OutP->NDR = NDR_record;


	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(3402, "task_threads")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__mach_ports_register_t__defined)
#define __MIG_check__Request__mach_ports_register_t__defined
#ifndef __NDR_convert__int_rep__Request__mach_ports_register_t__init_port_setCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__mach_ports_register_t__init_port_setCnt__defined
#define	__NDR_convert__int_rep__Request__mach_ports_register_t__init_port_setCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__mach_ports_register_t__init_port_setCnt__defined
#define	__NDR_convert__int_rep__Request__mach_ports_register_t__init_port_setCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__mach_ports_register_t__init_port_setCnt__defined */


mig_internal kern_return_t __MIG_check__Request__mach_ports_register_t(__attribute__((__unused__)) __Request__mach_ports_register_t *In0P)
{

	typedef __Request__mach_ports_register_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->init_port_set.type != MACH_MSG_OOL_PORTS_DESCRIPTOR ||
	    In0P->init_port_set.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__mach_ports_register_t__init_port_setCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__mach_ports_register_t__init_port_setCnt__defined)
		__NDR_convert__int_rep__Request__mach_ports_register_t__init_port_setCnt(&In0P->init_port_setCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__mach_ports_register_t__init_port_setCnt__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_ports_register_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_ports_register */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_ports_register
(
	task_t target_task,
	mach_port_array_t init_port_set,
	mach_msg_type_number_t init_port_setCnt
);

/* Routine mach_ports_register */
mig_internal novalue _Xmach_ports_register
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_ports_descriptor_t init_port_set;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t init_port_setCnt;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_ports_register_t __Request;
	typedef __Reply__mach_ports_register_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_ports_register_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_ports_register_t__defined */

	__DeclareRcvRpc(3403, "mach_ports_register")
	__BeforeRcvRpc(3403, "mach_ports_register")

#if	defined(__MIG_check__Request__mach_ports_register_t__defined)
	check_result = __MIG_check__Request__mach_ports_register_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_ports_register_t__defined) */

	OutP->RetCode = mach_ports_register(In0P->Head.msgh_request_port, (mach_port_array_t)(In0P->init_port_set.address), In0P->init_port_setCnt);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3403, "mach_ports_register")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__mach_ports_lookup_t__defined)
#define __MIG_check__Request__mach_ports_lookup_t__defined

mig_internal kern_return_t __MIG_check__Request__mach_ports_lookup_t(__attribute__((__unused__)) __Request__mach_ports_lookup_t *In0P)
{

	typedef __Request__mach_ports_lookup_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__mach_ports_lookup_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_ports_lookup */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_ports_lookup
(
	task_t target_task,
	mach_port_array_t *init_port_set,
	mach_msg_type_number_t *init_port_setCnt
);

/* Routine mach_ports_lookup */
mig_internal novalue _Xmach_ports_lookup
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__mach_ports_lookup_t __Request;
	typedef __Reply__mach_ports_lookup_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__mach_ports_lookup_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__mach_ports_lookup_t__defined */

#if	UseStaticTemplates
	const static mach_msg_ool_ports_descriptor_t init_port_setTemplate = {
		/* addr = */		(void *)0,
		/* coun = */		0,
		/* deal = */		FALSE,
		/* copy is meaningful only in overwrite mode */
		/* copy = */		MACH_MSG_PHYSICAL_COPY,
		/* disp = */		19,
		/* type = */		MACH_MSG_OOL_PORTS_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(3404, "mach_ports_lookup")
	__BeforeRcvRpc(3404, "mach_ports_lookup")

#if	defined(__MIG_check__Request__mach_ports_lookup_t__defined)
	check_result = __MIG_check__Request__mach_ports_lookup_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__mach_ports_lookup_t__defined) */

#if	UseStaticTemplates
	OutP->init_port_set = init_port_setTemplate;
#else	/* UseStaticTemplates */
	OutP->init_port_set.disposition = 19;
	OutP->init_port_set.deallocate =  FALSE;
	OutP->init_port_set.type = MACH_MSG_OOL_PORTS_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = mach_ports_lookup(In0P->Head.msgh_request_port, (mach_port_array_t *)&(OutP->init_port_set.address), &OutP->init_port_setCnt);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}
	OutP->init_port_set.count = OutP->init_port_setCnt;


	OutP->NDR = NDR_record;


	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(3404, "mach_ports_lookup")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_info_t__defined)
#define __MIG_check__Request__task_info_t__defined
#ifndef __NDR_convert__int_rep__Request__task_info_t__flavor__defined
#if	defined(__NDR_convert__int_rep__task__task_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__int_rep__task__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__int_rep__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_info_t__flavor__defined */

#ifndef __NDR_convert__int_rep__Request__task_info_t__task_info_outCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_info_t__task_info_outCnt__defined
#define	__NDR_convert__int_rep__Request__task_info_t__task_info_outCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_info_t__task_info_outCnt__defined
#define	__NDR_convert__int_rep__Request__task_info_t__task_info_outCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_info_t__task_info_outCnt__defined */

#ifndef __NDR_convert__char_rep__Request__task_info_t__flavor__defined
#if	defined(__NDR_convert__char_rep__task__task_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__char_rep__task__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__char_rep__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_info_t__flavor__defined */

#ifndef __NDR_convert__float_rep__Request__task_info_t__flavor__defined
#if	defined(__NDR_convert__float_rep__task__task_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__float_rep__task__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__float_rep__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_info_t__flavor(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_info_t__flavor__defined */


mig_internal kern_return_t __MIG_check__Request__task_info_t(__attribute__((__unused__)) __Request__task_info_t *In0P)
{

	typedef __Request__task_info_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_info_t__flavor__defined) || \
	defined(__NDR_convert__int_rep__Request__task_info_t__task_info_outCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_info_t__flavor__defined)
		__NDR_convert__int_rep__Request__task_info_t__flavor(&In0P->flavor, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_info_t__flavor__defined */
#if defined(__NDR_convert__int_rep__Request__task_info_t__task_info_outCnt__defined)
		__NDR_convert__int_rep__Request__task_info_t__task_info_outCnt(&In0P->task_info_outCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_info_t__task_info_outCnt__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_info_t__flavor__defined) || \
	0
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_info_t__flavor__defined)
		__NDR_convert__char_rep__Request__task_info_t__flavor(&In0P->flavor, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_info_t__flavor__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_info_t__flavor__defined) || \
	0
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_info_t__flavor__defined)
		__NDR_convert__float_rep__Request__task_info_t__flavor(&In0P->flavor, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_info_t__flavor__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_info_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_info */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_info
(
	task_name_t target_task,
	task_flavor_t flavor,
	task_info_t task_info_out,
	mach_msg_type_number_t *task_info_outCnt
);

/* Routine task_info */
mig_internal novalue _Xtask_info
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_flavor_t flavor;
		mach_msg_type_number_t task_info_outCnt;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_info_t __Request;
	typedef __Reply__task_info_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_info_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_info_t__defined */

	__DeclareRcvRpc(3405, "task_info")
	__BeforeRcvRpc(3405, "task_info")

#if	defined(__MIG_check__Request__task_info_t__defined)
	check_result = __MIG_check__Request__task_info_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_info_t__defined) */

	OutP->task_info_outCnt = 10;
	if (In0P->task_info_outCnt < OutP->task_info_outCnt)
		OutP->task_info_outCnt = In0P->task_info_outCnt;

	OutP->RetCode = task_info(In0P->Head.msgh_request_port, In0P->flavor, OutP->task_info_out, &OutP->task_info_outCnt);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;

	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply) - 40) + (((4 * OutP->task_info_outCnt)));

	__AfterRcvRpc(3405, "task_info")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_set_info_t__defined)
#define __MIG_check__Request__task_set_info_t__defined
#ifndef __NDR_convert__int_rep__Request__task_set_info_t__flavor__defined
#if	defined(__NDR_convert__int_rep__task__task_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__int_rep__task__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__int_rep__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_info_t__flavor__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_info_t__task_info_in__defined
#if	defined(__NDR_convert__int_rep__task__task_info_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__int_rep__task__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task_info_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__int_rep__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__integer_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__task__integer_t)
#elif	defined(__NDR_convert__int_rep__integer_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__integer_t)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_info_t__task_info_in__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_info_t__task_info_inCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_inCnt__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_inCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_inCnt__defined
#define	__NDR_convert__int_rep__Request__task_set_info_t__task_info_inCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_info_t__task_info_inCnt__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_info_t__flavor__defined
#if	defined(__NDR_convert__char_rep__task__task_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__char_rep__task__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__char_rep__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_info_t__flavor__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_info_t__task_info_in__defined
#if	defined(__NDR_convert__char_rep__task__task_info_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__char_rep__task__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task_info_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__char_rep__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__integer_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__task__integer_t)
#elif	defined(__NDR_convert__char_rep__integer_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__integer_t)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__char_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_info_t__task_info_in__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_info_t__flavor__defined
#if	defined(__NDR_convert__float_rep__task__task_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__float_rep__task__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__float_rep__task_flavor_t((task_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__flavor(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_info_t__flavor__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_info_t__task_info_in__defined
#if	defined(__NDR_convert__float_rep__task__task_info_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__float_rep__task__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task_info_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__float_rep__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__integer_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__task__integer_t)
#elif	defined(__NDR_convert__float_rep__integer_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__integer_t)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in__defined
#define	__NDR_convert__float_rep__Request__task_set_info_t__task_info_in(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_info_t__task_info_in__defined */


mig_internal kern_return_t __MIG_check__Request__task_set_info_t(__attribute__((__unused__)) __Request__task_set_info_t *In0P)
{

	typedef __Request__task_set_info_t __Request;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	msgh_size = In0P->Head.msgh_size;
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (msgh_size < (mach_msg_size_t)(sizeof(__Request) - 40)) ||  (msgh_size > (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Request__task_set_info_t__task_info_inCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Request__task_set_info_t__task_info_inCnt(&In0P->task_info_inCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_info_t__task_info_inCnt__defined */
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Request) - 40) + ((4 * In0P->task_info_inCnt)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_set_info_t__flavor__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_info_t__task_info_in__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_info_t__task_info_inCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_set_info_t__flavor__defined)
		__NDR_convert__int_rep__Request__task_set_info_t__flavor(&In0P->flavor, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_info_t__flavor__defined */
#if defined(__NDR_convert__int_rep__Request__task_set_info_t__task_info_in__defined)
		__NDR_convert__int_rep__Request__task_set_info_t__task_info_in(&In0P->task_info_in, In0P->NDR.int_rep, In0P->task_info_inCnt);
#endif	/* __NDR_convert__int_rep__Request__task_set_info_t__task_info_in__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_set_info_t__flavor__defined) || \
	defined(__NDR_convert__char_rep__Request__task_set_info_t__task_info_in__defined) || \
	0
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_set_info_t__flavor__defined)
		__NDR_convert__char_rep__Request__task_set_info_t__flavor(&In0P->flavor, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_info_t__flavor__defined */
#if defined(__NDR_convert__char_rep__Request__task_set_info_t__task_info_in__defined)
		__NDR_convert__char_rep__Request__task_set_info_t__task_info_in(&In0P->task_info_in, In0P->NDR.char_rep, In0P->task_info_inCnt);
#endif	/* __NDR_convert__char_rep__Request__task_set_info_t__task_info_in__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_set_info_t__flavor__defined) || \
	defined(__NDR_convert__float_rep__Request__task_set_info_t__task_info_in__defined) || \
	0
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_set_info_t__flavor__defined)
		__NDR_convert__float_rep__Request__task_set_info_t__flavor(&In0P->flavor, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_info_t__flavor__defined */
#if defined(__NDR_convert__float_rep__Request__task_set_info_t__task_info_in__defined)
		__NDR_convert__float_rep__Request__task_set_info_t__task_info_in(&In0P->task_info_in, In0P->NDR.float_rep, In0P->task_info_inCnt);
#endif	/* __NDR_convert__float_rep__Request__task_set_info_t__task_info_in__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_set_info_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_info */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_set_info
(
	task_t target_task,
	task_flavor_t flavor,
	task_info_t task_info_in,
	mach_msg_type_number_t task_info_inCnt
);

/* Routine task_set_info */
mig_internal novalue _Xtask_set_info
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_flavor_t flavor;
		mach_msg_type_number_t task_info_inCnt;
		integer_t task_info_in[10];
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_set_info_t __Request;
	typedef __Reply__task_set_info_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_set_info_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_set_info_t__defined */

	__DeclareRcvRpc(3406, "task_set_info")
	__BeforeRcvRpc(3406, "task_set_info")

#if	defined(__MIG_check__Request__task_set_info_t__defined)
	check_result = __MIG_check__Request__task_set_info_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_set_info_t__defined) */

	OutP->RetCode = task_set_info(In0P->Head.msgh_request_port, In0P->flavor, In0P->task_info_in, In0P->task_info_inCnt);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3406, "task_set_info")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_suspend_t__defined)
#define __MIG_check__Request__task_suspend_t__defined

mig_internal kern_return_t __MIG_check__Request__task_suspend_t(__attribute__((__unused__)) __Request__task_suspend_t *In0P)
{

	typedef __Request__task_suspend_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_suspend_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_suspend */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_suspend
(
	task_t target_task
);

/* Routine task_suspend */
mig_internal novalue _Xtask_suspend
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_suspend_t __Request;
	typedef __Reply__task_suspend_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_suspend_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_suspend_t__defined */

	__DeclareRcvRpc(3407, "task_suspend")
	__BeforeRcvRpc(3407, "task_suspend")

#if	defined(__MIG_check__Request__task_suspend_t__defined)
	check_result = __MIG_check__Request__task_suspend_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_suspend_t__defined) */

	OutP->RetCode = task_suspend(In0P->Head.msgh_request_port);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3407, "task_suspend")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_resume_t__defined)
#define __MIG_check__Request__task_resume_t__defined

mig_internal kern_return_t __MIG_check__Request__task_resume_t(__attribute__((__unused__)) __Request__task_resume_t *In0P)
{

	typedef __Request__task_resume_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_resume_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_resume */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_resume
(
	task_t target_task
);

/* Routine task_resume */
mig_internal novalue _Xtask_resume
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_resume_t __Request;
	typedef __Reply__task_resume_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_resume_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_resume_t__defined */

	__DeclareRcvRpc(3408, "task_resume")
	__BeforeRcvRpc(3408, "task_resume")

#if	defined(__MIG_check__Request__task_resume_t__defined)
	check_result = __MIG_check__Request__task_resume_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_resume_t__defined) */

	OutP->RetCode = task_resume(In0P->Head.msgh_request_port);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3408, "task_resume")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_get_special_port_t__defined)
#define __MIG_check__Request__task_get_special_port_t__defined
#ifndef __NDR_convert__int_rep__Request__task_get_special_port_t__which_port__defined
#if	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__int_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__int_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__int_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__int_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_get_special_port_t__which_port__defined */

#ifndef __NDR_convert__char_rep__Request__task_get_special_port_t__which_port__defined
#if	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__char_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__char_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__char_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__char_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_get_special_port_t__which_port__defined */

#ifndef __NDR_convert__float_rep__Request__task_get_special_port_t__which_port__defined
#if	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__float_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__float_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__float_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_get_special_port_t__which_port__defined
#define	__NDR_convert__float_rep__Request__task_get_special_port_t__which_port(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_get_special_port_t__which_port__defined */


mig_internal kern_return_t __MIG_check__Request__task_get_special_port_t(__attribute__((__unused__)) __Request__task_get_special_port_t *In0P)
{

	typedef __Request__task_get_special_port_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_get_special_port_t__which_port__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_get_special_port_t__which_port__defined)
		__NDR_convert__int_rep__Request__task_get_special_port_t__which_port(&In0P->which_port, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_get_special_port_t__which_port__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_get_special_port_t__which_port__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_get_special_port_t__which_port__defined)
		__NDR_convert__char_rep__Request__task_get_special_port_t__which_port(&In0P->which_port, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_get_special_port_t__which_port__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_get_special_port_t__which_port__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_get_special_port_t__which_port__defined)
		__NDR_convert__float_rep__Request__task_get_special_port_t__which_port(&In0P->which_port, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_get_special_port_t__which_port__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_get_special_port_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_get_special_port */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_get_special_port
(
	task_t task,
	int which_port,
	mach_port_t *special_port
);

/* Routine task_get_special_port */
mig_internal novalue _Xtask_get_special_port
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int which_port;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_get_special_port_t __Request;
	typedef __Reply__task_get_special_port_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_get_special_port_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_get_special_port_t__defined */

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t special_portTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(3409, "task_get_special_port")
	__BeforeRcvRpc(3409, "task_get_special_port")

#if	defined(__MIG_check__Request__task_get_special_port_t__defined)
	check_result = __MIG_check__Request__task_get_special_port_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_get_special_port_t__defined) */

#if	UseStaticTemplates
	OutP->special_port = special_portTemplate;
#else	/* UseStaticTemplates */
	OutP->special_port.disposition = 19;
	OutP->special_port.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = task_get_special_port(In0P->Head.msgh_request_port, In0P->which_port, &OutP->special_port.name);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(3409, "task_get_special_port")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_set_special_port_t__defined)
#define __MIG_check__Request__task_set_special_port_t__defined
#ifndef __NDR_convert__int_rep__Request__task_set_special_port_t__which_port__defined
#if	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__int_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__int_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__int_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__int_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_special_port_t__which_port__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_special_port_t__which_port__defined
#if	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__char_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__char_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__char_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__char_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_special_port_t__which_port__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_special_port_t__which_port__defined
#if	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__float_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__float_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__float_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_special_port_t__which_port__defined
#define	__NDR_convert__float_rep__Request__task_set_special_port_t__which_port(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_special_port_t__which_port__defined */


mig_internal kern_return_t __MIG_check__Request__task_set_special_port_t(__attribute__((__unused__)) __Request__task_set_special_port_t *In0P)
{

	typedef __Request__task_set_special_port_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->special_port.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->special_port.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_set_special_port_t__which_port__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_set_special_port_t__which_port__defined)
		__NDR_convert__int_rep__Request__task_set_special_port_t__which_port(&In0P->which_port, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_special_port_t__which_port__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_set_special_port_t__which_port__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_set_special_port_t__which_port__defined)
		__NDR_convert__char_rep__Request__task_set_special_port_t__which_port(&In0P->which_port, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_special_port_t__which_port__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_set_special_port_t__which_port__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_set_special_port_t__which_port__defined)
		__NDR_convert__float_rep__Request__task_set_special_port_t__which_port(&In0P->which_port, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_special_port_t__which_port__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_set_special_port_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_special_port */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_set_special_port
(
	task_t task,
	int which_port,
	mach_port_t special_port
);

/* Routine task_set_special_port */
mig_internal novalue _Xtask_set_special_port
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t special_port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		int which_port;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_set_special_port_t __Request;
	typedef __Reply__task_set_special_port_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_set_special_port_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_set_special_port_t__defined */

	__DeclareRcvRpc(3410, "task_set_special_port")
	__BeforeRcvRpc(3410, "task_set_special_port")

#if	defined(__MIG_check__Request__task_set_special_port_t__defined)
	check_result = __MIG_check__Request__task_set_special_port_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_set_special_port_t__defined) */

	OutP->RetCode = task_set_special_port(In0P->Head.msgh_request_port, In0P->which_port, In0P->special_port.name);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3410, "task_set_special_port")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__thread_create_t__defined)
#define __MIG_check__Request__thread_create_t__defined

mig_internal kern_return_t __MIG_check__Request__thread_create_t(__attribute__((__unused__)) __Request__thread_create_t *In0P)
{

	typedef __Request__thread_create_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__thread_create_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_create */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t thread_create
(
	task_t parent_task,
	thread_act_t *child_act
);

/* Routine thread_create */
mig_internal novalue _Xthread_create
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__thread_create_t __Request;
	typedef __Reply__thread_create_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__thread_create_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__thread_create_t__defined */

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t child_actTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(3411, "thread_create")
	__BeforeRcvRpc(3411, "thread_create")

#if	defined(__MIG_check__Request__thread_create_t__defined)
	check_result = __MIG_check__Request__thread_create_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__thread_create_t__defined) */

#if	UseStaticTemplates
	OutP->child_act = child_actTemplate;
#else	/* UseStaticTemplates */
	OutP->child_act.disposition = 19;
	OutP->child_act.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = thread_create(In0P->Head.msgh_request_port, &OutP->child_act.name);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(3411, "thread_create")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__thread_create_running_t__defined)
#define __MIG_check__Request__thread_create_running_t__defined
#ifndef __NDR_convert__int_rep__Request__thread_create_running_t__flavor__defined
#if	defined(__NDR_convert__int_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__int_rep__task__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__int_rep__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__thread_create_running_t__flavor__defined */

#ifndef __NDR_convert__int_rep__Request__thread_create_running_t__new_state__defined
#if	defined(__NDR_convert__int_rep__task__thread_state_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__int_rep__task__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_state_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__int_rep__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__natural_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__int_rep__task__natural_t)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__int_rep__natural_t)
#elif	defined(__NDR_convert__int_rep__task__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__int_rep__task__uint32_t)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__int_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__thread_create_running_t__new_state__defined */

#ifndef __NDR_convert__int_rep__Request__thread_create_running_t__new_stateCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_stateCnt__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_stateCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_stateCnt__defined
#define	__NDR_convert__int_rep__Request__thread_create_running_t__new_stateCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__thread_create_running_t__new_stateCnt__defined */

#ifndef __NDR_convert__char_rep__Request__thread_create_running_t__flavor__defined
#if	defined(__NDR_convert__char_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__char_rep__task__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__char_rep__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__thread_create_running_t__flavor__defined */

#ifndef __NDR_convert__char_rep__Request__thread_create_running_t__new_state__defined
#if	defined(__NDR_convert__char_rep__task__thread_state_t__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__char_rep__task__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_state_t__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__char_rep__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__natural_t__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__char_rep__task__natural_t)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__char_rep__natural_t)
#elif	defined(__NDR_convert__char_rep__task__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__char_rep__task__uint32_t)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__char_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__char_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__thread_create_running_t__new_state__defined */

#ifndef __NDR_convert__float_rep__Request__thread_create_running_t__flavor__defined
#if	defined(__NDR_convert__float_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__float_rep__task__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__float_rep__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__flavor(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__thread_create_running_t__flavor__defined */

#ifndef __NDR_convert__float_rep__Request__thread_create_running_t__new_state__defined
#if	defined(__NDR_convert__float_rep__task__thread_state_t__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__float_rep__task__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_state_t__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__float_rep__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__natural_t__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__float_rep__task__natural_t)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__float_rep__natural_t)
#elif	defined(__NDR_convert__float_rep__task__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__float_rep__task__uint32_t)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state__defined
#define	__NDR_convert__float_rep__Request__thread_create_running_t__new_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__float_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__thread_create_running_t__new_state__defined */


mig_internal kern_return_t __MIG_check__Request__thread_create_running_t(__attribute__((__unused__)) __Request__thread_create_running_t *In0P)
{

	typedef __Request__thread_create_running_t __Request;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	msgh_size = In0P->Head.msgh_size;
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (msgh_size < (mach_msg_size_t)(sizeof(__Request) - 576)) ||  (msgh_size > (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Request__thread_create_running_t__new_stateCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Request__thread_create_running_t__new_stateCnt(&In0P->new_stateCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__thread_create_running_t__new_stateCnt__defined */
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Request) - 576) + ((4 * In0P->new_stateCnt)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__thread_create_running_t__flavor__defined) || \
	defined(__NDR_convert__int_rep__Request__thread_create_running_t__new_state__defined) || \
	defined(__NDR_convert__int_rep__Request__thread_create_running_t__new_stateCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__thread_create_running_t__flavor__defined)
		__NDR_convert__int_rep__Request__thread_create_running_t__flavor(&In0P->flavor, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__thread_create_running_t__flavor__defined */
#if defined(__NDR_convert__int_rep__Request__thread_create_running_t__new_state__defined)
		__NDR_convert__int_rep__Request__thread_create_running_t__new_state(&In0P->new_state, In0P->NDR.int_rep, In0P->new_stateCnt);
#endif	/* __NDR_convert__int_rep__Request__thread_create_running_t__new_state__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__thread_create_running_t__flavor__defined) || \
	defined(__NDR_convert__char_rep__Request__thread_create_running_t__new_state__defined) || \
	0
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__thread_create_running_t__flavor__defined)
		__NDR_convert__char_rep__Request__thread_create_running_t__flavor(&In0P->flavor, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__thread_create_running_t__flavor__defined */
#if defined(__NDR_convert__char_rep__Request__thread_create_running_t__new_state__defined)
		__NDR_convert__char_rep__Request__thread_create_running_t__new_state(&In0P->new_state, In0P->NDR.char_rep, In0P->new_stateCnt);
#endif	/* __NDR_convert__char_rep__Request__thread_create_running_t__new_state__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__thread_create_running_t__flavor__defined) || \
	defined(__NDR_convert__float_rep__Request__thread_create_running_t__new_state__defined) || \
	0
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__thread_create_running_t__flavor__defined)
		__NDR_convert__float_rep__Request__thread_create_running_t__flavor(&In0P->flavor, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__thread_create_running_t__flavor__defined */
#if defined(__NDR_convert__float_rep__Request__thread_create_running_t__new_state__defined)
		__NDR_convert__float_rep__Request__thread_create_running_t__new_state(&In0P->new_state, In0P->NDR.float_rep, In0P->new_stateCnt);
#endif	/* __NDR_convert__float_rep__Request__thread_create_running_t__new_state__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__thread_create_running_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_create_running */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t thread_create_running
(
	task_t parent_task,
	thread_state_flavor_t flavor,
	thread_state_t new_state,
	mach_msg_type_number_t new_stateCnt,
	thread_act_t *child_act
);

/* Routine thread_create_running */
mig_internal novalue _Xthread_create_running
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		thread_state_flavor_t flavor;
		mach_msg_type_number_t new_stateCnt;
		natural_t new_state[144];
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__thread_create_running_t __Request;
	typedef __Reply__thread_create_running_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__thread_create_running_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__thread_create_running_t__defined */

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t child_actTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(3412, "thread_create_running")
	__BeforeRcvRpc(3412, "thread_create_running")

#if	defined(__MIG_check__Request__thread_create_running_t__defined)
	check_result = __MIG_check__Request__thread_create_running_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__thread_create_running_t__defined) */

#if	UseStaticTemplates
	OutP->child_act = child_actTemplate;
#else	/* UseStaticTemplates */
	OutP->child_act.disposition = 19;
	OutP->child_act.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = thread_create_running(In0P->Head.msgh_request_port, In0P->flavor, In0P->new_state, In0P->new_stateCnt, &OutP->child_act.name);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(3412, "thread_create_running")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_set_exception_ports_t__defined)
#define __MIG_check__Request__task_set_exception_ports_t__defined
#ifndef __NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask__defined
#if	defined(__NDR_convert__int_rep__task__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__task__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior__defined
#if	defined(__NDR_convert__int_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__task__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor__defined
#if	defined(__NDR_convert__int_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__task__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask__defined
#if	defined(__NDR_convert__char_rep__task__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__task__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior__defined
#if	defined(__NDR_convert__char_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__task__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor__defined
#if	defined(__NDR_convert__char_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__task__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask__defined
#if	defined(__NDR_convert__float_rep__task__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__task__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior__defined
#if	defined(__NDR_convert__float_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__task__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor__defined
#if	defined(__NDR_convert__float_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__task__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor__defined */


mig_internal kern_return_t __MIG_check__Request__task_set_exception_ports_t(__attribute__((__unused__)) __Request__task_set_exception_ports_t *In0P)
{

	typedef __Request__task_set_exception_ports_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->new_port.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->new_port.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask__defined)
		__NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask(&In0P->exception_mask, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_exception_ports_t__exception_mask__defined */
#if defined(__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior__defined)
		__NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior(&In0P->behavior, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_exception_ports_t__behavior__defined */
#if defined(__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor__defined)
		__NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor(&In0P->new_flavor, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_exception_ports_t__new_flavor__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask__defined) || \
	defined(__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior__defined) || \
	defined(__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask__defined)
		__NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask(&In0P->exception_mask, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_exception_ports_t__exception_mask__defined */
#if defined(__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior__defined)
		__NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior(&In0P->behavior, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_exception_ports_t__behavior__defined */
#if defined(__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor__defined)
		__NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor(&In0P->new_flavor, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_exception_ports_t__new_flavor__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask__defined) || \
	defined(__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior__defined) || \
	defined(__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask__defined)
		__NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask(&In0P->exception_mask, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_exception_ports_t__exception_mask__defined */
#if defined(__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior__defined)
		__NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior(&In0P->behavior, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_exception_ports_t__behavior__defined */
#if defined(__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor__defined)
		__NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor(&In0P->new_flavor, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_exception_ports_t__new_flavor__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_set_exception_ports_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_exception_ports */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_set_exception_ports
(
	task_t task,
	exception_mask_t exception_mask,
	mach_port_t new_port,
	exception_behavior_t behavior,
	thread_state_flavor_t new_flavor
);

/* Routine task_set_exception_ports */
mig_internal novalue _Xtask_set_exception_ports
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t new_port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		exception_mask_t exception_mask;
		exception_behavior_t behavior;
		thread_state_flavor_t new_flavor;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_set_exception_ports_t __Request;
	typedef __Reply__task_set_exception_ports_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_set_exception_ports_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_set_exception_ports_t__defined */

	__DeclareRcvRpc(3413, "task_set_exception_ports")
	__BeforeRcvRpc(3413, "task_set_exception_ports")

#if	defined(__MIG_check__Request__task_set_exception_ports_t__defined)
	check_result = __MIG_check__Request__task_set_exception_ports_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_set_exception_ports_t__defined) */

	OutP->RetCode = task_set_exception_ports(In0P->Head.msgh_request_port, In0P->exception_mask, In0P->new_port.name, In0P->behavior, In0P->new_flavor);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3413, "task_set_exception_ports")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_get_exception_ports_t__defined)
#define __MIG_check__Request__task_get_exception_ports_t__defined
#ifndef __NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask__defined
#if	defined(__NDR_convert__int_rep__task__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__task__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask__defined */

#ifndef __NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask__defined
#if	defined(__NDR_convert__char_rep__task__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__task__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask__defined */

#ifndef __NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask__defined
#if	defined(__NDR_convert__float_rep__task__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__task__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask__defined */


mig_internal kern_return_t __MIG_check__Request__task_get_exception_ports_t(__attribute__((__unused__)) __Request__task_get_exception_ports_t *In0P)
{

	typedef __Request__task_get_exception_ports_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask__defined)
		__NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask(&In0P->exception_mask, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_get_exception_ports_t__exception_mask__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask__defined)
		__NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask(&In0P->exception_mask, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_get_exception_ports_t__exception_mask__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask__defined)
		__NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask(&In0P->exception_mask, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_get_exception_ports_t__exception_mask__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_get_exception_ports_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_get_exception_ports */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_get_exception_ports
(
	task_t task,
	exception_mask_t exception_mask,
	exception_mask_array_t masks,
	mach_msg_type_number_t *masksCnt,
	exception_handler_array_t old_handlers,
	exception_behavior_array_t old_behaviors,
	exception_flavor_array_t old_flavors
);

/* Routine task_get_exception_ports */
mig_internal novalue _Xtask_get_exception_ports
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		exception_mask_t exception_mask;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_get_exception_ports_t __Request;
	typedef __Reply__task_get_exception_ports_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
	unsigned int msgh_size;
	unsigned int msgh_size_delta;

#ifdef	__MIG_check__Request__task_get_exception_ports_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_get_exception_ports_t__defined */

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t old_handlersTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	mach_msg_type_number_t masksCnt;
	exception_handler_t old_handlers[32];
	exception_behavior_t old_behaviors[32];
	thread_state_flavor_t old_flavors[32];

	__DeclareRcvRpc(3414, "task_get_exception_ports")
	__BeforeRcvRpc(3414, "task_get_exception_ports")

#if	defined(__MIG_check__Request__task_get_exception_ports_t__defined)
	check_result = __MIG_check__Request__task_get_exception_ports_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_get_exception_ports_t__defined) */

	{
	    register	mach_msg_port_descriptor_t	*ptr;
	    register int	i;

	    ptr = &OutP->old_handlers[0];
	    for (i = 0; i < 32; ptr++, i++) {
#if	UseStaticTemplates
		*ptr = old_handlersTemplate;
#else	/* UseStaticTemplates */
		ptr->name = MACH_PORT_NULL;
		ptr->disposition = 19;
		ptr->type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */
	    }
	}


	masksCnt = 32;

	RetCode = task_get_exception_ports(In0P->Head.msgh_request_port, In0P->exception_mask, OutP->masks, &masksCnt, old_handlers, old_behaviors, old_flavors);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}
	{
	    register	mach_msg_port_descriptor_t	*ptr;
	    register int	i, j;

	    ptr = &OutP->old_handlers[0];
	    j = min(32, masksCnt);
	    for (i = 0; i < j; ptr++, i++) {
		ptr->name = old_handlers[i];
	    }
	}


	OutP->NDR = NDR_record;

	OutP->masksCnt = masksCnt;
	msgh_size_delta = ((4 * masksCnt));
	msgh_size = (mach_msg_size_t)(sizeof(Reply) - 384) + msgh_size_delta;
	OutP = (Reply *) ((pointer_t) OutP + msgh_size_delta - 128);
	(void)memcpy((char *) OutP->old_behaviors, (const char *) old_behaviors, 4 * masksCnt);
	msgh_size_delta = ((4 * masksCnt));
	msgh_size += msgh_size_delta;
	OutP = (Reply *) ((pointer_t) OutP + msgh_size_delta - 128);
	(void)memcpy((char *) OutP->old_flavors, (const char *) old_flavors, 4 * masksCnt);
	msgh_size += ((4 * masksCnt));

	OutP = (Reply *) OutHeadP;
	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = msgh_size;
	OutP->msgh_body.msgh_descriptor_count = 32;
	__AfterRcvRpc(3414, "task_get_exception_ports")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_swap_exception_ports_t__defined)
#define __MIG_check__Request__task_swap_exception_ports_t__defined
#ifndef __NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#if	defined(__NDR_convert__int_rep__task__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__task__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask__defined */

#ifndef __NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior__defined
#if	defined(__NDR_convert__int_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__task__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior__defined */

#ifndef __NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#if	defined(__NDR_convert__int_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__task__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor__defined */

#ifndef __NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#if	defined(__NDR_convert__char_rep__task__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__task__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask__defined */

#ifndef __NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior__defined
#if	defined(__NDR_convert__char_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__task__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior__defined */

#ifndef __NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#if	defined(__NDR_convert__char_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__task__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor__defined */

#ifndef __NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#if	defined(__NDR_convert__float_rep__task__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__task__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__exception_mask_t((exception_mask_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask__defined */

#ifndef __NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior__defined
#if	defined(__NDR_convert__float_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__task__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__exception_behavior_t((exception_behavior_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior__defined */

#ifndef __NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#if	defined(__NDR_convert__float_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__task__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__thread_state_flavor_t((thread_state_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor__defined
#define	__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor__defined */


mig_internal kern_return_t __MIG_check__Request__task_swap_exception_ports_t(__attribute__((__unused__)) __Request__task_swap_exception_ports_t *In0P)
{

	typedef __Request__task_swap_exception_ports_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->new_port.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->new_port.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask__defined) || \
	defined(__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior__defined) || \
	defined(__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask__defined)
		__NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask(&In0P->exception_mask, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_swap_exception_ports_t__exception_mask__defined */
#if defined(__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior__defined)
		__NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior(&In0P->behavior, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_swap_exception_ports_t__behavior__defined */
#if defined(__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor__defined)
		__NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor(&In0P->new_flavor, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_swap_exception_ports_t__new_flavor__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask__defined) || \
	defined(__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior__defined) || \
	defined(__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask__defined)
		__NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask(&In0P->exception_mask, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_swap_exception_ports_t__exception_mask__defined */
#if defined(__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior__defined)
		__NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior(&In0P->behavior, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_swap_exception_ports_t__behavior__defined */
#if defined(__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor__defined)
		__NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor(&In0P->new_flavor, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_swap_exception_ports_t__new_flavor__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask__defined) || \
	defined(__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior__defined) || \
	defined(__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask__defined)
		__NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask(&In0P->exception_mask, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_swap_exception_ports_t__exception_mask__defined */
#if defined(__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior__defined)
		__NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior(&In0P->behavior, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_swap_exception_ports_t__behavior__defined */
#if defined(__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor__defined)
		__NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor(&In0P->new_flavor, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_swap_exception_ports_t__new_flavor__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_swap_exception_ports_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_swap_exception_ports */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_swap_exception_ports
(
	task_t task,
	exception_mask_t exception_mask,
	mach_port_t new_port,
	exception_behavior_t behavior,
	thread_state_flavor_t new_flavor,
	exception_mask_array_t masks,
	mach_msg_type_number_t *masksCnt,
	exception_handler_array_t old_handlerss,
	exception_behavior_array_t old_behaviors,
	exception_flavor_array_t old_flavors
);

/* Routine task_swap_exception_ports */
mig_internal novalue _Xtask_swap_exception_ports
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t new_port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		exception_mask_t exception_mask;
		exception_behavior_t behavior;
		thread_state_flavor_t new_flavor;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_swap_exception_ports_t __Request;
	typedef __Reply__task_swap_exception_ports_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
	unsigned int msgh_size;
	unsigned int msgh_size_delta;

#ifdef	__MIG_check__Request__task_swap_exception_ports_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_swap_exception_ports_t__defined */

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t old_handlerssTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	mach_msg_type_number_t masksCnt;
	exception_handler_t old_handlerss[32];
	exception_behavior_t old_behaviors[32];
	thread_state_flavor_t old_flavors[32];

	__DeclareRcvRpc(3415, "task_swap_exception_ports")
	__BeforeRcvRpc(3415, "task_swap_exception_ports")

#if	defined(__MIG_check__Request__task_swap_exception_ports_t__defined)
	check_result = __MIG_check__Request__task_swap_exception_ports_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_swap_exception_ports_t__defined) */

	{
	    register	mach_msg_port_descriptor_t	*ptr;
	    register int	i;

	    ptr = &OutP->old_handlerss[0];
	    for (i = 0; i < 32; ptr++, i++) {
#if	UseStaticTemplates
		*ptr = old_handlerssTemplate;
#else	/* UseStaticTemplates */
		ptr->name = MACH_PORT_NULL;
		ptr->disposition = 19;
		ptr->type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */
	    }
	}


	masksCnt = 32;

	RetCode = task_swap_exception_ports(In0P->Head.msgh_request_port, In0P->exception_mask, In0P->new_port.name, In0P->behavior, In0P->new_flavor, OutP->masks, &masksCnt, old_handlerss, old_behaviors, old_flavors);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}
	{
	    register	mach_msg_port_descriptor_t	*ptr;
	    register int	i, j;

	    ptr = &OutP->old_handlerss[0];
	    j = min(32, masksCnt);
	    for (i = 0; i < j; ptr++, i++) {
		ptr->name = old_handlerss[i];
	    }
	}


	OutP->NDR = NDR_record;

	OutP->masksCnt = masksCnt;
	msgh_size_delta = ((4 * masksCnt));
	msgh_size = (mach_msg_size_t)(sizeof(Reply) - 384) + msgh_size_delta;
	OutP = (Reply *) ((pointer_t) OutP + msgh_size_delta - 128);
	(void)memcpy((char *) OutP->old_behaviors, (const char *) old_behaviors, 4 * masksCnt);
	msgh_size_delta = ((4 * masksCnt));
	msgh_size += msgh_size_delta;
	OutP = (Reply *) ((pointer_t) OutP + msgh_size_delta - 128);
	(void)memcpy((char *) OutP->old_flavors, (const char *) old_flavors, 4 * masksCnt);
	msgh_size += ((4 * masksCnt));

	OutP = (Reply *) OutHeadP;
	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = msgh_size;
	OutP->msgh_body.msgh_descriptor_count = 32;
	__AfterRcvRpc(3415, "task_swap_exception_ports")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__lock_set_create_t__defined)
#define __MIG_check__Request__lock_set_create_t__defined
#ifndef __NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks__defined
#if	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks__defined */

#ifndef __NDR_convert__int_rep__Request__lock_set_create_t__policy__defined
#if	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__int_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__int_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__int_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__int_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__lock_set_create_t__policy__defined */

#ifndef __NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks__defined
#if	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks__defined */

#ifndef __NDR_convert__char_rep__Request__lock_set_create_t__policy__defined
#if	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__char_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__char_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__char_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__char_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__lock_set_create_t__policy__defined */

#ifndef __NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks__defined
#if	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks__defined
#define	__NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks__defined */

#ifndef __NDR_convert__float_rep__Request__lock_set_create_t__policy__defined
#if	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__float_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__float_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__float_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__lock_set_create_t__policy__defined
#define	__NDR_convert__float_rep__Request__lock_set_create_t__policy(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__lock_set_create_t__policy__defined */


mig_internal kern_return_t __MIG_check__Request__lock_set_create_t(__attribute__((__unused__)) __Request__lock_set_create_t *In0P)
{

	typedef __Request__lock_set_create_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks__defined) || \
	defined(__NDR_convert__int_rep__Request__lock_set_create_t__policy__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks__defined)
		__NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks(&In0P->n_ulocks, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__lock_set_create_t__n_ulocks__defined */
#if defined(__NDR_convert__int_rep__Request__lock_set_create_t__policy__defined)
		__NDR_convert__int_rep__Request__lock_set_create_t__policy(&In0P->policy, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__lock_set_create_t__policy__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks__defined) || \
	defined(__NDR_convert__char_rep__Request__lock_set_create_t__policy__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks__defined)
		__NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks(&In0P->n_ulocks, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__lock_set_create_t__n_ulocks__defined */
#if defined(__NDR_convert__char_rep__Request__lock_set_create_t__policy__defined)
		__NDR_convert__char_rep__Request__lock_set_create_t__policy(&In0P->policy, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__lock_set_create_t__policy__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks__defined) || \
	defined(__NDR_convert__float_rep__Request__lock_set_create_t__policy__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks__defined)
		__NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks(&In0P->n_ulocks, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__lock_set_create_t__n_ulocks__defined */
#if defined(__NDR_convert__float_rep__Request__lock_set_create_t__policy__defined)
		__NDR_convert__float_rep__Request__lock_set_create_t__policy(&In0P->policy, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__lock_set_create_t__policy__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__lock_set_create_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine lock_set_create */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t lock_set_create
(
	task_t task,
	lock_set_t *new_lock_set,
	int n_ulocks,
	int policy
);

/* Routine lock_set_create */
mig_internal novalue _Xlock_set_create
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int n_ulocks;
		int policy;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__lock_set_create_t __Request;
	typedef __Reply__lock_set_create_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__lock_set_create_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__lock_set_create_t__defined */

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t new_lock_setTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(3416, "lock_set_create")
	__BeforeRcvRpc(3416, "lock_set_create")

#if	defined(__MIG_check__Request__lock_set_create_t__defined)
	check_result = __MIG_check__Request__lock_set_create_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__lock_set_create_t__defined) */

#if	UseStaticTemplates
	OutP->new_lock_set = new_lock_setTemplate;
#else	/* UseStaticTemplates */
	OutP->new_lock_set.disposition = 19;
	OutP->new_lock_set.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = lock_set_create(In0P->Head.msgh_request_port, &OutP->new_lock_set.name, In0P->n_ulocks, In0P->policy);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(3416, "lock_set_create")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__lock_set_destroy_t__defined)
#define __MIG_check__Request__lock_set_destroy_t__defined

mig_internal kern_return_t __MIG_check__Request__lock_set_destroy_t(__attribute__((__unused__)) __Request__lock_set_destroy_t *In0P)
{

	typedef __Request__lock_set_destroy_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->lock_set.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->lock_set.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__lock_set_destroy_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine lock_set_destroy */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t lock_set_destroy
(
	task_t task,
	lock_set_t lock_set
);

/* Routine lock_set_destroy */
mig_internal novalue _Xlock_set_destroy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t lock_set;
		/* end of the kernel processed data */
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__lock_set_destroy_t __Request;
	typedef __Reply__lock_set_destroy_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__lock_set_destroy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__lock_set_destroy_t__defined */

	__DeclareRcvRpc(3417, "lock_set_destroy")
	__BeforeRcvRpc(3417, "lock_set_destroy")

#if	defined(__MIG_check__Request__lock_set_destroy_t__defined)
	check_result = __MIG_check__Request__lock_set_destroy_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__lock_set_destroy_t__defined) */

	OutP->RetCode = lock_set_destroy(In0P->Head.msgh_request_port, In0P->lock_set.name);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3417, "lock_set_destroy")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__semaphore_create_t__defined)
#define __MIG_check__Request__semaphore_create_t__defined
#ifndef __NDR_convert__int_rep__Request__semaphore_create_t__policy__defined
#if	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__int_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__int_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__int_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__int_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__semaphore_create_t__policy__defined */

#ifndef __NDR_convert__int_rep__Request__semaphore_create_t__value__defined
#if	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__int_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__int_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__int_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__int_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__semaphore_create_t__value__defined */

#ifndef __NDR_convert__char_rep__Request__semaphore_create_t__policy__defined
#if	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__char_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__char_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__char_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__char_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__semaphore_create_t__policy__defined */

#ifndef __NDR_convert__char_rep__Request__semaphore_create_t__value__defined
#if	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__char_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__char_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__char_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__char_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__semaphore_create_t__value__defined */

#ifndef __NDR_convert__float_rep__Request__semaphore_create_t__policy__defined
#if	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__float_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__float_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__float_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__semaphore_create_t__policy__defined
#define	__NDR_convert__float_rep__Request__semaphore_create_t__policy(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__semaphore_create_t__policy__defined */

#ifndef __NDR_convert__float_rep__Request__semaphore_create_t__value__defined
#if	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__float_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__float_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__float_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__semaphore_create_t__value__defined
#define	__NDR_convert__float_rep__Request__semaphore_create_t__value(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__semaphore_create_t__value__defined */


mig_internal kern_return_t __MIG_check__Request__semaphore_create_t(__attribute__((__unused__)) __Request__semaphore_create_t *In0P)
{

	typedef __Request__semaphore_create_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__semaphore_create_t__policy__defined) || \
	defined(__NDR_convert__int_rep__Request__semaphore_create_t__value__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__semaphore_create_t__policy__defined)
		__NDR_convert__int_rep__Request__semaphore_create_t__policy(&In0P->policy, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__semaphore_create_t__policy__defined */
#if defined(__NDR_convert__int_rep__Request__semaphore_create_t__value__defined)
		__NDR_convert__int_rep__Request__semaphore_create_t__value(&In0P->value, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__semaphore_create_t__value__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__semaphore_create_t__policy__defined) || \
	defined(__NDR_convert__char_rep__Request__semaphore_create_t__value__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__semaphore_create_t__policy__defined)
		__NDR_convert__char_rep__Request__semaphore_create_t__policy(&In0P->policy, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__semaphore_create_t__policy__defined */
#if defined(__NDR_convert__char_rep__Request__semaphore_create_t__value__defined)
		__NDR_convert__char_rep__Request__semaphore_create_t__value(&In0P->value, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__semaphore_create_t__value__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__semaphore_create_t__policy__defined) || \
	defined(__NDR_convert__float_rep__Request__semaphore_create_t__value__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__semaphore_create_t__policy__defined)
		__NDR_convert__float_rep__Request__semaphore_create_t__policy(&In0P->policy, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__semaphore_create_t__policy__defined */
#if defined(__NDR_convert__float_rep__Request__semaphore_create_t__value__defined)
		__NDR_convert__float_rep__Request__semaphore_create_t__value(&In0P->value, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__semaphore_create_t__value__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__semaphore_create_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine semaphore_create */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t semaphore_create
(
	task_t task,
	semaphore_t *semaphore,
	int policy,
	int value
);

/* Routine semaphore_create */
mig_internal novalue _Xsemaphore_create
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int policy;
		int value;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__semaphore_create_t __Request;
	typedef __Reply__semaphore_create_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__semaphore_create_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__semaphore_create_t__defined */

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t semaphoreTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(3418, "semaphore_create")
	__BeforeRcvRpc(3418, "semaphore_create")

#if	defined(__MIG_check__Request__semaphore_create_t__defined)
	check_result = __MIG_check__Request__semaphore_create_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__semaphore_create_t__defined) */

#if	UseStaticTemplates
	OutP->semaphore = semaphoreTemplate;
#else	/* UseStaticTemplates */
	OutP->semaphore.disposition = 19;
	OutP->semaphore.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = semaphore_create(In0P->Head.msgh_request_port, &OutP->semaphore.name, In0P->policy, In0P->value);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(3418, "semaphore_create")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__semaphore_destroy_t__defined)
#define __MIG_check__Request__semaphore_destroy_t__defined

mig_internal kern_return_t __MIG_check__Request__semaphore_destroy_t(__attribute__((__unused__)) __Request__semaphore_destroy_t *In0P)
{

	typedef __Request__semaphore_destroy_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->semaphore.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->semaphore.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__semaphore_destroy_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine semaphore_destroy */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t semaphore_destroy
(
	task_t task,
	semaphore_consume_ref_t semaphore
);

/* Routine semaphore_destroy */
mig_internal novalue _Xsemaphore_destroy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t semaphore;
		/* end of the kernel processed data */
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__semaphore_destroy_t __Request;
	typedef __Reply__semaphore_destroy_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__semaphore_destroy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__semaphore_destroy_t__defined */

	__DeclareRcvRpc(3419, "semaphore_destroy")
	__BeforeRcvRpc(3419, "semaphore_destroy")

#if	defined(__MIG_check__Request__semaphore_destroy_t__defined)
	check_result = __MIG_check__Request__semaphore_destroy_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__semaphore_destroy_t__defined) */

	OutP->RetCode = semaphore_destroy(In0P->Head.msgh_request_port, In0P->semaphore.name);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3419, "semaphore_destroy")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_policy_set_t__defined)
#define __MIG_check__Request__task_policy_set_t__defined
#ifndef __NDR_convert__int_rep__Request__task_policy_set_t__flavor__defined
#if	defined(__NDR_convert__int_rep__task__task_policy_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__int_rep__task__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task_policy_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__int_rep__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__int_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__int_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__int_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__int_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_policy_set_t__flavor__defined */

#ifndef __NDR_convert__int_rep__Request__task_policy_set_t__policy_info__defined
#if	defined(__NDR_convert__int_rep__task__task_policy_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__int_rep__task__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task_policy_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__int_rep__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__integer_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__task__integer_t)
#elif	defined(__NDR_convert__int_rep__integer_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__integer_t)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_policy_set_t__policy_info__defined */

#ifndef __NDR_convert__int_rep__Request__task_policy_set_t__policy_infoCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_infoCnt__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_infoCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_infoCnt__defined
#define	__NDR_convert__int_rep__Request__task_policy_set_t__policy_infoCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_policy_set_t__policy_infoCnt__defined */

#ifndef __NDR_convert__char_rep__Request__task_policy_set_t__flavor__defined
#if	defined(__NDR_convert__char_rep__task__task_policy_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__char_rep__task__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task_policy_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__char_rep__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__char_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__char_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__char_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__char_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_policy_set_t__flavor__defined */

#ifndef __NDR_convert__char_rep__Request__task_policy_set_t__policy_info__defined
#if	defined(__NDR_convert__char_rep__task__task_policy_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__char_rep__task__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task_policy_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__char_rep__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__integer_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__task__integer_t)
#elif	defined(__NDR_convert__char_rep__integer_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__integer_t)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__char_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_policy_set_t__policy_info__defined */

#ifndef __NDR_convert__float_rep__Request__task_policy_set_t__flavor__defined
#if	defined(__NDR_convert__float_rep__task__task_policy_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__float_rep__task__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task_policy_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__float_rep__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__float_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__float_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__float_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__flavor(a, f) \
	__NDR_convert__float_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_policy_set_t__flavor__defined */

#ifndef __NDR_convert__float_rep__Request__task_policy_set_t__policy_info__defined
#if	defined(__NDR_convert__float_rep__task__task_policy_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__float_rep__task__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task_policy_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__float_rep__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__integer_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__task__integer_t)
#elif	defined(__NDR_convert__float_rep__integer_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__integer_t)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info__defined
#define	__NDR_convert__float_rep__Request__task_policy_set_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_policy_set_t__policy_info__defined */


mig_internal kern_return_t __MIG_check__Request__task_policy_set_t(__attribute__((__unused__)) __Request__task_policy_set_t *In0P)
{

	typedef __Request__task_policy_set_t __Request;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	msgh_size = In0P->Head.msgh_size;
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (msgh_size < (mach_msg_size_t)(sizeof(__Request) - 64)) ||  (msgh_size > (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Request__task_policy_set_t__policy_infoCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Request__task_policy_set_t__policy_infoCnt(&In0P->policy_infoCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_policy_set_t__policy_infoCnt__defined */
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Request) - 64) + ((4 * In0P->policy_infoCnt)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_policy_set_t__flavor__defined) || \
	defined(__NDR_convert__int_rep__Request__task_policy_set_t__policy_info__defined) || \
	defined(__NDR_convert__int_rep__Request__task_policy_set_t__policy_infoCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_policy_set_t__flavor__defined)
		__NDR_convert__int_rep__Request__task_policy_set_t__flavor(&In0P->flavor, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_policy_set_t__flavor__defined */
#if defined(__NDR_convert__int_rep__Request__task_policy_set_t__policy_info__defined)
		__NDR_convert__int_rep__Request__task_policy_set_t__policy_info(&In0P->policy_info, In0P->NDR.int_rep, In0P->policy_infoCnt);
#endif	/* __NDR_convert__int_rep__Request__task_policy_set_t__policy_info__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_policy_set_t__flavor__defined) || \
	defined(__NDR_convert__char_rep__Request__task_policy_set_t__policy_info__defined) || \
	0
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_policy_set_t__flavor__defined)
		__NDR_convert__char_rep__Request__task_policy_set_t__flavor(&In0P->flavor, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_policy_set_t__flavor__defined */
#if defined(__NDR_convert__char_rep__Request__task_policy_set_t__policy_info__defined)
		__NDR_convert__char_rep__Request__task_policy_set_t__policy_info(&In0P->policy_info, In0P->NDR.char_rep, In0P->policy_infoCnt);
#endif	/* __NDR_convert__char_rep__Request__task_policy_set_t__policy_info__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_policy_set_t__flavor__defined) || \
	defined(__NDR_convert__float_rep__Request__task_policy_set_t__policy_info__defined) || \
	0
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_policy_set_t__flavor__defined)
		__NDR_convert__float_rep__Request__task_policy_set_t__flavor(&In0P->flavor, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_policy_set_t__flavor__defined */
#if defined(__NDR_convert__float_rep__Request__task_policy_set_t__policy_info__defined)
		__NDR_convert__float_rep__Request__task_policy_set_t__policy_info(&In0P->policy_info, In0P->NDR.float_rep, In0P->policy_infoCnt);
#endif	/* __NDR_convert__float_rep__Request__task_policy_set_t__policy_info__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_policy_set_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_policy_set */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_policy_set
(
	task_t task,
	task_policy_flavor_t flavor,
	task_policy_t policy_info,
	mach_msg_type_number_t policy_infoCnt
);

/* Routine task_policy_set */
mig_internal novalue _Xtask_policy_set
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_policy_flavor_t flavor;
		mach_msg_type_number_t policy_infoCnt;
		integer_t policy_info[16];
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_policy_set_t __Request;
	typedef __Reply__task_policy_set_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_policy_set_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_policy_set_t__defined */

	__DeclareRcvRpc(3420, "task_policy_set")
	__BeforeRcvRpc(3420, "task_policy_set")

#if	defined(__MIG_check__Request__task_policy_set_t__defined)
	check_result = __MIG_check__Request__task_policy_set_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_policy_set_t__defined) */

	OutP->RetCode = task_policy_set(In0P->Head.msgh_request_port, In0P->flavor, In0P->policy_info, In0P->policy_infoCnt);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3420, "task_policy_set")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_policy_get_t__defined)
#define __MIG_check__Request__task_policy_get_t__defined
#ifndef __NDR_convert__int_rep__Request__task_policy_get_t__flavor__defined
#if	defined(__NDR_convert__int_rep__task__task_policy_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__int_rep__task__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task_policy_flavor_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__int_rep__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__int_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__int_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__int_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__int_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__int_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_policy_get_t__flavor__defined */

#ifndef __NDR_convert__int_rep__Request__task_policy_get_t__policy_infoCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_get_t__policy_infoCnt__defined
#define	__NDR_convert__int_rep__Request__task_policy_get_t__policy_infoCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_get_t__policy_infoCnt__defined
#define	__NDR_convert__int_rep__Request__task_policy_get_t__policy_infoCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_policy_get_t__policy_infoCnt__defined */

#ifndef __NDR_convert__int_rep__Request__task_policy_get_t__get_default__defined
#if	defined(__NDR_convert__int_rep__task__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_get_t__get_default__defined
#define	__NDR_convert__int_rep__Request__task_policy_get_t__get_default(a, f) \
	__NDR_convert__int_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_get_t__get_default__defined
#define	__NDR_convert__int_rep__Request__task_policy_get_t__get_default(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_policy_get_t__get_default__defined */

#ifndef __NDR_convert__char_rep__Request__task_policy_get_t__flavor__defined
#if	defined(__NDR_convert__char_rep__task__task_policy_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__char_rep__task__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task_policy_flavor_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__char_rep__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__char_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__char_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__char_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__char_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__char_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_policy_get_t__flavor__defined */

#ifndef __NDR_convert__char_rep__Request__task_policy_get_t__get_default__defined
#if	defined(__NDR_convert__char_rep__task__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_get_t__get_default__defined
#define	__NDR_convert__char_rep__Request__task_policy_get_t__get_default(a, f) \
	__NDR_convert__char_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_get_t__get_default__defined
#define	__NDR_convert__char_rep__Request__task_policy_get_t__get_default(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_policy_get_t__get_default__defined */

#ifndef __NDR_convert__float_rep__Request__task_policy_get_t__flavor__defined
#if	defined(__NDR_convert__float_rep__task__task_policy_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__float_rep__task__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task_policy_flavor_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__float_rep__task_policy_flavor_t((task_policy_flavor_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__float_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__float_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__float_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor__defined
#define	__NDR_convert__float_rep__Request__task_policy_get_t__flavor(a, f) \
	__NDR_convert__float_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_policy_get_t__flavor__defined */

#ifndef __NDR_convert__float_rep__Request__task_policy_get_t__get_default__defined
#if	defined(__NDR_convert__float_rep__task__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_get_t__get_default__defined
#define	__NDR_convert__float_rep__Request__task_policy_get_t__get_default(a, f) \
	__NDR_convert__float_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_get_t__get_default__defined
#define	__NDR_convert__float_rep__Request__task_policy_get_t__get_default(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_policy_get_t__get_default__defined */


mig_internal kern_return_t __MIG_check__Request__task_policy_get_t(__attribute__((__unused__)) __Request__task_policy_get_t *In0P)
{

	typedef __Request__task_policy_get_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_policy_get_t__flavor__defined) || \
	defined(__NDR_convert__int_rep__Request__task_policy_get_t__policy_infoCnt__defined) || \
	defined(__NDR_convert__int_rep__Request__task_policy_get_t__get_default__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_policy_get_t__flavor__defined)
		__NDR_convert__int_rep__Request__task_policy_get_t__flavor(&In0P->flavor, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_policy_get_t__flavor__defined */
#if defined(__NDR_convert__int_rep__Request__task_policy_get_t__policy_infoCnt__defined)
		__NDR_convert__int_rep__Request__task_policy_get_t__policy_infoCnt(&In0P->policy_infoCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_policy_get_t__policy_infoCnt__defined */
#if defined(__NDR_convert__int_rep__Request__task_policy_get_t__get_default__defined)
		__NDR_convert__int_rep__Request__task_policy_get_t__get_default(&In0P->get_default, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_policy_get_t__get_default__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_policy_get_t__flavor__defined) || \
	0 || \
	defined(__NDR_convert__char_rep__Request__task_policy_get_t__get_default__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_policy_get_t__flavor__defined)
		__NDR_convert__char_rep__Request__task_policy_get_t__flavor(&In0P->flavor, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_policy_get_t__flavor__defined */
#if defined(__NDR_convert__char_rep__Request__task_policy_get_t__get_default__defined)
		__NDR_convert__char_rep__Request__task_policy_get_t__get_default(&In0P->get_default, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_policy_get_t__get_default__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_policy_get_t__flavor__defined) || \
	0 || \
	defined(__NDR_convert__float_rep__Request__task_policy_get_t__get_default__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_policy_get_t__flavor__defined)
		__NDR_convert__float_rep__Request__task_policy_get_t__flavor(&In0P->flavor, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_policy_get_t__flavor__defined */
#if defined(__NDR_convert__float_rep__Request__task_policy_get_t__get_default__defined)
		__NDR_convert__float_rep__Request__task_policy_get_t__get_default(&In0P->get_default, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_policy_get_t__get_default__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_policy_get_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_policy_get */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_policy_get
(
	task_t task,
	task_policy_flavor_t flavor,
	task_policy_t policy_info,
	mach_msg_type_number_t *policy_infoCnt,
	boolean_t *get_default
);

/* Routine task_policy_get */
mig_internal novalue _Xtask_policy_get
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_policy_flavor_t flavor;
		mach_msg_type_number_t policy_infoCnt;
		boolean_t get_default;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_policy_get_t __Request;
	typedef __Reply__task_policy_get_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
	unsigned int msgh_size_delta;

#ifdef	__MIG_check__Request__task_policy_get_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_policy_get_t__defined */

	__DeclareRcvRpc(3421, "task_policy_get")
	__BeforeRcvRpc(3421, "task_policy_get")

#if	defined(__MIG_check__Request__task_policy_get_t__defined)
	check_result = __MIG_check__Request__task_policy_get_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_policy_get_t__defined) */

	OutP->policy_infoCnt = 16;
	if (In0P->policy_infoCnt < OutP->policy_infoCnt)
		OutP->policy_infoCnt = In0P->policy_infoCnt;

	OutP->RetCode = task_policy_get(In0P->Head.msgh_request_port, In0P->flavor, OutP->policy_info, &OutP->policy_infoCnt, &In0P->get_default);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;

	msgh_size_delta = ((4 * OutP->policy_infoCnt));
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply) - 64) + msgh_size_delta;
	OutP = (Reply *) ((pointer_t) OutP + msgh_size_delta - 64);

	OutP->get_default = In0P->get_default;

	OutP = (Reply *) OutHeadP;
	__AfterRcvRpc(3421, "task_policy_get")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_sample_t__defined)
#define __MIG_check__Request__task_sample_t__defined

mig_internal kern_return_t __MIG_check__Request__task_sample_t(__attribute__((__unused__)) __Request__task_sample_t *In0P)
{

	typedef __Request__task_sample_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->reply.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->reply.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_sample_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_sample */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_sample
(
	task_t task,
	mach_port_t reply
);

/* Routine task_sample */
mig_internal novalue _Xtask_sample
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t reply;
		/* end of the kernel processed data */
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_sample_t __Request;
	typedef __Reply__task_sample_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_sample_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_sample_t__defined */

	__DeclareRcvRpc(3422, "task_sample")
	__BeforeRcvRpc(3422, "task_sample")

#if	defined(__MIG_check__Request__task_sample_t__defined)
	check_result = __MIG_check__Request__task_sample_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_sample_t__defined) */

	OutP->RetCode = task_sample(In0P->Head.msgh_request_port, In0P->reply.name);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3422, "task_sample")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_policy_t__defined)
#define __MIG_check__Request__task_policy_t__defined
#ifndef __NDR_convert__int_rep__Request__task_policy_t__policy__defined
#if	defined(__NDR_convert__int_rep__task__policy_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__int_rep__task__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__policy_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__int_rep__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_policy_t__policy__defined */

#ifndef __NDR_convert__int_rep__Request__task_policy_t__base__defined
#if	defined(__NDR_convert__int_rep__task__policy_base_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__int_rep__task__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__policy_base_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__int_rep__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__integer_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__task__integer_t)
#elif	defined(__NDR_convert__int_rep__integer_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__integer_t)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_policy_t__base__defined */

#ifndef __NDR_convert__int_rep__Request__task_policy_t__baseCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__baseCnt__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__baseCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__baseCnt__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__baseCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_policy_t__baseCnt__defined */

#ifndef __NDR_convert__int_rep__Request__task_policy_t__set_limit__defined
#if	defined(__NDR_convert__int_rep__task__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__set_limit__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__set_limit(a, f) \
	__NDR_convert__int_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__set_limit__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__set_limit(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_policy_t__set_limit__defined */

#ifndef __NDR_convert__int_rep__Request__task_policy_t__change__defined
#if	defined(__NDR_convert__int_rep__task__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__change__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__change(a, f) \
	__NDR_convert__int_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_policy_t__change__defined
#define	__NDR_convert__int_rep__Request__task_policy_t__change(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_policy_t__change__defined */

#ifndef __NDR_convert__char_rep__Request__task_policy_t__policy__defined
#if	defined(__NDR_convert__char_rep__task__policy_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__char_rep__task__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__policy_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__char_rep__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_policy_t__policy__defined */

#ifndef __NDR_convert__char_rep__Request__task_policy_t__base__defined
#if	defined(__NDR_convert__char_rep__task__policy_base_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__char_rep__task__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__policy_base_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__char_rep__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__integer_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__task__integer_t)
#elif	defined(__NDR_convert__char_rep__integer_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__integer_t)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_policy_t__base__defined */

#ifndef __NDR_convert__char_rep__Request__task_policy_t__set_limit__defined
#if	defined(__NDR_convert__char_rep__task__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__set_limit__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__set_limit(a, f) \
	__NDR_convert__char_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__set_limit__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__set_limit(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_policy_t__set_limit__defined */

#ifndef __NDR_convert__char_rep__Request__task_policy_t__change__defined
#if	defined(__NDR_convert__char_rep__task__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__change__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__change(a, f) \
	__NDR_convert__char_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_policy_t__change__defined
#define	__NDR_convert__char_rep__Request__task_policy_t__change(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_policy_t__change__defined */

#ifndef __NDR_convert__float_rep__Request__task_policy_t__policy__defined
#if	defined(__NDR_convert__float_rep__task__policy_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__float_rep__task__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__policy_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__float_rep__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__policy(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_policy_t__policy__defined */

#ifndef __NDR_convert__float_rep__Request__task_policy_t__base__defined
#if	defined(__NDR_convert__float_rep__task__policy_base_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__float_rep__task__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__policy_base_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__float_rep__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__integer_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__task__integer_t)
#elif	defined(__NDR_convert__float_rep__integer_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__integer_t)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_policy_t__base__defined */

#ifndef __NDR_convert__float_rep__Request__task_policy_t__set_limit__defined
#if	defined(__NDR_convert__float_rep__task__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__set_limit__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__set_limit(a, f) \
	__NDR_convert__float_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__set_limit__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__set_limit(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_policy_t__set_limit__defined */

#ifndef __NDR_convert__float_rep__Request__task_policy_t__change__defined
#if	defined(__NDR_convert__float_rep__task__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__change__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__change(a, f) \
	__NDR_convert__float_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_policy_t__change__defined
#define	__NDR_convert__float_rep__Request__task_policy_t__change(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_policy_t__change__defined */


mig_internal kern_return_t __MIG_check__Request__task_policy_t(__attribute__((__unused__)) __Request__task_policy_t *In0P, __attribute__((__unused__)) __Request__task_policy_t **In1PP)
{

	typedef __Request__task_policy_t __Request;
	__Request *In1P;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	unsigned int msgh_size_delta;

#if	__MigTypeCheck
	msgh_size = In0P->Head.msgh_size;
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (msgh_size < (mach_msg_size_t)(sizeof(__Request) - 20)) ||  (msgh_size > (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Request__task_policy_t__baseCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Request__task_policy_t__baseCnt(&In0P->baseCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_policy_t__baseCnt__defined */
	msgh_size_delta = (4 * In0P->baseCnt);
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Request) - 20) + msgh_size_delta)
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

	*In1PP = In1P = (__Request *) ((pointer_t) In0P + msgh_size_delta - 20);

#if	defined(__NDR_convert__int_rep__Request__task_policy_t__policy__defined) || \
	defined(__NDR_convert__int_rep__Request__task_policy_t__base__defined) || \
	defined(__NDR_convert__int_rep__Request__task_policy_t__baseCnt__defined) || \
	defined(__NDR_convert__int_rep__Request__task_policy_t__set_limit__defined) || \
	defined(__NDR_convert__int_rep__Request__task_policy_t__change__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_policy_t__policy__defined)
		__NDR_convert__int_rep__Request__task_policy_t__policy(&In0P->policy, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_policy_t__policy__defined */
#if defined(__NDR_convert__int_rep__Request__task_policy_t__base__defined)
		__NDR_convert__int_rep__Request__task_policy_t__base(&In0P->base, In0P->NDR.int_rep, In0P->baseCnt);
#endif	/* __NDR_convert__int_rep__Request__task_policy_t__base__defined */
#if defined(__NDR_convert__int_rep__Request__task_policy_t__set_limit__defined)
		__NDR_convert__int_rep__Request__task_policy_t__set_limit(&In1P->set_limit, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_policy_t__set_limit__defined */
#if defined(__NDR_convert__int_rep__Request__task_policy_t__change__defined)
		__NDR_convert__int_rep__Request__task_policy_t__change(&In1P->change, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_policy_t__change__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_policy_t__policy__defined) || \
	defined(__NDR_convert__char_rep__Request__task_policy_t__base__defined) || \
	0 || \
	defined(__NDR_convert__char_rep__Request__task_policy_t__set_limit__defined) || \
	defined(__NDR_convert__char_rep__Request__task_policy_t__change__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_policy_t__policy__defined)
		__NDR_convert__char_rep__Request__task_policy_t__policy(&In0P->policy, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_policy_t__policy__defined */
#if defined(__NDR_convert__char_rep__Request__task_policy_t__base__defined)
		__NDR_convert__char_rep__Request__task_policy_t__base(&In0P->base, In0P->NDR.char_rep, In0P->baseCnt);
#endif	/* __NDR_convert__char_rep__Request__task_policy_t__base__defined */
#if defined(__NDR_convert__char_rep__Request__task_policy_t__set_limit__defined)
		__NDR_convert__char_rep__Request__task_policy_t__set_limit(&In1P->set_limit, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_policy_t__set_limit__defined */
#if defined(__NDR_convert__char_rep__Request__task_policy_t__change__defined)
		__NDR_convert__char_rep__Request__task_policy_t__change(&In1P->change, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_policy_t__change__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_policy_t__policy__defined) || \
	defined(__NDR_convert__float_rep__Request__task_policy_t__base__defined) || \
	0 || \
	defined(__NDR_convert__float_rep__Request__task_policy_t__set_limit__defined) || \
	defined(__NDR_convert__float_rep__Request__task_policy_t__change__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_policy_t__policy__defined)
		__NDR_convert__float_rep__Request__task_policy_t__policy(&In0P->policy, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_policy_t__policy__defined */
#if defined(__NDR_convert__float_rep__Request__task_policy_t__base__defined)
		__NDR_convert__float_rep__Request__task_policy_t__base(&In0P->base, In0P->NDR.float_rep, In0P->baseCnt);
#endif	/* __NDR_convert__float_rep__Request__task_policy_t__base__defined */
#if defined(__NDR_convert__float_rep__Request__task_policy_t__set_limit__defined)
		__NDR_convert__float_rep__Request__task_policy_t__set_limit(&In1P->set_limit, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_policy_t__set_limit__defined */
#if defined(__NDR_convert__float_rep__Request__task_policy_t__change__defined)
		__NDR_convert__float_rep__Request__task_policy_t__change(&In1P->change, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_policy_t__change__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_policy_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_policy */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_policy
(
	task_t task,
	policy_t policy,
	policy_base_t base,
	mach_msg_type_number_t baseCnt,
	boolean_t set_limit,
	boolean_t change
);

/* Routine task_policy */
mig_internal novalue _Xtask_policy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		policy_t policy;
		mach_msg_type_number_t baseCnt;
		integer_t base[5];
		boolean_t set_limit;
		boolean_t change;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_policy_t __Request;
	typedef __Reply__task_policy_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Request *In1P;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_policy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_policy_t__defined */

	__DeclareRcvRpc(3423, "task_policy")
	__BeforeRcvRpc(3423, "task_policy")

#if	defined(__MIG_check__Request__task_policy_t__defined)
	check_result = __MIG_check__Request__task_policy_t((__Request *)In0P, (__Request **)&In1P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_policy_t__defined) */

	OutP->RetCode = task_policy(In0P->Head.msgh_request_port, In0P->policy, In0P->base, In0P->baseCnt, In1P->set_limit, In1P->change);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3423, "task_policy")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_set_emulation_t__defined)
#define __MIG_check__Request__task_set_emulation_t__defined
#ifndef __NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#if	defined(__NDR_convert__int_rep__task__vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__int_rep__task__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__int_rep__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__int_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__int_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__int_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__int_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_emulation_t__routine_number__defined
#if	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_emulation_t__routine_number__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#if	defined(__NDR_convert__char_rep__task__vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__char_rep__task__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__char_rep__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__char_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__char_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__char_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__char_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_emulation_t__routine_number__defined
#if	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_emulation_t__routine_number__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#if	defined(__NDR_convert__float_rep__task__vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__float_rep__task__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__float_rep__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__float_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__float_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__float_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt(a, f) \
	__NDR_convert__float_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_emulation_t__routine_number__defined
#if	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_number__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_t__routine_number(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_emulation_t__routine_number__defined */


mig_internal kern_return_t __MIG_check__Request__task_set_emulation_t(__attribute__((__unused__)) __Request__task_set_emulation_t *In0P)
{

	typedef __Request__task_set_emulation_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_emulation_t__routine_number__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt__defined)
		__NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt(&In0P->routine_entry_pt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_emulation_t__routine_entry_pt__defined */
#if defined(__NDR_convert__int_rep__Request__task_set_emulation_t__routine_number__defined)
		__NDR_convert__int_rep__Request__task_set_emulation_t__routine_number(&In0P->routine_number, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_emulation_t__routine_number__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt__defined) || \
	defined(__NDR_convert__char_rep__Request__task_set_emulation_t__routine_number__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt__defined)
		__NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt(&In0P->routine_entry_pt, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_emulation_t__routine_entry_pt__defined */
#if defined(__NDR_convert__char_rep__Request__task_set_emulation_t__routine_number__defined)
		__NDR_convert__char_rep__Request__task_set_emulation_t__routine_number(&In0P->routine_number, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_emulation_t__routine_number__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt__defined) || \
	defined(__NDR_convert__float_rep__Request__task_set_emulation_t__routine_number__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt__defined)
		__NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt(&In0P->routine_entry_pt, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_emulation_t__routine_entry_pt__defined */
#if defined(__NDR_convert__float_rep__Request__task_set_emulation_t__routine_number__defined)
		__NDR_convert__float_rep__Request__task_set_emulation_t__routine_number(&In0P->routine_number, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_emulation_t__routine_number__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_set_emulation_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_emulation */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_set_emulation
(
	task_t target_port,
	vm_address_t routine_entry_pt,
	int routine_number
);

/* Routine task_set_emulation */
mig_internal novalue _Xtask_set_emulation
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		vm_address_t routine_entry_pt;
		int routine_number;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_set_emulation_t __Request;
	typedef __Reply__task_set_emulation_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_set_emulation_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_set_emulation_t__defined */

	__DeclareRcvRpc(3424, "task_set_emulation")
	__BeforeRcvRpc(3424, "task_set_emulation")

#if	defined(__MIG_check__Request__task_set_emulation_t__defined)
	check_result = __MIG_check__Request__task_set_emulation_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_set_emulation_t__defined) */

	OutP->RetCode = task_set_emulation(In0P->Head.msgh_request_port, In0P->routine_entry_pt, In0P->routine_number);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3424, "task_set_emulation")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_get_emulation_vector_t__defined)
#define __MIG_check__Request__task_get_emulation_vector_t__defined

mig_internal kern_return_t __MIG_check__Request__task_get_emulation_vector_t(__attribute__((__unused__)) __Request__task_get_emulation_vector_t *In0P)
{

	typedef __Request__task_get_emulation_vector_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_get_emulation_vector_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_get_emulation_vector */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_get_emulation_vector
(
	task_t task,
	int *vector_start,
	emulation_vector_t *emulation_vector,
	mach_msg_type_number_t *emulation_vectorCnt
);

/* Routine task_get_emulation_vector */
mig_internal novalue _Xtask_get_emulation_vector
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_get_emulation_vector_t __Request;
	typedef __Reply__task_get_emulation_vector_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_get_emulation_vector_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_get_emulation_vector_t__defined */

#if	UseStaticTemplates
	const static mach_msg_ool_descriptor_t emulation_vectorTemplate = {
		/* addr = */		(void *)0,
		/* size = */		0,
		/* deal = */		FALSE,
		/* copy = */		MACH_MSG_VIRTUAL_COPY,
		/* pad2 = */		0,
		/* type = */		MACH_MSG_OOL_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(3425, "task_get_emulation_vector")
	__BeforeRcvRpc(3425, "task_get_emulation_vector")

#if	defined(__MIG_check__Request__task_get_emulation_vector_t__defined)
	check_result = __MIG_check__Request__task_get_emulation_vector_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_get_emulation_vector_t__defined) */

#if	UseStaticTemplates
	OutP->emulation_vector = emulation_vectorTemplate;
#else	/* UseStaticTemplates */
	OutP->emulation_vector.deallocate =  FALSE;
	OutP->emulation_vector.copy = MACH_MSG_VIRTUAL_COPY;
	OutP->emulation_vector.type = MACH_MSG_OOL_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = task_get_emulation_vector(In0P->Head.msgh_request_port, &OutP->vector_start, (emulation_vector_t *)&(OutP->emulation_vector.address), &OutP->emulation_vectorCnt);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}
	OutP->emulation_vector.size = OutP->emulation_vectorCnt * 4;


	OutP->NDR = NDR_record;


	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(3425, "task_get_emulation_vector")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_set_emulation_vector_t__defined)
#define __MIG_check__Request__task_set_emulation_vector_t__defined
#ifndef __NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start__defined
#if	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#if	defined(__NDR_convert__int_rep__task__emulation_vector_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__int_rep__task__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__emulation_vector_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__int_rep__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__int_rep__task__vm_offset_t)
#elif	defined(__NDR_convert__int_rep__vm_offset_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__int_rep__vm_offset_t)
#elif	defined(__NDR_convert__int_rep__task__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__int_rep__task__natural_t)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__int_rep__natural_t)
#elif	defined(__NDR_convert__int_rep__task__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__int_rep__task__uint32_t)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__int_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vectorCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vectorCnt__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vectorCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vectorCnt__defined
#define	__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vectorCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vectorCnt__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start__defined
#if	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#if	defined(__NDR_convert__char_rep__task__emulation_vector_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__char_rep__task__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__emulation_vector_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__char_rep__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__char_rep__task__vm_offset_t)
#elif	defined(__NDR_convert__char_rep__vm_offset_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__char_rep__vm_offset_t)
#elif	defined(__NDR_convert__char_rep__task__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__char_rep__task__natural_t)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__char_rep__natural_t)
#elif	defined(__NDR_convert__char_rep__task__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__char_rep__task__uint32_t)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__char_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start__defined
#if	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#if	defined(__NDR_convert__float_rep__task__emulation_vector_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__float_rep__task__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__emulation_vector_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__float_rep__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__float_rep__task__vm_offset_t)
#elif	defined(__NDR_convert__float_rep__vm_offset_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__float_rep__vm_offset_t)
#elif	defined(__NDR_convert__float_rep__task__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__float_rep__task__natural_t)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__float_rep__natural_t)
#elif	defined(__NDR_convert__float_rep__task__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__float_rep__task__uint32_t)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__float_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined */


mig_internal kern_return_t __MIG_check__Request__task_set_emulation_vector_t(__attribute__((__unused__)) __Request__task_set_emulation_vector_t *In0P)
{

	typedef __Request__task_set_emulation_vector_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->emulation_vector.type != MACH_MSG_OOL_DESCRIPTOR)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vectorCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start__defined)
		__NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start(&In0P->vector_start, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_emulation_vector_t__vector_start__defined */
#if defined(__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vectorCnt__defined)
		__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vectorCnt(&In0P->emulation_vectorCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vectorCnt__defined */
#if defined(__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined)
		__NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector((emulation_vector_t)(In0P->emulation_vector.address), In0P->NDR.int_rep, In0P->emulation_vectorCnt);
#endif	/* __NDR_convert__int_rep__Request__task_set_emulation_vector_t__emulation_vector__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start__defined) || \
	defined(__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined) || \
	0
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start__defined)
		__NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start(&In0P->vector_start, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_emulation_vector_t__vector_start__defined */
#if defined(__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined)
		__NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector((emulation_vector_t)(In0P->emulation_vector.address), In0P->NDR.char_rep, In0P->emulation_vectorCnt);
#endif	/* __NDR_convert__char_rep__Request__task_set_emulation_vector_t__emulation_vector__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start__defined) || \
	defined(__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined) || \
	0
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start__defined)
		__NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start(&In0P->vector_start, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_emulation_vector_t__vector_start__defined */
#if defined(__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined)
		__NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector((emulation_vector_t)(In0P->emulation_vector.address), In0P->NDR.float_rep, In0P->emulation_vectorCnt);
#endif	/* __NDR_convert__float_rep__Request__task_set_emulation_vector_t__emulation_vector__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_set_emulation_vector_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_emulation_vector */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_set_emulation_vector
(
	task_t task,
	int vector_start,
	emulation_vector_t emulation_vector,
	mach_msg_type_number_t emulation_vectorCnt
);

/* Routine task_set_emulation_vector */
mig_internal novalue _Xtask_set_emulation_vector
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t emulation_vector;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		int vector_start;
		mach_msg_type_number_t emulation_vectorCnt;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_set_emulation_vector_t __Request;
	typedef __Reply__task_set_emulation_vector_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_set_emulation_vector_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_set_emulation_vector_t__defined */

	__DeclareRcvRpc(3426, "task_set_emulation_vector")
	__BeforeRcvRpc(3426, "task_set_emulation_vector")

#if	defined(__MIG_check__Request__task_set_emulation_vector_t__defined)
	check_result = __MIG_check__Request__task_set_emulation_vector_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_set_emulation_vector_t__defined) */

	OutP->RetCode = task_set_emulation_vector(In0P->Head.msgh_request_port, In0P->vector_start, (emulation_vector_t)(In0P->emulation_vector.address), In0P->emulation_vectorCnt);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3426, "task_set_emulation_vector")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_set_ras_pc_t__defined)
#define __MIG_check__Request__task_set_ras_pc_t__defined
#ifndef __NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc__defined
#if	defined(__NDR_convert__int_rep__task__vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__int_rep__task__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__int_rep__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__int_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__int_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__int_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__int_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc__defined
#if	defined(__NDR_convert__int_rep__task__vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__int_rep__task__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_address_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__int_rep__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__int_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__int_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__int_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__int_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc__defined
#if	defined(__NDR_convert__char_rep__task__vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__char_rep__task__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__char_rep__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__char_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__char_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__char_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__char_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc__defined
#if	defined(__NDR_convert__char_rep__task__vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__char_rep__task__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_address_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__char_rep__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__char_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__char_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__char_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__char_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc__defined
#if	defined(__NDR_convert__float_rep__task__vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__float_rep__task__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__float_rep__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__float_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__float_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__float_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc(a, f) \
	__NDR_convert__float_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc__defined
#if	defined(__NDR_convert__float_rep__task__vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__float_rep__task__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_address_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__float_rep__vm_address_t((vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__float_rep__task__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__float_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__float_rep__task__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc__defined
#define	__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc(a, f) \
	__NDR_convert__float_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc__defined */


mig_internal kern_return_t __MIG_check__Request__task_set_ras_pc_t(__attribute__((__unused__)) __Request__task_set_ras_pc_t *In0P)
{

	typedef __Request__task_set_ras_pc_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc__defined)
		__NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc(&In0P->basepc, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_ras_pc_t__basepc__defined */
#if defined(__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc__defined)
		__NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc(&In0P->boundspc, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_ras_pc_t__boundspc__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc__defined) || \
	defined(__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc__defined)
		__NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc(&In0P->basepc, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_ras_pc_t__basepc__defined */
#if defined(__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc__defined)
		__NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc(&In0P->boundspc, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_ras_pc_t__boundspc__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc__defined) || \
	defined(__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc__defined)
		__NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc(&In0P->basepc, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_ras_pc_t__basepc__defined */
#if defined(__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc__defined)
		__NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc(&In0P->boundspc, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_ras_pc_t__boundspc__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_set_ras_pc_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_ras_pc */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_set_ras_pc
(
	task_t target_task,
	vm_address_t basepc,
	vm_address_t boundspc
);

/* Routine task_set_ras_pc */
mig_internal novalue _Xtask_set_ras_pc
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		vm_address_t basepc;
		vm_address_t boundspc;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_set_ras_pc_t __Request;
	typedef __Reply__task_set_ras_pc_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_set_ras_pc_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_set_ras_pc_t__defined */

	__DeclareRcvRpc(3427, "task_set_ras_pc")
	__BeforeRcvRpc(3427, "task_set_ras_pc")

#if	defined(__MIG_check__Request__task_set_ras_pc_t__defined)
	check_result = __MIG_check__Request__task_set_ras_pc_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_set_ras_pc_t__defined) */

	OutP->RetCode = task_set_ras_pc(In0P->Head.msgh_request_port, In0P->basepc, In0P->boundspc);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3427, "task_set_ras_pc")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_assign_t__defined)
#define __MIG_check__Request__task_assign_t__defined
#ifndef __NDR_convert__int_rep__Request__task_assign_t__assign_threads__defined
#if	defined(__NDR_convert__int_rep__task__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_assign_t__assign_threads__defined
#define	__NDR_convert__int_rep__Request__task_assign_t__assign_threads(a, f) \
	__NDR_convert__int_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_assign_t__assign_threads__defined
#define	__NDR_convert__int_rep__Request__task_assign_t__assign_threads(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_assign_t__assign_threads__defined */

#ifndef __NDR_convert__char_rep__Request__task_assign_t__assign_threads__defined
#if	defined(__NDR_convert__char_rep__task__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_assign_t__assign_threads__defined
#define	__NDR_convert__char_rep__Request__task_assign_t__assign_threads(a, f) \
	__NDR_convert__char_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_assign_t__assign_threads__defined
#define	__NDR_convert__char_rep__Request__task_assign_t__assign_threads(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_assign_t__assign_threads__defined */

#ifndef __NDR_convert__float_rep__Request__task_assign_t__assign_threads__defined
#if	defined(__NDR_convert__float_rep__task__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_assign_t__assign_threads__defined
#define	__NDR_convert__float_rep__Request__task_assign_t__assign_threads(a, f) \
	__NDR_convert__float_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_assign_t__assign_threads__defined
#define	__NDR_convert__float_rep__Request__task_assign_t__assign_threads(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_assign_t__assign_threads__defined */


mig_internal kern_return_t __MIG_check__Request__task_assign_t(__attribute__((__unused__)) __Request__task_assign_t *In0P)
{

	typedef __Request__task_assign_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->new_set.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->new_set.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_assign_t__assign_threads__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_assign_t__assign_threads__defined)
		__NDR_convert__int_rep__Request__task_assign_t__assign_threads(&In0P->assign_threads, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_assign_t__assign_threads__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_assign_t__assign_threads__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_assign_t__assign_threads__defined)
		__NDR_convert__char_rep__Request__task_assign_t__assign_threads(&In0P->assign_threads, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_assign_t__assign_threads__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_assign_t__assign_threads__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_assign_t__assign_threads__defined)
		__NDR_convert__float_rep__Request__task_assign_t__assign_threads(&In0P->assign_threads, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_assign_t__assign_threads__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_assign_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_assign */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_assign
(
	task_t task,
	processor_set_t new_set,
	boolean_t assign_threads
);

/* Routine task_assign */
mig_internal novalue _Xtask_assign
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t new_set;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		boolean_t assign_threads;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_assign_t __Request;
	typedef __Reply__task_assign_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_assign_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_assign_t__defined */

	__DeclareRcvRpc(3429, "task_assign")
	__BeforeRcvRpc(3429, "task_assign")

#if	defined(__MIG_check__Request__task_assign_t__defined)
	check_result = __MIG_check__Request__task_assign_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_assign_t__defined) */

	OutP->RetCode = task_assign(In0P->Head.msgh_request_port, In0P->new_set.name, In0P->assign_threads);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3429, "task_assign")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_assign_default_t__defined)
#define __MIG_check__Request__task_assign_default_t__defined
#ifndef __NDR_convert__int_rep__Request__task_assign_default_t__assign_threads__defined
#if	defined(__NDR_convert__int_rep__task__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_assign_default_t__assign_threads__defined
#define	__NDR_convert__int_rep__Request__task_assign_default_t__assign_threads(a, f) \
	__NDR_convert__int_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_assign_default_t__assign_threads__defined
#define	__NDR_convert__int_rep__Request__task_assign_default_t__assign_threads(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_assign_default_t__assign_threads__defined */

#ifndef __NDR_convert__char_rep__Request__task_assign_default_t__assign_threads__defined
#if	defined(__NDR_convert__char_rep__task__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_assign_default_t__assign_threads__defined
#define	__NDR_convert__char_rep__Request__task_assign_default_t__assign_threads(a, f) \
	__NDR_convert__char_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_assign_default_t__assign_threads__defined
#define	__NDR_convert__char_rep__Request__task_assign_default_t__assign_threads(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_assign_default_t__assign_threads__defined */

#ifndef __NDR_convert__float_rep__Request__task_assign_default_t__assign_threads__defined
#if	defined(__NDR_convert__float_rep__task__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_assign_default_t__assign_threads__defined
#define	__NDR_convert__float_rep__Request__task_assign_default_t__assign_threads(a, f) \
	__NDR_convert__float_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_assign_default_t__assign_threads__defined
#define	__NDR_convert__float_rep__Request__task_assign_default_t__assign_threads(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_assign_default_t__assign_threads__defined */


mig_internal kern_return_t __MIG_check__Request__task_assign_default_t(__attribute__((__unused__)) __Request__task_assign_default_t *In0P)
{

	typedef __Request__task_assign_default_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__task_assign_default_t__assign_threads__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_assign_default_t__assign_threads__defined)
		__NDR_convert__int_rep__Request__task_assign_default_t__assign_threads(&In0P->assign_threads, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_assign_default_t__assign_threads__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_assign_default_t__assign_threads__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_assign_default_t__assign_threads__defined)
		__NDR_convert__char_rep__Request__task_assign_default_t__assign_threads(&In0P->assign_threads, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_assign_default_t__assign_threads__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_assign_default_t__assign_threads__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_assign_default_t__assign_threads__defined)
		__NDR_convert__float_rep__Request__task_assign_default_t__assign_threads(&In0P->assign_threads, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_assign_default_t__assign_threads__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_assign_default_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_assign_default */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_assign_default
(
	task_t task,
	boolean_t assign_threads
);

/* Routine task_assign_default */
mig_internal novalue _Xtask_assign_default
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		boolean_t assign_threads;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_assign_default_t __Request;
	typedef __Reply__task_assign_default_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_assign_default_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_assign_default_t__defined */

	__DeclareRcvRpc(3430, "task_assign_default")
	__BeforeRcvRpc(3430, "task_assign_default")

#if	defined(__MIG_check__Request__task_assign_default_t__defined)
	check_result = __MIG_check__Request__task_assign_default_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_assign_default_t__defined) */

	OutP->RetCode = task_assign_default(In0P->Head.msgh_request_port, In0P->assign_threads);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3430, "task_assign_default")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_get_assignment_t__defined)
#define __MIG_check__Request__task_get_assignment_t__defined

mig_internal kern_return_t __MIG_check__Request__task_get_assignment_t(__attribute__((__unused__)) __Request__task_get_assignment_t *In0P)
{

	typedef __Request__task_get_assignment_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_get_assignment_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_get_assignment */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_get_assignment
(
	task_t task,
	processor_set_name_t *assigned_set
);

/* Routine task_get_assignment */
mig_internal novalue _Xtask_get_assignment
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_get_assignment_t __Request;
	typedef __Reply__task_get_assignment_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_get_assignment_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_get_assignment_t__defined */

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t assigned_setTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(3431, "task_get_assignment")
	__BeforeRcvRpc(3431, "task_get_assignment")

#if	defined(__MIG_check__Request__task_get_assignment_t__defined)
	check_result = __MIG_check__Request__task_get_assignment_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_get_assignment_t__defined) */

#if	UseStaticTemplates
	OutP->assigned_set = assigned_setTemplate;
#else	/* UseStaticTemplates */
	OutP->assigned_set.disposition = 19;
	OutP->assigned_set.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = task_get_assignment(In0P->Head.msgh_request_port, &OutP->assigned_set.name);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}

	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(3431, "task_get_assignment")
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__task_subsystem__
#if !defined(__MIG_check__Request__task_set_policy_t__defined)
#define __MIG_check__Request__task_set_policy_t__defined
#ifndef __NDR_convert__int_rep__Request__task_set_policy_t__policy__defined
#if	defined(__NDR_convert__int_rep__task__policy_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__int_rep__task__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__policy_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__int_rep__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_policy_t__policy__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_policy_t__base__defined
#if	defined(__NDR_convert__int_rep__task__policy_base_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__int_rep__task__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__policy_base_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__int_rep__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__integer_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__task__integer_t)
#elif	defined(__NDR_convert__int_rep__integer_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__integer_t)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_policy_t__base__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_policy_t__baseCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__baseCnt__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__baseCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__baseCnt__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__baseCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_policy_t__baseCnt__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_policy_t__limit__defined
#if	defined(__NDR_convert__int_rep__task__policy_limit_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__int_rep__task__policy_limit_t((policy_limit_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__policy_limit_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__int_rep__policy_limit_t((policy_limit_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__integer_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__task__integer_t)
#elif	defined(__NDR_convert__int_rep__integer_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__integer_t)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_policy_t__limit__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_policy_t__limitCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limitCnt__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limitCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limitCnt__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__limitCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_policy_t__limitCnt__defined */

#ifndef __NDR_convert__int_rep__Request__task_set_policy_t__change__defined
#if	defined(__NDR_convert__int_rep__task__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__change__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__change(a, f) \
	__NDR_convert__int_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Request__task_set_policy_t__change__defined
#define	__NDR_convert__int_rep__Request__task_set_policy_t__change(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__task_set_policy_t__change__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_policy_t__policy__defined
#if	defined(__NDR_convert__char_rep__task__policy_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__char_rep__task__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__policy_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__char_rep__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_policy_t__policy__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_policy_t__base__defined
#if	defined(__NDR_convert__char_rep__task__policy_base_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__char_rep__task__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__policy_base_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__char_rep__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__integer_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__task__integer_t)
#elif	defined(__NDR_convert__char_rep__integer_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__integer_t)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_policy_t__base__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_policy_t__limit__defined
#if	defined(__NDR_convert__char_rep__task__policy_limit_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__char_rep__task__policy_limit_t((policy_limit_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__policy_limit_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__char_rep__policy_limit_t((policy_limit_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__integer_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__task__integer_t)
#elif	defined(__NDR_convert__char_rep__integer_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__integer_t)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_policy_t__limit__defined */

#ifndef __NDR_convert__char_rep__Request__task_set_policy_t__change__defined
#if	defined(__NDR_convert__char_rep__task__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__change__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__change(a, f) \
	__NDR_convert__char_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Request__task_set_policy_t__change__defined
#define	__NDR_convert__char_rep__Request__task_set_policy_t__change(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__task_set_policy_t__change__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_policy_t__policy__defined
#if	defined(__NDR_convert__float_rep__task__policy_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__float_rep__task__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__policy_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__float_rep__policy_t((policy_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__policy(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_policy_t__policy__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_policy_t__base__defined
#if	defined(__NDR_convert__float_rep__task__policy_base_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__float_rep__task__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__policy_base_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__float_rep__policy_base_t((policy_base_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__integer_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__task__integer_t)
#elif	defined(__NDR_convert__float_rep__integer_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__integer_t)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__base(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_policy_t__base__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_policy_t__limit__defined
#if	defined(__NDR_convert__float_rep__task__policy_limit_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__float_rep__task__policy_limit_t((policy_limit_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__policy_limit_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__float_rep__policy_limit_t((policy_limit_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__integer_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__task__integer_t)
#elif	defined(__NDR_convert__float_rep__integer_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__integer_t)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__limit(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_policy_t__limit__defined */

#ifndef __NDR_convert__float_rep__Request__task_set_policy_t__change__defined
#if	defined(__NDR_convert__float_rep__task__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__change__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__change(a, f) \
	__NDR_convert__float_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Request__task_set_policy_t__change__defined
#define	__NDR_convert__float_rep__Request__task_set_policy_t__change(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__task_set_policy_t__change__defined */


mig_internal kern_return_t __MIG_check__Request__task_set_policy_t(__attribute__((__unused__)) __Request__task_set_policy_t *In0P, __attribute__((__unused__)) __Request__task_set_policy_t **In1PP, __attribute__((__unused__)) __Request__task_set_policy_t **In2PP)
{

	typedef __Request__task_set_policy_t __Request;
	__Request *In1P;
	__Request *In2P;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	unsigned int msgh_size_delta;

#if	__MigTypeCheck
	msgh_size = In0P->Head.msgh_size;
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (msgh_size < (mach_msg_size_t)(sizeof(__Request) - 24)) ||  (msgh_size > (mach_msg_size_t)sizeof(__Request))
)
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->pset.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->pset.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Request__task_set_policy_t__baseCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Request__task_set_policy_t__baseCnt(&In0P->baseCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_policy_t__baseCnt__defined */
	msgh_size_delta = (4 * In0P->baseCnt);
#if	__MigTypeCheck
	if (msgh_size < (mach_msg_size_t)(sizeof(__Request) - 24) + msgh_size_delta)
		return MIG_BAD_ARGUMENTS;
	msgh_size -= msgh_size_delta;
#endif	/* __MigTypeCheck */

	*In1PP = In1P = (__Request *) ((pointer_t) In0P + msgh_size_delta - 20);

#if defined(__NDR_convert__int_rep__Request__task_set_policy_t__limitCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Request__task_set_policy_t__limitCnt(&In1P->limitCnt, In1P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_policy_t__limitCnt__defined */
	msgh_size_delta = (4 * In1P->limitCnt);
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Request) - 24) + msgh_size_delta)
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

	*In2PP = In2P = (__Request *) ((pointer_t) In1P + msgh_size_delta - 4);

#if	defined(__NDR_convert__int_rep__Request__task_set_policy_t__policy__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_policy_t__base__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_policy_t__baseCnt__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_policy_t__limit__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_policy_t__limitCnt__defined) || \
	defined(__NDR_convert__int_rep__Request__task_set_policy_t__change__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__task_set_policy_t__policy__defined)
		__NDR_convert__int_rep__Request__task_set_policy_t__policy(&In0P->policy, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_policy_t__policy__defined */
#if defined(__NDR_convert__int_rep__Request__task_set_policy_t__base__defined)
		__NDR_convert__int_rep__Request__task_set_policy_t__base(&In0P->base, In0P->NDR.int_rep, In0P->baseCnt);
#endif	/* __NDR_convert__int_rep__Request__task_set_policy_t__base__defined */
#if defined(__NDR_convert__int_rep__Request__task_set_policy_t__limit__defined)
		__NDR_convert__int_rep__Request__task_set_policy_t__limit(&In1P->limit, In0P->NDR.int_rep, In1P->limitCnt);
#endif	/* __NDR_convert__int_rep__Request__task_set_policy_t__limit__defined */
#if defined(__NDR_convert__int_rep__Request__task_set_policy_t__change__defined)
		__NDR_convert__int_rep__Request__task_set_policy_t__change(&In2P->change, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__task_set_policy_t__change__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__task_set_policy_t__policy__defined) || \
	defined(__NDR_convert__char_rep__Request__task_set_policy_t__base__defined) || \
	0 || \
	defined(__NDR_convert__char_rep__Request__task_set_policy_t__limit__defined) || \
	0 || \
	defined(__NDR_convert__char_rep__Request__task_set_policy_t__change__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__task_set_policy_t__policy__defined)
		__NDR_convert__char_rep__Request__task_set_policy_t__policy(&In0P->policy, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_policy_t__policy__defined */
#if defined(__NDR_convert__char_rep__Request__task_set_policy_t__base__defined)
		__NDR_convert__char_rep__Request__task_set_policy_t__base(&In0P->base, In0P->NDR.char_rep, In0P->baseCnt);
#endif	/* __NDR_convert__char_rep__Request__task_set_policy_t__base__defined */
#if defined(__NDR_convert__char_rep__Request__task_set_policy_t__limit__defined)
		__NDR_convert__char_rep__Request__task_set_policy_t__limit(&In1P->limit, In0P->NDR.char_rep, In1P->limitCnt);
#endif	/* __NDR_convert__char_rep__Request__task_set_policy_t__limit__defined */
#if defined(__NDR_convert__char_rep__Request__task_set_policy_t__change__defined)
		__NDR_convert__char_rep__Request__task_set_policy_t__change(&In2P->change, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__task_set_policy_t__change__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__task_set_policy_t__policy__defined) || \
	defined(__NDR_convert__float_rep__Request__task_set_policy_t__base__defined) || \
	0 || \
	defined(__NDR_convert__float_rep__Request__task_set_policy_t__limit__defined) || \
	0 || \
	defined(__NDR_convert__float_rep__Request__task_set_policy_t__change__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__task_set_policy_t__policy__defined)
		__NDR_convert__float_rep__Request__task_set_policy_t__policy(&In0P->policy, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_policy_t__policy__defined */
#if defined(__NDR_convert__float_rep__Request__task_set_policy_t__base__defined)
		__NDR_convert__float_rep__Request__task_set_policy_t__base(&In0P->base, In0P->NDR.float_rep, In0P->baseCnt);
#endif	/* __NDR_convert__float_rep__Request__task_set_policy_t__base__defined */
#if defined(__NDR_convert__float_rep__Request__task_set_policy_t__limit__defined)
		__NDR_convert__float_rep__Request__task_set_policy_t__limit(&In1P->limit, In0P->NDR.float_rep, In1P->limitCnt);
#endif	/* __NDR_convert__float_rep__Request__task_set_policy_t__limit__defined */
#if defined(__NDR_convert__float_rep__Request__task_set_policy_t__change__defined)
		__NDR_convert__float_rep__Request__task_set_policy_t__change(&In2P->change, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__task_set_policy_t__change__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__task_set_policy_t__defined) */
#endif /* __MIG_check__Request__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_policy */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t task_set_policy
(
	task_t task,
	processor_set_t pset,
	policy_t policy,
	policy_base_t base,
	mach_msg_type_number_t baseCnt,
	policy_limit_t limit,
	mach_msg_type_number_t limitCnt,
	boolean_t change
);

/* Routine task_set_policy */
mig_internal novalue _Xtask_set_policy
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t pset;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		policy_t policy;
		mach_msg_type_number_t baseCnt;
		integer_t base[5];
		mach_msg_type_number_t limitCnt;
		integer_t limit[1];
		boolean_t change;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__task_set_policy_t __Request;
	typedef __Reply__task_set_policy_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Request *In1P;
	Request *In2P;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__task_set_policy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__task_set_policy_t__defined */

	__DeclareRcvRpc(3432, "task_set_policy")
	__BeforeRcvRpc(3432, "task_set_policy")

#if	defined(__MIG_check__Request__task_set_policy_t__defined)
	check_result = __MIG_check__Request__task_set_policy_t((__Request *)In0P, (__Request **)&In1P, (__Request **)&In2P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__task_set_policy_t__defined) */

	OutP->RetCode = task_set_policy(In0P->Head.msgh_request_port, In0P->pset.name, In0P->policy, In0P->base, In0P->baseCnt, In1P->limit, In1P->limitCnt, In2P->change);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(3432, "task_set_policy")
}


extern boolean_t task_server(
		mach_msg_header_t *InHeadP,
		mach_msg_header_t *OutHeadP);

extern mig_routine_t task_server_routine(
		mach_msg_header_t *InHeadP);


/* Description of this subsystem, for use in direct RPC */
const struct task_subsystem {
	mig_server_routine_t 	server;	/* Server routine */
	mach_msg_id_t	start;	/* Min routine number */
	mach_msg_id_t	end;	/* Max routine number + 1 */
	unsigned int	maxsize;	/* Max msg size */
	vm_address_t	reserved;	/* Reserved */
	struct routine_descriptor	/*Array of routine descriptors */
		routine[33];
} task_subsystem = {
	task_server_routine,
	3400,
	3433,
	(mach_msg_size_t)sizeof(union __ReplyUnion__task_subsystem),
	(vm_address_t)0,
	{
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_create, 5, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_create_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_terminate, 1, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_terminate_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_threads, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_threads_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_ports_register, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_ports_register_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xmach_ports_lookup, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__mach_ports_lookup_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_info, 4, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_info_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_set_info, 4, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_set_info_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_suspend, 1, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_suspend_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_resume, 1, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_resume_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_get_special_port, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_get_special_port_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_set_special_port, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_set_special_port_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xthread_create, 2, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__thread_create_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xthread_create_running, 5, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__thread_create_running_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_set_exception_ports, 5, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_set_exception_ports_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_get_exception_ports, 7, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_get_exception_ports_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_swap_exception_ports, 10, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_swap_exception_ports_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xlock_set_create, 4, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__lock_set_create_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xlock_set_destroy, 2, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__lock_set_destroy_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xsemaphore_create, 4, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__semaphore_create_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xsemaphore_destroy, 2, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__semaphore_destroy_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_policy_set, 4, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_policy_set_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_policy_get, 5, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_policy_get_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_sample, 2, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_sample_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_policy, 6, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_policy_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_set_emulation, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_set_emulation_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_get_emulation_vector, 4, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_get_emulation_vector_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_set_emulation_vector, 4, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_set_emulation_vector_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_set_ras_pc, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_set_ras_pc_t)},
		{0, 0, 0, 0, 0, 0},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_assign, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_assign_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_assign_default, 2, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_assign_default_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_get_assignment, 2, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_get_assignment_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xtask_set_policy, 8, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__task_set_policy_t)},
	}
};

mig_external boolean_t task_server
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

	if ((InHeadP->msgh_id > 3432) || (InHeadP->msgh_id < 3400) ||
	    ((routine = task_subsystem.routine[InHeadP->msgh_id - 3400].stub_routine) == 0)) {
		((mig_reply_error_t *)OutHeadP)->NDR = NDR_record;
		((mig_reply_error_t *)OutHeadP)->RetCode = MIG_BAD_ID;
		return FALSE;
	}
	(*routine) (InHeadP, OutHeadP);
	return TRUE;
}

mig_external mig_routine_t task_server_routine
	(mach_msg_header_t *InHeadP)
{
	register int msgh_id;

	msgh_id = InHeadP->msgh_id - 3400;

	if ((msgh_id > 32) || (msgh_id < 0))
		return 0;

	return task_subsystem.routine[msgh_id].stub_routine;
}
