using Lomont;
using OxyPlot;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media;
using Zadc;


namespace ZetLabGUI
{
    public class ViewModel
    {
        private ZadcNet z = new ZadcNet(DeviceType.A17U2,0);

        public GraphModel PlotModel1 { get; private set; } = new GraphModel("oscillogram");
        public GraphModel PlotModel2 { get; private set; } = new GraphModel("fft");

        int fft_size = 1024*8;
        double freq = 0;

        double koef;
        public ViewModel()
        {
            z.Open();
            z.InitDSP();
            Console.WriteLine($"Название: {z.GetNameDevice()}");
            Console.WriteLine($"Серийник: {z.GetSerialNumberDSP()}");
            var numChannelsADC = z.GetQuantityChannelADC();

            var bits = z.GetBitsADC();
            Console.WriteLine($"Битность АЦП: {bits}");
            Console.WriteLine($"Кол-во каналов АЦП: {numChannelsADC}");
            z.SetInputADC(0, 1); // вкл 1 канал
            if (numChannelsADC > 1)
                z.SetInputADC(1, 0);



            var amp = z.SetAmplifyADC(0, 1);
            Console.WriteLine($"Усиление: {amp}");

            var amplifyADC0 = z.GetAmplifyADC(0);
            Console.WriteLine($"Усиление, 1 канал: {amplifyADC0}");
            var amplifyADC1 = amplifyADC0;
            if (numChannelsADC > 1)
            {
                amplifyADC1 = z.GetAmplifyADC(1);
                Console.WriteLine($"Усиление, 2 канал: {amplifyADC1}");
            }

            var rrr = z.GetDigitalResolutionADC();
            Console.WriteLine($"Разрешение АЦП: {rrr}");

            var resolutionADC0 = z.GetDigitalResolChanADC(0);
            Console.WriteLine($"Разрешение, 1 канал: {resolutionADC0}");
            var resolutionADC1 = resolutionADC0;
            if (numChannelsADC > 1)
            {
                resolutionADC1 = z.GetDigitalResolChanADC(1);
                Console.WriteLine($"Разрешение, 2 канал: {resolutionADC1}");
            }

            numChannelsADC = z.GetNumberInputADC();
            Console.WriteLine($"Кол-во активных каналов: {numChannelsADC}");
            var numWordsADC = z.GetWordsADC();
            Console.WriteLine($"Кол-во слов в отсчете: {numWordsADC}");


            if (numWordsADC == 0 || amplifyADC0 == 0 || amplifyADC1 == 0)
            {
                Console.WriteLine("Деление на 0! Выход");
                z.Close();
                Console.ReadLine();
                return;
            }


            freq = z.SetFreqADC(25000);

             koef = resolutionADC0 / amplifyADC0;
            Console.WriteLine($"Множитель: {koef}");

            Console.WriteLine($"{freq / fft_size}");

             z.StopADC();
             z.OnReadADC += UpdateOscillogram;
             z.OnReadADC += UpdateFFT;
             z.StartADC();

            //z.StopADC();
            //z.Close();
        }

        private void UpdateFFT(double[] data)
        {
                //берем кол-во элементов == fft_size
                // koef*x = получаем значение в Вольтах
                var dat = data.AsParallel().Take(fft_size).Select(x => x * koef).ToArray();


                dat = FFTUtils.AbsFFT(dat);


                //index * (freq / fft_size)  = перевести в частоту
                //  20*Math.Log10((point * (2.0 / fft_size))/10e-6))   амплитуда в дБ,   point * (2.0 / fft_size) амплитуда
                var tt = (2.0 / fft_size) / 10e-6;

                var points = dat.AsParallel()
                    .Take(fft_size / 2)
                    .Select((point, index) => new DataPoint(index * (freq / fft_size), Log10(point * (2.0 / fft_size))))
                    .Skip(1) // убирать DC
                    .ToArray();

                PlotModel2.Update(points);

        }

        double Log10(double value)
        {
            return 20 * Math.Log10(value / 10e-6);
        }

        private void UpdateOscillogram(double[] data)
        {
                var dat = data.AsParallel().Take(fft_size).Select((point, index) => new DataPoint(index, point * koef)).ToArray();
                PlotModel1.Update(dat);

        }
    }
}
