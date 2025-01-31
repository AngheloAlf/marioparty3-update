#ifndef _TYPES_H_
#define _TYPES_H_

#define NULL 0

/// Linker symbol address, as in `ld_addrs.h`.
typedef u8 Addr[];
typedef f32 HuMtx4F[4][4];

#define va_arg(AP,TYPE) (AP = (__gnuc_va_list) ((char *) (AP) + __va_rounded_size (TYPE)), *((TYPE *) (void *) ((char *) (AP) - ((sizeof (TYPE) < __va_rounded_size (char) ? sizeof (TYPE) : __va_rounded_size (TYPE))))))

#endif