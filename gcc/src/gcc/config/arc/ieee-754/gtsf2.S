#include "arc-ieee-754.h"
/* inputs: r0, r1
   output: c, z flags to be used for 'hi' condition
   clobber: r12,flags  */
/* For NaNs, bit 22.. bit 30 must be set.  */
#if 0 /* DEBUG */
	.global __gtsf2
	.balign 4
	FUNC(__gtsf2)
__gtsf2:
	st.a r11,[sp,-4]` push_s blink` st.a r10,[sp,-4]` st.a r9,[sp,-4]
	st.a r8,[sp,-4]` st.a r7,[sp,-4]` st.a r6,[sp,-4]` st.a r5,[sp,-4]
	st.a r4,[sp,-4]` push_s r3` push_s r2` push_s r1`
	bl.d __gtsf2_c` push_s r0
	mov r11,r0` pop_s r0` pop_s r1` pop_s r2` pop_s r3
	ld.ab r4,[sp,4]` ld.ab r5,[sp,4]` ld.ab r6,[sp,4]`
	ld.ab r7,[sp,4]` ld.ab r8,[sp,4]` ld.ab r9,[sp,4]
	bl.d __gtsf2_asm` ld.ab r10,[sp,4]
	pop_s blink
	brgt.d r11,0,0f
	ld.ab r11,[sp,4]
	jls [blink]
	bl abort
0:	jhi [blink]
	bl abort
	ENDFUNC(__gtsf2)
#define __gtsf2 __gtsf2_asm
#endif /* DEBUG */
	.global __gtsf2
	.balign	4
	HIDDEN_FUNC(__gtsf2)
__gtsf2:
	or.f	r12,r0,r1
	bmi.d	.Lneg
	bmsk_s	r12,r12,23
	add1.f	0,r12,r0 ; check for NaN
	add1.cc.f r12,r12,r1
	j_s.d	[blink]
	cmp.cc	r0,r1
	.balign	4
.Lneg:	breq.d	r0,0,.L0
	add1.f	0,r12,r0 ; check for NaN
	add1.cc.f r12,r12,r1
	j_s.d	[blink]
	cmp.cc r1,r0
	.balign	4
.L0:	bxor.f	0,r1,31 ; check for -0
	j_s.d	[blink]
	cmp.hi	r1,r0
	ENDFUNC(__gtsf2)
