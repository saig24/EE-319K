; Print.s
; Student names: change this to your names or look very silly
; Last modification date: change this to the last modification date or look very silly
; Runs on LM4F120 or TM4C123
; EE319K lab 7 device driver for any LCD
;
; As part of Lab 7, students need to implement these LCD_OutDec and LCD_OutFix
; This driver assumes two low-level LCD functions
; ST7735_OutChar   outputs a single 8-bit ASCII character
; ST7735_OutString outputs a null-terminated string 

    IMPORT   ST7735_OutChar
    IMPORT   ST7735_OutString
    EXPORT   LCD_OutDec
    EXPORT   LCD_OutFix

    AREA    |.text|, CODE, READONLY, ALIGN=2
    THUMB

  
period		EQU	0x2E
zero		EQU 0x30
star		EQU	0x2A
test3		EQU 999
test4		EQU	9999
;-----------------------LCD_OutDec-----------------------
; Output a 32-bit number in unsigned decimal format
; Input: R0 (call by value) 32-bit unsigned number
; Output: none
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutDec
	MOV R1, R0
	MOV R2, #10
	MOV R3, #1
loop				;counts values in number and puts in R3 
	CMP R1, #9
	BLE out
	UDIV R1, R2
	ADD R3, #1
	B loop
out
					;to be continued
	BX LR 
	  
;* * * * * * * * End of LCD_OutDec * * * * * * * *

; -----------------------LCD _OutFix----------------------
; Output characters to LCD display in fixed-point format
; unsigned decimal, resolution 0.001, range 0.000 to 9.999
; Inputs:  R0 is an unsigned 32-bit number
; Outputs: none
; E.g., R0=0,    then output "0.000 "
;       R0=3,    then output "0.003 "
;       R0=89,   then output "0.089 "
;       R0=123,  then output "0.123 "
;       R0=9999, then output "9.999 "
;       R0>9999, then output "*.*** "
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutFix
	  ;PUSH R13
	  MOV R2, #10
	  MOV R3, #100
	  MOV R12, #1000
oneDigit
	MOV R1, R0				;R1 = input 
	CMP R1, #9				;checking significant ranges
	BGT twoDigit			;jumps to next category if not a fit
	MOV R0, #zero		
	BL ST7735_OutChar
	MOV R0, #period		
	BL ST7735_OutChar
	MOV R0, #zero		
	BL ST7735_OutChar		
	BL ST7735_OutChar
	MOV R0, R1				;reloading input inot R0
	BL findASCII
	BL ST7735_OutChar		;outputting significant bit
	B fin					;returning 
twoDigit
	CMP R1, #99
	BGT threeDigit
	MOV R0, #zero		
	BL ST7735_OutChar
	MOV R0, #period		
	BL ST7735_OutChar
	MOV R0, #zero		
	BL ST7735_OutChar
	UDIV R0, R1, R2
	BL findASCII
	BL ST7735_OutChar
	AND R0, R1, #0x1F
	BL findASCII
	BL ST7735_OutChar
	B fin
threeDigit
	LDR R4, =test3
	LDR R4, [R4]
	CMP R1, R4
	BGT fourDigit
	MOV R0, #zero		
	BL ST7735_OutChar
	MOV R0, #period		
	BL ST7735_OutChar
	UDIV R0, R1, R3
	BL findASCII
	BL ST7735_OutChar
	UDIV R0, R1, R2
	BL findASCII
	BL ST7735_OutChar
	AND R0, R1, #0x1F
	BL findASCII
	BL ST7735_OutChar	
	B fin
fourDigit
	LDR R4, =test4
	LDR R4, [R4]
	CMP R1, R4
	BGT stars
	UDIV R0, R1, R12
	BL findASCII
	BL ST7735_OutChar
	MOV R0, #period
	BL ST7735_OutChar
	UDIV R0, R1, R3
	BL findASCII
	BL ST7735_OutChar
	UDIV R0, R1, R2
	BL findASCII
	BL ST7735_OutChar
	AND R0, R1, #0x1F
	BL findASCII
	BL ST7735_OutChar	
	B fin
stars
	MOV R0, #star		
	BL ST7735_OutChar
	MOV R0, #period		
	BL ST7735_OutChar
	MOV R0, #star		
	BL ST7735_OutChar	
	BL ST7735_OutChar
fin
	;POP R13
    BX  LR
 
findASCII
	CMP R0, #0
	BNE a
	MOV R0, #0x30
	BX LR
a
	CMP R0, #1
	BNE c
	MOV R0, #0x31
	BX LR
c
	CMP R0, #2
	BNE d
	MOV R0, #0x32
	BX LR
d
	CMP R0, #3
	BNE e
	MOV R0, #0x33
	BX LR
e
	CMP R0, #4
	BNE f
	MOV R0, #0x34
	BX LR
f
	CMP R0, #5
	BNE g
	MOV R0, #0x35
	BX LR
g
	CMP R0, #6
	BNE h
	MOV R0, #0x36
	BX LR
h
	CMP R0, #7
	BNE i
	MOV R0, #0x37
	BX LR
i	
	CMP R0, #8
	BNE j
	MOV R0, #0x38
	BX LR
j
	MOV R0, #0x39
	BX  LR 

     ALIGN
;* * * * * * * * End of LCD_OutFix * * * * * * * *

     ALIGN                           ; make sure the end of this section is aligned
     END                             ; end of file
