//adcinfo.h
struct ADC_INFO {
short numberDSP;// - ���������� ����� DSP �� �����.
short typeADC;// - ����� ������ DSP: 0 - ADC, 1 - DAC.
short EnableADC;// - ������� ���.
short EnableDAC;// - ������� ���.
short EnableExtDevice;// - ������� ���������� ���������: 0 - ������ ���,0x01 - PRUS, 0x02 - HCP (ICP), 0x04 - Atten, 0x08 - SD-card, 0x10 -Ethernet, 0x20 - Bluetooth, 0x40 - PWM (���), 0x80 - DigAnaliz(���������� ����������), 0x100 - 1-Wire (TEDs), 0x200 - ���������� �� GPS, 0x400 - ������������� �� PTP.
short Start;// - ��������� ����� ������ 1- ����.
long Channel;// - ������� ���������� �������� �������.
long HCPChannel;// - ������� ���������� ���������� ������� HCP.
long OverloadChannel;// - ������� ���������� ������������� �������.
short WorkChADC;// - ���������� ���������� ������� ���.
short WorkChDAC;// - ���������� ���������� ������� ���.
short KodAmplify[32];// - ���� �������� �� ���.
short TypeConnection;// - ��� ���������� (1 - PCI, 2 - USB, 3 - Ethernet, 4 -Bluetouch).
double Amplitude[32];// - ����������� �������� ��������� ���.
short PRUS[32];// - ���� �������� ��������� ������ / ���. (����.) HCP.
double PreAmplitude[32];// - ����������� �������� �������������.
short Atten[4];// - ���� ����������� ���.
double Reduction[4];// - ����������� �������� ����������� ���.

short EnaExtStart;// - ���������� �������� ������ ��� 0 - ����������, 1- �������.
short EnaExtFreq ;//- ���������� ������� ������� ��� 0 - ����������,1 - �������.
short EnaCycle;// - ���������� ������������ ���������� 0-����������, 1-����������.
short ExtCycle;// - MasterSynchr: 1 - �������� �������������, 0 - ����������������� � �������������.
short ModaADC ;//- ���� ������ ��� 0-1, 1-2, 2-4, 3-5, 4-8, 5-10 ������������.
short EnaExtStartDAC;// - ���������� �������� ������ ��� 0 -����������, 1- �������.
short EnaExtFreqDAC;// - ���������� ������� ������� ��� 0 -����������, 1- �������.
short Reserv1 ;//- ������ 1 ������������ � ��������� CableTest.exe
short Reserv2;// - ������ 1 ������������ � ��������� CableTest.exe
double Freq ;//- ������� ������� �������������� (Freq = OporFreq/Rate).
double OporFreq;// - ������� ������� �������.
long Rate;// - ����������� ������� ������� �������.
long sizeInterrupt;// - ������ ��� ��������� ������ ��� ������ ���������� ��� (sizeInterrupt = QuantityPacketsADC * SizePacketADC).
short *AddressBufer;// - ����� ������ � ��������� �������.
short *AddressBuferDAC;// - ����� ������ � ��������� ������� ���.
short *AddressUserBufer ;//- ������ ������ � ���������������� �������.
short *AddressUserBuferDAC;// - ������ ������ � ����������������������� ���.
long SizeBufer;// - ������ ������ ����� �� ����� 1 000 000 ��������.
long SizeBuferDAC;// - ������ ������ ���������� �� ����� 1 000 000 ��������.
long Pointer;//- ������ �������� ���������� � ������ ���.
long PointerDAC;// - ������ �������� ���������� � ������ ���.
long PointerDSP;// - ������ ���������� ���������� � DSP.
short Bits;// - ���������� ��� � ��� ���������������.
short BitsDAC;// - ���������� ��� � ���.
short Words;// - ���������� 16-��������� ���� � ����� �������.
short WordsDAC;// - ���������� 16-��������� ���� � ����� ������� ���.
short QuantityChannelDigPort;// - ���������� ����� ��������� �����.
double DigitalResolution ;//- ��� �������� ������� ���.
double DigitalResolutionDAC;// - ��� �������� ������� ���.
double MaxFreq ;//- ������������ ������� ��������������.
short QuantityChannelADC ;// - ������������ ���������� ������� � ������ ���.
short QuantityChannelDAC;// - ������������ ���������� ������� � ������ ���.
short Reserv3 ;// - �� ������������ � ���������� �� setup.
unsigned long long Flag;// - ���������� ����������.
unsigned long long CurrentCounter ;//- �������� �������� � ������ ������.
unsigned long long IrqCounter;// - �������� �������� � ������� ����������.
unsigned long long IrqPeriod ;//- ������� ������ ����������.
unsigned long long FreqCounter ;//- ������� ��������.
long MyError ;//- ������ ����� ��� ������� ���������� .
short modify;// - ����� ���������, ������ ������������ ��������� ���������� ����������, ������ ��������� ����� ���������.
long AdrDSP;// - ����� �� DSP.
void *AdrMem ;//- ����� ������ ��� DSP.
long count ;//- ���������� ���� ��� ��������.
long numberCHNL;// - ����� ������ (��������� ����������.
short TestCode[6] ;//- �������� ��������. 
char verDSP[32];// - ������ DSP.
char DeviceName[16];// - ��� �������.
char Reserv4[16] ;//- ���������������.
char verDriver[64];// - ������ ��������.
long sizeInterruptDAC ;//- ������ ��� ��������� ������ ��� ������ ���������� ���.(sizeInterruptDAC = QuantityPacketsDAC * SizePacketDAC).
long StartDAC ;//- ��������� ����� ������ ��� 1- ����
long MaxSizeInterrupt ;//- ����������� ��������� ������ ��� ��������� ������ ��� ������ ����������.
long MaxSizeInterruptDAC;// - ����������� ��������� ������ ��� ��������� ������ ��� ������ ���������� ���.
long ChannelDAC ;//- ������� ���������� ��������� ������� ���.
long EnaCycleDAC ;//- ���������� ������������ ���������� ���: 0- ����������, 1-����������.
long ExtCycleDAC ;//- 0 - ��������� ������� �� ���������� ������ DSP, ��� �������� �� ������� ������, 1 - ��������� ������� �� ������� ������ � ��������� �� ������
short QuantityPacketsADC;// - ���������� ������� ������������ �� ���� ���������� ���.
short QuantityPacketsDAC ;//- ���������� ������� ������������ �� ���� ���������� ���.
short MaxQuantityPacketsADC ;//- ������������ ���������� ������� ������������ �� ���� ���������� ���.
short MaxQuantityPacketsDAC ;//- ������������ ���������� ������� ������������ �� ���� ���������� ���.
short Revision;// - ������� ����������.
short Reserved[9];// - ��������������� ADC_INFO, *PADC_INFO;
short StartPWM ;//- ������ ��� (0x01 - ����� 1 ������, 0x02 - ����� 2 ������, 0x04 - ����� 3 ������, 0x100 - ���� 1 ������, 0x200 - ���� 2 ������, 0x400 - ���� 3 ������)
short RatePWM ;//- �����������. ������� ������� ������� ��� ���.
short PeriodPWM ;//- ������ ���.
short OnDutyPWM0 ;//- ���������� ��� (����� 0).
short OnDutyPWM1 ;//- ���������� ��� (����� 1).
short OnDutyPWM2 ;//- ���������� ��� (����� 2).
short ShiftPWM1 ;//- ����� ��� (����� 0).
short ShiftPWM2;// - ����� ��� (����� 1).
long SizeBuferDSP_DAC ;//- ������ ������ SDRAM ��� � DSP.
long MaxSizeBuferDSP_DAC ;//- ������������ ������ ������ SDRAM ��� � DSP.
double ExtOporFreqDAC ;//- ������� ������� ������� ���.
long OfsetChanADC[32] ;//- ��������������� �������� ���.
long OfsetChanDAC[4] ;//- ��������������� �������� ���.
unsigned long long StartTime ;//- ���� � ����� ����������� �������.
unsigned long long GPSTime ;//- ���� � ����� ��������� GPS.
long long Drift ;//- ������� �������� ���-�� �������� ����-�� (������� 4 �����).
long long SyncDrift ;//- ������� �������� � ������ ��������� �������������.
char SyncCount;// - ������� �������������.
char SyncFlag ;//- ���� �������������.
char SatsInUse ;//- ���������� ������������� ���������, ��������� ��� �������������.
char StatePTP ;//- ��������� ����� PTP: 0 - PTP ����������, 3 - Disabled, 6 - Master, 9 - Slave.
unsigned short ReservedExt[264] ;//- ���������������.
unsigned long long FreqCounterPC;// - ������������ ������ ��������.
unsigned long long StartCounterPC ;//- ������������ ������ ��������.
unsigned long long EndCounterPC ;//- ������������ ������ ��������.
unsigned long long DurationSynhrPC ;//-������������ ������ ��������.
unsigned long TimerDSP;// - ������������ ������ ��������.
unsigned long NumberSecondDSP;// - ������������ ������ ��������.
unsigned long FreqQuartzDSP ;//- ������������ ������ ��������.
unsigned long Reserved1;// - ���������������.
unsigned long Reserved2 ;//- ���������������.
unsigned long Reserved3;// - ���������������.
unsigned long Reserved4 ;//- ���������������.
unsigned long Reserved5 ;//- ���������������.
unsigned short Command ;//- �������.
unsigned short Error ;//-�������������� ��� ��� ������.
unsigned long Size ;//- ������ � ������.
unsigned short Data[252] ;//- ������.
};