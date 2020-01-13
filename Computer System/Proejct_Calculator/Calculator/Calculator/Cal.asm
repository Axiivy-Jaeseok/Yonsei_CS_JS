INCLUDE Irvine32.inc

.data
in_filename BYTE "input.txt",0
out_filename BYTE "output.txt",0
in_fileHandle HANDLE ?
out_fileHandle HANDLE ?
c_array BYTE 22 DUP(?)


.code
main PROC
; Open the file for input
	mov edx, OFFSET in_filename
	call OpenInputFile
	mov in_fileHandle, eax
; Create the file for output
	mov edx, OFFSET out_filename
	call CreateOutputFile
	mov out_fileHandle, eax

L:
	mov eax, in_fileHandle
	mov edx, OFFSET c_array
	call input_data
	cmp eax, 1
	je close_file
	mov edx, OFFSET c_array
	call calculation
	mov edx, out_fileHandle
	call write_output
	jmp L

Close_file:
	mov eax, in_fileHandle
	call CloseFile
	mov eax, out_fileHandle
	call CloseFile

	exit
main ENDP

;------------------------------------------------------------------
input_data PROC USES ECX
; This procedure gets data from input.txt file
; Receives: EAX = file handle
;			EDX = OFFSET of calculator equation array
; Return: EAX = number of reading char
;------------------------------------------------------------------
.data
	buffer BYTE ?
	i_fileHandle Handle ?
	count DWORD ?
	offs DWORD ?

.code			
	mov i_fileHandle, eax			; input 파일 핸들 저장
	mov esi, edx					; calculator equation array의 오프셋 저장
	mov offs, edx
	mov count, 0					; 변수값 초기화

L:
; Read the char in file into a buffer
	mov eax, i_fileHandle
	mov edx, OFFSET buffer
	mov ecx, 1
	call ReadFromFile
	
; 만약 버퍼에 저장된 문자가 '\'거나 'n'일 때
	cmp buffer, 13
	je L
	cmp buffer, 10
	je L
; 만약 버퍼에 저장된 문자가 null일 때
	cmp buffer, 0
	je quit
; 그 외의 경우 calculation array에 저장
	mov bl, buffer
	mov BYTE PTR [esi], bl
	inc esi
	inc count
; 만약 버퍼에 저장된 문자가 '='일 때
	cmp buffer, 61
	je quit
	jmp L

quit:
	mov eax, count
	mov edx, offs
	ret

input_data ENDP


;---------------------------------------------------------------
calculation PROC USES ESI EBX ECX EDX
;
; Receives: EAX = number of charactors to rad from input file 
;			EDX = offset of c_array
; Return: EAX = result
;---------------------------------------------------------------
.data
push_count BYTE ?							; push count를 저장하는 변수
index_count BYTE ?							; index count를 지정하는 변수
temp DWORD ?								; 숫자 또는 연산자 저장
keep_ECX DWORD ?							; 임시로 ECX 값 저장
powop DWORD ?								; 제곱 연산을 위한 값

.code
; 지역변수 초기화
	mov push_count,0
	mov keep_ECX, 0
	mov powop, 0
	mov esi, edx							; c_array 오프셋 esi에 저장
	mov ebx, 0

	mov ecx, eax							; ecx에  최대 반복횟수 설정
	mov bl, BYTE PTR [esi]
	MOV temp, ebx							; eax 초기화를 위한 과정. 첫번째 index에서 자연수 불러옴
	mov ebx, 0
	SUB temp, 30h							; 숫자 - '0' -> 아스키코드 값을 숫자로 바꿔줌
	MOV eax, temp							; eax 초기화
	CMP BYTE PTR [esi+1], 30h				; 다음 index가 숫자인지 연산자인지 판단
	inc esi
	JB L1									; 숫자라면 L0로 이동, 숫자가 아니면 L1으로 분기

L0: DEC ecx									; index가 증가했으므로 반복횟수인 ecx 감소시킴
											; index_count의 값도 증가시켜줌
	mov bl, BYTE PTR [esi]
	MOV temp, ebx							; temp에 숫자 다시 불러옴
	mov ebx, 0
	SUB temp, 30h
	IMUL eax, 10							; eax에 10을 곱함
	ADD eax, temp							; eax에 temp 더함 -> 2자리수 자연수 완성
	DEC ecx
	INC esi

L1:	
	mov bl,BYTE PTR [esi]
	MOV temp, ebx							; 배열에서 값을 불러옴
	mov ebx, 0
	CMP temp, 30h							; '0'과 비교
	JB	L4									; '0'보다 작을경우 L4로 분기 (연산자는 전부 ASCII코드에서 '0'보다 작음)
	CMP temp, 3dh							; temp가 '='일 경우
	JE	FINCAL

	SUB temp, 30h							; 숫자 - '0' -> 아스키코드 값을 숫자로 바꿔줌
	mov ebx, temp
	CMP BYTE PTR [esi+1], 30h				; 다음 index가 숫자인지 연산자인지 판단
	JB ARICAL								; 숫자가 아니면 ARICAL으로 분기
	CMP BYTE PTR [esi+1], 3dh
	JE ARICAL
	mov ebx, 0
	DEC ecx									; index가 증가했으므로 반복횟수인 ecx 감소시킴
	INC esi									; index_count의 값도 증가시켜줌
	MOV bl, BYTE PTR [esi]					; ebx에 숫자 다시 불러옴
	SUB ebx, 30h							; 숫자 - '0' -> 아스키코드 값을 숫자로 바꿔줌
	XCHG temp, ebx							; ebx와 temp 교환
	IMUL ebx, 10							; ebx에 10을 곱함
	ADD ebx, temp							; ebx에 temp 더함 -> 2자리수 자연수 완성, ebx에 피연산자 저장
	DEC ecx
	
ARICAL: 
	CMP edx, 2ah							; 연산자 비교 후 분기
	JE MULCAL
	CMP edx, 2bh
	JE PLUCAL
	CMP edx, 2dh
	JE MINCAL
	CMP edx, 2fh
	JE DIVCAL
	CMP edx, 23h
	JE POWCAL
	CMP edx, 24h
	JE REMCAL

MULCAL:
	IMUL EAX, EBX							; EAX * EBX 한 후 EAX에 저장
	inc esi
	JMP DONEARI

PLUCAL:
	ADD EAX, EBX							; EAX + EBX 한 후 EAX에 저장
	inc esi
	JMP DONEARI

MINCAL:
	SUB EAX, EBX							; EAX - EBX 한 후 EAX에 저장
	inc esi
	JMP DONEARI

DIVCAL:
	MOV EDX, 0
	CDQ
	IDIV EBX								; EAX / EBX 한 후 EAX에 몫 저장
	inc esi
	JMP DONEARI

REMCAL:
	MOV EDX, 0
	CDQ
	IDIV EBX								; EAX / EBX
	XCHG EAX, EDX							; EAX에는 몫, EDX에는 나머지가 저장되므로 두 값 교환 (EAX에 나머지 저장됨)
	inc esi
	JMP DONEARI

POWCAL:
	MOV keep_ECX, ECX						; Loop를 돌아야하므로 ECX 값을 임시로 저장
	MOV ECX, EBX							; a^b는 a를 b번 곱하는 것이므로 피연산자인 EBX를 반복횟수 ECX에 저장
	DEC ECX
	MOV powop, EAX							; powop에 밑 저장
L3: IMUL powop								; EAX * powop
	LOOP L3
	MOV ECX, keep_ECX						; ECX를 다시 원래 값으로 되돌려 줌
	inc esi
	JMP DONEARI

L4: CMP BYTE PTR [esi+1], 2ah			; 다음 index가 *일 경우
	Je L5
	CMP BYTE PTR [esi+1], 2fh			; 다음 index의 값이 /일 경우
	Je L6
	MOV edx, temp							; 연산자를 edx에 저장해둠
	INC esi									; index_count 증가
	jmp L1

L5:	MOV edx, 23h							; '**'의 케이스를 임의로 23h 값으로 설정
	JMP L7

L6:	MOV edx, 24h							; '//'의 케이스를 임의로 24h 값으로 설정

L7: ADD esi, 2						; index_count 2만큼 증가

DONEARI: 
	jmp L1

FINCAL:
	ret
calculation ENDP


;-------------------------------------------------------------------
write_output PROC USES EAX EBX ECX
; This procedure write results in the output.txt file
; Receives: EAX = result of calculation
;			EDX = file handle
;--------------------------------------------------------------------
.data
	o_fileHandle Handle ?
	result BYTE 11 DUP(?)
	len_result DWORD ?

.code
	mov o_fileHandle, edx			; output 파일 핸들 저장
	mov len_result, 0				; 변수값 초기화

; Save the result in stack	
	mov ecx, 9
	cmp eax, 0
	jge L1	;result가 양수일때 L1으로 이동
	neg eax
L0: ; when result if negative
	;10으로 계속 나누면서 나머지 스택에 저장함
	mov edx, 0
	mov ebx, 10
	div ebx
	push edx
	inc len_result
	cmp eax, 0
	je quit
	loop L0
quit:
	;push edx
	mov ebx, 1
	mov edx, OFFSET result
	mov ecx, len_result
	jmp L2
L1: ; when result is positive
	;10으로 계속 나누면서 나머지 스택에 저장함
	mov edx, 0
	mov ebx, 10
	div ebx
	push edx
	inc len_result
	cmp eax, 0
	je quit1
	loop L1
quit1:
	;push edx ;나머지 저장
	mov ebx, 0
	mov edx, OFFSET result
	mov ecx, len_result
	jmp L3

; Move the result from stack to array
L2:	;음수일때 result배열에 '-' 저장
	mov eax, 45
	mov BYTE PTR [edx], al 
	inc edx
L3:
	pop eax
	add eax, 48
	mov BYTE PTR [edx], al			
	inc edx
	loop L3
	mov eax, 0dh
	mov BYTE PTR [edx], al
	inc edx
	inc len_result
	mov eax, 0ah
	mov BYTE PTR [edx], al
	inc len_result
	add len_result, ebx				;음수이면 result배열 길이 1 증가시킴

; Write the buffer to an output file
	mov eax, o_fileHandle
	mov edx, OFFSET result ;결과값 저장된 배열 주소로 바꾸기
	mov ecx, len_result  ;결과값 저장된 배열 길이로 바꾸기
	call WriteToFile
	
	ret
write_output ENDP

end main