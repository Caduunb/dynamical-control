/*
 * HIL_SS_data.c
 *
 * Real-Time Workshop code generation for Simulink model "HIL_SS.mdl".
 *
 * Model Version              : 1.85
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Jun 18 17:52:32 2019
 */

#include "HIL_SS.h"
#include "HIL_SS_private.h"

/* Block parameters (auto storage) */
Parameters_HIL_SS HIL_SS_P = {
  0.0,                                 /* HILInitialize_OOStart : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOEnter : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOTerminate : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOExit : '<Root>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AIHigh : '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AILow : '<Root>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AOHigh : '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AOLow : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOInitial : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOFinal : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOWatchdog : '<Root>/HIL Initialize'
                                        */
  2.4305934065934067E+004,             /* HILInitialize_POFrequency : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POLeading : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POTrailing : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POInitial : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POFinal : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POWatchdog : '<Root>/HIL Initialize'
                                        */
  1.5339807878856412E-003,             /* rotarycountstorads_Gain : '<Root>/rotary: counts to rads'
                                        */
  5.7295779513082323E+001,             /* Gain_Gain : '<S2>/Gain'
                                        */
  -30.0,                               /* HPFderivativefollowedbyaLPF_A : '<Root>/HPF: derivative  followed by a LPF'
                                        */
  -900.0,                              /* HPFderivativefollowedbyaLPF_C : '<Root>/HPF: derivative  followed by a LPF'
                                        */
  30.0,                                /* HPFderivativefollowedbyaLPF_D : '<Root>/HPF: derivative  followed by a LPF'
                                        */
  -20.0,                               /* TransferFcn_A : '<Root>/Transfer Fcn'
                                        */
  20.0,                                /* TransferFcn_C : '<Root>/Transfer Fcn'
                                        */
  10.0,                                /* Saturation_UpperSat : '<Root>/Saturation'
                                        */
  -10.0,                               /* Saturation_LowerSat : '<Root>/Saturation'
                                        */
  0.0,                                 /* Integrator1_IC : '<Root>/Integrator1'
                                        */
  -3.7035206660581368E-002,            /* Ki_Gain : '<Root>/Ki'
                                        */
  0.0,                                 /* Integrator_IC : '<Root>/Integrator'
                                        */

  /*  K_Gain : '<Root>/K'
   */
  { -8.6179762024065631E-001, -5.0302827530082028E-001 },
  45.0,                                /* SignalGenerator_Amplitude : '<Root>/Signal Generator'
                                        */
  0.2,                                 /* SignalGenerator_Frequency : '<Root>/Signal Generator'
                                        */

  /*  StateSpace_A : '<Root>/State-Space'
   */
  { -3.1788761923850501E+001, -1.4735952404813125E+001, 16.0 },
  16.0,                                /* StateSpace_B : '<Root>/State-Space'
                                        */
  2.2149532133517273E+001,             /* StateSpace_C : '<Root>/State-Space'
                                        */
  0.0,                                 /* StateSpace_X0 : '<Root>/State-Space'
                                        */

  /*  A_Gain : '<Root>/A'
   */
  { -3.1788761923850501E+001, 16.0, -1.4735952404813125E+001, 0.0 },

  /*  B_Gain : '<Root>/B'
   */
  { 16.0, 0.0 },

  /*  C_Gain : '<Root>/C'
   */
  { 0.0, 2.2149532133517273E+001 },

  /*  L_Gain : '<Root>/L'
   */
  { -3.0640910395154908E-001, 4.1586603367620589E-001 },
  1.0,                                 /* Constant_Value : '<S3>/Constant'
                                        */
  1.0,                                 /* Constant1_Value : '<S3>/Constant1'
                                        */
  0.484,                               /* delta2_Gain : '<S3>/delta+//2'
                                        */
  -0.375,                              /* delta2_Gain_d : '<S3>/delta-//2'
                                        */

  /*  HILInitialize_CKChannels : '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },
  0,                                   /* HILInitialize_DOWatchdog : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIInitial : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POModes : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POConfiguration : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POAlignment : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POPolarity : '<Root>/HIL Initialize'
                                        */

  /*  HILInitialize_AIChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_AOChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_DOChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_EIChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* HILInitialize_EIQuadrature : '<Root>/HIL Initialize'
                                        */

  /*  HILInitialize_POChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  0U,                                  /* HILReadEncoder_Channels : '<Root>/HIL Read Encoder'
                                        */
  0U,                                  /* HILWriteAnalog1_Channels : '<Root>/HIL Write Analog1'
                                        */
  1U,                                  /* Constant_Value_g : '<S1>/Constant'
                                        */
  1U,                                  /* SwitchControl_Threshold : '<S1>/SwitchControl'
                                        */
  0,                                   /* HILInitialize_Active : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AIPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOTerminate : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOExit : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOReset : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_DOStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_DOTerminate : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOExit : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOReset : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_EIPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_EIStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POTerminate : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POExit : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POReset : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_OOReset : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOInitial : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOFinal : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILReadEncoder_Active : '<Root>/HIL Read Encoder'
                                        */
  0                                    /* HILWriteAnalog1_Active : '<Root>/HIL Write Analog1'
                                        */
};
