  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (HIL_SS_P)
    ;%
      section.nData     = 44;
      section.data(44)  = dumData; %prealloc
      
	  ;% HIL_SS_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% HIL_SS_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% HIL_SS_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% HIL_SS_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% HIL_SS_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% HIL_SS_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% HIL_SS_P.HILInitialize_AOHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% HIL_SS_P.HILInitialize_AOLow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% HIL_SS_P.HILInitialize_AOInitial
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% HIL_SS_P.HILInitialize_AOFinal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% HIL_SS_P.HILInitialize_AOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% HIL_SS_P.HILInitialize_POFrequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% HIL_SS_P.HILInitialize_POLeading
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% HIL_SS_P.HILInitialize_POTrailing
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% HIL_SS_P.HILInitialize_POInitial
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% HIL_SS_P.HILInitialize_POFinal
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% HIL_SS_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% HIL_SS_P.rotarycountstorads_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% HIL_SS_P.Gain_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% HIL_SS_P.HPFderivativefollowedbyaLPF_A
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% HIL_SS_P.HPFderivativefollowedbyaLPF_C
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% HIL_SS_P.HPFderivativefollowedbyaLPF_D
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% HIL_SS_P.TransferFcn_A
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 22;
	
	  ;% HIL_SS_P.TransferFcn_C
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 23;
	
	  ;% HIL_SS_P.Saturation_UpperSat
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 24;
	
	  ;% HIL_SS_P.Saturation_LowerSat
	  section.data(26).logicalSrcIdx = 28;
	  section.data(26).dtTransOffset = 25;
	
	  ;% HIL_SS_P.Integrator1_IC
	  section.data(27).logicalSrcIdx = 29;
	  section.data(27).dtTransOffset = 26;
	
	  ;% HIL_SS_P.Ki_Gain
	  section.data(28).logicalSrcIdx = 30;
	  section.data(28).dtTransOffset = 27;
	
	  ;% HIL_SS_P.Integrator_IC
	  section.data(29).logicalSrcIdx = 31;
	  section.data(29).dtTransOffset = 28;
	
	  ;% HIL_SS_P.K_Gain
	  section.data(30).logicalSrcIdx = 32;
	  section.data(30).dtTransOffset = 29;
	
	  ;% HIL_SS_P.SignalGenerator_Amplitude
	  section.data(31).logicalSrcIdx = 33;
	  section.data(31).dtTransOffset = 31;
	
	  ;% HIL_SS_P.SignalGenerator_Frequency
	  section.data(32).logicalSrcIdx = 34;
	  section.data(32).dtTransOffset = 32;
	
	  ;% HIL_SS_P.StateSpace_A
	  section.data(33).logicalSrcIdx = 35;
	  section.data(33).dtTransOffset = 33;
	
	  ;% HIL_SS_P.StateSpace_B
	  section.data(34).logicalSrcIdx = 36;
	  section.data(34).dtTransOffset = 36;
	
	  ;% HIL_SS_P.StateSpace_C
	  section.data(35).logicalSrcIdx = 37;
	  section.data(35).dtTransOffset = 37;
	
	  ;% HIL_SS_P.StateSpace_X0
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 38;
	
	  ;% HIL_SS_P.A_Gain
	  section.data(37).logicalSrcIdx = 40;
	  section.data(37).dtTransOffset = 39;
	
	  ;% HIL_SS_P.B_Gain
	  section.data(38).logicalSrcIdx = 41;
	  section.data(38).dtTransOffset = 43;
	
	  ;% HIL_SS_P.C_Gain
	  section.data(39).logicalSrcIdx = 42;
	  section.data(39).dtTransOffset = 45;
	
	  ;% HIL_SS_P.L_Gain
	  section.data(40).logicalSrcIdx = 43;
	  section.data(40).dtTransOffset = 47;
	
	  ;% HIL_SS_P.Constant_Value
	  section.data(41).logicalSrcIdx = 44;
	  section.data(41).dtTransOffset = 49;
	
	  ;% HIL_SS_P.Constant1_Value
	  section.data(42).logicalSrcIdx = 45;
	  section.data(42).dtTransOffset = 50;
	
	  ;% HIL_SS_P.delta2_Gain
	  section.data(43).logicalSrcIdx = 46;
	  section.data(43).dtTransOffset = 51;
	
	  ;% HIL_SS_P.delta2_Gain_d
	  section.data(44).logicalSrcIdx = 47;
	  section.data(44).dtTransOffset = 52;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% HIL_SS_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% HIL_SS_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 3;
	
	  ;% HIL_SS_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 4;
	
	  ;% HIL_SS_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 5;
	
	  ;% HIL_SS_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 6;
	
	  ;% HIL_SS_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 53;
	  section.data(6).dtTransOffset = 7;
	
	  ;% HIL_SS_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 54;
	  section.data(7).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% HIL_SS_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% HIL_SS_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 8;
	
	  ;% HIL_SS_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 16;
	
	  ;% HIL_SS_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 58;
	  section.data(4).dtTransOffset = 24;
	
	  ;% HIL_SS_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 59;
	  section.data(5).dtTransOffset = 32;
	
	  ;% HIL_SS_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 60;
	  section.data(6).dtTransOffset = 33;
	
	  ;% HIL_SS_P.HILReadEncoder_Channels
	  section.data(7).logicalSrcIdx = 61;
	  section.data(7).dtTransOffset = 41;
	
	  ;% HIL_SS_P.HILWriteAnalog1_Channels
	  section.data(8).logicalSrcIdx = 62;
	  section.data(8).dtTransOffset = 42;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% HIL_SS_P.Constant_Value_g
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
	  ;% HIL_SS_P.SwitchControl_Threshold
	  section.data(2).logicalSrcIdx = 64;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% HIL_SS_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% HIL_SS_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 1;
	
	  ;% HIL_SS_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 67;
	  section.data(3).dtTransOffset = 2;
	
	  ;% HIL_SS_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 68;
	  section.data(4).dtTransOffset = 3;
	
	  ;% HIL_SS_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 69;
	  section.data(5).dtTransOffset = 4;
	
	  ;% HIL_SS_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 70;
	  section.data(6).dtTransOffset = 5;
	
	  ;% HIL_SS_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 71;
	  section.data(7).dtTransOffset = 6;
	
	  ;% HIL_SS_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 72;
	  section.data(8).dtTransOffset = 7;
	
	  ;% HIL_SS_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 73;
	  section.data(9).dtTransOffset = 8;
	
	  ;% HIL_SS_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 74;
	  section.data(10).dtTransOffset = 9;
	
	  ;% HIL_SS_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 75;
	  section.data(11).dtTransOffset = 10;
	
	  ;% HIL_SS_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 76;
	  section.data(12).dtTransOffset = 11;
	
	  ;% HIL_SS_P.HILInitialize_DOPStart
	  section.data(13).logicalSrcIdx = 77;
	  section.data(13).dtTransOffset = 12;
	
	  ;% HIL_SS_P.HILInitialize_DOPEnter
	  section.data(14).logicalSrcIdx = 78;
	  section.data(14).dtTransOffset = 13;
	
	  ;% HIL_SS_P.HILInitialize_DOStart
	  section.data(15).logicalSrcIdx = 79;
	  section.data(15).dtTransOffset = 14;
	
	  ;% HIL_SS_P.HILInitialize_DOEnter
	  section.data(16).logicalSrcIdx = 80;
	  section.data(16).dtTransOffset = 15;
	
	  ;% HIL_SS_P.HILInitialize_DOTerminate
	  section.data(17).logicalSrcIdx = 81;
	  section.data(17).dtTransOffset = 16;
	
	  ;% HIL_SS_P.HILInitialize_DOExit
	  section.data(18).logicalSrcIdx = 82;
	  section.data(18).dtTransOffset = 17;
	
	  ;% HIL_SS_P.HILInitialize_DOReset
	  section.data(19).logicalSrcIdx = 83;
	  section.data(19).dtTransOffset = 18;
	
	  ;% HIL_SS_P.HILInitialize_EIPStart
	  section.data(20).logicalSrcIdx = 84;
	  section.data(20).dtTransOffset = 19;
	
	  ;% HIL_SS_P.HILInitialize_EIPEnter
	  section.data(21).logicalSrcIdx = 85;
	  section.data(21).dtTransOffset = 20;
	
	  ;% HIL_SS_P.HILInitialize_EIStart
	  section.data(22).logicalSrcIdx = 86;
	  section.data(22).dtTransOffset = 21;
	
	  ;% HIL_SS_P.HILInitialize_EIEnter
	  section.data(23).logicalSrcIdx = 87;
	  section.data(23).dtTransOffset = 22;
	
	  ;% HIL_SS_P.HILInitialize_POPStart
	  section.data(24).logicalSrcIdx = 88;
	  section.data(24).dtTransOffset = 23;
	
	  ;% HIL_SS_P.HILInitialize_POPEnter
	  section.data(25).logicalSrcIdx = 89;
	  section.data(25).dtTransOffset = 24;
	
	  ;% HIL_SS_P.HILInitialize_POStart
	  section.data(26).logicalSrcIdx = 90;
	  section.data(26).dtTransOffset = 25;
	
	  ;% HIL_SS_P.HILInitialize_POEnter
	  section.data(27).logicalSrcIdx = 91;
	  section.data(27).dtTransOffset = 26;
	
	  ;% HIL_SS_P.HILInitialize_POTerminate
	  section.data(28).logicalSrcIdx = 92;
	  section.data(28).dtTransOffset = 27;
	
	  ;% HIL_SS_P.HILInitialize_POExit
	  section.data(29).logicalSrcIdx = 93;
	  section.data(29).dtTransOffset = 28;
	
	  ;% HIL_SS_P.HILInitialize_POReset
	  section.data(30).logicalSrcIdx = 94;
	  section.data(30).dtTransOffset = 29;
	
	  ;% HIL_SS_P.HILInitialize_OOReset
	  section.data(31).logicalSrcIdx = 95;
	  section.data(31).dtTransOffset = 30;
	
	  ;% HIL_SS_P.HILInitialize_DOInitial
	  section.data(32).logicalSrcIdx = 96;
	  section.data(32).dtTransOffset = 31;
	
	  ;% HIL_SS_P.HILInitialize_DOFinal
	  section.data(33).logicalSrcIdx = 97;
	  section.data(33).dtTransOffset = 32;
	
	  ;% HIL_SS_P.HILReadEncoder_Active
	  section.data(34).logicalSrcIdx = 98;
	  section.data(34).dtTransOffset = 33;
	
	  ;% HIL_SS_P.HILWriteAnalog1_Active
	  section.data(35).logicalSrcIdx = 99;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (HIL_SS_B)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% HIL_SS_B.Gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% HIL_SS_B.HPFderivativefollowedbyaLPF
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% HIL_SS_B.Saturation
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% HIL_SS_B.Sum10
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% HIL_SS_B.SignalGenerator
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% HIL_SS_B.SwitchControl
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% HIL_SS_B.Sum4
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% HIL_SS_B.Sum11
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% HIL_SS_B.Sum8
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (HIL_SS_DWork)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% HIL_SS_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% HIL_SS_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% HIL_SS_DWork.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% HIL_SS_DWork.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% HIL_SS_DWork.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% HIL_SS_DWork.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% HIL_SS_DWork.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% HIL_SS_DWork.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% HIL_SS_DWork.HILReadEncoder_PWORK
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% HIL_SS_DWork.Angularvelocitydegs_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% HIL_SS_DWork.HILWriteAnalog1_PWORK
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% HIL_SS_DWork.Scope1_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% HIL_SS_DWork.Scope4_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% HIL_SS_DWork.ToFile_PWORK.FilePtr
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% HIL_SS_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% HIL_SS_DWork.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 3;
	
	  ;% HIL_SS_DWork.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 11;
	
	  ;% HIL_SS_DWork.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 19;
	
	  ;% HIL_SS_DWork.HILInitialize_POModeValues
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 27;
	
	  ;% HIL_SS_DWork.HILInitialize_POAlignValues
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 35;
	
	  ;% HIL_SS_DWork.HILInitialize_POPolarityVals
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 43;
	
	  ;% HIL_SS_DWork.HILReadEncoder_Buffer
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% HIL_SS_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% HIL_SS_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% HIL_SS_DWork.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% HIL_SS_DWork.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1887569662;
  targMap.checksum1 = 4289013142;
  targMap.checksum2 = 3441355293;
  targMap.checksum3 = 3648118194;

