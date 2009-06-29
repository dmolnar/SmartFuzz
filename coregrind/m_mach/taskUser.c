/*
 * IDENTIFICATION:
 * stub generated Mon Jun 15 19:50:16 2009
 * with a MiG generated Tue Feb 19 02:01:43 PST 2008 by root@b75.local
 * OPTIONS: 
 */
#define	__MIG_check__Reply__task_subsystem__ 1
#define	__NDR_convert__Reply__task_subsystem__ 1
#define	__NDR_convert__mig_reply_error_subsystem__ 1

#include "task.h"


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

#ifndef	__MachMsgErrorWithTimeout
#define	__MachMsgErrorWithTimeout(_R_) { \
	switch (_R_) { \
	case MACH_SEND_INVALID_REPLY: \
	case MACH_RCV_INVALID_NAME: \
	case MACH_RCV_PORT_DIED: \
	case MACH_RCV_PORT_CHANGED: \
	case MACH_RCV_TIMED_OUT: \
		mig_dealloc_reply_port(InP->Head.msgh_reply_port); \
		break; \
	default: \
		mig_put_reply_port(InP->Head.msgh_reply_port); \
	} \
}
#endif	/* __MachMsgErrorWithTimeout */

#ifndef	__MachMsgErrorWithoutTimeout
#define	__MachMsgErrorWithoutTimeout(_R_) { \
	switch (_R_) { \
	case MACH_SEND_INVALID_REPLY: \
	case MACH_RCV_INVALID_NAME: \
	case MACH_RCV_PORT_DIED: \
	case MACH_RCV_PORT_CHANGED: \
		mig_dealloc_reply_port(InP->Head.msgh_reply_port); \
		break; \
	default: \
		mig_put_reply_port(InP->Head.msgh_reply_port); \
	} \
}
#endif	/* __MachMsgErrorWithoutTimeout */

#ifndef	__DeclareSendRpc
#define	__DeclareSendRpc(_NUM_, _NAME_)
#endif	/* __DeclareSendRpc */

#ifndef	__BeforeSendRpc
#define	__BeforeSendRpc(_NUM_, _NAME_)
#endif	/* __BeforeSendRpc */

#ifndef	__AfterSendRpc
#define	__AfterSendRpc(_NUM_, _NAME_)
#endif	/* __AfterSendRpc */

#ifndef	__DeclareSendSimple
#define	__DeclareSendSimple(_NUM_, _NAME_)
#endif	/* __DeclareSendSimple */

#ifndef	__BeforeSendSimple
#define	__BeforeSendSimple(_NUM_, _NAME_)
#endif	/* __BeforeSendSimple */

#ifndef	__AfterSendSimple
#define	__AfterSendSimple(_NUM_, _NAME_)
#endif	/* __AfterSendSimple */

#define msgh_request_port	msgh_remote_port
#define msgh_reply_port		msgh_local_port



#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_create_t__defined)
#define __MIG_check__Reply__task_create_t__defined

mig_internal kern_return_t __MIG_check__Reply__task_create_t(__Reply__task_create_t *Out0P)
{

	typedef __Reply__task_create_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3500) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	if (Out0P->child_task.type != MACH_MSG_PORT_DESCRIPTOR ||
	    Out0P->child_task.disposition != 17)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__task_create_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_create */
mig_external kern_return_t task_create
(
	task_t target_task,
	ledger_array_t ledgers,
	mach_msg_type_number_t ledgersCnt,
	boolean_t inherit_memory,
	task_t *child_task
)
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
	} Request;
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
		mach_msg_port_descriptor_t child_task;
		/* end of the kernel processed data */
		mach_msg_trailer_t trailer;
	} Reply;
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
		mach_msg_port_descriptor_t child_task;
		/* end of the kernel processed data */
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_create_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_create_t__defined */

	__DeclareSendRpc(3400, "task_create")

#if	UseStaticTemplates
	const static mach_msg_ool_ports_descriptor_t ledgersTemplate = {
		/* addr = */		(void *)0,
		/* coun = */		0,
		/* deal = */		FALSE,
		/* copy is meaningful only in overwrite mode */
		/* copy = */		MACH_MSG_PHYSICAL_COPY,
		/* disp = */		19,
		/* type = */		MACH_MSG_OOL_PORTS_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->ledgers = ledgersTemplate;
	InP->ledgers.address = (void *)(ledgers);
	InP->ledgers.count = ledgersCnt;
#else	/* UseStaticTemplates */
	InP->ledgers.address = (void *)(ledgers);
	InP->ledgers.count = ledgersCnt;
	InP->ledgers.disposition = 19;
	InP->ledgers.deallocate =  FALSE;
	InP->ledgers.type = MACH_MSG_OOL_PORTS_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	InP->NDR = NDR_record;

	InP->ledgersCnt = ledgersCnt;

	InP->inherit_memory = inherit_memory;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3400;

	__BeforeSendRpc(3400, "task_create")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3400, "task_create")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_create_t__defined)
	check_result = __MIG_check__Reply__task_create_t((__Reply__task_create_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_create_t__defined) */

	*child_task = Out0P->child_task.name;
	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_terminate_t__defined)
#define __MIG_check__Reply__task_terminate_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_terminate_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_terminate_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_terminate_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_terminate_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_terminate_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_terminate_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_terminate_t(__Reply__task_terminate_t *Out0P)
{

	typedef __Reply__task_terminate_t __Reply;
	if (Out0P->Head.msgh_id != 3501) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_terminate_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_terminate_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_terminate_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_terminate_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_terminate */
mig_external kern_return_t task_terminate
(
	task_t target_task
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_terminate_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_terminate_t__defined */

	__DeclareSendRpc(3401, "task_terminate")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3401;

	__BeforeSendRpc(3401, "task_terminate")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3401, "task_terminate")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_terminate_t__defined)
	check_result = __MIG_check__Reply__task_terminate_t((__Reply__task_terminate_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_terminate_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_threads_t__defined)
#define __MIG_check__Reply__task_threads_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_threads_t__act_listCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_threads_t__act_listCnt__defined
#define	__NDR_convert__int_rep__Reply__task_threads_t__act_listCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_threads_t__act_listCnt__defined
#define	__NDR_convert__int_rep__Reply__task_threads_t__act_listCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_threads_t__act_listCnt__defined */





mig_internal kern_return_t __MIG_check__Reply__task_threads_t(__Reply__task_threads_t *Out0P)
{

	typedef __Reply__task_threads_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3502) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	if (Out0P->act_list.type != MACH_MSG_OOL_PORTS_DESCRIPTOR ||
	    Out0P->act_list.disposition != 17)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__task_threads_t__act_listCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__task_threads_t__act_listCnt__defined)
		__NDR_convert__int_rep__Reply__task_threads_t__act_listCnt(&Out0P->act_listCnt, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__task_threads_t__act_listCnt__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__task_threads_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_threads */
mig_external kern_return_t task_threads
(
	task_t target_task,
	thread_act_array_t *act_list,
	mach_msg_type_number_t *act_listCnt
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_threads_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_threads_t__defined */

	__DeclareSendRpc(3402, "task_threads")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3402;

	__BeforeSendRpc(3402, "task_threads")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3402, "task_threads")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_threads_t__defined)
	check_result = __MIG_check__Reply__task_threads_t((__Reply__task_threads_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_threads_t__defined) */

	*act_list = (thread_act_array_t)(Out0P->act_list.address);
	*act_listCnt = Out0P->act_listCnt;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__mach_ports_register_t__defined)
#define __MIG_check__Reply__mach_ports_register_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_ports_register_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_ports_register_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_ports_register_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_ports_register_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_ports_register_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_ports_register_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__mach_ports_register_t(__Reply__mach_ports_register_t *Out0P)
{

	typedef __Reply__mach_ports_register_t __Reply;
	if (Out0P->Head.msgh_id != 3503) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__mach_ports_register_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__mach_ports_register_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__mach_ports_register_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__mach_ports_register_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_ports_register */
mig_external kern_return_t mach_ports_register
(
	task_t target_task,
	mach_port_array_t init_port_set,
	mach_msg_type_number_t init_port_setCnt
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__mach_ports_register_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_ports_register_t__defined */

	__DeclareSendRpc(3403, "mach_ports_register")

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

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->init_port_set = init_port_setTemplate;
	InP->init_port_set.address = (void *)(init_port_set);
	InP->init_port_set.count = init_port_setCnt;
#else	/* UseStaticTemplates */
	InP->init_port_set.address = (void *)(init_port_set);
	InP->init_port_set.count = init_port_setCnt;
	InP->init_port_set.disposition = 19;
	InP->init_port_set.deallocate =  FALSE;
	InP->init_port_set.type = MACH_MSG_OOL_PORTS_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	InP->NDR = NDR_record;

	InP->init_port_setCnt = init_port_setCnt;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3403;

	__BeforeSendRpc(3403, "mach_ports_register")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3403, "mach_ports_register")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_ports_register_t__defined)
	check_result = __MIG_check__Reply__mach_ports_register_t((__Reply__mach_ports_register_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_ports_register_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__mach_ports_lookup_t__defined)
#define __MIG_check__Reply__mach_ports_lookup_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_ports_lookup_t__init_port_setCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_ports_lookup_t__init_port_setCnt__defined
#define	__NDR_convert__int_rep__Reply__mach_ports_lookup_t__init_port_setCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_ports_lookup_t__init_port_setCnt__defined
#define	__NDR_convert__int_rep__Reply__mach_ports_lookup_t__init_port_setCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_ports_lookup_t__init_port_setCnt__defined */





mig_internal kern_return_t __MIG_check__Reply__mach_ports_lookup_t(__Reply__mach_ports_lookup_t *Out0P)
{

	typedef __Reply__mach_ports_lookup_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3504) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	if (Out0P->init_port_set.type != MACH_MSG_OOL_PORTS_DESCRIPTOR ||
	    Out0P->init_port_set.disposition != 17)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__mach_ports_lookup_t__init_port_setCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_ports_lookup_t__init_port_setCnt__defined)
		__NDR_convert__int_rep__Reply__mach_ports_lookup_t__init_port_setCnt(&Out0P->init_port_setCnt, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_ports_lookup_t__init_port_setCnt__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_ports_lookup_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_ports_lookup */
mig_external kern_return_t mach_ports_lookup
(
	task_t target_task,
	mach_port_array_t *init_port_set,
	mach_msg_type_number_t *init_port_setCnt
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__mach_ports_lookup_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_ports_lookup_t__defined */

	__DeclareSendRpc(3404, "mach_ports_lookup")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3404;

	__BeforeSendRpc(3404, "mach_ports_lookup")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3404, "mach_ports_lookup")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_ports_lookup_t__defined)
	check_result = __MIG_check__Reply__mach_ports_lookup_t((__Reply__mach_ports_lookup_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_ports_lookup_t__defined) */

	*init_port_set = (mach_port_array_t)(Out0P->init_port_set.address);
	*init_port_setCnt = Out0P->init_port_setCnt;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_info_t__defined)
#define __MIG_check__Reply__task_info_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_info_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_info_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_info_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_info_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_info_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_info_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__task_info_t__task_info_out__defined
#if	defined(__NDR_convert__int_rep__task__task_info_t__defined)
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__int_rep__task__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task_info_t__defined)
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__int_rep__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__task__integer_t)
#elif	defined(__NDR_convert__int_rep__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__integer_t)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_info_t__task_info_out__defined */


#ifndef __NDR_convert__int_rep__Reply__task_info_t__task_info_outCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_outCnt__defined
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_outCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_outCnt__defined
#define	__NDR_convert__int_rep__Reply__task_info_t__task_info_outCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_info_t__task_info_outCnt__defined */



#ifndef __NDR_convert__char_rep__Reply__task_info_t__task_info_out__defined
#if	defined(__NDR_convert__char_rep__task__task_info_t__defined)
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__char_rep__task__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task_info_t__defined)
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__char_rep__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__task__integer_t)
#elif	defined(__NDR_convert__char_rep__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__integer_t)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__char_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__task_info_t__task_info_out__defined */




#ifndef __NDR_convert__float_rep__Reply__task_info_t__task_info_out__defined
#if	defined(__NDR_convert__float_rep__task__task_info_t__defined)
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__float_rep__task__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task_info_t__defined)
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__float_rep__task_info_t((task_info_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__task__integer_t)
#elif	defined(__NDR_convert__float_rep__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__integer_t)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out__defined
#define	__NDR_convert__float_rep__Reply__task_info_t__task_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__task_info_t__task_info_out__defined */




mig_internal kern_return_t __MIG_check__Reply__task_info_t(__Reply__task_info_t *Out0P)
{

	typedef __Reply__task_info_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */

	if (Out0P->Head.msgh_id != 3505) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size > (mach_msg_size_t)sizeof(__Reply) || msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 40)) &&
	     (msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	      Out0P->RetCode == KERN_SUCCESS)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (Out0P->RetCode != KERN_SUCCESS) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if defined(__NDR_convert__int_rep__Reply__task_info_t__task_info_outCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_info_t__task_info_outCnt(&Out0P->task_info_outCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_info_t__task_info_outCnt__defined */
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Reply) - 40) + ((4 * Out0P->task_info_outCnt)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__task_info_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_info_t__task_info_out__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_info_t__task_info_outCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__task_info_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__task_info_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__task_info_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__task_info_t__task_info_out__defined)
		__NDR_convert__int_rep__Reply__task_info_t__task_info_out(&Out0P->task_info_out, Out0P->NDR.int_rep, Out0P->task_info_outCnt);
#endif /* __NDR_convert__int_rep__Reply__task_info_t__task_info_out__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__task_info_t__task_info_out__defined) || \
	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__task_info_t__task_info_out__defined)
		__NDR_convert__char_rep__Reply__task_info_t__task_info_out(&Out0P->task_info_out, Out0P->NDR.char_rep, Out0P->task_info_outCnt);
#endif /* __NDR_convert__char_rep__Reply__task_info_t__task_info_out__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__task_info_t__task_info_out__defined) || \
	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__task_info_t__task_info_out__defined)
		__NDR_convert__float_rep__Reply__task_info_t__task_info_out(&Out0P->task_info_out, Out0P->NDR.float_rep, Out0P->task_info_outCnt);
#endif /* __NDR_convert__float_rep__Reply__task_info_t__task_info_out__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__task_info_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_info */
mig_external kern_return_t task_info
(
	task_name_t target_task,
	task_flavor_t flavor,
	task_info_t task_info_out,
	mach_msg_type_number_t *task_info_outCnt
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_flavor_t flavor;
		mach_msg_type_number_t task_info_outCnt;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_info_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_info_t__defined */

	__DeclareSendRpc(3405, "task_info")

	InP->NDR = NDR_record;

	InP->flavor = flavor;

	if (*task_info_outCnt < 10)
		InP->task_info_outCnt = *task_info_outCnt;
	else
		InP->task_info_outCnt = 10;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3405;

	__BeforeSendRpc(3405, "task_info")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3405, "task_info")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_info_t__defined)
	check_result = __MIG_check__Reply__task_info_t((__Reply__task_info_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_info_t__defined) */

	if (Out0P->task_info_outCnt > *task_info_outCnt) {
		(void)memcpy((char *) task_info_out, (const char *) Out0P->task_info_out, 4 *  *task_info_outCnt);
		*task_info_outCnt = Out0P->task_info_outCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) task_info_out, (const char *) Out0P->task_info_out, 4 * Out0P->task_info_outCnt);

	*task_info_outCnt = Out0P->task_info_outCnt;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_set_info_t__defined)
#define __MIG_check__Reply__task_set_info_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_set_info_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_info_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_info_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_info_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_info_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_set_info_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_set_info_t(__Reply__task_set_info_t *Out0P)
{

	typedef __Reply__task_set_info_t __Reply;
	if (Out0P->Head.msgh_id != 3506) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_set_info_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_set_info_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_set_info_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_set_info_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_info */
mig_external kern_return_t task_set_info
(
	task_t target_task,
	task_flavor_t flavor,
	task_info_t task_info_in,
	mach_msg_type_number_t task_info_inCnt
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;
	unsigned int msgh_size;

#ifdef	__MIG_check__Reply__task_set_info_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_set_info_t__defined */

	__DeclareSendRpc(3406, "task_set_info")

	InP->NDR = NDR_record;

	InP->flavor = flavor;

	if (task_info_inCnt > 10) {
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) InP->task_info_in, (const char *) task_info_in, 4 * task_info_inCnt);

	InP->task_info_inCnt = task_info_inCnt;

	msgh_size = (mach_msg_size_t)(sizeof(Request) - 40) + ((4 * task_info_inCnt));
	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3406;

	__BeforeSendRpc(3406, "task_set_info")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3406, "task_set_info")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_set_info_t__defined)
	check_result = __MIG_check__Reply__task_set_info_t((__Reply__task_set_info_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_set_info_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_suspend_t__defined)
#define __MIG_check__Reply__task_suspend_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_suspend_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_suspend_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_suspend_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_suspend_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_suspend_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_suspend_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_suspend_t(__Reply__task_suspend_t *Out0P)
{

	typedef __Reply__task_suspend_t __Reply;
	if (Out0P->Head.msgh_id != 3507) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_suspend_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_suspend_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_suspend_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_suspend_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_suspend */
mig_external kern_return_t task_suspend
(
	task_t target_task
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_suspend_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_suspend_t__defined */

	__DeclareSendRpc(3407, "task_suspend")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3407;

	__BeforeSendRpc(3407, "task_suspend")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3407, "task_suspend")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_suspend_t__defined)
	check_result = __MIG_check__Reply__task_suspend_t((__Reply__task_suspend_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_suspend_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_resume_t__defined)
#define __MIG_check__Reply__task_resume_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_resume_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_resume_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_resume_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_resume_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_resume_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_resume_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_resume_t(__Reply__task_resume_t *Out0P)
{

	typedef __Reply__task_resume_t __Reply;
	if (Out0P->Head.msgh_id != 3508) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_resume_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_resume_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_resume_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_resume_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_resume */
mig_external kern_return_t task_resume
(
	task_t target_task
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_resume_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_resume_t__defined */

	__DeclareSendRpc(3408, "task_resume")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3408;

	__BeforeSendRpc(3408, "task_resume")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3408, "task_resume")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_resume_t__defined)
	check_result = __MIG_check__Reply__task_resume_t((__Reply__task_resume_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_resume_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_get_special_port_t__defined)
#define __MIG_check__Reply__task_get_special_port_t__defined

mig_internal kern_return_t __MIG_check__Reply__task_get_special_port_t(__Reply__task_get_special_port_t *Out0P)
{

	typedef __Reply__task_get_special_port_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3509) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	if (Out0P->special_port.type != MACH_MSG_PORT_DESCRIPTOR ||
	    Out0P->special_port.disposition != 17)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__task_get_special_port_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_get_special_port */
mig_external kern_return_t task_get_special_port
(
	task_t task,
	int which_port,
	mach_port_t *special_port
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int which_port;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_get_special_port_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_get_special_port_t__defined */

	__DeclareSendRpc(3409, "task_get_special_port")

	InP->NDR = NDR_record;

	InP->which_port = which_port;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3409;

	__BeforeSendRpc(3409, "task_get_special_port")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3409, "task_get_special_port")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_get_special_port_t__defined)
	check_result = __MIG_check__Reply__task_get_special_port_t((__Reply__task_get_special_port_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_get_special_port_t__defined) */

	*special_port = Out0P->special_port.name;
	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_set_special_port_t__defined)
#define __MIG_check__Reply__task_set_special_port_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_set_special_port_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_special_port_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_special_port_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_special_port_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_special_port_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_set_special_port_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_set_special_port_t(__Reply__task_set_special_port_t *Out0P)
{

	typedef __Reply__task_set_special_port_t __Reply;
	if (Out0P->Head.msgh_id != 3510) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_set_special_port_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_set_special_port_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_set_special_port_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_set_special_port_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_special_port */
mig_external kern_return_t task_set_special_port
(
	task_t task,
	int which_port,
	mach_port_t special_port
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_set_special_port_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_set_special_port_t__defined */

	__DeclareSendRpc(3410, "task_set_special_port")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t special_portTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->special_port = special_portTemplate;
	InP->special_port.name = special_port;
#else	/* UseStaticTemplates */
	InP->special_port.name = special_port;
	InP->special_port.disposition = 19;
	InP->special_port.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->which_port = which_port;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3410;

	__BeforeSendRpc(3410, "task_set_special_port")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3410, "task_set_special_port")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_set_special_port_t__defined)
	check_result = __MIG_check__Reply__task_set_special_port_t((__Reply__task_set_special_port_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_set_special_port_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__thread_create_t__defined)
#define __MIG_check__Reply__thread_create_t__defined

mig_internal kern_return_t __MIG_check__Reply__thread_create_t(__Reply__thread_create_t *Out0P)
{

	typedef __Reply__thread_create_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3511) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	if (Out0P->child_act.type != MACH_MSG_PORT_DESCRIPTOR ||
	    Out0P->child_act.disposition != 17)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__thread_create_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_create */
mig_external kern_return_t thread_create
(
	task_t parent_task,
	thread_act_t *child_act
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__thread_create_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_create_t__defined */

	__DeclareSendRpc(3411, "thread_create")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = parent_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3411;

	__BeforeSendRpc(3411, "thread_create")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3411, "thread_create")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_create_t__defined)
	check_result = __MIG_check__Reply__thread_create_t((__Reply__thread_create_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_create_t__defined) */

	*child_act = Out0P->child_act.name;
	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__thread_create_running_t__defined)
#define __MIG_check__Reply__thread_create_running_t__defined

mig_internal kern_return_t __MIG_check__Reply__thread_create_running_t(__Reply__thread_create_running_t *Out0P)
{

	typedef __Reply__thread_create_running_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3512) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	if (Out0P->child_act.type != MACH_MSG_PORT_DESCRIPTOR ||
	    Out0P->child_act.disposition != 17)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__thread_create_running_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_create_running */
mig_external kern_return_t thread_create_running
(
	task_t parent_task,
	thread_state_flavor_t flavor,
	thread_state_t new_state,
	mach_msg_type_number_t new_stateCnt,
	thread_act_t *child_act
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;
	unsigned int msgh_size;

#ifdef	__MIG_check__Reply__thread_create_running_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_create_running_t__defined */

	__DeclareSendRpc(3412, "thread_create_running")

	InP->NDR = NDR_record;

	InP->flavor = flavor;

	if (new_stateCnt > 144) {
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) InP->new_state, (const char *) new_state, 4 * new_stateCnt);

	InP->new_stateCnt = new_stateCnt;

	msgh_size = (mach_msg_size_t)(sizeof(Request) - 576) + ((4 * new_stateCnt));
	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = parent_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3412;

	__BeforeSendRpc(3412, "thread_create_running")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3412, "thread_create_running")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_create_running_t__defined)
	check_result = __MIG_check__Reply__thread_create_running_t((__Reply__thread_create_running_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_create_running_t__defined) */

	*child_act = Out0P->child_act.name;
	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_set_exception_ports_t__defined)
#define __MIG_check__Reply__task_set_exception_ports_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_set_exception_ports_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_exception_ports_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_exception_ports_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_exception_ports_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_exception_ports_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_set_exception_ports_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_set_exception_ports_t(__Reply__task_set_exception_ports_t *Out0P)
{

	typedef __Reply__task_set_exception_ports_t __Reply;
	if (Out0P->Head.msgh_id != 3513) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_set_exception_ports_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_set_exception_ports_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_set_exception_ports_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_set_exception_ports_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_exception_ports */
mig_external kern_return_t task_set_exception_ports
(
	task_t task,
	exception_mask_t exception_mask,
	mach_port_t new_port,
	exception_behavior_t behavior,
	thread_state_flavor_t new_flavor
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_set_exception_ports_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_set_exception_ports_t__defined */

	__DeclareSendRpc(3413, "task_set_exception_ports")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t new_portTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->new_port = new_portTemplate;
	InP->new_port.name = new_port;
#else	/* UseStaticTemplates */
	InP->new_port.name = new_port;
	InP->new_port.disposition = 19;
	InP->new_port.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->exception_mask = exception_mask;

	InP->behavior = behavior;

	InP->new_flavor = new_flavor;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3413;

	__BeforeSendRpc(3413, "task_set_exception_ports")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3413, "task_set_exception_ports")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_set_exception_ports_t__defined)
	check_result = __MIG_check__Reply__task_set_exception_ports_t((__Reply__task_set_exception_ports_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_set_exception_ports_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_get_exception_ports_t__defined)
#define __MIG_check__Reply__task_get_exception_ports_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined
#if	defined(__NDR_convert__int_rep__task__exception_mask_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__int_rep__task__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_mask_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__int_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__int_rep__task__exception_mask_t)
#elif	defined(__NDR_convert__int_rep__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__int_rep__exception_mask_t)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__task__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined */


#ifndef __NDR_convert__int_rep__Reply__task_get_exception_ports_t__masksCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masksCnt__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masksCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masksCnt__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masksCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_get_exception_ports_t__masksCnt__defined */


#ifndef __NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__int_rep__task__exception_behavior_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__int_rep__task__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__int_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__int_rep__task__exception_behavior_t)
#elif	defined(__NDR_convert__int_rep__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__int_rep__exception_behavior_t)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__task__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__int_rep__task__exception_flavor_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__int_rep__task__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__int_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__int_rep__task__thread_state_flavor_t)
#elif	defined(__NDR_convert__int_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__int_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__task__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined */


#ifndef __NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined
#if	defined(__NDR_convert__char_rep__task__exception_mask_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__char_rep__task__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_mask_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__char_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__char_rep__task__exception_mask_t)
#elif	defined(__NDR_convert__char_rep__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__char_rep__exception_mask_t)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__task__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined */



#ifndef __NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__char_rep__task__exception_behavior_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__char_rep__task__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__char_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__char_rep__task__exception_behavior_t)
#elif	defined(__NDR_convert__char_rep__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__char_rep__exception_behavior_t)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__task__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__char_rep__task__exception_flavor_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__char_rep__task__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__char_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__char_rep__task__thread_state_flavor_t)
#elif	defined(__NDR_convert__char_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__char_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__task__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined */


#ifndef __NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined
#if	defined(__NDR_convert__float_rep__task__exception_mask_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__float_rep__task__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_mask_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__float_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__float_rep__task__exception_mask_t)
#elif	defined(__NDR_convert__float_rep__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__float_rep__exception_mask_t)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__task__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined */



#ifndef __NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__float_rep__task__exception_behavior_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__float_rep__task__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__float_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__float_rep__task__exception_behavior_t)
#elif	defined(__NDR_convert__float_rep__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__float_rep__exception_behavior_t)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__task__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__float_rep__task__exception_flavor_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__float_rep__task__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__float_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__float_rep__task__thread_state_flavor_t)
#elif	defined(__NDR_convert__float_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__float_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__task__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined */



mig_internal kern_return_t __MIG_check__Reply__task_get_exception_ports_t(__Reply__task_get_exception_ports_t *Out0P, __Reply__task_get_exception_ports_t **Out1PP, __Reply__task_get_exception_ports_t **Out2PP)
{

	typedef __Reply__task_get_exception_ports_t __Reply;
	__Reply *Out1P;
	__Reply *Out2P;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	unsigned int msgh_size_delta;

	if (Out0P->Head.msgh_id != 3514) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 32 ||
	    msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 384) || msgh_size > (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	{
	    register	mach_msg_port_descriptor_t	*ptr;
	    register int	i;

	    ptr = &Out0P->old_handlers[0];
	    for (i = 0; i < 32; ptr++, i++) {
		if (ptr->type != MACH_MSG_PORT_DESCRIPTOR)
		{ return MIG_TYPE_ERROR; }
	    }
	}
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masksCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masksCnt(&Out0P->masksCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_get_exception_ports_t__masksCnt__defined */
	msgh_size_delta = (4 * Out0P->masksCnt);
#if	__MigTypeCheck
	if (msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 384) + msgh_size_delta)
		{ return MIG_TYPE_ERROR; }
	msgh_size -= msgh_size_delta;
#endif	/* __MigTypeCheck */

	*Out1PP = Out1P = (__Reply *) ((pointer_t) Out0P + msgh_size_delta - 128);

	msgh_size_delta = (4 * Out0P->masksCnt);
#if	__MigTypeCheck
	if (msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 384) + msgh_size_delta)
		{ return MIG_TYPE_ERROR; }
	msgh_size -= msgh_size_delta;
#endif	/* __MigTypeCheck */

	*Out2PP = Out2P = (__Reply *) ((pointer_t) Out1P + msgh_size_delta - 128);

#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Reply) - 384) + ((4 * Out0P->masksCnt)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masksCnt__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined)
		__NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__task_get_exception_ports_t__masks__defined */
#if defined(__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined)
		__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined)
		__NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__task_get_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined) || \
	0 || \
	defined(__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined)
		__NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__task_get_exception_ports_t__masks__defined */
#if defined(__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined)
		__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined)
		__NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__task_get_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined) || \
	0 || \
	defined(__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined)
		__NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__task_get_exception_ports_t__masks__defined */
#if defined(__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined)
		__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined)
		__NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__task_get_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__task_get_exception_ports_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_get_exception_ports */
mig_external kern_return_t task_get_exception_ports
(
	task_t task,
	exception_mask_t exception_mask,
	exception_mask_array_t masks,
	mach_msg_type_number_t *masksCnt,
	exception_handler_array_t old_handlers,
	exception_behavior_array_t old_behaviors,
	exception_flavor_array_t old_flavors
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		exception_mask_t exception_mask;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;
	Reply *Out1P;
	Reply *Out2P;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_get_exception_ports_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_get_exception_ports_t__defined */

	__DeclareSendRpc(3414, "task_get_exception_ports")

	InP->NDR = NDR_record;

	InP->exception_mask = exception_mask;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3414;

	__BeforeSendRpc(3414, "task_get_exception_ports")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3414, "task_get_exception_ports")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_get_exception_ports_t__defined)
	check_result = __MIG_check__Reply__task_get_exception_ports_t((__Reply__task_get_exception_ports_t *)Out0P, (__Reply__task_get_exception_ports_t **)&Out1P, (__Reply__task_get_exception_ports_t **)&Out2P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_get_exception_ports_t__defined) */

	if (Out0P->masksCnt > 32) {
		(void)memcpy((char *) masks, (const char *) Out0P->masks, 4 *  32);
		*masksCnt = Out0P->masksCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) masks, (const char *) Out0P->masks, 4 * Out0P->masksCnt);

	*masksCnt = Out0P->masksCnt;

	{
	    register	mach_msg_port_descriptor_t	*ptr;
	    register int	i, j;

	    ptr = &Out0P->old_handlers[0];
	    j = min(Out0P->masksCnt, *masksCnt);
	    for (i = 0; i < j; ptr++, i++) 
		old_handlers[i] = ptr->name;
	    if (Out0P->masksCnt > 32)
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	if (Out0P->masksCnt > 32) {
		(void)memcpy((char *) old_behaviors, (const char *) Out1P->old_behaviors, 4 *  32);
		*masksCnt = Out0P->masksCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) old_behaviors, (const char *) Out1P->old_behaviors, 4 * Out0P->masksCnt);

	if (Out0P->masksCnt > 32) {
		(void)memcpy((char *) old_flavors, (const char *) Out2P->old_flavors, 4 *  32);
		*masksCnt = Out0P->masksCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) old_flavors, (const char *) Out2P->old_flavors, 4 * Out0P->masksCnt);

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_swap_exception_ports_t__defined)
#define __MIG_check__Reply__task_swap_exception_ports_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined
#if	defined(__NDR_convert__int_rep__task__exception_mask_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__int_rep__task__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_mask_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__int_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__int_rep__task__exception_mask_t)
#elif	defined(__NDR_convert__int_rep__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__int_rep__exception_mask_t)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__task__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined */


#ifndef __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masksCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masksCnt__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masksCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masksCnt__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masksCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masksCnt__defined */


#ifndef __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__int_rep__task__exception_behavior_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__int_rep__task__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__int_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__int_rep__task__exception_behavior_t)
#elif	defined(__NDR_convert__int_rep__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__int_rep__exception_behavior_t)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__task__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__int_rep__task__exception_flavor_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__int_rep__task__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__int_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__int_rep__task__thread_state_flavor_t)
#elif	defined(__NDR_convert__int_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__int_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__task__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined */


#ifndef __NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined
#if	defined(__NDR_convert__char_rep__task__exception_mask_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__char_rep__task__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_mask_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__char_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__char_rep__task__exception_mask_t)
#elif	defined(__NDR_convert__char_rep__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__char_rep__exception_mask_t)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__task__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined */



#ifndef __NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__char_rep__task__exception_behavior_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__char_rep__task__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__char_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__char_rep__task__exception_behavior_t)
#elif	defined(__NDR_convert__char_rep__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__char_rep__exception_behavior_t)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__task__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__char_rep__task__exception_flavor_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__char_rep__task__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__char_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__char_rep__task__thread_state_flavor_t)
#elif	defined(__NDR_convert__char_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__char_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__task__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined */


#ifndef __NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined
#if	defined(__NDR_convert__float_rep__task__exception_mask_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__float_rep__task__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_mask_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__float_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__float_rep__task__exception_mask_t)
#elif	defined(__NDR_convert__float_rep__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__float_rep__exception_mask_t)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__task__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined */



#ifndef __NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__float_rep__task__exception_behavior_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__float_rep__task__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__float_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__float_rep__task__exception_behavior_t)
#elif	defined(__NDR_convert__float_rep__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__float_rep__exception_behavior_t)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__task__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__float_rep__task__exception_flavor_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__float_rep__task__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__float_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__float_rep__task__thread_state_flavor_t)
#elif	defined(__NDR_convert__float_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__float_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__task__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined */



mig_internal kern_return_t __MIG_check__Reply__task_swap_exception_ports_t(__Reply__task_swap_exception_ports_t *Out0P, __Reply__task_swap_exception_ports_t **Out1PP, __Reply__task_swap_exception_ports_t **Out2PP)
{

	typedef __Reply__task_swap_exception_ports_t __Reply;
	__Reply *Out1P;
	__Reply *Out2P;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	unsigned int msgh_size_delta;

	if (Out0P->Head.msgh_id != 3515) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 32 ||
	    msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 384) || msgh_size > (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	{
	    register	mach_msg_port_descriptor_t	*ptr;
	    register int	i;

	    ptr = &Out0P->old_handlerss[0];
	    for (i = 0; i < 32; ptr++, i++) {
		if (ptr->type != MACH_MSG_PORT_DESCRIPTOR)
		{ return MIG_TYPE_ERROR; }
	    }
	}
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masksCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masksCnt(&Out0P->masksCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masksCnt__defined */
	msgh_size_delta = (4 * Out0P->masksCnt);
#if	__MigTypeCheck
	if (msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 384) + msgh_size_delta)
		{ return MIG_TYPE_ERROR; }
	msgh_size -= msgh_size_delta;
#endif	/* __MigTypeCheck */

	*Out1PP = Out1P = (__Reply *) ((pointer_t) Out0P + msgh_size_delta - 128);

	msgh_size_delta = (4 * Out0P->masksCnt);
#if	__MigTypeCheck
	if (msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 384) + msgh_size_delta)
		{ return MIG_TYPE_ERROR; }
	msgh_size -= msgh_size_delta;
#endif	/* __MigTypeCheck */

	*Out2PP = Out2P = (__Reply *) ((pointer_t) Out1P + msgh_size_delta - 128);

#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Reply) - 384) + ((4 * Out0P->masksCnt)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masksCnt__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined)
		__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__masks__defined */
#if defined(__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined)
		__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined)
		__NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__task_swap_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined) || \
	0 || \
	defined(__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined)
		__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__task_swap_exception_ports_t__masks__defined */
#if defined(__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined)
		__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined)
		__NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__task_swap_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined) || \
	0 || \
	defined(__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined)
		__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__task_swap_exception_ports_t__masks__defined */
#if defined(__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined)
		__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined)
		__NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__task_swap_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__task_swap_exception_ports_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_swap_exception_ports */
mig_external kern_return_t task_swap_exception_ports
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
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;
	Reply *Out1P;
	Reply *Out2P;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_swap_exception_ports_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_swap_exception_ports_t__defined */

	__DeclareSendRpc(3415, "task_swap_exception_ports")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t new_portTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->new_port = new_portTemplate;
	InP->new_port.name = new_port;
#else	/* UseStaticTemplates */
	InP->new_port.name = new_port;
	InP->new_port.disposition = 19;
	InP->new_port.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->exception_mask = exception_mask;

	InP->behavior = behavior;

	InP->new_flavor = new_flavor;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3415;

	__BeforeSendRpc(3415, "task_swap_exception_ports")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3415, "task_swap_exception_ports")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_swap_exception_ports_t__defined)
	check_result = __MIG_check__Reply__task_swap_exception_ports_t((__Reply__task_swap_exception_ports_t *)Out0P, (__Reply__task_swap_exception_ports_t **)&Out1P, (__Reply__task_swap_exception_ports_t **)&Out2P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_swap_exception_ports_t__defined) */

	if (Out0P->masksCnt > 32) {
		(void)memcpy((char *) masks, (const char *) Out0P->masks, 4 *  32);
		*masksCnt = Out0P->masksCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) masks, (const char *) Out0P->masks, 4 * Out0P->masksCnt);

	*masksCnt = Out0P->masksCnt;

	{
	    register	mach_msg_port_descriptor_t	*ptr;
	    register int	i, j;

	    ptr = &Out0P->old_handlerss[0];
	    j = min(Out0P->masksCnt, *masksCnt);
	    for (i = 0; i < j; ptr++, i++) 
		old_handlerss[i] = ptr->name;
	    if (Out0P->masksCnt > 32)
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	if (Out0P->masksCnt > 32) {
		(void)memcpy((char *) old_behaviors, (const char *) Out1P->old_behaviors, 4 *  32);
		*masksCnt = Out0P->masksCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) old_behaviors, (const char *) Out1P->old_behaviors, 4 * Out0P->masksCnt);

	if (Out0P->masksCnt > 32) {
		(void)memcpy((char *) old_flavors, (const char *) Out2P->old_flavors, 4 *  32);
		*masksCnt = Out0P->masksCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) old_flavors, (const char *) Out2P->old_flavors, 4 * Out0P->masksCnt);

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__lock_set_create_t__defined)
#define __MIG_check__Reply__lock_set_create_t__defined

mig_internal kern_return_t __MIG_check__Reply__lock_set_create_t(__Reply__lock_set_create_t *Out0P)
{

	typedef __Reply__lock_set_create_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3516) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	if (Out0P->new_lock_set.type != MACH_MSG_PORT_DESCRIPTOR ||
	    Out0P->new_lock_set.disposition != 17)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__lock_set_create_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine lock_set_create */
mig_external kern_return_t lock_set_create
(
	task_t task,
	lock_set_t *new_lock_set,
	int n_ulocks,
	int policy
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int n_ulocks;
		int policy;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__lock_set_create_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__lock_set_create_t__defined */

	__DeclareSendRpc(3416, "lock_set_create")

	InP->NDR = NDR_record;

	InP->n_ulocks = n_ulocks;

	InP->policy = policy;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3416;

	__BeforeSendRpc(3416, "lock_set_create")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3416, "lock_set_create")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__lock_set_create_t__defined)
	check_result = __MIG_check__Reply__lock_set_create_t((__Reply__lock_set_create_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__lock_set_create_t__defined) */

	*new_lock_set = Out0P->new_lock_set.name;
	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__lock_set_destroy_t__defined)
#define __MIG_check__Reply__lock_set_destroy_t__defined
#ifndef __NDR_convert__int_rep__Reply__lock_set_destroy_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__lock_set_destroy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__lock_set_destroy_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__lock_set_destroy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__lock_set_destroy_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__lock_set_destroy_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__lock_set_destroy_t(__Reply__lock_set_destroy_t *Out0P)
{

	typedef __Reply__lock_set_destroy_t __Reply;
	if (Out0P->Head.msgh_id != 3517) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__lock_set_destroy_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__lock_set_destroy_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__lock_set_destroy_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__lock_set_destroy_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine lock_set_destroy */
mig_external kern_return_t lock_set_destroy
(
	task_t task,
	lock_set_t lock_set
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__lock_set_destroy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__lock_set_destroy_t__defined */

	__DeclareSendRpc(3417, "lock_set_destroy")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t lock_setTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->lock_set = lock_setTemplate;
	InP->lock_set.name = lock_set;
#else	/* UseStaticTemplates */
	InP->lock_set.name = lock_set;
	InP->lock_set.disposition = 19;
	InP->lock_set.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3417;

	__BeforeSendRpc(3417, "lock_set_destroy")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3417, "lock_set_destroy")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__lock_set_destroy_t__defined)
	check_result = __MIG_check__Reply__lock_set_destroy_t((__Reply__lock_set_destroy_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__lock_set_destroy_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__semaphore_create_t__defined)
#define __MIG_check__Reply__semaphore_create_t__defined

mig_internal kern_return_t __MIG_check__Reply__semaphore_create_t(__Reply__semaphore_create_t *Out0P)
{

	typedef __Reply__semaphore_create_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3518) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	if (Out0P->semaphore.type != MACH_MSG_PORT_DESCRIPTOR ||
	    Out0P->semaphore.disposition != 17)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__semaphore_create_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine semaphore_create */
mig_external kern_return_t semaphore_create
(
	task_t task,
	semaphore_t *semaphore,
	int policy,
	int value
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int policy;
		int value;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__semaphore_create_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__semaphore_create_t__defined */

	__DeclareSendRpc(3418, "semaphore_create")

	InP->NDR = NDR_record;

	InP->policy = policy;

	InP->value = value;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3418;

	__BeforeSendRpc(3418, "semaphore_create")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3418, "semaphore_create")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__semaphore_create_t__defined)
	check_result = __MIG_check__Reply__semaphore_create_t((__Reply__semaphore_create_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__semaphore_create_t__defined) */

	*semaphore = Out0P->semaphore.name;
	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__semaphore_destroy_t__defined)
#define __MIG_check__Reply__semaphore_destroy_t__defined
#ifndef __NDR_convert__int_rep__Reply__semaphore_destroy_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__semaphore_destroy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__semaphore_destroy_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__semaphore_destroy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__semaphore_destroy_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__semaphore_destroy_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__semaphore_destroy_t(__Reply__semaphore_destroy_t *Out0P)
{

	typedef __Reply__semaphore_destroy_t __Reply;
	if (Out0P->Head.msgh_id != 3519) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__semaphore_destroy_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__semaphore_destroy_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__semaphore_destroy_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__semaphore_destroy_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine semaphore_destroy */
mig_external kern_return_t semaphore_destroy
(
	task_t task,
	semaphore_t semaphore
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__semaphore_destroy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__semaphore_destroy_t__defined */

	__DeclareSendRpc(3419, "semaphore_destroy")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t semaphoreTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		17,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->semaphore = semaphoreTemplate;
	InP->semaphore.name = semaphore;
#else	/* UseStaticTemplates */
	InP->semaphore.name = semaphore;
	InP->semaphore.disposition = 17;
	InP->semaphore.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3419;

	__BeforeSendRpc(3419, "semaphore_destroy")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3419, "semaphore_destroy")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__semaphore_destroy_t__defined)
	check_result = __MIG_check__Reply__semaphore_destroy_t((__Reply__semaphore_destroy_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__semaphore_destroy_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_policy_set_t__defined)
#define __MIG_check__Reply__task_policy_set_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_policy_set_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_set_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_policy_set_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_set_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_policy_set_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_policy_set_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_policy_set_t(__Reply__task_policy_set_t *Out0P)
{

	typedef __Reply__task_policy_set_t __Reply;
	if (Out0P->Head.msgh_id != 3520) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_policy_set_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_policy_set_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_policy_set_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_policy_set_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_policy_set */
mig_external kern_return_t task_policy_set
(
	task_t task,
	task_policy_flavor_t flavor,
	task_policy_t policy_info,
	mach_msg_type_number_t policy_infoCnt
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;
	unsigned int msgh_size;

#ifdef	__MIG_check__Reply__task_policy_set_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_policy_set_t__defined */

	__DeclareSendRpc(3420, "task_policy_set")

	InP->NDR = NDR_record;

	InP->flavor = flavor;

	if (policy_infoCnt > 16) {
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) InP->policy_info, (const char *) policy_info, 4 * policy_infoCnt);

	InP->policy_infoCnt = policy_infoCnt;

	msgh_size = (mach_msg_size_t)(sizeof(Request) - 64) + ((4 * policy_infoCnt));
	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3420;

	__BeforeSendRpc(3420, "task_policy_set")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3420, "task_policy_set")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_policy_set_t__defined)
	check_result = __MIG_check__Reply__task_policy_set_t((__Reply__task_policy_set_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_policy_set_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_policy_get_t__defined)
#define __MIG_check__Reply__task_policy_get_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_policy_get_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_policy_get_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__task_policy_get_t__policy_info__defined
#if	defined(__NDR_convert__int_rep__task__task_policy_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__int_rep__task__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task_policy_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__int_rep__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__task__integer_t)
#elif	defined(__NDR_convert__int_rep__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__integer_t)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__task__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_policy_get_t__policy_info__defined */


#ifndef __NDR_convert__int_rep__Reply__task_policy_get_t__policy_infoCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_infoCnt__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_infoCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_infoCnt__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__policy_infoCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_policy_get_t__policy_infoCnt__defined */


#ifndef __NDR_convert__int_rep__Reply__task_policy_get_t__get_default__defined
#if	defined(__NDR_convert__int_rep__task__boolean_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__get_default__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__get_default(a, f) \
	__NDR_convert__int_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__get_default__defined
#define	__NDR_convert__int_rep__Reply__task_policy_get_t__get_default(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_policy_get_t__get_default__defined */



#ifndef __NDR_convert__char_rep__Reply__task_policy_get_t__policy_info__defined
#if	defined(__NDR_convert__char_rep__task__task_policy_t__defined)
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__char_rep__task__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task_policy_t__defined)
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__char_rep__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__task__integer_t)
#elif	defined(__NDR_convert__char_rep__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__integer_t)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__task__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__task_policy_get_t__policy_info__defined */



#ifndef __NDR_convert__char_rep__Reply__task_policy_get_t__get_default__defined
#if	defined(__NDR_convert__char_rep__task__boolean_t__defined)
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__get_default__defined
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__get_default(a, f) \
	__NDR_convert__char_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__get_default__defined
#define	__NDR_convert__char_rep__Reply__task_policy_get_t__get_default(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__task_policy_get_t__get_default__defined */



#ifndef __NDR_convert__float_rep__Reply__task_policy_get_t__policy_info__defined
#if	defined(__NDR_convert__float_rep__task__task_policy_t__defined)
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__float_rep__task__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task_policy_t__defined)
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__float_rep__task_policy_t((task_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__task__integer_t)
#elif	defined(__NDR_convert__float_rep__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__integer_t)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__task__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__task_policy_get_t__policy_info__defined */



#ifndef __NDR_convert__float_rep__Reply__task_policy_get_t__get_default__defined
#if	defined(__NDR_convert__float_rep__task__boolean_t__defined)
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__get_default__defined
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__get_default(a, f) \
	__NDR_convert__float_rep__task__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__get_default__defined
#define	__NDR_convert__float_rep__Reply__task_policy_get_t__get_default(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__task_policy_get_t__get_default__defined */



mig_internal kern_return_t __MIG_check__Reply__task_policy_get_t(__Reply__task_policy_get_t *Out0P, __Reply__task_policy_get_t **Out1PP)
{

	typedef __Reply__task_policy_get_t __Reply;
	__Reply *Out1P;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	unsigned int msgh_size_delta;

	if (Out0P->Head.msgh_id != 3521) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size > (mach_msg_size_t)sizeof(__Reply) || msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 64)) &&
	     (msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	      Out0P->RetCode == KERN_SUCCESS)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (Out0P->RetCode != KERN_SUCCESS) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if defined(__NDR_convert__int_rep__Reply__task_policy_get_t__policy_infoCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_policy_get_t__policy_infoCnt(&Out0P->policy_infoCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_policy_get_t__policy_infoCnt__defined */
	msgh_size_delta = (4 * Out0P->policy_infoCnt);
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Reply) - 64) + msgh_size_delta)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

	*Out1PP = Out1P = (__Reply *) ((pointer_t) Out0P + msgh_size_delta - 64);

#if	defined(__NDR_convert__int_rep__Reply__task_policy_get_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_policy_get_t__policy_infoCnt__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_policy_get_t__get_default__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__task_policy_get_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__task_policy_get_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__task_policy_get_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info__defined)
		__NDR_convert__int_rep__Reply__task_policy_get_t__policy_info(&Out0P->policy_info, Out0P->NDR.int_rep, Out0P->policy_infoCnt);
#endif /* __NDR_convert__int_rep__Reply__task_policy_get_t__policy_info__defined */
#if defined(__NDR_convert__int_rep__Reply__task_policy_get_t__get_default__defined)
		__NDR_convert__int_rep__Reply__task_policy_get_t__get_default(&Out1P->get_default, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__task_policy_get_t__get_default__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info__defined) || \
	0 || \
	defined(__NDR_convert__char_rep__Reply__task_policy_get_t__get_default__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info__defined)
		__NDR_convert__char_rep__Reply__task_policy_get_t__policy_info(&Out0P->policy_info, Out0P->NDR.char_rep, Out0P->policy_infoCnt);
#endif /* __NDR_convert__char_rep__Reply__task_policy_get_t__policy_info__defined */
#if defined(__NDR_convert__char_rep__Reply__task_policy_get_t__get_default__defined)
		__NDR_convert__char_rep__Reply__task_policy_get_t__get_default(&Out1P->get_default, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__task_policy_get_t__get_default__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info__defined) || \
	0 || \
	defined(__NDR_convert__float_rep__Reply__task_policy_get_t__get_default__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info__defined)
		__NDR_convert__float_rep__Reply__task_policy_get_t__policy_info(&Out0P->policy_info, Out0P->NDR.float_rep, Out0P->policy_infoCnt);
#endif /* __NDR_convert__float_rep__Reply__task_policy_get_t__policy_info__defined */
#if defined(__NDR_convert__float_rep__Reply__task_policy_get_t__get_default__defined)
		__NDR_convert__float_rep__Reply__task_policy_get_t__get_default(&Out1P->get_default, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__task_policy_get_t__get_default__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__task_policy_get_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_policy_get */
mig_external kern_return_t task_policy_get
(
	task_t task,
	task_policy_flavor_t flavor,
	task_policy_t policy_info,
	mach_msg_type_number_t *policy_infoCnt,
	boolean_t *get_default
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;
	Reply *Out1P;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_policy_get_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_policy_get_t__defined */

	__DeclareSendRpc(3421, "task_policy_get")

	InP->NDR = NDR_record;

	InP->flavor = flavor;

	if (*policy_infoCnt < 16)
		InP->policy_infoCnt = *policy_infoCnt;
	else
		InP->policy_infoCnt = 16;

	InP->get_default = *get_default;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3421;

	__BeforeSendRpc(3421, "task_policy_get")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3421, "task_policy_get")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_policy_get_t__defined)
	check_result = __MIG_check__Reply__task_policy_get_t((__Reply__task_policy_get_t *)Out0P, (__Reply__task_policy_get_t **)&Out1P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_policy_get_t__defined) */

	if (Out0P->policy_infoCnt > *policy_infoCnt) {
		(void)memcpy((char *) policy_info, (const char *) Out0P->policy_info, 4 *  *policy_infoCnt);
		*policy_infoCnt = Out0P->policy_infoCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) policy_info, (const char *) Out0P->policy_info, 4 * Out0P->policy_infoCnt);

	*policy_infoCnt = Out0P->policy_infoCnt;

	*get_default = Out1P->get_default;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_sample_t__defined)
#define __MIG_check__Reply__task_sample_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_sample_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_sample_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_sample_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_sample_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_sample_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_sample_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_sample_t(__Reply__task_sample_t *Out0P)
{

	typedef __Reply__task_sample_t __Reply;
	if (Out0P->Head.msgh_id != 3522) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_sample_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_sample_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_sample_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_sample_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_sample */
mig_external kern_return_t task_sample
(
	task_t task,
	mach_port_t reply
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_sample_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_sample_t__defined */

	__DeclareSendRpc(3422, "task_sample")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t replyTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		20,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->reply = replyTemplate;
	InP->reply.name = reply;
#else	/* UseStaticTemplates */
	InP->reply.name = reply;
	InP->reply.disposition = 20;
	InP->reply.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3422;

	__BeforeSendRpc(3422, "task_sample")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3422, "task_sample")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_sample_t__defined)
	check_result = __MIG_check__Reply__task_sample_t((__Reply__task_sample_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_sample_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_policy_t__defined)
#define __MIG_check__Reply__task_policy_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_policy_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_policy_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_policy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_policy_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_policy_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_policy_t(__Reply__task_policy_t *Out0P)
{

	typedef __Reply__task_policy_t __Reply;
	if (Out0P->Head.msgh_id != 3523) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_policy_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_policy_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_policy_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_policy_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_policy */
mig_external kern_return_t task_policy
(
	task_t task,
	policy_t policy,
	policy_base_t base,
	mach_msg_type_number_t baseCnt,
	boolean_t set_limit,
	boolean_t change
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;
	unsigned int msgh_size;
	unsigned int msgh_size_delta;


#ifdef	__MIG_check__Reply__task_policy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_policy_t__defined */

	__DeclareSendRpc(3423, "task_policy")

	InP->NDR = NDR_record;

	InP->policy = policy;

	if (baseCnt > 5) {
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) InP->base, (const char *) base, 4 * baseCnt);

	InP->baseCnt = baseCnt;

	msgh_size_delta = (4 * baseCnt);
	msgh_size = (mach_msg_size_t)(sizeof(Request) - 20) + msgh_size_delta;
	InP = (Request *) ((pointer_t) InP + msgh_size_delta - 20);

	InP->set_limit = set_limit;

	InP->change = change;

	InP = &Mess.In;
	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3423;

	__BeforeSendRpc(3423, "task_policy")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3423, "task_policy")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_policy_t__defined)
	check_result = __MIG_check__Reply__task_policy_t((__Reply__task_policy_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_policy_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_set_emulation_t__defined)
#define __MIG_check__Reply__task_set_emulation_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_set_emulation_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_emulation_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_emulation_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_emulation_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_emulation_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_set_emulation_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_set_emulation_t(__Reply__task_set_emulation_t *Out0P)
{

	typedef __Reply__task_set_emulation_t __Reply;
	if (Out0P->Head.msgh_id != 3524) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_set_emulation_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_set_emulation_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_set_emulation_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_set_emulation_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_emulation */
mig_external kern_return_t task_set_emulation
(
	task_t target_port,
	vm_address_t routine_entry_pt,
	int routine_number
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		vm_address_t routine_entry_pt;
		int routine_number;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_set_emulation_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_set_emulation_t__defined */

	__DeclareSendRpc(3424, "task_set_emulation")

	InP->NDR = NDR_record;

	InP->routine_entry_pt = routine_entry_pt;

	InP->routine_number = routine_number;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_port;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3424;

	__BeforeSendRpc(3424, "task_set_emulation")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3424, "task_set_emulation")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_set_emulation_t__defined)
	check_result = __MIG_check__Reply__task_set_emulation_t((__Reply__task_set_emulation_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_set_emulation_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_get_emulation_vector_t__defined)
#define __MIG_check__Reply__task_get_emulation_vector_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#if	defined(__NDR_convert__int_rep__task__int__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__int_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__task__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__int_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start__defined */


#ifndef __NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#if	defined(__NDR_convert__int_rep__task__emulation_vector_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__int_rep__task__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__emulation_vector_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__int_rep__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__task__vm_offset_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__int_rep__task__vm_offset_t)
#elif	defined(__NDR_convert__int_rep__vm_offset_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__int_rep__vm_offset_t)
#elif	defined(__NDR_convert__int_rep__task__natural_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__int_rep__task__natural_t)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__int_rep__natural_t)
#elif	defined(__NDR_convert__int_rep__task__uint32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__int_rep__task__uint32_t)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__int_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined */


#ifndef __NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vectorCnt__defined
#if	defined(__NDR_convert__int_rep__task__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vectorCnt__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vectorCnt(a, f) \
	__NDR_convert__int_rep__task__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vectorCnt__defined
#define	__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vectorCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vectorCnt__defined */


#ifndef __NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#if	defined(__NDR_convert__char_rep__task__int__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__char_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__task__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__char_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start__defined */


#ifndef __NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#if	defined(__NDR_convert__char_rep__task__emulation_vector_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__char_rep__task__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__emulation_vector_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__char_rep__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__task__vm_offset_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__char_rep__task__vm_offset_t)
#elif	defined(__NDR_convert__char_rep__vm_offset_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__char_rep__vm_offset_t)
#elif	defined(__NDR_convert__char_rep__task__natural_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__char_rep__task__natural_t)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__char_rep__natural_t)
#elif	defined(__NDR_convert__char_rep__task__uint32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__char_rep__task__uint32_t)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__char_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined */



#ifndef __NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#if	defined(__NDR_convert__float_rep__task__int__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__float_rep__task__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__task__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__float_rep__task__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start__defined */


#ifndef __NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#if	defined(__NDR_convert__float_rep__task__emulation_vector_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__float_rep__task__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__emulation_vector_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__float_rep__emulation_vector_t((emulation_vector_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__task__vm_offset_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__float_rep__task__vm_offset_t)
#elif	defined(__NDR_convert__float_rep__vm_offset_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((vm_offset_t *)(a), f, c, __NDR_convert__float_rep__vm_offset_t)
#elif	defined(__NDR_convert__float_rep__task__natural_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__float_rep__task__natural_t)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__float_rep__natural_t)
#elif	defined(__NDR_convert__float_rep__task__uint32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__float_rep__task__uint32_t)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined
#define	__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__float_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined */




mig_internal kern_return_t __MIG_check__Reply__task_get_emulation_vector_t(__Reply__task_get_emulation_vector_t *Out0P)
{

	typedef __Reply__task_get_emulation_vector_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3525) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	if (Out0P->emulation_vector.type != MACH_MSG_OOL_DESCRIPTOR)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined) || \
	defined(__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vectorCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start__defined)
		__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start(&Out0P->vector_start, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__task_get_emulation_vector_t__vector_start__defined */
#if defined(__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vectorCnt__defined)
		__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vectorCnt(&Out0P->emulation_vectorCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vectorCnt__defined */
#if defined(__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined)
		__NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector((emulation_vector_t)(Out0P->emulation_vector.address), Out0P->NDR.int_rep, Out0P->emulation_vectorCnt);
#endif /* __NDR_convert__int_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start__defined) || \
	defined(__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined) || \
	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start__defined)
		__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start(&Out0P->vector_start, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__task_get_emulation_vector_t__vector_start__defined */
#if defined(__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined)
		__NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector((emulation_vector_t)(Out0P->emulation_vector.address), Out0P->NDR.char_rep, Out0P->emulation_vectorCnt);
#endif /* __NDR_convert__char_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start__defined) || \
	defined(__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined) || \
	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start__defined)
		__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start(&Out0P->vector_start, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__task_get_emulation_vector_t__vector_start__defined */
#if defined(__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined)
		__NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector((emulation_vector_t)(Out0P->emulation_vector.address), Out0P->NDR.float_rep, Out0P->emulation_vectorCnt);
#endif /* __NDR_convert__float_rep__Reply__task_get_emulation_vector_t__emulation_vector__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__task_get_emulation_vector_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_get_emulation_vector */
mig_external kern_return_t task_get_emulation_vector
(
	task_t task,
	int *vector_start,
	emulation_vector_t *emulation_vector,
	mach_msg_type_number_t *emulation_vectorCnt
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_get_emulation_vector_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_get_emulation_vector_t__defined */

	__DeclareSendRpc(3425, "task_get_emulation_vector")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3425;

	__BeforeSendRpc(3425, "task_get_emulation_vector")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3425, "task_get_emulation_vector")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_get_emulation_vector_t__defined)
	check_result = __MIG_check__Reply__task_get_emulation_vector_t((__Reply__task_get_emulation_vector_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_get_emulation_vector_t__defined) */

	*vector_start = Out0P->vector_start;

	*emulation_vector = (emulation_vector_t)(Out0P->emulation_vector.address);
	*emulation_vectorCnt = Out0P->emulation_vectorCnt;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_set_emulation_vector_t__defined)
#define __MIG_check__Reply__task_set_emulation_vector_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_set_emulation_vector_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_emulation_vector_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_emulation_vector_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_emulation_vector_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_emulation_vector_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_set_emulation_vector_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_set_emulation_vector_t(__Reply__task_set_emulation_vector_t *Out0P)
{

	typedef __Reply__task_set_emulation_vector_t __Reply;
	if (Out0P->Head.msgh_id != 3526) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_set_emulation_vector_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_set_emulation_vector_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_set_emulation_vector_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_set_emulation_vector_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_emulation_vector */
mig_external kern_return_t task_set_emulation_vector
(
	task_t task,
	int vector_start,
	emulation_vector_t emulation_vector,
	mach_msg_type_number_t emulation_vectorCnt
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_set_emulation_vector_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_set_emulation_vector_t__defined */

	__DeclareSendRpc(3426, "task_set_emulation_vector")

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

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->emulation_vector = emulation_vectorTemplate;
	InP->emulation_vector.address = (void *)(emulation_vector);
	InP->emulation_vector.size = emulation_vectorCnt * 4;
#else	/* UseStaticTemplates */
	InP->emulation_vector.address = (void *)(emulation_vector);
	InP->emulation_vector.size = emulation_vectorCnt * 4;
	InP->emulation_vector.deallocate =  FALSE;
	InP->emulation_vector.copy = MACH_MSG_VIRTUAL_COPY;
	InP->emulation_vector.type = MACH_MSG_OOL_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->vector_start = vector_start;

	InP->emulation_vectorCnt = emulation_vectorCnt;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3426;

	__BeforeSendRpc(3426, "task_set_emulation_vector")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3426, "task_set_emulation_vector")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_set_emulation_vector_t__defined)
	check_result = __MIG_check__Reply__task_set_emulation_vector_t((__Reply__task_set_emulation_vector_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_set_emulation_vector_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_set_ras_pc_t__defined)
#define __MIG_check__Reply__task_set_ras_pc_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_set_ras_pc_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_ras_pc_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_ras_pc_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_ras_pc_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_ras_pc_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_set_ras_pc_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_set_ras_pc_t(__Reply__task_set_ras_pc_t *Out0P)
{

	typedef __Reply__task_set_ras_pc_t __Reply;
	if (Out0P->Head.msgh_id != 3527) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_set_ras_pc_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_set_ras_pc_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_set_ras_pc_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_set_ras_pc_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_ras_pc */
mig_external kern_return_t task_set_ras_pc
(
	task_t target_task,
	vm_address_t basepc,
	vm_address_t boundspc
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		vm_address_t basepc;
		vm_address_t boundspc;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_set_ras_pc_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_set_ras_pc_t__defined */

	__DeclareSendRpc(3427, "task_set_ras_pc")

	InP->NDR = NDR_record;

	InP->basepc = basepc;

	InP->boundspc = boundspc;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3427;

	__BeforeSendRpc(3427, "task_set_ras_pc")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3427, "task_set_ras_pc")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_set_ras_pc_t__defined)
	check_result = __MIG_check__Reply__task_set_ras_pc_t((__Reply__task_set_ras_pc_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_set_ras_pc_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_assign_t__defined)
#define __MIG_check__Reply__task_assign_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_assign_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_assign_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_assign_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_assign_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_assign_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_assign_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_assign_t(__Reply__task_assign_t *Out0P)
{

	typedef __Reply__task_assign_t __Reply;
	if (Out0P->Head.msgh_id != 3529) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_assign_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_assign_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_assign_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_assign_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_assign */
mig_external kern_return_t task_assign
(
	task_t task,
	processor_set_t new_set,
	boolean_t assign_threads
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_assign_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_assign_t__defined */

	__DeclareSendRpc(3429, "task_assign")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t new_setTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->new_set = new_setTemplate;
	InP->new_set.name = new_set;
#else	/* UseStaticTemplates */
	InP->new_set.name = new_set;
	InP->new_set.disposition = 19;
	InP->new_set.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->assign_threads = assign_threads;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3429;

	__BeforeSendRpc(3429, "task_assign")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3429, "task_assign")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_assign_t__defined)
	check_result = __MIG_check__Reply__task_assign_t((__Reply__task_assign_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_assign_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_assign_default_t__defined)
#define __MIG_check__Reply__task_assign_default_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_assign_default_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_assign_default_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_assign_default_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_assign_default_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_assign_default_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_assign_default_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_assign_default_t(__Reply__task_assign_default_t *Out0P)
{

	typedef __Reply__task_assign_default_t __Reply;
	if (Out0P->Head.msgh_id != 3530) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_assign_default_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_assign_default_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_assign_default_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_assign_default_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_assign_default */
mig_external kern_return_t task_assign_default
(
	task_t task,
	boolean_t assign_threads
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		boolean_t assign_threads;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_assign_default_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_assign_default_t__defined */

	__DeclareSendRpc(3430, "task_assign_default")

	InP->NDR = NDR_record;

	InP->assign_threads = assign_threads;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3430;

	__BeforeSendRpc(3430, "task_assign_default")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3430, "task_assign_default")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_assign_default_t__defined)
	check_result = __MIG_check__Reply__task_assign_default_t((__Reply__task_assign_default_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_assign_default_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_get_assignment_t__defined)
#define __MIG_check__Reply__task_get_assignment_t__defined

mig_internal kern_return_t __MIG_check__Reply__task_get_assignment_t(__Reply__task_get_assignment_t *Out0P)
{

	typedef __Reply__task_get_assignment_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3531) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	if (Out0P->assigned_set.type != MACH_MSG_PORT_DESCRIPTOR ||
	    Out0P->assigned_set.disposition != 17)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__task_get_assignment_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_get_assignment */
mig_external kern_return_t task_get_assignment
(
	task_t task,
	processor_set_name_t *assigned_set
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__task_get_assignment_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_get_assignment_t__defined */

	__DeclareSendRpc(3431, "task_get_assignment")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3431;

	__BeforeSendRpc(3431, "task_get_assignment")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3431, "task_get_assignment")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_get_assignment_t__defined)
	check_result = __MIG_check__Reply__task_get_assignment_t((__Reply__task_get_assignment_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_get_assignment_t__defined) */

	*assigned_set = Out0P->assigned_set.name;
	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__task_subsystem__
#if !defined(__MIG_check__Reply__task_set_policy_t__defined)
#define __MIG_check__Reply__task_set_policy_t__defined
#ifndef __NDR_convert__int_rep__Reply__task_set_policy_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__task__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_policy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_policy_t__RetCode(a, f) \
	__NDR_convert__int_rep__task__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__task_set_policy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__task_set_policy_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__task_set_policy_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__task_set_policy_t(__Reply__task_set_policy_t *Out0P)
{

	typedef __Reply__task_set_policy_t __Reply;
	if (Out0P->Head.msgh_id != 3532) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__task_set_policy_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__task_set_policy_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__task_set_policy_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__task_set_policy_t__defined) */
#endif /* __MIG_check__Reply__task_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine task_set_policy */
mig_external kern_return_t task_set_policy
(
	task_t task,
	processor_set_t pset,
	policy_t policy,
	policy_base_t base,
	mach_msg_type_number_t baseCnt,
	policy_limit_t limit,
	mach_msg_type_number_t limitCnt,
	boolean_t change
)
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;
	unsigned int msgh_size;
	unsigned int msgh_size_delta;


#ifdef	__MIG_check__Reply__task_set_policy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__task_set_policy_t__defined */

	__DeclareSendRpc(3432, "task_set_policy")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t psetTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->pset = psetTemplate;
	InP->pset.name = pset;
#else	/* UseStaticTemplates */
	InP->pset.name = pset;
	InP->pset.disposition = 19;
	InP->pset.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->policy = policy;

	if (baseCnt > 5) {
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) InP->base, (const char *) base, 4 * baseCnt);

	InP->baseCnt = baseCnt;

	msgh_size_delta = (4 * baseCnt);
	msgh_size = (mach_msg_size_t)(sizeof(Request) - 24) + msgh_size_delta;
	InP = (Request *) ((pointer_t) InP + msgh_size_delta - 20);

	if (limitCnt > 1) {
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) InP->limit, (const char *) limit, 4 * limitCnt);

	InP->limitCnt = limitCnt;

	msgh_size_delta = (4 * limitCnt);
	msgh_size += msgh_size_delta;
	InP = (Request *) ((pointer_t) InP + msgh_size_delta - 4);

	InP->change = change;

	InP = &Mess.In;
	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3432;

	__BeforeSendRpc(3432, "task_set_policy")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3432, "task_set_policy")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__task_set_policy_t__defined)
	check_result = __MIG_check__Reply__task_set_policy_t((__Reply__task_set_policy_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__task_set_policy_t__defined) */

	return KERN_SUCCESS;
}
