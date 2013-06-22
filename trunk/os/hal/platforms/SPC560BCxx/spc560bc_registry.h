/*
    SPC5 HAL - Copyright (C) 2013 STMicroelectronics

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    SPC560BCxx/spc560bc_registry.h
 * @brief   SPC560B/Cxx capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef _SPC560BC_REGISTRY_H_
#define _SPC560BC_REGISTRY_H_

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    SPC560B/Cxx capabilities
 * @{
 */
/* eDMA attributes.*/
#define SPC5_HAS_EDMA                       FALSE

/* LINFlex attributes.*/
#define SPC5_HAS_LINFLEX0                   TRUE
#define SPC5_LINFLEX0_PCTL                  48
#define SPC5_LINFLEX0_RXI_HANDLER           vector79
#define SPC5_LINFLEX0_TXI_HANDLER           vector80
#define SPC5_LINFLEX0_ERR_HANDLER           vector81
#define SPC5_LINFLEX0_RXI_NUMBER            79
#define SPC5_LINFLEX0_TXI_NUMBER            80
#define SPC5_LINFLEX0_ERR_NUMBER            81
#define SPC5_LINFLEX0_CLK                   (halSPCGetSystemClock() /       \
                                             SPC5_PERIPHERAL1_CLK_DIV_VALUE)

#define SPC5_HAS_LINFLEX1                   TRUE
#define SPC5_LINFLEX1_PCTL                  49
#define SPC5_LINFLEX1_RXI_HANDLER           vector99
#define SPC5_LINFLEX1_TXI_HANDLER           vector100
#define SPC5_LINFLEX1_ERR_HANDLER           vector101
#define SPC5_LINFLEX1_RXI_NUMBER            99
#define SPC5_LINFLEX1_TXI_NUMBER            100
#define SPC5_LINFLEX1_ERR_NUMBER            101
#define SPC5_LINFLEX1_CLK                   (halSPCGetSystemClock() /       \
                                             SPC5_PERIPHERAL1_CLK_DIV_VALUE)

#define SPC5_HAS_LINFLEX2                   TRUE
#define SPC5_LINFLEX2_PCTL                  50
#define SPC5_LINFLEX2_RXI_HANDLER           vector119
#define SPC5_LINFLEX2_TXI_HANDLER           vector120
#define SPC5_LINFLEX2_ERR_HANDLER           vector121
#define SPC5_LINFLEX2_RXI_NUMBER            119
#define SPC5_LINFLEX2_TXI_NUMBER            120
#define SPC5_LINFLEX2_ERR_NUMBER            121
#define SPC5_LINFLEX2_CLK                   (halSPCGetSystemClock() /       \
                                             SPC5_PERIPHERAL1_CLK_DIV_VALUE)

#define SPC5_HAS_LINFLEX3                   TRUE
#define SPC5_LINFLEX3_PCTL                  51
#define SPC5_LINFLEX3_RXI_HANDLER           vector122
#define SPC5_LINFLEX3_TXI_HANDLER           vector123
#define SPC5_LINFLEX3_ERR_HANDLER           vector124
#define SPC5_LINFLEX3_RXI_NUMBER            122
#define SPC5_LINFLEX3_TXI_NUMBER            123
#define SPC5_LINFLEX3_ERR_NUMBER            124
#define SPC5_LINFLEX3_CLK                   (halSPCGetSystemClock() /       \
                                             SPC5_PERIPHERAL1_CLK_DIV_VALUE)

/* SIUL attributes.*/
#define SPC5_HAS_SIUL                       TRUE
#define SPC5_SIUL_PCTL                      68
#define SPC5_SIUL_NUM_PORTS                 8
#define SPC5_SIUL_NUM_PCRS                  123
#define SPC5_SIUL_NUM_PADSELS               32
#define SPC5_SIUL_SYSTEM_PINS               32,33,121,122

/* eMIOS attributes.*/
#define SPC5_HAS_EMIOS0                     TRUE
#define SPC5_EMIOS0_PCTL                    72
#define SPC5_EMIOS0_GFR_F0F1_HANDLER        vector141
#define SPC5_EMIOS0_GFR_F2F3_HANDLER        vector142
#define SPC5_EMIOS0_GFR_F4F5_HANDLER        vector143
#define SPC5_EMIOS0_GFR_F6F7_HANDLER        vector144
#define SPC5_EMIOS0_GFR_F8F9_HANDLER        vector145
#define SPC5_EMIOS0_GFR_F10F11_HANDLER      vector146
#define SPC5_EMIOS0_GFR_F12F13_HANDLER      vector147
#define SPC5_EMIOS0_GFR_F14F15_HANDLER      vector148
#define SPC5_EMIOS0_GFR_F16F17_HANDLER      vector149
#define SPC5_EMIOS0_GFR_F18F19_HANDLER      vector150
#define SPC5_EMIOS0_GFR_F20F21_HANDLER      vector151
#define SPC5_EMIOS0_GFR_F22F23_HANDLER      vector152
#define SPC5_EMIOS0_GFR_F24F25_HANDLER      vector153
#define SPC5_EMIOS0_GFR_F26F27_HANDLER      vector154
#define SPC5_EMIOS0_GFR_F0F1_NUMBER         141
#define SPC5_EMIOS0_GFR_F2F3_NUMBER         142
#define SPC5_EMIOS0_GFR_F4F5_NUMBER         143
#define SPC5_EMIOS0_GFR_F6F7_NUMBER         144
#define SPC5_EMIOS0_GFR_F8F9_NUMBER         145
#define SPC5_EMIOS0_GFR_F10F11_NUMBER       146
#define SPC5_EMIOS0_GFR_F12F13_NUMBER       147
#define SPC5_EMIOS0_GFR_F14F15_NUMBER       148
#define SPC5_EMIOS0_GFR_F16F17_NUMBER       149
#define SPC5_EMIOS0_GFR_F18F19_NUMBER       150
#define SPC5_EMIOS0_GFR_F20F21_NUMBER       151
#define SPC5_EMIOS0_GFR_F22F23_NUMBER       152
#define SPC5_EMIOS0_GFR_F24F25_NUMBER       153
#define SPC5_EMIOS0_GFR_F26F27_NUMBER       154

#define SPC5_EMIOS0_CLK                     (halSPCGetSystemClock() /         \
                                             SPC5_PERIPHERAL3_CLK_DIV_VALUE / \
                                             SPC5_EMIOS0_GPRE_VALUE)


#define SPC5_HAS_EMIOS1                     TRUE
#define SPC5_EMIOS1_PCTL                    73
#define SPC5_EMIOS1_GFR_F0F1_HANDLER        vector157
#define SPC5_EMIOS1_GFR_F2F3_HANDLER        vector158
#define SPC5_EMIOS1_GFR_F4F5_HANDLER        vector159
#define SPC5_EMIOS1_GFR_F6F7_HANDLER        vector160
#define SPC5_EMIOS1_GFR_F8F9_HANDLER        vector161
#define SPC5_EMIOS1_GFR_F10F11_HANDLER      vector162
#define SPC5_EMIOS1_GFR_F12F13_HANDLER      vector163
#define SPC5_EMIOS1_GFR_F14F15_HANDLER      vector164
#define SPC5_EMIOS1_GFR_F16F17_HANDLER      vector165
#define SPC5_EMIOS1_GFR_F18F19_HANDLER      vector166
#define SPC5_EMIOS1_GFR_F20F21_HANDLER      vector167
#define SPC5_EMIOS1_GFR_F22F23_HANDLER      vector168
#define SPC5_EMIOS1_GFR_F24F25_HANDLER      vector169
#define SPC5_EMIOS1_GFR_F26F27_HANDLER      vector170
#define SPC5_EMIOS1_GFR_F0F1_NUMBER         157
#define SPC5_EMIOS1_GFR_F2F3_NUMBER         158
#define SPC5_EMIOS1_GFR_F4F5_NUMBER         159
#define SPC5_EMIOS1_GFR_F6F7_NUMBER         160
#define SPC5_EMIOS1_GFR_F8F9_NUMBER         161
#define SPC5_EMIOS1_GFR_F10F11_NUMBER       162
#define SPC5_EMIOS1_GFR_F12F13_NUMBER       163
#define SPC5_EMIOS1_GFR_F14F15_NUMBER       164
#define SPC5_EMIOS1_GFR_F16F17_NUMBER       165
#define SPC5_EMIOS1_GFR_F18F19_NUMBER       166
#define SPC5_EMIOS1_GFR_F20F21_NUMBER       167
#define SPC5_EMIOS1_GFR_F22F23_NUMBER       168
#define SPC5_EMIOS1_GFR_F24F25_NUMBER       169
#define SPC5_EMIOS1_GFR_F26F27_NUMBER       170

#define SPC5_EMIOS1_CLK                     (halSPCGetSystemClock() /         \
                                             SPC5_PERIPHERAL3_CLK_DIV_VALUE / \
                                             SPC5_EMIOS1_GPRE_VALUE)

/* FlexCAN attributes.*/
#define SPC5_HAS_FLEXCAN0                                   TRUE
#define SPC5_FLEXCAN0_PCTL                                  16
#define SPC5_FLEXCAN0_MB                                    64
#define SPC5_FLEXCAN0_FLEXCAN_ESR_ERR_INT_HANDLER           vector65
#define SPC5_FLEXCAN0_FLEXCAN_ESR_BOFF_HANDLER              vector66
#define SPC5_FLEXCAN0_FLEXCAN_BUF_00_03_HANDLER             vector68
#define SPC5_FLEXCAN0_FLEXCAN_BUF_04_07_HANDLER             vector69
#define SPC5_FLEXCAN0_FLEXCAN_BUF_08_11_HANDLER             vector70
#define SPC5_FLEXCAN0_FLEXCAN_BUF_12_15_HANDLER             vector71
#define SPC5_FLEXCAN0_FLEXCAN_BUF_16_31_HANDLER             vector72
#define SPC5_FLEXCAN0_FLEXCAN_BUF_32_63_HANDLER             vector73
#define SPC5_FLEXCAN0_FLEXCAN_ESR_ERR_INT_NUMBER            65
#define SPC5_FLEXCAN0_FLEXCAN_ESR_BOFF_NUMBER               66
#define SPC5_FLEXCAN0_FLEXCAN_BUF_00_03_NUMBER              68
#define SPC5_FLEXCAN0_FLEXCAN_BUF_04_07_NUMBER              69
#define SPC5_FLEXCAN0_FLEXCAN_BUF_08_11_NUMBER              70
#define SPC5_FLEXCAN0_FLEXCAN_BUF_12_15_NUMBER              71
#define SPC5_FLEXCAN0_FLEXCAN_BUF_16_31_NUMBER              72
#define SPC5_FLEXCAN0_FLEXCAN_BUF_32_63_NUMBER              73
#define SPC5_FLEXCAN0_ENABLE_CLOCK()                        halSPCSetPeripheralClockMode(SPC5_FLEXCAN0_PCTL, SPC5_CAN_FLEXCAN0_START_PCTL);
#define SPC5_FLEXCAN0_DISABLE_CLOCK()                       halSPCSetPeripheralClockMode(SPC5_FLEXCAN0_PCTL, SPC5_CAN_FLEXCAN0_STOP_PCTL);

#define SPC5_HAS_FLEXCAN1                                   TRUE
#define SPC5_FLEXCAN1_PCTL                                  17
#define SPC5_FLEXCAN1_MB                                    64
#define SPC5_FLEXCAN1_FLEXCAN_ESR_ERR_INT_HANDLER           vector85
#define SPC5_FLEXCAN1_FLEXCAN_ESR_BOFF_HANDLER              vector86
#define SPC5_FLEXCAN1_FLEXCAN_BUF_00_03_HANDLER             vector88
#define SPC5_FLEXCAN1_FLEXCAN_BUF_04_07_HANDLER             vector89
#define SPC5_FLEXCAN1_FLEXCAN_BUF_08_11_HANDLER             vector90
#define SPC5_FLEXCAN1_FLEXCAN_BUF_12_15_HANDLER             vector91
#define SPC5_FLEXCAN1_FLEXCAN_BUF_16_31_HANDLER             vector92
#define SPC5_FLEXCAN1_FLEXCAN_BUF_32_63_HANDLER             vector93
#define SPC5_FLEXCAN1_FLEXCAN_ESR_ERR_INT_NUMBER            85
#define SPC5_FLEXCAN1_FLEXCAN_ESR_BOFF_NUMBER               86
#define SPC5_FLEXCAN1_FLEXCAN_BUF_00_03_NUMBER              88
#define SPC5_FLEXCAN1_FLEXCAN_BUF_04_07_NUMBER              89
#define SPC5_FLEXCAN1_FLEXCAN_BUF_08_11_NUMBER              90
#define SPC5_FLEXCAN1_FLEXCAN_BUF_12_15_NUMBER              91
#define SPC5_FLEXCAN1_FLEXCAN_BUF_16_31_NUMBER              92
#define SPC5_FLEXCAN1_FLEXCAN_BUF_32_63_NUMBER              93
#define SPC5_FLEXCAN1_ENABLE_CLOCK()                        halSPCSetPeripheralClockMode(SPC5_FLEXCAN1_PCTL, SPC5_CAN_FLEXCAN1_START_PCTL);
#define SPC5_FLEXCAN1_DISABLE_CLOCK()                       halSPCSetPeripheralClockMode(SPC5_FLEXCAN1_PCTL, SPC5_CAN_FLEXCAN1_STOP_PCTL);

#define SPC5_HAS_FLEXCAN2                                   TRUE
#define SPC5_FLEXCAN2_PCTL                                  18
#define SPC5_FLEXCAN2_MB                                    64
#define SPC5_FLEXCAN2_FLEXCAN_ESR_ERR_INT_HANDLER           vector105
#define SPC5_FLEXCAN2_FLEXCAN_ESR_BOFF_HANDLER              vector106
#define SPC5_FLEXCAN2_FLEXCAN_BUF_00_03_HANDLER             vector108
#define SPC5_FLEXCAN2_FLEXCAN_BUF_04_07_HANDLER             vector109
#define SPC5_FLEXCAN2_FLEXCAN_BUF_08_11_HANDLER             vector110
#define SPC5_FLEXCAN2_FLEXCAN_BUF_12_15_HANDLER             vector111
#define SPC5_FLEXCAN2_FLEXCAN_BUF_16_31_HANDLER             vector112
#define SPC5_FLEXCAN2_FLEXCAN_BUF_32_63_HANDLER             vector113
#define SPC5_FLEXCAN2_FLEXCAN_ESR_ERR_INT_NUMBER            105
#define SPC5_FLEXCAN2_FLEXCAN_ESR_BOFF_NUMBER               106
#define SPC5_FLEXCAN2_FLEXCAN_BUF_00_03_NUMBER              108
#define SPC5_FLEXCAN2_FLEXCAN_BUF_04_07_NUMBER              109
#define SPC5_FLEXCAN2_FLEXCAN_BUF_08_11_NUMBER              110
#define SPC5_FLEXCAN2_FLEXCAN_BUF_12_15_NUMBER              111
#define SPC5_FLEXCAN2_FLEXCAN_BUF_16_31_NUMBER              112
#define SPC5_FLEXCAN2_FLEXCAN_BUF_32_63_NUMBER              113
#define SPC5_FLEXCAN2_ENABLE_CLOCK()                        halSPCSetPeripheralClockMode(SPC5_FLEXCAN2_PCTL, SPC5_CAN_FLEXCAN2_START_PCTL);
#define SPC5_FLEXCAN2_DISABLE_CLOCK()                       halSPCSetPeripheralClockMode(SPC5_FLEXCAN2_PCTL, SPC5_CAN_FLEXCAN2_START_PCTL);

#define SPC5_HAS_FLEXCAN3                                   TRUE
#define SPC5_FLEXCAN3_PCTL                                  19
#define SPC5_FLEXCAN3_MB                                    64
#define SPC5_FLEXCAN3_FLEXCAN_ESR_ERR_INT_HANDLER           vector173
#define SPC5_FLEXCAN3_FLEXCAN_ESR_BOFF_HANDLER              vector174
#define SPC5_FLEXCAN3_FLEXCAN_BUF_00_03_HANDLER             vector176
#define SPC5_FLEXCAN3_FLEXCAN_BUF_04_07_HANDLER             vector177
#define SPC5_FLEXCAN3_FLEXCAN_BUF_08_11_HANDLER             vector178
#define SPC5_FLEXCAN3_FLEXCAN_BUF_12_15_HANDLER             vector179
#define SPC5_FLEXCAN3_FLEXCAN_BUF_16_31_HANDLER             vector180
#define SPC5_FLEXCAN3_FLEXCAN_BUF_32_63_HANDLER             vector181
#define SPC5_FLEXCAN3_FLEXCAN_ESR_ERR_INT_NUMBER            173
#define SPC5_FLEXCAN3_FLEXCAN_ESR_BOFF_NUMBER               174
#define SPC5_FLEXCAN3_FLEXCAN_BUF_00_03_NUMBER              176
#define SPC5_FLEXCAN3_FLEXCAN_BUF_04_07_NUMBER              177
#define SPC5_FLEXCAN3_FLEXCAN_BUF_08_11_NUMBER              178
#define SPC5_FLEXCAN3_FLEXCAN_BUF_12_15_NUMBER              179
#define SPC5_FLEXCAN3_FLEXCAN_BUF_16_31_NUMBER              180
#define SPC5_FLEXCAN3_FLEXCAN_BUF_32_63_NUMBER              181
#define SPC5_FLEXCAN3_ENABLE_CLOCK()                        halSPCSetPeripheralClockMode(SPC5_FLEXCAN3_PCTL, SPC5_CAN_FLEXCAN3_START_PCTL);
#define SPC5_FLEXCAN3_DISABLE_CLOCK()                       halSPCSetPeripheralClockMode(SPC5_FLEXCAN3_PCTL, SPC5_CAN_FLEXCAN3_STOP_PCTL);

#define SPC5_HAS_FLEXCAN4                                   TRUE
#define SPC5_FLEXCAN4_PCTL                                  20
#define SPC5_FLEXCAN4_MB                                    64
#define SPC5_FLEXCAN4_FLEXCAN_ESR_ERR_INT_HANDLER           vector190
#define SPC5_FLEXCAN4_FLEXCAN_ESR_BOFF_HANDLER              vector191
#define SPC5_FLEXCAN4_FLEXCAN_BUF_00_03_HANDLER             vector193
#define SPC5_FLEXCAN4_FLEXCAN_BUF_04_07_HANDLER             vector194
#define SPC5_FLEXCAN4_FLEXCAN_BUF_08_11_HANDLER             vector195
#define SPC5_FLEXCAN4_FLEXCAN_BUF_12_15_HANDLER             vector196
#define SPC5_FLEXCAN4_FLEXCAN_BUF_16_31_HANDLER             vector197
#define SPC5_FLEXCAN4_FLEXCAN_BUF_32_63_HANDLER             vector198
#define SPC5_FLEXCAN4_FLEXCAN_ESR_ERR_INT_NUMBER            190
#define SPC5_FLEXCAN4_FLEXCAN_ESR_BOFF_NUMBER               191
#define SPC5_FLEXCAN4_FLEXCAN_BUF_00_03_NUMBER              193
#define SPC5_FLEXCAN4_FLEXCAN_BUF_04_07_NUMBER              194
#define SPC5_FLEXCAN4_FLEXCAN_BUF_08_11_NUMBER              195
#define SPC5_FLEXCAN4_FLEXCAN_BUF_12_15_NUMBER              196
#define SPC5_FLEXCAN4_FLEXCAN_BUF_16_31_NUMBER              197
#define SPC5_FLEXCAN4_FLEXCAN_BUF_32_63_NUMBER              198
#define SPC5_FLEXCAN4_ENABLE_CLOCK()                        halSPCSetPeripheralClockMode(SPC5_FLEXCAN4_PCTL, SPC5_CAN_FLEXCAN4_START_PCTL);
#define SPC5_FLEXCAN4_DISABLE_CLOCK()                       halSPCSetPeripheralClockMode(SPC5_FLEXCAN4_PCTL, SPC5_CAN_FLEXCAN4_STOP_PCTL);

#define SPC5_HAS_FLEXCAN5                                   TRUE
#define SPC5_FLEXCAN5_PCTL                                  21
#define SPC5_FLEXCAN5_MB                                    64
#define SPC5_FLEXCAN5_FLEXCAN_ESR_ERR_INT_HANDLER           vector202
#define SPC5_FLEXCAN5_FLEXCAN_ESR_BOFF_HANDLER              vector203
#define SPC5_FLEXCAN5_FLEXCAN_BUF_00_03_HANDLER             vector205
#define SPC5_FLEXCAN5_FLEXCAN_BUF_04_07_HANDLER             vector206
#define SPC5_FLEXCAN5_FLEXCAN_BUF_08_11_HANDLER             vector207
#define SPC5_FLEXCAN5_FLEXCAN_BUF_12_15_HANDLER             vector208
#define SPC5_FLEXCAN5_FLEXCAN_BUF_16_31_HANDLER             vector209
#define SPC5_FLEXCAN5_FLEXCAN_BUF_32_63_HANDLER             vector210
#define SPC5_FLEXCAN5_FLEXCAN_ESR_ERR_INT_NUMBER            202
#define SPC5_FLEXCAN5_FLEXCAN_ESR_BOFF_NUMBER               203
#define SPC5_FLEXCAN5_FLEXCAN_BUF_00_03_NUMBER              205
#define SPC5_FLEXCAN5_FLEXCAN_BUF_04_07_NUMBER              206
#define SPC5_FLEXCAN5_FLEXCAN_BUF_08_11_NUMBER              207
#define SPC5_FLEXCAN5_FLEXCAN_BUF_12_15_NUMBER              208
#define SPC5_FLEXCAN5_FLEXCAN_BUF_16_31_NUMBER              209
#define SPC5_FLEXCAN5_FLEXCAN_BUF_32_63_NUMBER              210
#define SPC5_FLEXCAN5_ENABLE_CLOCK()                        halSPCSetPeripheralClockMode(SPC5_FLEXCAN5_PCTL, SPC5_CAN_FLEXCAN5_START_PCTL);
#define SPC5_FLEXCAN5_DISABLE_CLOCK()                       halSPCSetPeripheralClockMode(SPC5_FLEXCAN5_PCTL, SPC5_CAN_FLEXCAN5_STOP_PCTL);
/** @} */

#endif /* _SPC560BC_REGISTRY_H_ */

/** @} */
