/*
 * bit_operators.h
 *
 * Created: 04-10-2021 12:27:19
 *  Author: Mainframe
 */ 


#ifndef BIT_OPERATORS_H_
#define BIT_OPERATORS_H_

#define get_bit(Port,Bit) (Port & (1<<Bit))
#define set_bit(Port,Bit) (Port|=(1<<Bit)) 
#define clear_bit(Port,Bit) (Port&=~(1<<Bit)) 
#define toggle_bit(Port,Bit) (Port^=(1<<Bit)) 


#define set_byte(Port, byte) (Port |= byte)
#define clear_byte(Port, byte) (Port &= ~(byte))
#define get_byte(Port, byte) (Port & byte)

#endif /* BIT_OPERATORS_H_ */