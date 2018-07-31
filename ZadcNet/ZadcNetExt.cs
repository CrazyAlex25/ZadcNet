using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Zadc
{
    partial class ZadcNet
    {
        CancellationTokenSource cancelReadADC;

        public delegate void DelegateReadADC(double[] data);
        public event DelegateReadADC OnReadADC = delegate { };

        public int SerialNumber => GetSerialNumberDSP();
        public string DeviceName => GetNameDevice();
        public string Version => GetVersion();
        public ConnectionType ConnectionType => GetTypeConnection();
        public int Error => GetError();
        public int Modify => GetModify();
        public uint Flag => GetFlag();
        public int QuantityChannelADC => GetQuantityChannelADC();
        public int NumberInputADC => GetNumberInputADC();
        public int WordsADC => GetWordsADC();
        public int PointerADC => GetPointerADC();




        //Примечание: Данные, доступные для обработки — это данные между pointerADC_old и pointerADC.
        //Чем больше частота, тем больше будет между ними разница в момент обработки.
        //Соответственно, если pointerADC_old != pointerADC, то это означает, 
        //что накопились данные размером от pointerADC_old до pointerADC (нужно не забыть учесть переход через границу кольцевого буфера, в примере это есть).

        //Так же хотелось бы напомнить о том, как выглядит цикл для считывания данных по всем отсчётам:

        //При частоте 32 кГц за секунду будет приходить 32000 отсчёт ов по каждому включенному каналу.
        //Если включен один канал то будет приходить всего 32000 отсчёт ов,
        //т.е.указатель pointerADC будет изменяться на 32000 позиций (поскольку в ZET210 16-разрядный АЦП и один отсчёт соответствует одному слову, т.е. 2 байтам).
        //Таким образом цикл сводится к тому, чтобы запрашивать позицию pointerADC, сравнивать ее с предыдущим значением и если между ними есть разница,
        //то можно из буфера взять данные от pointerADCold до pointerADC — это и есть новые пришедшие данные.
        private void OnStartADC()
        {
            GetBufferADC(out IntPtr buffer, out int size);
            var bitsADC = GetWordsADC();
            var numChannels = GetNumberInputADC();

            int ptr = 0;
            int ptr_old = 0;
            int sleep = 100;

            if (bitsADC==1)
            {
                while (!cancelReadADC.IsCancellationRequested)
                {
                    Thread.Sleep(sleep);
                 
                    ptr = GetPointerADC();
                    if (ptr == ptr_old) continue;
                    var data = ReadShort(ref buffer, size, ptr_old, ptr);
                    ptr_old = ptr;
                    OnReadADC(data);
                }
            }
            else
            {
                while (!cancelReadADC.IsCancellationRequested)
                {
                    Thread.Sleep(sleep);
                    ptr = GetPointerADC();
                    if (ptr == ptr_old) continue;
                    var data = ReadInt(ref buffer, size, ptr_old, ptr);
                    ptr_old = ptr;
                    OnReadADC(data);
                }
            }

            RemBufferADC(ref buffer);
        }

        private unsafe double[] ReadShort(ref IntPtr buffer,int buffer_size,int start,int stop,int count=0)
        {
            var ptr = (short*)buffer;
            var dataLenght = stop - start;
            if (dataLenght < 0)
                dataLenght = buffer_size - start + stop;
            if (count > 0)
                dataLenght = count;

            double[] data = new double[dataLenght];

            int i_start = start;
            int i_stop = start + dataLenght;
            int y = 0;
            while (i_start < i_stop)
            {
                int index = i_start % buffer_size;
                data[y] = ptr[index];
                i_start++;
                y++;
            }
            return data;
        }
        private unsafe double[] ReadInt(ref IntPtr buffer, int buffer_size, int start, int stop, int count = 0)
        {
            var ptr = (int*)buffer;
            var dataLenght = stop - start;
            if (dataLenght < 0)
                dataLenght = buffer_size - start + stop;
            if (count > 0)
                dataLenght = count;

            double[] data = new double[dataLenght];

            int i_start = start;
            int i_stop = start + dataLenght;
            int y = 0;
            while (i_start < i_stop)
            {
                int index = i_start % buffer_size;
                data[y] = ptr[index];
                i_start++;
                y++;
            }
            return data;
        }
    }
}
