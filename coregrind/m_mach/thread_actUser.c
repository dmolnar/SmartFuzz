/*
 * IDENTIFICATION:
 * stub generated Mon Jun 15 19:50:16 2009
 * with a MiG generated Tue Feb 19 02:01:43 PST 2008 by root@b75.local
 * OPTIONS: 
 */
#define	__MIG_check__Reply__thread_act_subsystem__ 1
#define	__NDR_convert__Reply__thread_act_subsystem__ 1
#define	__NDR_convert__mig_reply_error_subsystem__ 1

#include "thread_act.h"


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
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_terminate_t__defined)
#define __MIG_check__Reply__thread_terminate_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_terminate_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_terminate_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_terminate_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_terminate_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_terminate_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_terminate_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_terminate_t(__Reply__thread_terminate_t *Out0P)
{

	typedef __Reply__thread_terminate_t __Reply;
	if (Out0P->Head.msgh_id != 3700) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_terminate_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_terminate_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_terminate_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_terminate_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_terminate */
mig_external kern_return_t thread_terminate
(
	thread_act_t target_act
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

#ifdef	__MIG_check__Reply__thread_terminate_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_terminate_t__defined */

	__DeclareSendRpc(3600, "thread_terminate")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(17, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3600;

	__BeforeSendRpc(3600, "thread_terminate")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3600, "thread_terminate")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_terminate_t__defined)
	check_result = __MIG_check__Reply__thread_terminate_t((__Reply__thread_terminate_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_terminate_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__act_get_state_t__defined)
#define __MIG_check__Reply__act_get_state_t__defined
#ifndef __NDR_convert__int_rep__Reply__act_get_state_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__act_get_state_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__act_get_state_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__act_get_state_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__act_get_state_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__act_get_state_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__act_get_state_t__old_state__defined
#if	defined(__NDR_convert__int_rep__thread_act__thread_state_t__defined)
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__int_rep__thread_act__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_state_t__defined)
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__int_rep__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_act__natural_t__defined)
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__int_rep__thread_act__natural_t)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__int_rep__natural_t)
#elif	defined(__NDR_convert__int_rep__thread_act__uint32_t__defined)
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__int_rep__thread_act__uint32_t)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__int_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__act_get_state_t__old_state__defined */


#ifndef __NDR_convert__int_rep__Reply__act_get_state_t__old_stateCnt__defined
#if	defined(__NDR_convert__int_rep__thread_act__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_stateCnt__defined
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_stateCnt(a, f) \
	__NDR_convert__int_rep__thread_act__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_stateCnt__defined
#define	__NDR_convert__int_rep__Reply__act_get_state_t__old_stateCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__act_get_state_t__old_stateCnt__defined */



#ifndef __NDR_convert__char_rep__Reply__act_get_state_t__old_state__defined
#if	defined(__NDR_convert__char_rep__thread_act__thread_state_t__defined)
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__char_rep__thread_act__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_state_t__defined)
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__char_rep__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_act__natural_t__defined)
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__char_rep__thread_act__natural_t)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__char_rep__natural_t)
#elif	defined(__NDR_convert__char_rep__thread_act__uint32_t__defined)
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__char_rep__thread_act__uint32_t)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__char_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__act_get_state_t__old_state__defined */




#ifndef __NDR_convert__float_rep__Reply__act_get_state_t__old_state__defined
#if	defined(__NDR_convert__float_rep__thread_act__thread_state_t__defined)
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__float_rep__thread_act__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_state_t__defined)
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__float_rep__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_act__natural_t__defined)
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__float_rep__thread_act__natural_t)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__float_rep__natural_t)
#elif	defined(__NDR_convert__float_rep__thread_act__uint32_t__defined)
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__float_rep__thread_act__uint32_t)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__act_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__float_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__act_get_state_t__old_state__defined */




mig_internal kern_return_t __MIG_check__Reply__act_get_state_t(__Reply__act_get_state_t *Out0P)
{

	typedef __Reply__act_get_state_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */

	if (Out0P->Head.msgh_id != 3701) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size > (mach_msg_size_t)sizeof(__Reply) || msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 576)) &&
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

#if defined(__NDR_convert__int_rep__Reply__act_get_state_t__old_stateCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__act_get_state_t__old_stateCnt(&Out0P->old_stateCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__act_get_state_t__old_stateCnt__defined */
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Reply) - 576) + ((4 * Out0P->old_stateCnt)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__act_get_state_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__act_get_state_t__old_state__defined) || \
	defined(__NDR_convert__int_rep__Reply__act_get_state_t__old_stateCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__act_get_state_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__act_get_state_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__act_get_state_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__act_get_state_t__old_state__defined)
		__NDR_convert__int_rep__Reply__act_get_state_t__old_state(&Out0P->old_state, Out0P->NDR.int_rep, Out0P->old_stateCnt);
#endif /* __NDR_convert__int_rep__Reply__act_get_state_t__old_state__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__act_get_state_t__old_state__defined) || \
	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__act_get_state_t__old_state__defined)
		__NDR_convert__char_rep__Reply__act_get_state_t__old_state(&Out0P->old_state, Out0P->NDR.char_rep, Out0P->old_stateCnt);
#endif /* __NDR_convert__char_rep__Reply__act_get_state_t__old_state__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__act_get_state_t__old_state__defined) || \
	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__act_get_state_t__old_state__defined)
		__NDR_convert__float_rep__Reply__act_get_state_t__old_state(&Out0P->old_state, Out0P->NDR.float_rep, Out0P->old_stateCnt);
#endif /* __NDR_convert__float_rep__Reply__act_get_state_t__old_state__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__act_get_state_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine act_get_state */
mig_external kern_return_t act_get_state
(
	thread_act_t target_act,
	int flavor,
	thread_state_t old_state,
	mach_msg_type_number_t *old_stateCnt
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int flavor;
		mach_msg_type_number_t old_stateCnt;
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
		mach_msg_type_number_t old_stateCnt;
		natural_t old_state[144];
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
		mach_msg_type_number_t old_stateCnt;
		natural_t old_state[144];
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

#ifdef	__MIG_check__Reply__act_get_state_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__act_get_state_t__defined */

	__DeclareSendRpc(3601, "act_get_state")

	InP->NDR = NDR_record;

	InP->flavor = flavor;

	if (*old_stateCnt < 144)
		InP->old_stateCnt = *old_stateCnt;
	else
		InP->old_stateCnt = 144;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3601;

	__BeforeSendRpc(3601, "act_get_state")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3601, "act_get_state")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__act_get_state_t__defined)
	check_result = __MIG_check__Reply__act_get_state_t((__Reply__act_get_state_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__act_get_state_t__defined) */

	if (Out0P->old_stateCnt > *old_stateCnt) {
		(void)memcpy((char *) old_state, (const char *) Out0P->old_state, 4 *  *old_stateCnt);
		*old_stateCnt = Out0P->old_stateCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) old_state, (const char *) Out0P->old_state, 4 * Out0P->old_stateCnt);

	*old_stateCnt = Out0P->old_stateCnt;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__act_set_state_t__defined)
#define __MIG_check__Reply__act_set_state_t__defined
#ifndef __NDR_convert__int_rep__Reply__act_set_state_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__act_set_state_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__act_set_state_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__act_set_state_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__act_set_state_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__act_set_state_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__act_set_state_t(__Reply__act_set_state_t *Out0P)
{

	typedef __Reply__act_set_state_t __Reply;
	if (Out0P->Head.msgh_id != 3702) {
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

#if defined(__NDR_convert__int_rep__Reply__act_set_state_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__act_set_state_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__act_set_state_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__act_set_state_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine act_set_state */
mig_external kern_return_t act_set_state
(
	thread_act_t target_act,
	int flavor,
	thread_state_t new_state,
	mach_msg_type_number_t new_stateCnt
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int flavor;
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

#ifdef	__MIG_check__Reply__act_set_state_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__act_set_state_t__defined */

	__DeclareSendRpc(3602, "act_set_state")

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
	InP->Head.msgh_request_port = target_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3602;

	__BeforeSendRpc(3602, "act_set_state")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3602, "act_set_state")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__act_set_state_t__defined)
	check_result = __MIG_check__Reply__act_set_state_t((__Reply__act_set_state_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__act_set_state_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_get_state_t__defined)
#define __MIG_check__Reply__thread_get_state_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_get_state_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_get_state_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_get_state_t__old_state__defined
#if	defined(__NDR_convert__int_rep__thread_act__thread_state_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__int_rep__thread_act__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_state_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__int_rep__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_act__natural_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__int_rep__thread_act__natural_t)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__int_rep__natural_t)
#elif	defined(__NDR_convert__int_rep__thread_act__uint32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__int_rep__thread_act__uint32_t)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__int_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_get_state_t__old_state__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_get_state_t__old_stateCnt__defined
#if	defined(__NDR_convert__int_rep__thread_act__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_stateCnt__defined
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_stateCnt(a, f) \
	__NDR_convert__int_rep__thread_act__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_stateCnt__defined
#define	__NDR_convert__int_rep__Reply__thread_get_state_t__old_stateCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_get_state_t__old_stateCnt__defined */



#ifndef __NDR_convert__char_rep__Reply__thread_get_state_t__old_state__defined
#if	defined(__NDR_convert__char_rep__thread_act__thread_state_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__char_rep__thread_act__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_state_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__char_rep__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_act__natural_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__char_rep__thread_act__natural_t)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__char_rep__natural_t)
#elif	defined(__NDR_convert__char_rep__thread_act__uint32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__char_rep__thread_act__uint32_t)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__char_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__char_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__thread_get_state_t__old_state__defined */




#ifndef __NDR_convert__float_rep__Reply__thread_get_state_t__old_state__defined
#if	defined(__NDR_convert__float_rep__thread_act__thread_state_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__float_rep__thread_act__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_state_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__float_rep__thread_state_t((thread_state_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_act__natural_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__float_rep__thread_act__natural_t)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((natural_t *)(a), f, c, __NDR_convert__float_rep__natural_t)
#elif	defined(__NDR_convert__float_rep__thread_act__uint32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__float_rep__thread_act__uint32_t)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state__defined
#define	__NDR_convert__float_rep__Reply__thread_get_state_t__old_state(a, f, c) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, c, __NDR_convert__float_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__thread_get_state_t__old_state__defined */




mig_internal kern_return_t __MIG_check__Reply__thread_get_state_t(__Reply__thread_get_state_t *Out0P)
{

	typedef __Reply__thread_get_state_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */

	if (Out0P->Head.msgh_id != 3703) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size > (mach_msg_size_t)sizeof(__Reply) || msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 576)) &&
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

#if defined(__NDR_convert__int_rep__Reply__thread_get_state_t__old_stateCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_get_state_t__old_stateCnt(&Out0P->old_stateCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_get_state_t__old_stateCnt__defined */
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Reply) - 576) + ((4 * Out0P->old_stateCnt)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__thread_get_state_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_get_state_t__old_state__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_get_state_t__old_stateCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__thread_get_state_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__thread_get_state_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__thread_get_state_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__thread_get_state_t__old_state__defined)
		__NDR_convert__int_rep__Reply__thread_get_state_t__old_state(&Out0P->old_state, Out0P->NDR.int_rep, Out0P->old_stateCnt);
#endif /* __NDR_convert__int_rep__Reply__thread_get_state_t__old_state__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__thread_get_state_t__old_state__defined) || \
	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__thread_get_state_t__old_state__defined)
		__NDR_convert__char_rep__Reply__thread_get_state_t__old_state(&Out0P->old_state, Out0P->NDR.char_rep, Out0P->old_stateCnt);
#endif /* __NDR_convert__char_rep__Reply__thread_get_state_t__old_state__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__thread_get_state_t__old_state__defined) || \
	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__thread_get_state_t__old_state__defined)
		__NDR_convert__float_rep__Reply__thread_get_state_t__old_state(&Out0P->old_state, Out0P->NDR.float_rep, Out0P->old_stateCnt);
#endif /* __NDR_convert__float_rep__Reply__thread_get_state_t__old_state__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__thread_get_state_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_get_state */
mig_external kern_return_t thread_get_state
(
	thread_act_t target_act,
	thread_state_flavor_t flavor,
	thread_state_t old_state,
	mach_msg_type_number_t *old_stateCnt
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		thread_state_flavor_t flavor;
		mach_msg_type_number_t old_stateCnt;
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
		mach_msg_type_number_t old_stateCnt;
		natural_t old_state[144];
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
		mach_msg_type_number_t old_stateCnt;
		natural_t old_state[144];
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

#ifdef	__MIG_check__Reply__thread_get_state_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_get_state_t__defined */

	__DeclareSendRpc(3603, "thread_get_state")

	InP->NDR = NDR_record;

	InP->flavor = flavor;

	if (*old_stateCnt < 144)
		InP->old_stateCnt = *old_stateCnt;
	else
		InP->old_stateCnt = 144;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3603;

	__BeforeSendRpc(3603, "thread_get_state")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3603, "thread_get_state")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_get_state_t__defined)
	check_result = __MIG_check__Reply__thread_get_state_t((__Reply__thread_get_state_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_get_state_t__defined) */

	if (Out0P->old_stateCnt > *old_stateCnt) {
		(void)memcpy((char *) old_state, (const char *) Out0P->old_state, 4 *  *old_stateCnt);
		*old_stateCnt = Out0P->old_stateCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) old_state, (const char *) Out0P->old_state, 4 * Out0P->old_stateCnt);

	*old_stateCnt = Out0P->old_stateCnt;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_set_state_t__defined)
#define __MIG_check__Reply__thread_set_state_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_set_state_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_set_state_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_set_state_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_set_state_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_set_state_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_set_state_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_set_state_t(__Reply__thread_set_state_t *Out0P)
{

	typedef __Reply__thread_set_state_t __Reply;
	if (Out0P->Head.msgh_id != 3704) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_set_state_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_set_state_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_set_state_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_set_state_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_set_state */
mig_external kern_return_t thread_set_state
(
	thread_act_t target_act,
	thread_state_flavor_t flavor,
	thread_state_t new_state,
	mach_msg_type_number_t new_stateCnt
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

#ifdef	__MIG_check__Reply__thread_set_state_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_set_state_t__defined */

	__DeclareSendRpc(3604, "thread_set_state")

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
	InP->Head.msgh_request_port = target_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3604;

	__BeforeSendRpc(3604, "thread_set_state")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3604, "thread_set_state")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_set_state_t__defined)
	check_result = __MIG_check__Reply__thread_set_state_t((__Reply__thread_set_state_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_set_state_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_suspend_t__defined)
#define __MIG_check__Reply__thread_suspend_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_suspend_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_suspend_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_suspend_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_suspend_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_suspend_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_suspend_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_suspend_t(__Reply__thread_suspend_t *Out0P)
{

	typedef __Reply__thread_suspend_t __Reply;
	if (Out0P->Head.msgh_id != 3705) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_suspend_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_suspend_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_suspend_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_suspend_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_suspend */
mig_external kern_return_t thread_suspend
(
	thread_act_t target_act
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

#ifdef	__MIG_check__Reply__thread_suspend_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_suspend_t__defined */

	__DeclareSendRpc(3605, "thread_suspend")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3605;

	__BeforeSendRpc(3605, "thread_suspend")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3605, "thread_suspend")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_suspend_t__defined)
	check_result = __MIG_check__Reply__thread_suspend_t((__Reply__thread_suspend_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_suspend_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_resume_t__defined)
#define __MIG_check__Reply__thread_resume_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_resume_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_resume_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_resume_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_resume_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_resume_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_resume_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_resume_t(__Reply__thread_resume_t *Out0P)
{

	typedef __Reply__thread_resume_t __Reply;
	if (Out0P->Head.msgh_id != 3706) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_resume_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_resume_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_resume_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_resume_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_resume */
mig_external kern_return_t thread_resume
(
	thread_act_t target_act
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

#ifdef	__MIG_check__Reply__thread_resume_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_resume_t__defined */

	__DeclareSendRpc(3606, "thread_resume")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3606;

	__BeforeSendRpc(3606, "thread_resume")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3606, "thread_resume")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_resume_t__defined)
	check_result = __MIG_check__Reply__thread_resume_t((__Reply__thread_resume_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_resume_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_abort_t__defined)
#define __MIG_check__Reply__thread_abort_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_abort_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_abort_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_abort_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_abort_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_abort_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_abort_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_abort_t(__Reply__thread_abort_t *Out0P)
{

	typedef __Reply__thread_abort_t __Reply;
	if (Out0P->Head.msgh_id != 3707) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_abort_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_abort_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_abort_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_abort_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_abort */
mig_external kern_return_t thread_abort
(
	thread_act_t target_act
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

#ifdef	__MIG_check__Reply__thread_abort_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_abort_t__defined */

	__DeclareSendRpc(3607, "thread_abort")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3607;

	__BeforeSendRpc(3607, "thread_abort")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3607, "thread_abort")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_abort_t__defined)
	check_result = __MIG_check__Reply__thread_abort_t((__Reply__thread_abort_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_abort_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_abort_safely_t__defined)
#define __MIG_check__Reply__thread_abort_safely_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_abort_safely_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_abort_safely_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_abort_safely_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_abort_safely_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_abort_safely_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_abort_safely_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_abort_safely_t(__Reply__thread_abort_safely_t *Out0P)
{

	typedef __Reply__thread_abort_safely_t __Reply;
	if (Out0P->Head.msgh_id != 3708) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_abort_safely_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_abort_safely_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_abort_safely_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_abort_safely_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_abort_safely */
mig_external kern_return_t thread_abort_safely
(
	thread_act_t target_act
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

#ifdef	__MIG_check__Reply__thread_abort_safely_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_abort_safely_t__defined */

	__DeclareSendRpc(3608, "thread_abort_safely")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3608;

	__BeforeSendRpc(3608, "thread_abort_safely")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3608, "thread_abort_safely")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_abort_safely_t__defined)
	check_result = __MIG_check__Reply__thread_abort_safely_t((__Reply__thread_abort_safely_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_abort_safely_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_depress_abort_t__defined)
#define __MIG_check__Reply__thread_depress_abort_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_depress_abort_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_depress_abort_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_depress_abort_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_depress_abort_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_depress_abort_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_depress_abort_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_depress_abort_t(__Reply__thread_depress_abort_t *Out0P)
{

	typedef __Reply__thread_depress_abort_t __Reply;
	if (Out0P->Head.msgh_id != 3709) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_depress_abort_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_depress_abort_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_depress_abort_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_depress_abort_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_depress_abort */
mig_external kern_return_t thread_depress_abort
(
	thread_act_t thread
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

#ifdef	__MIG_check__Reply__thread_depress_abort_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_depress_abort_t__defined */

	__DeclareSendRpc(3609, "thread_depress_abort")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = thread;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3609;

	__BeforeSendRpc(3609, "thread_depress_abort")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3609, "thread_depress_abort")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_depress_abort_t__defined)
	check_result = __MIG_check__Reply__thread_depress_abort_t((__Reply__thread_depress_abort_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_depress_abort_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_get_special_port_t__defined)
#define __MIG_check__Reply__thread_get_special_port_t__defined

mig_internal kern_return_t __MIG_check__Reply__thread_get_special_port_t(__Reply__thread_get_special_port_t *Out0P)
{

	typedef __Reply__thread_get_special_port_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3710) {
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
#endif /* !defined(__MIG_check__Reply__thread_get_special_port_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_get_special_port */
mig_external kern_return_t thread_get_special_port
(
	thread_act_t thr_act,
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

#ifdef	__MIG_check__Reply__thread_get_special_port_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_get_special_port_t__defined */

	__DeclareSendRpc(3610, "thread_get_special_port")

	InP->NDR = NDR_record;

	InP->which_port = which_port;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = thr_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3610;

	__BeforeSendRpc(3610, "thread_get_special_port")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3610, "thread_get_special_port")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_get_special_port_t__defined)
	check_result = __MIG_check__Reply__thread_get_special_port_t((__Reply__thread_get_special_port_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_get_special_port_t__defined) */

	*special_port = Out0P->special_port.name;
	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_set_special_port_t__defined)
#define __MIG_check__Reply__thread_set_special_port_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_set_special_port_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_set_special_port_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_set_special_port_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_set_special_port_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_set_special_port_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_set_special_port_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_set_special_port_t(__Reply__thread_set_special_port_t *Out0P)
{

	typedef __Reply__thread_set_special_port_t __Reply;
	if (Out0P->Head.msgh_id != 3711) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_set_special_port_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_set_special_port_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_set_special_port_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_set_special_port_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_set_special_port */
mig_external kern_return_t thread_set_special_port
(
	thread_act_t thr_act,
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

#ifdef	__MIG_check__Reply__thread_set_special_port_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_set_special_port_t__defined */

	__DeclareSendRpc(3611, "thread_set_special_port")

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
	InP->Head.msgh_request_port = thr_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3611;

	__BeforeSendRpc(3611, "thread_set_special_port")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3611, "thread_set_special_port")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_set_special_port_t__defined)
	check_result = __MIG_check__Reply__thread_set_special_port_t((__Reply__thread_set_special_port_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_set_special_port_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_info_t__defined)
#define __MIG_check__Reply__thread_info_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_info_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_info_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_info_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_info_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_info_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_info_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_info_t__thread_info_out__defined
#if	defined(__NDR_convert__int_rep__thread_act__thread_info_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__int_rep__thread_act__thread_info_t((thread_info_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_info_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__int_rep__thread_info_t((thread_info_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_act__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__thread_act__integer_t)
#elif	defined(__NDR_convert__int_rep__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__integer_t)
#elif	defined(__NDR_convert__int_rep__thread_act__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_info_t__thread_info_out__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_info_t__thread_info_outCnt__defined
#if	defined(__NDR_convert__int_rep__thread_act__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_outCnt__defined
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_outCnt(a, f) \
	__NDR_convert__int_rep__thread_act__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_outCnt__defined
#define	__NDR_convert__int_rep__Reply__thread_info_t__thread_info_outCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_info_t__thread_info_outCnt__defined */



#ifndef __NDR_convert__char_rep__Reply__thread_info_t__thread_info_out__defined
#if	defined(__NDR_convert__char_rep__thread_act__thread_info_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__char_rep__thread_act__thread_info_t((thread_info_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_info_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__char_rep__thread_info_t((thread_info_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_act__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__thread_act__integer_t)
#elif	defined(__NDR_convert__char_rep__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__integer_t)
#elif	defined(__NDR_convert__char_rep__thread_act__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__thread_info_t__thread_info_out__defined */




#ifndef __NDR_convert__float_rep__Reply__thread_info_t__thread_info_out__defined
#if	defined(__NDR_convert__float_rep__thread_act__thread_info_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__float_rep__thread_act__thread_info_t((thread_info_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_info_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__float_rep__thread_info_t((thread_info_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_act__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__thread_act__integer_t)
#elif	defined(__NDR_convert__float_rep__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__integer_t)
#elif	defined(__NDR_convert__float_rep__thread_act__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out__defined
#define	__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__thread_info_t__thread_info_out__defined */




mig_internal kern_return_t __MIG_check__Reply__thread_info_t(__Reply__thread_info_t *Out0P)
{

	typedef __Reply__thread_info_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */

	if (Out0P->Head.msgh_id != 3712) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size > (mach_msg_size_t)sizeof(__Reply) || msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 48)) &&
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

#if defined(__NDR_convert__int_rep__Reply__thread_info_t__thread_info_outCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_info_t__thread_info_outCnt(&Out0P->thread_info_outCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_info_t__thread_info_outCnt__defined */
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Reply) - 48) + ((4 * Out0P->thread_info_outCnt)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__thread_info_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_info_t__thread_info_outCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__thread_info_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__thread_info_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__thread_info_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out__defined)
		__NDR_convert__int_rep__Reply__thread_info_t__thread_info_out(&Out0P->thread_info_out, Out0P->NDR.int_rep, Out0P->thread_info_outCnt);
#endif /* __NDR_convert__int_rep__Reply__thread_info_t__thread_info_out__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out__defined) || \
	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out__defined)
		__NDR_convert__char_rep__Reply__thread_info_t__thread_info_out(&Out0P->thread_info_out, Out0P->NDR.char_rep, Out0P->thread_info_outCnt);
#endif /* __NDR_convert__char_rep__Reply__thread_info_t__thread_info_out__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out__defined) || \
	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out__defined)
		__NDR_convert__float_rep__Reply__thread_info_t__thread_info_out(&Out0P->thread_info_out, Out0P->NDR.float_rep, Out0P->thread_info_outCnt);
#endif /* __NDR_convert__float_rep__Reply__thread_info_t__thread_info_out__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__thread_info_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_info */
mig_external kern_return_t thread_info
(
	thread_act_t target_act,
	thread_flavor_t flavor,
	thread_info_t thread_info_out,
	mach_msg_type_number_t *thread_info_outCnt
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		thread_flavor_t flavor;
		mach_msg_type_number_t thread_info_outCnt;
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
		mach_msg_type_number_t thread_info_outCnt;
		integer_t thread_info_out[12];
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
		mach_msg_type_number_t thread_info_outCnt;
		integer_t thread_info_out[12];
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

#ifdef	__MIG_check__Reply__thread_info_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_info_t__defined */

	__DeclareSendRpc(3612, "thread_info")

	InP->NDR = NDR_record;

	InP->flavor = flavor;

	if (*thread_info_outCnt < 12)
		InP->thread_info_outCnt = *thread_info_outCnt;
	else
		InP->thread_info_outCnt = 12;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3612;

	__BeforeSendRpc(3612, "thread_info")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3612, "thread_info")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_info_t__defined)
	check_result = __MIG_check__Reply__thread_info_t((__Reply__thread_info_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_info_t__defined) */

	if (Out0P->thread_info_outCnt > *thread_info_outCnt) {
		(void)memcpy((char *) thread_info_out, (const char *) Out0P->thread_info_out, 4 *  *thread_info_outCnt);
		*thread_info_outCnt = Out0P->thread_info_outCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) thread_info_out, (const char *) Out0P->thread_info_out, 4 * Out0P->thread_info_outCnt);

	*thread_info_outCnt = Out0P->thread_info_outCnt;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_set_exception_ports_t__defined)
#define __MIG_check__Reply__thread_set_exception_ports_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_set_exception_ports_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_set_exception_ports_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_set_exception_ports_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_set_exception_ports_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_set_exception_ports_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_set_exception_ports_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_set_exception_ports_t(__Reply__thread_set_exception_ports_t *Out0P)
{

	typedef __Reply__thread_set_exception_ports_t __Reply;
	if (Out0P->Head.msgh_id != 3713) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_set_exception_ports_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_set_exception_ports_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_set_exception_ports_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_set_exception_ports_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_set_exception_ports */
mig_external kern_return_t thread_set_exception_ports
(
	thread_act_t thread,
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

#ifdef	__MIG_check__Reply__thread_set_exception_ports_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_set_exception_ports_t__defined */

	__DeclareSendRpc(3613, "thread_set_exception_ports")

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
	InP->Head.msgh_request_port = thread;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3613;

	__BeforeSendRpc(3613, "thread_set_exception_ports")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3613, "thread_set_exception_ports")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_set_exception_ports_t__defined)
	check_result = __MIG_check__Reply__thread_set_exception_ports_t((__Reply__thread_set_exception_ports_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_set_exception_ports_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_get_exception_ports_t__defined)
#define __MIG_check__Reply__thread_get_exception_ports_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined
#if	defined(__NDR_convert__int_rep__thread_act__exception_mask_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__int_rep__thread_act__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_mask_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__int_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_act__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__int_rep__thread_act__exception_mask_t)
#elif	defined(__NDR_convert__int_rep__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__int_rep__exception_mask_t)
#elif	defined(__NDR_convert__int_rep__thread_act__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__thread_act__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__thread_act__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masksCnt__defined
#if	defined(__NDR_convert__int_rep__thread_act__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masksCnt__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masksCnt(a, f) \
	__NDR_convert__int_rep__thread_act__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masksCnt__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masksCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masksCnt__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__int_rep__thread_act__exception_behavior_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__int_rep__thread_act__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__int_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_act__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__int_rep__thread_act__exception_behavior_t)
#elif	defined(__NDR_convert__int_rep__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__int_rep__exception_behavior_t)
#elif	defined(__NDR_convert__int_rep__thread_act__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__thread_act__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__thread_act__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__int_rep__thread_act__exception_flavor_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__int_rep__thread_act__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__int_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_act__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__int_rep__thread_act__thread_state_flavor_t)
#elif	defined(__NDR_convert__int_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__int_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__int_rep__thread_act__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__thread_act__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__thread_act__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined */


#ifndef __NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined
#if	defined(__NDR_convert__char_rep__thread_act__exception_mask_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__char_rep__thread_act__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_mask_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__char_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_act__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__char_rep__thread_act__exception_mask_t)
#elif	defined(__NDR_convert__char_rep__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__char_rep__exception_mask_t)
#elif	defined(__NDR_convert__char_rep__thread_act__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__thread_act__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__thread_act__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined */



#ifndef __NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__char_rep__thread_act__exception_behavior_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__char_rep__thread_act__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__char_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_act__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__char_rep__thread_act__exception_behavior_t)
#elif	defined(__NDR_convert__char_rep__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__char_rep__exception_behavior_t)
#elif	defined(__NDR_convert__char_rep__thread_act__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__thread_act__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__thread_act__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__char_rep__thread_act__exception_flavor_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__char_rep__thread_act__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__char_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_act__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__char_rep__thread_act__thread_state_flavor_t)
#elif	defined(__NDR_convert__char_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__char_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__char_rep__thread_act__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__thread_act__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__thread_act__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined */


#ifndef __NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined
#if	defined(__NDR_convert__float_rep__thread_act__exception_mask_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__float_rep__thread_act__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_mask_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__float_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_act__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__float_rep__thread_act__exception_mask_t)
#elif	defined(__NDR_convert__float_rep__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__float_rep__exception_mask_t)
#elif	defined(__NDR_convert__float_rep__thread_act__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__thread_act__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__thread_act__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined */



#ifndef __NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__float_rep__thread_act__exception_behavior_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__float_rep__thread_act__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__float_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_act__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__float_rep__thread_act__exception_behavior_t)
#elif	defined(__NDR_convert__float_rep__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__float_rep__exception_behavior_t)
#elif	defined(__NDR_convert__float_rep__thread_act__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__thread_act__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__thread_act__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__float_rep__thread_act__exception_flavor_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__float_rep__thread_act__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__float_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_act__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__float_rep__thread_act__thread_state_flavor_t)
#elif	defined(__NDR_convert__float_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__float_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__float_rep__thread_act__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__thread_act__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__thread_act__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined */



mig_internal kern_return_t __MIG_check__Reply__thread_get_exception_ports_t(__Reply__thread_get_exception_ports_t *Out0P, __Reply__thread_get_exception_ports_t **Out1PP, __Reply__thread_get_exception_ports_t **Out2PP)
{

	typedef __Reply__thread_get_exception_ports_t __Reply;
	__Reply *Out1P;
	__Reply *Out2P;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	unsigned int msgh_size_delta;

	if (Out0P->Head.msgh_id != 3714) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masksCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masksCnt(&Out0P->masksCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masksCnt__defined */
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

#if	defined(__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masksCnt__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined)
		__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__masks__defined */
#if defined(__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined)
		__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined)
		__NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__thread_get_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined) || \
	0 || \
	defined(__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined)
		__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__thread_get_exception_ports_t__masks__defined */
#if defined(__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined)
		__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined)
		__NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__thread_get_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined) || \
	0 || \
	defined(__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined)
		__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__thread_get_exception_ports_t__masks__defined */
#if defined(__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined)
		__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined)
		__NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__thread_get_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__thread_get_exception_ports_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_get_exception_ports */
mig_external kern_return_t thread_get_exception_ports
(
	thread_act_t thread,
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

#ifdef	__MIG_check__Reply__thread_get_exception_ports_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_get_exception_ports_t__defined */

	__DeclareSendRpc(3614, "thread_get_exception_ports")

	InP->NDR = NDR_record;

	InP->exception_mask = exception_mask;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = thread;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3614;

	__BeforeSendRpc(3614, "thread_get_exception_ports")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3614, "thread_get_exception_ports")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_get_exception_ports_t__defined)
	check_result = __MIG_check__Reply__thread_get_exception_ports_t((__Reply__thread_get_exception_ports_t *)Out0P, (__Reply__thread_get_exception_ports_t **)&Out1P, (__Reply__thread_get_exception_ports_t **)&Out2P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_get_exception_ports_t__defined) */

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
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_swap_exception_ports_t__defined)
#define __MIG_check__Reply__thread_swap_exception_ports_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined
#if	defined(__NDR_convert__int_rep__thread_act__exception_mask_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__int_rep__thread_act__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_mask_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__int_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_act__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__int_rep__thread_act__exception_mask_t)
#elif	defined(__NDR_convert__int_rep__exception_mask_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__int_rep__exception_mask_t)
#elif	defined(__NDR_convert__int_rep__thread_act__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__thread_act__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__thread_act__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masksCnt__defined
#if	defined(__NDR_convert__int_rep__thread_act__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masksCnt__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masksCnt(a, f) \
	__NDR_convert__int_rep__thread_act__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masksCnt__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masksCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masksCnt__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__int_rep__thread_act__exception_behavior_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__int_rep__thread_act__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__int_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_act__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__int_rep__thread_act__exception_behavior_t)
#elif	defined(__NDR_convert__int_rep__exception_behavior_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__int_rep__exception_behavior_t)
#elif	defined(__NDR_convert__int_rep__thread_act__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__thread_act__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__thread_act__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__int_rep__thread_act__exception_flavor_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__int_rep__thread_act__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__int_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_act__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__int_rep__thread_act__thread_state_flavor_t)
#elif	defined(__NDR_convert__int_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__int_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__int_rep__thread_act__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__thread_act__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__thread_act__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined */


#ifndef __NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined
#if	defined(__NDR_convert__char_rep__thread_act__exception_mask_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__char_rep__thread_act__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_mask_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__char_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_act__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__char_rep__thread_act__exception_mask_t)
#elif	defined(__NDR_convert__char_rep__exception_mask_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__char_rep__exception_mask_t)
#elif	defined(__NDR_convert__char_rep__thread_act__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__thread_act__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__thread_act__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined */



#ifndef __NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__char_rep__thread_act__exception_behavior_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__char_rep__thread_act__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__char_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_act__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__char_rep__thread_act__exception_behavior_t)
#elif	defined(__NDR_convert__char_rep__exception_behavior_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__char_rep__exception_behavior_t)
#elif	defined(__NDR_convert__char_rep__thread_act__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__thread_act__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__thread_act__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__char_rep__thread_act__exception_flavor_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__char_rep__thread_act__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__char_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_act__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__char_rep__thread_act__thread_state_flavor_t)
#elif	defined(__NDR_convert__char_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__char_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__char_rep__thread_act__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__thread_act__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__thread_act__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined */


#ifndef __NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined
#if	defined(__NDR_convert__float_rep__thread_act__exception_mask_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__float_rep__thread_act__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_mask_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__float_rep__exception_mask_array_t((exception_mask_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_act__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__float_rep__thread_act__exception_mask_t)
#elif	defined(__NDR_convert__float_rep__exception_mask_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((exception_mask_t *)(a), f, c, __NDR_convert__float_rep__exception_mask_t)
#elif	defined(__NDR_convert__float_rep__thread_act__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__thread_act__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__thread_act__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined */



#ifndef __NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#if	defined(__NDR_convert__float_rep__thread_act__exception_behavior_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__float_rep__thread_act__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_behavior_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__float_rep__exception_behavior_array_t((exception_behavior_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_act__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__float_rep__thread_act__exception_behavior_t)
#elif	defined(__NDR_convert__float_rep__exception_behavior_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((exception_behavior_t *)(a), f, c, __NDR_convert__float_rep__exception_behavior_t)
#elif	defined(__NDR_convert__float_rep__thread_act__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__thread_act__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__thread_act__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined */


#ifndef __NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#if	defined(__NDR_convert__float_rep__thread_act__exception_flavor_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__float_rep__thread_act__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__exception_flavor_array_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__float_rep__exception_flavor_array_t((exception_flavor_array_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_act__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__float_rep__thread_act__thread_state_flavor_t)
#elif	defined(__NDR_convert__float_rep__thread_state_flavor_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((thread_state_flavor_t *)(a), f, c, __NDR_convert__float_rep__thread_state_flavor_t)
#elif	defined(__NDR_convert__float_rep__thread_act__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__thread_act__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__thread_act__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined
#define	__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined */



mig_internal kern_return_t __MIG_check__Reply__thread_swap_exception_ports_t(__Reply__thread_swap_exception_ports_t *Out0P, __Reply__thread_swap_exception_ports_t **Out1PP, __Reply__thread_swap_exception_ports_t **Out2PP)
{

	typedef __Reply__thread_swap_exception_ports_t __Reply;
	__Reply *Out1P;
	__Reply *Out2P;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	unsigned int msgh_size_delta;

	if (Out0P->Head.msgh_id != 3715) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masksCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masksCnt(&Out0P->masksCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masksCnt__defined */
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

#if	defined(__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masksCnt__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined)
		__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__masks__defined */
#if defined(__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined)
		__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined)
		__NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.int_rep, Out0P->masksCnt);
#endif /* __NDR_convert__int_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined) || \
	0 || \
	defined(__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined)
		__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__masks__defined */
#if defined(__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined)
		__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined)
		__NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.char_rep, Out0P->masksCnt);
#endif /* __NDR_convert__char_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined) || \
	0 || \
	defined(__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined) || \
	defined(__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined)
		__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks(&Out0P->masks, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__masks__defined */
#if defined(__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined)
		__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors(&Out1P->old_behaviors, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_behaviors__defined */
#if defined(__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined)
		__NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors(&Out2P->old_flavors, Out0P->NDR.float_rep, Out0P->masksCnt);
#endif /* __NDR_convert__float_rep__Reply__thread_swap_exception_ports_t__old_flavors__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__thread_swap_exception_ports_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_swap_exception_ports */
mig_external kern_return_t thread_swap_exception_ports
(
	thread_act_t thread,
	exception_mask_t exception_mask,
	mach_port_t new_port,
	exception_behavior_t behavior,
	thread_state_flavor_t new_flavor,
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

#ifdef	__MIG_check__Reply__thread_swap_exception_ports_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_swap_exception_ports_t__defined */

	__DeclareSendRpc(3615, "thread_swap_exception_ports")

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
	InP->Head.msgh_request_port = thread;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3615;

	__BeforeSendRpc(3615, "thread_swap_exception_ports")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3615, "thread_swap_exception_ports")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_swap_exception_ports_t__defined)
	check_result = __MIG_check__Reply__thread_swap_exception_ports_t((__Reply__thread_swap_exception_ports_t *)Out0P, (__Reply__thread_swap_exception_ports_t **)&Out1P, (__Reply__thread_swap_exception_ports_t **)&Out2P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_swap_exception_ports_t__defined) */

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
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_policy_t__defined)
#define __MIG_check__Reply__thread_policy_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_policy_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_policy_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_policy_t(__Reply__thread_policy_t *Out0P)
{

	typedef __Reply__thread_policy_t __Reply;
	if (Out0P->Head.msgh_id != 3716) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_policy_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_policy_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_policy_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_policy_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_policy */
mig_external kern_return_t thread_policy
(
	thread_act_t thr_act,
	policy_t policy,
	policy_base_t base,
	mach_msg_type_number_t baseCnt,
	boolean_t set_limit
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


#ifdef	__MIG_check__Reply__thread_policy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_policy_t__defined */

	__DeclareSendRpc(3616, "thread_policy")

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

	InP = &Mess.In;
	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = thr_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3616;

	__BeforeSendRpc(3616, "thread_policy")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3616, "thread_policy")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_policy_t__defined)
	check_result = __MIG_check__Reply__thread_policy_t((__Reply__thread_policy_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_policy_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_policy_set_t__defined)
#define __MIG_check__Reply__thread_policy_set_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_policy_set_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_set_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_set_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_set_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_set_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_policy_set_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_policy_set_t(__Reply__thread_policy_set_t *Out0P)
{

	typedef __Reply__thread_policy_set_t __Reply;
	if (Out0P->Head.msgh_id != 3717) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_policy_set_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_policy_set_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_policy_set_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_policy_set_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_policy_set */
mig_external kern_return_t thread_policy_set
(
	thread_act_t thread,
	thread_policy_flavor_t flavor,
	thread_policy_t policy_info,
	mach_msg_type_number_t policy_infoCnt
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		thread_policy_flavor_t flavor;
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

#ifdef	__MIG_check__Reply__thread_policy_set_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_policy_set_t__defined */

	__DeclareSendRpc(3617, "thread_policy_set")

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
	InP->Head.msgh_request_port = thread;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3617;

	__BeforeSendRpc(3617, "thread_policy_set")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3617, "thread_policy_set")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_policy_set_t__defined)
	check_result = __MIG_check__Reply__thread_policy_set_t((__Reply__thread_policy_set_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_policy_set_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_policy_get_t__defined)
#define __MIG_check__Reply__thread_policy_get_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_policy_get_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_policy_get_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info__defined
#if	defined(__NDR_convert__int_rep__thread_act__thread_policy_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__int_rep__thread_act__thread_policy_t((thread_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_policy_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__int_rep__thread_policy_t((thread_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__thread_act__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__thread_act__integer_t)
#elif	defined(__NDR_convert__int_rep__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__int_rep__integer_t)
#elif	defined(__NDR_convert__int_rep__thread_act__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_policy_get_t__policy_infoCnt__defined
#if	defined(__NDR_convert__int_rep__thread_act__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_infoCnt__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_infoCnt(a, f) \
	__NDR_convert__int_rep__thread_act__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_infoCnt__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_infoCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_policy_get_t__policy_infoCnt__defined */


#ifndef __NDR_convert__int_rep__Reply__thread_policy_get_t__get_default__defined
#if	defined(__NDR_convert__int_rep__thread_act__boolean_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__get_default__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__get_default(a, f) \
	__NDR_convert__int_rep__thread_act__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__boolean_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__get_default__defined
#define	__NDR_convert__int_rep__Reply__thread_policy_get_t__get_default(a, f) \
	__NDR_convert__int_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_policy_get_t__get_default__defined */



#ifndef __NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info__defined
#if	defined(__NDR_convert__char_rep__thread_act__thread_policy_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__char_rep__thread_act__thread_policy_t((thread_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_policy_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__char_rep__thread_policy_t((thread_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__thread_act__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__thread_act__integer_t)
#elif	defined(__NDR_convert__char_rep__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__char_rep__integer_t)
#elif	defined(__NDR_convert__char_rep__thread_act__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info__defined */



#ifndef __NDR_convert__char_rep__Reply__thread_policy_get_t__get_default__defined
#if	defined(__NDR_convert__char_rep__thread_act__boolean_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__get_default__defined
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__get_default(a, f) \
	__NDR_convert__char_rep__thread_act__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__boolean_t__defined)
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__get_default__defined
#define	__NDR_convert__char_rep__Reply__thread_policy_get_t__get_default(a, f) \
	__NDR_convert__char_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__thread_policy_get_t__get_default__defined */



#ifndef __NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info__defined
#if	defined(__NDR_convert__float_rep__thread_act__thread_policy_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__float_rep__thread_act__thread_policy_t((thread_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_policy_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__float_rep__thread_policy_t((thread_policy_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__thread_act__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__thread_act__integer_t)
#elif	defined(__NDR_convert__float_rep__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((integer_t *)(a), f, c, __NDR_convert__float_rep__integer_t)
#elif	defined(__NDR_convert__float_rep__thread_act__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__thread_act__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info__defined
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info__defined */



#ifndef __NDR_convert__float_rep__Reply__thread_policy_get_t__get_default__defined
#if	defined(__NDR_convert__float_rep__thread_act__boolean_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__get_default__defined
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__get_default(a, f) \
	__NDR_convert__float_rep__thread_act__boolean_t((boolean_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__boolean_t__defined)
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__get_default__defined
#define	__NDR_convert__float_rep__Reply__thread_policy_get_t__get_default(a, f) \
	__NDR_convert__float_rep__boolean_t((boolean_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__thread_policy_get_t__get_default__defined */



mig_internal kern_return_t __MIG_check__Reply__thread_policy_get_t(__Reply__thread_policy_get_t *Out0P, __Reply__thread_policy_get_t **Out1PP)
{

	typedef __Reply__thread_policy_get_t __Reply;
	__Reply *Out1P;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	unsigned int msgh_size_delta;

	if (Out0P->Head.msgh_id != 3718) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_infoCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_infoCnt(&Out0P->policy_infoCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_policy_get_t__policy_infoCnt__defined */
	msgh_size_delta = (4 * Out0P->policy_infoCnt);
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Reply) - 64) + msgh_size_delta)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

	*Out1PP = Out1P = (__Reply *) ((pointer_t) Out0P + msgh_size_delta - 64);

#if	defined(__NDR_convert__int_rep__Reply__thread_policy_get_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_infoCnt__defined) || \
	defined(__NDR_convert__int_rep__Reply__thread_policy_get_t__get_default__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__thread_policy_get_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__thread_policy_get_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__thread_policy_get_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info__defined)
		__NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info(&Out0P->policy_info, Out0P->NDR.int_rep, Out0P->policy_infoCnt);
#endif /* __NDR_convert__int_rep__Reply__thread_policy_get_t__policy_info__defined */
#if defined(__NDR_convert__int_rep__Reply__thread_policy_get_t__get_default__defined)
		__NDR_convert__int_rep__Reply__thread_policy_get_t__get_default(&Out1P->get_default, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__thread_policy_get_t__get_default__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info__defined) || \
	0 || \
	defined(__NDR_convert__char_rep__Reply__thread_policy_get_t__get_default__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info__defined)
		__NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info(&Out0P->policy_info, Out0P->NDR.char_rep, Out0P->policy_infoCnt);
#endif /* __NDR_convert__char_rep__Reply__thread_policy_get_t__policy_info__defined */
#if defined(__NDR_convert__char_rep__Reply__thread_policy_get_t__get_default__defined)
		__NDR_convert__char_rep__Reply__thread_policy_get_t__get_default(&Out1P->get_default, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__thread_policy_get_t__get_default__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info__defined) || \
	0 || \
	defined(__NDR_convert__float_rep__Reply__thread_policy_get_t__get_default__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info__defined)
		__NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info(&Out0P->policy_info, Out0P->NDR.float_rep, Out0P->policy_infoCnt);
#endif /* __NDR_convert__float_rep__Reply__thread_policy_get_t__policy_info__defined */
#if defined(__NDR_convert__float_rep__Reply__thread_policy_get_t__get_default__defined)
		__NDR_convert__float_rep__Reply__thread_policy_get_t__get_default(&Out1P->get_default, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__thread_policy_get_t__get_default__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__thread_policy_get_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_policy_get */
mig_external kern_return_t thread_policy_get
(
	thread_act_t thread,
	thread_policy_flavor_t flavor,
	thread_policy_t policy_info,
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
		thread_policy_flavor_t flavor;
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

#ifdef	__MIG_check__Reply__thread_policy_get_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_policy_get_t__defined */

	__DeclareSendRpc(3618, "thread_policy_get")

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
	InP->Head.msgh_request_port = thread;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3618;

	__BeforeSendRpc(3618, "thread_policy_get")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3618, "thread_policy_get")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_policy_get_t__defined)
	check_result = __MIG_check__Reply__thread_policy_get_t((__Reply__thread_policy_get_t *)Out0P, (__Reply__thread_policy_get_t **)&Out1P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_policy_get_t__defined) */

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
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_sample_t__defined)
#define __MIG_check__Reply__thread_sample_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_sample_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_sample_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_sample_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_sample_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_sample_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_sample_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_sample_t(__Reply__thread_sample_t *Out0P)
{

	typedef __Reply__thread_sample_t __Reply;
	if (Out0P->Head.msgh_id != 3719) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_sample_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_sample_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_sample_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_sample_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_sample */
mig_external kern_return_t thread_sample
(
	thread_act_t thread,
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

#ifdef	__MIG_check__Reply__thread_sample_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_sample_t__defined */

	__DeclareSendRpc(3619, "thread_sample")

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
	InP->Head.msgh_request_port = thread;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3619;

	__BeforeSendRpc(3619, "thread_sample")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3619, "thread_sample")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_sample_t__defined)
	check_result = __MIG_check__Reply__thread_sample_t((__Reply__thread_sample_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_sample_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__etap_trace_thread_t__defined)
#define __MIG_check__Reply__etap_trace_thread_t__defined
#ifndef __NDR_convert__int_rep__Reply__etap_trace_thread_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__etap_trace_thread_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__etap_trace_thread_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__etap_trace_thread_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__etap_trace_thread_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__etap_trace_thread_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__etap_trace_thread_t(__Reply__etap_trace_thread_t *Out0P)
{

	typedef __Reply__etap_trace_thread_t __Reply;
	if (Out0P->Head.msgh_id != 3720) {
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

#if defined(__NDR_convert__int_rep__Reply__etap_trace_thread_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__etap_trace_thread_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__etap_trace_thread_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__etap_trace_thread_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine etap_trace_thread */
mig_external kern_return_t etap_trace_thread
(
	thread_act_t target_act,
	boolean_t trace_status
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		boolean_t trace_status;
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

#ifdef	__MIG_check__Reply__etap_trace_thread_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__etap_trace_thread_t__defined */

	__DeclareSendRpc(3620, "etap_trace_thread")

	InP->NDR = NDR_record;

	InP->trace_status = trace_status;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3620;

	__BeforeSendRpc(3620, "etap_trace_thread")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3620, "etap_trace_thread")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__etap_trace_thread_t__defined)
	check_result = __MIG_check__Reply__etap_trace_thread_t((__Reply__etap_trace_thread_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__etap_trace_thread_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_assign_t__defined)
#define __MIG_check__Reply__thread_assign_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_assign_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_assign_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_assign_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_assign_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_assign_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_assign_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_assign_t(__Reply__thread_assign_t *Out0P)
{

	typedef __Reply__thread_assign_t __Reply;
	if (Out0P->Head.msgh_id != 3721) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_assign_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_assign_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_assign_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_assign_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_assign */
mig_external kern_return_t thread_assign
(
	thread_act_t thread,
	processor_set_t new_set
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

#ifdef	__MIG_check__Reply__thread_assign_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_assign_t__defined */

	__DeclareSendRpc(3621, "thread_assign")

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

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = thread;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3621;

	__BeforeSendRpc(3621, "thread_assign")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3621, "thread_assign")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_assign_t__defined)
	check_result = __MIG_check__Reply__thread_assign_t((__Reply__thread_assign_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_assign_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_assign_default_t__defined)
#define __MIG_check__Reply__thread_assign_default_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_assign_default_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_assign_default_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_assign_default_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_assign_default_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_assign_default_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_assign_default_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_assign_default_t(__Reply__thread_assign_default_t *Out0P)
{

	typedef __Reply__thread_assign_default_t __Reply;
	if (Out0P->Head.msgh_id != 3722) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_assign_default_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_assign_default_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_assign_default_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_assign_default_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_assign_default */
mig_external kern_return_t thread_assign_default
(
	thread_act_t thread
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

#ifdef	__MIG_check__Reply__thread_assign_default_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_assign_default_t__defined */

	__DeclareSendRpc(3622, "thread_assign_default")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = thread;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3622;

	__BeforeSendRpc(3622, "thread_assign_default")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3622, "thread_assign_default")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_assign_default_t__defined)
	check_result = __MIG_check__Reply__thread_assign_default_t((__Reply__thread_assign_default_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_assign_default_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_get_assignment_t__defined)
#define __MIG_check__Reply__thread_get_assignment_t__defined

mig_internal kern_return_t __MIG_check__Reply__thread_get_assignment_t(__Reply__thread_get_assignment_t *Out0P)
{

	typedef __Reply__thread_get_assignment_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 3723) {
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
#endif /* !defined(__MIG_check__Reply__thread_get_assignment_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_get_assignment */
mig_external kern_return_t thread_get_assignment
(
	thread_act_t thread,
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

#ifdef	__MIG_check__Reply__thread_get_assignment_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_get_assignment_t__defined */

	__DeclareSendRpc(3623, "thread_get_assignment")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = thread;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3623;

	__BeforeSendRpc(3623, "thread_get_assignment")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3623, "thread_get_assignment")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_get_assignment_t__defined)
	check_result = __MIG_check__Reply__thread_get_assignment_t((__Reply__thread_get_assignment_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_get_assignment_t__defined) */

	*assigned_set = Out0P->assigned_set.name;
	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__thread_act_subsystem__
#if !defined(__MIG_check__Reply__thread_set_policy_t__defined)
#define __MIG_check__Reply__thread_set_policy_t__defined
#ifndef __NDR_convert__int_rep__Reply__thread_set_policy_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__thread_act__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_set_policy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_set_policy_t__RetCode(a, f) \
	__NDR_convert__int_rep__thread_act__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__thread_set_policy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__thread_set_policy_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__thread_set_policy_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__thread_set_policy_t(__Reply__thread_set_policy_t *Out0P)
{

	typedef __Reply__thread_set_policy_t __Reply;
	if (Out0P->Head.msgh_id != 3724) {
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

#if defined(__NDR_convert__int_rep__Reply__thread_set_policy_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__thread_set_policy_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__thread_set_policy_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__thread_set_policy_t__defined) */
#endif /* __MIG_check__Reply__thread_act_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine thread_set_policy */
mig_external kern_return_t thread_set_policy
(
	thread_act_t thr_act,
	processor_set_t pset,
	policy_t policy,
	policy_base_t base,
	mach_msg_type_number_t baseCnt,
	policy_limit_t limit,
	mach_msg_type_number_t limitCnt
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


#ifdef	__MIG_check__Reply__thread_set_policy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__thread_set_policy_t__defined */

	__DeclareSendRpc(3624, "thread_set_policy")

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

	msgh_size += (4 * limitCnt);
	InP = &Mess.In;
	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = thr_act;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 3624;

	__BeforeSendRpc(3624, "thread_set_policy")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(3624, "thread_set_policy")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__thread_set_policy_t__defined)
	check_result = __MIG_check__Reply__thread_set_policy_t((__Reply__thread_set_policy_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__thread_set_policy_t__defined) */

	return KERN_SUCCESS;
}
