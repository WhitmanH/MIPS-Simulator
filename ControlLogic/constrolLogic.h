//
// Created by Rui Tu on 11/8/15.
//

#ifndef PROCESSOR_ASSIGNMENT1_CONTROLLOGIC_H
#define PROCESSOR_ASSIGNMENT1_CONTROLLOGIC_H

/*
 * false: The register destination number for the Write register comes from the rt field
 * true:  The register destination number for the Write register comes from the rd field
 * */
extern int Register_Destination_Signal;


/*
 * false: none
 * true:  The second ALU operand comes from the second register file output
 * */
extern int Register_Write_Signal;


/*
 * false: The second ALU operand comes from the second register file output
 * true:  The second ALU operand is the sign- extended, lower 16 bits of the instruction.
 * */
extern int ALU_Src_Signal;


/*
 * false: The PC is replaced by the output of the adder that computes the value of PC + 4
 * true:  The PC is replaced by the output of the adder that computes the branch target.
 * */
extern int PC_Src_Signal;


/*
 * false: None
 * true:  Data memory contents designated by the address input are put on the Read data output.
 * */
extern int Memory_Read_Signal;


/*
 * false: None
 * true:  Data memory contents designated by the address input are replaced by the value on the
 *        Write data input.
 * */
extern int Memory_Write_Signal;


/*
 * false: The value fed to the register Write data input comes from the ALU.
 * true:  The value fed to the register Write data input comes from the data memory.
 * */
extern int Memory_Write_To_Register_Signal;



#endif //PROCESSOR_ASSIGNMENT1_CONTROLLOGIC_H
