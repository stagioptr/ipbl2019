using System;
using System.Globalization;
using Xamarin.Forms;

namespace STAGIOPTR.Converters
{
    public class QualifyConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            int qualify = (int)value;
            switch (qualify)
            {
                case 5:
                    return "very_satisfied_white.png";
                case 4:
                    return "satisfied_white.png";
                case 3:
                    return "normal_white.png";
                case 2:
                    return "dissatisfied_white.png";
                case 1:
                    return "very_dissatisfied_white.png";
                default:
                    return null;
            }
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
