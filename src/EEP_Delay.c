// TMS320F2833x   Project.
/****************************************************************************/
/*                                                                          */
/*  @file       : *_Delay.c                                                 */
/*  @Copyright  : DelvisBeans.(c) 2015 MULTIBEANS_ORG All rights reserved.  */
/*  @Revision   : Ver 1.0.                                                  */
/*  @Data       : 2015.04.15 Realse.                                        */
/*  @Belong     : PROJECT.                                                  */
/*                                                                          */
/*  **code : (GBK/GB2312) in Windows 7_x64. CCS v6.0 platform.              */
/****************************************************************************/
/*  @Attention:                                                             */
/*  ---------------------------------------------------------------------   */
/*  |    Data    |  Behavior |     Offer     |          Content         |   */
/*  | 2015.04.15 |   create  |DelvisBeans(M) | ceate the document.      |   */
/*  ---------------------------------------------------------------------   */
/*                                                            MULTIBEANS.   */
/****************************************************************************/
#include "DSP2833x_Device.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
////////////////                延时函数列表                         ////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void Delay_s( Uint16 times );
void Delay_ms( Uint16 times );
void Delay_us( Uint16 times );
void ldelay(unsigned int k) ;
void delay(unsigned int t) ;

// 150MHz 的主频，执行一条指令为6.6666666667ns的时间，所以1us需要150个指令周期
// 延时函数利用汇编语句进行执行。
//////////////////////////////////////////////////////////////////////////////
void Delay_us( Uint16 times ) {
    Uint16 i;

    for( i = 0; i < times; i++ ){
        asm(" RPT #149 || NOP");                // N+1个指令周期，1us
    }

}
//////////////////////////////////////////////////////////////////////////////
void Delay_ms( Uint16 times ) {

    Uint16 i;
    for (i = 0; i < times; i ++) {
        Delay_us( 1000 );
    }
}
//////////////////////////////////////////////////////////////////////////////
void Delay_s( Uint16 times ) {

    Uint16 i;
    for ( i = 0; i < times; i++ ) {
        Delay_ms( 1000 );                       // 1000个ms为1s
    }

}
//////////////////////////////////////////////////////////////////////////////
void ldelay(unsigned int k) {

    while( k > 0 ) {
        k--;
        delay(50000);
    }
}
//////////////////////////////////////////////////////////////////////////////
void delay(unsigned int t) {

    while( t > 0 )
        t--;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
////////////////                END OF FILE.              ////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
