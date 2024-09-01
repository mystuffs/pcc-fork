	.file "nfree.c"
	.section .rodata
size_suffix:
	.byte 66
	.byte 75
	.byte 77
	.byte 71
	.byte 84
	.byte 80
	.byte 0
	.section .text
	.align 4
conv_to_u64:
	pushq %rbp
	movq %rsp,%rbp
	subq $48,%rsp
.L1065:
	movq %rdi,-24(%rbp)
.L1069:
	leaq -16(%rbp),%rax
	movq %rax,-32(%rbp)
	movl $10,%edx
	movq -32(%rbp),%rsi
	movq -24(%rbp),%rdi
	call strtoull
	movq %rax,-8(%rbp)
	xorl %eax,%eax
	call __errno_location
	cmpl $0,(%rax)
	je .L1071
	movabs $.L1073,%rsi
	movl $1,%edi
	xorl %eax,%eax
	call err
.L1071:
	movq -16(%rbp),%rax
	cmpq -24(%rbp),%rax
	jne .L1075
	movabs $.L1077,%rsi
	movl $1,%edi
	xorl %eax,%eax
	call errx
.L1075:
	movq -8(%rbp),%rax
	movq %rax,-40(%rbp)
	jmp .L1067
.L1067:
	movq -40(%rbp),%rax
	leave
	ret
	.size conv_to_u64,.-conv_to_u64
	.section .rodata
	.align 8
.L1089:
	.long 0
	.long 1072693248
	.align 8
.L1091:
	.long 0
	.long 1072693248
	.section .text
	.align 4
pretty_size:
	pushq %rbp
	movq %rsp,%rbp
	subq $256,%rsp
.L1099:
	movq %rdi,-48(%rbp)
	movl %esi,-52(%rbp)
	movl %edx,-56(%rbp)
	movl %ecx,-60(%rbp)
.L1103:
	cmpl $0,-56(%rbp)
	je .L1105
	movl $1000,-32(%rbp)
	jmp .L1107
.L1105:
	movl $1024,-32(%rbp)
.L1107:
	movl -32(%rbp),%eax
	movl %eax,-20(%rbp)
	movq -48(%rbp),%rax
	salq $10,%rax
	movq %rax,-8(%rbp)
	movabs $1,%rsi
	movabs $2048,%rdi
	call calloc
	movq %rax,-16(%rbp)
	cmpq $0,-16(%rbp)
	jne .L1109
	movabs $.L1111,%rsi
	movl $1,%edi
	xorl %eax,%eax
	call err
.L1109:
	cmpl $0,-60(%rbp)
	je .L1113
	movl $0,-24(%rbp)
.L1119:
	cmpl $0,-56(%rbp)
	je .L1121
	movq -16(%rbp),%rax
	movq %rax,-72(%rbp)
	movl -20(%rbp),%eax
	movl %eax,-76(%rbp)
	movl -24(%rbp),%eax
	movl %eax,-80(%rbp)
	movl -80(%rbp),%esi
	movl -76(%rbp),%edi
	call power
	movq -8(%rbp),%rax
	testq %rax,%rax
	js 2f
	cvtsi2sdq %rax,%xmm1
	jmp 3f
2:
	movq %rax,%rdx
	shrq %rdx
	andq $1,%rax
	orq %rax,%rdx
	cvtsi2sdq %rdx,%xmm1
	addsd %xmm1,%xmm1
3:
	divsd %xmm0,%xmm1
	cvtsd2ss %xmm1,%xmm0
	cvtss2sd %xmm0,%xmm0
	movsd %xmm0,-88(%rbp)
	movl -24(%rbp),%eax
	movslq %eax,%rdx
	movabsq $size_suffix,%rax
	movsbl (%rax,%rdx,1),%eax
	movl %eax,-92(%rbp)
	movl -92(%rbp),%ecx
	movsd -88(%rbp),%xmm0
	movabs $.L1123,%rdx
	movabs $2048,%rsi
	movq -72(%rbp),%rdi
	movl $1,%eax
	call snprintf
	movl %eax,-28(%rbp)
	cmpl $4,-28(%rbp)
	jg .L1125
	movq -16(%rbp),%rax
	movq %rax,-104(%rbp)
	jmp .L1101
.L1125:
	movq -16(%rbp),%rax
	movq %rax,-112(%rbp)
	movl -20(%rbp),%eax
	movl %eax,-116(%rbp)
	movl -24(%rbp),%eax
	movl %eax,-120(%rbp)
	movl -120(%rbp),%esi
	movl -116(%rbp),%edi
	call power
	movq -8(%rbp),%rax
	testq %rax,%rax
	js 2f
	cvtsi2sdq %rax,%xmm1
	jmp 3f
2:
	movq %rax,%rdx
	shrq %rdx
	andq $1,%rax
	orq %rax,%rdx
	cvtsi2sdq %rdx,%xmm1
	addsd %xmm1,%xmm1
3:
	divsd %xmm0,%xmm1
	cvttsd2siq %xmm1,%rax
	movq %rax,-128(%rbp)
	movl -24(%rbp),%eax
	movslq %eax,%rdx
	movabsq $size_suffix,%rax
	movsbl (%rax,%rdx,1),%eax
	movl %eax,-132(%rbp)
	movl -132(%rbp),%r8d
	movq -128(%rbp),%rcx
	movabs $.L1127,%rdx
	movabs $2048,%rsi
	movq -112(%rbp),%rdi
	xorl %eax,%eax
	call snprintf
	movl %eax,-28(%rbp)
	cmpl $4,-28(%rbp)
	jg .L1129
	movq -16(%rbp),%rax
	movq %rax,-104(%rbp)
	jmp .L1101
.L1129:
	jmp .L1131
.L1121:
	movq -16(%rbp),%rax
	movq %rax,-144(%rbp)
	movl -20(%rbp),%eax
	movl %eax,-148(%rbp)
	movl -24(%rbp),%eax
	movl %eax,-152(%rbp)
	movl -152(%rbp),%esi
	movl -148(%rbp),%edi
	call power
	movq -8(%rbp),%rax
	testq %rax,%rax
	js 2f
	cvtsi2sdq %rax,%xmm1
	jmp 3f
2:
	movq %rax,%rdx
	shrq %rdx
	andq $1,%rax
	orq %rax,%rdx
	cvtsi2sdq %rdx,%xmm1
	addsd %xmm1,%xmm1
3:
	divsd %xmm0,%xmm1
	cvtsd2ss %xmm1,%xmm0
	cvtss2sd %xmm0,%xmm0
	movsd %xmm0,-160(%rbp)
	movl -24(%rbp),%eax
	movslq %eax,%rdx
	movabsq $size_suffix,%rax
	movsbl (%rax,%rdx,1),%eax
	movl %eax,-164(%rbp)
	movl -164(%rbp),%ecx
	movsd -160(%rbp),%xmm0
	movabs $.L1133,%rdx
	movabs $2048,%rsi
	movq -144(%rbp),%rdi
	movl $1,%eax
	call snprintf
	movl %eax,-28(%rbp)
	cmpl $4,-28(%rbp)
	jg .L1135
	movq -16(%rbp),%rax
	movq %rax,-104(%rbp)
	jmp .L1101
.L1135:
	movq -16(%rbp),%rax
	movq %rax,-176(%rbp)
	movl -20(%rbp),%eax
	movl %eax,-180(%rbp)
	movl -24(%rbp),%eax
	movl %eax,-184(%rbp)
	movl -184(%rbp),%esi
	movl -180(%rbp),%edi
	call power
	movq -8(%rbp),%rax
	testq %rax,%rax
	js 2f
	cvtsi2sdq %rax,%xmm1
	jmp 3f
2:
	movq %rax,%rdx
	shrq %rdx
	andq $1,%rax
	orq %rax,%rdx
	cvtsi2sdq %rdx,%xmm1
	addsd %xmm1,%xmm1
3:
	divsd %xmm0,%xmm1
	cvttsd2siq %xmm1,%rax
	movq %rax,-192(%rbp)
	movl -24(%rbp),%eax
	movslq %eax,%rdx
	movabsq $size_suffix,%rax
	movsbl (%rax,%rdx,1),%eax
	movl %eax,-196(%rbp)
	movl -196(%rbp),%r8d
	movq -192(%rbp),%rcx
	movabs $.L1137,%rdx
	movabs $2048,%rsi
	movq -176(%rbp),%rdi
	xorl %eax,%eax
	call snprintf
	movl %eax,-28(%rbp)
	cmpl $4,-28(%rbp)
	jg .L1139
	movq -16(%rbp),%rax
	movq %rax,-104(%rbp)
	jmp .L1101
.L1139:
.L1131:
.L1115:
	movl -24(%rbp),%eax
	movl %eax,-36(%rbp)
	incl -24(%rbp)
	jmp .L1119
.L1117:
	jmp .L1141
.L1113:
	movl -52(%rbp),%eax
	movl %eax,-200(%rbp)
	jmp .L1145
.L1147:
	movq -16(%rbp),%rax
	movq %rax,-208(%rbp)
	movl -20(%rbp),%eax
	movslq %eax,%rcx
	movq -8(%rbp),%rax
	xorq %rdx,%rdx
	divq %rcx
	movq %rax,%rcx
	movq %rcx,-216(%rbp)
	movq -216(%rbp),%rcx
	movabs $.L1149,%rdx
	movabs $2048,%rsi
	movq -208(%rbp),%rdi
	xorl %eax,%eax
	call snprintf
	jmp .L1143
.L1151:
	movq -16(%rbp),%rax
	movq %rax,-224(%rbp)
	movq -8(%rbp),%rax
	movq %rax,-232(%rbp)
	movq -232(%rbp),%rcx
	movabs $.L1149,%rdx
	movabs $2048,%rsi
	movq -224(%rbp),%rdi
	xorl %eax,%eax
	call snprintf
	jmp .L1143
.L1153:
	movq -16(%rbp),%rax
	movq %rax,-240(%rbp)
	movl -20(%rbp),%eax
	movl %eax,-244(%rbp)
	movl -52(%rbp),%eax
	decl %eax
	movl %eax,-248(%rbp)
	movl -248(%rbp),%esi
	movl -244(%rbp),%edi
	call power
	movq -8(%rbp),%rax
	testq %rax,%rax
	js 2f
	cvtsi2sdq %rax,%xmm1
	jmp 3f
2:
	movq %rax,%rdx
	shrq %rdx
	andq $1,%rax
	orq %rax,%rdx
	cvtsi2sdq %rdx,%xmm1
	addsd %xmm1,%xmm1
3:
	divsd %xmm0,%xmm1
	movabsq $0x43e0000000000000,%rax
	movd %rax,%xmm0
	ucomisd %xmm0,%xmm1
	jae 2f
	cvttsd2siq %xmm1,%rax
	jmp 3f
2:
	subsd %xmm0,%xmm1
	cvttsd2siq %xmm1,%rax
	movabsq $0x8000000000000000,%rdx
	xorq %rdx,%rax
3:

	movq %rax,-256(%rbp)
	movq -256(%rbp),%rcx
	movabs $.L1149,%rdx
	movabs $2048,%rsi
	movq -240(%rbp),%rdi
	xorl %eax,%eax
	call snprintf
	jmp .L1143
.L1145:
	cmpl $0,-200(%rbp)
	je .L1147
	cmpl $1,-200(%rbp)
	je .L1151
	jmp .L1153
.L1143:
	movq -16(%rbp),%rax
	movq %rax,-104(%rbp)
	jmp .L1101
.L1141:
.L1101:
	movq -104(%rbp),%rax
	leave
	ret
	.size pretty_size,.-pretty_size
	.align 4
power:
	pushq %rbp
	movq %rsp,%rbp
	subq $32,%rsp
.L1155:
	movl %edi,-16(%rbp)
	movl %esi,-20(%rbp)
.L1159:
	cmpl $0,-20(%rbp)
	jne .L1161
	movsd .L1089(%rip),%xmm0
	movsd %xmm0,-32(%rbp)
	jmp .L1157
.L1161:
	movsd .L1091(%rip),%xmm0
	movsd %xmm0,-8(%rbp)
.L1167:
	movl -20(%rbp),%eax
	movl %eax,-12(%rbp)
	decl -20(%rbp)
	cmpl $0,-12(%rbp)
	je .L1169
	movsd -8(%rbp),%xmm0
	cvtsi2sd  -16(%rbp),%xmm1
	mulsd %xmm1,%xmm0
	movsd %xmm0,-8(%rbp)
	jmp .L1167
.L1169:
	movsd -8(%rbp),%xmm0
	movsd %xmm0,-32(%rbp)
	jmp .L1157
.L1157:
	movsd -32(%rbp),%xmm0
	leave
	ret
	.size power,.-power
	.align 4
read_meminfo_file:
	pushq %rbp
	movq %rsp,%rbp
	subq $320,%rsp
.L1173:
.L1177:
	xorl %esi,%esi
	movabs $.L1179,%rdi
	xorl %eax,%eax
	call open
	movl %eax,-4(%rbp)
	cmpl $-1,-4(%rbp)
	jne .L1181
	xorl %eax,%eax
	call __errno_location
	cmpl $2,(%rax)
	jne .L1183
	movabs $.L1185,%rsi
	movl $1,%edi
	xorl %eax,%eax
	call errx
.L1183:
	movabs $.L1187,%rsi
	movl $1,%edi
	xorl %eax,%eax
	call err
.L1181:
	movabs $1,%rsi
	movabs $1,%rdi
	call calloc
	movq %rax,-216(%rbp)
	cmpq $0,-216(%rbp)
	jne .L1189
	movabs $.L1111,%rsi
	movl $1,%edi
	xorl %eax,%eax
	call err
.L1189:
	leaq -204(%rbp),%rax
	movq %rax,-240(%rbp)
	movabs $200,%rdx
	xorl %esi,%esi
	movq -240(%rbp),%rdi
	call memset
	xorq %rax,%rax
	movq %rax,-232(%rbp)
	movq %rax,-224(%rbp)
.L1191:
	movl -4(%rbp),%eax
	movl %eax,-244(%rbp)
	leaq -204(%rbp),%rax
	movq %rax,-256(%rbp)
	movabs $199,%rdx
	movq -256(%rbp),%rsi
	movl -244(%rbp),%edi
	call read
	cmpq $0,%rax
	jle .L1193
	cmpq $200,-224(%rbp)
	ja .L1195
	movabsq $800,%rax
	movq %rax,-224(%rbp)
	movq -216(%rbp),%rax
	movq %rax,-264(%rbp)
	movq -232(%rbp),%rax
	addq -224(%rbp),%rax
	movq %rax,-272(%rbp)
	movq -272(%rbp),%rsi
	movq -264(%rbp),%rdi
	call realloc
	movq %rax,-216(%rbp)
	cmpq $0,-216(%rbp)
	jne .L1197
	movabs $.L1199,%rsi
	movl $1,%edi
	xorl %eax,%eax
	call err
.L1197:
	movq -224(%rbp),%rax
	addq %rax,-232(%rbp)
	jmp .L1201
.L1195:
	movabsq $200,%rax
	subq %rax,-224(%rbp)
.L1201:
	movq -216(%rbp),%rax
	movq %rax,-280(%rbp)
	movq -280(%rbp),%rdi
	call strlen
	movq -216(%rbp),%rdx
	addq %rax,%rdx
	movq %rdx,-288(%rbp)
	leaq -204(%rbp),%rax
	movq %rax,-296(%rbp)
	movabs $200,%rdx
	movq -296(%rbp),%rsi
	movq -288(%rbp),%rdi
	call memcpy
	leaq -204(%rbp),%rax
	movq %rax,-304(%rbp)
	movabs $199,%rdx
	xorl %esi,%esi
	movq -304(%rbp),%rdi
	call memset
	jmp .L1191
.L1193:
	movl -4(%rbp),%eax
	movl %eax,-308(%rbp)
	movl -308(%rbp),%edi
	call close
	movq -216(%rbp),%rax
	movq %rax,-320(%rbp)
	jmp .L1175
.L1175:
	movq -320(%rbp),%rax
	leave
	ret
	.size read_meminfo_file,.-read_meminfo_file
	.align 4
get_mem_kv:
	pushq %rbp
	movq %rsp,%rbp
	subq $112,%rsp
.L1205:
	movq %rdi,-56(%rbp)
	movq %rsi,-64(%rbp)
.L1209:
	movq -56(%rbp),%rdi
	call strdup
	movq %rax,-16(%rbp)
	cmpq $0,-16(%rbp)
	jne .L1211
	movabs $.L1213,%rsi
	movl $1,%edi
	xorl %eax,%eax
	call err
.L1211:
	movq -16(%rbp),%rax
	movq %rax,-72(%rbp)
	movq -64(%rbp),%rsi
	movq -72(%rbp),%rdi
	call strstr
	movq %rax,-8(%rbp)
	cmpq $0,-8(%rbp)
	jne .L1215
	movq -64(%rbp),%rdx
	movabs $.L1217,%rsi
	movl $1,%edi
	xorl %eax,%eax
	call errx
.L1215:
	movq -8(%rbp),%rax
	movq %rax,-80(%rbp)
	movl $10,%esi
	movq -80(%rbp),%rdi
	call strchr
	subq -8(%rbp),%rax
	movq %rax,-24(%rbp)
	movq -8(%rbp),%rax
	movq -24(%rbp),%rdx
	movb $0,(%rax,%rdx,1)
.L1219:
	movq -8(%rbp),%rax
	movsbl (%rax),%eax
	cmpl $32,%eax
	je .L1221
	movq -8(%rbp),%rax
	movq %rax,-40(%rbp)
	incq -8(%rbp)
	jmp .L1219
.L1221:
.L1223:
	movq -8(%rbp),%rax
	movsbl (%rax),%eax
	cmpl $32,%eax
	jne .L1225
	movq -8(%rbp),%rax
	movq %rax,-48(%rbp)
	incq -8(%rbp)
	jmp .L1223
.L1225:
	movq -8(%rbp),%rax
	movq %rax,-88(%rbp)
	movabs $.L1227,%rsi
	movq -88(%rbp),%rdi
	call strcspn
	movq %rax,-24(%rbp)
	movq -8(%rbp),%rax
	movq -24(%rbp),%rdx
	movb $0,(%rax,%rdx,1)
	movq -8(%rbp),%rax
	movq %rax,-96(%rbp)
	movq -96(%rbp),%rdi
	call conv_to_u64
	movq %rax,-32(%rbp)
	movq -16(%rbp),%rax
	movq %rax,-104(%rbp)
	movq -104(%rbp),%rdi
	call free
	movq -32(%rbp),%rax
	movq %rax,-112(%rbp)
	jmp .L1207
.L1207:
	movq -112(%rbp),%rax
	leave
	ret
	.size get_mem_kv,.-get_mem_kv
	.align 4
do_collect_meminfo:
	pushq %rbp
	movq %rsp,%rbp
	subq $16,%rsp
.L1231:
	movq %rdi,-8(%rbp)
	movq %rsi,-16(%rbp)
.L1235:
	movabs $.L1237,%rsi
	movq -16(%rbp),%rdi
	call get_mem_kv
	movq -8(%rbp),%rdx
	movq %rax,(%rdx)
	movabs $.L1239,%rsi
	movq -16(%rbp),%rdi
	call get_mem_kv
	movq -8(%rbp),%rdx
	movabsq $8,%rcx
	movq %rax,(%rdx,%rcx,1)
	movabs $.L1241,%rsi
	movq -16(%rbp),%rdi
	call get_mem_kv
	movq -8(%rbp),%rdx
	movabsq $16,%rcx
	movq %rax,(%rdx,%rcx,1)
	movabs $.L1243,%rsi
	movq -16(%rbp),%rdi
	call get_mem_kv
	movq -8(%rbp),%rdx
	movabsq $24,%rcx
	movq %rax,(%rdx,%rcx,1)
	movabs $.L1245,%rsi
	movq -16(%rbp),%rdi
	call get_mem_kv
	movq -8(%rbp),%rdx
	movabsq $32,%rcx
	movq %rax,(%rdx,%rcx,1)
	movabs $.L1247,%rsi
	movq -16(%rbp),%rdi
	call get_mem_kv
	movq -8(%rbp),%rdx
	movabsq $40,%rcx
	movq %rax,(%rdx,%rcx,1)
	movabs $.L1249,%rsi
	movq -16(%rbp),%rdi
	call get_mem_kv
	movq -8(%rbp),%rdx
	movabsq $48,%rcx
	movq %rax,(%rdx,%rcx,1)
	movabs $.L1251,%rsi
	movq -16(%rbp),%rdi
	call get_mem_kv
	movq -8(%rbp),%rdx
	movabsq $56,%rcx
	movq %rax,(%rdx,%rcx,1)
.L1233:
	leave
	ret
	.size do_collect_meminfo,.-do_collect_meminfo
	.align 4
print_collected_info:
	pushq %rbp
	movq %rsp,%rbp
	subq $80,%rsp
.L1255:
	movq %rdi,-16(%rbp)
.L1259:
	movq -16(%rbp),%rdx
	movq (%rdx),%rax
	movq -16(%rbp),%rdx
	movabsq $16,%rcx
	subq (%rdx,%rcx,1),%rax
	movq %rax,-8(%rbp)
	movq -16(%rbp),%rax
	movq (%rax),%rdx
	movq %rdx,-24(%rbp)
	movl $1,%ecx
	xorl %edx,%edx
	movl $1,%esi
	movq -24(%rbp),%rdi
	call pretty_size
	movq %rax,-32(%rbp)
	movq -32(%rbp),%rdx
	movabs $.L1261,%rsi
	movq stdout(%rip),%rdi
	xorl %eax,%eax
	call fprintf
	movq -8(%rbp),%rax
	movq %rax,-40(%rbp)
	movl $1,%ecx
	xorl %edx,%edx
	movl $1,%esi
	movq -40(%rbp),%rdi
	call pretty_size
	movq %rax,-48(%rbp)
	movq -48(%rbp),%rdx
	movabs $.L1261,%rsi
	movq stdout(%rip),%rdi
	xorl %eax,%eax
	call fprintf
	movq -16(%rbp),%rax
	movabsq $8,%rdx
	movq (%rax,%rdx,1),%rcx
	movq %rcx,-56(%rbp)
	movl $1,%ecx
	xorl %edx,%edx
	movl $1,%esi
	movq -56(%rbp),%rdi
	call pretty_size
	movq %rax,-64(%rbp)
	movq -64(%rbp),%rdx
	movabs $.L1261,%rsi
	movq stdout(%rip),%rdi
	xorl %eax,%eax
	call fprintf
	movq -16(%rbp),%rax
	movabsq $24,%rdx
	movq (%rax,%rdx,1),%rcx
	movq %rcx,-72(%rbp)
	movl $1,%ecx
	xorl %edx,%edx
	movl $1,%esi
	movq -72(%rbp),%rdi
	call pretty_size
	movq %rax,-80(%rbp)
	movq -80(%rbp),%rdx
	movabs $.L1261,%rsi
	movq stdout(%rip),%rdi
	xorl %eax,%eax
	call fprintf
.L1257:
	leave
	ret
	.size print_collected_info,.-print_collected_info
	.align 4
	.globl main
	.type main,@function
main:
	pushq %rbp
	movq %rsp,%rbp
	subq $112,%rsp
.L1265:
.L1269:
	xorl %eax,%eax
	call read_meminfo_file
	movq %rax,-8(%rbp)
	leaq -80(%rbp),%rax
	movq %rax,-88(%rbp)
	movq -8(%rbp),%rax
	movq %rax,-96(%rbp)
	movq -96(%rbp),%rsi
	movq -88(%rbp),%rdi
	call do_collect_meminfo
	leaq -80(%rbp),%rax
	movq %rax,-104(%rbp)
	movq -104(%rbp),%rdi
	call print_collected_info
.L1267:
	leave
	ret
	.size main,.-main
	.section .rodata
.L1261:
	.ascii "%s\012\0"
.L1251:
	.ascii "SwapFree:\0"
.L1249:
	.ascii "SwapTotal:\0"
.L1247:
	.ascii "Cached:\0"
.L1245:
	.ascii "Buffers:\0"
.L1243:
	.ascii "Shmem:\0"
.L1241:
	.ascii "MemAvailable:\0"
.L1239:
	.ascii "MemFree:\0"
.L1237:
	.ascii "MemTotal:\0"
.L1227:
	.ascii " \0"
.L1217:
	.ascii "cannot get value of the provided key: '%s'\0"
.L1213:
	.ascii "strdup()\0"
.L1199:
	.ascii "realloc()\0"
.L1187:
	.ascii "open()\0"
.L1185:
	.ascii "cannot find /proc/meminfo. Is /proc mounted?\0"
.L1179:
	.ascii "/proc/meminfo\0"
.L1149:
	.ascii "%lld\0"
.L1137:
	.ascii "%ld%c\0"
.L1133:
	.ascii "%.1f%c\0"
.L1127:
	.ascii "%ld%ci\0"
.L1123:
	.ascii "%.1f%ci\0"
.L1111:
	.ascii "calloc()\0"
.L1077:
	.ascii "no digits are available in that string.\0"
.L1073:
	.ascii "strtoull()\0"
	.section	.note.GNU-stack,"",@progbits
	.ident "PCC: Portable C Compiler 1.2.0.DEVEL 20231021 for x86_64-pc-linux-gnu"
	.end
