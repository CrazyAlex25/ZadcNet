//adcinfo.h
struct ADC_INFO {
short numberDSP;// - порядковый номер DSP на плате.
short typeADC;// - режим работы DSP: 0 - ADC, 1 - DAC.
short EnableADC;// - наличие АЦП.
short EnableDAC;// - наличие ЦАП.
short EnableExtDevice;// - наличие аппаратной поддержки: 0 - ничего нет,0x01 - PRUS, 0x02 - HCP (ICP), 0x04 - Atten, 0x08 - SD-card, 0x10 -Ethernet, 0x20 - Bluetooth, 0x40 - PWM (ШИМ), 0x80 - DigAnaliz(Логический анализатор), 0x100 - 1-Wire (TEDs), 0x200 - Подстройка по GPS, 0x400 - Синхронизация по PTP.
short Start;// - состояние ввода данных 1- ввод.
long Channel;// - битовая комбинация вводимых каналов.
long HCPChannel;// - битовая комбинация включенных каналов HCP.
long OverloadChannel;// - битовая комбинация перегруженных каналов.
short WorkChADC;// - количество работающих каналов АЦП.
short WorkChDAC;// - количество работающих каналов ЦАП.
short KodAmplify[32];// - коды усиления на АЦП.
short TypeConnection;// - тип интерфейса (1 - PCI, 2 - USB, 3 - Ethernet, 4 -Bluetouch).
double Amplitude[32];// - коэффициент усиления усилителя АЦП.
short PRUS[32];// - коды усиления усилителя заряда / вкл. (выкл.) HCP.
double PreAmplitude[32];// - коэффициент усиления предусилителя.
short Atten[4];// - коды аттенюатора ЦАП.
double Reduction[4];// - коэффициент передачи аттенюатора ЦАП.

short EnaExtStart;// - разрешение внешнего старта АЦП 0 - внутренний, 1- внешний.
short EnaExtFreq ;//- разрешение внешней частоты ЦАП 0 - внутренний,1 - внешний.
short EnaCycle;// - разрешение циклического накопления 0-однократно, 1-циклически.
short ExtCycle;// - MasterSynchr: 1 - Задатчик синхронизации, 0 - ведомоеустройство в синхронизации.
short ModaADC ;//- мода работы АЦП 0-1, 1-2, 2-4, 3-5, 4-8, 5-10 прореживание.
short EnaExtStartDAC;// - разрешение внешнего старта ЦАП 0 -внутренний, 1- внешний.
short EnaExtFreqDAC;// - разрешение внешней частоты ЦАП 0 -внутренний, 1- внешний.
short Reserv1 ;//- резерв 1 используется в программе CableTest.exe
short Reserv2;// - резерв 1 используется в программе CableTest.exe
double Freq ;//- текущая частота преобразования (Freq = OporFreq/Rate).
double OporFreq;// - внешняя опорная частота.
long Rate;// - коэффициент деления опорной частоты.
long sizeInterrupt;// - размер для перекачки данных при каждом прерывании АЦП (sizeInterrupt = QuantityPacketsADC * SizePacketADC).
short *AddressBufer;// - адрес буфера в системной области.
short *AddressBuferDAC;// - адрес буфера в системной области ЦАП.
short *AddressUserBufer ;//- адреса буфера в пользовательской области.
short *AddressUserBuferDAC;// - адреса буфера в пользовательскойобласти ЦАП.
long SizeBufer;// - размер буфера ввода не более 1 000 000 отсчетов.
long SizeBuferDAC;// - размер буфера генератора не более 1 000 000 отсчетов.
long Pointer;//- индекс текущего накопления в буфере АЦП.
long PointerDAC;// - индекс текущего накопления в буфере ЦАП.
long PointerDSP;// - индекс прошедшего накопления в DSP.
short Bits;// - количество бит в АЦП преобразователе.
short BitsDAC;// - количество бит в ЦАП.
short Words;// - количество 16-разрядных слов в одном отсчете.
short WordsDAC;// - количество 16-разрядных слов в одном отсчете ЦАП.
short QuantityChannelDigPort;// - количество линий цифрового порта.
double DigitalResolution ;//- вес младшего разряда АЦП.
double DigitalResolutionDAC;// - вес младшего разряда ЦАП.
double MaxFreq ;//- максимальная частота преобразования.
short QuantityChannelADC ;// - максимальное количество каналов в модуле АЦП.
short QuantityChannelDAC;// - максимальное количество каналов в модуле ЦАП.
short Reserv3 ;// - не используется в программах из setup.
unsigned long long Flag;// - количество прерываний.
unsigned long long CurrentCounter ;//- значение счетчика в момент опроса.
unsigned long long IrqCounter;// - значение счетчика в текущее прерывание.
unsigned long long IrqPeriod ;//- текущий период прерываний.
unsigned long long FreqCounter ;//- частота счетчика.
long MyError ;//- ошибка ввода или задания параметров .
short modify;// - номер изменения, каждое существенное изменение параметров устройства, делает инкремент этого параметра.
long AdrDSP;// - адрес из DSP.
void *AdrMem ;//- адрес памяти для DSP.
long count ;//- количество слов для передачи.
long numberCHNL;// - номер канала (служебная переменная.
short TestCode[6] ;//- тестовые проверки. 
char verDSP[32];// - версия DSP.
char DeviceName[16];// - имя прибора.
char Reserv4[16] ;//- зарезервировано.
char verDriver[64];// - версия драйвера.
long sizeInterruptDAC ;//- размер для перекачки данных при каждом прерывании ЦАП.(sizeInterruptDAC = QuantityPacketsDAC * SizePacketDAC).
long StartDAC ;//- состояние ввода данных ЦАП 1- ввод
long MaxSizeInterrupt ;//- максимально возможный размер для перекачки данных при каждом прерывании.
long MaxSizeInterruptDAC;// - максимально возможный размер для перекачки данных при каждом прерывании ЦАП.
long ChannelDAC ;//- битовая комбинация выводимых каналов ЦАП.
long EnaCycleDAC ;//- разрешение циклического накопления ЦАП: 0- однократно, 1-циклически.
long ExtCycleDAC ;//- 0 - генерация сигнала из внутренней памяти DSP, без подкачки из внешней памяти, 1 - генерация сигнала из внешней памяти с подкачкой по прерыв
short QuantityPacketsADC;// - количество пакетов передаваемых за одно прерывание АЦП.
short QuantityPacketsDAC ;//- количество пакетов передаваемых за одно прерывание ЦАП.
short MaxQuantityPacketsADC ;//- максимальное количество пакетов передаваемых за одно прерывание АЦП.
short MaxQuantityPacketsDAC ;//- максимальное количество пакетов передаваемых за одно прерывание ЦАП.
short Revision;// - ревизия устройства.
short Reserved[9];// - зарезервировано ADC_INFO, *PADC_INFO;
short StartPWM ;//- запуск ШИМ (0x01 - старт 1 канала, 0x02 - старт 2 канала, 0x04 - старт 3 канала, 0x100 - стоп 1 канала, 0x200 - стоп 2 канала, 0x400 - стоп 3 канала)
short RatePWM ;//- коэффициент. деления опорной частоты для ШИМ.
short PeriodPWM ;//- период ШИМ.
short OnDutyPWM0 ;//- скважность ШИМ (канал 0).
short OnDutyPWM1 ;//- скважность ШИМ (канал 1).
short OnDutyPWM2 ;//- скважность ШИМ (канал 2).
short ShiftPWM1 ;//- сдвиг ШИМ (канал 0).
short ShiftPWM2;// - сдвиг ШИМ (канал 1).
long SizeBuferDSP_DAC ;//- размер буфера SDRAM ЦАП в DSP.
long MaxSizeBuferDSP_DAC ;//- максимальный размер буфера SDRAM ЦАП в DSP.
double ExtOporFreqDAC ;//- внешняя опорная частота ЦАП.
long OfsetChanADC[32] ;//- откалиброванное смещение АЦП.
long OfsetChanDAC[4] ;//- откалиброванное смещение ЦАП.
unsigned long long StartTime ;//- дата и время синхронного запуска.
unsigned long long GPSTime ;//- дата и время приемника GPS.
long long Drift ;//- текущее смещение отн-но ведущего устр-ва (младшие 4 байта).
long long SyncDrift ;//- текущее смещение в момент последней синхронизации.
char SyncCount;// - счетчик синхронизаций.
char SyncFlag ;//- флаг синхронизации.
char SatsInUse ;//- количество навигационных спутников, доступных для использования.
char StatePTP ;//- состояние порта PTP: 0 - PTP недоступен, 3 - Disabled, 6 - Master, 9 - Slave.
unsigned short ReservedExt[264] ;//- зарезервировано.
unsigned long long FreqCounterPC;// - используется внутри драйвера.
unsigned long long StartCounterPC ;//- используется внутри драйвера.
unsigned long long EndCounterPC ;//- используется внутри драйвера.
unsigned long long DurationSynhrPC ;//-используется внутри драйвера.
unsigned long TimerDSP;// - используется внутри драйвера.
unsigned long NumberSecondDSP;// - используется внутри драйвера.
unsigned long FreqQuartzDSP ;//- используется внутри драйвера.
unsigned long Reserved1;// - зарезервировано.
unsigned long Reserved2 ;//- зарезервировано.
unsigned long Reserved3;// - зарезервировано.
unsigned long Reserved4 ;//- зарезервировано.
unsigned long Reserved5 ;//- зарезервировано.
unsigned short Command ;//- команда.
unsigned short Error ;//-дополнительный код или ошибка.
unsigned long Size ;//- размер в байтах.
unsigned short Data[252] ;//- данные.
};