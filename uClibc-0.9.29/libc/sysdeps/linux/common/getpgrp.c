/* vi: set sw=4 ts=4: */
/*
 * getpgrp() for uClibc
 *
 * Copyright (C) 2000-2006 by Erik Andersen <andersen@codepoet.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#include <sys/syscall.h>
#include <unistd.h>

#ifdef __NR_getpgrp
_syscall0(pid_t, getpgrp);
#endif
