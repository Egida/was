#ifndef __HANDLER_H
#define __HANDLER_H

#include <ntddk.h>

BOOLEAN handler(PEXCEPTION_RECORD ExceptionRecord, PCONTEXT Context);

typedef NTSTATUS (NTAPI *NtQueryDirectoryFileEx_t)(
	HANDLE FileHandle,
	HANDLE Event,
	PIO_APC_ROUTINE ApcRoutine,
	PVOID ApcContext,
	PIO_STATUS_BLOCK IoStatusBlock,
	PVOID FileInformation,
	ULONG Length,
	FILE_INFORMATION_CLASS FileInformationClass,
	ULONG QueryFlags,  // Valid flags are in SL_QUERY_DIRECTORY_MASK
	PUNICODE_STRING FileName
);

extern NtQueryDirectoryFileEx_t origNtQueryDirectoryFileEx;

#endif //__HANDLER_H