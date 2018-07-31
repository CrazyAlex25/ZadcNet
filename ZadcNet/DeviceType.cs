using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadc
{
    // Поддерживаемые типы устройств
    //#define KD1610		0	// ADC 16/200
    //#define KD216		    1	// APC 216
    //#define KD500		    2	// ADC 16/500
    //#define KD500P		3	// ADC 16/500P
    //#define KD816		    4	// ADC 816
    //#define KD1002		5	// ADC 1002
    //#define KDU216		6	// APC 216 USB
    //#define KD24		    7	// ADC 24
    //#define KD1432		8	// ADC 1432
    //#define KDUACPB		9	// ACPB USB
    //#define KDU1616		10	// ZET210
    //#define KDUPD14		11	// PD14 USB
    //#define KDUVN		    12	// ZET110
    //#define KDUOSC		13	// ZET302
    //#define KDU8500		14	// A17U8
    //#define KDU2500		15	// A17U2
    //#define KDU1624		16	// ZET220
    //#define KDU0424		17	// ZET230
    //#define KDU0414		18	// ZET
    //#define KDU0824		19	// ZET240

    public enum DeviceType
    {
        ADC_16_200 = 0,
        APC_216 = 1,
        ADC_16_500 = 2,
        ADC_16_500P = 3,
        ADC_816 = 4,
        ADC_1002 = 5,
        APC_216_USB = 6,
        ADC_24 = 7,
        ADC_1432 = 8,
        ACPB_USB = 9,
        ZET210 = 10,
        PD14_USB = 11,
        ZET110 = 12,
        ZET302 = 13,
        A17U8 = 14,
        A17U2 = 15,
        ZET220 = 16,
        ZET230 = 17,
        ZET = 18,
        ZET240 = 19
    }
}
