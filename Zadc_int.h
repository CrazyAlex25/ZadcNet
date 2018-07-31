// �������������� ���� ���������
//#define KD1610		0	// ADC 16/200
//#define KD216		1	// APC 216
//#define KD500		2	// ADC 16/500
//#define KD500P		3	// ADC 16/500P
//#define KD816		4	// ADC 816
//#define KD1002		5	// ADC 1002
//#define KDU216		6	// APC 216 USB
//#define KD24		7	// ADC 24
//#define KD1432		8	// ADC 1432
//#define KDUACPB		9	// ACPB USB
//#define KDU1616		10	// ZET210
//#define KDUPD14		11	// PD14 USB
//#define KDUVN		12	// ZET110
//#define KDUOSC		13	// ZET302
//#define KDU8500		14	// A17U8
//#define KDU2500		15	// A17U2
//#define KDU1624		16	// ZET220
//#define KDU0424		17	// ZET230
//#define KDU0414		18	// ZET
//#define KDU0824		19	// ZET240


//��� ������� ���������� ��� ������. 0 - ��� ������, ����� - ��� ������

// ------------- ����� ������� -------------
// ������������ � ��������
__declspec(dllimport) long  ZOpen(long typeDevice, long numberDSP);
// ����������� �� ��������
__declspec(dllimport) long  ZClose(long typeDevice, long numberDSP);

// ����� � ������� ���������� ����������� (������ �� ��� DSP ������ ����������)
__declspec(dllimport) long  ZResetDSP(long typeDevice, long numberDSP);
// ������������������� ���������� ���������
__declspec(dllimport) long  ZInitDSP(long typeDevice, long numberDSP, const char *fileName);
// �������� �������� ����� DSP
__declspec(dllimport) long  ZGetSerialNumberDSP(long typeDevice, long numberDSP, long *serialNumber);
// �������� ��� ���������� (������������ ������ �� ����� 16 �������� ������ � ����������� 0, maxSizeStr - ������ ������ strName[])
__declspec(dllimport) long  ZGetNameDevice(long typeDevice, long numberDSP, char *strName, long maxSizeStr);
// �������� ������ �� (������������ ������ �� ����� 64 �������� ������ � ����������� 0)
__declspec(dllimport) long  ZGetVersion(long typeDevice, long numberDSP, char *verDSP, char *verDRV, char *verLIB);
// �������� ��� ���������� (1 - PCI, 2 - USB, 3 - Ethernet)
__declspec(dllimport) long  ZGetTypeConnection(long typeDevice, long numberDSP, long *type);
// ��������� ��� ������
__declspec(dllimport) long  ZGetError(long typeDevice, long numberDSP, long *error);
// ���������� ���-�� ��������� ���������� � ������� ��������
__declspec(dllimport) long  ZGetModify(long typeDevice, long numberDSP, long *modify);

// ��������� ���� - ���������� ���������� DSP (�������) � ������� ZStartADC()
__declspec(dllimport) long  ZGetFlag(long typeDevice, long numberDSP, unsigned long *flag);

// ��������� ������ ������������� �� ������� ������� (���������� �������, �� ��������������� ������� ��� ��� � ���)
__declspec(dllimport) long  ZGetEnableExtFreq(long typeDevice, long numberDSP, long *enable);
// ���./����. ������������� �� ������� ������� (���������� �������, �� ��������������� ������� ��� ��� � ���)
__declspec(dllimport) long  ZSetEnableExtFreq(long typeDevice, long numberDSP, long enable);
// ��������� ������ �������� ������� (���������� �������, �� ��������������� ������� ��� ��� � ���)
__declspec(dllimport) long  ZGetEnableExtStart(long typeDevice, long numberDSP, long *enable);
// ���./����. �������� ������� (���������� �������, �� ��������������� ������� ��� ��� � ���)
__declspec(dllimport) long  ZSetEnableExtStart(long typeDevice, long numberDSP, long enable);

// ��������� ���� ������ ��� ���� PnP
__declspec(dllimport) long  ZTestCode(long typeDevice, long numberDSP, long *code0, long *code1, long *code2);


// ��������� ���-�� ����� ��������� �����
__declspec(dllimport) long  ZGetQuantityChannelDigPort(long typeDevice, long numberDSP, long *quantityChannel);
// ��������� ����� ������� �����
__declspec(dllimport) long  ZGetDigOutEnable(long typeDevice, long numberDSP, unsigned long *digitalOutEnableMask);
// ���������� ����� ������� �����
__declspec(dllimport) long  ZSetDigOutEnable(long typeDevice, long numberDSP, unsigned long digitalOutEnableMask);
// ���������� ����� ��������� ����� �� ����� (��� ��������� ��������� ������ �����, numberOfBit = 0..quantityChannel-1)
__declspec(dllimport) long  ZSetBitDigOutEnable(long typeDevice, long numberDSP, long numberOfBit);
// ���������� ����� ����� ��������� ����� ����� (��� ��������� ��������� ������ �����)
__declspec(dllimport) long  ZSetBitMaskDigOutEnable(long typeDevice, long numberDSP, unsigned long maskOfBits);
// ���������� ����� ��������� ����� �� ���� (��� ��������� ��������� ������ �����, numberOfBit = 0..quantityChannel-1)
__declspec(dllimport) long  ZClrBitDigOutEnable(long typeDevice, long numberDSP, long numberOfBit);
// ���������� ����� ����� ��������� ����� ���� (��� ��������� ��������� ������ �����)
__declspec(dllimport) long  ZClrBitMaskDigOutEnable(long typeDevice, long numberDSP, unsigned long maskOfBits);
// ��������� ������ �� ������ �����
__declspec(dllimport) long  ZGetDigInput(long typeDevice, long numberDSP, unsigned long *digitalInput);
// ��������� ������, ���������� �� ������ �����
__declspec(dllimport) long  ZGetDigOutput(long typeDevice, long numberDSP, unsigned long *digitalOutput);
// �������� ������ � ����
__declspec(dllimport) long  ZSetDigOutput(long typeDevice, long numberDSP, unsigned long digitalOutput);
// ���������� ����� ��������� ����� � "1" (��� ��������� ��������� ������ �������, numberOfBit = 0..quantityChannel-1)
__declspec(dllimport) long  ZSetBitDigOutput(long typeDevice, long numberDSP, long numberOfBit);
// ���������� ����� ������� ��������� ����� � "1" (��� ��������� ��������� ������ �������)
__declspec(dllimport) long  ZSetBitMaskDigOutput(long typeDevice, long numberDSP, unsigned long maskOfBits);
// ���������� ����� ��������� ����� � "0" (��� ��������� ��������� ������ �������, numberOfBit = 0..quantityChannel-1)
__declspec(dllimport) long  ZClrBitDigOutput(long typeDevice, long numberDSP, long numberOfBit);
// ���������� ����� ������� ��������� ����� � "0" (��� ��������� ��������� ������ �������)
__declspec(dllimport) long  ZClrBitMaskDigOutput(long typeDevice, long numberDSP, unsigned long maskOfBits);
// �������� ����� ���������� �����-������ (mode=0 - ���������� ����, mode=1 - ��������� ����, mode=2 - UART)
										// +0x04 - ��������������� UART
										// +0x08 - 9 ��� UART
										// +0x10 - 2 ����-���� UART (�� ���.)
										// +0x20 - �������� �������� UART (�� ���.)
										// +0x40 - IrDA UART (�� ���.)
__declspec(dllimport) long  ZGetDigitalMode(long typeDevice, long numberDSP, long *mode);
// ����������� ����� ���������� �����-������ (mode=0 - ���������� ����, mode=1 - ��������� ����, mode=2 - UART)
__declspec(dllimport) long  ZSetDigitalMode(long typeDevice, long numberDSP, long mode);
// ����� ���������� ��������� �������� ������������� �� �������� ����  
__declspec(dllimport) long  ZGetMasterSynchr(long typeDevice, long numberDSP, long *enable);
// ��������� ��������� �������� ������������� �� �������� ����  
__declspec(dllimport) long  ZSetMasterSynchr(long typeDevice, long numberDSP, long enable);


// ��������� �������������� �� ������ ���
__declspec(dllimport) long  ZFindPWM(long typeDevice, long numberDSP, long* present);
// ������ ������� ���
__declspec(dllimport) long  ZStartPWM(long typeDevice, long numberDSP, long Start0, long Start1, long Start2);
// ������� ������� ���
__declspec(dllimport) long  ZStopPWM(long typeDevice, long numberDSP, long Stop0, long Stop1, long Stop2);
// ������ ������� ��� ����� ����. ������� ������� ������� � ������
__declspec(dllimport) long  ZSetFreqPWM(long typeDevice, long numberDSP, long Rate, long Period);
// ������ ���������� � ����� ������� ���
__declspec(dllimport) long  ZSetOnDutyPWM(long typeDevice, long numberDSP, long OnDutyPWM0, long OnDutyPWM1, long OnDutyPWM2, long ShiftPWM1, long ShiftPWM2);
// ����� �������� ������������� ���������� � DSP
__declspec(dllimport)long  ZRegulatorPWM(long typeDevice, long numberDSP, void *data, long *size);


// ------------- ������ ������� ��� ������ � ��� ��� ��� -------------
// ��������� ��� � ������� ������ DSP
__declspec(dllimport) long  ZGetEnableADC(long typeDevice, long numberDSP, long *enable);
// ��������� ��� � ������� ������ DSP
__declspec(dllimport) long  ZGetEnableDAC(long typeDevice, long numberDSP, long *enable);
// ���������� ���������� ��������� � ����� ���/���
__declspec(dllimport) long  ZSetTypeADC(long typeDevice, long numberDSP);
__declspec(dllimport) long  ZSetTypeDAC(long typeDevice, long numberDSP);
// ������ � ����� ��������� ��������� ���/���
__declspec(dllimport) long  ZGetStartADC(long typeDevice, long numberDSP, long *status);
__declspec(dllimport) long  ZGetStartDAC(long typeDevice, long numberDSP, long *status);
// ������ ��������� �����/������ �������
__declspec(dllimport) long  ZStartADC(long typeDevice, long numberDSP);
__declspec(dllimport) long  ZStartDAC(long typeDevice, long numberDSP);
// ������� ��������� �����/������
__declspec(dllimport) long  ZStopADC(long typeDevice, long numberDSP);
__declspec(dllimport) long  ZStopDAC(long typeDevice, long numberDSP);

// ��������� ���-�� ������� ���/���
__declspec(dllimport) long  ZGetQuantityChannelADC(long typeDevice, long numberDSP, long *quantityChannel);
__declspec(dllimport) long  ZGetQuantityChannelDAC(long typeDevice, long numberDSP, long *quantityChannel);
// ��������� ��� �������� ������� ���/��� (���������� �������)
__declspec(dllimport) long  ZGetDigitalResolutionADC(long typeDevice, long numberDSP, double *digitalResolution);
__declspec(dllimport) long  ZGetDigitalResolutionDAC(long typeDevice, long numberDSP, double *digitalResolution);
// ��������� ��������������� ���������� ��� �������� ������� ���/���
__declspec(dllimport) long  ZGetDigitalResolChanADC(long typeDevice, long numberDSP, long numberChannel, double *digitalResolChan);
__declspec(dllimport) long  ZGetDigitalResolChanDAC(long typeDevice, long numberDSP, long numberChannel, double *digitalResolChan);
// ��������� ���-�� ��� � ����� ������� ���/���
__declspec(dllimport) long  ZGetBitsADC(long typeDevice, long numberDSP, long *numberBits);
__declspec(dllimport) long  ZGetBitsDAC(long typeDevice, long numberDSP, long *numberBits);
// ��������� ���-�� ���� � ����� ������� ���/���
__declspec(dllimport) long  ZGetWordsADC(long typeDevice, long numberDSP, long *numberWords);
__declspec(dllimport) long  ZGetWordsDAC(long typeDevice, long numberDSP, long *numberWords);

// ��������� ������� ������������� 
__declspec(dllimport) long  ZGetFreqADC(long typeDevice, long numberDSP, double *freq);
__declspec(dllimport) long  ZGetFreqDAC(long typeDevice, long numberDSP, double *freq);
// ��������� ������� �� ������ ��������� ������ ������������� 
__declspec(dllimport) long  ZGetListFreqADC(long typeDevice, long numberDSP, long next, double *freq);
__declspec(dllimport) long  ZGetListFreqDAC(long typeDevice, long numberDSP, long next, double *freq);
// ���������� ��������� �� ������ ������� ������������� 
__declspec(dllimport) long  ZSetNextFreqADC(long typeDevice, long numberDSP, long next, double *freq);
__declspec(dllimport) long  ZSetNextFreqDAC(long typeDevice, long numberDSP, long next, double *freq);
// ���������� ������� �������������
__declspec(dllimport) long  ZSetFreqADC(long typeDevice, long numberDSP, double freqIn, double *freqOut);
__declspec(dllimport) long  ZSetFreqDAC(long typeDevice, long numberDSP, double freqIn, double *freqOut);

// ��������� �������� ������� ������� �������
__declspec(dllimport) long  ZGetExtFreqADC(long typeDevice, long numberDSP, double *oporFreq);
__declspec(dllimport) long  ZGetExtFreqDAC(long typeDevice, long numberDSP, double *oporFreq);
// ���������� �������� ������� ������� �������
__declspec(dllimport) long  ZSetExtFreqADC(long typeDevice, long numberDSP, double extFreq);
__declspec(dllimport) long  ZSetExtFreqDAC(long typeDevice, long numberDSP, double extFreq);
// ��������� ������ ������������� �� ������� ������� 
__declspec(dllimport) long  ZGetEnableExtFreqADC(long typeDevice, long numberDSP, long *enable);
__declspec(dllimport) long  ZGetEnableExtFreqDAC(long typeDevice, long numberDSP, long *enable);
// ���./����. ������������� �� ������� �������
__declspec(dllimport) long  ZSetEnableExtFreqADC(long typeDevice, long numberDSP, long enable);
__declspec(dllimport) long  ZSetEnableExtFreqDAC(long typeDevice, long numberDSP, long enable);
// ��������� ������ �������� �������
__declspec(dllimport) long  ZGetEnableExtStartADC(long typeDevice, long numberDSP, long *enable);
__declspec(dllimport) long  ZGetEnableExtStartDAC(long typeDevice, long numberDSP, long *enable);
// ���./����. �������� �������
__declspec(dllimport) long  ZSetEnableExtStartADC(long typeDevice, long numberDSP, long enable);
__declspec(dllimport) long  ZSetEnableExtStartDAC(long typeDevice, long numberDSP, long enable);

// ���������� ������������� ������ ������ ��� ����������
__declspec(dllimport) long  ZGetInterruptADC(long typeDevice, long numberDSP, long *size);
__declspec(dllimport) long  ZGetInterruptDAC(long typeDevice, long numberDSP, long *size);
// ���������� ����. ��������� ������ ������ ��� ����������
__declspec(dllimport) long  ZGetMaxInterruptADC(long typeDevice, long numberDSP, long *size);
__declspec(dllimport) long  ZGetMaxInterruptDAC(long typeDevice, long numberDSP, long *size);
// ���������� ������ ������ ��� ��������� ��� ����������
__declspec(dllimport) long  ZSetInterruptADC(long typeDevice, long numberDSP, long size);
__declspec(dllimport) long  ZSetInterruptDAC(long typeDevice, long numberDSP, long size);

// ���������� ������������� ������ ������ ������ DSP
__declspec(dllimport) long  ZGetSizePacketADC(long typeDevice, long numberDSP, long *size);
__declspec(dllimport) long  ZGetSizePacketDAC(long typeDevice, long numberDSP, long *size);
// ���������� ����. ��������� ������ ������ ������ DSP
__declspec(dllimport) long  ZGetMaxSizePacketADC(long typeDevice, long numberDSP, long *size);
__declspec(dllimport) long  ZGetMaxSizePacketDAC(long typeDevice, long numberDSP, long *size);
// ���������� ������ ������ ������ DSP
__declspec(dllimport) long  ZSetSizePacketADC(long typeDevice, long numberDSP, long size);
__declspec(dllimport) long  ZSetSizePacketDAC(long typeDevice, long numberDSP, long size);

// ���������� ������������� ���-�� ������� �� ���� ����������
__declspec(dllimport) long  ZGetQuantityPacketsADC(long typeDevice, long numberDSP, long *size);
__declspec(dllimport) long  ZGetQuantityPacketsDAC(long typeDevice, long numberDSP, long *size);
// ���������� ����. ��������� ���-�� ������� �� ���� ����������
__declspec(dllimport) long  ZGetMaxQuantityPacketsADC(long typeDevice, long numberDSP, long *size);
__declspec(dllimport) long  ZGetMaxQuantityPacketsDAC(long typeDevice, long numberDSP, long *size);
// ���������� ���-�� ������� �� ���� ����������
__declspec(dllimport) long  ZSetQuantityPacketsADC(long typeDevice, long numberDSP, long size);
__declspec(dllimport) long  ZSetQuantityPacketsDAC(long typeDevice, long numberDSP, long size);

// ���������� ����������� ��� ����������� ���������� � ����� ��� �� 
__declspec(dllimport) long  ZSetCycleSampleADC(long typeDevice, long numberDSP, long enable);
__declspec(dllimport) long  ZSetCycleSampleDAC(long typeDevice, long numberDSP, long enable);

// ������ ������ ������ ��� � ��� ��
__declspec(dllimport) long  ZSetBufferSizeADC(long typeDevice, long numberDSP, long size);
__declspec(dllimport) long  ZSetBufferSizeDAC(long typeDevice, long numberDSP, long size);
// ��������� ����� � ��� ��
__declspec(dllimport) long  ZGetBufferADC(long typeDevice, long numberDSP, void **buffer, long *size);
__declspec(dllimport) long  ZGetBufferDAC(long typeDevice, long numberDSP, void **buffer, long *size);
// ���������� ����� � ��� ��
__declspec(dllimport) long  ZRemBufferADC(long typeDevice, long numberDSP, void **buffer);
__declspec(dllimport) long  ZRemBufferDAC(long typeDevice, long numberDSP, void **buffer);
// ������ ��������� ������ � ��� ��
__declspec(dllimport) long  ZGetPointerADC(long typeDevice, long numberDSP, long *pointer);
__declspec(dllimport) long  ZGetPointerDAC(long typeDevice, long numberDSP, long *pointer);

// ����� ���������� ���������� �������
__declspec(dllimport) long  ZGetNumberInputADC(long typeDevice, long numberDSP, long *workChannels);
__declspec(dllimport) long  ZGetNumberOutputDAC(long typeDevice, long numberDSP, long *workChannels);
// ����� ������� �� �������� �����
__declspec(dllimport) long  ZGetInputADC(long typeDevice, long numberDSP, long numberChannel, long *enable);
__declspec(dllimport) long  ZGetOutputDAC(long typeDevice, long numberDSP, long numberChannel, long *enable);
// ��������/��������� �������� �����
__declspec(dllimport) long  ZSetInputADC(long typeDevice, long numberDSP, long numberChannel, long enable);
__declspec(dllimport) long  ZSetOutputDAC(long typeDevice, long numberDSP, long numberChannel, long enable);


// ------------- ������� ��� ������ ������ � ��� -------------
// �������� ���������� ������ ���
__declspec(dllimport) long  ZGetLastDataADC(long typeDevice, long numberDSP, long numberChannel, void *buffer, long size);

// ��������� ����. ��������
__declspec(dllimport) long  ZGetAmplifyADC(long typeDevice, long numberDSP, long numberChannel, double *amplify);
// ��������� ����. �������� �� ������ ��������� ����. ��������
__declspec(dllimport) long  ZGetListAmplifyADC(long typeDevice, long numberDSP, long next, double *amplify);
// ���������� ��������� ����. ��������
__declspec(dllimport) long  ZSetNextAmplifyADC(long typeDevice, long numberDSP, long numberChannel, long next, double *amplify);
// ���������� ����. ��������
__declspec(dllimport) long  ZSetAmplifyADC(long typeDevice, long numberDSP, long numberChannel, double amplifyIn, double *amplifyOut);

// ��������� ����. �������� ��8/10
__declspec(dllimport) long  ZGetPreAmplifyADC(long typeDevice, long numberDSP, long numberChannel, double *amplify);
// ��������� ����. �������� �� ������ ��������� ����. �������� ��8/10
__declspec(dllimport) long  ZGetListPreAmplifyADC(long typeDevice, long numberDSP, long next, double *amplify);
// ���������� ��������� ����. �������� ��8/10
__declspec(dllimport) long  ZSetNextPreAmplifyADC(long typeDevice, long numberDSP, long numberChannel, long next, double *amplify);
// ���������� ����. �������� ��8/10
__declspec(dllimport) long  ZSetPreAmplifyADC(long typeDevice, long numberDSP, long numberChannel, double amplifyIn, double *amplifyOut);

// ��������� �������������� � ��������� �� ������ HCP
__declspec(dllimport) long  ZFindHCPADC(long typeDevice, long numberDSP, long *present);
// ��������� � ��������� ��������� ������ ������ HCP
__declspec(dllimport) long  ZGetHCPADC(long typeDevice, long numberDSP, long numberChannel, long *enable);
// ���������� ��������� ��������� ������ ������ HCP
__declspec(dllimport) long  ZSetHCPADC(long typeDevice, long numberDSP, long numberChannel, long enable);

// ����� ����������������� ������ ��������� ������ ��� ����� 
__declspec(dllimport) long  ZGetInputDiffADC(long typeDevice, long numberDSP, long numberChannel, long *enable);
// ����������-�������� �������� ����� ��� ����� � ���������������� �����
__declspec(dllimport) long  ZSetInputDiffADC(long typeDevice, long numberDSP, long numberChannel, long enable);


// ------------- ������� ��� ������ ������ � ��� -------------
// ���������� ������� (�� ������ ��) ��� ���������� (������ �� ������ DSP) �������� � ���
__declspec(dllimport) long  ZSetExtCycleDAC(long typeDevice, long numberDSP, long enable);

// �������� �������������� �� ����������� ����������
__declspec(dllimport) long  ZFindSoftAtten(long typeDevice, long numberDSP, long *present);
// ��������� ���. ��������� �����������
__declspec(dllimport) long  ZGetAttenDAC(long typeDevice, long numberDSP, long numberChannel, double *reduction);
// ���������� ���. ��������� �����������
__declspec(dllimport) long  ZSetAttenDAC(long typeDevice, long numberDSP, long numberChannel, double reductionIn, double *reductionOut);

// ����� ������������� ������� ������ ��� � DSP
__declspec(dllimport) long  ZGetMaxSizeBufferDSPDAC(long typeDevice, long numberDSP, long *size);
// ����� ������� ������ ��� � DSP
__declspec(dllimport) long  ZGetSizeBufferDSPDAC(long typeDevice, long numberDSP, long *size);
// ���������� ������ ������ ��� � DSP
__declspec(dllimport) long  ZSetSizeBufferDSPDAC(long typeDevice, long numberDSP, long size);




