using System;
using System.Globalization;
using Xamarin.Forms;

namespace STAGIOPTR.Converters
{
    public class QualifyNameConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            int qualify = (int)value;
            switch (qualify)
            {
                case 5:
                    return "Ótimo";
                case 4:
                    return "Bom";
                case 3:
                    return "Regular";
                case 2:
                    return "Ruim";
                case 1:
                    return "Péssimo";
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
