#ifndef __PUBLIC_API___H
#define __PUBLIC_API___H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t Char0;//LSB
    uint8_t Char1;
    uint8_t Char2;
    uint8_t Char3;//MSB
}FourChar;

typedef union{
    int32_t  Int32;
    uint32_t Uint32;
    FourChar Char;
}Bit32;

typedef struct {
    uint8_t Char0;//LSB
    uint8_t Char1;//MSB
}TwoChar;

typedef union{
    int16_t  Int16;
    uint16_t Uint16;
    TwoChar Char;
}Bit16;

#define SET_BIT(REG, BIT)               		((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)             		((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)              		((REG) & (BIT))
#define CLEAR_REG(REG)                  		((REG) = (0x0))
#define WRITE_REG(REG, VAL)             		((REG) = (VAL))
#define READ_REG(REG)                   		((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)	WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define SET_BIT_N(x, n)                 (x |= 1U <<n)                           //单个位置位操作 
#define CLR_BIT_N(x, n)                 (x &= ~(1U << n))                       //单个位清零操作 
#define READ_BIT_N(x, n)                (x & (1U << n))                         //读取单个位操作
#define SET_BNAD_BIT_N(x, m, n)					(x |= (~((~0U) << (m-n+1)) << n))       //BITn~BITm置位操作 
#define CLR_BNAD_BIT_N(x, m, n)					(x &= ((~0U) << (m-n+1)) << n)          //BITn~BITm清零操作
#define READ_BAND_BIT_N(x, m, n) 				((x &= ~((~0U) << (m-n+1)) << n) >> n)  //读取BITn~BITm操作

#define GET_BUFF_LEN(arr)               (sizeof(arr)/sizeof(arr[0]))            //缓存区大小计算
#define GetMemberOffset(Type, member)   ((uint32_t)(&(((Type*)0)->member)))     //结构体变量偏移量计算

#define MIN(i, j) 											(((i) < (j)) ? (i) : (j))//取较小的值
#define MAX(i, j) 											(((i) > (j)) ? (i) : (j))//取较大的值

#define ADD_NUM_LIMIT(obj,limit)				(obj = (obj+1)%limit)
#define SUB_NUM_LIMIT(obj,limit)				(obj = ((obj?obj:limit)-1))

#define hex_to_str(__str,__hex,__len)   hex2str(__str,__hex,__len)

#define TYPE_CHECK_SIZE(type, size) 		extern int sizeof_##type##_is_error[(sizeof(type)<=(unsigned long)(size))]//结构体大小校验

uint32_t ByteLittle_GetUint32           (uint8_t *pBuf);                        //小端转整形
int32_t  ByteLittle_GetInt32            (uint8_t *pBuf);                        //小端转整形
uint16_t ByteLittle_GetUint16           (uint8_t *pBuf);                        //小端转整形
int16_t  ByteLittle_GetInt16            (uint8_t *pBuf);                        //小端转整形

uint32_t ByteBig_GetUint32              (uint8_t *pBuf);                        //小端转整形
int32_t  ByteBig_GetInt32               (uint8_t *pBuf);                        //小端转整形
uint16_t ByteBig_GetUint16              (uint8_t *pBuf);                        //小端转整形
int16_t  ByteBig_GetInt16               (uint8_t *pBuf);                        //小端转整形

uint16_t VoidDataToBuf									(void *data,void *buf,uint16_t len,uint8_t dir);//将数据存入缓存区

extern void	BigLitterTurn								(void *data,uint8_t len);               //大小端翻转

extern void Uint32Little_GetByte				(uint32_t Temp,uint8_t *pBuf,uint16_t* pLen);   //小端整形转字节
extern void Int32Little_GetByte					(int32_t Temp,uint8_t *pBuf,uint16_t* pLen);    //小端整形转字节
extern void Uint16Little_GetByte				(uint16_t Temp,uint8_t *pBuf,uint16_t* pLen);   //小端整形转字节
extern void Int16Little_GetByte					(int16_t Temp,uint8_t *pBuf,uint16_t* pLen);    //小端整形转字节

extern void Uint32Big_GetByte						(uint32_t Temp,uint8_t *pBuf,uint16_t* pLen);   //大端整形转字节
extern void Int32Big_GetByte						(int32_t Temp,uint8_t *pBuf,uint16_t* pLen);    //大端整形转字节
extern void Uint16Big_GetByte						(uint16_t Temp,uint8_t *pBuf,uint16_t* pLen);   //大端整形转字节
extern void Int16Big_GetByte						(int16_t Temp,uint8_t *pBuf,uint16_t* pLen);    //大端整形转字节

extern void hex2str(uint8_t *str, uint8_t *hex, uint32_t len);

extern uint16_t GET_CRC16(uint8_t *puchMsg, uint32_t usDataLen);
#endif
