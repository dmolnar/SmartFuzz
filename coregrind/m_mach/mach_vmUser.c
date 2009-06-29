/*
 * IDENTIFICATION:
 * stub generated Mon Jun 15 19:50:16 2009
 * with a MiG generated Tue Feb 19 02:01:43 PST 2008 by root@b75.local
 * OPTIONS: 
 */
#define	__MIG_check__Reply__mach_vm_subsystem__ 1
#define	__NDR_convert__Reply__mach_vm_subsystem__ 1
#define	__NDR_convert__mig_reply_error_subsystem__ 1

#include "mach_vm.h"


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
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_allocate_t__defined)
#define __MIG_check__Reply__mach_vm_allocate_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_allocate_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_allocate_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_allocate_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_allocate_t__address__defined */



#ifndef __NDR_convert__char_rep__Reply__mach_vm_allocate_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_allocate_t__address__defined */



#ifndef __NDR_convert__float_rep__Reply__mach_vm_allocate_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_allocate_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_allocate_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_allocate_t__address__defined */



mig_internal kern_return_t __MIG_check__Reply__mach_vm_allocate_t(__Reply__mach_vm_allocate_t *Out0P)
{

	typedef __Reply__mach_vm_allocate_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 4900) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
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

#if	defined(__NDR_convert__int_rep__Reply__mach_vm_allocate_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_allocate_t__address__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_vm_allocate_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__mach_vm_allocate_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_allocate_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_allocate_t__address__defined)
		__NDR_convert__int_rep__Reply__mach_vm_allocate_t__address(&Out0P->address, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_allocate_t__address__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_allocate_t__address__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__mach_vm_allocate_t__address__defined)
		__NDR_convert__char_rep__Reply__mach_vm_allocate_t__address(&Out0P->address, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_allocate_t__address__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_allocate_t__address__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__mach_vm_allocate_t__address__defined)
		__NDR_convert__float_rep__Reply__mach_vm_allocate_t__address(&Out0P->address, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_allocate_t__address__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_vm_allocate_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_allocate */
mig_external kern_return_t mach_vm_allocate
(
	vm_map_t target,
	mach_vm_address_t *address,
	mach_vm_size_t size,
	int flags
)
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
		mach_vm_address_t address;
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
		mach_vm_address_t address;
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

#ifdef	__MIG_check__Reply__mach_vm_allocate_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_allocate_t__defined */

	__DeclareSendRpc(4800, "mach_vm_allocate")

	InP->NDR = NDR_record;

	InP->address = *address;

	InP->size = size;

	InP->flags = flags;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4800;

	__BeforeSendRpc(4800, "mach_vm_allocate")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4800, "mach_vm_allocate")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_allocate_t__defined)
	check_result = __MIG_check__Reply__mach_vm_allocate_t((__Reply__mach_vm_allocate_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_allocate_t__defined) */

	*address = Out0P->address;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_deallocate_t__defined)
#define __MIG_check__Reply__mach_vm_deallocate_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_deallocate_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_deallocate_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_deallocate_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_deallocate_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_deallocate_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_deallocate_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__mach_vm_deallocate_t(__Reply__mach_vm_deallocate_t *Out0P)
{

	typedef __Reply__mach_vm_deallocate_t __Reply;
	if (Out0P->Head.msgh_id != 4901) {
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

#if defined(__NDR_convert__int_rep__Reply__mach_vm_deallocate_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__mach_vm_deallocate_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__mach_vm_deallocate_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__mach_vm_deallocate_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_deallocate */
mig_external kern_return_t mach_vm_deallocate
(
	vm_map_t target,
	mach_vm_address_t address,
	mach_vm_size_t size
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
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

#ifdef	__MIG_check__Reply__mach_vm_deallocate_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_deallocate_t__defined */

	__DeclareSendRpc(4801, "mach_vm_deallocate")

	InP->NDR = NDR_record;

	InP->address = address;

	InP->size = size;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4801;

	__BeforeSendRpc(4801, "mach_vm_deallocate")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4801, "mach_vm_deallocate")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_deallocate_t__defined)
	check_result = __MIG_check__Reply__mach_vm_deallocate_t((__Reply__mach_vm_deallocate_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_deallocate_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_protect_t__defined)
#define __MIG_check__Reply__mach_vm_protect_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_protect_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_protect_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_protect_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_protect_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_protect_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_protect_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__mach_vm_protect_t(__Reply__mach_vm_protect_t *Out0P)
{

	typedef __Reply__mach_vm_protect_t __Reply;
	if (Out0P->Head.msgh_id != 4902) {
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

#if defined(__NDR_convert__int_rep__Reply__mach_vm_protect_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__mach_vm_protect_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__mach_vm_protect_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__mach_vm_protect_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_protect */
mig_external kern_return_t mach_vm_protect
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	boolean_t set_maximum,
	vm_prot_t new_protection
)
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

#ifdef	__MIG_check__Reply__mach_vm_protect_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_protect_t__defined */

	__DeclareSendRpc(4802, "mach_vm_protect")

	InP->NDR = NDR_record;

	InP->address = address;

	InP->size = size;

	InP->set_maximum = set_maximum;

	InP->new_protection = new_protection;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4802;

	__BeforeSendRpc(4802, "mach_vm_protect")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4802, "mach_vm_protect")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_protect_t__defined)
	check_result = __MIG_check__Reply__mach_vm_protect_t((__Reply__mach_vm_protect_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_protect_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_inherit_t__defined)
#define __MIG_check__Reply__mach_vm_inherit_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_inherit_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_inherit_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_inherit_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_inherit_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_inherit_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_inherit_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__mach_vm_inherit_t(__Reply__mach_vm_inherit_t *Out0P)
{

	typedef __Reply__mach_vm_inherit_t __Reply;
	if (Out0P->Head.msgh_id != 4903) {
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

#if defined(__NDR_convert__int_rep__Reply__mach_vm_inherit_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__mach_vm_inherit_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__mach_vm_inherit_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__mach_vm_inherit_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_inherit */
mig_external kern_return_t mach_vm_inherit
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	vm_inherit_t new_inheritance
)
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

#ifdef	__MIG_check__Reply__mach_vm_inherit_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_inherit_t__defined */

	__DeclareSendRpc(4803, "mach_vm_inherit")

	InP->NDR = NDR_record;

	InP->address = address;

	InP->size = size;

	InP->new_inheritance = new_inheritance;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4803;

	__BeforeSendRpc(4803, "mach_vm_inherit")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4803, "mach_vm_inherit")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_inherit_t__defined)
	check_result = __MIG_check__Reply__mach_vm_inherit_t((__Reply__mach_vm_inherit_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_inherit_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_read_t__defined)
#define __MIG_check__Reply__mach_vm_read_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_read_t__data__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_offset_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_t__data__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_t__data(a, f, c) \
	__NDR_convert__int_rep__mach_vm__vm_offset_t((vm_offset_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__vm_offset_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_t__data__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_t__data(a, f, c) \
	__NDR_convert__int_rep__vm_offset_t((vm_offset_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_read_t__data__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_read_t__dataCnt__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_t__dataCnt__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_t__dataCnt(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_t__dataCnt__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_t__dataCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_read_t__dataCnt__defined */


#ifndef __NDR_convert__char_rep__Reply__mach_vm_read_t__data__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_offset_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_t__data__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_t__data(a, f, c) \
	__NDR_convert__char_rep__mach_vm__vm_offset_t((vm_offset_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__vm_offset_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_t__data__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_t__data(a, f, c) \
	__NDR_convert__char_rep__vm_offset_t((vm_offset_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_read_t__data__defined */



#ifndef __NDR_convert__float_rep__Reply__mach_vm_read_t__data__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_offset_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_t__data__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_t__data(a, f, c) \
	__NDR_convert__float_rep__mach_vm__vm_offset_t((vm_offset_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__vm_offset_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_t__data__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_t__data(a, f, c) \
	__NDR_convert__float_rep__vm_offset_t((vm_offset_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_read_t__data__defined */




mig_internal kern_return_t __MIG_check__Reply__mach_vm_read_t(__Reply__mach_vm_read_t *Out0P)
{

	typedef __Reply__mach_vm_read_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 4904) {
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
	if (Out0P->data.type != MACH_MSG_OOL_DESCRIPTOR)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__mach_vm_read_t__data__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_read_t__dataCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_vm_read_t__dataCnt__defined)
		__NDR_convert__int_rep__Reply__mach_vm_read_t__dataCnt(&Out0P->dataCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__mach_vm_read_t__dataCnt__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_read_t__data__defined)
		__NDR_convert__int_rep__Reply__mach_vm_read_t__data((vm_offset_t)(Out0P->data.address), Out0P->NDR.int_rep, Out0P->dataCnt);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_read_t__data__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Reply__mach_vm_read_t__data__defined) || \
	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__mach_vm_read_t__data__defined)
		__NDR_convert__char_rep__Reply__mach_vm_read_t__data((vm_offset_t)(Out0P->data.address), Out0P->NDR.char_rep, Out0P->dataCnt);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_read_t__data__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Reply__mach_vm_read_t__data__defined) || \
	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__mach_vm_read_t__data__defined)
		__NDR_convert__float_rep__Reply__mach_vm_read_t__data((vm_offset_t)(Out0P->data.address), Out0P->NDR.float_rep, Out0P->dataCnt);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_read_t__data__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_vm_read_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_read */
mig_external kern_return_t mach_vm_read
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	vm_offset_t *data,
	mach_msg_type_number_t *dataCnt
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
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
		mach_msg_ool_descriptor_t data;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t dataCnt;
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
		mach_msg_ool_descriptor_t data;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t dataCnt;
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

#ifdef	__MIG_check__Reply__mach_vm_read_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_read_t__defined */

	__DeclareSendRpc(4804, "mach_vm_read")

	InP->NDR = NDR_record;

	InP->address = address;

	InP->size = size;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4804;

	__BeforeSendRpc(4804, "mach_vm_read")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4804, "mach_vm_read")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_read_t__defined)
	check_result = __MIG_check__Reply__mach_vm_read_t((__Reply__mach_vm_read_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_read_t__defined) */

	*data = (vm_offset_t)(Out0P->data.address);
	*dataCnt = Out0P->dataCnt;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_read_list_t__defined)
#define __MIG_check__Reply__mach_vm_read_list_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_read_list_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_read_list_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_read_entry_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_read_entry_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__int_rep__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__int_rep__mach_vm__mach_vm_offset_t)
#elif	defined(__NDR_convert__int_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__int_rep__mach_vm_offset_t)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__int_rep__mach_vm__uint64_t)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__int_rep__uint64_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list__defined */



#ifndef __NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_read_entry_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_read_entry_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__char_rep__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__char_rep__mach_vm__mach_vm_offset_t)
#elif	defined(__NDR_convert__char_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__char_rep__mach_vm_offset_t)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__char_rep__mach_vm__uint64_t)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__char_rep__uint64_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list__defined */



#ifndef __NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_read_entry_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_read_entry_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__float_rep__mach_vm_read_entry_t((mach_vm_read_entry_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__mach_vm_offset_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__float_rep__mach_vm__mach_vm_offset_t)
#elif	defined(__NDR_convert__float_rep__mach_vm_offset_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((mach_vm_offset_t *)(a), f, 512, __NDR_convert__float_rep__mach_vm_offset_t)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__float_rep__mach_vm__uint64_t)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list(a, f) \
	__NDR_convert__ARRAY((uint64_t *)(a), f, 512, __NDR_convert__float_rep__uint64_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list__defined */



mig_internal kern_return_t __MIG_check__Reply__mach_vm_read_list_t(__Reply__mach_vm_read_list_t *Out0P)
{

	typedef __Reply__mach_vm_read_list_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 4905) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
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

#if	defined(__NDR_convert__int_rep__Reply__mach_vm_read_list_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_vm_read_list_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__mach_vm_read_list_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_read_list_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list__defined)
		__NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list(&Out0P->data_list, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_read_list_t__data_list__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list__defined)
		__NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list(&Out0P->data_list, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_read_list_t__data_list__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list__defined)
		__NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list(&Out0P->data_list, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_read_list_t__data_list__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_vm_read_list_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_read_list */
mig_external kern_return_t mach_vm_read_list
(
	vm_map_t target_task,
	mach_vm_read_entry_t data_list,
	natural_t count
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_read_entry_t data_list;
		natural_t count;
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
		mach_vm_read_entry_t data_list;
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
		mach_vm_read_entry_t data_list;
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

#ifdef	__MIG_check__Reply__mach_vm_read_list_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_read_list_t__defined */

	__DeclareSendRpc(4805, "mach_vm_read_list")

	InP->NDR = NDR_record;

	{   typedef struct { char data[4096]; } *sp;
	    * (sp) InP->data_list = * (sp) data_list;
	}

	InP->count = count;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4805;

	__BeforeSendRpc(4805, "mach_vm_read_list")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4805, "mach_vm_read_list")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_read_list_t__defined)
	check_result = __MIG_check__Reply__mach_vm_read_list_t((__Reply__mach_vm_read_list_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_read_list_t__defined) */

	{   typedef struct { char data[4096]; } *sp;
	    * (sp) data_list = * (sp) Out0P->data_list;
	}

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_write_t__defined)
#define __MIG_check__Reply__mach_vm_write_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_write_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_write_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_write_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_write_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_write_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_write_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__mach_vm_write_t(__Reply__mach_vm_write_t *Out0P)
{

	typedef __Reply__mach_vm_write_t __Reply;
	if (Out0P->Head.msgh_id != 4906) {
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

#if defined(__NDR_convert__int_rep__Reply__mach_vm_write_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__mach_vm_write_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__mach_vm_write_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__mach_vm_write_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_write */
mig_external kern_return_t mach_vm_write
(
	vm_map_t target_task,
	mach_vm_address_t address,
	vm_offset_t data,
	mach_msg_type_number_t dataCnt
)
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

#ifdef	__MIG_check__Reply__mach_vm_write_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_write_t__defined */

	__DeclareSendRpc(4806, "mach_vm_write")

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

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->data = dataTemplate;
	InP->data.address = (void *)(data);
	InP->data.size = dataCnt;
#else	/* UseStaticTemplates */
	InP->data.address = (void *)(data);
	InP->data.size = dataCnt;
	InP->data.deallocate =  FALSE;
	InP->data.copy = MACH_MSG_VIRTUAL_COPY;
	InP->data.type = MACH_MSG_OOL_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->address = address;

	InP->dataCnt = dataCnt;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4806;

	__BeforeSendRpc(4806, "mach_vm_write")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4806, "mach_vm_write")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_write_t__defined)
	check_result = __MIG_check__Reply__mach_vm_write_t((__Reply__mach_vm_write_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_write_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_copy_t__defined)
#define __MIG_check__Reply__mach_vm_copy_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_copy_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_copy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_copy_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_copy_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_copy_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_copy_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__mach_vm_copy_t(__Reply__mach_vm_copy_t *Out0P)
{

	typedef __Reply__mach_vm_copy_t __Reply;
	if (Out0P->Head.msgh_id != 4907) {
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

#if defined(__NDR_convert__int_rep__Reply__mach_vm_copy_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__mach_vm_copy_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__mach_vm_copy_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__mach_vm_copy_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_copy */
mig_external kern_return_t mach_vm_copy
(
	vm_map_t target_task,
	mach_vm_address_t source_address,
	mach_vm_size_t size,
	mach_vm_address_t dest_address
)
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

#ifdef	__MIG_check__Reply__mach_vm_copy_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_copy_t__defined */

	__DeclareSendRpc(4807, "mach_vm_copy")

	InP->NDR = NDR_record;

	InP->source_address = source_address;

	InP->size = size;

	InP->dest_address = dest_address;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4807;

	__BeforeSendRpc(4807, "mach_vm_copy")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4807, "mach_vm_copy")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_copy_t__defined)
	check_result = __MIG_check__Reply__mach_vm_copy_t((__Reply__mach_vm_copy_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_copy_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_read_overwrite_t__defined)
#define __MIG_check__Reply__mach_vm_read_overwrite_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize__defined */



#ifndef __NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize__defined */



#ifndef __NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize__defined */



mig_internal kern_return_t __MIG_check__Reply__mach_vm_read_overwrite_t(__Reply__mach_vm_read_overwrite_t *Out0P)
{

	typedef __Reply__mach_vm_read_overwrite_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 4908) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
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

#if	defined(__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize__defined)
		__NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize(&Out0P->outsize, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_read_overwrite_t__outsize__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize__defined)
		__NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize(&Out0P->outsize, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_read_overwrite_t__outsize__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize__defined)
		__NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize(&Out0P->outsize, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_read_overwrite_t__outsize__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_vm_read_overwrite_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_read_overwrite */
mig_external kern_return_t mach_vm_read_overwrite
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	mach_vm_address_t data,
	mach_vm_size_t *outsize
)
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
		mach_vm_size_t outsize;
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
		mach_vm_size_t outsize;
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

#ifdef	__MIG_check__Reply__mach_vm_read_overwrite_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_read_overwrite_t__defined */

	__DeclareSendRpc(4808, "mach_vm_read_overwrite")

	InP->NDR = NDR_record;

	InP->address = address;

	InP->size = size;

	InP->data = data;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4808;

	__BeforeSendRpc(4808, "mach_vm_read_overwrite")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4808, "mach_vm_read_overwrite")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_read_overwrite_t__defined)
	check_result = __MIG_check__Reply__mach_vm_read_overwrite_t((__Reply__mach_vm_read_overwrite_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_read_overwrite_t__defined) */

	*outsize = Out0P->outsize;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_msync_t__defined)
#define __MIG_check__Reply__mach_vm_msync_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_msync_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_msync_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_msync_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_msync_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_msync_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_msync_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__mach_vm_msync_t(__Reply__mach_vm_msync_t *Out0P)
{

	typedef __Reply__mach_vm_msync_t __Reply;
	if (Out0P->Head.msgh_id != 4909) {
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

#if defined(__NDR_convert__int_rep__Reply__mach_vm_msync_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__mach_vm_msync_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__mach_vm_msync_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__mach_vm_msync_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_msync */
mig_external kern_return_t mach_vm_msync
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	vm_sync_t sync_flags
)
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

#ifdef	__MIG_check__Reply__mach_vm_msync_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_msync_t__defined */

	__DeclareSendRpc(4809, "mach_vm_msync")

	InP->NDR = NDR_record;

	InP->address = address;

	InP->size = size;

	InP->sync_flags = sync_flags;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4809;

	__BeforeSendRpc(4809, "mach_vm_msync")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4809, "mach_vm_msync")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_msync_t__defined)
	check_result = __MIG_check__Reply__mach_vm_msync_t((__Reply__mach_vm_msync_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_msync_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_behavior_set_t__defined)
#define __MIG_check__Reply__mach_vm_behavior_set_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_behavior_set_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_behavior_set_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_behavior_set_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_behavior_set_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_behavior_set_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_behavior_set_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__mach_vm_behavior_set_t(__Reply__mach_vm_behavior_set_t *Out0P)
{

	typedef __Reply__mach_vm_behavior_set_t __Reply;
	if (Out0P->Head.msgh_id != 4910) {
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

#if defined(__NDR_convert__int_rep__Reply__mach_vm_behavior_set_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__mach_vm_behavior_set_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__mach_vm_behavior_set_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__mach_vm_behavior_set_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_behavior_set */
mig_external kern_return_t mach_vm_behavior_set
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	vm_behavior_t new_behavior
)
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

#ifdef	__MIG_check__Reply__mach_vm_behavior_set_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_behavior_set_t__defined */

	__DeclareSendRpc(4810, "mach_vm_behavior_set")

	InP->NDR = NDR_record;

	InP->address = address;

	InP->size = size;

	InP->new_behavior = new_behavior;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4810;

	__BeforeSendRpc(4810, "mach_vm_behavior_set")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4810, "mach_vm_behavior_set")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_behavior_set_t__defined)
	check_result = __MIG_check__Reply__mach_vm_behavior_set_t((__Reply__mach_vm_behavior_set_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_behavior_set_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_map_t__defined)
#define __MIG_check__Reply__mach_vm_map_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_map_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_map_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_map_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_map_t__address__defined */



#ifndef __NDR_convert__char_rep__Reply__mach_vm_map_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_map_t__address__defined */



#ifndef __NDR_convert__float_rep__Reply__mach_vm_map_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_map_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_map_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_map_t__address__defined */



mig_internal kern_return_t __MIG_check__Reply__mach_vm_map_t(__Reply__mach_vm_map_t *Out0P)
{

	typedef __Reply__mach_vm_map_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 4911) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
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

#if	defined(__NDR_convert__int_rep__Reply__mach_vm_map_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_map_t__address__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_vm_map_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__mach_vm_map_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_map_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_map_t__address__defined)
		__NDR_convert__int_rep__Reply__mach_vm_map_t__address(&Out0P->address, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_map_t__address__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_map_t__address__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__mach_vm_map_t__address__defined)
		__NDR_convert__char_rep__Reply__mach_vm_map_t__address(&Out0P->address, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_map_t__address__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_map_t__address__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__mach_vm_map_t__address__defined)
		__NDR_convert__float_rep__Reply__mach_vm_map_t__address(&Out0P->address, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_map_t__address__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_vm_map_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_map */
mig_external kern_return_t mach_vm_map
(
	vm_map_t target_task,
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
)
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
		mach_vm_address_t address;
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
		mach_vm_address_t address;
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

#ifdef	__MIG_check__Reply__mach_vm_map_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_map_t__defined */

	__DeclareSendRpc(4811, "mach_vm_map")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t objectTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->object = objectTemplate;
	InP->object.name = object;
#else	/* UseStaticTemplates */
	InP->object.name = object;
	InP->object.disposition = 19;
	InP->object.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->address = *address;

	InP->size = size;

	InP->mask = mask;

	InP->flags = flags;

	InP->offset = offset;

	InP->copy = copy;

	InP->cur_protection = cur_protection;

	InP->max_protection = max_protection;

	InP->inheritance = inheritance;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4811;

	__BeforeSendRpc(4811, "mach_vm_map")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4811, "mach_vm_map")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_map_t__defined)
	check_result = __MIG_check__Reply__mach_vm_map_t((__Reply__mach_vm_map_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_map_t__defined) */

	*address = Out0P->address;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_machine_attribute_t__defined)
#define __MIG_check__Reply__mach_vm_machine_attribute_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value__defined */



#ifndef __NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value__defined */



#ifndef __NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_machine_attribute_val_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__vm_machine_attribute_val_t((vm_machine_attribute_val_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value__defined */



mig_internal kern_return_t __MIG_check__Reply__mach_vm_machine_attribute_t(__Reply__mach_vm_machine_attribute_t *Out0P)
{

	typedef __Reply__mach_vm_machine_attribute_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 4912) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
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

#if	defined(__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value__defined)
		__NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value(&Out0P->value, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_machine_attribute_t__value__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value__defined)
		__NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value(&Out0P->value, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_machine_attribute_t__value__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value__defined)
		__NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value(&Out0P->value, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_machine_attribute_t__value__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_vm_machine_attribute_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_machine_attribute */
mig_external kern_return_t mach_vm_machine_attribute
(
	vm_map_t target_task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	vm_machine_attribute_t attribute,
	vm_machine_attribute_val_t *value
)
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
		vm_machine_attribute_val_t value;
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
		vm_machine_attribute_val_t value;
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

#ifdef	__MIG_check__Reply__mach_vm_machine_attribute_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_machine_attribute_t__defined */

	__DeclareSendRpc(4812, "mach_vm_machine_attribute")

	InP->NDR = NDR_record;

	InP->address = address;

	InP->size = size;

	InP->attribute = attribute;

	InP->value = *value;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4812;

	__BeforeSendRpc(4812, "mach_vm_machine_attribute")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4812, "mach_vm_machine_attribute")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_machine_attribute_t__defined)
	check_result = __MIG_check__Reply__mach_vm_machine_attribute_t((__Reply__mach_vm_machine_attribute_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_machine_attribute_t__defined) */

	*value = Out0P->value;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_remap_t__defined)
#define __MIG_check__Reply__mach_vm_remap_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_remap_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_remap_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__int_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__vm_prot_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__int_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection__defined */



#ifndef __NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address__defined */


#ifndef __NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__char_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection__defined */


#ifndef __NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__vm_prot_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__char_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection__defined */



#ifndef __NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address__defined */


#ifndef __NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__float_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection__defined */


#ifndef __NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__vm_prot_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__float_rep__vm_prot_t((vm_prot_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection__defined */



mig_internal kern_return_t __MIG_check__Reply__mach_vm_remap_t(__Reply__mach_vm_remap_t *Out0P)
{

	typedef __Reply__mach_vm_remap_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 4913) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
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

#if	defined(__NDR_convert__int_rep__Reply__mach_vm_remap_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_vm_remap_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__mach_vm_remap_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_remap_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address__defined)
		__NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address(&Out0P->target_address, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_remap_t__target_address__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection__defined)
		__NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection(&Out0P->cur_protection, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_remap_t__cur_protection__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection__defined)
		__NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection(&Out0P->max_protection, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_remap_t__max_protection__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address__defined) || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection__defined) || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address__defined)
		__NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address(&Out0P->target_address, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_remap_t__target_address__defined */
#if defined(__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection__defined)
		__NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection(&Out0P->cur_protection, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_remap_t__cur_protection__defined */
#if defined(__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection__defined)
		__NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection(&Out0P->max_protection, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_remap_t__max_protection__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address__defined) || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection__defined) || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address__defined)
		__NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address(&Out0P->target_address, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_remap_t__target_address__defined */
#if defined(__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection__defined)
		__NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection(&Out0P->cur_protection, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_remap_t__cur_protection__defined */
#if defined(__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection__defined)
		__NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection(&Out0P->max_protection, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_remap_t__max_protection__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_vm_remap_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_remap */
mig_external kern_return_t mach_vm_remap
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
)
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
		mach_vm_address_t target_address;
		vm_prot_t cur_protection;
		vm_prot_t max_protection;
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
		mach_vm_address_t target_address;
		vm_prot_t cur_protection;
		vm_prot_t max_protection;
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

#ifdef	__MIG_check__Reply__mach_vm_remap_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_remap_t__defined */

	__DeclareSendRpc(4813, "mach_vm_remap")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t src_taskTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->src_task = src_taskTemplate;
	InP->src_task.name = src_task;
#else	/* UseStaticTemplates */
	InP->src_task.name = src_task;
	InP->src_task.disposition = 19;
	InP->src_task.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->target_address = *target_address;

	InP->size = size;

	InP->mask = mask;

	InP->anywhere = anywhere;

	InP->src_address = src_address;

	InP->copy = copy;

	InP->inheritance = inheritance;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4813;

	__BeforeSendRpc(4813, "mach_vm_remap")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4813, "mach_vm_remap")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_remap_t__defined)
	check_result = __MIG_check__Reply__mach_vm_remap_t((__Reply__mach_vm_remap_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_remap_t__defined) */

	*target_address = Out0P->target_address;

	*cur_protection = Out0P->cur_protection;

	*max_protection = Out0P->max_protection;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_page_query_t__defined)
#define __MIG_check__Reply__mach_vm_page_query_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_page_query_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_page_query_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition__defined
#if	defined(__NDR_convert__int_rep__mach_vm__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__int_rep__mach_vm__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__int_rep__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count__defined
#if	defined(__NDR_convert__int_rep__mach_vm__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__int_rep__mach_vm__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__integer_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__int_rep__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count__defined */



#ifndef __NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition__defined
#if	defined(__NDR_convert__char_rep__mach_vm__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__char_rep__mach_vm__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__char_rep__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition__defined */


#ifndef __NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count__defined
#if	defined(__NDR_convert__char_rep__mach_vm__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__char_rep__mach_vm__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__integer_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__char_rep__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count__defined */



#ifndef __NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition__defined
#if	defined(__NDR_convert__float_rep__mach_vm__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__float_rep__mach_vm__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__float_rep__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition__defined */


#ifndef __NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count__defined
#if	defined(__NDR_convert__float_rep__mach_vm__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__float_rep__mach_vm__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__integer_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__float_rep__integer_t((integer_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count__defined */



mig_internal kern_return_t __MIG_check__Reply__mach_vm_page_query_t(__Reply__mach_vm_page_query_t *Out0P)
{

	typedef __Reply__mach_vm_page_query_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 4914) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
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

#if	defined(__NDR_convert__int_rep__Reply__mach_vm_page_query_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_vm_page_query_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__mach_vm_page_query_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_page_query_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition__defined)
		__NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition(&Out0P->disposition, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_page_query_t__disposition__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count__defined)
		__NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count(&Out0P->ref_count, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_page_query_t__ref_count__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition__defined) || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition__defined)
		__NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition(&Out0P->disposition, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_page_query_t__disposition__defined */
#if defined(__NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count__defined)
		__NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count(&Out0P->ref_count, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_page_query_t__ref_count__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition__defined) || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition__defined)
		__NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition(&Out0P->disposition, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_page_query_t__disposition__defined */
#if defined(__NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count__defined)
		__NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count(&Out0P->ref_count, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_page_query_t__ref_count__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_vm_page_query_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_page_query */
mig_external kern_return_t mach_vm_page_query
(
	vm_map_t target_map,
	mach_vm_offset_t offset,
	integer_t *disposition,
	integer_t *ref_count
)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_vm_offset_t offset;
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
		integer_t disposition;
		integer_t ref_count;
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
		integer_t disposition;
		integer_t ref_count;
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

#ifdef	__MIG_check__Reply__mach_vm_page_query_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_page_query_t__defined */

	__DeclareSendRpc(4814, "mach_vm_page_query")

	InP->NDR = NDR_record;

	InP->offset = offset;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_map;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4814;

	__BeforeSendRpc(4814, "mach_vm_page_query")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4814, "mach_vm_page_query")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_page_query_t__defined)
	check_result = __MIG_check__Reply__mach_vm_page_query_t((__Reply__mach_vm_page_query_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_page_query_t__defined) */

	*disposition = Out0P->disposition;

	*ref_count = Out0P->ref_count;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_region_recurse_t__defined)
#define __MIG_check__Reply__mach_vm_region_recurse_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#if	defined(__NDR_convert__int_rep__mach_vm__natural_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__int_rep__mach_vm__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__natural_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__int_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__int_rep__mach_vm__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__int_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_region_recurse_info_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__int_rep__mach_vm__vm_region_recurse_info_t((vm_region_recurse_info_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__vm_region_recurse_info_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__int_rep__vm_region_recurse_info_t((vm_region_recurse_info_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__mach_vm__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__mach_vm__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__infoCnt__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__infoCnt__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__infoCnt(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__infoCnt__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__infoCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__infoCnt__defined */



#ifndef __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address__defined */


#ifndef __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size__defined */


#ifndef __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#if	defined(__NDR_convert__char_rep__mach_vm__natural_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__char_rep__mach_vm__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__natural_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__char_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__char_rep__mach_vm__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__char_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined */


#ifndef __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_region_recurse_info_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__char_rep__mach_vm__vm_region_recurse_info_t((vm_region_recurse_info_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__vm_region_recurse_info_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__char_rep__vm_region_recurse_info_t((vm_region_recurse_info_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__mach_vm__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__mach_vm__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info__defined */




#ifndef __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address__defined */


#ifndef __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size__defined */


#ifndef __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#if	defined(__NDR_convert__float_rep__mach_vm__natural_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__float_rep__mach_vm__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__natural_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__float_rep__natural_t((natural_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__float_rep__mach_vm__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth(a, f) \
	__NDR_convert__float_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined */


#ifndef __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_region_recurse_info_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__float_rep__mach_vm__vm_region_recurse_info_t((vm_region_recurse_info_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__vm_region_recurse_info_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__float_rep__vm_region_recurse_info_t((vm_region_recurse_info_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__mach_vm__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__mach_vm__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info__defined */




mig_internal kern_return_t __MIG_check__Reply__mach_vm_region_recurse_t(__Reply__mach_vm_region_recurse_t *Out0P)
{

	typedef __Reply__mach_vm_region_recurse_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */

	if (Out0P->Head.msgh_id != 4915) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size > (mach_msg_size_t)sizeof(__Reply) || msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 76)) &&
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

#if defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__infoCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__infoCnt(&Out0P->infoCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__infoCnt__defined */
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Reply) - 76) + ((4 * Out0P->infoCnt)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__infoCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address__defined)
		__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address(&Out0P->address, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__address__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size__defined)
		__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size(&Out0P->size, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__size__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined)
		__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth(&Out0P->nesting_depth, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info__defined)
		__NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info(&Out0P->info, Out0P->NDR.int_rep, Out0P->infoCnt);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_recurse_t__info__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address__defined) || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size__defined) || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined) || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info__defined) || \
	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address__defined)
		__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address(&Out0P->address, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__address__defined */
#if defined(__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size__defined)
		__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size(&Out0P->size, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__size__defined */
#if defined(__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined)
		__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth(&Out0P->nesting_depth, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined */
#if defined(__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info__defined)
		__NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info(&Out0P->info, Out0P->NDR.char_rep, Out0P->infoCnt);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_recurse_t__info__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address__defined) || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size__defined) || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined) || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info__defined) || \
	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address__defined)
		__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address(&Out0P->address, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__address__defined */
#if defined(__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size__defined)
		__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size(&Out0P->size, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__size__defined */
#if defined(__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined)
		__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth(&Out0P->nesting_depth, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__nesting_depth__defined */
#if defined(__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info__defined)
		__NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info(&Out0P->info, Out0P->NDR.float_rep, Out0P->infoCnt);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_recurse_t__info__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_vm_region_recurse_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_region_recurse */
mig_external kern_return_t mach_vm_region_recurse
(
	vm_map_t target_task,
	mach_vm_address_t *address,
	mach_vm_size_t *size,
	natural_t *nesting_depth,
	vm_region_recurse_info_t info,
	mach_msg_type_number_t *infoCnt
)
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
		mach_vm_address_t address;
		mach_vm_size_t size;
		natural_t nesting_depth;
		mach_msg_type_number_t infoCnt;
		int info[19];
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
		mach_vm_address_t address;
		mach_vm_size_t size;
		natural_t nesting_depth;
		mach_msg_type_number_t infoCnt;
		int info[19];
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

#ifdef	__MIG_check__Reply__mach_vm_region_recurse_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_region_recurse_t__defined */

	__DeclareSendRpc(4815, "mach_vm_region_recurse")

	InP->NDR = NDR_record;

	InP->address = *address;

	InP->nesting_depth = *nesting_depth;

	if (*infoCnt < 19)
		InP->infoCnt = *infoCnt;
	else
		InP->infoCnt = 19;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4815;

	__BeforeSendRpc(4815, "mach_vm_region_recurse")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4815, "mach_vm_region_recurse")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_region_recurse_t__defined)
	check_result = __MIG_check__Reply__mach_vm_region_recurse_t((__Reply__mach_vm_region_recurse_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_region_recurse_t__defined) */

	*address = Out0P->address;

	*size = Out0P->size;

	*nesting_depth = Out0P->nesting_depth;

	if (Out0P->infoCnt > *infoCnt) {
		(void)memcpy((char *) info, (const char *) Out0P->info, 4 *  *infoCnt);
		*infoCnt = Out0P->infoCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) info, (const char *) Out0P->info, 4 * Out0P->infoCnt);

	*infoCnt = Out0P->infoCnt;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_region_t__defined)
#define __MIG_check__Reply__mach_vm_region_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_region_t__address__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_address_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_t__address__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_region_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm_size_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_t__size__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_region_t__info__defined
#if	defined(__NDR_convert__int_rep__mach_vm__vm_region_info_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__int_rep__mach_vm__vm_region_info_t((vm_region_info_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__vm_region_info_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__int_rep__vm_region_info_t((vm_region_info_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__mach_vm__int)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__int_rep__int)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__mach_vm__int32_t)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__int_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_t__info__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_region_t__infoCnt__defined
#if	defined(__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__infoCnt__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__infoCnt(a, f) \
	__NDR_convert__int_rep__mach_vm__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__infoCnt__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_region_t__infoCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_t__infoCnt__defined */


#ifndef __NDR_convert__char_rep__Reply__mach_vm_region_t__address__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_address_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_t__address__defined */


#ifndef __NDR_convert__char_rep__Reply__mach_vm_region_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm_size_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_t__size__defined */


#ifndef __NDR_convert__char_rep__Reply__mach_vm_region_t__info__defined
#if	defined(__NDR_convert__char_rep__mach_vm__vm_region_info_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__char_rep__mach_vm__vm_region_info_t((vm_region_info_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__vm_region_info_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__char_rep__vm_region_info_t((vm_region_info_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__mach_vm__int)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__char_rep__int)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__mach_vm__int32_t)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__char_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_t__info__defined */



#ifndef __NDR_convert__float_rep__Reply__mach_vm_region_t__address__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_address_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm_address_t((mach_vm_address_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__address__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__address(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_t__address__defined */


#ifndef __NDR_convert__float_rep__Reply__mach_vm_region_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm_size_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm_size_t((mach_vm_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__size__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_t__size__defined */


#ifndef __NDR_convert__float_rep__Reply__mach_vm_region_t__info__defined
#if	defined(__NDR_convert__float_rep__mach_vm__vm_region_info_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__float_rep__mach_vm__vm_region_info_t((vm_region_info_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__vm_region_info_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__float_rep__vm_region_info_t((vm_region_info_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__mach_vm__int)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int *)(a), f, c, __NDR_convert__float_rep__int)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__mach_vm__int32_t)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_region_t__info(a, f, c) \
	__NDR_convert__ARRAY((int32_t *)(a), f, c, __NDR_convert__float_rep__int32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_t__info__defined */




mig_internal kern_return_t __MIG_check__Reply__mach_vm_region_t(__Reply__mach_vm_region_t *Out0P)
{

	typedef __Reply__mach_vm_region_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */

	if (Out0P->Head.msgh_id != 4916) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size < (mach_msg_size_t)(sizeof(__Reply) - 40) || msgh_size > (mach_msg_size_t)sizeof(__Reply)) &&
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
	if (Out0P->object_name.type != MACH_MSG_PORT_DESCRIPTOR ||
	    Out0P->object_name.disposition != 17)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__mach_vm_region_t__infoCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__mach_vm_region_t__infoCnt(&Out0P->infoCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__mach_vm_region_t__infoCnt__defined */
#if	__MigTypeCheck
	if (msgh_size != (mach_msg_size_t)(sizeof(__Reply) - 40) + ((4 * Out0P->infoCnt)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__mach_vm_region_t__address__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_region_t__size__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_region_t__info__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_region_t__infoCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_vm_region_t__address__defined)
		__NDR_convert__int_rep__Reply__mach_vm_region_t__address(&Out0P->address, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_t__address__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_region_t__size__defined)
		__NDR_convert__int_rep__Reply__mach_vm_region_t__size(&Out0P->size, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_t__size__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_region_t__info__defined)
		__NDR_convert__int_rep__Reply__mach_vm_region_t__info(&Out0P->info, Out0P->NDR.int_rep, Out0P->infoCnt);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_region_t__info__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Reply__mach_vm_region_t__address__defined) || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_region_t__size__defined) || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_region_t__info__defined) || \
	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__mach_vm_region_t__address__defined)
		__NDR_convert__char_rep__Reply__mach_vm_region_t__address(&Out0P->address, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_t__address__defined */
#if defined(__NDR_convert__char_rep__Reply__mach_vm_region_t__size__defined)
		__NDR_convert__char_rep__Reply__mach_vm_region_t__size(&Out0P->size, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_t__size__defined */
#if defined(__NDR_convert__char_rep__Reply__mach_vm_region_t__info__defined)
		__NDR_convert__char_rep__Reply__mach_vm_region_t__info(&Out0P->info, Out0P->NDR.char_rep, Out0P->infoCnt);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_region_t__info__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Reply__mach_vm_region_t__address__defined) || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_region_t__size__defined) || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_region_t__info__defined) || \
	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__mach_vm_region_t__address__defined)
		__NDR_convert__float_rep__Reply__mach_vm_region_t__address(&Out0P->address, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_t__address__defined */
#if defined(__NDR_convert__float_rep__Reply__mach_vm_region_t__size__defined)
		__NDR_convert__float_rep__Reply__mach_vm_region_t__size(&Out0P->size, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_t__size__defined */
#if defined(__NDR_convert__float_rep__Reply__mach_vm_region_t__info__defined)
		__NDR_convert__float_rep__Reply__mach_vm_region_t__info(&Out0P->info, Out0P->NDR.float_rep, Out0P->infoCnt);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_region_t__info__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_vm_region_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_region */
mig_external kern_return_t mach_vm_region
(
	vm_map_t target_task,
	mach_vm_address_t *address,
	mach_vm_size_t *size,
	vm_region_flavor_t flavor,
	vm_region_info_t info,
	mach_msg_type_number_t *infoCnt,
	mach_port_t *object_name
)
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
		mach_msg_port_descriptor_t object_name;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		mach_msg_type_number_t infoCnt;
		int info[10];
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
		mach_msg_port_descriptor_t object_name;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		mach_msg_type_number_t infoCnt;
		int info[10];
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

#ifdef	__MIG_check__Reply__mach_vm_region_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_region_t__defined */

	__DeclareSendRpc(4816, "mach_vm_region")

	InP->NDR = NDR_record;

	InP->address = *address;

	InP->flavor = flavor;

	if (*infoCnt < 10)
		InP->infoCnt = *infoCnt;
	else
		InP->infoCnt = 10;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4816;

	__BeforeSendRpc(4816, "mach_vm_region")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4816, "mach_vm_region")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_region_t__defined)
	check_result = __MIG_check__Reply__mach_vm_region_t((__Reply__mach_vm_region_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_region_t__defined) */

	*address = Out0P->address;

	*size = Out0P->size;

	if (Out0P->infoCnt > *infoCnt) {
		(void)memcpy((char *) info, (const char *) Out0P->info, 4 *  *infoCnt);
		*infoCnt = Out0P->infoCnt;
		{ return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) info, (const char *) Out0P->info, 4 * Out0P->infoCnt);

	*infoCnt = Out0P->infoCnt;

	*object_name = Out0P->object_name.name;
	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply___mach_make_memory_entry_t__defined)
#define __MIG_check__Reply___mach_make_memory_entry_t__defined
#ifndef __NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size__defined
#if	defined(__NDR_convert__int_rep__mach_vm__memory_object_size_t__defined)
#define	__NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__memory_object_size_t__defined)
#define	__NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__int_rep__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__int_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint64_t__defined)
#define	__NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__int_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size__defined */


#ifndef __NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size__defined
#if	defined(__NDR_convert__char_rep__mach_vm__memory_object_size_t__defined)
#define	__NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__memory_object_size_t__defined)
#define	__NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__char_rep__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__char_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint64_t__defined)
#define	__NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__char_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size__defined */


#ifndef __NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size__defined
#if	defined(__NDR_convert__float_rep__mach_vm__memory_object_size_t__defined)
#define	__NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__memory_object_size_t__defined)
#define	__NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__float_rep__memory_object_size_t((memory_object_size_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__float_rep__mach_vm__uint64_t((uint64_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint64_t__defined)
#define	__NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size__defined
#define	__NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size(a, f) \
	__NDR_convert__float_rep__uint64_t((uint64_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size__defined */



mig_internal kern_return_t __MIG_check__Reply___mach_make_memory_entry_t(__Reply___mach_make_memory_entry_t *Out0P)
{

	typedef __Reply___mach_make_memory_entry_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 4917) {
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
	if (Out0P->object_handle.type != MACH_MSG_PORT_DESCRIPTOR ||
	    Out0P->object_handle.disposition != 17)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size__defined)
		__NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size(&Out0P->size, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply___mach_make_memory_entry_t__size__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size__defined)
		__NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size(&Out0P->size, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply___mach_make_memory_entry_t__size__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size__defined)
		__NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size(&Out0P->size, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply___mach_make_memory_entry_t__size__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply___mach_make_memory_entry_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine _mach_make_memory_entry */
mig_external kern_return_t _mach_make_memory_entry
(
	vm_map_t target_task,
	memory_object_size_t *size,
	memory_object_offset_t offset,
	vm_prot_t permission,
	mem_entry_name_port_t *object_handle,
	mem_entry_name_port_t parent_handle
)
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
		mach_msg_port_descriptor_t object_handle;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		memory_object_size_t size;
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
		mach_msg_port_descriptor_t object_handle;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		memory_object_size_t size;
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

#ifdef	__MIG_check__Reply___mach_make_memory_entry_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply___mach_make_memory_entry_t__defined */

	__DeclareSendRpc(4817, "_mach_make_memory_entry")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t parent_handleTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		19,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->parent_handle = parent_handleTemplate;
	InP->parent_handle.name = parent_handle;
#else	/* UseStaticTemplates */
	InP->parent_handle.name = parent_handle;
	InP->parent_handle.disposition = 19;
	InP->parent_handle.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->size = *size;

	InP->offset = offset;

	InP->permission = permission;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4817;

	__BeforeSendRpc(4817, "_mach_make_memory_entry")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4817, "_mach_make_memory_entry")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply___mach_make_memory_entry_t__defined)
	check_result = __MIG_check__Reply___mach_make_memory_entry_t((__Reply___mach_make_memory_entry_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply___mach_make_memory_entry_t__defined) */

	*size = Out0P->size;

	*object_handle = Out0P->object_handle.name;
	return KERN_SUCCESS;
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__mach_vm_subsystem__
#if !defined(__MIG_check__Reply__mach_vm_purgable_control_t__defined)
#define __MIG_check__Reply__mach_vm_purgable_control_t__defined
#ifndef __NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__mach_vm__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__RetCode(a, f) \
	__NDR_convert__int_rep__mach_vm__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state__defined
#if	defined(__NDR_convert__int_rep__mach_vm__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__int_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__int_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state__defined */



#ifndef __NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state__defined
#if	defined(__NDR_convert__char_rep__mach_vm__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__char_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__char_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state__defined */



#ifndef __NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state__defined
#if	defined(__NDR_convert__float_rep__mach_vm__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__float_rep__mach_vm__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__mach_vm__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__float_rep__mach_vm__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state__defined
#define	__NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state__defined */



mig_internal kern_return_t __MIG_check__Reply__mach_vm_purgable_control_t(__Reply__mach_vm_purgable_control_t *Out0P)
{

	typedef __Reply__mach_vm_purgable_control_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 4918) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
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

#if	defined(__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state__defined)
		__NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state(&Out0P->state, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__mach_vm_purgable_control_t__state__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state__defined)
		__NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state(&Out0P->state, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__mach_vm_purgable_control_t__state__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state__defined)
		__NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state(&Out0P->state, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__mach_vm_purgable_control_t__state__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__mach_vm_purgable_control_t__defined) */
#endif /* __MIG_check__Reply__mach_vm_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine mach_vm_purgable_control */
mig_external kern_return_t mach_vm_purgable_control
(
	vm_map_t target_task,
	mach_vm_address_t address,
	vm_purgable_t control,
	int *state
)
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
		int state;
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
		int state;
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

#ifdef	__MIG_check__Reply__mach_vm_purgable_control_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__mach_vm_purgable_control_t__defined */

	__DeclareSendRpc(4818, "mach_vm_purgable_control")

	InP->NDR = NDR_record;

	InP->address = address;

	InP->control = control;

	InP->state = *state;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = target_task;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 4818;

	__BeforeSendRpc(4818, "mach_vm_purgable_control")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(4818, "mach_vm_purgable_control")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__mach_vm_purgable_control_t__defined)
	check_result = __MIG_check__Reply__mach_vm_purgable_control_t((__Reply__mach_vm_purgable_control_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__mach_vm_purgable_control_t__defined) */

	*state = Out0P->state;

	return KERN_SUCCESS;
}
