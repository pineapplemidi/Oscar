
_newButton:

	MOVF        R0, 0 
	MOVWF       R2 
	MOVF        R1, 0 
	MOVWF       R3 
	MOVF        FARG_newButton_b+0, 0 
	MOVWF       R4 
	MOVF        FARG_newButton_cc+0, 0 
	MOVWF       R5 
	MOVLW       122
	MOVWF       R6 
	CLRF        R7 
	CLRF        R8 
	CLRF        R9 
	CLRF        R10 
	MOVLW       7
	MOVWF       R0 
	MOVF        R2, 0 
	MOVWF       FSR1 
	MOVF        R3, 0 
	MOVWF       FSR1H 
	MOVLW       4
	MOVWF       FSR0 
	MOVLW       0
	MOVWF       FSR0H 
L_newButton0:
	MOVF        POSTINC0+0, 0 
	MOVWF       POSTINC1+0 
	DECF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_newButton0
L_end_newButton:
	RETURN      0
; end of _newButton
