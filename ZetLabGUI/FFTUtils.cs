using Lomont;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace ZetLabGUI
{
    /// <summary>
    /// FFTUtils is a class utilising the Lomont FFT class for FFT transforms
    /// as well as having utility classes for converting from real arrays to complex arrays
    /// as used by the exocortex FFT and Lomont FFT
    /// http://www.exocortex.org/dsp/
    /// http://www.lomont.org
    /// 
    /// perivar@nerseth.com
    /// </summary>
    public static class FFTUtils
    {
        public enum FFTMethod : int
        {
            DFT = 0,
            IDFT = 1,
            DHT = 2
        }

        #region FFT and IFFT methods
        /// <summary>
        /// This method duplicates exactly the function
        /// abs(fft(input)) in MATLAB
        /// The MATLAB abs() is equal to sqrt(real(X).^2 + imag(X).^2)
        /// </summary>
        /// <param name="input">e.g. an audio signal</param>
        /// <returns>an array with frequency information (power spectrum or magnitude)</returns>
        public static double[] AbsFFT(double[] input)
        {
            double[] fftArray = FFT(input);
            return Abs(fftArray);
        }

        /// <summary>
        /// This method duplicates exactly the function
        /// abs(fft(input)) in MATLAB
        /// The MATLAB abs() is equal to sqrt(real(X).^2 + imag(X).^2)
        /// </summary>
        /// <param name="floatArray">e.g. an audio signal</param>
        /// <returns>an array with frequency information (power spectrum or magnitude)</returns>
        public static float[] AbsFFT(float[] floatArray)
        {
            double[] doubleArray = MathUtils.FloatToDouble(floatArray);
            double[] doubleArray2 = AbsFFT(doubleArray);
            return MathUtils.DoubleToFloat(doubleArray2);
        }

        /// <summary>
        /// This method duplicates exactly the function
        /// fft(input) in MATLAB
        /// </summary>
        /// <param name="floatArray">e.g. an audio signal</param>
        /// <returns>a complex array (the array alternates between a real and an imaginary value)</returns>
        public static double[] FFT(float[] floatArray)
        {
            double[] doubleArray = MathUtils.FloatToDouble(floatArray);
            return FFT(doubleArray);
        }

        /// <summary>
        /// This method duplicates exactly the function
        /// fft(input) in MATLAB
        /// </summary>
        /// <param name="input">e.g. an audio signal</param>
        /// <returns>a complex array (the array alternates between a real and an imaginary value)</returns>
        public static double[] FFT(double[] input)
        {
            var fft = new LomontFFT();
            var complexSignal = DoubleToComplexDouble(input);
            fft.FFT(complexSignal, true);
            return complexSignal;
        }

        /// <summary>
        /// This method duplicates exactly the function
        /// ifft(input) in MATLAB
        /// Requires a complex input number to be able to exactly
        /// transform back to an orginal signal
        /// i.e. x = ifft(fft(x))
        /// </summary>
        /// <param name="floatArray"></param>
        /// <param name="inputComplex">If true, the input array is a complex arrray.
        /// i.e. the array alternates between a real and an imaginary value.
        /// If false, the array contains only real values</param>
        /// <param name="returnComplex">If true, return a complex return arrray.
        /// i.e. the array alternates between a real and an imaginary value.
        /// If false, return only the positive real value
        /// </param>
        /// <returns>signal (complex or only positive real values)</returns>
        public static float[] IFFT(float[] floatArray, bool inputComplex = true, bool returnComplex = true)
        {
            double[] doubleArray = MathUtils.FloatToDouble(floatArray);
            double[] doubleArray2 = IFFT(doubleArray, inputComplex, returnComplex);
            return MathUtils.DoubleToFloat(doubleArray2);
        }

        /// <summary>
        /// This method duplicates exactly the function
        /// ifft(input) in MATLAB
        /// Requires a complex input number to be able to exactly
        /// transform back to an orginal signal
        /// i.e. x = ifft(fft(x))
        /// </summary>
        /// <param name="input"></param>
        /// <param name="inputComplex">If true, the input array is a complex arrray.
        /// i.e. the array alternates between a real and an imaginary value.
        /// If false, the array contains only real values</param>
        /// <param name="returnComplex">If true, return a complex return arrray.
        /// i.e. the array alternates between a real and an imaginary value.
        /// If false, return only the positive real value
        /// </param>
        /// <returns>signal (complex or only positive real values)</returns>
        public static double[] IFFT(double[] input, bool inputComplex = true, bool returnComplex = true)
        {
            var fft = new LomontFFT();

            double[] complexSignal;
            if (inputComplex)
            {
                complexSignal = input;
            }
            else
            {
                complexSignal = DoubleToComplexDouble(input);
            }

            fft.FFT(complexSignal, false);

            if (returnComplex)
            {
                return complexSignal;
            }
            else
            {
                return Real(complexSignal);
            }
        }
        #endregion

        #region Abs, Real and Imag Methods
        /// <summary>
        /// This method duplicates the function
        /// abs(input) in MATLAB for a complex signal array
        /// i.e. the array alternates between a real and an imaginary value
        /// The MATLAB abs() is equal to sqrt(real(X).^2 + imag(X).^2)
        /// </summary>
        /// <param name="complexSignal">a complex array (the array alternates between a real and an imaginary value)</param>
        /// <param name="scale">scaling factor (1 is no scaling)</param>
        /// <returns>new signal (also called the power spectrum or magnitude)</returns>
        public static double[] Abs(double[] complexSignal, double scale = 1)
        {
            int N = complexSignal.Length / 2;

            var abs = new double[N];
            for (int j = 0; j < N; j++)
            {
                double re = complexSignal[2 * j];
                double img = complexSignal[2 * j + 1];
                abs[j] = Math.Sqrt(re * re + img * img) * scale;
            }
            return abs;
        }

        /// <summary>
        /// This method duplicates the function
        /// abs(input) in MATLAB for a complex signal array
        /// i.e. the array alternates between a real and an imaginary value
        /// The MATLAB abs() is equal to sqrt(real(X).^2 + imag(X).^2)
        /// </summary>
        /// <param name="complexSignal">a complex array (the array alternates between a real and an imaginary value)</param>
        /// <param name="scale">scaling factor (1 is no scaling)</param>
        /// <returns>new signal (also called the power spectrum or magnitude)</returns>
        public static float[] Abs(float[] complexSignal, float scale = 1)
        {
            int N = complexSignal.Length / 2;

            var abs = new float[N];
            for (int j = 0; j < N; j++)
            {
                float re = complexSignal[2 * j];
                float img = complexSignal[2 * j + 1];
                abs[j] = (float)Math.Sqrt(re * re + img * img) * scale;
            }
            return abs;
        }

        /// <summary>
        /// This method duplicates exactly the function
        /// real(input) in MATLAB
        /// Requires a complex input number array
        /// </summary>
        /// <param name="complexSignal">a complex array (the array alternates between a real and an imaginary value)</param>
        /// <param name="scale"></param>
        /// <returns>the real portion of the signal</returns>
        public static double[] Real(double[] complexSignal, double scale = 1)
        {
            int N = complexSignal.Length / 2;

            var returnArray = new double[N];
            for (int j = 0; j < N; j++)
            {
                double re = complexSignal[2 * j] * scale;
                double img = complexSignal[2 * j + 1] * scale;
                returnArray[j] = re;
            }
            return returnArray;
        }

        /// <summary>
        /// This method duplicates exactly the function
        /// real(input) in MATLAB
        /// Requires a complex input number array
        /// </summary>
        /// <param name="complexSignal">a complex array (the array alternates between a real and an imaginary value)</param>
        /// <param name="scale"></param>
        /// <returns>the real portion of the signal</returns>
        public static float[] Real(float[] complexSignal, float scale = 1)
        {
            int N = complexSignal.Length / 2;

            var returnArray = new float[N];
            for (int j = 0; j < N; j++)
            {
                float re = complexSignal[2 * j] * scale;
                float img = complexSignal[2 * j + 1] * scale;
                returnArray[j] = re;
            }
            return returnArray;
        }

        /// <summary>
        /// This method duplicates exactly the function
        /// imag(input) in MATLAB
        /// Requires a complex input number array
        /// </summary>
        /// <param name="complexSignal">a complex array (the array alternates between a real and an imaginary value)</param>
        /// <param name="scale"></param>
        /// <returns>the imaginary portion of the signal</returns>
        public static double[] Imag(double[] complexSignal, double scale = 1)
        {
            int N = complexSignal.Length / 2;

            var returnArray = new double[N];
            for (int j = 0; j < N; j++)
            {
                double re = complexSignal[2 * j] * scale;
                double img = complexSignal[2 * j + 1] * scale;
                returnArray[j] = img;
            }
            return returnArray;
        }

        /// <summary>
        /// This method duplicates exactly the function
        /// imag(input) in MATLAB
        /// Requires a complex input number array
        /// </summary>
        /// <param name="complexSignal">a complex array (the array alternates between a real and an imaginary value)</param>
        /// <param name="scale"></param>
        /// <returns>the imaginary portion of the signal</returns>
        public static float[] Imag(float[] complexSignal, float scale = 1)
        {
            int N = complexSignal.Length / 2;

            var returnArray = new float[N];
            for (int j = 0; j < N; j++)
            {
                float re = complexSignal[2 * j] * scale;
                float img = complexSignal[2 * j + 1] * scale;
                returnArray[j] = img;
            }
            return returnArray;
        }
        #endregion

        #region Convert Signal to Complex Signal Types
        /// <summary>
        /// Convert a real signal to a signal of a complex type
        /// i.e. the array alternates between a real and an imaginary value
        /// </summary>
        /// <param name="input">real signal</param>
        /// <returns>complex signal</returns>
        public static double[] DoubleToComplexDouble(double[] input)
        {
            // LomontFFT and ExocortexDSP requires a complex signal to work
            // i.e. the array alternates between a real and an imaginary value
            // even - Re, odd - Img
            int N = input.Length;
            var complexSignal = new double[2 * N];
            for (int j = 0; j < N; j++)
            {
                complexSignal[2 * j] = (double)input[j];
                complexSignal[2 * j + 1] = 0;  // need to clear out as fft modifies buffer (phase)
            }
            return complexSignal;
        }

        /// <summary>
        /// Convert a real signal to a signal of a complex type
        /// i.e. the array alternates between a real and an imaginary value
        /// </summary>
        /// <param name="input">real signal</param>
        /// <returns>complex signal</returns>
        public static float[] FloatToComplexFloat(float[] input)
        {
            // LomontFFT and ExocortexDSP requires a complex signal to work
            // i.e. the array alternates between a real and an imaginary value
            // even - Re, odd - Img
            int N = input.Length;
            var complexSignal = new float[2 * N];
            for (int j = 0; j < N; j++)
            {
                complexSignal[2 * j] = (float)input[j];
                complexSignal[2 * j + 1] = 0;  // need to clear out as fft modifies buffer (phase)
            }
            return complexSignal;
        }

        /// <summary>
        /// Convert a real signal to a signal of a complex type
        /// i.e. the array alternates between a real and an imaginary value
        /// </summary>
        /// <param name="input">real signal</param>
        /// <returns>complex signal</returns>
        public static double[] FloatToComplexDouble(float[] input)
        {
            // LomontFFT and ExocortexDSP requires a complex signal to work
            // i.e. the array alternates between a real and an imaginary value
            // even - Re, odd - Img
            int N = input.Length;
            var complexSignal = new double[2 * N];
            for (int j = 0; j < N; j++)
            {
                complexSignal[2 * j] = (double)input[j];
                complexSignal[2 * j + 1] = 0;  // need to clear out as fft modifies buffer (phase)
            }
            return complexSignal;
        }

        /// <summary>
        /// Convert a real signal to a signal of a complex type
        /// i.e. the array alternates between a real and an imaginary value
        /// </summary>
        /// <param name="input">real signal</param>
        /// <returns>complex signal</returns>
        public static Complex[] DoubleToComplex(double[] input)
        {
            // LomontFFT and ExocortexDSP requires a complex signal to work
            // i.e. the array alternates between a real and an imaginary value
            // even - Re, odd - Img
            int N = input.Length;
            var complexSignal = new Complex[N];
            for (int j = 0; j < N; j++)
            {
                complexSignal[j] = new Complex(input[j], 0);
            }
            return complexSignal;
        }

        /// <summary>
        /// Return a complex double array (alternating between real and imaginary values)
        /// as an array with Complex objects
        /// </summary>
        /// <param name="complexDouble">complex double array</param>
        /// <returns>an array of Complex objects</returns>
        public static Complex[] ComplexDoubleToComplex(double[] complexDouble)
        {
            // LomontFFT returns a complex double array
            // i.e. the array alternates between a real and an imaginary value
            // even - Re, odd - Img
            int N = complexDouble.Length / 2;
            var complexSignal = new Complex[N];
            for (int j = 0; j < N; j++)
            {
                double re = complexDouble[2 * j];
                double img = complexDouble[2 * j + 1];
                complexSignal[j] = new Complex(re, img);
            }

            return complexSignal;
        }

        public static double[] ComplexToComplexDouble(Complex[] complexSignal)
        {
            // LomontFFT returns a complex double array
            // i.e. the array alternates between a real and an imaginary value
            // even - Re, odd - Img
            int N = complexSignal.Length;
            var complexDouble = new double[N * 2];

            for (int j = 0; j < N; j++)
            {
                double re = complexSignal[j].Real;
                double img = complexSignal[j].Imaginary;
                complexDouble[2 * j] = re;
                complexDouble[2 * j + 1] = img;
            }

            return complexDouble;
        }

        /// <summary>
        /// Convert a real signal to a signal of a complex type
        /// i.e. the array alternates between a real and an imaginary value
        /// </summary>
        /// <param name="input">real signal</param>
        /// <returns>complex signal</returns>
        public static Complex[] FloatToComplex(float[] input)
        {
            // LomontFFT and ExocortexDSP requires a complex signal to work
            // i.e. the array alternates between a real and an imaginary value
            // even - Re, odd - Img
            int N = input.Length;
            var complexSignal = new Complex[N];
            for (int j = 0; j < N; j++)
            {
                complexSignal[j] = new Complex(input[j], 0);
            }
            return complexSignal;
        }

        /// <summary>
        /// Convert a Half Complex Format to a Complex Format
        /// This method converts a half complex format to it's real components
        /// Requires a half complex input number array
        /// r0, r1, r2, ..., rn/2, i(n+1)/2-1, ..., i2, i1
        /// Here, rk is the real part of the kth output, and ikis the imaginary part. (Division by 2 is rounded down.)
        /// For a halfcomplex array hc[n], the kth component thus has its real part in hc[k] and its imaginary part in hc[n-k],
        /// with the exception of k == 0 or n/2 (the latter only if n is even)—in these two cases, the imaginary part is zero due to symmetries of the real-input DFT, and is not stored.
        /// Thus, the r2hc transform of n real values is a halfcomplex array of length n, and vice versa for hc2r.
        /// </summary>
        /// <param name="halfcomplex_coefficient"></param>
        /// <returns></returns>
        public static double[] HC2C(double[] halfcomplex_coefficient)
        {

            int n = halfcomplex_coefficient.Length;
            var complex_coefficient = new double[2 * n];

            complex_coefficient[0] = halfcomplex_coefficient[0];
            complex_coefficient[1] = 0.0;
            int i = 0;

            for (i = 1; i < n - i; i++)
            {
                double hc_real = halfcomplex_coefficient[i];
                double hc_imag = halfcomplex_coefficient[n - i];

                complex_coefficient[2 * i] = hc_real;
                complex_coefficient[2 * i + 1] = hc_imag;

                int endPos = 2 * (n - i + 1);
                complex_coefficient[endPos - 2] = hc_real;
                complex_coefficient[endPos - 1] = -hc_imag;
            }

            if (i == n - i)
            {
                complex_coefficient[n] = halfcomplex_coefficient[i];
                complex_coefficient[n + 1] = 0.0;
            }

            return complex_coefficient;
        }
        #endregion

        /// <summary>
        /// Generate a spectrogram array spaced linearily
        /// </summary>
        /// <param name="samples">audio data</param>
        /// <param name="fftWindowsSize">fft window size</param>
        /// <param name="fftOverlap">overlap in number of samples (normaly half of the fft window size) [low number = high overlap]</param>
        /// <returns>spectrogram jagged array</returns>
        public static double[][] CreateSpectrogramLomont(float[] samples, int fftWindowsSize, int fftOverlap)
        {
            var fft = new LomontFFT();

            int numberOfSamples = samples.Length;

            // overlap must be an integer smaller than the window size
            // half the windows size is quite normal
            double[] windowArray = FFTWindow.GetWindowFunction(FFTWindowType.HANNING, fftWindowsSize);

            // width of the segment - e.g. split the file into 78 time slots (numberOfSegments) and do analysis on each slot
            int numberOfSegments = (numberOfSamples - fftWindowsSize) / fftOverlap;
            var frames = new double[numberOfSegments][];

            // since we are dealing with small buffer sizes (1024) but are trying to detect peaks at low frequency ranges
            // octaves 0 .. 2 for example, zero padding is nessessary to improve the interpolation resolution of the FFT
            // otherwise FFT bins will be quite large making it impossible to distinguish between low octave notes which
            // are seperated by only a few Hz in these ranges.
            //const int ZERO_PAD_MULTIPLIER = 4; // zero padding adds interpolation resolution to the FFT, it also dilutes the magnitude of the bins
            // TODO: figure out how to properly use zero_padding

            // even - Re, odd - Img
            var complexSignal = new double[2 * fftWindowsSize];
            //var complexSignal = new double[2*fftWindowsSize*ZERO_PAD_MULTIPLIER*2]; // zero pad
            double lengthSqrt = Math.Sqrt(fftWindowsSize);
            for (int i = 0; i < numberOfSegments; i++)
            {
                // apply Hanning Window
                for (int j = 0; j < fftWindowsSize; j++)
                {
                    // Weight by Hann Window
                    complexSignal[2 * j] = (double)(windowArray[j] * samples[i * fftOverlap + j]);

                    // need to clear out as fft modifies buffer (phase)
                    complexSignal[2 * j + 1] = 0;
                }

                // FFT transform for gathering the spectrum
                fft.FFT(complexSignal, true);

                // get the ABS of the complex signal
                var band = new double[fftWindowsSize / 2];
                for (int j = 0; j < fftWindowsSize / 2; j++)
                {
                    double re = complexSignal[2 * j];
                    double img = complexSignal[2 * j + 1];

                    // do the Abs calculation and add with Math.Sqrt(audio_data.Length);
                    // i.e. the magnitude spectrum
                    band[j] = (double)(Math.Sqrt(re * re + img * img) * lengthSqrt);
                }
                frames[i] = band;
            }
            return frames;
        }


        /// <summary>
        /// Generate a spectrum graph array spaced linearily
        /// </summary>
        /// <param name="samples">audio data</param>
        /// <param name="fftWindowsSize">fft window size</param>
        /// <returns>spectrum graph array</returns>
        public static double[] CreateSpectrumAnalysisLomont(float[] samples, int fftWindowsSize)
        {
            var fft = new LomontFFT();

            int numberOfSamples = samples.Length;

            // overlap must be an integer smaller than the window size
            // half the windows size is quite normal
            double[] windowArray = FFTWindow.GetWindowFunction(FFTWindowType.HANNING, fftWindowsSize);

            // even - Re, odd - Img
            var complexSignal = new double[2 * fftWindowsSize];

            // apply Hanning Window
            // e.g. take 371 ms each 11.6 ms (2048 samples each 64 samples)
            for (int j = 0; (j < fftWindowsSize) && (samples.Length > j); j++)
            {
                // Weight by Hann Window
                complexSignal[2 * j] = (double)(windowArray[j] * samples[j]);

                // need to clear out as fft modifies buffer (phase)
                complexSignal[2 * j + 1] = 0;
            }

            // FFT transform for gathering the spectrum
            fft.FFT(complexSignal, true);

            var band = new double[fftWindowsSize / 2];
            double lengthSqrt = Math.Sqrt(fftWindowsSize);
            for (int j = 0; j < fftWindowsSize / 2; j++)
            {
                double re = complexSignal[2 * j] * lengthSqrt;
                double img = complexSignal[2 * j + 1] * lengthSqrt;

                // do the Abs calculation and add with Math.Sqrt(audio_data.Length);
                // i.e. the magnitude spectrum
                band[j] = (double)(Math.Sqrt(re * re + img * img) * lengthSqrt);
            }
            return band;
        }


    }
}
