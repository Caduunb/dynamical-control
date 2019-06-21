/*
 * HIL_SS.c
 *
 * Real-Time Workshop code generation for Simulink model "HIL_SS.mdl".
 *
 * Model Version              : 1.85
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Jun 18 17:52:32 2019
 */

#include "HIL_SS.h"
#include "HIL_SS_private.h"
#include <stdio.h>
#include "HIL_SS_dt.h"

/* Block signals (auto storage) */
BlockIO_HIL_SS HIL_SS_B;

/* Continuous states */
ContinuousStates_HIL_SS HIL_SS_X;

/* Block states (auto storage) */
D_Work_HIL_SS HIL_SS_DWork;

/* Real-time model */
RT_MODEL_HIL_SS HIL_SS_M_;
RT_MODEL_HIL_SS *HIL_SS_M = &HIL_SS_M_;

/* Function: rt_WriteMat4FileHeader =========================================
 * Abstract:
 *      Writes out MAT-file header.  Returns success or failure.
 *
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/* This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y,x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  HIL_SS_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (temp*f0[i]);
  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  HIL_SS_output(0);
  HIL_SS_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (temp*f1[i]);
  rtsiSetdX(si, f2);
  HIL_SS_output(0);
  HIL_SS_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (h*f2[i]);
  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  HIL_SS_output(0);
  HIL_SS_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void HIL_SS_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder;
  real_T rtb_TmpHiddenBufferAtToFileInpo[3];
  real_T rtb_Sign;

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(HIL_SS_M)) {
    HIL_SS_M->Timing.t[0] = rtsiGetT(&HIL_SS_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(HIL_SS_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&HIL_SS_M->solverInfo,
                          ((HIL_SS_M->Timing.clockTick0+1)*
      HIL_SS_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    real_T rtb_Ki;
    real_T rtb_L_idx;
    real_T rtb_L_idx_0;
    if (rtmIsMajorTimeStep(HIL_SS_M) &&
        HIL_SS_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function Block: HIL_SS/HIL Read Encoder (hil_read_encoder_block) */
      {
        t_error result = hil_read_encoder(HIL_SS_DWork.HILInitialize_Card,
          &HIL_SS_P.HILReadEncoder_Channels, 1,
          &HIL_SS_DWork.HILReadEncoder_Buffer);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        } else {
          rtb_HILReadEncoder = HIL_SS_DWork.HILReadEncoder_Buffer;
        }
      }

      /* Gain: '<S2>/Gain' incorporates:
       *  Gain: '<Root>/rotary: counts to rads'
       */
      HIL_SS_B.Gain = HIL_SS_P.rotarycountstorads_Gain * rtb_HILReadEncoder *
        HIL_SS_P.Gain_Gain;
    }

    /* TransferFcn Block: '<Root>/HPF: derivative  followed by a LPF' */
    HIL_SS_B.HPFderivativefollowedbyaLPF =
      HIL_SS_P.HPFderivativefollowedbyaLPF_D*HIL_SS_B.Gain;
    HIL_SS_B.HPFderivativefollowedbyaLPF +=
      HIL_SS_P.HPFderivativefollowedbyaLPF_C*
      HIL_SS_X.HPFderivativefollowedbyaLPF_CST;
    if (rtmIsMajorTimeStep(HIL_SS_M) &&
        HIL_SS_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* TransferFcn Block: '<Root>/Transfer Fcn' */
    rtb_Sign = HIL_SS_P.TransferFcn_C*HIL_SS_X.TransferFcn_CSTATE;

    /* Saturate: '<Root>/Saturation' */
    HIL_SS_B.Saturation = rt_SATURATE(rtb_Sign, HIL_SS_P.Saturation_LowerSat,
      HIL_SS_P.Saturation_UpperSat);
    if (rtmIsMajorTimeStep(HIL_SS_M) &&
        HIL_SS_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function Block: HIL_SS/HIL Write Analog1 (hil_write_analog_block) */
      {
        t_error result;
        result = hil_write_analog(HIL_SS_DWork.HILInitialize_Card,
          &HIL_SS_P.HILWriteAnalog1_Channels, 1, &HIL_SS_B.Saturation);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        }
      }
    }

    /* Integrator: '<Root>/Integrator1' */
    rtb_Sign = HIL_SS_X.Integrator1_CSTATE;

    /* Gain: '<Root>/Ki' */
    rtb_Ki = HIL_SS_P.Ki_Gain * rtb_Sign;

    /* Integrator: '<Root>/Integrator' */
    rtb_L_idx = HIL_SS_X.Integrator_CSTATE[0];
    rtb_L_idx_0 = HIL_SS_X.Integrator_CSTATE[1];

    /* Gain: '<Root>/K' */
    rtb_Sign = HIL_SS_P.K_Gain[0] * HIL_SS_X.Integrator_CSTATE[0] +
      HIL_SS_P.K_Gain[1] * HIL_SS_X.Integrator_CSTATE[1];

    /* Sum: '<Root>/Sum10' */
    HIL_SS_B.Sum10 = (0.0 - rtb_Ki) - rtb_Sign;
    if (rtmIsMajorTimeStep(HIL_SS_M) &&
        HIL_SS_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* SignalGenerator: '<Root>/Signal Generator' */
    {
      real_T phase = HIL_SS_P.SignalGenerator_Frequency*HIL_SS_M->Timing.t[0];
      phase = phase-floor(phase);
      HIL_SS_B.SignalGenerator = ( phase >= 0.5 ) ?
        HIL_SS_P.SignalGenerator_Amplitude : -HIL_SS_P.SignalGenerator_Amplitude;
    }

    /* StateSpace Block: '<Root>/State-Space' */
    {
      rtb_Sign = HIL_SS_P.StateSpace_C*HIL_SS_X.StateSpace_CSTATE[1];
    }

    /* Switch: '<S1>/SwitchControl' incorporates:
     *  Constant: '<S1>/Constant'
     */
    if (HIL_SS_P.Constant_Value_g > HIL_SS_P.SwitchControl_Threshold) {
      HIL_SS_B.SwitchControl = rtb_Sign;
    } else {
      HIL_SS_B.SwitchControl = HIL_SS_B.HPFderivativefollowedbyaLPF;
    }

    if (rtmIsMajorTimeStep(HIL_SS_M) &&
        HIL_SS_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion: '<Root>/TmpHiddenBufferAtTo FileInport1' */
      rtb_TmpHiddenBufferAtToFileInpo[0] = HIL_SS_B.SignalGenerator;
      rtb_TmpHiddenBufferAtToFileInpo[1] = HIL_SS_B.SwitchControl;
      rtb_TmpHiddenBufferAtToFileInpo[2] = HIL_SS_B.HPFderivativefollowedbyaLPF;

      /* ToFile: '<Root>/To File' */
      if (rtmIsMajorTimeStep(HIL_SS_M)) {
        if (!(++HIL_SS_DWork.ToFile_IWORK.Decimation % 1) &&
            (HIL_SS_DWork.ToFile_IWORK.Count*4)+1 < 100000000 ) {
          real_T u[4];
          FILE *fp = (FILE *) HIL_SS_DWork.ToFile_PWORK.FilePtr;
          if (fp != (NULL)) {
            HIL_SS_DWork.ToFile_IWORK.Decimation = 0;
            u[0] = HIL_SS_M->Timing.t[1];
            u[1] = rtb_TmpHiddenBufferAtToFileInpo[0];
            u[2] = rtb_TmpHiddenBufferAtToFileInpo[1];
            u[3] = rtb_TmpHiddenBufferAtToFileInpo[2];
            if (fwrite(u, sizeof(real_T), 4, fp) != 4) {
              rtmSetErrorStatus(HIL_SS_M,
                                "Error writing to MAT-file HILSSPACE.mat");
              return;
            }

            if (((++HIL_SS_DWork.ToFile_IWORK.Count)*4)+1 >= 100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file HILSSPACE.mat.\n");
            }
          }
        }
      }
    }

    /* Gain: '<Root>/C' */
    rtb_Sign = HIL_SS_P.C_Gain[0] * rtb_L_idx + HIL_SS_P.C_Gain[1] * rtb_L_idx_0;

    /* Sum: '<Root>/Sum9' */
    rtb_Sign = HIL_SS_B.SwitchControl - rtb_Sign;

    /* Signum: '<S3>/Sign' */

    /* Sum: '<Root>/Sum8' incorporates:
     *  Gain: '<Root>/A'
     *  Gain: '<Root>/B'
     *  Gain: '<Root>/L'
     */
    HIL_SS_B.Sum8[0] = (HIL_SS_P.B_Gain[0] * HIL_SS_B.Sum10 + HIL_SS_P.L_Gain[0]
                        * rtb_Sign) + (HIL_SS_P.A_Gain[0] * rtb_L_idx +
      HIL_SS_P.A_Gain[2] * rtb_L_idx_0);

    /* Sum: '<Root>/Sum8' incorporates:
     *  Gain: '<Root>/A'
     *  Gain: '<Root>/B'
     *  Gain: '<Root>/L'
     */
    HIL_SS_B.Sum8[1] = (HIL_SS_P.B_Gain[1] * HIL_SS_B.Sum10 + HIL_SS_P.L_Gain[1]
                        * rtb_Sign) + (HIL_SS_P.A_Gain[1] * rtb_L_idx +
      HIL_SS_P.A_Gain[3] * rtb_L_idx_0);
    rtb_Sign = rt_SIGNd_snf(HIL_SS_B.Sum10);

    /* Sum: '<S3>/Sum4' incorporates:
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/Constant1'
     *  Gain: '<S3>/delta+//2'
     *  Gain: '<S3>/delta-//2'
     *  Product: '<S3>/Divide'
     *  Sum: '<S3>/Sum5'
     *  Sum: '<S3>/Sum6'
     *  Sum: '<S3>/Sum7'
     */
    HIL_SS_B.Sum4 = ((HIL_SS_P.Constant_Value + rtb_Sign) * HIL_SS_P.delta2_Gain
                     - (HIL_SS_P.Constant1_Value - rtb_Sign) *
                     HIL_SS_P.delta2_Gain_d) * rtb_Sign + HIL_SS_B.Sum10;

    /* Sum: '<Root>/Sum11' */
    HIL_SS_B.Sum11 = HIL_SS_B.SignalGenerator - HIL_SS_B.SwitchControl;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void HIL_SS_update(int_T tid)
{
  if (rtmIsMajorTimeStep(HIL_SS_M)) {
    rt_ertODEUpdateContinuousStates(&HIL_SS_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++HIL_SS_M->Timing.clockTick0))
    ++HIL_SS_M->Timing.clockTickH0;
  HIL_SS_M->Timing.t[0] = HIL_SS_M->Timing.clockTick0 *
    HIL_SS_M->Timing.stepSize0 + HIL_SS_M->Timing.clockTickH0 *
    HIL_SS_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(HIL_SS_M) &&
      HIL_SS_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    if (!(++HIL_SS_M->Timing.clockTick1))
      ++HIL_SS_M->Timing.clockTickH1;
    HIL_SS_M->Timing.t[1] = HIL_SS_M->Timing.clockTick1 *
      HIL_SS_M->Timing.stepSize1 + HIL_SS_M->Timing.clockTickH1 *
      HIL_SS_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void HIL_SS_derivatives(void)
{
  /* TransferFcn Block: '<Root>/HPF: derivative  followed by a LPF' */
  {
    ((StateDerivatives_HIL_SS *) HIL_SS_M->ModelData.derivs)
      ->HPFderivativefollowedbyaLPF_CST = HIL_SS_B.Gain;
    ((StateDerivatives_HIL_SS *) HIL_SS_M->ModelData.derivs)
      ->HPFderivativefollowedbyaLPF_CST +=
      (HIL_SS_P.HPFderivativefollowedbyaLPF_A)*
      HIL_SS_X.HPFderivativefollowedbyaLPF_CST;
  }

  /* TransferFcn Block: '<Root>/Transfer Fcn' */
  {
    ((StateDerivatives_HIL_SS *) HIL_SS_M->ModelData.derivs)->TransferFcn_CSTATE
      = HIL_SS_B.Sum4;
    ((StateDerivatives_HIL_SS *) HIL_SS_M->ModelData.derivs)->TransferFcn_CSTATE
      += (HIL_SS_P.TransferFcn_A)*HIL_SS_X.TransferFcn_CSTATE;
  }

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  ((StateDerivatives_HIL_SS *) HIL_SS_M->ModelData.derivs)->Integrator1_CSTATE =
    HIL_SS_B.Sum11;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  ((StateDerivatives_HIL_SS *) HIL_SS_M->ModelData.derivs)->Integrator_CSTATE[0]
    = HIL_SS_B.Sum8[0];
  ((StateDerivatives_HIL_SS *) HIL_SS_M->ModelData.derivs)->Integrator_CSTATE[1]
    = HIL_SS_B.Sum8[1];

  /* StateSpace Block: '<Root>/State-Space' */
  {
    ((StateDerivatives_HIL_SS *) HIL_SS_M->ModelData.derivs)->StateSpace_CSTATE
      [0] = HIL_SS_P.StateSpace_B*HIL_SS_B.Sum10;
    ((StateDerivatives_HIL_SS *) HIL_SS_M->ModelData.derivs)->StateSpace_CSTATE
      [0] += (HIL_SS_P.StateSpace_A[0])*HIL_SS_X.StateSpace_CSTATE[0] +
      (HIL_SS_P.StateSpace_A[1])*HIL_SS_X.StateSpace_CSTATE[1];
    ((StateDerivatives_HIL_SS *) HIL_SS_M->ModelData.derivs)->StateSpace_CSTATE
      [1] = (HIL_SS_P.StateSpace_A[2])*HIL_SS_X.StateSpace_CSTATE[0];
  }
}

/* Model initialize function */
void HIL_SS_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)HIL_SS_M,0,
                sizeof(RT_MODEL_HIL_SS));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&HIL_SS_M->solverInfo, &HIL_SS_M->Timing.simTimeStep);
    rtsiSetTPtr(&HIL_SS_M->solverInfo, &rtmGetTPtr(HIL_SS_M));
    rtsiSetStepSizePtr(&HIL_SS_M->solverInfo, &HIL_SS_M->Timing.stepSize0);
    rtsiSetdXPtr(&HIL_SS_M->solverInfo, &HIL_SS_M->ModelData.derivs);
    rtsiSetContStatesPtr(&HIL_SS_M->solverInfo, &HIL_SS_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&HIL_SS_M->solverInfo,
      &HIL_SS_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&HIL_SS_M->solverInfo, (&rtmGetErrorStatus(HIL_SS_M)));
    rtsiSetRTModelPtr(&HIL_SS_M->solverInfo, HIL_SS_M);
  }

  rtsiSetSimTimeStep(&HIL_SS_M->solverInfo, MAJOR_TIME_STEP);
  HIL_SS_M->ModelData.intgData.y = HIL_SS_M->ModelData.odeY;
  HIL_SS_M->ModelData.intgData.f[0] = HIL_SS_M->ModelData.odeF[0];
  HIL_SS_M->ModelData.intgData.f[1] = HIL_SS_M->ModelData.odeF[1];
  HIL_SS_M->ModelData.intgData.f[2] = HIL_SS_M->ModelData.odeF[2];
  HIL_SS_M->ModelData.intgData.f[3] = HIL_SS_M->ModelData.odeF[3];
  HIL_SS_M->ModelData.contStates = ((real_T *) &HIL_SS_X);
  rtsiSetSolverData(&HIL_SS_M->solverInfo, (void *)&HIL_SS_M->ModelData.intgData);
  rtsiSetSolverName(&HIL_SS_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = HIL_SS_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    HIL_SS_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    HIL_SS_M->Timing.sampleTimes = (&HIL_SS_M->Timing.sampleTimesArray[0]);
    HIL_SS_M->Timing.offsetTimes = (&HIL_SS_M->Timing.offsetTimesArray[0]);

    /* task periods */
    HIL_SS_M->Timing.sampleTimes[0] = (0.0);
    HIL_SS_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    HIL_SS_M->Timing.offsetTimes[0] = (0.0);
    HIL_SS_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(HIL_SS_M, &HIL_SS_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = HIL_SS_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    HIL_SS_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(HIL_SS_M, -1);
  HIL_SS_M->Timing.stepSize0 = 0.002;
  HIL_SS_M->Timing.stepSize1 = 0.002;

  /* external mode info */
  HIL_SS_M->Sizes.checksums[0] = (1887569662U);
  HIL_SS_M->Sizes.checksums[1] = (4289013142U);
  HIL_SS_M->Sizes.checksums[2] = (3441355293U);
  HIL_SS_M->Sizes.checksums[3] = (3648118194U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    HIL_SS_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &HIL_SS_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, HIL_SS_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(HIL_SS_M));
  }

  HIL_SS_M->solverInfoPtr = (&HIL_SS_M->solverInfo);
  HIL_SS_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&HIL_SS_M->solverInfo, 0.002);
  rtsiSetSolverMode(&HIL_SS_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  HIL_SS_M->ModelData.blockIO = ((void *) &HIL_SS_B);

  {
    HIL_SS_B.Gain = 0.0;
    HIL_SS_B.HPFderivativefollowedbyaLPF = 0.0;
    HIL_SS_B.Saturation = 0.0;
    HIL_SS_B.Sum10 = 0.0;
    HIL_SS_B.SignalGenerator = 0.0;
    HIL_SS_B.SwitchControl = 0.0;
    HIL_SS_B.Sum4 = 0.0;
    HIL_SS_B.Sum11 = 0.0;
    HIL_SS_B.Sum8[0] = 0.0;
    HIL_SS_B.Sum8[1] = 0.0;
  }

  /* parameters */
  HIL_SS_M->ModelData.defaultParam = ((real_T *) &HIL_SS_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &HIL_SS_X;
    HIL_SS_M->ModelData.contStates = (x);
    (void) memset((void *)x,0,
                  sizeof(ContinuousStates_HIL_SS));
  }

  /* states (dwork) */
  HIL_SS_M->Work.dwork = ((void *) &HIL_SS_DWork);
  (void) memset((void *)&HIL_SS_DWork, 0,
                sizeof(D_Work_HIL_SS));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      HIL_SS_DWork.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      HIL_SS_DWork.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      HIL_SS_DWork.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      HIL_SS_DWork.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      HIL_SS_DWork.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      HIL_SS_DWork.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      HIL_SS_DWork.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      HIL_SS_DWork.HILInitialize_POValues[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    HIL_SS_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void HIL_SS_terminate(void)
{
  /* S-Function Block: HIL_SS/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(HIL_SS_DWork.HILInitialize_Card);
    hil_task_delete_all(HIL_SS_DWork.HILInitialize_Card);
    hil_monitor_stop_all(HIL_SS_DWork.HILInitialize_Card);
    hil_monitor_delete_all(HIL_SS_DWork.HILInitialize_Card);
    is_switching = false;
    if ((HIL_SS_P.HILInitialize_AOTerminate && !is_switching) ||
        (HIL_SS_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &HIL_SS_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = HIL_SS_P.HILInitialize_AOFinal;
        }
      }

      result = hil_write_analog(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_AOChannels[0], 8U,
        &HIL_SS_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
      }
    }

    if ((HIL_SS_P.HILInitialize_DOTerminate && !is_switching) ||
        (HIL_SS_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &HIL_SS_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = HIL_SS_P.HILInitialize_DOFinal;
        }
      }

      result = hil_write_digital(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &HIL_SS_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
      }
    }

    if ((HIL_SS_P.HILInitialize_POTerminate && !is_switching) ||
        (HIL_SS_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &HIL_SS_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = HIL_SS_P.HILInitialize_POFinal;
        }
      }

      result = hil_write_pwm(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_POChannels[0], 8U,
        &HIL_SS_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
      }
    }

    hil_close(HIL_SS_DWork.HILInitialize_Card);
    HIL_SS_DWork.HILInitialize_Card = NULL;
  }

  /* ToFile Block: '<Root>/To File' */
  {
    FILE *fp = (FILE *) HIL_SS_DWork.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      const char *fileName = "HILSSPACE.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(HIL_SS_M, "Error closing MAT-file HILSSPACE.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(HIL_SS_M, "Error reopening MAT-file HILSSPACE.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 4, HIL_SS_DWork.ToFile_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(HIL_SS_M,
                          "Error writing header for ans to MAT-file HILSSPACE.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(HIL_SS_M, "Error closing MAT-file HILSSPACE.mat");
        return;
      }

      HIL_SS_DWork.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  HIL_SS_output(tid);
}

void MdlUpdate(int_T tid)
{
  HIL_SS_update(tid);
}

void MdlInitializeSizes(void)
{
  HIL_SS_M->Sizes.numContStates = (7); /* Number of continuous states */
  HIL_SS_M->Sizes.numY = (0);          /* Number of model outputs */
  HIL_SS_M->Sizes.numU = (0);          /* Number of model inputs */
  HIL_SS_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  HIL_SS_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  HIL_SS_M->Sizes.numBlocks = (39);    /* Number of blocks */
  HIL_SS_M->Sizes.numBlockIO = (9);    /* Number of block outputs */
  HIL_SS_M->Sizes.numBlockPrms = (142);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* TransferFcn Block: '<Root>/HPF: derivative  followed by a LPF' */
  HIL_SS_X.HPFderivativefollowedbyaLPF_CST = 0.0;

  /* TransferFcn Block: '<Root>/Transfer Fcn' */
  HIL_SS_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  HIL_SS_X.Integrator1_CSTATE = HIL_SS_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  HIL_SS_X.Integrator_CSTATE[0] = HIL_SS_P.Integrator_IC;
  HIL_SS_X.Integrator_CSTATE[1] = HIL_SS_P.Integrator_IC;

  /* StateSpace Block: '<Root>/State-Space' */
  HIL_SS_X.StateSpace_CSTATE[0] = HIL_SS_P.StateSpace_X0;
  HIL_SS_X.StateSpace_CSTATE[1] = HIL_SS_P.StateSpace_X0;
}

void MdlStart(void)
{
  /* S-Function Block: HIL_SS/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &HIL_SS_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(HIL_SS_DWork.HILInitialize_Card,
      "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(HIL_SS_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
      return;
    }

    if ((HIL_SS_P.HILInitialize_AIPStart && !is_switching) ||
        (HIL_SS_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &HIL_SS_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = HIL_SS_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &HIL_SS_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = HIL_SS_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_AIChannels[0], 8U,
        &HIL_SS_DWork.HILInitialize_AIMinimums[0],
        &HIL_SS_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }
    }

    if ((HIL_SS_P.HILInitialize_AOPStart && !is_switching) ||
        (HIL_SS_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &HIL_SS_DWork.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = HIL_SS_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &HIL_SS_DWork.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = HIL_SS_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_AOChannels[0], 8U,
        &HIL_SS_DWork.HILInitialize_AOMinimums[0],
        &HIL_SS_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }
    }

    if ((HIL_SS_P.HILInitialize_AOStart && !is_switching) ||
        (HIL_SS_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &HIL_SS_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = HIL_SS_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_AOChannels[0], 8U,
        &HIL_SS_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }
    }

    if (HIL_SS_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &HIL_SS_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = HIL_SS_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (HIL_SS_DWork.HILInitialize_Card, &HIL_SS_P.HILInitialize_AOChannels[0],
         8U, &HIL_SS_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(HIL_SS_DWork.HILInitialize_Card, NULL,
      0U, &HIL_SS_P.HILInitialize_DOChannels[0], 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
      return;
    }

    if ((HIL_SS_P.HILInitialize_DOStart && !is_switching) ||
        (HIL_SS_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &HIL_SS_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = HIL_SS_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &HIL_SS_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }
    }

    if (HIL_SS_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &HIL_SS_DWork.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = HIL_SS_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (HIL_SS_DWork.HILInitialize_Card, &HIL_SS_P.HILInitialize_DOChannels[0],
         8U, (const t_digital_state *) &HIL_SS_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }
    }

    if ((HIL_SS_P.HILInitialize_EIPStart && !is_switching) ||
        (HIL_SS_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &HIL_SS_DWork.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = HIL_SS_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_EIChannels[0], 8U, (t_encoder_quadrature_mode *)
        &HIL_SS_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }
    }

    if ((HIL_SS_P.HILInitialize_EIStart && !is_switching) ||
        (HIL_SS_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &HIL_SS_DWork.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = HIL_SS_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_EIChannels[0], 8U,
        &HIL_SS_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }
    }

    if ((HIL_SS_P.HILInitialize_POPStart && !is_switching) ||
        (HIL_SS_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &HIL_SS_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = HIL_SS_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_POChannels[0], 8U, (t_pwm_mode *)
        &HIL_SS_DWork.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          &HIL_SS_P.HILInitialize_POChannels[0];
        int32_T *dw_POModeValues = &HIL_SS_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            HIL_SS_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            HIL_SS_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              HIL_SS_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            HIL_SS_DWork.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            HIL_SS_DWork.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              HIL_SS_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(HIL_SS_DWork.HILInitialize_Card,
          &HIL_SS_DWork.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &HIL_SS_DWork.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(HIL_SS_DWork.HILInitialize_Card,
          &HIL_SS_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &HIL_SS_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &HIL_SS_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = HIL_SS_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &HIL_SS_DWork.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = HIL_SS_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &HIL_SS_DWork.HILInitialize_POPolarityVals
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = HIL_SS_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_POChannels[0], 8U,
        (t_pwm_configuration *) &HIL_SS_DWork.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &HIL_SS_DWork.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &HIL_SS_DWork.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &HIL_SS_DWork.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = HIL_SS_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &HIL_SS_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = HIL_SS_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_POChannels[0], 8U,
        &HIL_SS_DWork.HILInitialize_POSortedFreqs[0],
        &HIL_SS_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }
    }

    if ((HIL_SS_P.HILInitialize_POStart && !is_switching) ||
        (HIL_SS_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &HIL_SS_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = HIL_SS_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(HIL_SS_DWork.HILInitialize_Card,
        &HIL_SS_P.HILInitialize_POChannels[0], 8U,
        &HIL_SS_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }
    }

    if (HIL_SS_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &HIL_SS_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = HIL_SS_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (HIL_SS_DWork.HILInitialize_Card, &HIL_SS_P.HILInitialize_POChannels[0],
         8U, &HIL_SS_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(HIL_SS_M, _rt_error_message);
        return;
      }
    }
  }

  /* ToFile Block: '<Root>/To File' */
  {
    const char *fileName = "HILSSPACE.mat";
    FILE *fp;
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(HIL_SS_M, "Error creating .mat file HILSSPACE.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,4,0,"ans")) {
      rtmSetErrorStatus(HIL_SS_M,
                        "Error writing mat file header to file HILSSPACE.mat");
      return;
    }

    HIL_SS_DWork.ToFile_IWORK.Count = 0;
    HIL_SS_DWork.ToFile_IWORK.Decimation = -1;
    HIL_SS_DWork.ToFile_PWORK.FilePtr = fp;
  }

  MdlInitialize();
}

RT_MODEL_HIL_SS *HIL_SS(void)
{
  HIL_SS_initialize(1);
  return HIL_SS_M;
}

void MdlTerminate(void)
{
  HIL_SS_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
