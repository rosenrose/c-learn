	.text
	.def	"@feat.00";
	.scl	3;
	.type	0;
	.endef
	.globl	"@feat.00"
.set "@feat.00", 0
	.file	"adder.c"
	.def	add;
	.scl	2;
	.type	32;
	.endef
	.globl	add                             // -- Begin function add
	.p2align	2
add:                                    // @add
.seh_proc add
// %bb.0:
	sub	sp, sp, #16
	.seh_stackalloc	16
	.seh_endprologue
	str	w1, [sp, #12]
	str	w0, [sp, #8]
	ldr	w8, [sp, #8]
	ldr	w9, [sp, #12]
	add	w0, w8, w9
	.seh_startepilogue
	add	sp, sp, #16
	.seh_stackalloc	16
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.addrsig
