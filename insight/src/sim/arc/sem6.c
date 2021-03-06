/* Simulator instruction semantics for arc600f.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright 1996-2005 Free Software Foundation, Inc.

This file is part of the GNU simulators.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.

*/

#define WANT_CPU arc600f
#define WANT_CPU_ARC600F

#include "sim-main.h"
#include "cgen-mem.h"
#include "cgen-ops.h"

#undef GET_ATTR
#if defined (__STDC__) || defined (ALMOST_STDC) || defined (HAVE_STRINGIZE)
#define GET_ATTR(cpu, num, attr) CGEN_ATTR_VALUE (NULL, abuf->idesc->attrs, CGEN_INSN_##attr)
#else
#define GET_ATTR(cpu, num, attr) CGEN_ATTR_VALUE (NULL, abuf->idesc->attrs, CGEN_INSN_/**/attr)
#endif

/* This is used so that we can compile two copies of the semantic code,
   one with full feature support and one without that runs fast(er).
   FAST_P, when desired, is defined on the command line, -DFAST_P=1.  */
#if FAST_P
#define SEM_FN_NAME(cpu,fn) XCONCAT3 (cpu,_semf_,fn)
#undef TRACE_RESULT
#define TRACE_RESULT(cpu, abuf, name, type, val)
#else
#define SEM_FN_NAME(cpu,fn) XCONCAT3 (cpu,_sem_,fn)
#endif

/* x-invalid: --invalid-- */

static SEM_PC
SEM_FN_NAME (arc600f,x_invalid) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
    /* Update the recorded pc in the cpu state struct.
       Only necessary for WITH_SCACHE case, but to avoid the
       conditional compilation ....  */
    SET_H_PC (pc);
    /* Virtual insns have zero size.  Overwrite vpc with address of next insn
       using the default-insn-bitsize spec.  When executing insns in parallel
       we may want to queue the fault and continue execution.  */
    vpc = SEM_NEXT_VPC (sem_arg, pc, 4);
    vpc = sim_engine_invalid_insn (current_cpu, pc, vpc);
  }

  return vpc;
#undef FLD
}

/* x-after: --after-- */

static SEM_PC
SEM_FN_NAME (arc600f,x_after) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
#if WITH_SCACHE_PBB_ARC600F
    arc600f_pbb_after (current_cpu, sem_arg);
#endif
  }

  return vpc;
#undef FLD
}

/* x-before: --before-- */

static SEM_PC
SEM_FN_NAME (arc600f,x_before) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
#if WITH_SCACHE_PBB_ARC600F
    arc600f_pbb_before (current_cpu, sem_arg);
#endif
  }

  return vpc;
#undef FLD
}

/* x-cti-chain: --cti-chain-- */

static SEM_PC
SEM_FN_NAME (arc600f,x_cti_chain) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
#if WITH_SCACHE_PBB_ARC600F
#ifdef DEFINE_SWITCH
    vpc = arc600f_pbb_cti_chain (current_cpu, sem_arg,
			       pbb_br_type, pbb_br_npc);
    BREAK (sem);
#else
    /* FIXME: Allow provision of explicit ifmt spec in insn spec.  */
    vpc = arc600f_pbb_cti_chain (current_cpu, sem_arg,
			       CPU_PBB_BR_TYPE (current_cpu),
			       CPU_PBB_BR_NPC (current_cpu));
#endif
#endif
  }

  return vpc;
#undef FLD
}

/* x-chain: --chain-- */

static SEM_PC
SEM_FN_NAME (arc600f,x_chain) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
#if WITH_SCACHE_PBB_ARC600F
    vpc = arc600f_pbb_chain (current_cpu, sem_arg);
#ifdef DEFINE_SWITCH
    BREAK (sem);
#endif
#endif
  }

  return vpc;
#undef FLD
}

/* x-begin: --begin-- */

static SEM_PC
SEM_FN_NAME (arc600f,x_begin) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
#if WITH_SCACHE_PBB_ARC600F
#if defined DEFINE_SWITCH || defined FAST_P
    /* In the switch case FAST_P is a constant, allowing several optimizations
       in any called inline functions.  */
    vpc = arc600f_pbb_begin (current_cpu, FAST_P);
#else
#if 0 /* cgen engine can't handle dynamic fast/full switching yet.  */
    vpc = arc600f_pbb_begin (current_cpu, STATE_RUN_FAST_P (CPU_STATE (current_cpu)));
#else
    vpc = arc600f_pbb_begin (current_cpu, 0);
#endif
#endif
#endif
  }

  return vpc;
#undef FLD
}

/* b_s: b$i2cond $label10 */

static SEM_PC
SEM_FN_NAME (arc600f,b_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_b_s.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (GET_H_I2COND (FLD (f_cond_i2))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
  {
    USI opval = FLD (i_label10);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else if (0) {
  {
    USI opval = FLD (i_label10);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
  {
    USI opval = FLD (i_label10);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* bcc_s: b$i3cond$_S $label7 */

static SEM_PC
SEM_FN_NAME (arc600f,bcc_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_bcc_s.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (GET_H_I3COND (FLD (f_cond_i3))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
  {
    USI opval = FLD (i_label7);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else if (0) {
  {
    USI opval = FLD (i_label7);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
  {
    USI opval = FLD (i_label7);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* brcc_s: br$RccS$_S $R_b,0,$label8 */

static SEM_PC
SEM_FN_NAME (arc600f,brcc_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_brcc_s.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if ((FLD (f_brscond) == 0) ? (EQSI (GET_H_CR16 (FLD (f_op__b)), 0)) : (FLD (f_brscond) == 1) ? (NESI (GET_H_CR16 (FLD (f_op__b)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
  {
    USI opval = FLD (i_label8);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else if (0) {
  {
    USI opval = FLD (i_label8);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
  {
    USI opval = FLD (i_label8);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* bcc_l: b$Qcondb$_L $label21 */

static SEM_PC
SEM_FN_NAME (arc600f,bcc_l) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_bcc_l.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
((void) 0); /*nop*/
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
  {
    USI opval = FLD (i_label21);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else if (0) {
  {
    USI opval = FLD (i_label21);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
  {
    USI opval = FLD (i_label21);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* bcc_l.d: b$Qcondb$_L.d $label21 */

static SEM_PC
SEM_FN_NAME (arc600f,bcc_l_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_bcc_l.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
((void) 0); /*nop*/
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  {
    USI opval = FLD (i_label21);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else if (1) {
{
  {
    USI opval = FLD (i_label21);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  {
    USI opval = FLD (i_label21);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* b_l: b$uncondb$_L $label25 */

static SEM_PC
SEM_FN_NAME (arc600f,b_l) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_b_l.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
  {
    USI opval = FLD (i_label25);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else if (0) {
  {
    USI opval = FLD (i_label25);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
  {
    USI opval = FLD (i_label25);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* b_l.d: b$uncondb$_L.d $label25 */

static SEM_PC
SEM_FN_NAME (arc600f,b_l_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_b_l.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  {
    USI opval = FLD (i_label25);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else if (1) {
{
  {
    USI opval = FLD (i_label25);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  {
    USI opval = FLD (i_label25);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* brcc_RC: b$Rcc $RB,$RC,$label9 */

static SEM_PC
SEM_FN_NAME (arc600f,brcc_RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_brcc_RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = GET_H_CR (FLD (f_op_C));
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = GET_H_CR (FLD (f_op_C));
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = GET_H_CR (FLD (f_op_C));
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* brcc_RC.d: b$Rcc.d $RB,$RC,$label9 */

static SEM_PC
SEM_FN_NAME (arc600f,brcc_RC_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_brcc_RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = GET_H_CR (FLD (f_op_C));
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
{
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
 else if (1) {
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = GET_H_CR (FLD (f_op_C));
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
{
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = GET_H_CR (FLD (f_op_C));
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
{
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* brcc_U6: b$Rcc $RB,$U6,$label9 */

static SEM_PC
SEM_FN_NAME (arc600f,brcc_U6) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_brcc_U6.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
((void) 0); /*nop*/
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_u6);
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
((void) 0); /*nop*/
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_u6);
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
((void) 0); /*nop*/
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_u6);
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* brcc_U6.d: b$Rcc.d $RB,$U6,$label9 */

static SEM_PC
SEM_FN_NAME (arc600f,brcc_U6_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_brcc_U6.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
((void) 0); /*nop*/
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_u6);
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
{
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
 else if (1) {
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
((void) 0); /*nop*/
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_u6);
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
{
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_condition;
  SI tmp_B;
  SI tmp_C;
  tmp_condition = FLD (f_brcond);
((void) 0); /*nop*/
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_u6);
if ((tmp_condition == CONDBR_REQ) ? (EQSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RNE) ? (NESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLT) ? (LTSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RGE) ? (GESI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RLO) ? (LTUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_RHS) ? (GEUSI (tmp_B, tmp_C)) : (tmp_condition == CONDBR_BIT0) ? (EQSI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : (tmp_condition == CONDBR_BIT1) ? (NESI (ANDSI (tmp_B, SLLSI (1, tmp_C)), 0)) : ((cgen_rtx_error (current_cpu, "unreachable - put in because of parser error"), 0))) {
{
  {
    USI opval = FLD (i_label9);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* bl_s: bl$uncondj$_S $label13a */

static SEM_PC
SEM_FN_NAME (arc600f,bl_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_bl_s.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  {
    SI opval = ADDSI (pc, 2);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    USI opval = FLD (i_label13a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else if (0) {
{
  {
    SI opval = ADDSI (pc, 2);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    USI opval = FLD (i_label13a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  {
    SI opval = ADDSI (pc, 2);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    USI opval = FLD (i_label13a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* blcc: bl$Qcondj$_L $label21 */

static SEM_PC
SEM_FN_NAME (arc600f,blcc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_blcc.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
((void) 0); /*nop*/
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    USI opval = FLD (i_label21a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else if (0) {
{
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    USI opval = FLD (i_label21a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    USI opval = FLD (i_label21a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* blcc.d: bl$Qcondj$_L.d $label21 */

static SEM_PC
SEM_FN_NAME (arc600f,blcc_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_blcc.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
((void) 0); /*nop*/
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
{
  {
    USI opval = FLD (i_label21a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (1) {
{
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
{
  {
    USI opval = FLD (i_label21a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
{
  {
    USI opval = FLD (i_label21a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* bl: bl$uncondj$_L $label25a */

static SEM_PC
SEM_FN_NAME (arc600f,bl) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_bl.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    USI opval = FLD (i_label25a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else if (0) {
{
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    USI opval = FLD (i_label25a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    USI opval = FLD (i_label25a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* bl.d: bl$uncondj$_L.d $label25a */

static SEM_PC
SEM_FN_NAME (arc600f,bl_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_bl.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (i_label25a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (1) {
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (i_label25a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (i_label25a);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* ld_abs: ld$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ld_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ld$_AW_abs: ld$_AW$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ld__AW_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ld.ab_abs: ld.ab$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ld_ab_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ld.as_abs: ld.as$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ld_as_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_s9), 2));
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ld_abc: ld$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ld_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ld$_AW_abc: ld$_AW$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ld__AW_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ld.ab_abc: ld.ab$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ld_ab_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ld.as_abc: ld.as$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ld_as_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 2));
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ld_s_abc: ld$_S $R_a,[$R_b,$R_c] */

static SEM_PC
SEM_FN_NAME (arc600f,ld_s_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abc.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR16 (FLD (f_op__b)), GET_H_CR16 (FLD (f_op__c)));
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR16 (FLD (f_op__a), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ld_s_abu: ld$_S $R_c,[$R_b,$sc_u5_] */

static SEM_PC
SEM_FN_NAME (arc600f,ld_s_abu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR16 (FLD (f_op__b)), FLD (f_u5x4));
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR16 (FLD (f_op__c), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ld_s_absp: ld$_S $R_b,[$SP,$u5x4] */

static SEM_PC
SEM_FN_NAME (arc600f,ld_s_absp) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_SP (), FLD (f_u5x4));
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ld_s_gprel: ld$_S $R_b,[$GP,$sc_s9_] */

static SEM_PC
SEM_FN_NAME (arc600f,ld_s_gprel) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_gprel.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_GP (), FLD (f_s9x4));
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_R0 (, opval);
    TRACE_RESULT (current_cpu, abuf, "r0", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ld_s_pcrel: ld$_S $R_b,[$PCL,$u8x4] */

static SEM_PC
SEM_FN_NAME (arc600f,ld_s_pcrel) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_pcrel.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (ANDSI (pc, -4), FLD (f_u8x4));
  {
    SI opval = GETMEMSI (current_cpu, pc, tmp_eaddr);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ldb_abs: ldb$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb$_AW_abs: ldb$_AW$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb__AW_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb.ab_abs: ldb.ab$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_ab_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb.as_abs: ldb.as$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_as_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), (cgen_rtx_error (current_cpu, "invalid insn"), 0));
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb_abc: ldb$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb$_AW_abc: ldb$_AW$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb__AW_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb.ab_abc: ldb.ab$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_ab_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb.as_abc: ldb.as$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_as_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), (cgen_rtx_error (current_cpu, "invalid insn"), 0));
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb_s_abc: ldb$_S $R_a,[$R_b,$R_c] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_s_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abc.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR16 (FLD (f_op__b)), GET_H_CR16 (FLD (f_op__c)));
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR16 (FLD (f_op__a), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ldb_s_abu: ldb$_S $R_c,[$R_b,$sc_u5b] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_s_abu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldb_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR16 (FLD (f_op__b)), FLD (f_u5));
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR16 (FLD (f_op__c), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ldb_s_absp: ldb$_S $R_b,[$SP,$u5x4] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_s_absp) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_SP (), FLD (f_u5x4));
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ldb_s_gprel: ldb$_S $R_b,[$GP,$sc_s9b] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_s_gprel) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldb_s_gprel.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_GP (), FLD (f_s9x1));
  {
    SI opval = ZEXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_R0 (, opval);
    TRACE_RESULT (current_cpu, abuf, "r0", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ldb.x_abs: ldb.x$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_x_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = EXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb$_AW.x_abs: ldb$_AW.x$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb__AW_x_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = EXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb.ab.x_abs: ldb.ab.x$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_ab_x_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    SI opval = EXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb.as.x_abs: ldb.as.x$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_as_x_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), (cgen_rtx_error (current_cpu, "invalid insn"), 0));
  {
    SI opval = EXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb.x_abc: ldb.x$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_x_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  {
    SI opval = EXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb$_AW.x_abc: ldb$_AW.x$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb__AW_x_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = EXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb.ab.x_abc: ldb.ab.x$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_ab_x_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    SI opval = EXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldb.as.x_abc: ldb.as.x$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldb_as_x_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), (cgen_rtx_error (current_cpu, "invalid insn"), 0));
  {
    SI opval = EXTQISI (GETMEMQI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw_abs: ldw$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = ZEXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw$_AW_abs: ldw$_AW$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw__AW_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = ZEXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw.ab_abs: ldw.ab$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_ab_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    SI opval = ZEXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw.as_abs: ldw.as$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_as_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_s9), 1));
  {
    SI opval = ZEXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw_abc: ldw$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  {
    SI opval = ZEXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw$_AW_abc: ldw$_AW$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw__AW_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = ZEXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw.ab_abc: ldw.ab$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_ab_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    SI opval = ZEXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw.as_abc: ldw.as$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_as_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 1));
  {
    SI opval = ZEXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw_s_abc: ldw$_S $R_a,[$R_b,$R_c] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_s_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abc.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR16 (FLD (f_op__b)), GET_H_CR16 (FLD (f_op__c)));
  {
    SI opval = ZEXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR16 (FLD (f_op__a), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ldw_s_abu: ldw$_S $R_c,[$R_b,$sc_u5w] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_s_abu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldw_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR16 (FLD (f_op__b)), FLD (f_u5x2));
  {
    SI opval = ZEXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR16 (FLD (f_op__c), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ldw_s_gprel: ldw$_S $R_b,[$GP,$sc_s9w] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_s_gprel) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldw_s_gprel.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_GP (), FLD (f_s9x2));
  {
    SI opval = ZEXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_R0 (, opval);
    TRACE_RESULT (current_cpu, abuf, "r0", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ldw.x_abs: ldw.x$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_x_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = EXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw$_AW.x_abs: ldw$_AW.x$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw__AW_x_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = EXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw.ab.x_abs: ldw.ab.x$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_ab_x_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    SI opval = EXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw.as.x_abs: ldw.as.x$LDODi $RA,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_as_x_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_s9), 1));
  {
    SI opval = EXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw.x_abc: ldw.x$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_x_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  {
    SI opval = EXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw$_AW.x_abc: ldw$_AW.x$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw__AW_x_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = EXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw.ab.x_abc: ldw.ab.x$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_ab_x_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    SI opval = EXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw.as.x_abc: ldw.as.x$LDRDi $RA,[$RB,$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_as_x_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 1));
  {
    SI opval = EXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* ldw_s.x_abu: ldw$_S.x $R_c,[$R_b,$sc_u5w] */

static SEM_PC
SEM_FN_NAME (arc600f,ldw_s_x_abu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldw_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR16 (FLD (f_op__b)), FLD (f_u5x2));
  {
    SI opval = EXTHISI (GETMEMHI (current_cpu, pc, tmp_eaddr));
    SET_H_CR16 (FLD (f_op__c), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* st_abs: st$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,st_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = GET_H_CR (FLD (f_op_C));
    SETMEMSI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* st$_AW_abs: st$_AW$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,st__AW_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_CR (FLD (f_op_C));
    SETMEMSI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* st.ab_abs: st.ab$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,st_ab_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    SI opval = GET_H_CR (FLD (f_op_C));
    SETMEMSI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* st.as_abs: st.as$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,st_as_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_s9), 2));
  {
    SI opval = GET_H_CR (FLD (f_op_C));
    SETMEMSI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* st_s_abu: st$_S $R_c,[$R_b,$sc_u5_] */

static SEM_PC
SEM_FN_NAME (arc600f,st_s_abu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR16 (FLD (f_op__b)), FLD (f_u5x4));
  {
    SI opval = GET_H_CR16 (FLD (f_op__c));
    SETMEMSI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* st_s_absp: st$_S $R_b,[$SP,$u5x4] */

static SEM_PC
SEM_FN_NAME (arc600f,st_s_absp) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_SP (), FLD (f_u5x4));
  {
    SI opval = GET_H_CR16 (FLD (f_op__b));
    SETMEMSI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* stb_abs: stb$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,stb_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    QI opval = GET_H_CR (FLD (f_op_C));
    SETMEMQI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* stb$_AW_abs: stb$_AW$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,stb__AW_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    QI opval = GET_H_CR (FLD (f_op_C));
    SETMEMQI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* stb.ab_abs: stb.ab$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,stb_ab_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    QI opval = GET_H_CR (FLD (f_op_C));
    SETMEMQI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* stb.as_abs: stb.as$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,stb_as_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), (cgen_rtx_error (current_cpu, "invalid insn"), 0));
  {
    QI opval = GET_H_CR (FLD (f_op_C));
    SETMEMQI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* stb_s_abu: stb$_S $R_c,[$R_b,$sc_u5b] */

static SEM_PC
SEM_FN_NAME (arc600f,stb_s_abu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldb_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR16 (FLD (f_op__b)), FLD (f_u5));
  {
    QI opval = GET_H_CR16 (FLD (f_op__c));
    SETMEMQI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* stb_s_absp: stb$_S $R_b,[$SP,$u5x4] */

static SEM_PC
SEM_FN_NAME (arc600f,stb_s_absp) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_SP (), FLD (f_u5x4));
  {
    QI opval = GET_H_CR16 (FLD (f_op__b));
    SETMEMQI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* stw_abs: stw$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,stw_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    HI opval = GET_H_CR (FLD (f_op_C));
    SETMEMHI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* stw$_AW_abs: stw$_AW$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,stw__AW_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  {
    SI opval = tmp_eaddr;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    HI opval = GET_H_CR (FLD (f_op_C));
    SETMEMHI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* stw.ab_abs: stw.ab$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,stw_ab_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_sum;
  SI tmp_eaddr;
  tmp_sum = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s9));
  tmp_eaddr = GET_H_CR (FLD (f_op_B));
  {
    HI opval = GET_H_CR (FLD (f_op_C));
    SETMEMHI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
  {
    SI opval = tmp_sum;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* stw.as_abs: stw.as$STODi $RC,[$RB,$s9] */

static SEM_PC
SEM_FN_NAME (arc600f,stw_as_abs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_s9), 1));
  {
    HI opval = GET_H_CR (FLD (f_op_C));
    SETMEMHI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* stw_s_abu: stw$_S $R_c,[$R_b,$sc_u5w] */

static SEM_PC
SEM_FN_NAME (arc600f,stw_s_abu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldw_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_eaddr;
  tmp_eaddr = ADDSI (GET_H_CR16 (FLD (f_op__b)), FLD (f_u5x2));
  {
    HI opval = GET_H_CR16 (FLD (f_op__c));
    SETMEMHI (current_cpu, pc, tmp_eaddr, opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* add_L_s12 $RA,: add$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,add_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add_ccu6 $RA,: add$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,add_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add_L_u6 $RA,: add$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,add_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add_L_r_r $RA,$RC: add$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,add_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add_cc $RA,$RC: add$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,add_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add_s_abc: add$_S $R_a,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,add_s_abc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abc.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = ADDSI (tmp_B, tmp_C);
    SET_H_CR16 (FLD (f_op__a), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* add_s_cbu3: add$_S $R_c,$R_b,$u3 */

static SEM_PC
SEM_FN_NAME (arc600f,add_s_cbu3) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u3);
  {
    SI opval = ADDSI (tmp_B, tmp_C);
    SET_H_CR16 (FLD (f_op__c), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* add_s_mcah: add$_S $R_b,$R_b,$Rh */

static SEM_PC
SEM_FN_NAME (arc600f,add_s_mcah) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_mcah.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
{
if (EQSI (FLD (f_op_h), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 2));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (2, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_h), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR (FLD (f_op_h));
  {
    SI opval = ADDSI (tmp_B, tmp_C);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* add_s_absp: add$_S $R_b,$SP,$u5x4 */

static SEM_PC
SEM_FN_NAME (arc600f,add_s_absp) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_SP ();
  tmp_C = FLD (f_u5x4);
  {
    SI opval = ADDSI (tmp_B, tmp_C);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* add_s_asspsp: add$_S $SP,$SP,$u5x4 */

static SEM_PC
SEM_FN_NAME (arc600f,add_s_asspsp) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_SP ();
  tmp_C = FLD (f_u5x4);
  {
    SI opval = ADDSI (tmp_B, tmp_C);
    SET_H_SP (, opval);
    TRACE_RESULT (current_cpu, abuf, "sp", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* add_s_gp: add$_S $R0,$GP,$s9x4 */

static SEM_PC
SEM_FN_NAME (arc600f,add_s_gp) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_gprel.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_GP ();
  tmp_C = FLD (f_s9x4);
  {
    SI opval = ADDSI (tmp_B, tmp_C);
    SET_H_R0 (, opval);
    TRACE_RESULT (current_cpu, abuf, "r0", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* add_s_r_u7: add$_S $R_b,$R_b,$u7 */

static SEM_PC
SEM_FN_NAME (arc600f,add_s_r_u7) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_r_u7.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u7);
  {
    SI opval = ADDSI (tmp_B, tmp_C);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* adc_L_s12 $RA,: adc$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,adc_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDCSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), CPU (h_cbit));
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), CPU (h_cbit));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* adc_ccu6 $RA,: adc$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,adc_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ADDCSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* adc_L_u6 $RA,: adc$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,adc_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDCSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* adc_L_r_r $RA,$RC: adc$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,adc_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDCSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* adc_cc $RA,$RC: adc$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,adc_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ADDCSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
    CPU (h_cbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub_L_s12 $RA,: sub$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,sub_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub_ccu6 $RA,: sub$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sub_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub_L_u6 $RA,: sub$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sub_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub_L_r_r $RA,$RC: sub$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sub_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub_cc $RA,$RC: sub$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sub_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub_s_cbu3: sub$_S $R_c,$R_b,$u3 */

static SEM_PC
SEM_FN_NAME (arc600f,sub_s_cbu3) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u3);
  {
    SI opval = SUBSI (tmp_B, tmp_C);
    SET_H_CR16 (FLD (f_op__c), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* I16_GO_SUB_s_go: sub$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_SUB_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = SUBSI (tmp_B, tmp_C);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* sub_s_go_sub_ne: sub$_S $NE$R_b,$R_b,$R_b */

static SEM_PC
SEM_FN_NAME (arc600f,sub_s_go_sub_ne) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_mov_s_r_u7.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (EQBI (CPU (h_zbit), 0)) {
  {
    SI opval = 0;
    SET_H_CR16 (FLD (f_op__b), opval);
    written |= (1 << 1);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub_s_ssb: sub$_S $R_b,$R_b,$u5 */

static SEM_PC
SEM_FN_NAME (arc600f,sub_s_ssb) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldb_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u5);
  {
    SI opval = SUBSI (tmp_B, tmp_C);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* sub_s_asspsp: sub$_S $SP,$SP,$u5x4 */

static SEM_PC
SEM_FN_NAME (arc600f,sub_s_asspsp) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ld_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_SP ();
  tmp_C = FLD (f_u5x4);
  {
    SI opval = SUBSI (tmp_B, tmp_C);
    SET_H_SP (, opval);
    TRACE_RESULT (current_cpu, abuf, "sp", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* sbc_L_s12 $RA,: sbc$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,sbc_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBCSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), CPU (h_cbit));
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), CPU (h_cbit));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sbc_ccu6 $RA,: sbc$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sbc_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBCSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sbc_L_u6 $RA,: sbc$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sbc_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBCSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), CPU (h_cbit));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sbc_L_r_r $RA,$RC: sbc$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sbc_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBCSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sbc_cc $RA,$RC: sbc$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sbc_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBCSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), CPU (h_cbit));
    CPU (h_cbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* and_L_s12 $RA,: and$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,and_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* and_ccu6 $RA,: and$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,and_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* and_L_u6 $RA,: and$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,and_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* and_L_r_r $RA,$RC: and$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,and_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* and_cc $RA,$RC: and$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,and_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_AND_s_go: and$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_AND_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = ANDSI (tmp_B, tmp_C);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* or_L_s12 $RA,: or$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,or_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* or_ccu6 $RA,: or$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,or_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ORSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* or_L_u6 $RA,: or$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,or_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* or_L_r_r $RA,$RC: or$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,or_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* or_cc $RA,$RC: or$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,or_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ORSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_OR_s_go: or$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_OR_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = ORSI (tmp_B, tmp_C);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* bic_L_s12 $RA,: bic$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,bic_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), INVSI (FLD (f_s12)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bic_ccu6 $RA,: bic$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,bic_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), INVSI (FLD (f_u6)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bic_L_u6 $RA,: bic$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,bic_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), INVSI (FLD (f_u6)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bic_L_r_r $RA,$RC: bic$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,bic_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), INVSI (GET_H_CR (FLD (f_op_C))));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bic_cc $RA,$RC: bic$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,bic_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), INVSI (GET_H_CR (FLD (f_op_C))));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_BIC_s_go: bic$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_BIC_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = ANDSI (tmp_B, INVSI (tmp_C));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* xor_L_s12 $RA,: xor$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,xor_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = XORSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* xor_ccu6 $RA,: xor$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,xor_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = XORSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* xor_L_u6 $RA,: xor$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,xor_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = XORSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* xor_L_r_r $RA,$RC: xor$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,xor_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = XORSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* xor_cc $RA,$RC: xor$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,xor_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = XORSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_XOR_s_go: xor$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_XOR_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = XORSI (tmp_B, tmp_C);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* max_L_s12 $RA,: max$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,max_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (GTSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12))) ? (GET_H_CR (FLD (f_op_B))) : (FLD (f_s12));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = GESI (FLD (f_s12), GET_H_CR (FLD (f_op_B)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* max_ccu6 $RA,: max$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,max_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (GTSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6))) ? (GET_H_CR (FLD (f_op_B))) : (FLD (f_u6));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = GESI (FLD (f_u6), GET_H_CR (FLD (f_op_B)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* max_L_u6 $RA,: max$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,max_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (GTSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6))) ? (GET_H_CR (FLD (f_op_B))) : (FLD (f_u6));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = GESI (FLD (f_u6), GET_H_CR (FLD (f_op_B)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* max_L_r_r $RA,$RC: max$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,max_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (GTSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)))) ? (GET_H_CR (FLD (f_op_B))) : (GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = GESI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_B)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* max_cc $RA,$RC: max$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,max_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (GTSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)))) ? (GET_H_CR (FLD (f_op_B))) : (GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = GESI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_B)));
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* min_L_s12 $RA,: min$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,min_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (LTSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12))) ? (GET_H_CR (FLD (f_op_B))) : (FLD (f_s12));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = LESI (FLD (f_s12), GET_H_CR (FLD (f_op_B)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* min_ccu6 $RA,: min$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,min_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (LTSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6))) ? (GET_H_CR (FLD (f_op_B))) : (FLD (f_u6));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = LESI (FLD (f_u6), GET_H_CR (FLD (f_op_B)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* min_L_u6 $RA,: min$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,min_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (LTSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6))) ? (GET_H_CR (FLD (f_op_B))) : (FLD (f_u6));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = LESI (FLD (f_u6), GET_H_CR (FLD (f_op_B)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* min_L_r_r $RA,$RC: min$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,min_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (LTSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)))) ? (GET_H_CR (FLD (f_op_B))) : (GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = LESI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_B)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* min_cc $RA,$RC: min$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,min_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (LTSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)))) ? (GET_H_CR (FLD (f_op_B))) : (GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = LESI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_B)));
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mov_L_s12 : mov$_L$F $RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,mov_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
((void) 0); /*nop*/
  tmp_result = FLD (f_s12);
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
if (GTSI (FLD (f_F), 0)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 3);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 4);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mov_ccu6 : mov$Qcondi$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mov_ccu6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
((void) 0); /*nop*/
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
((void) 0); /*nop*/
  tmp_result = FLD (f_u6);
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 3);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
if (GTSI (FLD (f_F), 0)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 4);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 5);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mov_L_u6 : mov$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mov_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
((void) 0); /*nop*/
  tmp_result = FLD (f_u6);
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
if (GTSI (FLD (f_F), 0)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 3);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 4);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mov_L_r_r $RC: mov$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mov_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = GET_H_CR (FLD (f_op_C));
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
if (GTSI (FLD (f_F), 0)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mov_cc $RC: mov$Qcondi$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mov_cc__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
((void) 0); /*nop*/
  tmp_result = GET_H_CR (FLD (f_op_C));
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
if (GTSI (FLD (f_F), 0)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mov_s_mcah: mov$_S $R_b,$Rh */

static SEM_PC
SEM_FN_NAME (arc600f,mov_s_mcah) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_mcah.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_h), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 2));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (2, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_h), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = GET_H_CR (FLD (f_op_h));
  {
    SI opval = tmp_result;
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
if (GTSI (-1, 0)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 6);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mov_s_mcahb: mov$_S $Rh,$R_b */

static SEM_PC
SEM_FN_NAME (arc600f,mov_s_mcahb) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_mcah.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
((void) 0); /*nop*/
  tmp_result = GET_H_CR16 (FLD (f_op__b));
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_h), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
if (GTSI (-1, 0)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 2);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 3);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mov_s_r_u7: mov$_S $R_b,$u7 */

static SEM_PC
SEM_FN_NAME (arc600f,mov_s_r_u7) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_mov_s_r_u7.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
((void) 0); /*nop*/
  tmp_result = FLD (f_u8);
  {
    SI opval = tmp_result;
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
if (GTSI (-1, 0)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 2);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 3);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* tst_L_s12 : tst$_L$F1 $RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,tst_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_s12);
  tmp_result = ANDSI (tmp_B, tmp_C);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* tst_ccu6 : tst$Qcondi$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,tst_ccu6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_u6);
  tmp_result = ANDSI (tmp_B, tmp_C);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* tst_L_u6 : tst$_L$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,tst_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_u6);
  tmp_result = ANDSI (tmp_B, tmp_C);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* tst_L_r_r $RC: tst$_L$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,tst_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = GET_H_CR (FLD (f_op_C));
  tmp_result = ANDSI (tmp_B, tmp_C);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* tst_cc $RC: tst$Qcondi$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,tst_cc__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = GET_H_CR (FLD (f_op_C));
  tmp_result = ANDSI (tmp_B, tmp_C);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* tst_s_go: tst$_S $R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,tst_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  tmp_result = ANDSI (tmp_B, tmp_C);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* cmp_L_s12 : cmp$_L$F1 $RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,cmp_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = EXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = EXTSIDI (FLD (f_s12));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = ZEXTSIDI (FLD (f_s12));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* cmp_ccu6 : cmp$Qcondi$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,cmp_ccu6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
((void) 0); /*nop*/
  tmp_B = EXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = EXTSIDI (FLD (f_u6));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = ZEXTSIDI (FLD (f_u6));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* cmp_L_u6 : cmp$_L$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,cmp_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = EXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = EXTSIDI (FLD (f_u6));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = ZEXTSIDI (FLD (f_u6));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* cmp_L_r_r $RC: cmp$_L$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,cmp_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = EXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = EXTSIDI (GET_H_CR (FLD (f_op_C)));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = ZEXTSIDI (GET_H_CR (FLD (f_op_C)));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* cmp_cc $RC: cmp$Qcondi$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,cmp_cc__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
((void) 0); /*nop*/
  tmp_B = EXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = EXTSIDI (GET_H_CR (FLD (f_op_C)));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = ZEXTSIDI (GET_H_CR (FLD (f_op_C)));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* cmp_s_mcah: cmp$_S $R_b,$Rh */

static SEM_PC
SEM_FN_NAME (arc600f,cmp_s_mcah) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_mcah.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
{
if (EQSI (FLD (f_op_h), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 2));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (2, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_h), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = EXTSIDI (GET_H_CR16 (FLD (f_op__b)));
  tmp_C = EXTSIDI (GET_H_CR (FLD (f_op_h)));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR16 (FLD (f_op__b)));
  tmp_C = ZEXTSIDI (GET_H_CR (FLD (f_op_h)));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* cmp_s_r_u7: cmp$_S $R_b,$u7 */

static SEM_PC
SEM_FN_NAME (arc600f,cmp_s_r_u7) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_r_u7.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
((void) 0); /*nop*/
  tmp_B = EXTSIDI (GET_H_CR16 (FLD (f_op__b)));
  tmp_C = EXTSIDI (FLD (f_u7));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR16 (FLD (f_op__b)));
  tmp_C = ZEXTSIDI (FLD (f_u7));
  tmp_tmp = SUBDI (tmp_B, tmp_C);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* rcmp_L_s12 : rcmp$_L$F1 $RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,rcmp_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = EXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = EXTSIDI (FLD (f_s12));
  tmp_tmp = SUBDI (tmp_C, tmp_B);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = ZEXTSIDI (FLD (f_s12));
  tmp_tmp = SUBDI (tmp_C, tmp_B);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* rcmp_ccu6 : rcmp$Qcondi$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,rcmp_ccu6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
((void) 0); /*nop*/
  tmp_B = EXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = EXTSIDI (FLD (f_u6));
  tmp_tmp = SUBDI (tmp_C, tmp_B);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = ZEXTSIDI (FLD (f_u6));
  tmp_tmp = SUBDI (tmp_C, tmp_B);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* rcmp_L_u6 : rcmp$_L$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,rcmp_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = EXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = EXTSIDI (FLD (f_u6));
  tmp_tmp = SUBDI (tmp_C, tmp_B);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = ZEXTSIDI (FLD (f_u6));
  tmp_tmp = SUBDI (tmp_C, tmp_B);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* rcmp_L_r_r $RC: rcmp$_L$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,rcmp_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = EXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = EXTSIDI (GET_H_CR (FLD (f_op_C)));
  tmp_tmp = SUBDI (tmp_C, tmp_B);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = ZEXTSIDI (GET_H_CR (FLD (f_op_C)));
  tmp_tmp = SUBDI (tmp_C, tmp_B);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* rcmp_cc $RC: rcmp$Qcondi$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,rcmp_cc__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  DI tmp_tmp;
  DI tmp_B;
  DI tmp_C;
((void) 0); /*nop*/
  tmp_B = EXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = EXTSIDI (GET_H_CR (FLD (f_op_C)));
  tmp_tmp = SUBDI (tmp_C, tmp_B);
  tmp_result = SUBWORDDISI (tmp_tmp, 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEBI (LTSI (tmp_result, 0), LTDI (tmp_tmp, 0));
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  tmp_B = ZEXTSIDI (GET_H_CR (FLD (f_op_B)));
  tmp_C = ZEXTSIDI (GET_H_CR (FLD (f_op_C)));
  tmp_tmp = SUBDI (tmp_C, tmp_B);
  {
    BI opval = LTDI (tmp_tmp, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* rsub_L_s12 $RA,: rsub$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,rsub_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (FLD (f_s12), GET_H_CR (FLD (f_op_B)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (FLD (f_s12), GET_H_CR (FLD (f_op_B)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (FLD (f_s12), GET_H_CR (FLD (f_op_B)), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* rsub_ccu6 $RA,: rsub$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,rsub_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBSI (FLD (f_u6), GET_H_CR (FLD (f_op_B)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (FLD (f_u6), GET_H_CR (FLD (f_op_B)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (FLD (f_u6), GET_H_CR (FLD (f_op_B)), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* rsub_L_u6 $RA,: rsub$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,rsub_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (FLD (f_u6), GET_H_CR (FLD (f_op_B)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (FLD (f_u6), GET_H_CR (FLD (f_op_B)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (FLD (f_u6), GET_H_CR (FLD (f_op_B)), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* rsub_L_r_r $RA,$RC: rsub$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,rsub_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_B)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_B)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_B)), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* rsub_cc $RA,$RC: rsub$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,rsub_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_B)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_B)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_B)), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bset_L_s12 $RA,: bset$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,bset_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (GET_H_CR (FLD (f_op_B)), SLLSI (1, ANDSI (FLD (f_s12), 31)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bset_ccu6 $RA,: bset$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,bset_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ORSI (GET_H_CR (FLD (f_op_B)), SLLSI (1, ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bset_L_u6 $RA,: bset$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,bset_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (GET_H_CR (FLD (f_op_B)), SLLSI (1, ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bset_L_r_r $RA,$RC: bset$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,bset_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (GET_H_CR (FLD (f_op_B)), SLLSI (1, ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bset_cc $RA,$RC: bset$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,bset_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ORSI (GET_H_CR (FLD (f_op_B)), SLLSI (1, ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bset_s_ssb: bset$_S $R_b,$R_b,$u5 */

static SEM_PC
SEM_FN_NAME (arc600f,bset_s_ssb) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldb_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u5);
  {
    SI opval = ORSI (tmp_B, SLLSI (1, ANDSI (tmp_C, 31)));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* bclr_L_s12 $RA,: bclr$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,bclr_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), INVSI (SLLSI (1, ANDSI (FLD (f_s12), 31))));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bclr_ccu6 $RA,: bclr$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,bclr_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), INVSI (SLLSI (1, ANDSI (FLD (f_u6), 31))));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bclr_L_u6 $RA,: bclr$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,bclr_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), INVSI (SLLSI (1, ANDSI (FLD (f_u6), 31))));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bclr_L_r_r $RA,$RC: bclr$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,bclr_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), INVSI (SLLSI (1, ANDSI (GET_H_CR (FLD (f_op_C)), 31))));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bclr_cc $RA,$RC: bclr$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,bclr_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), INVSI (SLLSI (1, ANDSI (GET_H_CR (FLD (f_op_C)), 31))));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bclr_s_ssb: bclr$_S $R_b,$R_b,$u5 */

static SEM_PC
SEM_FN_NAME (arc600f,bclr_s_ssb) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldb_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u5);
  {
    SI opval = ANDSI (tmp_B, INVSI (SLLSI (1, ANDSI (tmp_C, 31))));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* btst_L_s12 : btst$_L$F1 $RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,btst_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_s12);
  tmp_result = ANDSI (tmp_B, SLLSI (1, ANDSI (tmp_C, 31)));
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* btst_ccu6 : btst$Qcondi$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,btst_ccu6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_u6);
  tmp_result = ANDSI (tmp_B, SLLSI (1, ANDSI (tmp_C, 31)));
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* btst_L_u6 : btst$_L$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,btst_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = FLD (f_u6);
  tmp_result = ANDSI (tmp_B, SLLSI (1, ANDSI (tmp_C, 31)));
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* btst_L_r_r $RC: btst$_L$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,btst_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = GET_H_CR (FLD (f_op_C));
  tmp_result = ANDSI (tmp_B, SLLSI (1, ANDSI (tmp_C, 31)));
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* btst_cc $RC: btst$Qcondi$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,btst_cc__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR (FLD (f_op_B));
  tmp_C = GET_H_CR (FLD (f_op_C));
  tmp_result = ANDSI (tmp_B, SLLSI (1, ANDSI (tmp_C, 31)));
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* btst_s_ssb: btst$_S $R_b,$u5 */

static SEM_PC
SEM_FN_NAME (arc600f,btst_s_ssb) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldb_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u5);
  tmp_result = ANDSI (tmp_B, SLLSI (1, ANDSI (tmp_C, 31)));
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* bxor_L_s12 $RA,: bxor$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,bxor_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = XORSI (GET_H_CR (FLD (f_op_B)), SLLSI (1, ANDSI (FLD (f_s12), 31)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bxor_ccu6 $RA,: bxor$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,bxor_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = XORSI (GET_H_CR (FLD (f_op_B)), SLLSI (1, ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bxor_L_u6 $RA,: bxor$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,bxor_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = XORSI (GET_H_CR (FLD (f_op_B)), SLLSI (1, ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bxor_L_r_r $RA,$RC: bxor$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,bxor_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = XORSI (GET_H_CR (FLD (f_op_B)), SLLSI (1, ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bxor_cc $RA,$RC: bxor$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,bxor_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = XORSI (GET_H_CR (FLD (f_op_B)), SLLSI (1, ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bmsk_L_s12 $RA,: bmsk$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,bmsk_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), SUBSI (SLLSI (SLLSI (1, ANDSI (FLD (f_s12), 31)), 1), 1));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bmsk_ccu6 $RA,: bmsk$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,bmsk_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), SUBSI (SLLSI (SLLSI (1, ANDSI (FLD (f_u6), 31)), 1), 1));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bmsk_L_u6 $RA,: bmsk$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,bmsk_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), SUBSI (SLLSI (SLLSI (1, ANDSI (FLD (f_u6), 31)), 1), 1));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bmsk_L_r_r $RA,$RC: bmsk$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,bmsk_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), SUBSI (SLLSI (SLLSI (1, ANDSI (GET_H_CR (FLD (f_op_C)), 31)), 1), 1));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bmsk_cc $RA,$RC: bmsk$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,bmsk_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ANDSI (GET_H_CR (FLD (f_op_B)), SUBSI (SLLSI (SLLSI (1, ANDSI (GET_H_CR (FLD (f_op_C)), 31)), 1), 1));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* bmsk_s_ssb: bmsk$_S $R_b,$R_b,$u5 */

static SEM_PC
SEM_FN_NAME (arc600f,bmsk_s_ssb) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldb_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u5);
  {
    SI opval = ANDSI (tmp_B, SUBSI (SLLSI (SLLSI (1, ANDSI (tmp_C, 31)), 1), 1));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* add1_L_s12 $RA,: add1$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,add1_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_s12), 1));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_s12), 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add1_ccu6 $RA,: add1$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,add1_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 1));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add1_L_u6 $RA,: add1$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,add1_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 1));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add1_L_r_r $RA,$RC: add1$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,add1_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 1));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add1_cc $RA,$RC: add1$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,add1_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 1));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_ADD1_s_go: add1$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_ADD1_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = ADDSI (tmp_B, SLLSI (tmp_C, 1));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* add2_L_s12 $RA,: add2$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,add2_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_s12), 2));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_s12), 2);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add2_ccu6 $RA,: add2$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,add2_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 2));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 2);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add2_L_u6 $RA,: add2$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,add2_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 2));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 2);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add2_L_r_r $RA,$RC: add2$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,add2_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 2));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 2);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add2_cc $RA,$RC: add2$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,add2_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 2));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 2);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_ADD2_s_go: add2$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_ADD2_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = ADDSI (tmp_B, SLLSI (tmp_C, 2));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* add3_L_s12 $RA,: add3$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,add3_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_s12), 3));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_s12), 3);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add3_ccu6 $RA,: add3$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,add3_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 3));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 3);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add3_L_u6 $RA,: add3$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,add3_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 3));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 3);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add3_L_r_r $RA,$RC: add3$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,add3_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 3));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 3);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* add3_cc $RA,$RC: add3$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,add3_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 3));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 3);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_ADD3_s_go: add3$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_ADD3_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = ADDSI (tmp_B, SLLSI (tmp_C, 3));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* sub1_L_s12 $RA,: sub1$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,sub1_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_s12), 1));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_s12), 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub1_ccu6 $RA,: sub1$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sub1_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 1));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub1_L_u6 $RA,: sub1$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sub1_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 1));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub1_L_r_r $RA,$RC: sub1$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sub1_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 1));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub1_cc $RA,$RC: sub1$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sub1_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 1));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 1);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub2_L_s12 $RA,: sub2$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,sub2_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_s12), 2));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_s12), 2);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub2_ccu6 $RA,: sub2$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sub2_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 2));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 2);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub2_L_u6 $RA,: sub2$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sub2_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 2));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 2);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub2_L_r_r $RA,$RC: sub2$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sub2_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 2));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 2);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub2_cc $RA,$RC: sub2$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sub2_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 2));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 2);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub3_L_s12 $RA,: sub3$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,sub3_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_s12), 3));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_s12), 3);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub3_ccu6 $RA,: sub3$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sub3_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 3));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 3);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub3_L_u6 $RA,: sub3$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sub3_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (FLD (f_u6), 3));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (FLD (f_u6), 3);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub3_L_r_r $RA,$RC: sub3$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sub3_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 3));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 3);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sub3_cc $RA,$RC: sub3$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sub3_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = SUBSI (GET_H_CR (FLD (f_op_B)), SLLSI (GET_H_CR (FLD (f_op_C)), 3));
if (FLD (f_F)) {
{
  SI tmp_sC;
  tmp_sC = SLLSI (GET_H_CR (FLD (f_op_C)), 3);
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SUBOFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = SUBCFSI (GET_H_CR (FLD (f_op_B)), tmp_sC, 0);
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpy_L_s12 $RA,: mpy$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,mpy_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEDI (EXTSIDI (tmp_result), MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_s12))));
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpy_ccu6 $RA,: mpy$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mpy_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEDI (EXTSIDI (tmp_result), MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_u6))));
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpy_L_u6 $RA,: mpy$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mpy_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEDI (EXTSIDI (tmp_result), MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_u6))));
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpy_L_r_r $RA,$RC: mpy$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mpy_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C))));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEDI (EXTSIDI (tmp_result), MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (GET_H_CR (FLD (f_op_C)))));
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpy_cc $RA,$RC: mpy$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mpy_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C))));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEDI (EXTSIDI (tmp_result), MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (GET_H_CR (FLD (f_op_C)))));
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyh_L_s12 $RA,: mpyh$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,mpyh_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SUBWORDDISI (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_s12))), 0));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = 0;
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyh_ccu6 $RA,: mpyh$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mpyh_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SUBWORDDISI (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_u6))), 0));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = 0;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyh_L_u6 $RA,: mpyh$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mpyh_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SUBWORDDISI (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_u6))), 0));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = 0;
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyh_L_r_r $RA,$RC: mpyh$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mpyh_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SUBWORDDISI (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (GET_H_CR (FLD (f_op_C)))), 0));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = 0;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyh_cc $RA,$RC: mpyh$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mpyh_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SUBWORDDISI (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (GET_H_CR (FLD (f_op_C)))), 0));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = 0;
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyhu_L_s12 $RA,: mpyhu$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,mpyhu_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SUBWORDDISI (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (FLD (f_s12))), 0));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = 0;
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyhu_ccu6 $RA,: mpyhu$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mpyhu_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SUBWORDDISI (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (FLD (f_u6))), 0));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = 0;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyhu_L_u6 $RA,: mpyhu$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mpyhu_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SUBWORDDISI (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (FLD (f_u6))), 0));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = 0;
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyhu_L_r_r $RA,$RC: mpyhu$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mpyhu_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SUBWORDDISI (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (GET_H_CR (FLD (f_op_C)))), 0));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = 0;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyhu_cc $RA,$RC: mpyhu$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mpyhu_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SUBWORDDISI (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (GET_H_CR (FLD (f_op_C)))), 0));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = 0;
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyu_L_s12 $RA,: mpyu$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,mpyu_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULSI (GET_H_CR (FLD (f_op_B)), FLD (f_s12)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEDI (ZEXTSIDI (tmp_result), MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (FLD (f_s12))));
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyu_ccu6 $RA,: mpyu$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mpyu_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEDI (ZEXTSIDI (tmp_result), MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (FLD (f_u6))));
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyu_L_u6 $RA,: mpyu$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mpyu_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULSI (GET_H_CR (FLD (f_op_B)), FLD (f_u6)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEDI (ZEXTSIDI (tmp_result), MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (FLD (f_u6))));
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyu_L_r_r $RA,$RC: mpyu$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mpyu_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C))));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEDI (ZEXTSIDI (tmp_result), MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (GET_H_CR (FLD (f_op_C)))));
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mpyu_cc $RA,$RC: mpyu$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mpyu_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULSI (GET_H_CR (FLD (f_op_B)), GET_H_CR (FLD (f_op_C))));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = NEDI (ZEXTSIDI (tmp_result), MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (GET_H_CR (FLD (f_op_C)))));
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* j_L_r_r [$RC_noilink]: j$_L$F0 [$RC_noilink] */

static SEM_PC
SEM_FN_NAME (arc600f,j_L_r_r___RC_noilink_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_cc [$RC_noilink]: j$Qcondi$F0 [$RC_noilink] */

static SEM_PC
SEM_FN_NAME (arc600f,j_cc___RC_noilink_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 25);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 25);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 25);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 25);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_L_r_r [$RC_ilink]: j$_L$F1F [$RC_ilink] */

static SEM_PC
SEM_FN_NAME (arc600f,j_L_r_r___RC_ilink_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_ILINKX (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_ILINKX (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_ILINKX (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_cc [$RC_ilink]: j$Qcondi$F1F [$RC_ilink] */

static SEM_PC
SEM_FN_NAME (arc600f,j_cc___RC_ilink_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 23);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_ILINKX (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 25);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_ILINKX (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 25);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 22);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 25);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  switch (FLD (f_op_Cj))
  {
  case 29 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 11));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  case 30 : {
if (FLD (f_F)) {
  {
    SI opval = GET_H_AUXR (((UINT) 12));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 24);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
} else {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  default : {
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
}
    break;
  }
  {
    USI opval = GET_H_ILINKX (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 25);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_L_s12 : j$_L$F0 $s12 */

static SEM_PC
SEM_FN_NAME (arc600f,j_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_ccu6 : j$Qcondi$F0 $U6 */

static SEM_PC
SEM_FN_NAME (arc600f,j_ccu6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_L_u6 : j$_L$F0 $U6 */

static SEM_PC
SEM_FN_NAME (arc600f,j_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
if (FLD (f_F)) {
cgen_rtx_error (current_cpu, "invalid insn");
}
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_s: j$_S [$R_b] */

static SEM_PC
SEM_FN_NAME (arc600f,j_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_mov_s_r_u7.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_s$_S: j$_S [$R31] */

static SEM_PC
SEM_FN_NAME (arc600f,j_s__S) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_seq$_S: jeq$_S [$R31] */

static SEM_PC
SEM_FN_NAME (arc600f,j_seq__S) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
if (NEBI (CPU (h_zbit), 0)) {
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
 else if (0) {
{
  SI tmp_result;
((void) 0); /*nop*/
if (NEBI (CPU (h_zbit), 0)) {
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
if (NEBI (CPU (h_zbit), 0)) {
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_sne$_S: jne$_S [$R31] */

static SEM_PC
SEM_FN_NAME (arc600f,j_sne__S) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
if (EQBI (CPU (h_zbit), 0)) {
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
 else if (0) {
{
  SI tmp_result;
((void) 0); /*nop*/
if (EQBI (CPU (h_zbit), 0)) {
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
if (EQBI (CPU (h_zbit), 0)) {
{
((void) 0); /*nop*/
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_L_s12.d : j$_L$F0.d $s12 */

static SEM_PC
SEM_FN_NAME (arc600f,j_L_s12_d_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (1) {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_ccu6.d : j$Qcondi$F0.d $U6 */

static SEM_PC
SEM_FN_NAME (arc600f,j_ccu6_d_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (1) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_L_u6.d : j$_L$F0.d $U6 */

static SEM_PC
SEM_FN_NAME (arc600f,j_L_u6_d_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (1) {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_L_r_r.d [$RC]: j$_L$F0.d [$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,j_L_r_r_d___RC_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (1) {
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_cc.d [$RC]: j$Qcondi$F0.d [$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,j_cc_d___RC_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (1) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_s.d: j$_S.d [$R_b] */

static SEM_PC
SEM_FN_NAME (arc600f,j_s_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_mov_s_r_u7.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (1) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* j_s$_S.d: j$_S.d [$R31] */

static SEM_PC
SEM_FN_NAME (arc600f,j_s__S_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else if (1) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_R31 ();
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_L_s12 : jl$_L$F0 $s12 */

static SEM_PC
SEM_FN_NAME (arc600f,jl_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_ccu6 : jl$Qcondi$F0 $U6 */

static SEM_PC
SEM_FN_NAME (arc600f,jl_ccu6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_L_u6 : jl$_L$F0 $U6 */

static SEM_PC
SEM_FN_NAME (arc600f,jl_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_s: jl$_S [$R_b] */

static SEM_PC
SEM_FN_NAME (arc600f,jl_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_mov_s_r_u7.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 2);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 2);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 2);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_L_r_r [$RC_noilink]: jl$_L$F0 [$RC_noilink] */

static SEM_PC
SEM_FN_NAME (arc600f,jl_L_r_r___RC_noilink_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, ((EQSI (FLD (f_op_C), 62)) ? (8) : (4)));
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, ((EQSI (FLD (f_op_C), 62)) ? (8) : (4)));
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, ((EQSI (FLD (f_op_C), 62)) ? (8) : (4)));
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_cc [$RC_noilink]: jl$Qcondi$F0 [$RC_noilink] */

static SEM_PC
SEM_FN_NAME (arc600f,jl_cc___RC_noilink_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, ((EQSI (FLD (f_op_C), 62)) ? (8) : (4)));
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, ((EQSI (FLD (f_op_C), 62)) ? (8) : (4)));
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    USI opval = GET_H_NOILINK (FLD (f_op_Cj));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, ((EQSI (FLD (f_op_C), 62)) ? (8) : (4)));
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_L_s12.d : jl$_L$F0.d $s12 */

static SEM_PC
SEM_FN_NAME (arc600f,jl_L_s12_d_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
 else if (1) {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (f_s12);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_ccu6.d : jl$Qcondi$F0.d $U6 */

static SEM_PC
SEM_FN_NAME (arc600f,jl_ccu6_d_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
 else if (1) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_L_u6.d : jl$_L$F0.d $U6 */

static SEM_PC
SEM_FN_NAME (arc600f,jl_L_u6_d_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
 else if (1) {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = FLD (f_u6);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_L_r_r.d [$RC]: jl$_L$F0.d [$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,jl_L_r_r_d___RC_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
 else if (1) {
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_cc.d [$RC]: jl$Qcondi$F0.d [$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,jl_cc_d___RC_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
 else if (1) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 8);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = GET_H_CR (FLD (f_op_C));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* jl_s.d: jl$_S.d [$R_b] */

static SEM_PC
SEM_FN_NAME (arc600f,jl_s_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_mov_s_r_u7.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 2));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
}
 else if (1) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 2));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  HI tmp_nword;
  tmp_nword = GETMEMHI (current_cpu, pc, ADDSI (pc, 2));
if (ANDHI (ANDHI (tmp_nword, SRAHI (tmp_nword, 1)), 40960)) {
  {
    SI opval = ADDSI (pc, 4);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
} else {
  {
    SI opval = ADDSI (pc, 6);
    SET_H_CR (((UINT) 31), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
{
  {
    USI opval = GET_H_CR16 (FLD (f_op__b));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* lp_L_s12 : lp$_L$F0 $s12x2 */

static SEM_PC
SEM_FN_NAME (arc600f,lp_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_lp_L_s12_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    SI opval = ADDSI (ANDSI (pc, -4), FLD (f_s12x2));
    SET_H_AUXR (((UINT) 3), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_AUXR (((UINT) 2), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    SI opval = ADDSI (ANDSI (pc, -4), FLD (f_s12x2));
    SET_H_AUXR (((UINT) 3), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_AUXR (((UINT) 2), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
  {
    SI opval = ADDSI (ANDSI (pc, -4), FLD (f_s12x2));
    SET_H_AUXR (((UINT) 3), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_AUXR (((UINT) 2), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* lpcc_ccu6: lp$Qcondi$F0 $U6x2 */

static SEM_PC
SEM_FN_NAME (arc600f,lpcc_ccu6) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_lpcc_ccu6.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    SI opval = ADDSI (ANDSI (pc, -4), FLD (f_u6x2));
    SET_H_AUXR (((UINT) 3), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_AUXR (((UINT) 2), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
}
}
}
}
 else if (0) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    SI opval = ADDSI (ANDSI (pc, -4), FLD (f_u6x2));
    SET_H_AUXR (((UINT) 3), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_AUXR (((UINT) 2), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
}
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  SI tmp_result;
((void) 0); /*nop*/
{
  {
    SI opval = ADDSI (ANDSI (pc, -4), FLD (f_u6x2));
    SET_H_AUXR (((UINT) 3), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    SI opval = ADDSI (pc, 4);
    SET_H_AUXR (((UINT) 2), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
}
}
}
} else {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 20);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
  {
    USI opval = ADDSI (ANDSI (pc, -4), FLD (f_u6x2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else if (0) {
  {
    USI opval = ADDSI (ANDSI (pc, -4), FLD (f_u6x2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
  {
    USI opval = ADDSI (ANDSI (pc, -4), FLD (f_u6x2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 21);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* flag_L_s12 : flag$_L$F0 $s12 */

static SEM_PC
SEM_FN_NAME (arc600f,flag_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
if (ANDSI (FLD (f_s12), 1)) {
sim_engine_halt (CPU_STATE (current_cpu), current_cpu, NULL, pc,			    sim_exited, a5f_h_cr_get (current_cpu, 0));}
  {
    SI opval = FLD (f_s12);
    SET_H_STATUS32 (((UINT) 0), opval);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* flag_ccu6 : flag$Qcondi$F0 $U6 */

static SEM_PC
SEM_FN_NAME (arc600f,flag_ccu6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
if (ANDSI (FLD (f_u6), 1)) {
sim_engine_halt (CPU_STATE (current_cpu), current_cpu, NULL, pc,			    sim_exited, a5f_h_cr_get (current_cpu, 0));}
  {
    SI opval = FLD (f_u6);
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 6);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* flag_L_u6 : flag$_L$F0 $U6 */

static SEM_PC
SEM_FN_NAME (arc600f,flag_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
if (ANDSI (FLD (f_u6), 1)) {
sim_engine_halt (CPU_STATE (current_cpu), current_cpu, NULL, pc,			    sim_exited, a5f_h_cr_get (current_cpu, 0));}
  {
    SI opval = FLD (f_u6);
    SET_H_STATUS32 (((UINT) 0), opval);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* flag_L_r_r $RC: flag$_L$F0 $RC */

static SEM_PC
SEM_FN_NAME (arc600f,flag_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
{
if (ANDSI (GET_H_CR (FLD (f_op_C)), 1)) {
sim_engine_halt (CPU_STATE (current_cpu), current_cpu, NULL, pc,			    sim_exited, a5f_h_cr_get (current_cpu, 0));}
  {
    SI opval = GET_H_CR (FLD (f_op_C));
    SET_H_STATUS32 (((UINT) 0), opval);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
}
}

  return vpc;
#undef FLD
}

/* flag_cc $RC: flag$Qcondi$F0 $RC */

static SEM_PC
SEM_FN_NAME (arc600f,flag_cc__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
((void) 0); /*nop*/
{
if (ANDSI (GET_H_CR (FLD (f_op_C)), 1)) {
sim_engine_halt (CPU_STATE (current_cpu), current_cpu, NULL, pc,			    sim_exited, a5f_h_cr_get (current_cpu, 0));}
  {
    SI opval = GET_H_CR (FLD (f_op_C));
    SET_H_STATUS32 (((UINT) 0), opval);
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "status32", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* lr_L_r_r [$RC]: lr$_L$F0 $RB,[$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,lr_L_r_r___RC_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  {
    SI opval = GET_H_AUXR (GET_H_CR (FLD (f_op_C)));
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* lr_L_s12 : lr$_L$F0 $RB,[$s12] */

static SEM_PC
SEM_FN_NAME (arc600f,lr_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  {
    SI opval = GET_H_AUXR (FLD (f_s12));
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* lr_L_u6 : lr$_L$F0 $RB,[$U6] */

static SEM_PC
SEM_FN_NAME (arc600f,lr_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  {
    SI opval = GET_H_AUXR (FLD (f_u6));
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* sr_L_r_r [$RC]: sr$_L$F0 $RB,[$RC] */

static SEM_PC
SEM_FN_NAME (arc600f,sr_L_r_r___RC_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  {
    SI opval = GET_H_CR (FLD (f_op_B));
    SET_H_AUXR (GET_H_CR (FLD (f_op_C)), opval);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
}

  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* sr_L_s12 : sr$_L$F0 $RB,[$s12] */

static SEM_PC
SEM_FN_NAME (arc600f,sr_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  {
    SI opval = GET_H_CR (FLD (f_op_B));
    SET_H_AUXR (FLD (f_s12), opval);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
}

  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* sr_L_u6 : sr$_L$F0 $RB,[$U6] */

static SEM_PC
SEM_FN_NAME (arc600f,sr_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  {
    SI opval = GET_H_CR (FLD (f_op_B));
    SET_H_AUXR (FLD (f_u6), opval);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
}

  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* asl_L_r_r $RC: asl$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,asl_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (GET_H_CR (FLD (f_op_C)), GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asl_L_u6 : asl$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,asl_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ADDSI (FLD (f_u6), FLD (f_u6));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ADDOFSI (FLD (f_u6), FLD (f_u6), 0);
    CPU (h_vbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = ADDCFSI (FLD (f_u6), FLD (f_u6), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_ASL_s_go: asl$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_ASL_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = ADDSI (tmp_C, tmp_C);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* asr_L_r_r $RC: asr$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,asr_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SRASI (GET_H_CR (FLD (f_op_C)), 1);
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ANDSI (GET_H_CR (FLD (f_op_C)), 1);
    CPU (h_cbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asr_L_u6 : asr$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,asr_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SRASI (FLD (f_u6), 1);
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ANDSI (FLD (f_u6), 1);
    CPU (h_cbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_ASR_s_go: asr$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_ASR_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = SRASI (tmp_C, 1);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* lsr_L_r_r $RC: lsr$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,lsr_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SRLSI (GET_H_CR (FLD (f_op_C)), 1);
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ANDSI (GET_H_CR (FLD (f_op_C)), 1);
    CPU (h_cbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* lsr_L_u6 : lsr$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,lsr_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = SRLSI (FLD (f_u6), 1);
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ANDSI (FLD (f_u6), 1);
    CPU (h_cbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_LSR_s_go: lsr$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_LSR_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = SRLSI (tmp_C, 1);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ror_L_r_r $RC: ror$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,ror_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (SRLSI (GET_H_CR (FLD (f_op_C)), 1), SLLSI (GET_H_CR (FLD (f_op_C)), 31));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ANDSI (GET_H_CR (FLD (f_op_C)), 1);
    CPU (h_cbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* ror_L_u6 : ror$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,ror_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (SRLSI (FLD (f_u6), 1), SLLSI (FLD (f_u6), 31));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ANDSI (FLD (f_u6), 1);
    CPU (h_cbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* rrc_L_r_r $RC: rrc$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,rrc_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (SRLSI (GET_H_CR (FLD (f_op_C)), 1), SLLSI (ZEXTBISI (CPU (h_cbit)), 31));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ANDSI (GET_H_CR (FLD (f_op_C)), 1);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* rrc_L_u6 : rrc$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,rrc_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (SRLSI (FLD (f_u6), 1), SLLSI (ZEXTBISI (CPU (h_cbit)), 31));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ANDSI (FLD (f_u6), 1);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sexb_L_r_r $RC: sexb$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sexb_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = EXTQISI ((GET_H_CR (FLD (f_op_C))));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sexb_L_u6 : sexb$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sexb_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = EXTQISI ((FLD (f_u6)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_SEXB_s_go: sexb$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_SEXB_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = EXTQISI ((tmp_C));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* sexw_L_r_r $RC: sexw$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,sexw_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = EXTHISI ((GET_H_CR (FLD (f_op_C))));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* sexw_L_u6 : sexw$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,sexw_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = EXTHISI ((FLD (f_u6)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_SEXW_s_go: sexw$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_SEXW_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = EXTHISI ((tmp_C));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* extb_L_r_r $RC: extb$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,extb_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ZEXTQISI ((GET_H_CR (FLD (f_op_C))));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* extb_L_u6 : extb$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,extb_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ZEXTQISI ((FLD (f_u6)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_EXTB_s_go: extb$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_EXTB_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = ZEXTQISI ((tmp_C));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* extw_L_r_r $RC: extw$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,extw_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ZEXTHISI ((GET_H_CR (FLD (f_op_C))));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* extw_L_u6 : extw$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,extw_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ZEXTHISI ((FLD (f_u6)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_EXTW_s_go: extw$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_EXTW_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = ZEXTHISI ((tmp_C));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* abs_L_r_r $RC: abs$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,abs_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ABSSI (({   SI tmp_res;
  tmp_res = GET_H_CR (FLD (f_op_C));
; tmp_res; }));
if (FLD (f_F)) {
{
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
  {
    BI opval = LTSI ((GET_H_CR (FLD (f_op_C))), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = EQSI (GET_H_CR (FLD (f_op_C)), 0x80000000);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = CPU (h_vbit);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* abs_L_u6 : abs$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,abs_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ABSSI (({   SI tmp_res;
  tmp_res = FLD (f_u6);
; tmp_res; }));
if (FLD (f_F)) {
{
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
  {
    BI opval = LTSI ((FLD (f_u6)), 0);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
  {
    BI opval = EQSI (FLD (f_u6), 0x80000000);
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
  {
    BI opval = CPU (h_vbit);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_ABS_s_go: abs$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_ABS_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = ABSSI (({   SI tmp_res;
  tmp_res = tmp_C;
; tmp_res; }));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* not_L_r_r $RC: not$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,not_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = INVSI (GET_H_CR (FLD (f_op_C)));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* not_L_u6 : not$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,not_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = INVSI (FLD (f_u6));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_NOT_s_go: not$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_NOT_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = INVSI (tmp_C);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* rlc_L_r_r $RC: rlc$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,rlc_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (SLLSI (GET_H_CR (FLD (f_op_C)), 1), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SRLSI (GET_H_CR (FLD (f_op_C)), 31);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* rlc_L_u6 : rlc$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,rlc_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ORSI (SLLSI (FLD (f_u6), 1), CPU (h_cbit));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = SRLSI (FLD (f_u6), 31);
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* I16_GO_NEG_s_go: neg$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_NEG_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = NEGSI (tmp_C);
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* swi: swi */

static SEM_PC
SEM_FN_NAME (arc600f,swi) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
; /*clobber*/
  {
    USI opval = arc_trap (current_cpu, pc, 4, 0);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
 else if (0) {
{
; /*clobber*/
  {
    USI opval = arc_trap (current_cpu, pc, 4, 0);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
; /*clobber*/
  {
    USI opval = arc_trap (current_cpu, pc, 4, 0);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* trap_s: trap$_S $trapnum */

static SEM_PC
SEM_FN_NAME (arc600f,trap_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_trap_s.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (pc, 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
{
  {
    USI opval = arc_trap (current_cpu, pc, 2, FLD (f_trapnum));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
; /*clobber*/
}
}
}
 else if (0) {
{
  {
    USI opval = arc_trap (current_cpu, pc, 2, FLD (f_trapnum));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
; /*clobber*/
}
}
 else {
{
  {
    SI opval = pc;
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
{
  {
    USI opval = arc_trap (current_cpu, pc, 2, FLD (f_trapnum));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
; /*clobber*/
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* brk: brk */

static SEM_PC
SEM_FN_NAME (arc600f,brk) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

arc_breakpoint (current_cpu, pc, 4);

  return vpc;
#undef FLD
}

/* brk_s: brk_s */

static SEM_PC
SEM_FN_NAME (arc600f,brk_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

arc_breakpoint (current_cpu, pc, 2);

  return vpc;
#undef FLD
}

/* asl_L_s12 $RA,: asl$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,asl_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SLLSI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_s12), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_s12), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (32, ANDSI (FLD (f_s12), 31))), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asl_ccu6 $RA,: asl$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,asl_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SLLSI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_u6), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (32, ANDSI (FLD (f_u6), 31))), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asl_L_u6 $RA,: asl$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,asl_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SLLSI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_u6), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (32, ANDSI (FLD (f_u6), 31))), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asl_L_r_r $RA,$RC: asl$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,asl_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SLLSI (GET_H_CR (FLD (f_op_B)), ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (32, ANDSI (GET_H_CR (FLD (f_op_C)), 31))), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asl_cc $RA,$RC: asl$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,asl_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SLLSI (GET_H_CR (FLD (f_op_B)), ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (32, ANDSI (GET_H_CR (FLD (f_op_C)), 31))), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asl_s_cbu3: asl$_S $R_c,$R_b,$u3 */

static SEM_PC
SEM_FN_NAME (arc600f,asl_s_cbu3) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u3);
  {
    SI opval = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SLLSI (tmp_B, ANDSI (tmp_C, 31)));
    SET_H_CR16 (FLD (f_op__c), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* asl_s_ssb: asl$_S $R_b,$R_b,$u5 */

static SEM_PC
SEM_FN_NAME (arc600f,asl_s_ssb) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldb_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u5);
  {
    SI opval = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SLLSI (tmp_B, ANDSI (tmp_C, 31)));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* I16_GO_ASLM_s_go: asl$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_ASLM_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SLLSI (tmp_B, ANDSI (tmp_C, 31)));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* lsr_L_s12 $RA,: lsr$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,lsr_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRLSI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_s12), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_s12), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (FLD (f_s12), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* lsr_ccu6 $RA,: lsr$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,lsr_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRLSI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_u6), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (FLD (f_u6), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* lsr_L_u6 $RA,: lsr$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,lsr_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRLSI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_u6), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (FLD (f_u6), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* lsr_L_r_r $RA,$RC: lsr$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,lsr_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRLSI (GET_H_CR (FLD (f_op_B)), ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* lsr_cc $RA,$RC: lsr$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,lsr_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRLSI (GET_H_CR (FLD (f_op_B)), ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* lsr_s_ssb: lsr$_S $R_b,$R_b,$u5 */

static SEM_PC
SEM_FN_NAME (arc600f,lsr_s_ssb) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldb_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u5);
  {
    SI opval = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRLSI (tmp_B, ANDSI (tmp_C, 31)));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* I16_GO_LSRM_s_go: lsr$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_LSRM_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRLSI (tmp_B, ANDSI (tmp_C, 31)));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* asr_L_s12 $RA,: asr$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,asr_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRASI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_s12), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_s12), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (FLD (f_s12), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asr_ccu6 $RA,: asr$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,asr_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRASI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_u6), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (FLD (f_u6), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asr_L_u6 $RA,: asr$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,asr_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRASI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_u6), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (FLD (f_u6), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asr_L_r_r $RA,$RC: asr$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,asr_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRASI (GET_H_CR (FLD (f_op_B)), ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asr_cc $RA,$RC: asr$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,asr_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRASI (GET_H_CR (FLD (f_op_B)), ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asr_s_cbu3: asr$_S $R_c,$R_b,$u3 */

static SEM_PC
SEM_FN_NAME (arc600f,asr_s_cbu3) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u3);
  {
    SI opval = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRASI (tmp_B, ANDSI (tmp_C, 31)));
    SET_H_CR16 (FLD (f_op__c), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* asr_s_ssb: asr$_S $R_b,$R_b,$u5 */

static SEM_PC
SEM_FN_NAME (arc600f,asr_s_ssb) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_ldb_s_abu.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = FLD (f_u5);
  {
    SI opval = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRASI (tmp_B, ANDSI (tmp_C, 31)));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* I16_GO_ASRM_s_go: asr$_S $R_b,$R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,I16_GO_ASRM_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  SI tmp_B;
  SI tmp_C;
((void) 0); /*nop*/
  tmp_B = GET_H_CR16 (FLD (f_op__b));
  tmp_C = GET_H_CR16 (FLD (f_op__c));
  {
    SI opval = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRASI (tmp_B, ANDSI (tmp_C, 31)));
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* ror_L_s12 $RA,: ror$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,ror_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (RORSI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_s12), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_s12), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (FLD (f_s12), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* ror_ccu6 $RA,: ror$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,ror_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (RORSI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_u6), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (FLD (f_u6), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* ror_L_u6 $RA,: ror$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,ror_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (RORSI (GET_H_CR (FLD (f_op_B)), ANDSI (FLD (f_u6), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (FLD (f_u6), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (FLD (f_u6), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* ror_L_r_r $RA,$RC: ror$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,ror_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (RORSI (GET_H_CR (FLD (f_op_B)), ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* ror_cc $RA,$RC: ror$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,ror_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (RORSI (GET_H_CR (FLD (f_op_B)), ANDSI (GET_H_CR (FLD (f_op_C)), 31)));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ((EQSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 0)) ? (0) : (ANDSI (SRLSI (GET_H_CR (FLD (f_op_B)), SUBSI (ANDSI (GET_H_CR (FLD (f_op_C)), 31), 1)), 1)));
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mul64_L_s12 : mul64$_L$F1 $RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,mul64_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if ((0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (1)) {
{
  DI tmp_result;
  tmp_result = MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_s12)));
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 6);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_result, 16), 1);
    SET_H_CR (((UINT) 58), opval);
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_CR (((UINT) 59), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mul64_ccu6 : mul64$Qcondi$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mul64_ccu6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
((void) 0); /*nop*/
if ((0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (1)) {
{
  DI tmp_result;
  tmp_result = MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_u6)));
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_result, 16), 1);
    SET_H_CR (((UINT) 58), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_CR (((UINT) 59), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mul64_L_u6 : mul64$_L$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mul64_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if ((0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (1)) {
{
  DI tmp_result;
  tmp_result = MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_u6)));
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 6);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_result, 16), 1);
    SET_H_CR (((UINT) 58), opval);
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_CR (((UINT) 59), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mul64_L_r_r $RC: mul64$_L$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mul64_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if ((0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (1)) {
{
  DI tmp_result;
  tmp_result = MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (GET_H_CR (FLD (f_op_C))));
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_result, 16), 1);
    SET_H_CR (((UINT) 58), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_CR (((UINT) 59), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mul64_cc $RC: mul64$Qcondi$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mul64_cc__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
((void) 0); /*nop*/
if ((0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (1)) {
{
  DI tmp_result;
  tmp_result = MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (GET_H_CR (FLD (f_op_C))));
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_result, 16), 1);
    SET_H_CR (((UINT) 58), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_CR (((UINT) 59), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mul64_s_go: mul64$_S $R_b,$R_c */

static SEM_PC
SEM_FN_NAME (arc600f,mul64_s_go) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_s_cbu3.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
((void) 0); /*nop*/
if ((0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (1)) {
{
  DI tmp_result;
  tmp_result = MULDI (EXTSIDI (GET_H_CR16 (FLD (f_op__b))), EXTSIDI (GET_H_CR16 (FLD (f_op__c))));
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 2);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_result, 16), 1);
    SET_H_CR (((UINT) 58), opval);
    written |= (1 << 3);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_CR (((UINT) 59), opval);
    written |= (1 << 4);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mulu64_L_s12 : mulu64$_L$F1 $RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,mulu64_L_s12_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if ((0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (1)) {
{
  DI tmp_result;
  tmp_result = MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (FLD (f_s12)));
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 6);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_result, 16), 1);
    SET_H_CR (((UINT) 58), opval);
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_CR (((UINT) 59), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mulu64_ccu6 : mulu64$Qcondi$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mulu64_ccu6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
((void) 0); /*nop*/
if ((0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (1)) {
{
  DI tmp_result;
  tmp_result = MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (FLD (f_u6)));
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_result, 16), 1);
    SET_H_CR (((UINT) 58), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_CR (((UINT) 59), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mulu64_L_u6 : mulu64$_L$F1 $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mulu64_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if ((0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (1)) {
{
  DI tmp_result;
  tmp_result = MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (FLD (f_u6)));
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 6);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_result, 16), 1);
    SET_H_CR (((UINT) 58), opval);
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_CR (((UINT) 59), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mulu64_L_r_r $RC: mulu64$_L$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mulu64_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_st_abs.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if ((0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (1)) {
{
  DI tmp_result;
  tmp_result = MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (GET_H_CR (FLD (f_op_C))));
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_result, 16), 1);
    SET_H_CR (((UINT) 58), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_CR (((UINT) 59), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mulu64_cc $RC: mulu64$Qcondi$F1 $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mulu64_cc__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
((void) 0); /*nop*/
if ((0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (1)) {
{
  DI tmp_result;
  tmp_result = MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (GET_H_CR (FLD (f_op_C))));
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (SRLDI (tmp_result, 16), 1);
    SET_H_CR (((UINT) 58), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_CR (((UINT) 59), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* adds_L_s12 $RA,: adds$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,adds_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = ADDDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_s12)));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
  {
    BI opval = 0;
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* adds_ccu6 $RA,: adds$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,adds_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = ADDDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_u6)));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
  {
    BI opval = 0;
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* adds_L_u6 $RA,: adds$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,adds_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = ADDDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_u6)));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
  {
    BI opval = 0;
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* adds_L_r_r $RA,$RC: adds$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,adds_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = ADDDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (GET_H_CR (FLD (f_op_C))));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
  {
    BI opval = 0;
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* adds_cc $RA,$RC: adds$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,adds_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = ADDDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (GET_H_CR (FLD (f_op_C))));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
  {
    BI opval = 0;
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* subs_L_s12 $RA,: subs$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,subs_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = SUBDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_s12)));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
  {
    BI opval = 0;
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* subs_ccu6 $RA,: subs$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,subs_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = SUBDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_u6)));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
  {
    BI opval = 0;
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* subs_L_u6 $RA,: subs$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,subs_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = SUBDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (FLD (f_u6)));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
  {
    BI opval = 0;
    CPU (h_cbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* subs_L_r_r $RA,$RC: subs$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,subs_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = SUBDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (GET_H_CR (FLD (f_op_C))));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
  {
    BI opval = 0;
    CPU (h_cbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* subs_cc $RA,$RC: subs$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,subs_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = SUBDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (GET_H_CR (FLD (f_op_C))));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
  {
    BI opval = 0;
    CPU (h_cbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* divaw_L_s12 $RA,: divaw$_L$F0 $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,divaw_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   USI tmp_tmp;
  tmp_tmp = SLLSI (GET_H_CR (FLD (f_op_B)), 1);
; ((EQSI (ANDSI (SUBSI (tmp_tmp, FLD (f_s12)), 0x80000000), 0)) ? (ADDSI (SUBSI (tmp_tmp, FLD (f_s12)), 1)) : (tmp_tmp)); }));
if (FLD (f_F)) {
((void) 0); /*nop*/
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* divaw_ccu6 $RA,: divaw$Qcondi$F0 $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,divaw_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   USI tmp_tmp;
  tmp_tmp = SLLSI (GET_H_CR (FLD (f_op_B)), 1);
; ((EQSI (ANDSI (SUBSI (tmp_tmp, FLD (f_u6)), 0x80000000), 0)) ? (ADDSI (SUBSI (tmp_tmp, FLD (f_u6)), 1)) : (tmp_tmp)); }));
if (FLD (f_F)) {
((void) 0); /*nop*/
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* divaw_L_u6 $RA,: divaw$_L$F0 $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,divaw_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   USI tmp_tmp;
  tmp_tmp = SLLSI (GET_H_CR (FLD (f_op_B)), 1);
; ((EQSI (ANDSI (SUBSI (tmp_tmp, FLD (f_u6)), 0x80000000), 0)) ? (ADDSI (SUBSI (tmp_tmp, FLD (f_u6)), 1)) : (tmp_tmp)); }));
if (FLD (f_F)) {
((void) 0); /*nop*/
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* divaw_L_r_r $RA,$RC: divaw$_L$F0 $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,divaw_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   USI tmp_tmp;
  tmp_tmp = SLLSI (GET_H_CR (FLD (f_op_B)), 1);
; ((EQSI (ANDSI (SUBSI (tmp_tmp, GET_H_CR (FLD (f_op_C))), 0x80000000), 0)) ? (ADDSI (SUBSI (tmp_tmp, GET_H_CR (FLD (f_op_C))), 1)) : (tmp_tmp)); }));
if (FLD (f_F)) {
((void) 0); /*nop*/
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* divaw_cc $RA,$RC: divaw$Qcondi$F0 $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,divaw_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   USI tmp_tmp;
  tmp_tmp = SLLSI (GET_H_CR (FLD (f_op_B)), 1);
; ((EQSI (ANDSI (SUBSI (tmp_tmp, GET_H_CR (FLD (f_op_C))), 0x80000000), 0)) ? (ADDSI (SUBSI (tmp_tmp, GET_H_CR (FLD (f_op_C))), 1)) : (tmp_tmp)); }));
if (FLD (f_F)) {
((void) 0); /*nop*/
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asls_L_s12 $RA,: asls$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,asls_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_b;
  tmp_b = EXTSIDI (GET_H_CR (FLD (f_op_B)));
;   tmp_b = (EQDI (tmp_b, 0)) ? (0) : (GTSI ((FLD (f_s12)), 31)) ? (SLLDI (tmp_b, 31)) : (LTSI ((FLD (f_s12)), -31)) ? (SRADI (tmp_b, 31)) : (GESI ((FLD (f_s12)), 0)) ? (SLLDI (tmp_b, (FLD (f_s12)))) : (SRASI (GET_H_CR (FLD (f_op_B)), NEGSI ((FLD (f_s12)))));
; ((GTDI (tmp_b, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_b, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_b)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asls_ccu6 $RA,: asls$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,asls_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_b;
  tmp_b = EXTSIDI (GET_H_CR (FLD (f_op_B)));
;   tmp_b = (EQDI (tmp_b, 0)) ? (0) : (GTSI ((FLD (f_u6)), 31)) ? (SLLDI (tmp_b, 31)) : (LTSI ((FLD (f_u6)), -31)) ? (SRADI (tmp_b, 31)) : (GESI ((FLD (f_u6)), 0)) ? (SLLDI (tmp_b, (FLD (f_u6)))) : (SRASI (GET_H_CR (FLD (f_op_B)), NEGSI ((FLD (f_u6)))));
; ((GTDI (tmp_b, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_b, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_b)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asls_L_u6 $RA,: asls$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,asls_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_b;
  tmp_b = EXTSIDI (GET_H_CR (FLD (f_op_B)));
;   tmp_b = (EQDI (tmp_b, 0)) ? (0) : (GTSI ((FLD (f_u6)), 31)) ? (SLLDI (tmp_b, 31)) : (LTSI ((FLD (f_u6)), -31)) ? (SRADI (tmp_b, 31)) : (GESI ((FLD (f_u6)), 0)) ? (SLLDI (tmp_b, (FLD (f_u6)))) : (SRASI (GET_H_CR (FLD (f_op_B)), NEGSI ((FLD (f_u6)))));
; ((GTDI (tmp_b, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_b, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_b)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asls_L_r_r $RA,$RC: asls$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,asls_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_b;
  tmp_b = EXTSIDI (GET_H_CR (FLD (f_op_B)));
;   tmp_b = (EQDI (tmp_b, 0)) ? (0) : (GTSI ((GET_H_CR (FLD (f_op_C))), 31)) ? (SLLDI (tmp_b, 31)) : (LTSI ((GET_H_CR (FLD (f_op_C))), -31)) ? (SRADI (tmp_b, 31)) : (GESI ((GET_H_CR (FLD (f_op_C))), 0)) ? (SLLDI (tmp_b, (GET_H_CR (FLD (f_op_C))))) : (SRASI (GET_H_CR (FLD (f_op_B)), NEGSI ((GET_H_CR (FLD (f_op_C))))));
; ((GTDI (tmp_b, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_b, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_b)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asls_cc $RA,$RC: asls$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,asls_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_b;
  tmp_b = EXTSIDI (GET_H_CR (FLD (f_op_B)));
;   tmp_b = (EQDI (tmp_b, 0)) ? (0) : (GTSI ((GET_H_CR (FLD (f_op_C))), 31)) ? (SLLDI (tmp_b, 31)) : (LTSI ((GET_H_CR (FLD (f_op_C))), -31)) ? (SRADI (tmp_b, 31)) : (GESI ((GET_H_CR (FLD (f_op_C))), 0)) ? (SLLDI (tmp_b, (GET_H_CR (FLD (f_op_C))))) : (SRASI (GET_H_CR (FLD (f_op_B)), NEGSI ((GET_H_CR (FLD (f_op_C))))));
; ((GTDI (tmp_b, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_b, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_b)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asrs_L_s12 $RA,: asrs$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,asrs_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_b;
  tmp_b = EXTSIDI (GET_H_CR (FLD (f_op_B)));
;   tmp_b = (EQDI (tmp_b, 0)) ? (0) : (GTSI ((FLD (f_s12)), 31)) ? (SRADI (tmp_b, 31)) : (LTSI ((FLD (f_s12)), -31)) ? (SLLDI (tmp_b, 31)) : (GESI ((FLD (f_s12)), 0)) ? (SRADI (tmp_b, (FLD (f_s12)))) : (SLLSI (GET_H_CR (FLD (f_op_B)), NEGSI ((FLD (f_s12)))));
; ((GTDI (tmp_b, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_b, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_b)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asrs_ccu6 $RA,: asrs$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,asrs_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_b;
  tmp_b = EXTSIDI (GET_H_CR (FLD (f_op_B)));
;   tmp_b = (EQDI (tmp_b, 0)) ? (0) : (GTSI ((FLD (f_u6)), 31)) ? (SRADI (tmp_b, 31)) : (LTSI ((FLD (f_u6)), -31)) ? (SLLDI (tmp_b, 31)) : (GESI ((FLD (f_u6)), 0)) ? (SRADI (tmp_b, (FLD (f_u6)))) : (SLLSI (GET_H_CR (FLD (f_op_B)), NEGSI ((FLD (f_u6)))));
; ((GTDI (tmp_b, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_b, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_b)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asrs_L_u6 $RA,: asrs$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,asrs_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_b;
  tmp_b = EXTSIDI (GET_H_CR (FLD (f_op_B)));
;   tmp_b = (EQDI (tmp_b, 0)) ? (0) : (GTSI ((FLD (f_u6)), 31)) ? (SRADI (tmp_b, 31)) : (LTSI ((FLD (f_u6)), -31)) ? (SLLDI (tmp_b, 31)) : (GESI ((FLD (f_u6)), 0)) ? (SRADI (tmp_b, (FLD (f_u6)))) : (SLLSI (GET_H_CR (FLD (f_op_B)), NEGSI ((FLD (f_u6)))));
; ((GTDI (tmp_b, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_b, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_b)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asrs_L_r_r $RA,$RC: asrs$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,asrs_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_b;
  tmp_b = EXTSIDI (GET_H_CR (FLD (f_op_B)));
;   tmp_b = (EQDI (tmp_b, 0)) ? (0) : (GTSI ((GET_H_CR (FLD (f_op_C))), 31)) ? (SRADI (tmp_b, 31)) : (LTSI ((GET_H_CR (FLD (f_op_C))), -31)) ? (SLLDI (tmp_b, 31)) : (GESI ((GET_H_CR (FLD (f_op_C))), 0)) ? (SRADI (tmp_b, (GET_H_CR (FLD (f_op_C))))) : (SLLSI (GET_H_CR (FLD (f_op_B)), NEGSI ((GET_H_CR (FLD (f_op_C))))));
; ((GTDI (tmp_b, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_b, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_b)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* asrs_cc $RA,$RC: asrs$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,asrs_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_b;
  tmp_b = EXTSIDI (GET_H_CR (FLD (f_op_B)));
;   tmp_b = (EQDI (tmp_b, 0)) ? (0) : (GTSI ((GET_H_CR (FLD (f_op_C))), 31)) ? (SRADI (tmp_b, 31)) : (LTSI ((GET_H_CR (FLD (f_op_C))), -31)) ? (SLLDI (tmp_b, 31)) : (GESI ((GET_H_CR (FLD (f_op_C))), 0)) ? (SRADI (tmp_b, (GET_H_CR (FLD (f_op_C))))) : (SLLSI (GET_H_CR (FLD (f_op_B)), NEGSI ((GET_H_CR (FLD (f_op_C))))));
; ((GTDI (tmp_b, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_b, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_b)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* addsdw_L_s12 $RA,: addsdw$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,addsdw_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_C_SI;
  HI tmp_res1;
  HI tmp_res2;
  tmp_res2 = ({   SI tmp_tmp;
  tmp_tmp = ADDHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 1), SUBWORDSIHI ((FLD (f_s12)), 1));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
;   tmp_cur_s2bit = tmp_cur_s1bit;
;   tmp_res1 = ({   SI tmp_tmp;
  tmp_tmp = ADDHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 0), SUBWORDSIHI ((FLD (f_s12)), 0));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
; ORHI (SLLHI (tmp_res1, 16), tmp_res2); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ORBI (tmp_cur_s1bit, tmp_cur_s2bit);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
}
if (tmp_cur_s2bit) {
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* addsdw_ccu6 $RA,: addsdw$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,addsdw_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_C_SI;
  HI tmp_res1;
  HI tmp_res2;
  tmp_res2 = ({   SI tmp_tmp;
  tmp_tmp = ADDHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 1), SUBWORDSIHI ((FLD (f_u6)), 1));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
;   tmp_cur_s2bit = tmp_cur_s1bit;
;   tmp_res1 = ({   SI tmp_tmp;
  tmp_tmp = ADDHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 0), SUBWORDSIHI ((FLD (f_u6)), 0));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
; ORHI (SLLHI (tmp_res1, 16), tmp_res2); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ORBI (tmp_cur_s1bit, tmp_cur_s2bit);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
}
if (tmp_cur_s2bit) {
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* addsdw_L_u6 $RA,: addsdw$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,addsdw_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_C_SI;
  HI tmp_res1;
  HI tmp_res2;
  tmp_res2 = ({   SI tmp_tmp;
  tmp_tmp = ADDHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 1), SUBWORDSIHI ((FLD (f_u6)), 1));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
;   tmp_cur_s2bit = tmp_cur_s1bit;
;   tmp_res1 = ({   SI tmp_tmp;
  tmp_tmp = ADDHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 0), SUBWORDSIHI ((FLD (f_u6)), 0));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
; ORHI (SLLHI (tmp_res1, 16), tmp_res2); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ORBI (tmp_cur_s1bit, tmp_cur_s2bit);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
}
if (tmp_cur_s2bit) {
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* addsdw_L_r_r $RA,$RC: addsdw$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,addsdw_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_C_SI;
  HI tmp_res1;
  HI tmp_res2;
  tmp_res2 = ({   SI tmp_tmp;
  tmp_tmp = ADDHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 1), SUBWORDSIHI ((GET_H_CR (FLD (f_op_C))), 1));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
;   tmp_cur_s2bit = tmp_cur_s1bit;
;   tmp_res1 = ({   SI tmp_tmp;
  tmp_tmp = ADDHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 0), SUBWORDSIHI ((GET_H_CR (FLD (f_op_C))), 0));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
; ORHI (SLLHI (tmp_res1, 16), tmp_res2); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ORBI (tmp_cur_s1bit, tmp_cur_s2bit);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
}
if (tmp_cur_s2bit) {
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* addsdw_cc $RA,$RC: addsdw$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,addsdw_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_C_SI;
  HI tmp_res1;
  HI tmp_res2;
  tmp_res2 = ({   SI tmp_tmp;
  tmp_tmp = ADDHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 1), SUBWORDSIHI ((GET_H_CR (FLD (f_op_C))), 1));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
;   tmp_cur_s2bit = tmp_cur_s1bit;
;   tmp_res1 = ({   SI tmp_tmp;
  tmp_tmp = ADDHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 0), SUBWORDSIHI ((GET_H_CR (FLD (f_op_C))), 0));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
; ORHI (SLLHI (tmp_res1, 16), tmp_res2); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ORBI (tmp_cur_s1bit, tmp_cur_s2bit);
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
}
if (tmp_cur_s2bit) {
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* subsdw_L_s12 $RA,: subsdw$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,subsdw_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_C_SI;
  HI tmp_res1;
  HI tmp_res2;
  tmp_res2 = ({   SI tmp_tmp;
  tmp_tmp = SUBHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 1), SUBWORDSIHI ((FLD (f_s12)), 1));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
;   tmp_cur_s2bit = tmp_cur_s1bit;
;   tmp_res1 = ({   SI tmp_tmp;
  tmp_tmp = SUBHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 0), SUBWORDSIHI ((FLD (f_s12)), 0));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
; ORHI (SLLHI (tmp_res1, 16), tmp_res2); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ORBI (tmp_cur_s1bit, tmp_cur_s2bit);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
}
if (tmp_cur_s2bit) {
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* subsdw_ccu6 $RA,: subsdw$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,subsdw_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_C_SI;
  HI tmp_res1;
  HI tmp_res2;
  tmp_res2 = ({   SI tmp_tmp;
  tmp_tmp = SUBHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 1), SUBWORDSIHI ((FLD (f_u6)), 1));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
;   tmp_cur_s2bit = tmp_cur_s1bit;
;   tmp_res1 = ({   SI tmp_tmp;
  tmp_tmp = SUBHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 0), SUBWORDSIHI ((FLD (f_u6)), 0));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
; ORHI (SLLHI (tmp_res1, 16), tmp_res2); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ORBI (tmp_cur_s1bit, tmp_cur_s2bit);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
}
if (tmp_cur_s2bit) {
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* subsdw_L_u6 $RA,: subsdw$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,subsdw_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_C_SI;
  HI tmp_res1;
  HI tmp_res2;
  tmp_res2 = ({   SI tmp_tmp;
  tmp_tmp = SUBHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 1), SUBWORDSIHI ((FLD (f_u6)), 1));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
;   tmp_cur_s2bit = tmp_cur_s1bit;
;   tmp_res1 = ({   SI tmp_tmp;
  tmp_tmp = SUBHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 0), SUBWORDSIHI ((FLD (f_u6)), 0));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
; ORHI (SLLHI (tmp_res1, 16), tmp_res2); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ORBI (tmp_cur_s1bit, tmp_cur_s2bit);
    CPU (h_vbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
}
if (tmp_cur_s2bit) {
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* subsdw_L_r_r $RA,$RC: subsdw$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,subsdw_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_C_SI;
  HI tmp_res1;
  HI tmp_res2;
  tmp_res2 = ({   SI tmp_tmp;
  tmp_tmp = SUBHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 1), SUBWORDSIHI ((GET_H_CR (FLD (f_op_C))), 1));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
;   tmp_cur_s2bit = tmp_cur_s1bit;
;   tmp_res1 = ({   SI tmp_tmp;
  tmp_tmp = SUBHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 0), SUBWORDSIHI ((GET_H_CR (FLD (f_op_C))), 0));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
; ORHI (SLLHI (tmp_res1, 16), tmp_res2); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ORBI (tmp_cur_s1bit, tmp_cur_s2bit);
    CPU (h_vbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
}
if (tmp_cur_s2bit) {
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* subsdw_cc $RA,$RC: subsdw$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,subsdw_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_C_SI;
  HI tmp_res1;
  HI tmp_res2;
  tmp_res2 = ({   SI tmp_tmp;
  tmp_tmp = SUBHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 1), SUBWORDSIHI ((GET_H_CR (FLD (f_op_C))), 1));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
;   tmp_cur_s2bit = tmp_cur_s1bit;
;   tmp_res1 = ({   SI tmp_tmp;
  tmp_tmp = SUBHI (SUBWORDSIHI (GET_H_CR (FLD (f_op_B)), 0), SUBWORDSIHI ((GET_H_CR (FLD (f_op_C))), 0));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); });
; ORHI (SLLHI (tmp_res1, 16), tmp_res2); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = ORBI (tmp_cur_s1bit, tmp_cur_s2bit);
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
}
if (tmp_cur_s2bit) {
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* swap_L_r_r $RC: swap$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,swap_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (RORSI (GET_H_CR (FLD (f_op_C)), 16));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* swap_L_u6 : swap$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,swap_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (RORSI (FLD (f_u6), 16));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* norm_L_r_r $RC: norm$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,norm_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_val;
  SI tmp_bits;
  tmp_val = ((GESI ((GET_H_CR (FLD (f_op_C))), 0)) ? ((GET_H_CR (FLD (f_op_C)))) : (INVSI ((GET_H_CR (FLD (f_op_C))))));
;   tmp_bits = 31;
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 4), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 4));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 4));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 3), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 3));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 3));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 2), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 2));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 2));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 1), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 1));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 1));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 0), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 0));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 0));
}
; tmp_bits; }));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (GET_H_CR (FLD (f_op_C)), 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* norm_L_u6 : norm$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,norm_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_val;
  SI tmp_bits;
  tmp_val = ((GESI ((FLD (f_u6)), 0)) ? ((FLD (f_u6))) : (INVSI ((FLD (f_u6)))));
;   tmp_bits = 31;
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 4), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 4));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 4));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 3), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 3));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 3));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 2), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 2));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 2));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 1), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 1));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 1));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 0), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 0));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 0));
}
; tmp_bits; }));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (FLD (f_u6), 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (FLD (f_u6), 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* rnd16_L_r_r $RC: rnd16$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,rnd16_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRLSI (({   DI tmp_tmp;
  tmp_tmp = ADDDI (EXTSIDI (32768), EXTSIDI (GET_H_CR (FLD (f_op_C))));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }), 16));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* rnd16_L_u6 : rnd16$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,rnd16_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (SRLSI (({   DI tmp_tmp;
  tmp_tmp = ADDDI (EXTSIDI (32768), EXTSIDI (FLD (f_u6)));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }), 16));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* abssw_L_r_r $RC: abssw$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,abssw_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_tmp;
  tmp_tmp = ABSSI (EXTHISI ((GET_H_CR (FLD (f_op_C)))));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* abssw_L_u6 : abssw$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,abssw_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_tmp;
  tmp_tmp = ABSSI (EXTHISI ((FLD (f_u6))));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* abss_L_r_r $RC: abss$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,abss_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (((GESI ((GET_H_CR (FLD (f_op_C))), 0)) ? (GET_H_CR (FLD (f_op_C))) : (({   DI tmp_tmp;
  tmp_tmp = SUBDI (EXTSIDI (0), EXTSIDI (GET_H_CR (FLD (f_op_C))));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }))));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* abss_L_u6 : abss$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,abss_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (((GESI ((FLD (f_u6)), 0)) ? (FLD (f_u6)) : (({   DI tmp_tmp;
  tmp_tmp = SUBDI (EXTSIDI (0), EXTSIDI (FLD (f_u6)));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }))));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* negsw_L_r_r $RC: negsw$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,negsw_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_tmp;
  tmp_tmp = EXTHISI ((GET_H_CR (FLD (f_op_C))));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* negsw_L_u6 : negsw$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,negsw_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_tmp;
  tmp_tmp = EXTHISI ((FLD (f_u6)));
; (GTSI (tmp_tmp, 32767)) ? (  tmp_cur_s1bit = 1, 32767) : (LTSI (tmp_tmp, -32768)) ? (  tmp_cur_s1bit = 1, -32768) : (tmp_tmp); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* negs_L_r_r $RC: negs$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,negs_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = SUBDI (EXTSIDI (0), EXTSIDI (GET_H_CR (FLD (f_op_C))));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* negs_L_u6 : negs$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,negs_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   DI tmp_tmp;
  tmp_tmp = SUBDI (EXTSIDI (0), EXTSIDI (FLD (f_u6)));
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); }));
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* normw_L_r_r $RC: normw$_L$F $RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,normw_L_r_r__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_C), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_C), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_val;
  SI tmp_bits;
  tmp_val = ((GESI (ORSI (SLLSI (GET_H_CR (FLD (f_op_C)), 16), ANDSI (GET_H_CR (FLD (f_op_C)), 65535)), 0)) ? (ORSI (SLLSI (GET_H_CR (FLD (f_op_C)), 16), ANDSI (GET_H_CR (FLD (f_op_C)), 65535))) : (INVSI (ORSI (SLLSI (GET_H_CR (FLD (f_op_C)), 16), ANDSI (GET_H_CR (FLD (f_op_C)), 65535)))));
;   tmp_bits = 31;
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 4), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 4));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 4));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 3), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 3));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 3));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 2), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 2));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 2));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 1), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 1));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 1));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 0), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 0));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 0));
}
; tmp_bits; }));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* normw_L_u6 : normw$_L$F $RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,normw_L_u6_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (({   SI tmp_val;
  SI tmp_bits;
  tmp_val = ((GESI (ORSI (SLLSI (FLD (f_u6), 16), ANDSI (FLD (f_u6), 65535)), 0)) ? (ORSI (SLLSI (FLD (f_u6), 16), ANDSI (FLD (f_u6), 65535))) : (INVSI (ORSI (SLLSI (FLD (f_u6), 16), ANDSI (FLD (f_u6), 65535)))));
;   tmp_bits = 31;
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 4), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 4));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 4));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 3), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 3));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 3));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 2), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 2));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 2));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 1), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 1));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 1));
}
; if (GESI (tmp_val, SLLSI (1, SUBSI (SLLSI (1, 0), 1)))) {
  tmp_val = SRLSI (tmp_val, SLLSI (1, 0));
  tmp_bits = SUBSI (tmp_bits, SLLSI (1, 0));
}
; tmp_bits; }));
if (FLD (f_F)) {
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 7);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* nop_s: nop_s */

static SEM_PC
SEM_FN_NAME (arc600f,nop_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

((void) 0); /*nop*/

  return vpc;
#undef FLD
}

/* unimp_s: unimp_s */

static SEM_PC
SEM_FN_NAME (arc600f,unimp_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

cgen_rtx_error (current_cpu, "invalid insn");

  return vpc;
#undef FLD
}

/* pop_s_b: pop$_S $R_b */

static SEM_PC
SEM_FN_NAME (arc600f,pop_s_b) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_mov_s_r_u7.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  {
    SI opval = GETMEMSI (current_cpu, pc, GET_H_SP ());
    SET_H_CR16 (FLD (f_op__b), opval);
    TRACE_RESULT (current_cpu, abuf, "cr16", 'x', opval);
  }
  {
    SI opval = ADDSI (GET_H_SP (), 4);
    SET_H_SP (, opval);
    TRACE_RESULT (current_cpu, abuf, "sp", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* pop_s_blink: pop$_S $R31 */

static SEM_PC
SEM_FN_NAME (arc600f,pop_s_blink) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  {
    SI opval = GETMEMSI (current_cpu, pc, GET_H_SP ());
    SET_H_R31 (, opval);
    TRACE_RESULT (current_cpu, abuf, "r31", 'x', opval);
  }
  {
    SI opval = ADDSI (GET_H_SP (), 4);
    SET_H_SP (, opval);
    TRACE_RESULT (current_cpu, abuf, "sp", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* push_s_b: push$_S $R_b */

static SEM_PC
SEM_FN_NAME (arc600f,push_s_b) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_mov_s_r_u7.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  {
    SI opval = ADDSI (GET_H_SP (), -4);
    SET_H_SP (, opval);
    TRACE_RESULT (current_cpu, abuf, "sp", 'x', opval);
  }
  {
    SI opval = GET_H_CR16 (FLD (f_op__b));
    SETMEMSI (current_cpu, pc, GET_H_SP (), opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* push_s_blink: push$_S $R31 */

static SEM_PC
SEM_FN_NAME (arc600f,push_s_blink) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  {
    SI opval = ADDSI (GET_H_SP (), -4);
    SET_H_SP (, opval);
    TRACE_RESULT (current_cpu, abuf, "sp", 'x', opval);
  }
  {
    SI opval = GET_H_R31 ();
    SETMEMSI (current_cpu, pc, GET_H_SP (), opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* mullw_L_s12 $RA,: mullw$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,mullw_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_tmp;
  tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (FLD (f_s12), 65535))));
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mullw_ccu6 $RA,: mullw$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mullw_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ({   DI tmp_tmp;
  tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (FLD (f_u6), 65535))));
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mullw_L_u6 $RA,: mullw$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mullw_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_tmp;
  tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (FLD (f_u6), 65535))));
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mullw_L_r_r $RA,$RC: mullw$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mullw_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_tmp;
  tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (GET_H_CR (FLD (f_op_C)), 65535))));
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mullw_cc $RA,$RC: mullw$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mullw_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ({   DI tmp_tmp;
  tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (GET_H_CR (FLD (f_op_C)), 65535))));
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* maclw_L_s12 $RA,: maclw$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,maclw_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  SI tmp_SItmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (FLD (f_s12), 65535))));
;   {
    BI opval = NOTDI (SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   {
    BI opval = ANDBI (CPU (h_vbit), SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
; if (NEBI (CPU (h_vbit), 0)) {
  tmp_tmp = XORDI (SRADI (tmp_old, 63), SRLSI (-1, 1));
}
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   tmp_SItmp = ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp));
;   tmp_cur_s1bit = ORBI (tmp_cur_s1bit, CPU (h_vbit));
; tmp_SItmp; });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* maclw_ccu6 $RA,: maclw$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,maclw_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  SI tmp_SItmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (FLD (f_u6), 65535))));
;   {
    BI opval = NOTDI (SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   {
    BI opval = ANDBI (CPU (h_vbit), SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
; if (NEBI (CPU (h_vbit), 0)) {
  tmp_tmp = XORDI (SRADI (tmp_old, 63), SRLSI (-1, 1));
}
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   tmp_SItmp = ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp));
;   tmp_cur_s1bit = ORBI (tmp_cur_s1bit, CPU (h_vbit));
; tmp_SItmp; });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* maclw_L_u6 $RA,: maclw$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,maclw_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  SI tmp_SItmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (FLD (f_u6), 65535))));
;   {
    BI opval = NOTDI (SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   {
    BI opval = ANDBI (CPU (h_vbit), SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
; if (NEBI (CPU (h_vbit), 0)) {
  tmp_tmp = XORDI (SRADI (tmp_old, 63), SRLSI (-1, 1));
}
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   tmp_SItmp = ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp));
;   tmp_cur_s1bit = ORBI (tmp_cur_s1bit, CPU (h_vbit));
; tmp_SItmp; });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* maclw_L_r_r $RA,$RC: maclw$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,maclw_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  SI tmp_SItmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (GET_H_CR (FLD (f_op_C)), 65535))));
;   {
    BI opval = NOTDI (SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   {
    BI opval = ANDBI (CPU (h_vbit), SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
; if (NEBI (CPU (h_vbit), 0)) {
  tmp_tmp = XORDI (SRADI (tmp_old, 63), SRLSI (-1, 1));
}
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   tmp_SItmp = ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp));
;   tmp_cur_s1bit = ORBI (tmp_cur_s1bit, CPU (h_vbit));
; tmp_SItmp; });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* maclw_cc $RA,$RC: maclw$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,maclw_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  SI tmp_SItmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (GET_H_CR (FLD (f_op_C)), 65535))));
;   {
    BI opval = NOTDI (SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   {
    BI opval = ANDBI (CPU (h_vbit), SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
; if (NEBI (CPU (h_vbit), 0)) {
  tmp_tmp = XORDI (SRADI (tmp_old, 63), SRLSI (-1, 1));
}
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   tmp_SItmp = ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp));
;   tmp_cur_s1bit = ORBI (tmp_cur_s1bit, CPU (h_vbit));
; tmp_SItmp; });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* machlw_L_s12 $RA,: machlw$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,machlw_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (FLD (f_s12), -65536))));
;   {
    BI opval = NOTDI (SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   tmp_cur_s1bit = ANDBI (CPU (h_vbit), XORDI (tmp_old, tmp_tmp));
; if (tmp_cur_s1bit) {
  tmp_tmp = XORDI (SRADI (tmp_old, 63), SRLSI (-1, 1));
}
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; SUBWORDDISI (tmp_tmp, 0); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* machlw_ccu6 $RA,: machlw$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,machlw_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (FLD (f_u6), -65536))));
;   {
    BI opval = NOTDI (SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   tmp_cur_s1bit = ANDBI (CPU (h_vbit), XORDI (tmp_old, tmp_tmp));
; if (tmp_cur_s1bit) {
  tmp_tmp = XORDI (SRADI (tmp_old, 63), SRLSI (-1, 1));
}
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; SUBWORDDISI (tmp_tmp, 0); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* machlw_L_u6 $RA,: machlw$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,machlw_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (FLD (f_u6), -65536))));
;   {
    BI opval = NOTDI (SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   tmp_cur_s1bit = ANDBI (CPU (h_vbit), XORDI (tmp_old, tmp_tmp));
; if (tmp_cur_s1bit) {
  tmp_tmp = XORDI (SRADI (tmp_old, 63), SRLSI (-1, 1));
}
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; SUBWORDDISI (tmp_tmp, 0); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* machlw_L_r_r $RA,$RC: machlw$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,machlw_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (GET_H_CR (FLD (f_op_C)), -65536))));
;   {
    BI opval = NOTDI (SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   tmp_cur_s1bit = ANDBI (CPU (h_vbit), XORDI (tmp_old, tmp_tmp));
; if (tmp_cur_s1bit) {
  tmp_tmp = XORDI (SRADI (tmp_old, 63), SRLSI (-1, 1));
}
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; SUBWORDDISI (tmp_tmp, 0); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* machlw_cc $RA,$RC: machlw$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,machlw_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (EXTSIDI (GET_H_CR (FLD (f_op_B))), EXTSIDI (ANDSI (GET_H_CR (FLD (f_op_C)), -65536))));
;   {
    BI opval = NOTDI (SRLDI (XORDI (tmp_old, tmp_tmp), 63));
    CPU (h_vbit) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   tmp_cur_s1bit = ANDBI (CPU (h_vbit), XORDI (tmp_old, tmp_tmp));
; if (tmp_cur_s1bit) {
  tmp_tmp = XORDI (SRADI (tmp_old, 63), SRLSI (-1, 1));
}
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; SUBWORDDISI (tmp_tmp, 0); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mululw_L_s12 $RA,: mululw$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,mululw_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_tmp;
  tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (ANDSI (FLD (f_s12), 65535))));
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mululw_ccu6 $RA,: mululw$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mululw_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ({   DI tmp_tmp;
  tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (ANDSI (FLD (f_u6), 65535))));
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 8);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mululw_L_u6 $RA,: mululw$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,mululw_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_tmp;
  tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (ANDSI (FLD (f_u6), 65535))));
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mululw_L_r_r $RA,$RC: mululw$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mululw_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_tmp;
  tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (ANDSI (GET_H_CR (FLD (f_op_C)), 65535))));
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* mululw_cc $RA,$RC: mululw$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,mululw_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ({   DI tmp_tmp;
  tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (ANDSI (GET_H_CR (FLD (f_op_C)), 65535))));
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; ((GTDI (tmp_tmp, 2147483647)) ? (  tmp_cur_s1bit = 1, 2147483647) : (LTDI (tmp_tmp, ADDSI (-2147483647, -1))) ? (  tmp_cur_s1bit = 1, ADDSI (-2147483647, -1)) : (  tmp_cur_s1bit = 0, tmp_tmp)); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 9);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* machulw_L_s12 $RA,: machulw$_L$F $RB,$RB,$s12 */

static SEM_PC
SEM_FN_NAME (arc600f,machulw_L_s12__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_s12__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (ANDSI (FLD (f_s12), -65536))));
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   tmp_cur_s1bit = (GTUDI (tmp_old, tmp_tmp)) ? ((  tmp_tmp = -1, 1)) : (0);
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; SUBWORDDISI (tmp_tmp, 0); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* machulw_ccu6 $RA,: machulw$Qcondi$F $RB,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,machulw_ccu6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_ccu6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (ANDSI (FLD (f_u6), -65536))));
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   tmp_cur_s1bit = (GTUDI (tmp_old, tmp_tmp)) ? ((  tmp_tmp = -1, 1)) : (0);
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; SUBWORDDISI (tmp_tmp, 0); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 10);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* machulw_L_u6 $RA,: machulw$_L$F $RA,$RB,$U6 */

static SEM_PC
SEM_FN_NAME (arc600f,machulw_L_u6__RA_) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_u6__RA_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (EQSI (FLD (f_op_B), 62)) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (EQSI (FLD (f_op_B), 63)) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (ANDSI (FLD (f_u6), -65536))));
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   tmp_cur_s1bit = (GTUDI (tmp_old, tmp_tmp)) ? ((  tmp_tmp = -1, 1)) : (0);
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; SUBWORDDISI (tmp_tmp, 0); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* machulw_L_r_r $RA,$RC: machulw$_L$F $RA,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,machulw_L_r_r__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_add_L_r_r__RA__RC.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (ANDSI (GET_H_CR (FLD (f_op_C)), -65536))));
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   tmp_cur_s1bit = (GTUDI (tmp_old, tmp_tmp)) ? ((  tmp_tmp = -1, 1)) : (0);
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; SUBWORDDISI (tmp_tmp, 0); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_A), opval);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* machulw_cc $RA,$RC: machulw$Qcondi$F $RB,$RB,$RC */

static SEM_PC
SEM_FN_NAME (arc600f,machulw_cc__RA__RC) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_j_cc___RC_noilink_.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
if (ORBI (EQSI (FLD (f_op_B), 62), EQSI (FLD (f_op_C), 62))) {
{
  HI tmp_high;
  HI tmp_low;
  tmp_high = GETMEMHI (current_cpu, pc, ADDSI (pc, 4));
  tmp_low = GETMEMHI (current_cpu, pc, ADDSI (pc, ADDSI (4, 2)));
CPU (h_cr[((UINT) 62)]) = ORSI (SLLSI (ZEXTHISI (tmp_high), 16), ZEXTHISI (tmp_low));
}
}
if (ORBI (EQSI (FLD (f_op_B), 63), EQSI (FLD (f_op_C), 63))) {
CPU (h_cr[((UINT) 63)]) = ANDSI (pc, -4);
}
}
if (GET_H_QCONDB (FLD (f_cond_Q))) {
{
  SI tmp_result;
  BI tmp_cur_s1bit;
  BI tmp_cur_s2bit;
((void) 0); /*nop*/
  tmp_result = ({   DI tmp_old;
  DI tmp_tmp;
  tmp_old = ADDDI (SLLDI (ZEXTSIDI (GET_H_CR (((UINT) 56))), 32), ZEXTSIDI (GET_H_CR (((UINT) 57))));
;   tmp_tmp = (0) ? ((cgen_rtx_error (current_cpu, "invalid insn"), 0)) : (MULDI (ZEXTSIDI (GET_H_CR (FLD (f_op_B))), ZEXTSIDI (ANDSI (GET_H_CR (FLD (f_op_C)), -65536))));
;   tmp_tmp = ADDDI (tmp_old, tmp_tmp);
;   tmp_cur_s1bit = (GTUDI (tmp_old, tmp_tmp)) ? ((  tmp_tmp = -1, 1)) : (0);
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 1);
    SET_H_CR (((UINT) 57), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
;   {
    SI opval = SUBWORDDISI (tmp_tmp, 0);
    SET_H_CR (((UINT) 56), opval);
    written |= (1 << 12);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
; SUBWORDDISI (tmp_tmp, 0); });
if (FLD (f_F)) {
{
{
  {
    BI opval = LTSI (tmp_result, 0);
    CPU (h_nbit) = opval;
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "nbit", 'x', opval);
  }
  {
    BI opval = EQSI (tmp_result, 0);
    CPU (h_zbit) = opval;
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "zbit", 'x', opval);
  }
}
  {
    BI opval = tmp_cur_s1bit;
    CPU (h_vbit) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "vbit", 'x', opval);
  }
if (tmp_cur_s1bit) {
  {
    BI opval = 1;
    CPU (h_s1bit) = opval;
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "s1bit", 'x', opval);
  }
  {
    BI opval = 1;
    CPU (h_s2bit) = opval;
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "s2bit", 'x', opval);
  }
}
}
}
  {
    SI opval = tmp_result;
    SET_H_CR (FLD (f_op_B), opval);
    written |= (1 << 11);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* current_loop_end:  */

static SEM_PC
SEM_FN_NAME (arc600f,current_loop_end) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (ANDBI (EQSI (pc, GET_H_AUXR (((UINT) 3))), NOTBI (CPU (h_lbit)))) {
{
  {
    SI opval = ADDSI (GET_H_CR (((UINT) 60)), -1);
    SET_H_CR (((UINT) 60), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
if (GET_H_CR (((UINT) 60))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (GET_H_AUXR (((UINT) 2)), 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
  {
    USI opval = GET_H_AUXR (((UINT) 2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else if (0) {
  {
    USI opval = GET_H_AUXR (((UINT) 2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
 else {
{
  {
    SI opval = GET_H_AUXR (((UINT) 2));
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
  {
    USI opval = GET_H_AUXR (((UINT) 2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* current_loop_end_after_branch:  */

static SEM_PC
SEM_FN_NAME (arc600f,current_loop_end_after_branch) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (
#ifdef SEM_IN_SWITCH
pbb_br_type != SEM_BRANCH_UNTAKEN
#else
CPU_PBB_BR_NPC (current_cpu) != SEM_BRANCH_UNTAKEN
#endif
) {

#ifdef SEM_IN_SWITCH
npc = pbb_br_npc; br_type = pbb_br_type;
#else
npc = CPU_PBB_BR_NPC (current_cpu); br_type = CPU_PBB_BR_TYPE (current_cpu);
#endif
}
 else if (ANDBI (EQSI (pc, GET_H_AUXR (((UINT) 3))), NOTBI (CPU (h_lbit)))) {
{
  {
    SI opval = ADDSI (GET_H_CR (((UINT) 60)), -1);
    SET_H_CR (((UINT) 60), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
if (GET_H_CR (((UINT) 60))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (GET_H_AUXR (((UINT) 2)), 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
  {
    USI opval = GET_H_AUXR (((UINT) 2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else if (0) {
  {
    USI opval = GET_H_AUXR (((UINT) 2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
 else {
{
  {
    SI opval = GET_H_AUXR (((UINT) 2));
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
  {
    USI opval = GET_H_AUXR (((UINT) 2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* arc600_current_loop_end_after_branch:  */

static SEM_PC
SEM_FN_NAME (arc600f,arc600_current_loop_end_after_branch) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.fmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (
#ifdef SEM_IN_SWITCH
pbb_br_type != SEM_BRANCH_UNTAKEN
#else
CPU_PBB_BR_NPC (current_cpu) != SEM_BRANCH_UNTAKEN
#endif
) {
{

#ifdef SEM_IN_SWITCH
npc = pbb_br_npc; br_type = pbb_br_type;
#else
npc = CPU_PBB_BR_NPC (current_cpu); br_type = CPU_PBB_BR_TYPE (current_cpu);
#endif
  {
    SI opval = ADDSI (GET_H_CR (((UINT) 60)), -1);
    SET_H_CR (((UINT) 60), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
}
}
 else if (ANDBI (EQSI (pc, GET_H_AUXR (((UINT) 3))), NOTBI (CPU (h_lbit)))) {
{
  {
    SI opval = ADDSI (GET_H_CR (((UINT) 60)), -1);
    SET_H_CR (((UINT) 60), opval);
    written |= (1 << 16);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
if (GET_H_CR (((UINT) 60))) {
if (ANDIF (GESI (SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)])), 0), ANDIF (CPU (h_e1), ANDSI (GET_H_AUXR (((UINT) 34)), 1)))) {
{
  {
    SI opval = SUBSI (CPU_INSN_COUNT (current_cpu), CPU (h_timer_expire[((UINT) 0)]));
    SET_H_AUXR (((UINT) 33), opval);
    written |= (1 << 14);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
if (CPU (h_ubit)) {
{
  SI tmp_countp;
  UHI tmp_count;
  tmp_countp = ADDSI (ANDSI (SRLSI (GET_H_AUXR (((UINT) 2)), 1), -2), CPU (h_prof_offset[((UINT) 0)]));
  tmp_count = ADDHI (GETMEMUHI (current_cpu, pc, tmp_countp), 1);
if (tmp_count) {
  {
    UHI opval = tmp_count;
    SETMEMUHI (current_cpu, pc, tmp_countp, opval);
    written |= (1 << 18);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }
}
  {
    USI opval = GET_H_AUXR (((UINT) 2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
 else if (0) {
  {
    USI opval = GET_H_AUXR (((UINT) 2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
 else {
{
  {
    SI opval = GET_H_AUXR (((UINT) 2));
    SET_H_CR (((UINT) 29), opval);
    written |= (1 << 15);
    TRACE_RESULT (current_cpu, abuf, "cr", 'x', opval);
  }
  {
    SI opval = GET_H_STATUS32 (((UINT) 0));
    SET_H_AUXR (((UINT) 11), opval);
    written |= (1 << 13);
    TRACE_RESULT (current_cpu, abuf, "auxr", 'x', opval);
  }
  {
    BI opval = 0;
    CPU (h_e1) = opval;
    written |= (1 << 17);
    TRACE_RESULT (current_cpu, abuf, "e1", 'x', opval);
  }
  {
    USI opval = ADDSI (GET_H_AUXR (((UINT) 37)), 24);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
} else {
  {
    USI opval = GET_H_AUXR (((UINT) 2));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 19);
    TRACE_RESULT (current_cpu, abuf, "pc", 'x', opval);
  }
}
}
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* Table of all semantic fns.  */

static const struct sem_fn_desc sem_fns[] = {
  { ARC600F_INSN_X_INVALID, SEM_FN_NAME (arc600f,x_invalid) },
  { ARC600F_INSN_X_AFTER, SEM_FN_NAME (arc600f,x_after) },
  { ARC600F_INSN_X_BEFORE, SEM_FN_NAME (arc600f,x_before) },
  { ARC600F_INSN_X_CTI_CHAIN, SEM_FN_NAME (arc600f,x_cti_chain) },
  { ARC600F_INSN_X_CHAIN, SEM_FN_NAME (arc600f,x_chain) },
  { ARC600F_INSN_X_BEGIN, SEM_FN_NAME (arc600f,x_begin) },
  { ARC600F_INSN_B_S, SEM_FN_NAME (arc600f,b_s) },
  { ARC600F_INSN_BCC_S, SEM_FN_NAME (arc600f,bcc_s) },
  { ARC600F_INSN_BRCC_S, SEM_FN_NAME (arc600f,brcc_s) },
  { ARC600F_INSN_BCC_L, SEM_FN_NAME (arc600f,bcc_l) },
  { ARC600F_INSN_BCC_L_D, SEM_FN_NAME (arc600f,bcc_l_d) },
  { ARC600F_INSN_B_L, SEM_FN_NAME (arc600f,b_l) },
  { ARC600F_INSN_B_L_D, SEM_FN_NAME (arc600f,b_l_d) },
  { ARC600F_INSN_BRCC_RC, SEM_FN_NAME (arc600f,brcc_RC) },
  { ARC600F_INSN_BRCC_RC_D, SEM_FN_NAME (arc600f,brcc_RC_d) },
  { ARC600F_INSN_BRCC_U6, SEM_FN_NAME (arc600f,brcc_U6) },
  { ARC600F_INSN_BRCC_U6_D, SEM_FN_NAME (arc600f,brcc_U6_d) },
  { ARC600F_INSN_BL_S, SEM_FN_NAME (arc600f,bl_s) },
  { ARC600F_INSN_BLCC, SEM_FN_NAME (arc600f,blcc) },
  { ARC600F_INSN_BLCC_D, SEM_FN_NAME (arc600f,blcc_d) },
  { ARC600F_INSN_BL, SEM_FN_NAME (arc600f,bl) },
  { ARC600F_INSN_BL_D, SEM_FN_NAME (arc600f,bl_d) },
  { ARC600F_INSN_LD_ABS, SEM_FN_NAME (arc600f,ld_abs) },
  { ARC600F_INSN_LD__AW_ABS, SEM_FN_NAME (arc600f,ld__AW_abs) },
  { ARC600F_INSN_LD_AB_ABS, SEM_FN_NAME (arc600f,ld_ab_abs) },
  { ARC600F_INSN_LD_AS_ABS, SEM_FN_NAME (arc600f,ld_as_abs) },
  { ARC600F_INSN_LD_ABC, SEM_FN_NAME (arc600f,ld_abc) },
  { ARC600F_INSN_LD__AW_ABC, SEM_FN_NAME (arc600f,ld__AW_abc) },
  { ARC600F_INSN_LD_AB_ABC, SEM_FN_NAME (arc600f,ld_ab_abc) },
  { ARC600F_INSN_LD_AS_ABC, SEM_FN_NAME (arc600f,ld_as_abc) },
  { ARC600F_INSN_LD_S_ABC, SEM_FN_NAME (arc600f,ld_s_abc) },
  { ARC600F_INSN_LD_S_ABU, SEM_FN_NAME (arc600f,ld_s_abu) },
  { ARC600F_INSN_LD_S_ABSP, SEM_FN_NAME (arc600f,ld_s_absp) },
  { ARC600F_INSN_LD_S_GPREL, SEM_FN_NAME (arc600f,ld_s_gprel) },
  { ARC600F_INSN_LD_S_PCREL, SEM_FN_NAME (arc600f,ld_s_pcrel) },
  { ARC600F_INSN_LDB_ABS, SEM_FN_NAME (arc600f,ldb_abs) },
  { ARC600F_INSN_LDB__AW_ABS, SEM_FN_NAME (arc600f,ldb__AW_abs) },
  { ARC600F_INSN_LDB_AB_ABS, SEM_FN_NAME (arc600f,ldb_ab_abs) },
  { ARC600F_INSN_LDB_AS_ABS, SEM_FN_NAME (arc600f,ldb_as_abs) },
  { ARC600F_INSN_LDB_ABC, SEM_FN_NAME (arc600f,ldb_abc) },
  { ARC600F_INSN_LDB__AW_ABC, SEM_FN_NAME (arc600f,ldb__AW_abc) },
  { ARC600F_INSN_LDB_AB_ABC, SEM_FN_NAME (arc600f,ldb_ab_abc) },
  { ARC600F_INSN_LDB_AS_ABC, SEM_FN_NAME (arc600f,ldb_as_abc) },
  { ARC600F_INSN_LDB_S_ABC, SEM_FN_NAME (arc600f,ldb_s_abc) },
  { ARC600F_INSN_LDB_S_ABU, SEM_FN_NAME (arc600f,ldb_s_abu) },
  { ARC600F_INSN_LDB_S_ABSP, SEM_FN_NAME (arc600f,ldb_s_absp) },
  { ARC600F_INSN_LDB_S_GPREL, SEM_FN_NAME (arc600f,ldb_s_gprel) },
  { ARC600F_INSN_LDB_X_ABS, SEM_FN_NAME (arc600f,ldb_x_abs) },
  { ARC600F_INSN_LDB__AW_X_ABS, SEM_FN_NAME (arc600f,ldb__AW_x_abs) },
  { ARC600F_INSN_LDB_AB_X_ABS, SEM_FN_NAME (arc600f,ldb_ab_x_abs) },
  { ARC600F_INSN_LDB_AS_X_ABS, SEM_FN_NAME (arc600f,ldb_as_x_abs) },
  { ARC600F_INSN_LDB_X_ABC, SEM_FN_NAME (arc600f,ldb_x_abc) },
  { ARC600F_INSN_LDB__AW_X_ABC, SEM_FN_NAME (arc600f,ldb__AW_x_abc) },
  { ARC600F_INSN_LDB_AB_X_ABC, SEM_FN_NAME (arc600f,ldb_ab_x_abc) },
  { ARC600F_INSN_LDB_AS_X_ABC, SEM_FN_NAME (arc600f,ldb_as_x_abc) },
  { ARC600F_INSN_LDW_ABS, SEM_FN_NAME (arc600f,ldw_abs) },
  { ARC600F_INSN_LDW__AW_ABS, SEM_FN_NAME (arc600f,ldw__AW_abs) },
  { ARC600F_INSN_LDW_AB_ABS, SEM_FN_NAME (arc600f,ldw_ab_abs) },
  { ARC600F_INSN_LDW_AS_ABS, SEM_FN_NAME (arc600f,ldw_as_abs) },
  { ARC600F_INSN_LDW_ABC, SEM_FN_NAME (arc600f,ldw_abc) },
  { ARC600F_INSN_LDW__AW_ABC, SEM_FN_NAME (arc600f,ldw__AW_abc) },
  { ARC600F_INSN_LDW_AB_ABC, SEM_FN_NAME (arc600f,ldw_ab_abc) },
  { ARC600F_INSN_LDW_AS_ABC, SEM_FN_NAME (arc600f,ldw_as_abc) },
  { ARC600F_INSN_LDW_S_ABC, SEM_FN_NAME (arc600f,ldw_s_abc) },
  { ARC600F_INSN_LDW_S_ABU, SEM_FN_NAME (arc600f,ldw_s_abu) },
  { ARC600F_INSN_LDW_S_GPREL, SEM_FN_NAME (arc600f,ldw_s_gprel) },
  { ARC600F_INSN_LDW_X_ABS, SEM_FN_NAME (arc600f,ldw_x_abs) },
  { ARC600F_INSN_LDW__AW_X_ABS, SEM_FN_NAME (arc600f,ldw__AW_x_abs) },
  { ARC600F_INSN_LDW_AB_X_ABS, SEM_FN_NAME (arc600f,ldw_ab_x_abs) },
  { ARC600F_INSN_LDW_AS_X_ABS, SEM_FN_NAME (arc600f,ldw_as_x_abs) },
  { ARC600F_INSN_LDW_X_ABC, SEM_FN_NAME (arc600f,ldw_x_abc) },
  { ARC600F_INSN_LDW__AW_X_ABC, SEM_FN_NAME (arc600f,ldw__AW_x_abc) },
  { ARC600F_INSN_LDW_AB_X_ABC, SEM_FN_NAME (arc600f,ldw_ab_x_abc) },
  { ARC600F_INSN_LDW_AS_X_ABC, SEM_FN_NAME (arc600f,ldw_as_x_abc) },
  { ARC600F_INSN_LDW_S_X_ABU, SEM_FN_NAME (arc600f,ldw_s_x_abu) },
  { ARC600F_INSN_ST_ABS, SEM_FN_NAME (arc600f,st_abs) },
  { ARC600F_INSN_ST__AW_ABS, SEM_FN_NAME (arc600f,st__AW_abs) },
  { ARC600F_INSN_ST_AB_ABS, SEM_FN_NAME (arc600f,st_ab_abs) },
  { ARC600F_INSN_ST_AS_ABS, SEM_FN_NAME (arc600f,st_as_abs) },
  { ARC600F_INSN_ST_S_ABU, SEM_FN_NAME (arc600f,st_s_abu) },
  { ARC600F_INSN_ST_S_ABSP, SEM_FN_NAME (arc600f,st_s_absp) },
  { ARC600F_INSN_STB_ABS, SEM_FN_NAME (arc600f,stb_abs) },
  { ARC600F_INSN_STB__AW_ABS, SEM_FN_NAME (arc600f,stb__AW_abs) },
  { ARC600F_INSN_STB_AB_ABS, SEM_FN_NAME (arc600f,stb_ab_abs) },
  { ARC600F_INSN_STB_AS_ABS, SEM_FN_NAME (arc600f,stb_as_abs) },
  { ARC600F_INSN_STB_S_ABU, SEM_FN_NAME (arc600f,stb_s_abu) },
  { ARC600F_INSN_STB_S_ABSP, SEM_FN_NAME (arc600f,stb_s_absp) },
  { ARC600F_INSN_STW_ABS, SEM_FN_NAME (arc600f,stw_abs) },
  { ARC600F_INSN_STW__AW_ABS, SEM_FN_NAME (arc600f,stw__AW_abs) },
  { ARC600F_INSN_STW_AB_ABS, SEM_FN_NAME (arc600f,stw_ab_abs) },
  { ARC600F_INSN_STW_AS_ABS, SEM_FN_NAME (arc600f,stw_as_abs) },
  { ARC600F_INSN_STW_S_ABU, SEM_FN_NAME (arc600f,stw_s_abu) },
  { ARC600F_INSN_ADD_L_S12__RA_, SEM_FN_NAME (arc600f,add_L_s12__RA_) },
  { ARC600F_INSN_ADD_CCU6__RA_, SEM_FN_NAME (arc600f,add_ccu6__RA_) },
  { ARC600F_INSN_ADD_L_U6__RA_, SEM_FN_NAME (arc600f,add_L_u6__RA_) },
  { ARC600F_INSN_ADD_L_R_R__RA__RC, SEM_FN_NAME (arc600f,add_L_r_r__RA__RC) },
  { ARC600F_INSN_ADD_CC__RA__RC, SEM_FN_NAME (arc600f,add_cc__RA__RC) },
  { ARC600F_INSN_ADD_S_ABC, SEM_FN_NAME (arc600f,add_s_abc) },
  { ARC600F_INSN_ADD_S_CBU3, SEM_FN_NAME (arc600f,add_s_cbu3) },
  { ARC600F_INSN_ADD_S_MCAH, SEM_FN_NAME (arc600f,add_s_mcah) },
  { ARC600F_INSN_ADD_S_ABSP, SEM_FN_NAME (arc600f,add_s_absp) },
  { ARC600F_INSN_ADD_S_ASSPSP, SEM_FN_NAME (arc600f,add_s_asspsp) },
  { ARC600F_INSN_ADD_S_GP, SEM_FN_NAME (arc600f,add_s_gp) },
  { ARC600F_INSN_ADD_S_R_U7, SEM_FN_NAME (arc600f,add_s_r_u7) },
  { ARC600F_INSN_ADC_L_S12__RA_, SEM_FN_NAME (arc600f,adc_L_s12__RA_) },
  { ARC600F_INSN_ADC_CCU6__RA_, SEM_FN_NAME (arc600f,adc_ccu6__RA_) },
  { ARC600F_INSN_ADC_L_U6__RA_, SEM_FN_NAME (arc600f,adc_L_u6__RA_) },
  { ARC600F_INSN_ADC_L_R_R__RA__RC, SEM_FN_NAME (arc600f,adc_L_r_r__RA__RC) },
  { ARC600F_INSN_ADC_CC__RA__RC, SEM_FN_NAME (arc600f,adc_cc__RA__RC) },
  { ARC600F_INSN_SUB_L_S12__RA_, SEM_FN_NAME (arc600f,sub_L_s12__RA_) },
  { ARC600F_INSN_SUB_CCU6__RA_, SEM_FN_NAME (arc600f,sub_ccu6__RA_) },
  { ARC600F_INSN_SUB_L_U6__RA_, SEM_FN_NAME (arc600f,sub_L_u6__RA_) },
  { ARC600F_INSN_SUB_L_R_R__RA__RC, SEM_FN_NAME (arc600f,sub_L_r_r__RA__RC) },
  { ARC600F_INSN_SUB_CC__RA__RC, SEM_FN_NAME (arc600f,sub_cc__RA__RC) },
  { ARC600F_INSN_SUB_S_CBU3, SEM_FN_NAME (arc600f,sub_s_cbu3) },
  { ARC600F_INSN_I16_GO_SUB_S_GO, SEM_FN_NAME (arc600f,I16_GO_SUB_s_go) },
  { ARC600F_INSN_SUB_S_GO_SUB_NE, SEM_FN_NAME (arc600f,sub_s_go_sub_ne) },
  { ARC600F_INSN_SUB_S_SSB, SEM_FN_NAME (arc600f,sub_s_ssb) },
  { ARC600F_INSN_SUB_S_ASSPSP, SEM_FN_NAME (arc600f,sub_s_asspsp) },
  { ARC600F_INSN_SBC_L_S12__RA_, SEM_FN_NAME (arc600f,sbc_L_s12__RA_) },
  { ARC600F_INSN_SBC_CCU6__RA_, SEM_FN_NAME (arc600f,sbc_ccu6__RA_) },
  { ARC600F_INSN_SBC_L_U6__RA_, SEM_FN_NAME (arc600f,sbc_L_u6__RA_) },
  { ARC600F_INSN_SBC_L_R_R__RA__RC, SEM_FN_NAME (arc600f,sbc_L_r_r__RA__RC) },
  { ARC600F_INSN_SBC_CC__RA__RC, SEM_FN_NAME (arc600f,sbc_cc__RA__RC) },
  { ARC600F_INSN_AND_L_S12__RA_, SEM_FN_NAME (arc600f,and_L_s12__RA_) },
  { ARC600F_INSN_AND_CCU6__RA_, SEM_FN_NAME (arc600f,and_ccu6__RA_) },
  { ARC600F_INSN_AND_L_U6__RA_, SEM_FN_NAME (arc600f,and_L_u6__RA_) },
  { ARC600F_INSN_AND_L_R_R__RA__RC, SEM_FN_NAME (arc600f,and_L_r_r__RA__RC) },
  { ARC600F_INSN_AND_CC__RA__RC, SEM_FN_NAME (arc600f,and_cc__RA__RC) },
  { ARC600F_INSN_I16_GO_AND_S_GO, SEM_FN_NAME (arc600f,I16_GO_AND_s_go) },
  { ARC600F_INSN_OR_L_S12__RA_, SEM_FN_NAME (arc600f,or_L_s12__RA_) },
  { ARC600F_INSN_OR_CCU6__RA_, SEM_FN_NAME (arc600f,or_ccu6__RA_) },
  { ARC600F_INSN_OR_L_U6__RA_, SEM_FN_NAME (arc600f,or_L_u6__RA_) },
  { ARC600F_INSN_OR_L_R_R__RA__RC, SEM_FN_NAME (arc600f,or_L_r_r__RA__RC) },
  { ARC600F_INSN_OR_CC__RA__RC, SEM_FN_NAME (arc600f,or_cc__RA__RC) },
  { ARC600F_INSN_I16_GO_OR_S_GO, SEM_FN_NAME (arc600f,I16_GO_OR_s_go) },
  { ARC600F_INSN_BIC_L_S12__RA_, SEM_FN_NAME (arc600f,bic_L_s12__RA_) },
  { ARC600F_INSN_BIC_CCU6__RA_, SEM_FN_NAME (arc600f,bic_ccu6__RA_) },
  { ARC600F_INSN_BIC_L_U6__RA_, SEM_FN_NAME (arc600f,bic_L_u6__RA_) },
  { ARC600F_INSN_BIC_L_R_R__RA__RC, SEM_FN_NAME (arc600f,bic_L_r_r__RA__RC) },
  { ARC600F_INSN_BIC_CC__RA__RC, SEM_FN_NAME (arc600f,bic_cc__RA__RC) },
  { ARC600F_INSN_I16_GO_BIC_S_GO, SEM_FN_NAME (arc600f,I16_GO_BIC_s_go) },
  { ARC600F_INSN_XOR_L_S12__RA_, SEM_FN_NAME (arc600f,xor_L_s12__RA_) },
  { ARC600F_INSN_XOR_CCU6__RA_, SEM_FN_NAME (arc600f,xor_ccu6__RA_) },
  { ARC600F_INSN_XOR_L_U6__RA_, SEM_FN_NAME (arc600f,xor_L_u6__RA_) },
  { ARC600F_INSN_XOR_L_R_R__RA__RC, SEM_FN_NAME (arc600f,xor_L_r_r__RA__RC) },
  { ARC600F_INSN_XOR_CC__RA__RC, SEM_FN_NAME (arc600f,xor_cc__RA__RC) },
  { ARC600F_INSN_I16_GO_XOR_S_GO, SEM_FN_NAME (arc600f,I16_GO_XOR_s_go) },
  { ARC600F_INSN_MAX_L_S12__RA_, SEM_FN_NAME (arc600f,max_L_s12__RA_) },
  { ARC600F_INSN_MAX_CCU6__RA_, SEM_FN_NAME (arc600f,max_ccu6__RA_) },
  { ARC600F_INSN_MAX_L_U6__RA_, SEM_FN_NAME (arc600f,max_L_u6__RA_) },
  { ARC600F_INSN_MAX_L_R_R__RA__RC, SEM_FN_NAME (arc600f,max_L_r_r__RA__RC) },
  { ARC600F_INSN_MAX_CC__RA__RC, SEM_FN_NAME (arc600f,max_cc__RA__RC) },
  { ARC600F_INSN_MIN_L_S12__RA_, SEM_FN_NAME (arc600f,min_L_s12__RA_) },
  { ARC600F_INSN_MIN_CCU6__RA_, SEM_FN_NAME (arc600f,min_ccu6__RA_) },
  { ARC600F_INSN_MIN_L_U6__RA_, SEM_FN_NAME (arc600f,min_L_u6__RA_) },
  { ARC600F_INSN_MIN_L_R_R__RA__RC, SEM_FN_NAME (arc600f,min_L_r_r__RA__RC) },
  { ARC600F_INSN_MIN_CC__RA__RC, SEM_FN_NAME (arc600f,min_cc__RA__RC) },
  { ARC600F_INSN_MOV_L_S12_, SEM_FN_NAME (arc600f,mov_L_s12_) },
  { ARC600F_INSN_MOV_CCU6_, SEM_FN_NAME (arc600f,mov_ccu6_) },
  { ARC600F_INSN_MOV_L_U6_, SEM_FN_NAME (arc600f,mov_L_u6_) },
  { ARC600F_INSN_MOV_L_R_R__RC, SEM_FN_NAME (arc600f,mov_L_r_r__RC) },
  { ARC600F_INSN_MOV_CC__RC, SEM_FN_NAME (arc600f,mov_cc__RC) },
  { ARC600F_INSN_MOV_S_MCAH, SEM_FN_NAME (arc600f,mov_s_mcah) },
  { ARC600F_INSN_MOV_S_MCAHB, SEM_FN_NAME (arc600f,mov_s_mcahb) },
  { ARC600F_INSN_MOV_S_R_U7, SEM_FN_NAME (arc600f,mov_s_r_u7) },
  { ARC600F_INSN_TST_L_S12_, SEM_FN_NAME (arc600f,tst_L_s12_) },
  { ARC600F_INSN_TST_CCU6_, SEM_FN_NAME (arc600f,tst_ccu6_) },
  { ARC600F_INSN_TST_L_U6_, SEM_FN_NAME (arc600f,tst_L_u6_) },
  { ARC600F_INSN_TST_L_R_R__RC, SEM_FN_NAME (arc600f,tst_L_r_r__RC) },
  { ARC600F_INSN_TST_CC__RC, SEM_FN_NAME (arc600f,tst_cc__RC) },
  { ARC600F_INSN_TST_S_GO, SEM_FN_NAME (arc600f,tst_s_go) },
  { ARC600F_INSN_CMP_L_S12_, SEM_FN_NAME (arc600f,cmp_L_s12_) },
  { ARC600F_INSN_CMP_CCU6_, SEM_FN_NAME (arc600f,cmp_ccu6_) },
  { ARC600F_INSN_CMP_L_U6_, SEM_FN_NAME (arc600f,cmp_L_u6_) },
  { ARC600F_INSN_CMP_L_R_R__RC, SEM_FN_NAME (arc600f,cmp_L_r_r__RC) },
  { ARC600F_INSN_CMP_CC__RC, SEM_FN_NAME (arc600f,cmp_cc__RC) },
  { ARC600F_INSN_CMP_S_MCAH, SEM_FN_NAME (arc600f,cmp_s_mcah) },
  { ARC600F_INSN_CMP_S_R_U7, SEM_FN_NAME (arc600f,cmp_s_r_u7) },
  { ARC600F_INSN_RCMP_L_S12_, SEM_FN_NAME (arc600f,rcmp_L_s12_) },
  { ARC600F_INSN_RCMP_CCU6_, SEM_FN_NAME (arc600f,rcmp_ccu6_) },
  { ARC600F_INSN_RCMP_L_U6_, SEM_FN_NAME (arc600f,rcmp_L_u6_) },
  { ARC600F_INSN_RCMP_L_R_R__RC, SEM_FN_NAME (arc600f,rcmp_L_r_r__RC) },
  { ARC600F_INSN_RCMP_CC__RC, SEM_FN_NAME (arc600f,rcmp_cc__RC) },
  { ARC600F_INSN_RSUB_L_S12__RA_, SEM_FN_NAME (arc600f,rsub_L_s12__RA_) },
  { ARC600F_INSN_RSUB_CCU6__RA_, SEM_FN_NAME (arc600f,rsub_ccu6__RA_) },
  { ARC600F_INSN_RSUB_L_U6__RA_, SEM_FN_NAME (arc600f,rsub_L_u6__RA_) },
  { ARC600F_INSN_RSUB_L_R_R__RA__RC, SEM_FN_NAME (arc600f,rsub_L_r_r__RA__RC) },
  { ARC600F_INSN_RSUB_CC__RA__RC, SEM_FN_NAME (arc600f,rsub_cc__RA__RC) },
  { ARC600F_INSN_BSET_L_S12__RA_, SEM_FN_NAME (arc600f,bset_L_s12__RA_) },
  { ARC600F_INSN_BSET_CCU6__RA_, SEM_FN_NAME (arc600f,bset_ccu6__RA_) },
  { ARC600F_INSN_BSET_L_U6__RA_, SEM_FN_NAME (arc600f,bset_L_u6__RA_) },
  { ARC600F_INSN_BSET_L_R_R__RA__RC, SEM_FN_NAME (arc600f,bset_L_r_r__RA__RC) },
  { ARC600F_INSN_BSET_CC__RA__RC, SEM_FN_NAME (arc600f,bset_cc__RA__RC) },
  { ARC600F_INSN_BSET_S_SSB, SEM_FN_NAME (arc600f,bset_s_ssb) },
  { ARC600F_INSN_BCLR_L_S12__RA_, SEM_FN_NAME (arc600f,bclr_L_s12__RA_) },
  { ARC600F_INSN_BCLR_CCU6__RA_, SEM_FN_NAME (arc600f,bclr_ccu6__RA_) },
  { ARC600F_INSN_BCLR_L_U6__RA_, SEM_FN_NAME (arc600f,bclr_L_u6__RA_) },
  { ARC600F_INSN_BCLR_L_R_R__RA__RC, SEM_FN_NAME (arc600f,bclr_L_r_r__RA__RC) },
  { ARC600F_INSN_BCLR_CC__RA__RC, SEM_FN_NAME (arc600f,bclr_cc__RA__RC) },
  { ARC600F_INSN_BCLR_S_SSB, SEM_FN_NAME (arc600f,bclr_s_ssb) },
  { ARC600F_INSN_BTST_L_S12_, SEM_FN_NAME (arc600f,btst_L_s12_) },
  { ARC600F_INSN_BTST_CCU6_, SEM_FN_NAME (arc600f,btst_ccu6_) },
  { ARC600F_INSN_BTST_L_U6_, SEM_FN_NAME (arc600f,btst_L_u6_) },
  { ARC600F_INSN_BTST_L_R_R__RC, SEM_FN_NAME (arc600f,btst_L_r_r__RC) },
  { ARC600F_INSN_BTST_CC__RC, SEM_FN_NAME (arc600f,btst_cc__RC) },
  { ARC600F_INSN_BTST_S_SSB, SEM_FN_NAME (arc600f,btst_s_ssb) },
  { ARC600F_INSN_BXOR_L_S12__RA_, SEM_FN_NAME (arc600f,bxor_L_s12__RA_) },
  { ARC600F_INSN_BXOR_CCU6__RA_, SEM_FN_NAME (arc600f,bxor_ccu6__RA_) },
  { ARC600F_INSN_BXOR_L_U6__RA_, SEM_FN_NAME (arc600f,bxor_L_u6__RA_) },
  { ARC600F_INSN_BXOR_L_R_R__RA__RC, SEM_FN_NAME (arc600f,bxor_L_r_r__RA__RC) },
  { ARC600F_INSN_BXOR_CC__RA__RC, SEM_FN_NAME (arc600f,bxor_cc__RA__RC) },
  { ARC600F_INSN_BMSK_L_S12__RA_, SEM_FN_NAME (arc600f,bmsk_L_s12__RA_) },
  { ARC600F_INSN_BMSK_CCU6__RA_, SEM_FN_NAME (arc600f,bmsk_ccu6__RA_) },
  { ARC600F_INSN_BMSK_L_U6__RA_, SEM_FN_NAME (arc600f,bmsk_L_u6__RA_) },
  { ARC600F_INSN_BMSK_L_R_R__RA__RC, SEM_FN_NAME (arc600f,bmsk_L_r_r__RA__RC) },
  { ARC600F_INSN_BMSK_CC__RA__RC, SEM_FN_NAME (arc600f,bmsk_cc__RA__RC) },
  { ARC600F_INSN_BMSK_S_SSB, SEM_FN_NAME (arc600f,bmsk_s_ssb) },
  { ARC600F_INSN_ADD1_L_S12__RA_, SEM_FN_NAME (arc600f,add1_L_s12__RA_) },
  { ARC600F_INSN_ADD1_CCU6__RA_, SEM_FN_NAME (arc600f,add1_ccu6__RA_) },
  { ARC600F_INSN_ADD1_L_U6__RA_, SEM_FN_NAME (arc600f,add1_L_u6__RA_) },
  { ARC600F_INSN_ADD1_L_R_R__RA__RC, SEM_FN_NAME (arc600f,add1_L_r_r__RA__RC) },
  { ARC600F_INSN_ADD1_CC__RA__RC, SEM_FN_NAME (arc600f,add1_cc__RA__RC) },
  { ARC600F_INSN_I16_GO_ADD1_S_GO, SEM_FN_NAME (arc600f,I16_GO_ADD1_s_go) },
  { ARC600F_INSN_ADD2_L_S12__RA_, SEM_FN_NAME (arc600f,add2_L_s12__RA_) },
  { ARC600F_INSN_ADD2_CCU6__RA_, SEM_FN_NAME (arc600f,add2_ccu6__RA_) },
  { ARC600F_INSN_ADD2_L_U6__RA_, SEM_FN_NAME (arc600f,add2_L_u6__RA_) },
  { ARC600F_INSN_ADD2_L_R_R__RA__RC, SEM_FN_NAME (arc600f,add2_L_r_r__RA__RC) },
  { ARC600F_INSN_ADD2_CC__RA__RC, SEM_FN_NAME (arc600f,add2_cc__RA__RC) },
  { ARC600F_INSN_I16_GO_ADD2_S_GO, SEM_FN_NAME (arc600f,I16_GO_ADD2_s_go) },
  { ARC600F_INSN_ADD3_L_S12__RA_, SEM_FN_NAME (arc600f,add3_L_s12__RA_) },
  { ARC600F_INSN_ADD3_CCU6__RA_, SEM_FN_NAME (arc600f,add3_ccu6__RA_) },
  { ARC600F_INSN_ADD3_L_U6__RA_, SEM_FN_NAME (arc600f,add3_L_u6__RA_) },
  { ARC600F_INSN_ADD3_L_R_R__RA__RC, SEM_FN_NAME (arc600f,add3_L_r_r__RA__RC) },
  { ARC600F_INSN_ADD3_CC__RA__RC, SEM_FN_NAME (arc600f,add3_cc__RA__RC) },
  { ARC600F_INSN_I16_GO_ADD3_S_GO, SEM_FN_NAME (arc600f,I16_GO_ADD3_s_go) },
  { ARC600F_INSN_SUB1_L_S12__RA_, SEM_FN_NAME (arc600f,sub1_L_s12__RA_) },
  { ARC600F_INSN_SUB1_CCU6__RA_, SEM_FN_NAME (arc600f,sub1_ccu6__RA_) },
  { ARC600F_INSN_SUB1_L_U6__RA_, SEM_FN_NAME (arc600f,sub1_L_u6__RA_) },
  { ARC600F_INSN_SUB1_L_R_R__RA__RC, SEM_FN_NAME (arc600f,sub1_L_r_r__RA__RC) },
  { ARC600F_INSN_SUB1_CC__RA__RC, SEM_FN_NAME (arc600f,sub1_cc__RA__RC) },
  { ARC600F_INSN_SUB2_L_S12__RA_, SEM_FN_NAME (arc600f,sub2_L_s12__RA_) },
  { ARC600F_INSN_SUB2_CCU6__RA_, SEM_FN_NAME (arc600f,sub2_ccu6__RA_) },
  { ARC600F_INSN_SUB2_L_U6__RA_, SEM_FN_NAME (arc600f,sub2_L_u6__RA_) },
  { ARC600F_INSN_SUB2_L_R_R__RA__RC, SEM_FN_NAME (arc600f,sub2_L_r_r__RA__RC) },
  { ARC600F_INSN_SUB2_CC__RA__RC, SEM_FN_NAME (arc600f,sub2_cc__RA__RC) },
  { ARC600F_INSN_SUB3_L_S12__RA_, SEM_FN_NAME (arc600f,sub3_L_s12__RA_) },
  { ARC600F_INSN_SUB3_CCU6__RA_, SEM_FN_NAME (arc600f,sub3_ccu6__RA_) },
  { ARC600F_INSN_SUB3_L_U6__RA_, SEM_FN_NAME (arc600f,sub3_L_u6__RA_) },
  { ARC600F_INSN_SUB3_L_R_R__RA__RC, SEM_FN_NAME (arc600f,sub3_L_r_r__RA__RC) },
  { ARC600F_INSN_SUB3_CC__RA__RC, SEM_FN_NAME (arc600f,sub3_cc__RA__RC) },
  { ARC600F_INSN_MPY_L_S12__RA_, SEM_FN_NAME (arc600f,mpy_L_s12__RA_) },
  { ARC600F_INSN_MPY_CCU6__RA_, SEM_FN_NAME (arc600f,mpy_ccu6__RA_) },
  { ARC600F_INSN_MPY_L_U6__RA_, SEM_FN_NAME (arc600f,mpy_L_u6__RA_) },
  { ARC600F_INSN_MPY_L_R_R__RA__RC, SEM_FN_NAME (arc600f,mpy_L_r_r__RA__RC) },
  { ARC600F_INSN_MPY_CC__RA__RC, SEM_FN_NAME (arc600f,mpy_cc__RA__RC) },
  { ARC600F_INSN_MPYH_L_S12__RA_, SEM_FN_NAME (arc600f,mpyh_L_s12__RA_) },
  { ARC600F_INSN_MPYH_CCU6__RA_, SEM_FN_NAME (arc600f,mpyh_ccu6__RA_) },
  { ARC600F_INSN_MPYH_L_U6__RA_, SEM_FN_NAME (arc600f,mpyh_L_u6__RA_) },
  { ARC600F_INSN_MPYH_L_R_R__RA__RC, SEM_FN_NAME (arc600f,mpyh_L_r_r__RA__RC) },
  { ARC600F_INSN_MPYH_CC__RA__RC, SEM_FN_NAME (arc600f,mpyh_cc__RA__RC) },
  { ARC600F_INSN_MPYHU_L_S12__RA_, SEM_FN_NAME (arc600f,mpyhu_L_s12__RA_) },
  { ARC600F_INSN_MPYHU_CCU6__RA_, SEM_FN_NAME (arc600f,mpyhu_ccu6__RA_) },
  { ARC600F_INSN_MPYHU_L_U6__RA_, SEM_FN_NAME (arc600f,mpyhu_L_u6__RA_) },
  { ARC600F_INSN_MPYHU_L_R_R__RA__RC, SEM_FN_NAME (arc600f,mpyhu_L_r_r__RA__RC) },
  { ARC600F_INSN_MPYHU_CC__RA__RC, SEM_FN_NAME (arc600f,mpyhu_cc__RA__RC) },
  { ARC600F_INSN_MPYU_L_S12__RA_, SEM_FN_NAME (arc600f,mpyu_L_s12__RA_) },
  { ARC600F_INSN_MPYU_CCU6__RA_, SEM_FN_NAME (arc600f,mpyu_ccu6__RA_) },
  { ARC600F_INSN_MPYU_L_U6__RA_, SEM_FN_NAME (arc600f,mpyu_L_u6__RA_) },
  { ARC600F_INSN_MPYU_L_R_R__RA__RC, SEM_FN_NAME (arc600f,mpyu_L_r_r__RA__RC) },
  { ARC600F_INSN_MPYU_CC__RA__RC, SEM_FN_NAME (arc600f,mpyu_cc__RA__RC) },
  { ARC600F_INSN_J_L_R_R___RC_NOILINK_, SEM_FN_NAME (arc600f,j_L_r_r___RC_noilink_) },
  { ARC600F_INSN_J_CC___RC_NOILINK_, SEM_FN_NAME (arc600f,j_cc___RC_noilink_) },
  { ARC600F_INSN_J_L_R_R___RC_ILINK_, SEM_FN_NAME (arc600f,j_L_r_r___RC_ilink_) },
  { ARC600F_INSN_J_CC___RC_ILINK_, SEM_FN_NAME (arc600f,j_cc___RC_ilink_) },
  { ARC600F_INSN_J_L_S12_, SEM_FN_NAME (arc600f,j_L_s12_) },
  { ARC600F_INSN_J_CCU6_, SEM_FN_NAME (arc600f,j_ccu6_) },
  { ARC600F_INSN_J_L_U6_, SEM_FN_NAME (arc600f,j_L_u6_) },
  { ARC600F_INSN_J_S, SEM_FN_NAME (arc600f,j_s) },
  { ARC600F_INSN_J_S__S, SEM_FN_NAME (arc600f,j_s__S) },
  { ARC600F_INSN_J_SEQ__S, SEM_FN_NAME (arc600f,j_seq__S) },
  { ARC600F_INSN_J_SNE__S, SEM_FN_NAME (arc600f,j_sne__S) },
  { ARC600F_INSN_J_L_S12_D_, SEM_FN_NAME (arc600f,j_L_s12_d_) },
  { ARC600F_INSN_J_CCU6_D_, SEM_FN_NAME (arc600f,j_ccu6_d_) },
  { ARC600F_INSN_J_L_U6_D_, SEM_FN_NAME (arc600f,j_L_u6_d_) },
  { ARC600F_INSN_J_L_R_R_D___RC_, SEM_FN_NAME (arc600f,j_L_r_r_d___RC_) },
  { ARC600F_INSN_J_CC_D___RC_, SEM_FN_NAME (arc600f,j_cc_d___RC_) },
  { ARC600F_INSN_J_S_D, SEM_FN_NAME (arc600f,j_s_d) },
  { ARC600F_INSN_J_S__S_D, SEM_FN_NAME (arc600f,j_s__S_d) },
  { ARC600F_INSN_JL_L_S12_, SEM_FN_NAME (arc600f,jl_L_s12_) },
  { ARC600F_INSN_JL_CCU6_, SEM_FN_NAME (arc600f,jl_ccu6_) },
  { ARC600F_INSN_JL_L_U6_, SEM_FN_NAME (arc600f,jl_L_u6_) },
  { ARC600F_INSN_JL_S, SEM_FN_NAME (arc600f,jl_s) },
  { ARC600F_INSN_JL_L_R_R___RC_NOILINK_, SEM_FN_NAME (arc600f,jl_L_r_r___RC_noilink_) },
  { ARC600F_INSN_JL_CC___RC_NOILINK_, SEM_FN_NAME (arc600f,jl_cc___RC_noilink_) },
  { ARC600F_INSN_JL_L_S12_D_, SEM_FN_NAME (arc600f,jl_L_s12_d_) },
  { ARC600F_INSN_JL_CCU6_D_, SEM_FN_NAME (arc600f,jl_ccu6_d_) },
  { ARC600F_INSN_JL_L_U6_D_, SEM_FN_NAME (arc600f,jl_L_u6_d_) },
  { ARC600F_INSN_JL_L_R_R_D___RC_, SEM_FN_NAME (arc600f,jl_L_r_r_d___RC_) },
  { ARC600F_INSN_JL_CC_D___RC_, SEM_FN_NAME (arc600f,jl_cc_d___RC_) },
  { ARC600F_INSN_JL_S_D, SEM_FN_NAME (arc600f,jl_s_d) },
  { ARC600F_INSN_LP_L_S12_, SEM_FN_NAME (arc600f,lp_L_s12_) },
  { ARC600F_INSN_LPCC_CCU6, SEM_FN_NAME (arc600f,lpcc_ccu6) },
  { ARC600F_INSN_FLAG_L_S12_, SEM_FN_NAME (arc600f,flag_L_s12_) },
  { ARC600F_INSN_FLAG_CCU6_, SEM_FN_NAME (arc600f,flag_ccu6_) },
  { ARC600F_INSN_FLAG_L_U6_, SEM_FN_NAME (arc600f,flag_L_u6_) },
  { ARC600F_INSN_FLAG_L_R_R__RC, SEM_FN_NAME (arc600f,flag_L_r_r__RC) },
  { ARC600F_INSN_FLAG_CC__RC, SEM_FN_NAME (arc600f,flag_cc__RC) },
  { ARC600F_INSN_LR_L_R_R___RC_, SEM_FN_NAME (arc600f,lr_L_r_r___RC_) },
  { ARC600F_INSN_LR_L_S12_, SEM_FN_NAME (arc600f,lr_L_s12_) },
  { ARC600F_INSN_LR_L_U6_, SEM_FN_NAME (arc600f,lr_L_u6_) },
  { ARC600F_INSN_SR_L_R_R___RC_, SEM_FN_NAME (arc600f,sr_L_r_r___RC_) },
  { ARC600F_INSN_SR_L_S12_, SEM_FN_NAME (arc600f,sr_L_s12_) },
  { ARC600F_INSN_SR_L_U6_, SEM_FN_NAME (arc600f,sr_L_u6_) },
  { ARC600F_INSN_ASL_L_R_R__RC, SEM_FN_NAME (arc600f,asl_L_r_r__RC) },
  { ARC600F_INSN_ASL_L_U6_, SEM_FN_NAME (arc600f,asl_L_u6_) },
  { ARC600F_INSN_I16_GO_ASL_S_GO, SEM_FN_NAME (arc600f,I16_GO_ASL_s_go) },
  { ARC600F_INSN_ASR_L_R_R__RC, SEM_FN_NAME (arc600f,asr_L_r_r__RC) },
  { ARC600F_INSN_ASR_L_U6_, SEM_FN_NAME (arc600f,asr_L_u6_) },
  { ARC600F_INSN_I16_GO_ASR_S_GO, SEM_FN_NAME (arc600f,I16_GO_ASR_s_go) },
  { ARC600F_INSN_LSR_L_R_R__RC, SEM_FN_NAME (arc600f,lsr_L_r_r__RC) },
  { ARC600F_INSN_LSR_L_U6_, SEM_FN_NAME (arc600f,lsr_L_u6_) },
  { ARC600F_INSN_I16_GO_LSR_S_GO, SEM_FN_NAME (arc600f,I16_GO_LSR_s_go) },
  { ARC600F_INSN_ROR_L_R_R__RC, SEM_FN_NAME (arc600f,ror_L_r_r__RC) },
  { ARC600F_INSN_ROR_L_U6_, SEM_FN_NAME (arc600f,ror_L_u6_) },
  { ARC600F_INSN_RRC_L_R_R__RC, SEM_FN_NAME (arc600f,rrc_L_r_r__RC) },
  { ARC600F_INSN_RRC_L_U6_, SEM_FN_NAME (arc600f,rrc_L_u6_) },
  { ARC600F_INSN_SEXB_L_R_R__RC, SEM_FN_NAME (arc600f,sexb_L_r_r__RC) },
  { ARC600F_INSN_SEXB_L_U6_, SEM_FN_NAME (arc600f,sexb_L_u6_) },
  { ARC600F_INSN_I16_GO_SEXB_S_GO, SEM_FN_NAME (arc600f,I16_GO_SEXB_s_go) },
  { ARC600F_INSN_SEXW_L_R_R__RC, SEM_FN_NAME (arc600f,sexw_L_r_r__RC) },
  { ARC600F_INSN_SEXW_L_U6_, SEM_FN_NAME (arc600f,sexw_L_u6_) },
  { ARC600F_INSN_I16_GO_SEXW_S_GO, SEM_FN_NAME (arc600f,I16_GO_SEXW_s_go) },
  { ARC600F_INSN_EXTB_L_R_R__RC, SEM_FN_NAME (arc600f,extb_L_r_r__RC) },
  { ARC600F_INSN_EXTB_L_U6_, SEM_FN_NAME (arc600f,extb_L_u6_) },
  { ARC600F_INSN_I16_GO_EXTB_S_GO, SEM_FN_NAME (arc600f,I16_GO_EXTB_s_go) },
  { ARC600F_INSN_EXTW_L_R_R__RC, SEM_FN_NAME (arc600f,extw_L_r_r__RC) },
  { ARC600F_INSN_EXTW_L_U6_, SEM_FN_NAME (arc600f,extw_L_u6_) },
  { ARC600F_INSN_I16_GO_EXTW_S_GO, SEM_FN_NAME (arc600f,I16_GO_EXTW_s_go) },
  { ARC600F_INSN_ABS_L_R_R__RC, SEM_FN_NAME (arc600f,abs_L_r_r__RC) },
  { ARC600F_INSN_ABS_L_U6_, SEM_FN_NAME (arc600f,abs_L_u6_) },
  { ARC600F_INSN_I16_GO_ABS_S_GO, SEM_FN_NAME (arc600f,I16_GO_ABS_s_go) },
  { ARC600F_INSN_NOT_L_R_R__RC, SEM_FN_NAME (arc600f,not_L_r_r__RC) },
  { ARC600F_INSN_NOT_L_U6_, SEM_FN_NAME (arc600f,not_L_u6_) },
  { ARC600F_INSN_I16_GO_NOT_S_GO, SEM_FN_NAME (arc600f,I16_GO_NOT_s_go) },
  { ARC600F_INSN_RLC_L_R_R__RC, SEM_FN_NAME (arc600f,rlc_L_r_r__RC) },
  { ARC600F_INSN_RLC_L_U6_, SEM_FN_NAME (arc600f,rlc_L_u6_) },
  { ARC600F_INSN_I16_GO_NEG_S_GO, SEM_FN_NAME (arc600f,I16_GO_NEG_s_go) },
  { ARC600F_INSN_SWI, SEM_FN_NAME (arc600f,swi) },
  { ARC600F_INSN_TRAP_S, SEM_FN_NAME (arc600f,trap_s) },
  { ARC600F_INSN_BRK, SEM_FN_NAME (arc600f,brk) },
  { ARC600F_INSN_BRK_S, SEM_FN_NAME (arc600f,brk_s) },
  { ARC600F_INSN_ASL_L_S12__RA_, SEM_FN_NAME (arc600f,asl_L_s12__RA_) },
  { ARC600F_INSN_ASL_CCU6__RA_, SEM_FN_NAME (arc600f,asl_ccu6__RA_) },
  { ARC600F_INSN_ASL_L_U6__RA_, SEM_FN_NAME (arc600f,asl_L_u6__RA_) },
  { ARC600F_INSN_ASL_L_R_R__RA__RC, SEM_FN_NAME (arc600f,asl_L_r_r__RA__RC) },
  { ARC600F_INSN_ASL_CC__RA__RC, SEM_FN_NAME (arc600f,asl_cc__RA__RC) },
  { ARC600F_INSN_ASL_S_CBU3, SEM_FN_NAME (arc600f,asl_s_cbu3) },
  { ARC600F_INSN_ASL_S_SSB, SEM_FN_NAME (arc600f,asl_s_ssb) },
  { ARC600F_INSN_I16_GO_ASLM_S_GO, SEM_FN_NAME (arc600f,I16_GO_ASLM_s_go) },
  { ARC600F_INSN_LSR_L_S12__RA_, SEM_FN_NAME (arc600f,lsr_L_s12__RA_) },
  { ARC600F_INSN_LSR_CCU6__RA_, SEM_FN_NAME (arc600f,lsr_ccu6__RA_) },
  { ARC600F_INSN_LSR_L_U6__RA_, SEM_FN_NAME (arc600f,lsr_L_u6__RA_) },
  { ARC600F_INSN_LSR_L_R_R__RA__RC, SEM_FN_NAME (arc600f,lsr_L_r_r__RA__RC) },
  { ARC600F_INSN_LSR_CC__RA__RC, SEM_FN_NAME (arc600f,lsr_cc__RA__RC) },
  { ARC600F_INSN_LSR_S_SSB, SEM_FN_NAME (arc600f,lsr_s_ssb) },
  { ARC600F_INSN_I16_GO_LSRM_S_GO, SEM_FN_NAME (arc600f,I16_GO_LSRM_s_go) },
  { ARC600F_INSN_ASR_L_S12__RA_, SEM_FN_NAME (arc600f,asr_L_s12__RA_) },
  { ARC600F_INSN_ASR_CCU6__RA_, SEM_FN_NAME (arc600f,asr_ccu6__RA_) },
  { ARC600F_INSN_ASR_L_U6__RA_, SEM_FN_NAME (arc600f,asr_L_u6__RA_) },
  { ARC600F_INSN_ASR_L_R_R__RA__RC, SEM_FN_NAME (arc600f,asr_L_r_r__RA__RC) },
  { ARC600F_INSN_ASR_CC__RA__RC, SEM_FN_NAME (arc600f,asr_cc__RA__RC) },
  { ARC600F_INSN_ASR_S_CBU3, SEM_FN_NAME (arc600f,asr_s_cbu3) },
  { ARC600F_INSN_ASR_S_SSB, SEM_FN_NAME (arc600f,asr_s_ssb) },
  { ARC600F_INSN_I16_GO_ASRM_S_GO, SEM_FN_NAME (arc600f,I16_GO_ASRM_s_go) },
  { ARC600F_INSN_ROR_L_S12__RA_, SEM_FN_NAME (arc600f,ror_L_s12__RA_) },
  { ARC600F_INSN_ROR_CCU6__RA_, SEM_FN_NAME (arc600f,ror_ccu6__RA_) },
  { ARC600F_INSN_ROR_L_U6__RA_, SEM_FN_NAME (arc600f,ror_L_u6__RA_) },
  { ARC600F_INSN_ROR_L_R_R__RA__RC, SEM_FN_NAME (arc600f,ror_L_r_r__RA__RC) },
  { ARC600F_INSN_ROR_CC__RA__RC, SEM_FN_NAME (arc600f,ror_cc__RA__RC) },
  { ARC600F_INSN_MUL64_L_S12_, SEM_FN_NAME (arc600f,mul64_L_s12_) },
  { ARC600F_INSN_MUL64_CCU6_, SEM_FN_NAME (arc600f,mul64_ccu6_) },
  { ARC600F_INSN_MUL64_L_U6_, SEM_FN_NAME (arc600f,mul64_L_u6_) },
  { ARC600F_INSN_MUL64_L_R_R__RC, SEM_FN_NAME (arc600f,mul64_L_r_r__RC) },
  { ARC600F_INSN_MUL64_CC__RC, SEM_FN_NAME (arc600f,mul64_cc__RC) },
  { ARC600F_INSN_MUL64_S_GO, SEM_FN_NAME (arc600f,mul64_s_go) },
  { ARC600F_INSN_MULU64_L_S12_, SEM_FN_NAME (arc600f,mulu64_L_s12_) },
  { ARC600F_INSN_MULU64_CCU6_, SEM_FN_NAME (arc600f,mulu64_ccu6_) },
  { ARC600F_INSN_MULU64_L_U6_, SEM_FN_NAME (arc600f,mulu64_L_u6_) },
  { ARC600F_INSN_MULU64_L_R_R__RC, SEM_FN_NAME (arc600f,mulu64_L_r_r__RC) },
  { ARC600F_INSN_MULU64_CC__RC, SEM_FN_NAME (arc600f,mulu64_cc__RC) },
  { ARC600F_INSN_ADDS_L_S12__RA_, SEM_FN_NAME (arc600f,adds_L_s12__RA_) },
  { ARC600F_INSN_ADDS_CCU6__RA_, SEM_FN_NAME (arc600f,adds_ccu6__RA_) },
  { ARC600F_INSN_ADDS_L_U6__RA_, SEM_FN_NAME (arc600f,adds_L_u6__RA_) },
  { ARC600F_INSN_ADDS_L_R_R__RA__RC, SEM_FN_NAME (arc600f,adds_L_r_r__RA__RC) },
  { ARC600F_INSN_ADDS_CC__RA__RC, SEM_FN_NAME (arc600f,adds_cc__RA__RC) },
  { ARC600F_INSN_SUBS_L_S12__RA_, SEM_FN_NAME (arc600f,subs_L_s12__RA_) },
  { ARC600F_INSN_SUBS_CCU6__RA_, SEM_FN_NAME (arc600f,subs_ccu6__RA_) },
  { ARC600F_INSN_SUBS_L_U6__RA_, SEM_FN_NAME (arc600f,subs_L_u6__RA_) },
  { ARC600F_INSN_SUBS_L_R_R__RA__RC, SEM_FN_NAME (arc600f,subs_L_r_r__RA__RC) },
  { ARC600F_INSN_SUBS_CC__RA__RC, SEM_FN_NAME (arc600f,subs_cc__RA__RC) },
  { ARC600F_INSN_DIVAW_L_S12__RA_, SEM_FN_NAME (arc600f,divaw_L_s12__RA_) },
  { ARC600F_INSN_DIVAW_CCU6__RA_, SEM_FN_NAME (arc600f,divaw_ccu6__RA_) },
  { ARC600F_INSN_DIVAW_L_U6__RA_, SEM_FN_NAME (arc600f,divaw_L_u6__RA_) },
  { ARC600F_INSN_DIVAW_L_R_R__RA__RC, SEM_FN_NAME (arc600f,divaw_L_r_r__RA__RC) },
  { ARC600F_INSN_DIVAW_CC__RA__RC, SEM_FN_NAME (arc600f,divaw_cc__RA__RC) },
  { ARC600F_INSN_ASLS_L_S12__RA_, SEM_FN_NAME (arc600f,asls_L_s12__RA_) },
  { ARC600F_INSN_ASLS_CCU6__RA_, SEM_FN_NAME (arc600f,asls_ccu6__RA_) },
  { ARC600F_INSN_ASLS_L_U6__RA_, SEM_FN_NAME (arc600f,asls_L_u6__RA_) },
  { ARC600F_INSN_ASLS_L_R_R__RA__RC, SEM_FN_NAME (arc600f,asls_L_r_r__RA__RC) },
  { ARC600F_INSN_ASLS_CC__RA__RC, SEM_FN_NAME (arc600f,asls_cc__RA__RC) },
  { ARC600F_INSN_ASRS_L_S12__RA_, SEM_FN_NAME (arc600f,asrs_L_s12__RA_) },
  { ARC600F_INSN_ASRS_CCU6__RA_, SEM_FN_NAME (arc600f,asrs_ccu6__RA_) },
  { ARC600F_INSN_ASRS_L_U6__RA_, SEM_FN_NAME (arc600f,asrs_L_u6__RA_) },
  { ARC600F_INSN_ASRS_L_R_R__RA__RC, SEM_FN_NAME (arc600f,asrs_L_r_r__RA__RC) },
  { ARC600F_INSN_ASRS_CC__RA__RC, SEM_FN_NAME (arc600f,asrs_cc__RA__RC) },
  { ARC600F_INSN_ADDSDW_L_S12__RA_, SEM_FN_NAME (arc600f,addsdw_L_s12__RA_) },
  { ARC600F_INSN_ADDSDW_CCU6__RA_, SEM_FN_NAME (arc600f,addsdw_ccu6__RA_) },
  { ARC600F_INSN_ADDSDW_L_U6__RA_, SEM_FN_NAME (arc600f,addsdw_L_u6__RA_) },
  { ARC600F_INSN_ADDSDW_L_R_R__RA__RC, SEM_FN_NAME (arc600f,addsdw_L_r_r__RA__RC) },
  { ARC600F_INSN_ADDSDW_CC__RA__RC, SEM_FN_NAME (arc600f,addsdw_cc__RA__RC) },
  { ARC600F_INSN_SUBSDW_L_S12__RA_, SEM_FN_NAME (arc600f,subsdw_L_s12__RA_) },
  { ARC600F_INSN_SUBSDW_CCU6__RA_, SEM_FN_NAME (arc600f,subsdw_ccu6__RA_) },
  { ARC600F_INSN_SUBSDW_L_U6__RA_, SEM_FN_NAME (arc600f,subsdw_L_u6__RA_) },
  { ARC600F_INSN_SUBSDW_L_R_R__RA__RC, SEM_FN_NAME (arc600f,subsdw_L_r_r__RA__RC) },
  { ARC600F_INSN_SUBSDW_CC__RA__RC, SEM_FN_NAME (arc600f,subsdw_cc__RA__RC) },
  { ARC600F_INSN_SWAP_L_R_R__RC, SEM_FN_NAME (arc600f,swap_L_r_r__RC) },
  { ARC600F_INSN_SWAP_L_U6_, SEM_FN_NAME (arc600f,swap_L_u6_) },
  { ARC600F_INSN_NORM_L_R_R__RC, SEM_FN_NAME (arc600f,norm_L_r_r__RC) },
  { ARC600F_INSN_NORM_L_U6_, SEM_FN_NAME (arc600f,norm_L_u6_) },
  { ARC600F_INSN_RND16_L_R_R__RC, SEM_FN_NAME (arc600f,rnd16_L_r_r__RC) },
  { ARC600F_INSN_RND16_L_U6_, SEM_FN_NAME (arc600f,rnd16_L_u6_) },
  { ARC600F_INSN_ABSSW_L_R_R__RC, SEM_FN_NAME (arc600f,abssw_L_r_r__RC) },
  { ARC600F_INSN_ABSSW_L_U6_, SEM_FN_NAME (arc600f,abssw_L_u6_) },
  { ARC600F_INSN_ABSS_L_R_R__RC, SEM_FN_NAME (arc600f,abss_L_r_r__RC) },
  { ARC600F_INSN_ABSS_L_U6_, SEM_FN_NAME (arc600f,abss_L_u6_) },
  { ARC600F_INSN_NEGSW_L_R_R__RC, SEM_FN_NAME (arc600f,negsw_L_r_r__RC) },
  { ARC600F_INSN_NEGSW_L_U6_, SEM_FN_NAME (arc600f,negsw_L_u6_) },
  { ARC600F_INSN_NEGS_L_R_R__RC, SEM_FN_NAME (arc600f,negs_L_r_r__RC) },
  { ARC600F_INSN_NEGS_L_U6_, SEM_FN_NAME (arc600f,negs_L_u6_) },
  { ARC600F_INSN_NORMW_L_R_R__RC, SEM_FN_NAME (arc600f,normw_L_r_r__RC) },
  { ARC600F_INSN_NORMW_L_U6_, SEM_FN_NAME (arc600f,normw_L_u6_) },
  { ARC600F_INSN_NOP_S, SEM_FN_NAME (arc600f,nop_s) },
  { ARC600F_INSN_UNIMP_S, SEM_FN_NAME (arc600f,unimp_s) },
  { ARC600F_INSN_POP_S_B, SEM_FN_NAME (arc600f,pop_s_b) },
  { ARC600F_INSN_POP_S_BLINK, SEM_FN_NAME (arc600f,pop_s_blink) },
  { ARC600F_INSN_PUSH_S_B, SEM_FN_NAME (arc600f,push_s_b) },
  { ARC600F_INSN_PUSH_S_BLINK, SEM_FN_NAME (arc600f,push_s_blink) },
  { ARC600F_INSN_MULLW_L_S12__RA_, SEM_FN_NAME (arc600f,mullw_L_s12__RA_) },
  { ARC600F_INSN_MULLW_CCU6__RA_, SEM_FN_NAME (arc600f,mullw_ccu6__RA_) },
  { ARC600F_INSN_MULLW_L_U6__RA_, SEM_FN_NAME (arc600f,mullw_L_u6__RA_) },
  { ARC600F_INSN_MULLW_L_R_R__RA__RC, SEM_FN_NAME (arc600f,mullw_L_r_r__RA__RC) },
  { ARC600F_INSN_MULLW_CC__RA__RC, SEM_FN_NAME (arc600f,mullw_cc__RA__RC) },
  { ARC600F_INSN_MACLW_L_S12__RA_, SEM_FN_NAME (arc600f,maclw_L_s12__RA_) },
  { ARC600F_INSN_MACLW_CCU6__RA_, SEM_FN_NAME (arc600f,maclw_ccu6__RA_) },
  { ARC600F_INSN_MACLW_L_U6__RA_, SEM_FN_NAME (arc600f,maclw_L_u6__RA_) },
  { ARC600F_INSN_MACLW_L_R_R__RA__RC, SEM_FN_NAME (arc600f,maclw_L_r_r__RA__RC) },
  { ARC600F_INSN_MACLW_CC__RA__RC, SEM_FN_NAME (arc600f,maclw_cc__RA__RC) },
  { ARC600F_INSN_MACHLW_L_S12__RA_, SEM_FN_NAME (arc600f,machlw_L_s12__RA_) },
  { ARC600F_INSN_MACHLW_CCU6__RA_, SEM_FN_NAME (arc600f,machlw_ccu6__RA_) },
  { ARC600F_INSN_MACHLW_L_U6__RA_, SEM_FN_NAME (arc600f,machlw_L_u6__RA_) },
  { ARC600F_INSN_MACHLW_L_R_R__RA__RC, SEM_FN_NAME (arc600f,machlw_L_r_r__RA__RC) },
  { ARC600F_INSN_MACHLW_CC__RA__RC, SEM_FN_NAME (arc600f,machlw_cc__RA__RC) },
  { ARC600F_INSN_MULULW_L_S12__RA_, SEM_FN_NAME (arc600f,mululw_L_s12__RA_) },
  { ARC600F_INSN_MULULW_CCU6__RA_, SEM_FN_NAME (arc600f,mululw_ccu6__RA_) },
  { ARC600F_INSN_MULULW_L_U6__RA_, SEM_FN_NAME (arc600f,mululw_L_u6__RA_) },
  { ARC600F_INSN_MULULW_L_R_R__RA__RC, SEM_FN_NAME (arc600f,mululw_L_r_r__RA__RC) },
  { ARC600F_INSN_MULULW_CC__RA__RC, SEM_FN_NAME (arc600f,mululw_cc__RA__RC) },
  { ARC600F_INSN_MACHULW_L_S12__RA_, SEM_FN_NAME (arc600f,machulw_L_s12__RA_) },
  { ARC600F_INSN_MACHULW_CCU6__RA_, SEM_FN_NAME (arc600f,machulw_ccu6__RA_) },
  { ARC600F_INSN_MACHULW_L_U6__RA_, SEM_FN_NAME (arc600f,machulw_L_u6__RA_) },
  { ARC600F_INSN_MACHULW_L_R_R__RA__RC, SEM_FN_NAME (arc600f,machulw_L_r_r__RA__RC) },
  { ARC600F_INSN_MACHULW_CC__RA__RC, SEM_FN_NAME (arc600f,machulw_cc__RA__RC) },
  { ARC600F_INSN_CURRENT_LOOP_END, SEM_FN_NAME (arc600f,current_loop_end) },
  { ARC600F_INSN_CURRENT_LOOP_END_AFTER_BRANCH, SEM_FN_NAME (arc600f,current_loop_end_after_branch) },
  { ARC600F_INSN_ARC600_CURRENT_LOOP_END_AFTER_BRANCH, SEM_FN_NAME (arc600f,arc600_current_loop_end_after_branch) },
  { 0, 0 }
};

/* Add the semantic fns to IDESC_TABLE.  */

void
SEM_FN_NAME (arc600f,init_idesc_table) (SIM_CPU *current_cpu)
{
  IDESC *idesc_table = CPU_IDESC (current_cpu);
  const struct sem_fn_desc *sf;
  int mach_num = MACH_NUM (CPU_MACH (current_cpu));

  for (sf = &sem_fns[0]; sf->fn != 0; ++sf)
    {
      const CGEN_INSN *insn = idesc_table[sf->index].idata;
      int valid_p = (CGEN_INSN_VIRTUAL_P (insn)
		     || CGEN_INSN_MACH_HAS_P (insn, mach_num));
#if FAST_P
      if (valid_p)
	idesc_table[sf->index].sem_fast = sf->fn;
      else
	idesc_table[sf->index].sem_fast = SEM_FN_NAME (arc600f,x_invalid);
#else
      if (valid_p)
	idesc_table[sf->index].sem_full = sf->fn;
      else
	idesc_table[sf->index].sem_full = SEM_FN_NAME (arc600f,x_invalid);
#endif
    }
}

