using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

using static Zadc.NativeMethods;

namespace Zadc
{
    public partial class ZadcNet
    {
        const int MAX_CHARS = 64; // max string value from adcinfo
        private readonly int dev, dsp;

        public ZadcNet(DeviceType dev, int dsp)
        {
            this.dev = (int)dev;
            this.dsp = dsp;
        }

        public void Open() => ZOpen(dev, dsp);
        public void Close() => ZClose(dev, dsp);
        public void ResetDSP() => ZResetDSP(dev, dsp);
        public void InitDSP(string fileName = "") => ZInitDSP(dev, dsp, fileName);

        
        public int GetSerialNumberDSP()
        {
            ZGetSerialNumberDSP(dev, dsp, out int number);
            return number;
        }
        
        public string GetNameDevice()
        {
            var name = new StringBuilder(MAX_CHARS);
            ZGetNameDevice(dev, dsp, name, name.Capacity);
            return name.ToString();
        }
        
        public string GetVersion()
        {
            StringBuilder sb1 = new StringBuilder(MAX_CHARS);
            StringBuilder sb2 = new StringBuilder(MAX_CHARS);
            StringBuilder sb3 = new StringBuilder(MAX_CHARS);
            ZGetVersion(dev, dsp, sb1, sb2, sb3);
            return $"{sb1.ToString()}\n{sb2.ToString()}\n{sb3.ToString()}";

        }
        
        public ConnectionType GetTypeConnection()
        {
            ZGetTypeConnection(dev, dsp, out int type);
            return (ConnectionType)type;
        }

        
        public int GetError()
        {
            ZGetError(dev, dsp, out int err);
            return err;
        }
       
        public int GetModify()
        {
            ZGetModify(dev, dsp, out int mod);
            return mod;
        }

       
        public uint GetFlag()
        {
            ZGetFlag(dev, dsp, out uint flag);
            return flag;
        }

        
        public int GetQuantityChannelADC()
        {
            ZGetQuantityChannelADC(dev, dsp, out int QuantityChannelADC);
            return QuantityChannelADC;
        }

        public void SetInputADC(int numberChannel, int enable) => ZSetInputADC(dev, dsp, numberChannel, enable);


        public double GetDigitalResolChanADC(int numberChannel)
        {
            ZGetDigitalResolChanADC(dev, dsp, numberChannel, out double digitalResolChan);
            return digitalResolChan;
        }

       
        public int GetNumberInputADC()
        {
            ZGetNumberInputADC(dev, dsp, out int work);
            return work;
        }

        
        public int GetWordsADC()
        {
            ZGetWordsADC(dev, dsp, out int words);
            return words;
        }

        public double GetAmplifyADC(int numberChannel)
        {
            ZGetAmplifyADC(dev, dsp, numberChannel, out double amplify);
            return amplify;
        }


        public void GetBufferADC(out IntPtr buffer, out int size)
        {
            ZGetBufferADC(dev, dsp, out buffer, out size);
        }
        public void RemBufferADC(ref IntPtr buffer)
        {
            ZRemBufferADC(dev, dsp, ref buffer);
        }
        
        public int GetPointerADC()
        {
            ZGetPointerADC(dev, dsp, out int pointer);
            return pointer;
        }
        public double SetFreqADC(double freq)
        {
            ZSetFreqADC(dev, dsp, freq, out double freqOut);
            return freqOut;
        }

        public void StartADC()
        {
            ZStartADC(dev, dsp);
            cancelReadADC = new CancellationTokenSource();
            Task.Run((Action)OnStartADC, cancelReadADC.Token);
        }


        public void StopADC()
        {
            cancelReadADC?.Cancel();
            ZStopADC(dev, dsp);
        }

        public double SetAmplifyADC(int numChannel,double amplify)
        {
            ZSetAmplifyADC(dev, dsp, numChannel, amplify, out double ampOut);
            return ampOut;
        }

        public double GetDigitalResolutionADC()
        {
            ZGetDigitalResolutionADC(dev, dsp, out double res);
            return res;
        }

        public int GetBitsADC()
        {
            ZGetBitsADC(dev, dsp, out int bits);
            return bits;
        }
    }
}
